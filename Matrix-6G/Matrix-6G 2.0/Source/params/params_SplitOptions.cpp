#include "params_SplitOptions.h"

#include "params_Identifiers.h"
#include "../splits/splits_Constants.h"

using namespace constants;



SplitOptions::SplitOptions() :
	splitOptionsTree{ ID::split_Options }
{
	fillSplitOptionsTreeWithProperties();
}

void SplitOptions::fillSplitOptionsTreeWithProperties() {
	splitOptionsTree.setProperty(ID::split_Name, splits::initialSplitNameString, nullptr);
	splitOptionsTree.setProperty(ID::split_ZoneVoiceAssignment, (uint8)0, nullptr);
	splitOptionsTree.setProperty(ID::split_ZoneVolumeBalance, (uint8)31, nullptr);
	splitOptionsTree.setProperty(ID::split_LowerZoneLimit, (uint8)35, nullptr);
	splitOptionsTree.setProperty(ID::split_LowerZoneTranspose, (uint8)36, nullptr);
	splitOptionsTree.setProperty(ID::split_LowerZoneMidiOut, (uint8)1, nullptr);
	splitOptionsTree.setProperty(ID::split_UpperZoneLimit, (uint8)36, nullptr);
	splitOptionsTree.setProperty(ID::split_UpperZoneTranspose, (uint8)36, nullptr);
	splitOptionsTree.setProperty(ID::split_UpperZoneMidiOut, (uint8)1, nullptr);
	splitOptionsTree.setProperty(ID::split_LowerZoneVoiceNumber, (uint8)0, nullptr);
	splitOptionsTree.setProperty(ID::split_UpperZoneVoiceNumber, (uint8)1, nullptr);
}

void SplitOptions::addListener(ValueTree::Listener* listener) {
	splitOptionsTree.addListener(listener);
}

void SplitOptions::removeListener(ValueTree::Listener* listener) {
	splitOptionsTree.removeListener(listener);
}

const String SplitOptions::splitName() {
	return splitOptionsTree.getProperty(ID::split_Name);
}

void SplitOptions::setSplitName(String newName) {
	splitOptionsTree.setProperty(ID::split_Name, newName, nullptr);
}

const uint8 SplitOptions::zoneVoiceAssignment() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_ZoneVoiceAssignment);
}

void SplitOptions::setZoneVoiceAssignment(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_ZoneVoiceAssignment, newValue, nullptr);
}

const uint8 SplitOptions::zoneVolumeBalance() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_ZoneVolumeBalance);
}

void SplitOptions::setZoneVolumeBalance(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_ZoneVolumeBalance, newValue, nullptr);
}

const uint8 SplitOptions::lowerZoneLimit() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneLimit);
}

void SplitOptions::setLowerZoneLimit(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_LowerZoneLimit, newValue, nullptr);
}

const uint8 SplitOptions::lowerZonePatchNumber() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneVoiceNumber);
}

void SplitOptions::setLowerZonePatchNumber(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_LowerZoneVoiceNumber, newValue, nullptr);
}

const uint8 SplitOptions::lowerZoneTranspose() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneTranspose);
}

void SplitOptions::setLowerZoneTranspose(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_LowerZoneTranspose, newValue, nullptr);
}

const uint8 SplitOptions::lowerZoneMidiOut() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_LowerZoneMidiOut);
}

void SplitOptions::setLowerZoneMidiOut(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_LowerZoneMidiOut, newValue, nullptr);
}

const uint8 SplitOptions::upperZoneLimit() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneLimit);
}

void SplitOptions::setUpperZoneLimit(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_UpperZoneLimit, newValue, nullptr);
}

const uint8 SplitOptions::upperZonePatchNumber() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneVoiceNumber);
}

void SplitOptions::setUpperZonePatchNumber(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_UpperZoneVoiceNumber, newValue, nullptr);
}

const uint8 SplitOptions::upperZoneTranspose() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneTranspose);
}

void SplitOptions::setUpperZoneTranspose(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_UpperZoneTranspose, newValue, nullptr);
}

const uint8 SplitOptions::upperZoneMidiOut() {
	return (uint8)(int)splitOptionsTree.getProperty(ID::split_UpperZoneMidiOut);
}

void SplitOptions::setUpperZoneMidiOut(uint8 newValue) {
	splitOptionsTree.setProperty(ID::split_UpperZoneMidiOut, newValue, nullptr);
}

XmlElement* SplitOptions::getStateXml() {
	auto splitOptionsTreeStateXml{ splitOptionsTree.createXml() };
	splitOptionsTreeStateXml->setTagName(ID::state_SplitOptions);
	return splitOptionsTreeStateXml.release();
}

void SplitOptions::replaceState(const ValueTree& newState) {
	splitOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
