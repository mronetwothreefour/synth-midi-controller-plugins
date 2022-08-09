#pragma once

#include <JuceHeader.h>

class SliderWithMouseWheelMoveOverride :
	public Slider
{
	UndoManager* undoManager;

public:
	bool isModifyingPitch;

	SliderWithMouseWheelMoveOverride() = delete;

	SliderWithMouseWheelMoveOverride(UndoManager* undoManager);
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

	explicit RotarySliderWithMouseWheelMoveOverride(UndoManager* undoManager);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseWheelMoveOverride)
};




class LinearSliderWithMouseWheelMoveOverride :
	public SliderWithMouseWheelMoveOverride
{
public:
	LinearSliderWithMouseWheelMoveOverride() = delete;

	explicit LinearSliderWithMouseWheelMoveOverride(UndoManager* undoManager);
};
