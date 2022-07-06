#pragma once

#include <JuceHeader.h>

#include "up_tree_GlobalOptions.h"
#include "up_tree_TooltipsOptions.h"
#include "up_tree_VoiceTransmissionOptions.h"
#include "../midi/midi_0_OutgoingMidiBuffers.h"
#include "../voices/voices_1_tree_VoicesBanks.h"



class UnexposedParameters
{
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<VoicesBanks> voicesBanks;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	GlobalOptions* getGlobalOptions();
	OutgoingMidiBuffers* getOutgoingMidiBuffers();
	TooltipsOptions* getTooltipsOptions();
	VoicesBanks* getVoicesBanks();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};