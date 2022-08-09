#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Track = SeqTrackNum;

class SliderWithMouseWheelMoveOverride : 
	public Slider
{
	UndoManager* undoManager;

public:
	bool isModifyingPitch;
	bool isModifyingSeqStep;

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




class RotarySliderWithMouseDownModForOscShape :
	public RotarySliderWithMouseWheelMoveOverride
{
public:
	RotarySliderWithMouseDownModForOscShape() = delete;

	explicit RotarySliderWithMouseDownModForOscShape(UndoManager* undoManager);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseDownModForOscShape)
};




class RotarySliderWithMouseDownModForSeqStep :
	public RotarySliderWithMouseWheelMoveOverride
{
	const Track track;

public:
	RotarySliderWithMouseDownModForSeqStep() = delete;

	RotarySliderWithMouseDownModForSeqStep(Track track, UndoManager* undoManager);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithMouseDownModForSeqStep)
};
