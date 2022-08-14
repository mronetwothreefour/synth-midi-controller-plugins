#pragma once

#include <JuceHeader.h>

#include "up_0_tree_GlobalOptions.h"
#include "up_0_tree_TooltipsOptions.h"
#include "up_0_tree_VoiceTransmissionOptions.h"
#include "../midi/midi_0_OutgoingMidiBuffers.h"

class UnexposedParameters
{
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	GlobalOptions* getGlobalOptions();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	OutgoingMidiBuffers* getOutgoingMidiBuffers();
	TooltipsOptions* getTooltipsOptions();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};