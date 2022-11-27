#include "ep_2_tree_ParamRandomizationOptions.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "ep_0_tree_MatrixModOptions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MatrixMod.h"

using Tree = ValueTree;

ParamRandomizationOptions::ParamRandomizationOptions(InfoForExposedParameters* info, MatrixModOptions* matrixModOptions) :
	randomizationOptionsTree{ ID::tree_RandomizationOptions },
	info{ info },
	matrixModOptions{ matrixModOptions }
{
	setTransmitMethodIsQuickEdit(true);

	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		setParamIsLocked(paramIndex, false);

		auto numberOfChoices{ info->numberOfChoicesFor(paramIndex) };
		if (numberOfChoices == 2) {
			randomizationOptionsTree.addChild(Tree{ info->IDfor(paramIndex), {}, {} }, paramIndex, nullptr);
			setRepeatChoicesAreAllowedForParam(true, paramIndex);
		}
		else {
			auto rangeIsSigned{ info->choiceNameFor(0, paramIndex).startsWith("-") };
			allowAllChoicesForParam(paramIndex, rangeIsSigned);
			setRepeatChoicesAreAllowedForParam(false, paramIndex);
		}
	}

	for (auto modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
		for (auto modType = (int)MM_Type::source; modType <= (int)MM_Type::destination; ++modType) {
			setMatrixModParamIsLocked(modNum, MM_Type{ modType }, false);
			allowAllChoicesForMatrixModParam(modNum, MM_Type{ modType });
			setRepeatChoicesAreAllowedForMatrixModParam(true, modNum, MM_Type{ modType });
		}
	}
}

const bool ParamRandomizationOptions::transmitMethodIsQuickEdit() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethodIsQuickEdit) == true);
}

void ParamRandomizationOptions::setTransmitMethodIsQuickEdit(bool shouldBeQuickEdit) {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethodIsQuickEdit, shouldBeQuickEdit ? true : false, nullptr);
}




const bool ParamRandomizationOptions::paramIsLocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool ParamRandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void ParamRandomizationOptions::setParamIsLocked(uint8 paramIndex, bool shouldBeLocked) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(info->IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}

Value ParamRandomizationOptions::getParamIsLockedAsValue(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return paramTree.getPropertyAsValue(ID::rndm_ParamIsLocked, nullptr);
}




const bool ParamRandomizationOptions::choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void ParamRandomizationOptions::setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getOrCreateChildWithName(ID::rndm_AllowedChoices, nullptr) };
	auto propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, choiceNum, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForParam(paramIndex);
}

void ParamRandomizationOptions::clearAllowedChoicesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void ParamRandomizationOptions::allowAllChoicesForParam(uint8 paramIndex, bool rangeIsSigned) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto numberOfChoices{ info->numberOfChoicesFor(paramIndex) };
	auto choiceNum{ (uint8)0 };
	if (rangeIsSigned && transmitMethodIsQuickEdit())
		choiceNum = (numberOfChoices == 63 ? (uint8)32 : (uint8)64);
	jassert(numberOfChoices > 2);
	for (choiceNum; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}

void ParamRandomizationOptions::forbidAllNegativeChoicesForAllSignedParams() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		if (info->choiceNameFor((uint8)0, paramIndex).startsWith("-")) {
			auto numberOfNegativeValues{ info->numberOfChoicesFor(paramIndex) == 63 ? (uint8)31 : (uint8)63 };
			for (auto choiceNum = (uint8)0; choiceNum != numberOfNegativeValues; ++choiceNum)
				setChoiceIsAllowedForParam(choiceNum, false, paramIndex);
			checkNumberOfChoicesAllowedForParam(paramIndex);
			if (noChoiceIsAllowedForParam(paramIndex))
				setChoiceIsAllowedForParam(numberOfNegativeValues, true, paramIndex);
		}
	}
}

void ParamRandomizationOptions::allowAllNegativeChoicesForAllSignedParams() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		if (info->choiceNameFor((uint8)0, paramIndex).startsWith("-")) {
			auto numberOfNegativeValues{ info->numberOfChoicesFor(paramIndex) == 63 ? (uint8)31 : (uint8)63 };
			for (auto choiceNum = (uint8)0; choiceNum != numberOfNegativeValues; ++choiceNum)
				setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
		}
	}
}




void ParamRandomizationOptions::checkNumberOfChoicesAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}




const bool ParamRandomizationOptions::onlyOneChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}

Value ParamRandomizationOptions::getOnlyOneChoiceIsAllowedForParamAsValue(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return paramTree.getPropertyAsValue(ID::rndm_OnlyOneChoiceIsAllowed, nullptr);
}

const bool ParamRandomizationOptions::noChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoChoiceIsAllowed) == true;
}




const bool ParamRandomizationOptions::repeatChoicesAreAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool ParamRandomizationOptions::repeatChoicesAreForbiddenForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void ParamRandomizationOptions::setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(info->IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}




ValueTree ParamRandomizationOptions::getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoicesTree{ paramTree.getChildWithName(ID::rndm_AllowedChoices).createCopy() };
	return allowedChoicesTree;
}




const bool ParamRandomizationOptions::matrixModParamIsLocked(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool ParamRandomizationOptions::matrixModParamIsUnlocked(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void ParamRandomizationOptions::setMatrixModParamIsLocked(int modNum, MM_Type paramType, bool shouldBeLocked) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(paramID, nullptr) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}

Value ParamRandomizationOptions::getMatrixModParamIsLockedAsValue(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return paramTree.getPropertyAsValue(ID::rndm_ParamIsLocked, nullptr);
}




const bool ParamRandomizationOptions::choiceIsAllowedForMatrixModParam(uint8 choiceNum, int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void ParamRandomizationOptions::setChoiceIsAllowedForMatrixModParam(
	uint8 choiceNum, bool shouldBeAllowed, int modNum, MM_Type paramType)
{
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(paramID, nullptr) };
	auto allowedChoices{ paramTree.getOrCreateChildWithName(ID::rndm_AllowedChoices, nullptr) };
	auto propertyID{ "choice_" + (String)choiceNum };
	if (shouldBeAllowed)
		allowedChoices.setProperty(propertyID, choiceNum, nullptr);
	else
		if (allowedChoices.hasProperty(propertyID))
			allowedChoices.removeProperty(propertyID, nullptr);
	checkNumberOfChoicesAllowedForMatrixModParam(modNum, paramType);
}

void ParamRandomizationOptions::clearAllowedChoicesForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void ParamRandomizationOptions::allowAllChoicesForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto numberOfChoices{ paramType == MM_Type::source ? MMOD::numberOfSrcChoices : paramType == MM_Type::amount ? MMOD::numberOfAmtChoices : MMOD::numberOfDestChoices };
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForMatrixModParam(choiceNum, true, modNum, paramType);
}




void ParamRandomizationOptions::checkNumberOfChoicesAllowedForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}




const bool ParamRandomizationOptions::onlyOneChoiceIsAllowedForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}

Value ParamRandomizationOptions::getOnlyOneChoiceIsAllowedForMatrixModParamAsValue(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return paramTree.getPropertyAsValue(ID::rndm_OnlyOneChoiceIsAllowed, nullptr);
}

const bool ParamRandomizationOptions::noChoiceIsAllowedForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return (bool)paramTree.getProperty(ID::rndm_NoChoiceIsAllowed) == true;
}




const bool ParamRandomizationOptions::repeatChoicesAreAllowedForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool ParamRandomizationOptions::repeatChoicesAreForbiddenForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void ParamRandomizationOptions::setRepeatChoicesAreAllowedForMatrixModParam(bool shouldBeAllowed, int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(paramID, nullptr) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}

ValueTree ParamRandomizationOptions::getCopyOfAllowedChoicesTreeForMatrixModParam(int modNum, MM_Type paramType) {
	jassert(modNum > -1 && modNum < MMOD::numberOfModulators);
	auto paramID{ matrixModOptions->buildMatrixModParamID(modNum, paramType) };
	auto paramTree{ randomizationOptionsTree.getChildWithName(paramID) };
	auto allowedChoicesTree{ paramTree.getChildWithName(ID::rndm_AllowedChoices).createCopy() };
	return allowedChoicesTree;
}




std::unique_ptr<XmlElement> ParamRandomizationOptions::getStateXml() {
	auto randomizationOptionsTreeStateXml{ randomizationOptionsTree.createXml() };
	if (randomizationOptionsTreeStateXml != nullptr)
		randomizationOptionsTreeStateXml->setTagName(ID::state_RandomizationOptions);
	return randomizationOptionsTreeStateXml;
}

void ParamRandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		randomizationOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
