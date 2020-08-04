#pragma once

#include <JuceHeader.h>



class ButtonForSendingProgramEditBufferDumpRequest :
	public TextButton
{
	void sendProgramEditBufferDumpRequest();

public:
	ButtonForSendingProgramEditBufferDumpRequest();
	~ButtonForSendingProgramEditBufferDumpRequest();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDumpRequest)
};
