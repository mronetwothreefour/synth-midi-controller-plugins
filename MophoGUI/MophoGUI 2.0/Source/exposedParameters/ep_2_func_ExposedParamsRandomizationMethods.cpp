#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using Category = LFO_FreqCategory;
using Shape = OscWaveShape;
using StepCategory = SeqTrackStepChoiceCategory;

ExposedParamsRandomizationMethods::ExposedParamsRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	state{ exposedParams->state.get() },
	randomization{ exposedParams->randomization.get() },
	info{ exposedParams->info.get() },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
}

void ExposedParamsRandomizationMethods::randomizeAllUnlockedParameters() {
	if (randomization->transmitMethodIsSysEx() == true) {
		transmitOptions->setParamChangesShouldBeTransmitted(false);
		for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			if (paramIndex != EP::indexForArpegOnOff && paramIndex != EP::indexForSeqOnOff) {
				auto paramID{ info->IDfor(paramIndex) };
				if (randomization->paramIsUnlocked(paramIndex)) {
					auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
					applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
				}
			}
		}
		randomizeArpAndSeqOnOffParametersAfterDelay(0);
		callAfterDelay(300, [this] { SysExMessages::addEditBufferDataMessageToOutgoingBuffers(exposedParams, outgoingBuffers); });
		callAfterDelay(400, [this] { transmitOptions->setParamChangesShouldBeTransmitted(true); });
	}
	else {
		auto delayInMS{ 0 };
		for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			if (paramIndex != EP::indexForArpegOnOff && paramIndex != EP::indexForSeqOnOff) {
				auto paramID{ info->IDfor(paramIndex) };
				if (randomization->paramIsUnlocked(paramIndex)) {
					auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
					applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, delayInMS);
					delayInMS += 50;
				}
			}
		}
		randomizeArpAndSeqOnOffParametersAfterDelay(delayInMS);
	}
}

void ExposedParamsRandomizationMethods::randomizeParameter(uint8 paramIndex) {
	auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
}

void ExposedParamsRandomizationMethods::randomizeSeqTrackStep(Track track, Step step) {
	if (step == Step::all) {
		auto delayInMS{ 0 };
		for (auto stepNum = (int)Step::one; stepNum <= (int)Step::sixteen; ++stepNum) {
			auto newSetting{ randomlyChooseNewSettingForSeqTrackStep(track, Step{ stepNum }) };
			auto paramID{ info->IDfor(track, Step{ stepNum }) };
			applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, delayInMS);
			delayInMS += 50;
		}
	}
	else {
		auto newSetting{ randomlyChooseNewSettingForSeqTrackStep(track, step) };
		auto paramID{ info->IDfor(track, step) };
		applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForParam(uint8 paramIndex) {
	auto newSetting{ (uint8)255 };
	auto allowedChoicesType{ info->allowedChoicesTypeFor(paramIndex) };
	switch (allowedChoicesType)
	{
	case MophoConstants::AllowedChoicesType::standard:
		newSetting = randomlyChooseNewSettingForStandardOrVoiceNameCharParam(paramIndex);
		break;
	case MophoConstants::AllowedChoicesType::oscShape:
		newSetting = randomlyChooseNewSettingForOscShapeParam(paramIndex);
		break;
	case MophoConstants::AllowedChoicesType::binary:
		newSetting = randomlyChooseNewSettingForBinaryParam(paramIndex);
		break;
	case MophoConstants::AllowedChoicesType::lfoFreq:
		newSetting = randomlyChooseNewSettingFor_LFO_FreqParam(paramIndex);
		break;
	case MophoConstants::AllowedChoicesType::seqTrackStep: {
		auto track(info->seqTrackFor(paramIndex));
		auto step(info->seqTrackStepFor(paramIndex));
		newSetting = randomlyChooseNewSettingForSeqTrackStep(track, step);
		break;
	}
	case MophoConstants::AllowedChoicesType::voiceNameChar:
		newSetting = randomlyChooseNewSettingForStandardOrVoiceNameCharParam(paramIndex);
		break;
	default:
		break;
	}
	jassert(newSetting != 255);
	return newSetting;
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForStandardOrVoiceNameCharParam(uint8 paramIndex) {
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForParam(paramIndex) };
	if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
		auto allowedChoiceName{ allowedChoices.getPropertyName(0).toString() };
		return (uint8)(int)allowedChoices[allowedChoiceName];
	}
	else {
		if (randomization->repeatChoicesAreForbiddenForParam(paramIndex)) {
			auto paramID{ info->IDfor(paramIndex).toString() };
			auto paramPtr{ state->getParameter(paramID) };
			auto currentSetting{ paramPtr->getValue() };
			auto choiceToRemove{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
			auto nameOfPropertyToRemove{ "choice_" + (String)choiceToRemove };
			if (allowedChoices.hasProperty(nameOfPropertyToRemove))
				allowedChoices.removeProperty(nameOfPropertyToRemove, nullptr);
		}
		auto numberOfChoices{ allowedChoices.getNumProperties() };
		Random rndmNumGenerator{};
		auto newSettingIndex{ (int)floor(rndmNumGenerator.nextFloat() * numberOfChoices) };
		auto newSettingName{ allowedChoices.getPropertyName(newSettingIndex).toString() };
		return (uint8)(int)allowedChoices[newSettingName];
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForOscShapeParam(uint8 paramIndex) {
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForParam(paramIndex) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto allowedWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
		auto allowedShapeName{ allowedShapes.getPropertyName(0).toString() };
		auto allowedShape{ Shape{ (int)allowedShapes[allowedShapeName] } };
		if (allowedShape == Shape::pulse) {
			auto allowedWidthName{ allowedWidths.getPropertyName(0).toString() };
			auto allowedWidth{ (int)allowedWidths[allowedWidthName] };
			return uint8(allowedWidth);
		}
		else
			return (uint8)allowedShape;
	}
	else {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto paramPtr{ state->getParameter(paramID) };
		auto currentSetting{ paramPtr->getValue() };
		auto currentChoiceNum{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
		auto currentShape{ currentChoiceNum < (int)Shape::pulse ? Shape{ currentChoiceNum } : Shape::pulse };
		auto repeatsAreForbidden{ randomization->repeatChoicesAreForbiddenForParam(paramIndex) };
		if (repeatsAreForbidden) {
			String shapeToRemovePropertyID{ " " };
			if (currentShape != Shape::pulse) {
				shapeToRemovePropertyID = "choice_" + String((int)currentShape);
			}
			else {
				if (allowedWidths.getNumProperties() == 1) {
					if (allowedWidths.hasProperty("choice_" + (String)currentChoiceNum))
						shapeToRemovePropertyID = "choice_" + String((int)Shape::pulse);
				}
			}
			if (allowedShapes.hasProperty(shapeToRemovePropertyID))
				allowedShapes.removeProperty(shapeToRemovePropertyID, nullptr);
		}
		auto numberOfShapes{ allowedShapes.getNumProperties() };
		Random rndmNumGeneratorForShape{};
		auto newShapeIndex{ (int)floor(rndmNumGeneratorForShape.nextFloat() * numberOfShapes) };
		auto newShapeName{ allowedShapes.getPropertyName(newShapeIndex).toString() };
		auto newShape{ Shape{ (int)allowedShapes[newShapeName] } };
		if (newShape != Shape::pulse)
			return (uint8)(int)allowedShapes[newShapeName];
		else {
			if (repeatsAreForbidden && currentShape == Shape::pulse) {
				auto currentWidthPropertyID{ "choice_" + (String)currentChoiceNum };
				if (allowedWidths.hasProperty(currentWidthPropertyID))
					allowedWidths.removeProperty(currentWidthPropertyID, nullptr);
			}
			auto numberOfWidths{ allowedWidths.getNumProperties() };
			Random rndmNumGeneratorForWidth{};
			auto newWidthIndex{ (int)floor(rndmNumGeneratorForWidth.nextFloat() * numberOfWidths) };
			auto newWidthName{ allowedWidths.getPropertyName(newWidthIndex).toString() };
			return (uint8)(int)allowedWidths[newWidthName];
		}
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForBinaryParam(uint8 paramIndex) {
	if (randomization->repeatChoicesAreForbiddenForParam(paramIndex)) {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto paramPtr{ state->getParameter(paramID) };
		auto currentSetting{ roundToInt(paramPtr->getValue()) };
		auto newSetting{ 1 - currentSetting };
		return (uint8)newSetting;
	}
	else {
		Random rndmNumGenerator{};
		auto newSetting{ roundToInt(rndmNumGenerator.nextFloat()) };
		return (uint8)newSetting;
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingFor_LFO_FreqParam(uint8 paramIndex) {
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForParam(paramIndex) };
	auto allowedCategories{ allowedChoices.getChildWithName(ID::rndm_AllowedFreqCategories) };
	auto allowedUnsyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedUnsyncedFreq) };
	auto allowedPitchedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedPitchedFreq) };
	auto allowedSyncedFreq{ allowedChoices.getChildWithName(ID::rndm_AllowedSyncedFreq) };
	if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
		auto allowedCategoryChoiceName{ allowedCategories.getPropertyName(0).toString() };
		auto allowedCategory{ Category{ allowedCategoryChoiceName.fromFirstOccurrenceOf("_", false, false).getIntValue() } };
		switch (allowedCategory)
		{
		case Category::unsynced: {
			auto allowedFreqName{ allowedUnsyncedFreq.getPropertyName(0).toString() };
			return (uint8)(int)allowedUnsyncedFreq[allowedFreqName];
		}
		case Category::pitched: {
			auto allowedFreqName{ allowedPitchedFreq.getPropertyName(0).toString() };
			return (uint8)(int)allowedPitchedFreq[allowedFreqName];
		}
		case Category::synced: {
			auto allowedFreqName{ allowedSyncedFreq.getPropertyName(0).toString() };
			return (uint8)(int)allowedSyncedFreq[allowedFreqName];
		}
		default:
			return (uint8)255;
		}
	}
	else {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto paramPtr{ state->getParameter(paramID) };
		auto currentSetting{ paramPtr->getValue() };
		auto currentChoiceNum{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
		auto currentCategory{ currentChoiceNum < EP::first_LFO_PitchedFreqChoice ? Category::unsynced :
								currentChoiceNum >= EP::first_LFO_SyncedFreqChoice ? Category::synced : Category::pitched };
		auto repeatsAreForbidden{ randomization->repeatChoicesAreForbiddenForParam(paramIndex) };
		if (repeatsAreForbidden) {
			switch (currentCategory)
			{
			case Category::unsynced: {
				auto currentFreqPropertyID{ "choice_" + (String)currentChoiceNum };
				if (allowedUnsyncedFreq.hasProperty(currentFreqPropertyID))
					allowedUnsyncedFreq.removeProperty(currentFreqPropertyID, nullptr);
				}
				if (allowedUnsyncedFreq.getNumProperties() == 0) {
					auto currentCategoryPropertyID{ "choice_" + String((int)currentCategory) };
					if (allowedCategories.hasProperty(currentCategoryPropertyID))
						allowedCategories.removeProperty(currentCategoryPropertyID, nullptr);
				}
				break;
			case Category::pitched: {
				auto currentFreqPropertyID{ "choice_" + (String)currentChoiceNum };
				if (allowedPitchedFreq.hasProperty(currentFreqPropertyID))
					allowedPitchedFreq.removeProperty(currentFreqPropertyID, nullptr);
				}
				if (allowedPitchedFreq.getNumProperties() == 0) {
					auto currentCategoryPropertyID{ "choice_" + String((int)currentCategory) };
					if (allowedCategories.hasProperty(currentCategoryPropertyID))
						allowedCategories.removeProperty(currentCategoryPropertyID, nullptr);
				}
				break;
			case Category::synced: {
				auto currentFreqPropertyID{ "choice_" + (String)currentChoiceNum };
				if (allowedSyncedFreq.hasProperty(currentFreqPropertyID))
					allowedSyncedFreq.removeProperty(currentFreqPropertyID, nullptr);
				}
				if (allowedSyncedFreq.getNumProperties() == 0) {
					auto currentCategoryPropertyID{ "choice_" + String((int)currentCategory) };
					if (allowedCategories.hasProperty(currentCategoryPropertyID))
						allowedCategories.removeProperty(currentCategoryPropertyID, nullptr);
				}
				break;
			default:
				break;
			}
		}
		if (allowedCategories.getNumProperties() > 0) {
			auto numberOfCategories{ allowedCategories.getNumProperties() };
			Random rndmNumGeneratorForCategory{};
			auto newCategoryIndex{ (int)floor(rndmNumGeneratorForCategory.nextFloat() * numberOfCategories) };
			auto newCategoryChoiceName{ allowedCategories.getPropertyName(newCategoryIndex).toString() };
			auto newCategory{ Category{ (int)allowedCategories[newCategoryChoiceName] }};
			Random rndmNumGeneratorForFreq{};
			switch (newCategory)
			{
			case Category::unsynced: {
				auto numberOfAllowedFreq{ allowedUnsyncedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedUnsyncedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return (uint8)(int)allowedUnsyncedFreq[newFreqChoiceName];
			}
			case Category::pitched: {
				auto numberOfAllowedFreq{ allowedPitchedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedPitchedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return (uint8)(int)allowedPitchedFreq[newFreqChoiceName];
			}
			case Category::synced: {
				auto numberOfAllowedFreq{ allowedSyncedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedSyncedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return (uint8)(int)allowedSyncedFreq[newFreqChoiceName];
			}
			default:
				return (uint8)255;
			}
		}
		else
			return (uint8)255;
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForSeqTrackStep(Track track, Step step) {
	auto paramID{ info->IDfor(track, step).toString() };
	auto paramPtr{ state->getParameter(paramID) };
	auto currentSetting{ paramPtr->getValue() };
	auto currentChoiceNum{ (uint8)roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
	auto currentCategory{ StepCategory::numberOrPitch };
	if (currentChoiceNum == EP::choiceNumForSeqTrackStep_Reset)
		currentCategory = StepCategory::reset;
	if (currentChoiceNum == EP::choiceNumForSeqTrack_1_Step_Rest)
		currentCategory = StepCategory::rest;

	auto repeatsAreAllowed{ randomization->repeatsMustBeAllowedForSeqTrackStep(track, step) ? true :
		randomization->repeatChoicesAreAllowedForSeqTrackStep(track, step) };

	std::vector<StepCategory> categories;
	if (track == Track::one) {
		if (currentCategory != StepCategory::rest || repeatsAreAllowed) {
			auto probOfRest{ randomization->probabilityOfRestForSeqTrack_1_Step(step) };
			auto numberOfChancesForRest{ roundToInt(probOfRest * 100.0f) };
			for (auto i = 0; i != numberOfChancesForRest; ++i)
				categories.push_back(StepCategory::rest);
		}
	}
	if (step != Step::one) {
		if (currentCategory != StepCategory::reset || repeatsAreAllowed) {
			auto probOfReset{ randomization->probabilityOfResetForSeqTrackStep(track, step) };
			auto numberOfChancesForReset{ roundToInt(probOfReset * 100.0f) };
			for (auto i = 0; i != numberOfChancesForReset; ++i)
				categories.push_back(StepCategory::reset);
		}
	}
	for (auto i = (int)categories.size(); i < 100; ++i)
		categories.push_back(StepCategory::numberOrPitch);
	Random rndmNumGeneratorForCategory{};
	auto categoryIndex{ (int)floor(rndmNumGeneratorForCategory.nextFloat() * 100.0f) };
	auto categoryForNewSetting{ categories[categoryIndex] };
	switch (categoryForNewSetting)
	{
	case StepCategory::rest:
		return EP::choiceNumForSeqTrack_1_Step_Rest;
	case StepCategory::reset:
		return EP::choiceNumForSeqTrackStep_Reset;
	case StepCategory::numberOrPitch: {
		auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForSeqTrackStep(track, step) };
		if (repeatsAreAllowed == false) {
			auto currentChoicePropertyID{ "choice_" + (String)currentChoiceNum };
			if (allowedChoices.hasProperty(currentChoicePropertyID))
				allowedChoices.removeProperty(currentChoicePropertyID, nullptr);
		}
		auto numberOfChoices{ allowedChoices.getNumProperties() };
		if (numberOfChoices > 0) {
			Random rndmNumGeneratorForChoice{};
			auto choiceIndex{ (int)floor(rndmNumGeneratorForChoice.nextFloat() * numberOfChoices) };
			auto newChoiceName{ allowedChoices.getPropertyName(choiceIndex) };
			return (uint8)(int)allowedChoices[newChoiceName];
		}
		else
			return (uint8)255;
	}
	default:
		return (uint8)255;
	}
	return (uint8)255;
}

void ExposedParamsRandomizationMethods::applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs) {
	auto paramPtr{ state->getParameter(paramID) };
	if (paramPtr != nullptr) {
		auto newNormalizedSetting{ paramPtr->convertTo0to1(newSetting) };
		callAfterDelay(delayInMs, [paramPtr, newNormalizedSetting] { paramPtr->setValueNotifyingHost(newNormalizedSetting); });
	}
}

void ExposedParamsRandomizationMethods::randomizeArpAndSeqOnOffParametersAfterDelay(int delayInMs) {
	Random rndmNumGenerator{};
	auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
	auto transmitMethodIsSysEx{ randomization->transmitMethodIsSysEx() };
	auto seqDelay{ transmitMethodIsSysEx ? 0 : 50 };
	auto arpegIsUnlocked{ randomization->paramIsUnlocked(EP::indexForArpegOnOff) };
	auto arpegIsLocked{ !arpegIsUnlocked };
	auto seqIsUnlocked{ randomization->paramIsUnlocked(EP::indexForSeqOnOff) };
	auto seqIsLocked{ !seqIsUnlocked };
	auto arpegID{ info->IDfor(EP::indexForArpegOnOff) };
	auto seqID{ info->IDfor(EP::indexForSeqOnOff) };
	if (arpegIsUnlocked && seqIsUnlocked) {
		auto arpSeqOnOffChoice{ (int)std::floor(newNormalizedValue * 3) };
		switch (arpSeqOnOffChoice) {
		case 0: {
			applyNewSettingToExposedParameterAfterDelay((uint8)0, arpegID, delayInMs);
			applyNewSettingToExposedParameterAfterDelay((uint8)0, seqID, delayInMs + seqDelay);
			break;
		}
		case 1: {
			applyNewSettingToExposedParameterAfterDelay((uint8)1, arpegID, delayInMs);
			applyNewSettingToExposedParameterAfterDelay((uint8)0, seqID, delayInMs + seqDelay);
			break;
		}
		case 2: {
			applyNewSettingToExposedParameterAfterDelay((uint8)0, arpegID, delayInMs);
			applyNewSettingToExposedParameterAfterDelay((uint8)1, seqID, delayInMs + seqDelay);
			break;
		}
		default:
			break;
		}
	}
	if (arpegIsUnlocked && seqIsLocked) {
		auto arpOnOffChoice{ (uint8)roundToInt(newNormalizedValue) };
		applyNewSettingToExposedParameterAfterDelay(arpOnOffChoice, arpegID, delayInMs);
	}
	if (arpegIsLocked && seqIsUnlocked) {
		auto seqOnOffChoice{ (uint8)roundToInt(newNormalizedValue) };
		applyNewSettingToExposedParameterAfterDelay(seqOnOffChoice, seqID, delayInMs);
	}
}

void ExposedParamsRandomizationMethods::timerCallback() {
}
