#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using Category = LFO_FreqCategory;
using Shape = OscWaveShape;



ExposedParamsRandomizationMethods::ExposedParamsRandomizationMethods(ExposedParameters* exposedParams) :
	state{ exposedParams->state.get() },
	randomization{ exposedParams->randomization.get() },
	info{ exposedParams->info.get() }
{
}

void ExposedParamsRandomizationMethods::randomizeAllUnlockedParameters()
{
}

void ExposedParamsRandomizationMethods::randomizeParameter(uint8 paramIndex) {
	auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	auto paramPtr{ state->getParameter(paramID) };
	if (paramPtr != nullptr)
		paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
}

void ExposedParamsRandomizationMethods::randomizeSeqTrack(Track /*track*/)
{
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
	case MophoConstants::AllowedChoicesType::seqTrackStep:
		break;
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
		auto allowedChoiceNum{ allowedChoiceName.fromFirstOccurrenceOf("choice_", false, false).getIntValue() };
		return (uint8)allowedChoiceNum;
	}
	else {
		if (randomization->repeatChoicesAreForbiddenForParam(paramIndex)) {
			auto paramID{ info->IDfor(paramIndex).toString() };
			auto paramPtr{ state->getParameter(paramID) };
			auto currentSetting{ paramPtr->getValue() };
			auto choiceToRemove{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
			auto propertyID{ "choice_" + (String)choiceToRemove };
			if (allowedChoices.hasProperty(propertyID))
				allowedChoices.removeProperty(propertyID, nullptr);
		}
		auto numberOfChoices{ allowedChoices.getNumProperties() };
		Random rndmNumGenerator{};
		auto newSettingIndex{ (int)floor(rndmNumGenerator.nextFloat() * numberOfChoices) };
		auto newSettingName{ allowedChoices.getPropertyName(newSettingIndex).toString() };
		return uint8(newSettingName.fromFirstOccurrenceOf("choice_", false, false).getIntValue());
	}
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForOscShapeParam(uint8 paramIndex) {
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForParam(paramIndex) };
	auto allowedShapes{ allowedChoices.getChildWithName(ID::rndm_AllowedShapes) };
	auto allowedWidths{ allowedChoices.getChildWithName(ID::rndm_AllowedPulseWidths) };
	if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
		auto allowedShapeName{ allowedShapes.getPropertyName(0).toString() };
		auto allowedShape{ Shape{ allowedShapeName.fromFirstOccurrenceOf("_", false, false).getIntValue() } };
		if (allowedShape == Shape::pulse) {
			auto allowedWidthName{ allowedWidths.getPropertyName(0).toString() };
			auto allowedWidth{ allowedWidthName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
			return uint8((int)Shape::pulse + allowedWidth);
		}
		else
			return (uint8)allowedShape;
	}
	else {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto paramPtr{ state->getParameter(paramID) };
		auto currentSetting{ paramPtr->getValue() };
		auto currentSettingNum{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
		auto repeatsAreForbidden{ randomization->repeatChoicesAreForbiddenForParam(paramIndex) };
		if (repeatsAreForbidden && currentSettingNum < (int)Shape::pulse) {
			auto currentSettingPropertyID{ "choice_" + (String)currentSettingNum };
			if (allowedShapes.hasProperty(currentSettingPropertyID))
				allowedShapes.removeProperty(currentSettingPropertyID, nullptr);
		}
		auto numberOfShapes{ allowedShapes.getNumProperties() };
		Random rndmNumGeneratorForShape{};
		auto newShapeIndex{ (int)floor(rndmNumGeneratorForShape.nextFloat() * numberOfShapes) };
		auto newShapeName{ allowedShapes.getPropertyName(newShapeIndex).toString() };
		if (newShapeName != "choice_" + String((int)Shape::pulse))
			return uint8(newShapeName.fromFirstOccurrenceOf("choice_", false, false).getIntValue());
		else {
			if (repeatsAreForbidden && currentSettingNum >= (int)Shape::pulse) {
				auto currentWidthPropertyID{ "choice_" + String(currentSettingNum - (int)Shape::pulse) };
				if (allowedWidths.hasProperty(currentWidthPropertyID))
					allowedWidths.removeProperty(currentWidthPropertyID, nullptr);
			}
			auto numberOfWidths{ allowedWidths.getNumProperties() };
			Random rndmNumGeneratorForWidth{};
			auto newWidthIndex{ (int)floor(rndmNumGeneratorForWidth.nextFloat() * numberOfWidths) };
			auto newWidthName{ allowedWidths.getPropertyName(newWidthIndex).toString() };
			auto newWidthNum{ newWidthName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
			return uint8(newWidthNum + (int)Shape::pulse);
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
			auto allowedFreqNum{ allowedFreqName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
			return (uint8)allowedFreqNum;
		}
		case Category::pitched: {
			auto allowedFreqName{ allowedPitchedFreq.getPropertyName(0).toString() };
			auto allowedFreqNum{ allowedFreqName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
			return uint8(allowedFreqNum + EP::firstLFO_PitchedFreqChoice);
		}
		case Category::synced: {
			auto allowedFreqName{ allowedSyncedFreq.getPropertyName(0).toString() };
			auto allowedFreqNum{ allowedFreqName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
			return uint8(allowedFreqNum + EP::firstLFO_SyncedFreqChoice);
		}
		default:
			return (uint8)255;
		}
	}
	else {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto paramPtr{ state->getParameter(paramID) };
		auto currentSetting{ paramPtr->getValue() };
		auto currentSettingNum{ roundToInt(paramPtr->convertFrom0to1(currentSetting)) };
		auto currentCategory{ currentSettingNum < EP::firstLFO_PitchedFreqChoice ? Category::unsynced :
								currentSettingNum >= EP::firstLFO_SyncedFreqChoice ? Category::synced : Category::pitched };
		auto repeatsAreForbidden{ randomization->repeatChoicesAreForbiddenForParam(paramIndex) };
		if (repeatsAreForbidden) {
			switch (currentCategory)
			{
			case Category::unsynced: {
				auto currentFreqPropertyID{ "choice_" + (String)currentSettingNum };
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
				auto currentFreqPropertyID{ "choice_" + String(currentSettingNum - EP::firstLFO_PitchedFreqChoice) };
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
				auto currentFreqPropertyID{ "choice_" + String(currentSettingNum - EP::firstLFO_SyncedFreqChoice) };
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
			auto newCategory{ Category{ newCategoryChoiceName.fromFirstOccurrenceOf("_", false, false).getIntValue() } };
			Random rndmNumGeneratorForFreq{};
			switch (newCategory)
			{
			case Category::unsynced: {
				auto numberOfAllowedFreq{ allowedUnsyncedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedUnsyncedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return uint8(newFreqChoiceName.fromFirstOccurrenceOf("_", false, false).getIntValue());
			}
			case Category::pitched: {
				auto numberOfAllowedFreq{ allowedPitchedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedPitchedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return uint8(newFreqChoiceName.fromFirstOccurrenceOf("_", false, false).getIntValue() + EP::firstLFO_PitchedFreqChoice);
			}
			case Category::synced: {
				auto numberOfAllowedFreq{ allowedSyncedFreq.getNumProperties() };
				auto newFreqChoiceIndex{ (int)floor(rndmNumGeneratorForFreq.nextFloat() * numberOfAllowedFreq) };
				auto newFreqChoiceName{ allowedSyncedFreq.getPropertyName(newFreqChoiceIndex).toString() };
				return uint8(newFreqChoiceName.fromFirstOccurrenceOf("_", false, false).getIntValue() + EP::firstLFO_SyncedFreqChoice);
			}
			default:
				return (uint8)255;
			}
		}
		else
			return (uint8)255;
	}
}

void ExposedParamsRandomizationMethods::timerCallback()
{
}
