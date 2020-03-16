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

//==============================================================================

void KnobWidget_OscSlop::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 6)
		setValueDisplayLabelText(String(currentValue));
	else setValueDisplayLabelText("ERR");
}

String KnobWidget_OscSlop::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Introduces subtle amounts of random oscillator\n";
		tooltip += "frequency drift for a \"vintage analog\" sound.\n";
		tooltip += "Range: 0 to 5.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_OscMix::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Controls the level balance between oscillators 1 & 2.\n";
		tooltip += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
		tooltip += "At 127, only oscillator 2 is heard. At 64, an equal\n";
		tooltip += "mix of the two oscillators is heard.";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_BendRange::drawValue(const double& currentValue) noexcept
{
	auto currentVal{ roundToInt(currentValue) };
	if (currentVal > -1 && currentValue < 13)
		setValueDisplayLabelText(valueConverters.intToBendRange(currentVal, false));
	else setValueDisplayLabelText("ERR");
}

String KnobWidget_BendRange::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToBendRange(roundToInt(currentValue), true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the maximum amount (in semitones) by which pitch wheel\n";
		tooltip += "messages can raise or lower the pitches of the oscillators.\n";
		tooltip += "Range: 0 (no bend) to +/-12 semitones.\n";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_NoiseLevel::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the level of white noise\n";
		tooltip += "sent into the low-pass filter.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_ExtInLevel::createTooltipString(const double& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(roundToInt(currentValue)) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the level of external audio\n";
		tooltip += "input sent into the low-pass filter.\n";
		tooltip += "When nothing is connected to audio in,\n";
		tooltip += "this controls the level of feedback\n";
		tooltip += "from the left audio output.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}
