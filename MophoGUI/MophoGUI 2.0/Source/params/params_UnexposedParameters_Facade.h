#pragma once

#include <JuceHeader.h>

#include "params_GlobalAudioOptions.h"
#include "params_MidiOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../voices/voices_VoicesBanks.h"



class UnexposedParameters
{
	std::unique_ptr<GlobalAudioOptions> globalAudioOptions;
	std::unique_ptr<MidiOptions> midiOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<VoicesBanks> voicesBanks;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	GlobalAudioOptions* globalAudioOptions_get();
	MidiOptions* midiOptions_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	VoicesBanks* voicesBanks_get();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};

