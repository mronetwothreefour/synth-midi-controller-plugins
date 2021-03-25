#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	currentPatchOptions{ new CurrentPatchOptions(this) },
	masterOptions{ new MasterOptions() },
	matrixModSettings{ new MatrixModSettings(this) },
	patchTransmissionOptions{ new PatchTransmissionOptions() },
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

MasterOptions* UnexposedParameters::masterOptions_get() {
	return masterOptions.get();
}

MatrixModSettings* UnexposedParameters::matrixModSettings_get() {
	return matrixModSettings.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

PatchBanks* UnexposedParameters::patchBanks_get() {
	return patchBanks.get();
}

PatchTransmissionOptions* UnexposedParameters::patchTransmissionOptions_get() {
	return patchTransmissionOptions.get();
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
	patchTransmissionOptions = nullptr;
	matrixModSettings = nullptr;
	masterOptions = nullptr;
	currentPatchOptions = nullptr;
}
