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




SliderWithMouseWheelModForPitch::SliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
}

void SliderWithMouseWheelModForPitch::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) {
	unexposedParams->undoManager_get()->beginNewTransaction();
	auto delta{ wheel.deltaY };
	auto currentValue{ getValue() };
	auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
	if (event.mods == ModifierKeys::shiftModifier)
		interval *= 12.0;
	if (delta != 0.0f)
		setValue(currentValue + interval);
	unexposedParams->undoManager_get()->beginNewTransaction();
}




SliderWithMouseWheelModForSeqStep::SliderWithMouseWheelModForSeqStep(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
}

void SliderWithMouseWheelModForSeqStep::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel)
{
	unexposedParams->undoManager_get()->beginNewTransaction();
	auto delta{ wheel.deltaY };
	auto currentValue{ getValue() };
	auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
	if (event.mods == ModifierKeys::shiftModifier)
		interval *= 24.0;
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




RotarySliderWithMouseWheelModForPitch::RotarySliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelModForPitch{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
}




RotarySliderWithMouseWheelModForSeqStep::RotarySliderWithMouseWheelModForSeqStep(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelModForSeqStep{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
}




SliderForSequencerSteps::SliderForSequencerSteps(int sequencerTrack, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelModForSeqStep{ unexposedParams },
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
	if (KeyPress::isKeyCurrentlyDown('0') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad0)) {
		setValue(0.0, sendNotification);
		return;
	}
	if (KeyPress::isKeyCurrentlyDown('1') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad1)) {
		setValue(1.0, sendNotification);
		return;
	}
	if (KeyPress::isKeyCurrentlyDown('2') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad2)) {
		setValue(2.0, sendNotification);
		return;
	}
	if (KeyPress::isKeyCurrentlyDown('3') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad3)) {
		setValue(3.0, sendNotification);
		return;
	}
	if (KeyPress::isKeyCurrentlyDown('4') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad4)) {
		setValue(54.0, sendNotification);
		return;
	}
	else Slider::mouseDown(event);
}
