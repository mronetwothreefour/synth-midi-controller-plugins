#include "widget_ModifiedJuceSliders.h"

#include "../gui/gui_Constants.h"

using namespace constants;



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




RotarySliderWithMouseWheelMod::RotarySliderWithMouseWheelMod(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelMod{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(GUI::knobStartAngleInDegrees), degreesToRadians(GUI::knobEndAngleInDegrees), true);
}




RotarySliderWithMouseWheelModForPitch::RotarySliderWithMouseWheelModForPitch(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelModForPitch{ unexposedParams }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(degreesToRadians(GUI::knobStartAngleInDegrees), degreesToRadians(GUI::knobEndAngleInDegrees), true);
}
