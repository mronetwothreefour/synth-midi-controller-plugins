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




// Like SliderWithMouseWheelMod, but also modifies mouseWheelMove()
// so that the slider is incremented by 12 (one octave) when the 
// SHIFT key is being held down. 
class SliderWithMouseWheelModForPitch : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelModForPitch() = delete;

	explicit SliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;
};




// Like SliderWithMouseWheelMod, but also modifies mouseWheelMove()
// so that the slider is incremented by 24 (one octave, including 
// 'bent' pitches) when the SHIFT key is being held down. 
class SliderWithMouseWheelModForSeqStep : public Slider
{
	UnexposedParameters* unexposedParams;

public:
	SliderWithMouseWheelModForSeqStep() = delete;

	explicit SliderWithMouseWheelModForSeqStep(UnexposedParameters* unexposedParams);
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;
};




class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod() = delete;

	explicit RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams);
};




class RotarySliderWithMouseWheelModForPitch : public SliderWithMouseWheelModForPitch
{
public:
	RotarySliderWithMouseWheelModForPitch() = delete;

	explicit RotarySliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams);
};




class RotarySliderWithMouseWheelModForSeqStep : public SliderWithMouseWheelModForSeqStep
{
public:
	RotarySliderWithMouseWheelModForSeqStep() = delete;

	explicit RotarySliderWithMouseWheelModForSeqStep(UnexposedParameters* unexposedParams);
};




// A custom slider used for setting the values of sequencer steps.
// The mouseDown() function is overridden so that the slider's value
// changes to 126 (sequencer track reset) when clicked while the CTRL
// key is down. If the step is in sequencer track 1, the slider's value
// is set to 127 (rest) when clicked while the ALT key is down.
class SliderForSequencerSteps : public RotarySliderWithMouseWheelModForSeqStep
{
	const int sequencerTrack;

public:
	SliderForSequencerSteps() = delete;

	SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;
};




// A custom slider used for setting oscillator wave shapes.
// The mouseDown() function is overridden so that when a number 
// from 0..4 is held down and the slider is clicked, one of the 
// wave shapes is directly selected.
class SliderForOscWaveShapes : public RotarySliderWithMouseWheelMod
{
public:
	SliderForOscWaveShapes() = delete;

	explicit SliderForOscWaveShapes(UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;
};


