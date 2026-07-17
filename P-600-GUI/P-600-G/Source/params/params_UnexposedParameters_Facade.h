#pragma once

#include <JuceHeader.h>

#include "params_TooltipOptions.h"
#include "params_VoiceTransmissionOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../voices/voices_VoicesBank.h"



class UnexposedParameters
{
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<VoicesBank> voicesBank;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	VoicesBank* voicesBank_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	VoiceTransmissionOptions* voiceTransmissionOptions_get();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};