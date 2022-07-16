#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "ep_3_facade_ExposedParameters.h"



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
		break;
	case MophoConstants::AllowedChoicesType::binary:
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
	if (allowedChoices.getNumProperties() == 1) {
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

void ExposedParamsRandomizationMethods::timerCallback()
{
}
