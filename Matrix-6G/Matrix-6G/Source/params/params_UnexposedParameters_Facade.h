#pragma once

#include <JuceHeader.h>

#include "params_CurrentPatchOptions.h"
#include "params_MatrixModSettings.h"
#include "params_MidiOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../patches/patches_PatchBanks.h"



class UnexposedParameters
{
	std::unique_ptr<CurrentPatchOptions> currentPatchOptions;
	std::unique_ptr<MatrixModSettings> matrixModSettings;
	std::unique_ptr<MidiOptions> midiOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<PatchBanks> patchBanks;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	CurrentPatchOptions* currentPatchOptions_get();
	MatrixModSettings* matrixModSettings_get();
	MidiOptions* midiOptions_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	PatchBanks* patchBanks_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};