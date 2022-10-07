#include "up_0_tree_SplitOptions.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_Voices.h"

SplitOptions::SplitOptions() :
	splitOptionsTree{ ID::tree_SplitOptions }
{
	setSplitName(SPLT::initialSplitNameString);
	setZoneVoiceAssignment(SplitZoneVoiceAssignment::lower_2_Upper_4);
	setZoneVolumeBalance((uint8)31);
	setZoneLimit(SplitZone::lower, (uint8)35);
	setZoneVoiceNumber(SplitZone::lower, (uint8)0);
	setZoneTranspose(SplitZone::lower, (uint8)36);
	setZone_MIDI_OutIsEnabled(SplitZone::lower, true);
	setZoneLimit(SplitZone::upper, (uint8)36);
	setZoneVoiceNumber(SplitZone::upper, (uint8)1);
	setZoneTranspose(SplitZone::upper, (uint8)36);
	setZone_MIDI_OutIsEnabled(SplitZone::upper, true);
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
	jassert(newBalance < 64);
	splitOptionsTree.setProperty(ID::split_ZoneVolumeBalance, newBalance, nullptr);
}

const uint8 SplitOptions::zoneLimit(SplitZone zone) {
	if (zone == SplitZone::lower)
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneLimit);
	else
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneLimit);
}

void SplitOptions::setZoneLimit(SplitZone zone, const uint8 newLimit) {
	jassert(newLimit < 128);
	if (zone == SplitZone::lower)
		splitOptionsTree.setProperty(ID::split_LowerZoneLimit, newLimit, nullptr);
	else
		splitOptionsTree.setProperty(ID::split_UpperZoneLimit, newLimit, nullptr);
}

const uint8 SplitOptions::zoneVoiceNumber(SplitZone zone) {
	if (zone == SplitZone::lower)
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneVoiceNumber);
	else
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneVoiceNumber);
}

void SplitOptions::setZoneVoiceNumber(SplitZone zone, const uint8 newVoiceNum) {
	jassert(newVoiceNum < VCS::numberOfSlotsInVoicesBank);
	if (zone == SplitZone::lower)
		splitOptionsTree.setProperty(ID::split_LowerZoneVoiceNumber, newVoiceNum, nullptr);
	else
		splitOptionsTree.setProperty(ID::split_UpperZoneVoiceNumber, newVoiceNum, nullptr);
}

const uint8 SplitOptions::zoneTranspose(SplitZone zone) {
	if (zone == SplitZone::lower)
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneTranspose);
	else
		return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneTranspose);
}

void SplitOptions::setZoneTranspose(SplitZone zone, const uint8 newTranspose) {
	jassert(newTranspose < 61);
	if (zone == SplitZone::lower)
		splitOptionsTree.setProperty(ID::split_LowerZoneTranspose, newTranspose, nullptr);
	else
		splitOptionsTree.setProperty(ID::split_UpperZoneTranspose, newTranspose, nullptr);
}

const bool SplitOptions::zone_MIDI_OutIsEnabled(SplitZone zone) {
	if (zone == SplitZone::lower)
		return (bool)splitOptionsTree.getProperty(ID::split_LowerZone_MIDI_OutIsEnabled);
	else
		return (bool)splitOptionsTree.getProperty(ID::split_UpperZone_MIDI_OutIsEnabled);
}

void SplitOptions::setZone_MIDI_OutIsEnabled(SplitZone zone, const bool shouldBeEnabled) {
	if (zone == SplitZone::lower)
		splitOptionsTree.setProperty(ID::split_LowerZone_MIDI_OutIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
	else
		splitOptionsTree.setProperty(ID::split_UpperZone_MIDI_OutIsEnabled, shouldBeEnabled ? (bool)true : (bool)false, nullptr);
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
