#pragma once

#include <JuceHeader.h>

#include "up_0_tree_GlobalOptions.h"
#include "up_0_tree_SplitOptions.h"
#include "up_0_tree_TooltipsOptions.h"
#include "up_0_tree_VoiceTransmissionOptions.h"
#include "../midi/midi_0_Outgoing_MIDI_Buffers.h"
#include "../voices/voices_1_tree_VoicesBanks.h"

class UnexposedParameters
{
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<Outgoing_MIDI_Buffers> outgoing_MIDI_Buffers;
	std::unique_ptr<SplitOptions> splitOptions;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<VoicesBanks> voicesBanks;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	GlobalOptions* getGlobalOptions();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	Outgoing_MIDI_Buffers* getOutgoing_MIDI_Buffers();
	SplitOptions* getSplitOptions();
	TooltipsOptions* getTooltipsOptions();
	VoicesBanks* getVoicesBanks();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};