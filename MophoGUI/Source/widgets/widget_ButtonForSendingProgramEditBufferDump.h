#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

class ButtonForSendingProgramEditBufferDump :
	public TextButton
{
	AudioProcessorValueTreeState* exposedParams;
	OutgoingMidiBuffers* outgoingBuffers;

	void sendProgramEditBufferDump();

public:
	ButtonForSendingProgramEditBufferDump() = delete;

	ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);
	~ButtonForSendingProgramEditBufferDump();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDump)
};

