#include "up_tree_RandomizationOptions.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;
using Info = InfoForExposedParameters;
using Tree = ValueTree;



RandomizationOptions::RandomizationOptions() :
	randomizationOptionsTree{ID::rndm_Options }
{
	setTransmitMethodIsSysEx(true);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto allowedChoicesType{ Info::get().allowedChoicesTypeFor(paramIndex)};
		if (allowedChoicesType == AllowedChoicesType::binary) {
			randomizationOptionsTree.addChild(Tree{ Info::get().IDfor(paramIndex), {}, {} }, paramIndex, nullptr);
			setRepeatChoicesAreAllowedForParam(true, paramIndex);
		}
		else {
			if (allowedChoicesType != AllowedChoicesType::seqTrackStep) {
				randomizationOptionsTree.addChild(Tree{ Info::get().IDfor(paramIndex), {}, { Tree{ ID::rndm_AllowedChoices } } }, paramIndex, nullptr);
				setRepeatChoicesAreAllowedForParam(false, paramIndex);
			}
		}

		setParamIsLocked(paramIndex, false);

		if (allowedChoicesType == AllowedChoicesType::standard)
			allowAllChoicesForParam(paramIndex);
		if (allowedChoicesType == AllowedChoicesType::oscShape)
			allowAllChoicesForOscShapeParam(paramIndex);
		if (allowedChoicesType == AllowedChoicesType::lfoFreq)
			allowAllChoicesForLFO_FreqParam(paramIndex);
		if (allowedChoicesType == AllowedChoicesType::voiceNameChar)
			allowAllChoicesForVoiceNameCharParam(paramIndex);
	}

	for (auto trackNum = (int)Track::one; trackNum <= (int)Track::four; ++trackNum) {
		setTargetStepForSeqTrack(Step::all, Track{ trackNum });
		for (auto stepNum = (int)Step::all; stepNum <= (int)Step::sixteen; ++stepNum) {
			setRepeatChoicesAreAllowedForSeqTrackStep(false, Track{ trackNum }, Step{ stepNum });
			if (trackNum == (int)Track::one)
				setProbabilityOfRestForSeqTrack_1_Step(0.13f, Step{ stepNum });
			setProbabilityOfDuplicateForSeqTrackStep(0.0f, Track{ trackNum }, Step{ stepNum });
			setProbabilityOfResetForSeqTrackStep(0.0f, Track{ trackNum }, Step{ stepNum });
			allowAllChoicesForSeqTrackStep(Track{ trackNum }, Step{ stepNum });
		}
	}
}





const bool RandomizationOptions::transmitMethodIsSysEx() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethodIsSysEx) == true);
}

void RandomizationOptions::setTransmitMethodIsSysEx(bool shouldBeSysEx) {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethodIsSysEx, shouldBeSysEx ? true : false, nullptr);
}




const bool RandomizationOptions::paramIsLocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool RandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void RandomizationOptions::setParamIsLocked(uint8 paramIndex, bool shouldBeLocked) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(Info::get().IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}




const bool RandomizationOptions::choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard ||
		    Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getOrCreateChildWithName(ID::rndm_AllowedChoices, nullptr) };
	String propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForParam(paramIndex);
}

void RandomizationOptions::checkNumberOfChoicesAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto allowedChoicesType{ Info::get().allowedChoicesTypeFor(paramIndex) };
	jassert(allowedChoicesType == AllowedChoicesType::standard || allowedChoicesType == AllowedChoicesType::voiceNameChar);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::clearAllowedChoicesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto allowedChoicesType{ Info::get().allowedChoicesTypeFor(paramIndex) };
	jassert(allowedChoicesType == AllowedChoicesType::standard || allowedChoicesType == AllowedChoicesType::voiceNameChar);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto numberOfChoices{ Info::get().numberOfChoicesFor(paramIndex) };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}




const bool RandomizationOptions::oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto propertyID{ "choice_" + String((int)shape) };
	return allowedShapes.hasProperty(propertyID) == true;
}

void RandomizationOptions::setOscShapeIsAllowedForParam(OscWaveShape shape, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedShapes, nullptr) };
	auto propertyID{ "choice_" + String((int)shape) };
	if (shouldBeAllowed)
		allowedShapes.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedShapes.hasProperty(propertyID))
			allowedShapes.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

const bool RandomizationOptions::noOscShapeIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoOscShapeIsAllowed) == true;
}

const bool RandomizationOptions::pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex) {
	jassert(pulseWidth < EP::numberOfPulseWidths);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	return allowedPulseWidths.hasProperty("choice_" + (String)pulseWidth) == true;
}

void RandomizationOptions::setPulseWidthIsAllowedForParam(int pulseWidth, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(pulseWidth < EP::numberOfPulseWidths);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedPulseWidths, nullptr) };
	auto propertyID{ "choice_" + (String)pulseWidth };
	if (shouldBeAllowed)
		allowedPulseWidths.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedPulseWidths.hasProperty(propertyID))
			allowedPulseWidths.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

const bool RandomizationOptions::noPulseWidthIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoPulseWidthIsAllowed) == true;
}

void RandomizationOptions::checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto noShapes{ allowedShapes.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoOscShapeIsAllowed, noShapes ? (bool)true : (bool)false, nullptr);

	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	auto noPulseWidths{ allowedPulseWidths.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoPulseWidthIsAllowed, noPulseWidths ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ false };
	if (allowedShapes.getNumProperties() == 1) {
		if (allowedShapes.hasProperty("choice_" + String((int)OscWaveShape::pulse)))
			onlyOneChoice = (allowedPulseWidths.getNumProperties() == 1);
		else
			onlyOneChoice = true;
	}
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::clearAllowedOscShapesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	allowedShapes.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedPulseWidthsForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	allowedPulseWidths.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForOscShapeParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape)
		setOscShapeIsAllowedForParam(OscWaveShape{ shape }, true, paramIndex);
	for (auto width = 0; width < EP::numberOfPulseWidths; ++width)
		setPulseWidthIsAllowedForParam(width, true, paramIndex);
}




const bool RandomizationOptions::categoryIsAllowedForLFO_FreqParam(Category category, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	auto propertyID{ "choice_" + String((int)category) };
	return allowedCategories.hasProperty(propertyID) == true;
}

void RandomizationOptions::setCategoryIsAllowedForLFO_FreqParam(LFO_FreqCategory category, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedFreqCategories, nullptr) };
	auto propertyID{ "choice_" + String((int)category) };
	if (shouldBeAllowed)
		allowedCategories.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedCategories.hasProperty(propertyID))
			allowedCategories.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForLFO_FreqParam(paramIndex);
}

const bool RandomizationOptions::noCategoryIsAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoFreqCategoryIsAllowed) == true;
}

const bool RandomizationOptions::unsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfUnsyncedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	return allowedUnsyncedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfUnsyncedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedUnsyncedFreq{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedUnsyncedFreq, nullptr) };
	auto propertyID{ "choice_" + (String)freq };
	if (shouldBeAllowed)
		allowedUnsyncedFreq.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedUnsyncedFreq.hasProperty(propertyID))
			allowedUnsyncedFreq.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForLFO_FreqParam(paramIndex);
}

const bool RandomizationOptions::noUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoUnsyncedFreqIsAllowed) == true;
}

const bool RandomizationOptions::pitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfPitchedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	return allowedPitchedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setPitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfPitchedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPitchedFreq{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedPitchedFreq, nullptr) };
	auto propertyID{ "choice_" + (String)freq };
	if (shouldBeAllowed)
		allowedPitchedFreq.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedPitchedFreq.hasProperty(propertyID))
			allowedPitchedFreq.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForLFO_FreqParam(paramIndex);
}

const bool RandomizationOptions::noPitchedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoPitchedFreqIsAllowed) == true;
}

const bool RandomizationOptions::syncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfSyncedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	return allowedSyncedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setSyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfSyncedLFO_Frequencies);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedSyncedFreq{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedSyncedFreq, nullptr) };
	auto propertyID{ "choice_" + (String)freq };
	if (shouldBeAllowed)
		allowedSyncedFreq.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedSyncedFreq.hasProperty(propertyID))
			allowedSyncedFreq.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForLFO_FreqParam(paramIndex);
}

const bool RandomizationOptions::noSyncedFreqIsAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoSyncedFreqIsAllowed) == true;
}

void RandomizationOptions::checkNumberOfChoicesAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	auto noCategories{ allowedCategories.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoFreqCategoryIsAllowed, noCategories ? (bool)true : (bool)false, nullptr);

	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	auto noUnsyncedFreq{ allowedUnsyncedFreq.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoUnsyncedFreqIsAllowed, noUnsyncedFreq ? (bool)true : (bool)false, nullptr);

	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	auto noPitchedFreq{ allowedPitchedFreq.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoPitchedFreqIsAllowed, noPitchedFreq ? (bool)true : (bool)false, nullptr);

	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	auto noSyncedFreq{ allowedSyncedFreq.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoUnsyncedFreqIsAllowed, noSyncedFreq ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ false };
	if (allowedCategories.getNumProperties() == 1) {
		if (allowedCategories.hasProperty("choice_" + String((int)Category::unsynced)))
			onlyOneChoice = (allowedUnsyncedFreq.getNumProperties() == 1);
		if (allowedCategories.hasProperty("choice_" + String((int)Category::pitched)))
			onlyOneChoice = (allowedPitchedFreq.getNumProperties() == 1);
		if (allowedCategories.hasProperty("choice_" + String((int)Category::synced)))
			onlyOneChoice = (allowedSyncedFreq.getNumProperties() == 1);
	}
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::clearAllowedCategoriesForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	allowedCategories.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedUnsyncedFreqForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	allowedUnsyncedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedPitchedFreqForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	allowedPitchedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedSyncedFreqForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	allowedSyncedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForLFO_FreqParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	for (auto category = (int)Category::unsynced; category <= (int)Category::synced; ++category)
		setCategoryIsAllowedForLFO_FreqParam(Category{ category }, true, paramIndex);
	for (auto unsyncedFreq = (uint8)0; unsyncedFreq < EP::numberOfUnsyncedLFO_Frequencies; ++unsyncedFreq)
		setUnsyncedFreqIsAllowedForLFO_FreqParam(unsyncedFreq, true, paramIndex);
	for (auto pitchedFreq = (uint8)0; pitchedFreq < EP::numberOfPitchedLFO_Frequencies; ++pitchedFreq)
		setPitchedFreqIsAllowedForLFO_FreqParam(pitchedFreq, true, paramIndex);
	for (auto syncedFreq = (uint8)0; syncedFreq < EP::numberOfSyncedLFO_Frequencies; ++syncedFreq)
		setSyncedFreqIsAllowedForLFO_FreqParam(syncedFreq, true, paramIndex);
}

const bool RandomizationOptions::choiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, uint8 paramIndex) {
	jassert(choiceNum < EP::numberOfChoicesForVoiceNameChar - EP::firstVisibleVoiceNameCharNumber);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	choiceNum += EP::firstVisibleVoiceNameCharNumber;
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForVoiceNameCharParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(choiceNum < EP::numberOfChoicesForVoiceNameChar - EP::firstVisibleVoiceNameCharNumber);
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getOrCreateChildWithName(ID::rndm_AllowedChoices, nullptr) };
	choiceNum += EP::firstVisibleVoiceNameCharNumber;
	String propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForVoiceNameCharParam(paramIndex);
}

void RandomizationOptions::checkNumberOfChoicesAllowedForVoiceNameCharParam(uint8 paramIndex) {
	checkNumberOfChoicesAllowedForParam(paramIndex);
}

void RandomizationOptions::clearAllowedChoicesForVoiceNameCharParam(uint8 paramIndex) {
	clearAllowedChoicesForParam(paramIndex);
}

void RandomizationOptions::allowAllChoicesForVoiceNameCharParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	for (auto choiceNum = EP::firstVisibleVoiceNameCharNumber; choiceNum != EP::numberOfChoicesForVoiceNameChar; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}




const bool RandomizationOptions::onlyOneChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}

const bool RandomizationOptions::noChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}




const bool RandomizationOptions::repeatChoicesAreAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool RandomizationOptions::repeatChoicesAreForbiddenForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void RandomizationOptions::setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(Info::get().IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}




void RandomizationOptions::addListenerToChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramID{ Info::get().IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).addListener(listener);
}

void RandomizationOptions::removeListenerFromChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramID{ Info::get().IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).removeListener(listener);
}




Tree RandomizationOptions::getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoicesTree{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return allowedChoicesTree;
}





Step RandomizationOptions::targetStepForSeqTrack(Track track) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto stepNum{ (int)trackTree.getProperty(ID::rndm_SeqTrackTargetStep) };
	return Step{ stepNum };
}

void RandomizationOptions::setTargetStepForSeqTrack(Step step, Track track) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getOrCreateChildWithName(trackTreeID, nullptr) };
	trackTree.setProperty(ID::rndm_SeqTrackTargetStep, (int)step, nullptr);
}

const float RandomizationOptions::probabilityOfRestForSeqTrack_1_Step(Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RestProbForAllSteps : ID::rndm_RestProbForStep_.toString() + String((int)step) };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfRestForSeqTrack_1_Step(float newProb, Step step) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getOrCreateChildWithName(trackTreeID, nullptr) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RestProbForAllSteps : ID::rndm_RestProbForStep_.toString() + String((int)step) };
	trackTree.setProperty(propertyID, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfDuplicateForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_DupeProbForAllSteps : ID::rndm_DupeProbForStep_.toString() + String((int)step) };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfDuplicateForSeqTrackStep(float newProb, Track track, Step step) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getOrCreateChildWithName(trackTreeID, nullptr) };
	Identifier propertyID{ step == Step::all ? ID::rndm_DupeProbForAllSteps : ID::rndm_DupeProbForStep_.toString() + String((int)step) };
	trackTree.setProperty(propertyID, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_ResetProbForAllSteps : ID::rndm_ResetProbForStep_.toString() + String((int)step) };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfResetForSeqTrackStep(float newProb, Track track, Step step) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getOrCreateChildWithName(trackTreeID, nullptr) };
	Identifier propertyID{ step == Step::all ? ID::rndm_ResetProbForAllSteps : ID::rndm_ResetProbForStep_.toString() + String((int)step) };
	trackTree.setProperty(propertyID, newProb, nullptr);
}

const bool RandomizationOptions::choiceIsAllowedForSeqTrackStep(uint8 choiceNum, Track track, Step step) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier allowedChoicesID{ step == Step::all ? ID::rndm_AllowedChoicesForAllSteps : 
		ID::rndm_AllowedChoicesForStep_.toString() + String((int)step)
	};
	auto allowedChoices{ trackTree.getChildWithName(allowedChoicesID) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForSeqTrackStep(uint8 choiceNum, bool shouldBeAllowed, Track track, Step step) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier allowedChoicesID{ step == Step::all ? ID::rndm_AllowedChoicesForAllSteps :
		ID::rndm_AllowedChoicesForStep_.toString() + String((int)step)
	};
	auto allowedChoices{ trackTree.getOrCreateChildWithName(allowedChoicesID, nullptr) };
	String propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(track, step);
}

void RandomizationOptions::clearAllowedChoicesForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier allowedChoicesID{ step == Step::all ? ID::rndm_AllowedChoicesForAllSteps :
		ID::rndm_AllowedChoicesForStep_.toString() + String((int)step)
	};
	auto allowedChoices{ trackTree.getChildWithName(allowedChoicesID) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForSeqTrackStep(Track track, Step step) {
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForSeqTrackSteps; ++choiceNum)
		setChoiceIsAllowedForSeqTrackStep(choiceNum, true, track, step);
}

void RandomizationOptions::checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier allowedChoicesID{ step == Step::all ? ID::rndm_AllowedChoicesForAllSteps :
		ID::rndm_AllowedChoicesForStep_.toString() + String((int)step)
	};
	auto allowedChoices{ trackTree.getChildWithName(allowedChoicesID) };

	auto repeatsMustBeAllowed{ false };
	if (track == Track::one && probabilityOfRestForSeqTrack_1_Step(step) >= 0.5f ||
		probabilityOfDuplicateForSeqTrackStep(track, step) >= 0.5f ||
		probabilityOfResetForSeqTrackStep(track, step) >= 0.5f)
		repeatsMustBeAllowed = true;
	auto numberOfChoicesAllowed{ allowedChoices.getNumProperties() };
	if (numberOfChoicesAllowed == 1) {
		if (track == Track::one && probabilityOfRestForSeqTrack_1_Step(step) == 0.0f &&
			probabilityOfResetForSeqTrackStep(track, step) == 0.0f)
			repeatsMustBeAllowed = true;
		if (track != Track::one && probabilityOfResetForSeqTrackStep(track, step) == 0.0f)
			repeatsMustBeAllowed = true;
	}
	Identifier repeatsMustBeAllowedID{ step == Step::all ? ID::rndm_RepeatChoicesMustBeAllowedForAllSteps :
		ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + String((int)step)
	};
	trackTree.setProperty(repeatsMustBeAllowedID, repeatsMustBeAllowed ? (bool)true : (bool)false, nullptr);

	Identifier noChoiceIsAllowedID{ step == Step::all ? ID::rndm_NoChoiceIsAllowedForAllSteps :
		ID::rndm_NoChoiceIsAllowedForStep_.toString() + String((int)step)
	};
	auto noChoiceIsAllowed{ numberOfChoicesAllowed == 0 };
	trackTree.setProperty(noChoiceIsAllowedID, noChoiceIsAllowed ? (bool)true : (bool)false, nullptr);
}

const bool RandomizationOptions::repeatChoicesMustBeAllowedForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RepeatChoicesMustBeAllowedForAllSteps : 
		ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + String((int)step)
	};
	return (bool)trackTree.getProperty(propertyID) == true;
}

const bool RandomizationOptions::noChoiceIsAllowedForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_NoChoiceIsAllowedForAllSteps :
		ID::rndm_NoChoiceIsAllowedForStep_.toString() + String((int)step)
	};
	return (bool)trackTree.getProperty(propertyID) == true;
}

const bool RandomizationOptions::repeatChoicesAreAllowedForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RepeatChoicesAreAllowedForAllSteps :
		ID::rndm_RepeatChoicesAreAllowedForStep_.toString() + String((int)step)
	};
	return (bool)trackTree.getProperty(propertyID) == true;
}

const bool RandomizationOptions::repeatChoicesAreForbiddenForSeqTrackStep(Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RepeatChoicesAreAllowedForAllSteps :
		ID::rndm_RepeatChoicesAreAllowedForStep_.toString() + String((int)step)
	};
	return (bool)trackTree.getProperty(propertyID) == false;
}

void RandomizationOptions::setRepeatChoicesAreAllowedForSeqTrackStep(bool shouldBeAllowed, Track track, Step step) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	Identifier propertyID{ step == Step::all ? ID::rndm_RepeatChoicesAreAllowedForAllSteps :
		ID::rndm_RepeatChoicesAreAllowedForStep_.toString() + String((int)step)
	};
	trackTree.setProperty(propertyID, shouldBeAllowed ? true : false, nullptr);
}




void RandomizationOptions::addListenerToSeqTrackTree(Tree::Listener* listener, Track track) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	randomizationOptionsTree.getChildWithName(trackTreeID).addListener(listener);
}

void RandomizationOptions::removeListenerFromSeqTrackTree(Tree::Listener* listener, Track track) {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + String((int)track) };
	randomizationOptionsTree.getChildWithName(trackTreeID).removeListener(listener);
}




XmlElement* RandomizationOptions::getStateXml() {
	auto randomizationOptionsTreeStateXml{ randomizationOptionsTree.createXml() };
	if (randomizationOptionsTreeStateXml != nullptr)
		randomizationOptionsTreeStateXml->setTagName(ID::state_RandomizationOptions);
	return randomizationOptionsTreeStateXml.release();
}

void RandomizationOptions::replaceState(const Tree& newState) {
	if (newState.isValid())
		randomizationOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
