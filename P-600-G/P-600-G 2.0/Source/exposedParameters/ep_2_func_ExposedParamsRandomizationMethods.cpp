#include "ep_2_func_ExposedParamsRandomizationMethods.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

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
	transmitOptions->setParamChangesShouldBeTransmitted(false);
	for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		if (randomization->paramIsUnlocked(paramIndex)) {
			auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
			applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
		}
	}
	callAfterDelay(200, [this]
		{ SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers); }
	);
	callAfterDelay(300, [this] { transmitOptions->setParamChangesShouldBeTransmitted(true); });
}

void ExposedParamsRandomizationMethods::randomizeParameter(uint8 paramIndex) {
	auto newSetting{ randomlyChooseNewSettingForParam(paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForParam(uint8 paramIndex) {
	if (info->numberOfChoicesFor(paramIndex) == 2)
		return randomlyChooseNewSettingForBinaryParam(paramIndex);
	else
		return randomlyChooseNewSettingForNonBinaryParam(paramIndex);
}

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForBinaryParam(uint8 paramIndex) {
	auto paramID{ info->IDfor(paramIndex).toString() };
	auto paramPtr{ state->getParameter(paramID) };
	if (randomization->repeatChoicesAreForbiddenForParam(paramIndex)) {
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

uint8 ExposedParamsRandomizationMethods::randomlyChooseNewSettingForNonBinaryParam(uint8 paramIndex) {
	auto paramID{ info->IDfor(paramIndex).toString() };
	auto paramPtr{ state->getParameter(paramID) };
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForParam(paramIndex) };
	if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
		auto allowedChoiceName{ allowedChoices.getPropertyName(0).toString() };
		return (uint8)(int)allowedChoices[allowedChoiceName];
	}
	else {
		if (randomization->repeatChoicesAreForbiddenForParam(paramIndex)) {
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

void ExposedParamsRandomizationMethods::applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs) {
	auto paramPtr{ state->getParameter(paramID) };
	if (paramPtr != nullptr) {
		auto newNormalizedSetting{ paramPtr->convertTo0to1(newSetting) };
		callAfterDelay(delayInMs, [paramPtr, newNormalizedSetting] { paramPtr->setValueNotifyingHost(newNormalizedSetting); });
	}
}

void ExposedParamsRandomizationMethods::timerCallback() {
}
