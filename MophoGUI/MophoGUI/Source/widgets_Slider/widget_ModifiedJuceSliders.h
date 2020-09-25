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




// A custom slider used for setting the values of sequencer steps.
// The mouseDown() function is overridden so that the slider's value
// changes to 126 (sequencer track reset) when clicked while the CTRL
// key is down. If the step is in sequencer track 1, the slider's value
// is set to 127 (rest) when clicked while the ALT key is down.
class SliderForSequencerSteps : public RotarySliderWithMouseWheelMod
{
	const int sequencerTrack;

public:
	SliderForSequencerSteps() = delete;

	SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;
};


