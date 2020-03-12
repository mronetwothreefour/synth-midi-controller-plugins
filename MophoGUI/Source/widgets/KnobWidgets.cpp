#include "KnobWidgets.h"

//==============================================================================

void KnobWidget_OscPitch::drawValue(const double& currentValue)
{
	setValueDisplayLabelText(valueConverters.intToPitchName(roundToInt(currentValue), false));
}

String KnobWidget_OscPitch::createTooltipString(const double& currentValue) const
{
	String tooltip{ "Current Value: " + valueConverters.intToPitchName(roundToInt(currentValue), true) + "\n" };
	tooltip += "Sets the oscillator's base pitch in semitone steps\n";
	tooltip += "Range: C 0 to C 10. Middle C is C 3";
	return tooltip;
}

//==============================================================================

void KnobWidget_FineTune::drawValue(const double& currentValue)
{
	setValueDisplayLabelText(valueConverters.intToFineTuneRange(roundToInt(currentValue), false));
}

String KnobWidget_FineTune::createTooltipString(const double& currentValue) const
{
	String tooltip{ "Current Value: " + valueConverters.intToFineTuneRange(roundToInt(currentValue), true) + "\n" };
	tooltip += "Fine tunes the oscillator's base pitch\n";
	tooltip += "Range: -50 cents to +50 cents\n";
	tooltip += "0 = no detuning (centered)";
	return tooltip;
}

//==============================================================================

void KnobWidget_OscShape::drawValue(const double& currentValue)
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal == 0) // Off
	{
		shapeRenderer.clear();
		setValueDisplayLabelText("OFF");
	}
	if (currentVal == 1) // Sawtooth
	{
		setValueDisplayLabelText("");
		shapeRenderer.drawSawtooth();
	}
	if (currentVal == 2) // Triangle
	{
		setValueDisplayLabelText("");
		shapeRenderer.drawTriangle();
	}
	if (currentVal == 3) // Sawtooth-Triangle Mix
	{
		setValueDisplayLabelText("");
		shapeRenderer.drawSawTri();
	}
}

String KnobWidget_OscShape::createTooltipString(const double& currentValue) const
{
	return String();
}
