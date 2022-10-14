#include "gui_comp_JuceSlidersWithMouseMods.h"

SliderWithMouseWheelMoveOverride::SliderWithMouseWheelMoveOverride(UndoManager* undoManager) :
	isModifyingPitch{ false },
	undoManager{ undoManager }
{
}

void SliderWithMouseWheelMoveOverride::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) {
	if (isEnabled() == true) {
		if (undoManager != nullptr)
			undoManager->beginNewTransaction();
		auto delta{ wheel.deltaY };
		auto currentValue{ getValue() };
		auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f) {
			if (event.mods == ModifierKeys::shiftModifier) {
				if (isModifyingPitch)
					interval *= 12.0;
				else
					interval *= 10.0;
			}
			setValue(currentValue + interval);
		}
		if (undoManager != nullptr)
			undoManager->beginNewTransaction();
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------


RotarySliderWithMouseWheelMoveOverride::RotarySliderWithMouseWheelMoveOverride(UndoManager* undoManager) :
	SliderWithMouseWheelMoveOverride{ undoManager }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	auto startAngleInRadians{ degreesToRadians(225.0f) };
	auto endAngleInRadians{ degreesToRadians(495.0f) };
	setRotaryParameters(startAngleInRadians, endAngleInRadians, true);
}


//------------------------------------------------------------------------------------------------------------------------------------------


LinearSliderWithMouseWheelMoveOverride::LinearSliderWithMouseWheelMoveOverride(UndoManager* undoManager) :
	SliderWithMouseWheelMoveOverride{ undoManager }
{
	setSliderStyle(Slider::LinearHorizontal);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setSliderSnapsToMousePosition(false);
}


//------------------------------------------------------------------------------------------------------------------------------------------


LinearSliderWithMouseWheelMoveOverrideAndInvertedRange::LinearSliderWithMouseWheelMoveOverrideAndInvertedRange(UndoManager* undoManager) :
	SliderWithMouseWheelMoveOverride{ undoManager }
{
	setSliderStyle(Slider::LinearHorizontal);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setSliderSnapsToMousePosition(false);
}

double LinearSliderWithMouseWheelMoveOverrideAndInvertedRange::proportionOfLengthToValue(double proportion) {
	return Slider::proportionOfLengthToValue(1.0f - proportion);
}

double LinearSliderWithMouseWheelMoveOverrideAndInvertedRange::valueToProportionOfLength(double value) {
	return 1.0f - Slider::valueToProportionOfLength(value);
}
