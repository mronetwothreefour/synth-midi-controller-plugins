#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

class ButtonForSendingProgramEditBufferDumpRequest :
	public TextButton
{
	OutgoingMidiBuffers* outgoingBuffers;

	void sendProgramEditBufferDumpRequest();

public:
	explicit ButtonForSendingProgramEditBufferDumpRequest(OutgoingMidiBuffers* outgoingBuffers);
	~ButtonForSendingProgramEditBufferDumpRequest();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDumpRequest)
};
