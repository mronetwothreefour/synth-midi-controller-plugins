#include "up_0_tree_TooltipsOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

TooltipsOptions::TooltipsOptions() :
    tooltipsOptionsTree{ ID::tree_TooltipsOptions }
{
    setShouldShowCurrentChoice(true);
    setShouldShowDescription(true);
    setDelayInMilliseconds(2500);
}

const bool TooltipsOptions::shouldShowCurrentChoice() {
    return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentChoice) == true;
}

void TooltipsOptions::setShouldShowCurrentChoice(const bool shouldShow) {
    tooltipsOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentChoice, shouldShow ? (bool)true : (bool)false, nullptr);
}

const bool TooltipsOptions::shouldShowDescription() {
    return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShouldShowDescription) == true;
}

void TooltipsOptions::setShouldShowDescription(const bool shouldShow) {
    tooltipsOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, shouldShow ? (bool)true : (bool)false, nullptr);
}

const int TooltipsOptions::delayInMilliseconds() {
    return (int)tooltipsOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipsOptions::setDelayInMilliseconds(const int newDelay) {
    tooltipsOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}

Value TooltipsOptions::getTooltipsPropertyAsValue(const Identifier propertyID) {
    return tooltipsOptionsTree.getPropertyAsValue(propertyID, nullptr);
}

std::unique_ptr<XmlElement> TooltipsOptions::getStateXml() {
    auto tooltipsOptionsTreeStateXml{ tooltipsOptionsTree.createXml() };
    if (tooltipsOptionsTreeStateXml != nullptr)
        tooltipsOptionsTreeStateXml->setTagName(ID::state_TooltipsOptions);
    return tooltipsOptionsTreeStateXml;
}

void TooltipsOptions::replaceState(const ValueTree& newState) {
    if (newState.isValid())
        tooltipsOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
