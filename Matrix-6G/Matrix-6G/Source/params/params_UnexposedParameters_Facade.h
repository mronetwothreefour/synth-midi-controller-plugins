#pragma once

#include <JuceHeader.h>

#include "params_CurrentPatchOptions.h"
#include "params_MasterOptions.h"
#include "params_MatrixModSettings.h"
#include "params_PatchTransmissionOptions.h"
#include "params_SplitOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../patches/patches_PatchBanks.h"
#include "../splits/splits_SplitsBank.h"



class UnexposedParameters
{
	std::unique_ptr<CurrentPatchOptions> currentPatchOptions;
	std::unique_ptr<MasterOptions> masterOptions;
	std::unique_ptr<MatrixModSettings> matrixModSettings;
	std::unique_ptr<PatchTransmissionOptions> patchTransmissionOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<PatchBanks> patchBanks;
	std::unique_ptr<SplitOptions> splitOptions;
	std::unique_ptr<SplitsBank> splitsBank;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	CurrentPatchOptions* currentPatchOptions_get();
	MasterOptions* masterOptions_get();
	MatrixModSettings* matrixModSettings_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	PatchBanks* patchBanks_get();
	PatchTransmissionOptions* patchTransmissionOptions_get();
	SplitOptions* splitOptions_get();
	SplitsBank* splitsBank_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};