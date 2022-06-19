#pragma once

#include <JuceHeader.h>

#include "../../unexposedParameters/up_facade_UnexposedParameters.h"



class SliderWithMouseWheelMoveOverride : 
	public Slider
{
	UndoManager* undoManager;

public:
	bool isModifyingPitch;
	bool isModifyingSeqStep;

	SliderWithMouseWheelMoveOverride() = delete;

	SliderWithMouseWheelMoveOverride(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderWithMouseWheelMoveOverride)
};




class RotarySliderWithMouseWheelMoveOverride :
	public SliderWithMouseWheelMoveOverride
{
public:
	RotarySliderWithMouseWheelMoveOverride() = delete;

	explicit RotarySliderWithMouseWheelMoveOverride(UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseWheelMoveOverride)
};




class RotarySliderWithMouseDownModForOscShape :
	public RotarySliderWithMouseWheelMoveOverride
{
public:
	RotarySliderWithMouseDownModForOscShape() = delete;

	explicit RotarySliderWithMouseDownModForOscShape(UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseDownModForOscShape)
};




class RotarySliderWithMouseDownModForSeqStep :
	public RotarySliderWithMouseWheelMoveOverride
{
	const int trackNum;

public:
	RotarySliderWithMouseDownModForSeqStep() = delete;

	RotarySliderWithMouseDownModForSeqStep(int trackNum, UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseDownModForSeqStep)
};
