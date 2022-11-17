#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParamsRandomizationOptions;
class TooltipsOptions;

class AllowRepeatChoicesToggle_SeqTrackStep :
	public Component,
	public Value::Listener
{
	Track track;
	Step step;
	ExposedParamsRandomizationOptions* randomization;
	Value repeatsMustBeAllowedForStepAsValue;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle_SeqTrackStep() = delete;

	AllowRepeatChoicesToggle_SeqTrackStep(Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~AllowRepeatChoicesToggle_SeqTrackStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle_SeqTrackStep)
};