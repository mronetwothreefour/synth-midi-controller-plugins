#include "KnobWidgets.h"

//==============================================================================

void KnobWidget_OscPitch::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 121)
		setValueDisplayLabelText(valueConverters.intToPitchName(currentVal, false));
	else setValueDisplayLabelText("ERR");
}

String KnobWidget_OscPitch::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPitchName(roundToInt(currentValue), true) + "\n" ;
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the oscillator's base pitch in semitone steps.\n";
		tooltip += "Range: C 0 to C 10. Middle C is C 3.";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_FineTune::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 101)
		setValueDisplayLabelText(valueConverters.intToFineTuneRange(currentVal, false));
	else setValueDisplayLabelText("ERR");
}

String KnobWidget_FineTune::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToFineTuneRange(roundToInt(currentValue), true) + "\n" ;
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Fine tunes the oscillator's base pitch.\n";
		tooltip += "Range: -50 cents to +50 cents.\n";
		tooltip += "0 = no detuning (centered).";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_OscShape::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 104)
	{
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
		if (currentVal > 3 && currentValue < 104) // Pulse
		{
			setValueDisplayLabelText("");
			shapeRenderer.drawPulse(currentVal - 3);
		}
	}
	else
	{
		shapeRenderer.clear();
		setValueDisplayLabelText("ERR");
	}
}

String KnobWidget_OscShape::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToOscWaveShape(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Selects the oscillator's wave shape.\n";
		tooltip += "Available options: Off; Sawtooth; Triangle;\n";
		tooltip += "Sawtooth/Triangle Mix; Pulse (Width 0 to 99).\n";
		tooltip += "A Pulse with width 50 is a square wave.";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_0to127::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 128)
		setValueDisplayLabelText(String(currentValue));
	else setValueDisplayLabelText("ERR");
}

//==============================================================================

String KnobWidget_OscGlide::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the oscillator's glide (portamento) rate.\n";
		tooltip += "Range: 0 (fastest) to 127 (slowest)";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_SubOscLvl::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the level of the sub-oscillator,\n";
		tooltip += "which generates a square wave pitched\n";
		tooltip += "one octave below the oscillator.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}
