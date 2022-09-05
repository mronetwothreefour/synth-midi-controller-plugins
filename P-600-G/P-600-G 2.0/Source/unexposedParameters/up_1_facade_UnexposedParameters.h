#pragma once

#include <JuceHeader.h>

#include "up_0_tree_TooltipsOptions.h"
#include "up_0_tree_VoiceTransmissionOptions.h"
#include "../midi/midi_0_Outgoing_MIDI_Buffers.h"

class UnexposedParameters
{
	std::unique_ptr<Outgoing_MIDI_Buffers> outgoing_MIDI_Buffers;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	Outgoing_MIDI_Buffers* getOutgoing_MIDI_Buffers();
	TooltipsOptions* getTooltipsOptions();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};