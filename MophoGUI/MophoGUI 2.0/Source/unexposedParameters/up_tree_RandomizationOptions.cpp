#include "up_tree_RandomizationOptions.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;
using Tree = ValueTree;



RandomizationOptions::RandomizationOptions() :
	randomizationOptionsTree{ID::rndm_Options }
{
	setTransmitMethodIsSysEx(true);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto allowedChoicesType{ info.allowedChoicesTypeFor(paramIndex) };
		if (allowedChoicesType == AllowedChoicesType::binary) {
			randomizationOptionsTree.addChild(Tree{ info.IDfor(paramIndex), {}, {} }, paramIndex, nullptr);
			setRepeatChoicesAreAllowedForParam(true, paramIndex);
		}
		else {
			randomizationOptionsTree.addChild(Tree{ info.IDfor(paramIndex), {}, { Tree{ ID::rndm_AllowedChoices } } }, paramIndex, nullptr);
			setRepeatChoicesAreAllowedForParam(false, paramIndex);
		}

		setParamIsLocked(paramIndex, false);

		if (allowedChoicesType == AllowedChoicesType::standard) {
			auto numberOfChoices{ info.numberOfChoicesFor(paramIndex) };
			for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
				setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
		}
		if (allowedChoicesType == AllowedChoicesType::oscShape) {
			for (auto shape = (int)OscWaveShape::off; shape <= (int)OscWaveShape::pulse; ++shape)
				allowOscShapeForParam(OscWaveShape{ shape }, paramIndex);
			for (auto width = 0; width < 100; ++width)
				allowPulseWidthForParam(width, paramIndex);
		}
		//if (allowedChoicesType == AllowedChoicesType::lfoFreq) {
		//	for (auto category = (int)LFO_FreqCategory::unsynced; category <= (int)LFO_FreqCategory::synced; ++category)
		//		allowCategoryForLFO_FreqParam(LFO_FreqCategory{ category }, paramIndex);
		//	for (auto unsyncedFreq = 0; unsyncedFreq < EP::numberOfUnsyncedLFO_Frequencies; ++unsyncedFreq)
		//		allowUnsyncedFreqForLFO_FreqParam(unsyncedFreq, paramIndex);
		//	for (auto pitchedFreq = 0; pitchedFreq < EP::numberOfPitchedLFO_Frequencies; ++pitchedFreq)
		//		allowPitchedFreqForLFO_FreqParam(pitchedFreq, paramIndex);
		//	for (auto syncedFreq = 0; syncedFreq < EP::numberOfSyncedLFO_Frequencies; ++syncedFreq)
		//		allowUnsyncedFreqForLFO_FreqParam(syncedFreq, paramIndex);
		//}
	}
}





const bool RandomizationOptions::transmitMethodIsSysEx() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethodIsSysEx) == true);
}

void RandomizationOptions::setTransmitMethodIsSysEx(bool shouldBeSysEx) {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethodIsSysEx, shouldBeSysEx ? true : false, nullptr);
}




const bool RandomizationOptions::repeatChoicesAreAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool RandomizationOptions::repeatChoicesAreForbiddenForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void RandomizationOptions::setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}




const bool RandomizationOptions::paramIsLocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool RandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void RandomizationOptions::setParamIsLocked(uint8 paramIndex, bool shouldBeLocked) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}




const bool RandomizationOptions::choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void RandomizationOptions::setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	String choiceName{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(choiceName, (bool)true, nullptr);
	else
		if (allowedChoices.hasProperty(choiceName))
			allowedChoices.removeProperty(choiceName, nullptr);
	checkNumberOfChoicesAllowedForParam(paramIndex);
}

void RandomizationOptions::checkNumberOfChoicesAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);
	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}

void RandomizationOptions::clearAllowedChoicesForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void RandomizationOptions::allowAllChoicesForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto numberOfChoices{ info.numberOfChoicesFor(paramIndex) };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}




const bool RandomizationOptions::oscShapeIsAllowedForParam(OscWaveShape shape, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto propertyID{ "choice_" + String((int)shape) };
	return allowedShapes.hasProperty(propertyID);
}

void RandomizationOptions::allowOscShapeForParam(OscWaveShape shape, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedShapes, nullptr) };
	auto propertyID{ "choice_" + String((int)shape) };
	allowedShapes.setProperty(propertyID, (bool)true, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

void RandomizationOptions::forbidOscShapeForParam(OscWaveShape shape, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedShapes, nullptr) };
	auto propertyID{ "choice_" + String((int)shape) };
	if (allowedShapes.hasProperty(propertyID))
		allowedShapes.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

const bool RandomizationOptions::noOscShapeIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoOscShapeIsAllowed);
}

const bool RandomizationOptions::pulseWidthIsAllowedForParam(int pulseWidth, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	return allowedPulseWidths.hasProperty("choice_" + (String)pulseWidth);
}

void RandomizationOptions::allowPulseWidthForParam(int pulseWidth, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedPulseWidths, nullptr) };
	allowedPulseWidths.setProperty("choice_" + (String)pulseWidth, (bool)true, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

void RandomizationOptions::forbidPulseWidthForParam(int pulseWidth, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedPulseWidths{ allowedChoices.getOrCreateChildWithName(ID::rndm_AllowedPulseWidths, nullptr) };
	auto propertyID{ "choice_" + String(pulseWidth) };
	if (allowedPulseWidths.hasProperty(propertyID))
		allowedPulseWidths.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForOscShapeParam(paramIndex);
}

const bool RandomizationOptions::noPulseWidthIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoPulseWidthIsAllowed);
}

void RandomizationOptions::checkNumberOfChoicesAllowedForOscShapeParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto noShapes{ allowedShapes.getNumChildren() == 0 };
	paramTree.setProperty(ID::rndm_NoOscShapeIsAllowed, noShapes ? (bool)true : (bool)false, nullptr);
	auto allowedPulseWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	auto noPulseWidths{ allowedShapes.getNumChildren() == 0 };
	paramTree.setProperty(ID::rndm_NoPulseWidthIsAllowed, noPulseWidths ? (bool)true : (bool)false, nullptr);
	auto onlyOneChoice{ false };
	if (allowedShapes.getNumChildren() == 1) {
		if (allowedShapes.hasProperty("choice_" + String((int)OscWaveShape::pulse))) {
			onlyOneChoice = (allowedPulseWidths.getNumChildren() == 1);
		}
		else
			onlyOneChoice = true;
	}
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}





const bool RandomizationOptions::onlyOneChoiceIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return (bool)allowedChoices.getProperty(ID::rndm_OnlyOneChoiceIsAllowed);
}

const bool RandomizationOptions::noChoiceIsAllowedForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return (bool)allowedChoices.getProperty(ID::rndm_OnlyOneChoiceIsAllowed);
}




void RandomizationOptions::addListenerToChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).addListener(listener);
}

void RandomizationOptions::removeListenerFromChildTreeForParam(Tree::Listener* listener, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	randomizationOptionsTree.getChildWithName(paramID).removeListener(listener);
}




ValueTree RandomizationOptions::getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
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
