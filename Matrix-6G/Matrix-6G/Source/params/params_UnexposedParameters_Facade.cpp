#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	currentPatchOptions{ new CurrentPatchOptions(this) },
	matrixModSettings{ new MatrixModSettings(this) },
	midiOptions{ new MidiOptions() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	patchBanks{ new PatchBanks() },
	splitOptions{ new SplitOptions() },
	splitsBank{ new SplitsBank() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

CurrentPatchOptions* UnexposedParameters::currentPatchOptions_get() {
	return currentPatchOptions.get();
}

MatrixModSettings* UnexposedParameters::matrixModSettings_get() {
	return matrixModSettings.get();
}

MidiOptions* UnexposedParameters::midiOptions_get() {
	return midiOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

PatchBanks* UnexposedParameters::patchBanks_get() {
	return patchBanks.get();
}

SplitOptions* UnexposedParameters::splitOptions_get() {
	return splitOptions.get();
}

SplitsBank* UnexposedParameters::splitsBank_get() {
	return splitsBank.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	splitsBank = nullptr;
	splitOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	midiOptions = nullptr;
	matrixModSettings = nullptr;
	currentPatchOptions = nullptr;
}
