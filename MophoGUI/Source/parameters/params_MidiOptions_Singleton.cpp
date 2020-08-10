#include "params_MidiOptions_Singleton.h"

#include "../helpers/helper_Identifiers.h"



MidiOptions::MidiOptions() :
	midiParametersTree{ ID::midi_Options }
{
	fillMidiOptionsTreeWithProperties();
}

MidiOptions::~MidiOptions() {
}

void MidiOptions::fillMidiOptionsTreeWithProperties() {
	midiParametersTree.setProperty(ID::midi_Channel, (uint8)0, nullptr);
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	midiParametersTree.setProperty(ID::midi_ProgramTransmitTime, 300, nullptr);
}

MidiOptions& MidiOptions::get() {
	static MidiOptions midiParameters_Singleton;
	return midiParameters_Singleton;
}

void MidiOptions::addListener(ValueTree::Listener* listener) {
	midiParametersTree.addListener(listener);
}

void MidiOptions::removeListener(ValueTree::Listener* listener) {
	midiParametersTree.removeListener(listener);
}

uint8 MidiOptions::channel() {
	return (uint8)(int)midiParametersTree.getProperty(ID::midi_Channel);
}

void MidiOptions::setChannel(uint8 newChannel) {
	midiParametersTree.setProperty(ID::midi_Channel, newChannel, nullptr);
}

bool MidiOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)midiParametersTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void MidiOptions::setParamChangeEchosAreBlocked() {
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void MidiOptions::setParamChangeEchosAreNotBlocked() {
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

int MidiOptions::programTransmitTime() {
	return (int)midiParametersTree.getProperty(ID::midi_ProgramTransmitTime);
}

void MidiOptions::setProgramTransmitTime(int timeInMilliseconds) {
	midiParametersTree.setProperty(ID::midi_ProgramTransmitTime, timeInMilliseconds, nullptr);
}

