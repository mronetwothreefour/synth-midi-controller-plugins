#include "ep_2_tree_ExposedParamsRandomizationOptions.h"

#include "ep_1_tree_InfoForExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;
using Tree = ValueTree;

ExposedParamsRandomizationOptions::ExposedParamsRandomizationOptions(InfoForExposedParameters* info) :
	randomizationOptionsTree{ ID::tree_RandomizationOptions },
	info{ info }
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
			allowAllChoicesForParam(paramIndex);
			setRepeatChoicesAreAllowedForParam(false, paramIndex);
		}
	}
}

const bool ExposedParamsRandomizationOptions::transmitMethodIsQuickEdit() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethodIsQuickEdit) == true);
}

void ExposedParamsRandomizationOptions::setTransmitMethodIsQuickEdit(bool shouldBeQuickEdit) {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethodIsQuickEdit, shouldBeQuickEdit ? true : false, nullptr);
}

const bool ExposedParamsRandomizationOptions::paramIsLocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == true);
}

const bool ExposedParamsRandomizationOptions::paramIsUnlocked(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamIsLocked) == false);
}

void ExposedParamsRandomizationOptions::setParamIsLocked(uint8 paramIndex, bool shouldBeLocked) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(info->IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_ParamIsLocked, shouldBeLocked ? true : false, nullptr);
}

Value ExposedParamsRandomizationOptions::getParamIsLockedAsValue(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return paramTree.getPropertyAsValue(ID::rndm_ParamIsLocked, nullptr);
}




const bool ExposedParamsRandomizationOptions::choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

void ExposedParamsRandomizationOptions::setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex) {
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

void ExposedParamsRandomizationOptions::clearAllowedChoicesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeAllProperties(nullptr);
}

void ExposedParamsRandomizationOptions::allowAllChoicesForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto numberOfChoices{ info->numberOfChoicesFor(paramIndex) };
	jassert(numberOfChoices > 2);
	for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
		setChoiceIsAllowedForParam(choiceNum, true, paramIndex);
}




void ExposedParamsRandomizationOptions::checkNumberOfChoicesAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };

	auto noChoices{ allowedChoices.getNumProperties() == 0 };
	paramTree.setProperty(ID::rndm_NoChoiceIsAllowed, noChoices ? (bool)true : (bool)false, nullptr);

	auto onlyOneChoice{ allowedChoices.getNumProperties() == 1 };
	paramTree.setProperty(ID::rndm_OnlyOneChoiceIsAllowed, onlyOneChoice ? (bool)true : (bool)false, nullptr);
}




const bool ExposedParamsRandomizationOptions::onlyOneChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_OnlyOneChoiceIsAllowed) == true;
}

Value ExposedParamsRandomizationOptions::getOnlyOneChoiceIsAllowedForParamAsValue(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return paramTree.getPropertyAsValue(ID::rndm_OnlyOneChoiceIsAllowed, nullptr);
}

const bool ExposedParamsRandomizationOptions::noChoiceIsAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return (bool)paramTree.getProperty(ID::rndm_NoChoiceIsAllowed) == true;
}




const bool ExposedParamsRandomizationOptions::repeatChoicesAreAllowedForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == true);
}

const bool ExposedParamsRandomizationOptions::repeatChoicesAreForbiddenForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoicesAreAllowed) == false);
}

void ExposedParamsRandomizationOptions::setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	auto paramTree{ randomizationOptionsTree.getOrCreateChildWithName(info->IDfor(paramIndex), nullptr) };
	paramTree.setProperty(ID::rndm_RepeatChoicesAreAllowed, shouldBeAllowed ? true : false, nullptr);
}




ValueTree ExposedParamsRandomizationOptions::getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex) {
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);
	auto paramTree{ randomizationOptionsTree.getChildWithName(info->IDfor(paramIndex)) };
	auto allowedChoicesTree{ paramTree.getChildWithName(ID::rndm_AllowedChoices).createCopy() };
	return allowedChoicesTree;
}




std::unique_ptr<XmlElement> ExposedParamsRandomizationOptions::getStateXml() {
	auto randomizationOptionsTreeStateXml{ randomizationOptionsTree.createXml() };
	if (randomizationOptionsTreeStateXml != nullptr)
		randomizationOptionsTreeStateXml->setTagName(ID::state_RandomizationOptions);
	return randomizationOptionsTreeStateXml;
}

void ExposedParamsRandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		randomizationOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
