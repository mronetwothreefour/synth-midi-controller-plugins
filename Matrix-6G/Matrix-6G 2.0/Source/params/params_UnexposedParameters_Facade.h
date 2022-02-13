#pragma once

#include <JuceHeader.h>

#include "params_CurrentVoiceOptions.h"
#include "params_GlobalOptions.h"
#include "params_MatrixModSettings.h"
#include "params_SplitOptions.h"
#include "params_TooltipOptions.h"
#include "params_VoiceTransmissionOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../voices/voices_VoicesBanks.h"
#include "../splits/splits_SplitsBank.h"



class UnexposedParameters
{
	std::unique_ptr<CurrentVoiceOptions> currentVoiceOptions;
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<MatrixModSettings> matrixModSettings;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<SplitOptions> splitOptions;
	std::unique_ptr<SplitsBank> splitsBank;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<VoicesBanks> voicesBanks;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	CurrentVoiceOptions* currentVoiceOptions_get();
	GlobalOptions* globalOptions_get();
	MatrixModSettings* matrixModSettings_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	SplitOptions* splitOptions_get();
	SplitsBank* splitsBank_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	VoicesBanks* voicesBanks_get();
	VoiceTransmissionOptions* voiceTransmissionOptions_get();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};