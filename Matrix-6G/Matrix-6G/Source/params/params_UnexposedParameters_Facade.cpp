#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	undoManager{ new UndoManager() }
{
}

MidiOptions* UnexposedParameters::midiOptions_get() {
	return midiOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	midiOptions = nullptr;
}
