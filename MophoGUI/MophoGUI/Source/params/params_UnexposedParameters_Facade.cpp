#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() }
{
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

UnexposedParameters::~UnexposedParameters() {
	outgoingMidiBuffers = nullptr;
	undoManager = nullptr;
	tooltipOptions = nullptr;
}
