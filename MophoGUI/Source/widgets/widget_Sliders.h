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



// A custom slider used for setting the values of steps in sequencer track 1.
// The mouseDown() function is overridden so that the slider's value
// changes to 126 (sequencer track reset) when clicked while the CTRL
// key is down, and to 127 (rest) when clicked while the ALT key is down.
class SliderForTrack1Steps : public RotarySliderWithMouseWheelMod
{
public:
	void mouseDown(const MouseEvent& e) override {
		if (e.mods.isCtrlDown())
			setValue(126.0, sendNotification);
		if (e.mods.isAltDown())
			setValue(127.0, sendNotification);
		else Slider::mouseDown(e);
	}
};



// A custom slider used for setting the values of steps in sequencer tracks 2, 3, and 4.
// The mouseDown() function is overridden so that the slider's value changes to 126
// (sequencer track reset) when clicked while the CTRL key is down
class SliderForTracks2_3_4Steps : public RotarySliderWithMouseWheelMod
{
public:
	void mouseDown(const MouseEvent& e) override {
		if (e.mods.isCtrlDown())
			setValue(126, sendNotification);
		else Slider::mouseDown(e);
	}
};


