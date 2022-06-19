#include "gui_comp_JuceSlidersWithMouseMods.h"



SliderWithMouseWheelMoveOverride::SliderWithMouseWheelMoveOverride(UnexposedParameters* unexposedParams) :
	isModifyingPitch{ false },
	isModifyingSeqStep{ false },
	undoManager{ unexposedParams->getUndoManager() }
{
}

void SliderWithMouseWheelMoveOverride::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) {
	undoManager->beginNewTransaction();
	auto delta{ wheel.deltaY };
	auto currentValue{ getValue() };
	auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
	if (delta != 0.0f) {
		if (event.mods == ModifierKeys::shiftModifier) {
			if (isModifyingPitch)
				interval *= isModifyingSeqStep ? 24.0 : 12.0;
			else
				interval *= 10.0;
		}
		setValue(currentValue + interval);
	}
	undoManager->beginNewTransaction();
}


//------------------------------------------------------------------------------------------------------------------------------------------


RotarySliderWithMouseWheelMoveOverride::RotarySliderWithMouseWheelMoveOverride(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelMoveOverride{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	auto startAngleInRadians{ degreesToRadians(225.0f) };
	auto endAngleInRadians{ degreesToRadians(495.0f) };
	setRotaryParameters(startAngleInRadians, endAngleInRadians, true);
}


//------------------------------------------------------------------------------------------------------------------------------------------



RotarySliderWithMouseDownModForOscShape::RotarySliderWithMouseDownModForOscShape(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ unexposedParams }
{
}

void RotarySliderWithMouseDownModForOscShape::mouseDown(const MouseEvent& event) {
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


//------------------------------------------------------------------------------------------------------------------------------------------



RotarySliderWithMouseDownModForSeqStep::RotarySliderWithMouseDownModForSeqStep(int trackNum, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ unexposedParams },
	trackNum{ trackNum }
{
}

void RotarySliderWithMouseDownModForSeqStep::mouseDown(const MouseEvent& event) {
	if (event.mods.isCtrlDown()) {
		setValue(126.0, sendNotification);
		return;
	}
	if (event.mods.isAltDown()) {
		if (trackNum == 1)
			setValue(127.0, sendNotification);
		return;
	}
	else Slider::mouseDown(event);
}
