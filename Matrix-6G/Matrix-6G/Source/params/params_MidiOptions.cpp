#include "params_MidiOptions.h"

#include "params_Identifiers.h"



MidiOptions::MidiOptions() :
	midiOptionsTree{ ID::midi_Options }
{
	fillMidiOptionsTreeWithProperties();
}

void MidiOptions::fillMidiOptionsTreeWithProperties() {
	midiOptionsTree.setProperty(ID::midi_BasicChannel, (uint8)1, nullptr);
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_PatchTransmitTime, 300, nullptr);
}

void MidiOptions::addListener(ValueTree::Listener* listener) {
	midiOptionsTree.addListener(listener);
}

void MidiOptions::removeListener(ValueTree::Listener* listener) {
	midiOptionsTree.removeListener(listener);
}

const uint8 MidiOptions::basicChannel() {
	return (uint8)(int)midiOptionsTree.getProperty(ID::midi_BasicChannel);
}

void MidiOptions::setBasicChannel(uint8 newChannel) {
	midiOptionsTree.setProperty(ID::midi_BasicChannel, newChannel, nullptr);
}

bool MidiOptions::incomingPatchShouldBeSavedInCustomBankA() {
	return (bool)midiOptionsTree.getProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA);
}

bool MidiOptions::incomingPatchShouldBeSavedInCustomBankB() {
	return (bool)midiOptionsTree.getProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB);
}

void MidiOptions::setIncomingPatchShouldBeSavedInCustomBankA() {
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)true, nullptr);
}

void MidiOptions::setIncomingPatchShouldBeSavedInCustomBankB() {
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)true, nullptr);
}

void MidiOptions::setIncomingPatchShouldNotBeSavedInCustomBank() {
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankA, (bool)false, nullptr);
	midiOptionsTree.setProperty(ID::midi_IncomingPatchShouldBeSavedInCustomBankB, (bool)false, nullptr);
}

bool MidiOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)midiOptionsTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void MidiOptions::setParamChangeEchosAreBlocked() {
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void MidiOptions::setParamChangeEchosAreNotBlocked() {
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

const int MidiOptions::patchTransmitTime() {
	return (int)midiOptionsTree.getProperty(ID::midi_PatchTransmitTime);
}

void MidiOptions::setPatchTransmitTime(int timeInMilliseconds) {
	midiOptionsTree.setProperty(ID::midi_PatchTransmitTime, timeInMilliseconds, nullptr);
}
