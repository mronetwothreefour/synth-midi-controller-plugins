#pragma once

#include <JuceHeader.h>



class ButtonForSendingProgramEditBufferDump :
	public TextButton
{
	AudioProcessorValueTreeState* exposedParams;

	void sendProgramEditBufferDump();

public:
	ButtonForSendingProgramEditBufferDump() = delete;

	explicit ButtonForSendingProgramEditBufferDump(AudioProcessorValueTreeState* exposedParams);
	~ButtonForSendingProgramEditBufferDump();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSendingProgramEditBufferDump)
};

