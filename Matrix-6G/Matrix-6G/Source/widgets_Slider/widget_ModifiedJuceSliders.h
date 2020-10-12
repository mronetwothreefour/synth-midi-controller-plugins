#pragma once

#include <JuceHeader.h>

#include "../params/params_UnexposedParameters_Facade.h"



// Overrides the mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step).
// Calls to beginNewTransaction() in the UndoManager are also added, so 
// that wheel moves which aren't performed in rapid succession on a single
// Slider instance are logged as discrete events for undo/redo.
class SliderWithMouseWheelMod : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelMod() = delete;

	explicit SliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& /*event*/, const MouseWheelDetails& wheel) override;
};




class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod() = delete;

	explicit RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
};




class LinearSliderWithMouseWheelModAndReversedRange : public SliderWithMouseWheelMod
{
public:
	LinearSliderWithMouseWheelModAndReversedRange() = delete;

	explicit LinearSliderWithMouseWheelModAndReversedRange(UnexposedParameters* unexposedParams);
	double proportionOfLengthToValue(double proportion) override;
	double valueToProportionOfLength(double value) override;
};

