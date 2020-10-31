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




RotarySliderWithMouseWheelMod::RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelMod{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
}




SliderForSequencerSteps::SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	sequencerTrack{ sequencerTrack }
{
}

void SliderForSequencerSteps::mouseDown(const MouseEvent& event) {
	if (event.mods.isCtrlDown()) {
		setValue(126.0, sendNotification);
		return;
	}
	if (sequencerTrack == 1 && event.mods.isAltDown()) {
		setValue(127.0, sendNotification);
		return;
	}
	else Slider::mouseDown(event);
}





SliderForOscWaveShapes::SliderForOscWaveShapes(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams }
{
}

void SliderForOscWaveShapes::mouseDown(const MouseEvent& event) {
	if (KeyPressMenu::key_0.isCurrentlyDown()) {
		setValue(0.0, sendNotification);
		return;
	}
	if (KeyPressMenu::key_1.isCurrentlyDown()) {
		setValue(1.0, sendNotification);
		return;
	}
	if (KeyPressMenu::key_2.isCurrentlyDown()) {
		setValue(2.0, sendNotification);
		return;
	}
	if (KeyPressMenu::key_3.isCurrentlyDown()) {
		setValue(3.0, sendNotification);
		return;
	}
	if (KeyPressMenu::key_4.isCurrentlyDown()) {
		setValue(54.0, sendNotification);
		return;
	}
	else Slider::mouseDown(event);
}
