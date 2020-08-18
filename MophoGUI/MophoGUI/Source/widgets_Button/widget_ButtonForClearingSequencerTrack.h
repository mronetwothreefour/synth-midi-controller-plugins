#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ButtonForClearingSequencerTrack :
	public BaseButtonWithOnClickAndTooltipMethods,
	private Timer
{
	int trackNum;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	int sequencerStep{ 0 };

public:
	ButtonForClearingSequencerTrack() = delete;

	ButtonForClearingSequencerTrack(int trackNum, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	void timerCallback() override;
	void clearSequencerStep(int step);

public:
	~ButtonForClearingSequencerTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForClearingSequencerTrack)
};

