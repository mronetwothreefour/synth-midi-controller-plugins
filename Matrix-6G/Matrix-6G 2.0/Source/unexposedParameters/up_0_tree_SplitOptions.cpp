#include "up_0_tree_SplitOptions.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"

SplitOptions::SplitOptions() :
	splitOptionsTree{ ID::tree_SplitOptions }
{
	setSplitName(SPLT::initialSplitNameString);
	setZoneVoiceAssignment(SplitZoneVoiceAssignment::lower_2_Upper_4);
	setZoneVolumeBalance((uint8)31);
	setLowerZoneLimit((uint8)35);
	setLowerZoneVoiceNumber((uint8)0);
	setLowerZoneTranspose((uint8)36);
	setLowerZoneMidiOutIsEnabled(true);
	setUpperZoneLimit((uint8)36);
	setUpperZoneVoiceNumber((uint8)1);
	setUpperZoneTranspose((uint8)36);
	setUpperZoneMidiOutIsEnabled(true);
}

const String SplitOptions::splitName() {
	return splitOptionsTree.getProperty(ID::split_Name).toString();
}

void SplitOptions::setSplitName(const String newName) {
	splitOptionsTree.setProperty(ID::split_Name, newName, nullptr);
}

const SplitZoneVoiceAssignment SplitOptions::zoneVoiceAssignment() {
	return SplitZoneVoiceAssignment{ (int)splitOptionsTree.getProperty(ID::split_ZoneVoiceAssignment) };
}

void SplitOptions::setZoneVoiceAssignment(const SplitZoneVoiceAssignment newAssignment) {
	splitOptionsTree.setProperty(ID::split_ZoneVoiceAssignment, (int)newAssignment, nullptr);
}

const uint8 SplitOptions::zoneVolumeBalance() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_ZoneVolumeBalance);
}

void SplitOptions::setZoneVolumeBalance(const uint8 newBalance) {
	splitOptionsTree.setProperty(ID::split_ZoneVolumeBalance, newBalance, nullptr);
}

const uint8 SplitOptions::lowerZoneLimit() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneLimit);
}

void SplitOptions::setLowerZoneLimit(const uint8 newLimit) {
	splitOptionsTree.setProperty(ID::split_LowerZoneLimit, newLimit, nullptr);
}

const uint8 SplitOptions::lowerZoneVoiceNumber() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneVoiceNumber);
}

void SplitOptions::setLowerZoneVoiceNumber(const uint8 newVoiceNum) {
	splitOptionsTree.setProperty(ID::split_LowerZoneVoiceNumber, newVoiceNum, nullptr);
}

const uint8 SplitOptions::lowerZoneTranspose() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneTranspose);
}

void SplitOptions::setLowerZoneTranspose(const uint8 newTranspose) {
	splitOptionsTree.setProperty(ID::split_LowerZoneTranspose, newTranspose, nullptr);
}

const bool SplitOptions::lowerZoneMidiOutIsEnabled() {
	return (bool)splitOptionsTree.getProperty(ID::split_LowerZoneMidiOutIsEnabled);
}

void SplitOptions::setLowerZoneMidiOutIsEnabled(const bool shouldBeEnabled) {
	splitOptionsTree.setProperty(ID::split_LowerZoneMidiOutIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

const uint8 SplitOptions::upperZoneLimit() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneLimit);
}

void SplitOptions::setUpperZoneLimit(const uint8 newLimit) {
	splitOptionsTree.setProperty(ID::split_UpperZoneLimit, newLimit, nullptr);
}

const uint8 SplitOptions::upperZoneVoiceNumber() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneVoiceNumber);
}

void SplitOptions::setUpperZoneVoiceNumber(const uint8 newVoiceNum) {
	splitOptionsTree.setProperty(ID::split_UpperZoneVoiceNumber, newVoiceNum, nullptr);
}

const uint8 SplitOptions::upperZoneTranspose() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneTranspose);
}

void SplitOptions::setUpperZoneTranspose(const uint8 newTranspose) {
	splitOptionsTree.setProperty(ID::split_UpperZoneTranspose, newTranspose, nullptr);
}

const bool SplitOptions::upperZoneMidiOutIsEnabled() {
	return (bool)splitOptionsTree.getProperty(ID::split_UpperZoneMidiOutIsEnabled);
}

void SplitOptions::setUpperZoneMidiOutIsEnabled(const bool shouldBeEnabled) {
	splitOptionsTree.setProperty(ID::split_UpperZoneMidiOutIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
}

Value SplitOptions::getSplitParamAsValue(const Identifier paramID) {
	return splitOptionsTree.getPropertyAsValue(paramID, nullptr);
}

std::unique_ptr<XmlElement> SplitOptions::getStateXml() {
	auto splitOptionsTreeStateXml{ splitOptionsTree.createXml() };
	if (splitOptionsTreeStateXml != nullptr)
		splitOptionsTreeStateXml->setTagName(ID::state_TooltipsOptions);
	return splitOptionsTreeStateXml;
}

void SplitOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		splitOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
