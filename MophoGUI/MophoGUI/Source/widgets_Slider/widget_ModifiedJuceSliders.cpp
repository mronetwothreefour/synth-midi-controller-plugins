#include "widget_ModifiedJuceSliders.h"



SliderWithMouseWheelMod::SliderWithMouseWheelMod(UnexposedParameters* unexposedParameters) :
	unexposedParameters{ unexposedParameters }
{
}

void SliderWithMouseWheelMod::mouseWheelMove(const MouseEvent&, const MouseWheelDetails& wheel) {
	unexposedParameters->undoManager_get()->beginNewTransaction();
	auto delta{ wheel.deltaY };
	auto currentValue{ getValue() };
	auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
	if (delta != 0.0f)
		setValue(currentValue + interval);
	unexposedParameters->undoManager_get()->beginNewTransaction();
}

SliderWithMouseWheelMod::~SliderWithMouseWheelMod() {
}




RotarySliderWithMouseWheelMod::RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParameters) :
	SliderWithMouseWheelMod{ unexposedParameters }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
}

RotarySliderWithMouseWheelMod::~RotarySliderWithMouseWheelMod() {
}




SliderForSequencerSteps::SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParameters) :
	RotarySliderWithMouseWheelMod{ unexposedParameters },
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
