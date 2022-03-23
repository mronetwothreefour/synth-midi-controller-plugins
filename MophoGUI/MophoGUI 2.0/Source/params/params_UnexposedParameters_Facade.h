#pragma once

#include <JuceHeader.h>

#include "params_GlobalOptions.h"
#include "params_RandomizationOptions.h"
#include "params_VoiceTransmissionOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../voices/voices_VoicesBanks.h"



class UnexposedParameters
{
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<RandomizationOptions> randomizationOptions;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<VoicesBanks> voicesBanks;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	GlobalOptions* globalOptions_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	RandomizationOptions* randomizationOptions_get();
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

