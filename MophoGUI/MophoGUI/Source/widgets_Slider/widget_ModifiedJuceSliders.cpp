#include "widget_ModifiedJuceSliders.h"



SliderWithMouseWheelMod::SliderWithMouseWheelMod(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
}

void SliderWithMouseWheelMod::mouseWheelMove(const MouseEvent&, const MouseWheelDetails& wheel) {
	unexposedParams->undoManager_get()->beginNewTransaction();
	auto delta{ wheel.deltaY };
	auto currentValue{ getValue() };
	auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
	if (delta != 0.0f)
		setValue(currentValue + interval);
	unexposedParams->undoManager_get()->beginNewTransaction();
}

SliderWithMouseWheelMod::~SliderWithMouseWheelMod() {
}




RotarySliderWithMouseWheelMod::RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelMod{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
}

RotarySliderWithMouseWheelMod::~RotarySliderWithMouseWheelMod() {
}




SliderForSequencerSteps::SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	sequencerTrack{ sequencerTrack }
{
}

void SliderForSequencerSteps::mouseDown(const MouseEvent& event) {
	if (event.mods.isCtrlDown())
		setValue(126.0, sendNotification);
	if (sequencerTrack == 1 && event.mods.isAltDown())
		setValue(127.0, sendNotification);
	else Slider::mouseDown(event);
}

SliderForSequencerSteps::~SliderForSequencerSteps() {
}
