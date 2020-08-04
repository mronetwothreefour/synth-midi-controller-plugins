#pragma once

#include <JuceHeader.h>



class ButtonForClearingSequencerTrack :
	public TextButton,
	private Timer
{
	int trackNum;
	AudioProcessorValueTreeState* exposedParams;
	int sequencerStep{ 0 };

	void clearSequencerTrack();
	void timerCallback() override;
	void clearSequencerStep(int step);

public:
	ButtonForClearingSequencerTrack() = delete;

	ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams);
	~ButtonForClearingSequencerTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForClearingSequencerTrack)
};

