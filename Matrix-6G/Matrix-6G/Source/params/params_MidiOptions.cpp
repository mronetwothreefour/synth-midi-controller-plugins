#include "params_MidiOptions.h"

#include "params_Identifiers.h"



MidiOptions::MidiOptions() :
	midiOptionsTree{ ID::midi_Options }
{
	fillMidiOptionsTreeWithProperties();
}

void MidiOptions::fillMidiOptionsTreeWithProperties() {
	midiOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

void MidiOptions::addListener(ValueTree::Listener* listener) {
	midiOptionsTree.addListener(listener);
}

void MidiOptions::removeListener(ValueTree::Listener* listener) {
	midiOptionsTree.removeListener(listener);
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
