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




LinearSliderWithMouseWheelModAndReversedRange::LinearSliderWithMouseWheelModAndReversedRange(UnexposedParameters* unexposedParams) :
	SliderWithMouseWheelMod{ unexposedParams }
{
	setSliderStyle(Slider::LinearHorizontal);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

double LinearSliderWithMouseWheelModAndReversedRange::proportionOfLengthToValue(double proportion) {
	return Slider::proportionOfLengthToValue(1.0f - proportion);
}

double LinearSliderWithMouseWheelModAndReversedRange::valueToProportionOfLength(double value) {
	return 1.0f - Slider::valueToProportionOfLength(value);
}
