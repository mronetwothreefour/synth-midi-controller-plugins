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
			randomizationOptionsTree.addChild(Tree{ Info::get().IDfor(paramIndex), {}, { Tree{ ID::rndm_AllowedChoices } } }, paramIndex, nullptr);
			setRepeatChoicesAreAllowedForParam(false, paramIndex);
		}

		setParamIsLocked(paramIndex, false);

		if (allowedChoicesType == AllowedChoicesType::standard)
			allowAllChoicesForParam(paramIndex);
		if (allowedChoicesType == AllowedChoicesType::oscShape)
			allowAllChoicesForOscShapeParam(paramIndex);
		if (allowedChoicesType == AllowedChoicesType::lfoFreq)
			allowAllChoicesForLFO_FreqParam(paramIndex);
	}

	for (auto trackNum = 1; trackNum != 5; ++trackNum) {
		setEditModeIsAllStepsForSeqTrack(true, trackNum);
		setSelectedStepForSeqTrack(1, trackNum);
		if (trackNum == 1)
			setProbabilityOfRestForAllStepsInSeqTrack_1(0.13f);
		setProbabilityOfDuplicatesForAllStepsInSeqTrack(0.0f, trackNum);
		setProbabilityOfResetForAllStepsInSeqTrack(0.0f, trackNum);
		allowAllChoicesForAllStepsInSeqTrack(trackNum);
		for (auto stepNum = 1; stepNum != 17; ++stepNum) {
			if (trackNum == 1)
				setProbabilityOfRestForSeqTrack_1_Step(0.13f, stepNum);
				setProbabilityOfDuplicateForSeqTrackStep(0.0f, trackNum, stepNum);
				setProbabilityOfResetForSeqTrackStep(0.0f, trackNum, stepNum);
				allowAllChoicesForSeqTrackStep(trackNum, stepNum);
		}
	}
}





const bool RandomizationOptions::transmitMethodIsSysEx() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethodIsSysEx) == true);
}

void RandomizationOptions::setTransmitMethodIsSysEx(bool shouldBeSysEx) {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethodIsSysEx, shouldBeSysEx ? true : false, nullptr);
}




const bool RandomizationOptions::repeatChoicesAreAllowedForParam(uint8 paramIndex) {
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool RandomizationOptions::repeatChoicesAreForbiddenForParam(uint8 paramIndex) {
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void RandomizationOptions::setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex) {
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(Info::get().IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}




const bool RandomizationOptions::paramIsLocked(uint8 paramIndex) {
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool RandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void RandomizationOptions::setParamIsLocked(uint8 paramIndex, bool shouldBeLocked) {
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(Info::get().IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}




const bool RandomizationOptions::choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::clearAllowedChoicesForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto numberOfChoices{ Info::get().numberOfChoicesFor(paramIndex) };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}

const bool RandomizationOptions::onlyOneChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}

const bool RandomizationOptions::noChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}




const bool RandomizationOptions::oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto propertyID{ "choice_" + String((int)shape) };
	return allowedShapes.hasProperty(propertyID) == true;
}

void RandomizationOptions::setOscShapeIsAllowedForParam(OscWaveShape shape, bool shouldBeAllowed, uint8 paramIndex) {
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoOscShapeIsAllowed) == true;
}

const bool RandomizationOptions::pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex) {
	jassert(pulseWidth < EP::numberOfPulseWidths);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	return allowedPulseWidths.hasProperty("choice_" + (String)pulseWidth) == true;
}

void RandomizationOptions::setPulseWidthIsAllowedForParam(int pulseWidth, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(pulseWidth < EP::numberOfPulseWidths);
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoPulseWidthIsAllowed) == true;
}

void RandomizationOptions::checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex) {
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	allowedShapes.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedPulseWidthsForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	allowedPulseWidths.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForOscShapeParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape)
		setOscShapeIsAllowedForParam(OscWaveShape{ shape }, true, paramIndex);
	for (auto width = 0; width < EP::numberOfPulseWidths; ++width)
		setPulseWidthIsAllowedForParam(width, true, paramIndex);
}




const bool RandomizationOptions::categoryIsAllowedForLFO_FreqParam(Category category, uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	auto propertyID{ "choice_" + String((int)category) };
	return allowedCategories.hasProperty(propertyID) == true;
}

void RandomizationOptions::setCategoryIsAllowedForLFO_FreqParam(LFO_FreqCategory category, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedFreqCategories, nullptr) };
	auto propertyID{ "choice_" + String((int)category) };
	if (shouldBeAllowed)
		allowedCategories.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedCategories.hasProperty(propertyID))
			allowedCategories.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

const bool RandomizationOptions::noCategoryIsAllowedForLFO_FreqParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoFreqCategoryIsAllowed) == true;
}

const bool RandomizationOptions::unsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfUnsyncedLFO_Frequencies);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	return allowedUnsyncedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setUnsyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfUnsyncedLFO_Frequencies);
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoUnsyncedFreqIsAllowed) == true;
}

const bool RandomizationOptions::pitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfPitchedLFO_Frequencies);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	return allowedPitchedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setPitchedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfPitchedLFO_Frequencies);
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoPitchedFreqIsAllowed) == true;
}

const bool RandomizationOptions::syncedFreqIsAllowedForLFO_FreqParam(uint8 freq, uint8 paramIndex) {
	jassert(freq < EP::numberOfSyncedLFO_Frequencies);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	return allowedSyncedFreq.hasProperty("choice_" + (String)freq) == true;
}

void RandomizationOptions::setSyncedFreqIsAllowedForLFO_FreqParam(uint8 freq, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(freq < EP::numberOfSyncedLFO_Frequencies);
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoSyncedFreqIsAllowed) == true;
}

void RandomizationOptions::checkNumberOfChoicesAllowedForLFO_FreqParam(uint8 paramIndex) {
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
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	allowedCategories.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedUnsyncedFreqForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	allowedUnsyncedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedPitchedFreqForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	allowedPitchedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::clearAllowedSyncedFreqForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	allowedSyncedFreq.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForLFO_FreqParam(uint8 paramIndex) {
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





const bool RandomizationOptions::editModeIsAllStepsForSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (bool)trackTree.getProperty(ID::rndm_SeqTrackEditModeIsAllSteps) == true;
}

const bool RandomizationOptions::editModeIsSelectedStepForSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (bool)trackTree.getProperty(ID::rndm_SeqTrackEditModeIsAllSteps) == false;
}

void RandomizationOptions::setEditModeIsAllStepsForSeqTrack(bool shouldBeAllSteps, int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	trackTree.setProperty(ID::rndm_SeqTrackEditModeIsAllSteps, shouldBeAllSteps ? (bool)true : (bool)false, nullptr);
}

int RandomizationOptions::selectedStepForSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return trackTree.getProperty(ID::rndm_SelectedStep);
}

void RandomizationOptions::setSelectedStepForSeqTrack(int stepNum, int trackNum) {
	jassert(stepNum > 0 && stepNum < 17);
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	trackTree.setProperty(ID::rndm_SelectedStep, stepNum, nullptr);
}

const float RandomizationOptions::probabilityOfRestForAllStepsInSeqTrack_1() {
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (float)trackTree.getProperty(ID::rndm_ProbabilityOfRestForAllSteps);
}

void RandomizationOptions::setProbabilityOfRestForAllStepsInSeqTrack_1(float newProb) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	trackTree.setProperty(ID::rndm_ProbabilityOfRestForAllSteps, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfRestForSeqTrack_1_Step(int stepNum) {
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfRestForStep_.toString() + (String)stepNum };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfRestForSeqTrack_1_Step(float newProb, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + "1" };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfRestForStep_.toString() + (String)stepNum };
	trackTree.setProperty(propertyID, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfDuplicatesForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (float)trackTree.getProperty(ID::rndm_ProbabilityOfDublicatesForAllSteps);
}

void RandomizationOptions::setProbabilityOfDuplicatesForAllStepsInSeqTrack(float newProb, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	randomizationOptionsTree.setProperty(ID::rndm_ProbabilityOfDublicatesForAllSteps, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfDuplicateForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfDublicateForStep_.toString() + (String)stepNum };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfDuplicateForSeqTrackStep(float newProb, int trackNum, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 1 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfDublicateForStep_.toString() + (String)stepNum };
	randomizationOptionsTree.setProperty(propertyID, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (float)trackTree.getProperty(ID::rndm_ProbabilityOfResetForAllSteps);
}

void RandomizationOptions::setProbabilityOfResetForAllStepsInSeqTrack(float newProb, int trackNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	randomizationOptionsTree.setProperty(ID::rndm_ProbabilityOfResetForAllSteps, newProb, nullptr);
}

const float RandomizationOptions::probabilityOfResetForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfResetForStep_.toString() + (String)stepNum };
	return (float)trackTree.getProperty(propertyID);
}

void RandomizationOptions::setProbabilityOfResetForSeqTrackStep(float newProb, int trackNum, int stepNum) {
	jassert(newProb >= 0.0f && newProb <= 1.0f);
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_ProbabilityOfResetForStep_.toString() + (String)stepNum };
	randomizationOptionsTree.setProperty(propertyID, newProb, nullptr);
}

const bool RandomizationOptions::choiceIsAllowedForAllStepsInSeqTrack(uint8 choiceNum, int trackNum) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoices{ trackTree.getChildWithName(ID::rndm_AllowedChoicesForAllSteps) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForAllStepsInSeqTrack(uint8 choiceNum, bool shouldBeAllowed, int trackNum) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoices{ trackTree.getOrCreateChildWithName(ID::rndm_AllowedChoicesForAllSteps, nullptr) };
	String propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkProbabilitiesAndNumberOfChoicesAllowedForAllStepsInSeqTrack(trackNum);
}

void RandomizationOptions::clearAllowedChoicesForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoices{ trackTree.getChildWithName(ID::rndm_AllowedChoicesForAllSteps) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForSeqTrackSteps; ++choiceNum)
		setChoiceIsAllowedForAllStepsInSeqTrack(choiceNum, true, trackNum);
}

const bool RandomizationOptions::choiceIsAllowedForSeqTrackStep(uint8 choiceNum, int trackNum, int stepNum) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoicesID{ ID::rndm_AllowedChoicesForStep_.toString() + (String)stepNum };
	auto allowedChoices{ trackTree.getChildWithName(allowedChoicesID) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForSeqTrackStep(uint8 choiceNum, bool shouldBeAllowed, int trackNum, int stepNum) {
	jassert(choiceNum < EP::numberOfChoicesForSeqTrackSteps);
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoicesID{ ID::rndm_AllowedChoicesForStep_.toString() + (String)stepNum };
	auto allowedChoices{ trackTree.getOrCreateChildWithName(allowedChoicesID, nullptr) };
	String propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(trackNum, stepNum);
}

void RandomizationOptions::clearAllowedChoicesForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoicesID{ ID::rndm_AllowedChoicesForStep_.toString() + (String)stepNum };
	auto allowedChoices{ trackTree.getOrCreateChildWithName(allowedChoicesID, nullptr) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForSeqTrackSteps; ++choiceNum)
		setChoiceIsAllowedForSeqTrackStep(choiceNum, true, trackNum, stepNum);
}

void RandomizationOptions::checkProbabilitiesAndNumberOfChoicesAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoices{ trackTree.getOrCreateChildWithName(ID::rndm_AllowedChoicesForAllSteps, nullptr) };
	auto numberOfChoicesAllowed{ allowedChoices.getNumProperties() };

	auto repeatsMustBeAllowed{ false };
	if (trackNum == 1 && probabilityOfRestForAllStepsInSeqTrack_1() >= 0.5f ||
		probabilityOfDuplicatesForAllStepsInSeqTrack(trackNum) >= 0.5f ||
		probabilityOfResetForAllStepsInSeqTrack(trackNum) >= 0.5f)
		repeatsMustBeAllowed = true;
	if (numberOfChoicesAllowed == 1) {
		if (trackNum == 1 && probabilityOfRestForAllStepsInSeqTrack_1() == 0.0f &&
			probabilityOfResetForAllStepsInSeqTrack(trackNum) == 0.0f)
			repeatsMustBeAllowed = true;
		if (trackNum != 1 && probabilityOfResetForAllStepsInSeqTrack(trackNum) == 0.0f)
			repeatsMustBeAllowed = true;
	}
	trackTree.setProperty(ID::rndm_RepeatChoicesMustBeAllowedForAllSteps, repeatsMustBeAllowed ? (bool)true : (bool)false, nullptr);

	auto noChoiceIsAllowed{ numberOfChoicesAllowed == 0 };
	trackTree.setProperty(ID::rndm_NoChoiceIsAllowedForAllSteps, noChoiceIsAllowed ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::checkProbabilitiesAndNumberOfChoicesAllowedForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto allowedChoicesID{ ID::rndm_AllowedChoicesForStep_.toString() + (String)stepNum };
	auto allowedChoices{ trackTree.getOrCreateChildWithName(allowedChoicesID, nullptr)};
	auto numberOfChoicesAllowed{ allowedChoices.getNumProperties() };

	auto repeatsMustBeAllowed{ false };
	if (trackNum == 1 && probabilityOfRestForSeqTrack_1_Step(stepNum) >= 0.5f ||
		probabilityOfDuplicateForSeqTrackStep(trackNum, stepNum) >= 0.5f ||
		probabilityOfResetForSeqTrackStep(trackNum, stepNum) >= 0.5f)
		repeatsMustBeAllowed = true;
	if (numberOfChoicesAllowed == 1) {
		if (trackNum == 1 && probabilityOfRestForSeqTrack_1_Step(stepNum) == 0.0f &&
			probabilityOfResetForSeqTrackStep(trackNum, stepNum) == 0.0f)
			repeatsMustBeAllowed = true;
		if (trackNum != 1 && probabilityOfResetForSeqTrackStep(trackNum, stepNum) == 0.0f)
			repeatsMustBeAllowed = true;
	}
	auto propertyID{ ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + (String)stepNum };
	trackTree.setProperty(propertyID, repeatsMustBeAllowed ? (bool)true : (bool)false, nullptr);

	auto noChoiceIsAllowed{ numberOfChoicesAllowed == 0 };
	propertyID = ID::rndm_NoChoiceIsAllowedForStep_.toString() + (String)stepNum;
	trackTree.setProperty(propertyID, noChoiceIsAllowed ? (bool)true : (bool)false, nullptr);
}

const bool RandomizationOptions::repeatsMustBeAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (bool)trackTree.getProperty(ID::rndm_RepeatChoicesMustBeAllowedForAllSteps) == true;
}

const bool RandomizationOptions::noChoiceIsAllowedForAllStepsInSeqTrack(int trackNum) {
	jassert(trackNum > 0 && trackNum < 5);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	return (bool)trackTree.getProperty(ID::rndm_NoChoiceIsAllowedForAllSteps) == true;
}

const bool RandomizationOptions::repeatsMustBeAllowedForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID{ ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + (String)stepNum };
	return (bool)trackTree.getProperty(propertyID) == true;
}

const bool RandomizationOptions::noChoiceIsAllowedForSeqTrackStep(int trackNum, int stepNum) {
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	auto trackTreeID{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	auto trackTree{ randomizationOptionsTree.getChildWithName(trackTreeID) };
	auto propertyID = ID::rndm_NoChoiceIsAllowedForStep_.toString() + (String)stepNum;
	return (bool)trackTree.getProperty(propertyID) == true;
}




void RandomizationOptions::addListenerToChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	auto paramID{ Info::get().IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).addListener(listener);
}

void RandomizationOptions::removeListenerFromChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	auto paramID{ Info::get().IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).removeListener(listener);
}




ValueTree RandomizationOptions::getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex) {
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(Info::get().IDfor(paramIndex)) };
	auto allowedChoicesTree{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return allowedChoicesTree;
}




XmlElement* RandomizationOptions::getStateXml() {
	auto randomizationOptionsTreeStateXml{ randomizationOptionsTree.createXml() };
	if (randomizationOptionsTreeStateXml != nullptr)
		randomizationOptionsTreeStateXml->setTagName(ID::state_RandomizationOptions);
	return randomizationOptionsTreeStateXml.release();
}

void RandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		randomizationOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
