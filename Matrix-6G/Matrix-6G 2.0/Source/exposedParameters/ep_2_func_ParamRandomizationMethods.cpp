#include "ep_2_func_ParamRandomizationMethods.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MatrixMod.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

ParamRandomizationMethods::ParamRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	state{ exposedParams->state.get() },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomization{ exposedParams->randomization.get() },
	info{ exposedParams->info.get() },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
}

void ParamRandomizationMethods::randomizeAllUnlockedParameters() {
	if (randomization->transmitMethodIsQuickEdit()) {
		auto delayInMS{ 0 };
		for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			auto paramID{ info->IDfor(paramIndex) };
			if (randomization->paramIsUnlocked(paramIndex)) {
				auto newSetting{ randomlyChooseNewSettingForExposedParam(paramIndex) };
				applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, delayInMS);
				delayInMS += 50;
			}
		}
	}
	else {
		transmitOptions->setParamChangesShouldBeTransmitted(false);
		for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
			auto paramID{ info->IDfor(paramIndex) };
			if (randomization->paramIsUnlocked(paramIndex)) {
				auto newSetting{ randomlyChooseNewSettingForExposedParam(paramIndex) };
				applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
			}
		}
		for (auto modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
			for (auto modType = (int)MM_Type::source; modType <= (int)MM_Type::destination; ++modType) {
				auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, MM_Type{ modType })};
				if (randomization->matrixModParamIsUnlocked(modNum, MM_Type{ modType })) {
					auto newSetting{ randomlyChooseNewSettingForMatrixModParam(modNum, MM_Type{ modType }) };
					applyNewSettingToMatrixModParam(newSetting, modNum, MM_Type{ modType });
				}
			}
		}
		callAfterDelay(300, [this] { SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, outgoingBuffers); });
		callAfterDelay(400, [this] { transmitOptions->setParamChangesShouldBeTransmitted(true); });
	}
}

void ParamRandomizationMethods::randomizeExposedParameter(uint8 paramIndex) {
	auto newSetting{ randomlyChooseNewSettingForExposedParam(paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	applyNewSettingToExposedParameterAfterDelay(newSetting, paramID, 0);
}

void ParamRandomizationMethods::randomizeMatrixModParameter(int modNum, MM_Type paramType) {
	auto newSetting{ randomlyChooseNewSettingForMatrixModParam(modNum, paramType) };
	applyNewSettingToMatrixModParam(newSetting, modNum, paramType);
}

uint8 ParamRandomizationMethods::randomlyChooseNewSettingForExposedParam(uint8 paramIndex) {
	if (info->numberOfChoicesFor(paramIndex) == 2)
		return randomlyChooseNewSettingForBinaryExposedParam(paramIndex);
	else
		return randomlyChooseNewSettingForNonBinaryExposedParam(paramIndex);
}

uint8 ParamRandomizationMethods::randomlyChooseNewSettingForBinaryExposedParam(uint8 paramIndex) {
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

uint8 ParamRandomizationMethods::randomlyChooseNewSettingForNonBinaryExposedParam(uint8 paramIndex) {
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

void ParamRandomizationMethods::applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs) {
	auto paramPtr{ state->getParameter(paramID) };
	if (paramPtr != nullptr) {
		auto newNormalizedSetting{ paramPtr->convertTo0to1(newSetting) };
		callAfterDelay(delayInMs, [paramPtr, newNormalizedSetting] { paramPtr->setValueNotifyingHost(newNormalizedSetting); });
	}
}

uint8 ParamRandomizationMethods::randomlyChooseNewSettingForMatrixModParam(int modNum, MM_Type paramType) {
	auto allowedChoices{ randomization->getCopyOfAllowedChoicesTreeForMatrixModParam(modNum, paramType) };
	if (randomization->onlyOneChoiceIsAllowedForMatrixModParam(modNum, paramType)) {
		auto allowedChoiceName{ allowedChoices.getPropertyName(0).toString() };
		return (uint8)(int)allowedChoices[allowedChoiceName];
	}
	else {
		if (randomization->repeatChoicesAreForbiddenForMatrixModParam(modNum, paramType)) {
			auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
			auto paramAsValue{ matrixModOptions->getMatrixModPropertyAsValue(paramID) };
			auto currentChoice{ (int)paramAsValue.getValue() };
			auto nameOfPropertyToRemove{ "choice_" + (String)currentChoice };
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

void ParamRandomizationMethods::applyNewSettingToMatrixModParam(uint8 newSetting, int modNum, MM_Type paramType) {
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramAsValue{ matrixModOptions->getMatrixModPropertyAsValue(paramID) };
	paramAsValue.setValue(newSetting);
}

void ParamRandomizationMethods::timerCallback() {
}
