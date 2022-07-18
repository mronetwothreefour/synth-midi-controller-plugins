#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

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

void ExposedParamsRandomizationMethods::timerCallback()
{
}
