#pragma once

#include <JuceHeader.h>



// Overrides the mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step).
// Calls to beginNewTransaction() in the UndoManager are also added, so 
// that wheel moves which aren't performed in rapid succession on a single
// Slider instance are logged as discrete events for undo/redo.
class SliderWithMouseWheelMod : public Slider
{
public:
	void mouseWheelMove(const MouseEvent& /*event*/, const MouseWheelDetails& wheel) override {
		UndoManager_Singleton::get()->beginNewTransaction();
		auto delta{ wheel.deltaY };
		auto currentValue{ getValue() };
		auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f)
			setValue(currentValue + interval);
		UndoManager_Singleton::get()->beginNewTransaction();
	}
};



class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod() {
		setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
	}

	~RotarySliderWithMouseWheelMod() {
	}
};

