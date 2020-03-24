#include "KnobWidgets.h"

//==============================================================================

void KnobWidget_0to127::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 128)
		setCurrentValueText(String(currentValue));
	else setCurrentValueText("ERR");
}

//==============================================================================

void KnobWidget_PlusMinus127::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 255)
		setCurrentValueText(valueConverters.intToPlusMinus127(currentValue));
	else setCurrentValueText("ERR");
}

//==============================================================================

void KnobWidget_OscPitch::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 121)
		setCurrentValueText(valueConverters.intToOscPitchString(currentValue, false));
	else setCurrentValueText("ERR");
}

String KnobWidget_OscPitch::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToOscPitchString(currentValue, true) + "\n" ;
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the oscillator's base pitch in semitone steps.\n";
		tooltip += "Range: C 0 to C 10. Middle C is C 3.";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_FineTune::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 101)
		setCurrentValueText(valueConverters.intToFineTuneRange(currentValue, false));
	else setCurrentValueText("ERR");
}

String KnobWidget_FineTune::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToFineTuneRange(currentValue, true) + "\n" ;
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Fine tunes the oscillator's base pitch.\n";
		tooltip += "Range: -50 cents to +50 cents.\n";
		tooltip += "0 = no detuning (centered).";
	}
	return tooltip;
}

//==============================================================================

void KnobWidget_OscShape::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 104)
	{
		if (currentValue == 0) // Off
		{
			shapeRenderer.clear();
			setCurrentValueText("OFF");
		}
		if (currentValue == 1) // Sawtooth
		{
			setCurrentValueText("");
			shapeRenderer.drawSawtooth();
		}
		if (currentValue == 2) // Triangle
		{
			setCurrentValueText("");
			shapeRenderer.drawTriangle();
		}
		if (currentValue == 3) // Sawtooth-Triangle Mix
		{
			setCurrentValueText("");
			shapeRenderer.drawSawTri();
		}
		if (currentValue > 3 && currentValue < 104) // Pulse
		{
			setCurrentValueText("");
			shapeRenderer.drawPulse(currentValue - 3);
		}
	}
	else
	{
		shapeRenderer.clear();
		setCurrentValueText("ERR");
	}
}

String KnobWidget_OscShape::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToOscWaveShape(currentValue) + "\n";
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

String KnobWidget_OscGlide::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the oscillator's glide (portamento) rate.\n";
		tooltip += "Range: 0 (fastest) to 127 (slowest)";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_OscSubLvl::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
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

void KnobWidget_OscSlop::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 6)
		setCurrentValueText(String(currentValue));
	else setCurrentValueText("ERR");
}

String KnobWidget_OscSlop::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Introduces subtle amounts of random oscillator\n";
		tooltip += "frequency drift for a \"vintage analog\" sound.\n";
		tooltip += "Range: 0 to 5.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_OscMix::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
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

void KnobWidget_BendRange::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 13)
		setCurrentValueText(valueConverters.intToBendRange(currentValue, false));
	else setCurrentValueText("ERR");
}

String KnobWidget_BendRange::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToBendRange(currentValue, true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the maximum amount (in semitones) by which pitch wheel\n";
		tooltip += "messages can raise or lower the pitches of the oscillators.\n";
		tooltip += "Range: 0 (no bend) to +/-12 semitones.\n";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_NoiseLevel::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the level of white noise\n";
		tooltip += "sent into the low-pass filter.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_ExtInLevel::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
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

//==============================================================================

void KnobWidget_LPFfreq::drawValue(const int& currentValue) noexcept
{
	if (currentValue > -1 && currentValue < 165)
		setCurrentValueText(valueConverters.intToLPFfreq(currentValue, false));
	else setCurrentValueText("ERR");
}

String KnobWidget_LPFfreq::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToLPFfreq(currentValue, true) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the base cutoff frequency for the\n";
		tooltip += "low-pass filter (in semitone steps).\n";
		tooltip += "Range: 0 (C 0) to 164 (G# 13).\n";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_LPFreso::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the resonance level of the low-pass\n";
		tooltip += "filter. When in 4-pole mode, high settings\n";
		tooltip += "will cause the filter to self-oscillate.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_LPFenvAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPlusMinus127(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which the LPF envelope\n";
		tooltip += "modulates the filter's cutoff frequency.\n";
		tooltip += "Negative values invert the envelope.\n";
		tooltip += "Range: -127 to +127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_VelAmount::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which MIDI note velocity\n";
		tooltip += "modulates the amplitude of the envelope.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_LPFkeyAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the amount by which keyboard (MIDI) notes\n";
		tooltip += "will shift the low-pass filter's cutoff frequency.\n";
		tooltip += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
		tooltip += "semitone for each note. At 32, cutoff is shifted\n";
		tooltip += "by one half-semitone for each note.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_LPFfmAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which oscillator 1 modulates\n";
		tooltip += "the low-pass filter's cutoff frequency. This is\n";
		tooltip += "useful for generating bell-like FM sounds.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_EnvDelay::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the length of the envelope's delay segment\n";
		tooltip += "(the amount of time that passes after the envelope\n";
		tooltip += "is triggered before its attack segment begins).\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_EnvAttack::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the length of the envelope's attack segment\n";
		tooltip += "(the amount of time it takes for the envelope's\n";
		tooltip += "level to rise from minimum to maximum).\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_EnvDecay::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the length of the envelope's decay segment\n";
		tooltip += "(the amount of time it takes for the envelope's\n";
		tooltip += "level to fall from maximum to the sustain level).\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_EnvSustain::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the envelope's sustain level (once the\n";
		tooltip += "decay segment completes, the envelope stays\n";
		tooltip += "at this level until it is gated off).\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_EnvRelease::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the length of the envelope's release segment\n";
		tooltip += "(the amount of time it takes to fall from the sustain\n";
		tooltip += "level down to minimum once the envelope is gated off).\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_VCAlevel::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the voltage-controlled amplifier's baseline level. Turn this\n";
		tooltip += "up for droning sounds or when processing external audio input.\n";
		tooltip += "When this level is set to 127, the VCA envelope has no effect.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_VCAenvAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which the VCA envelope\n";
		tooltip += "modulates the voltage-controlled ampifier's level.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_PgmVolume::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + (String)(currentValue)+"\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the overall gain of the current program.\n";
		tooltip += "Range: 0 to 127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_Env3Amt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPlusMinus127(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which Envelope 3\n";
		tooltip += "modulates the destination parameter.\n";
		tooltip += "Negative values invert the envelope.\n";
		tooltip += "Range: -127 to +127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_ModAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPlusMinus127(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which the source\n";
		tooltip += "modulates the destination parameter.\n";
		tooltip += "Negative values invert the modulation.\n";
		tooltip += "Range: -127 to +127.";
	}
	return tooltip;
}

//==============================================================================

String KnobWidget_MidiModAmt::createTooltipString(const int& currentValue) const noexcept
{
	String tooltip{ "" };
	if (privateParams->shouldShowValueTip())
		tooltip += "Current Value: " + valueConverters.intToPlusMinus127(currentValue) + "\n";
	if (privateParams->shouldShowInfoTip())
	{
		tooltip += "Sets the degree to which the MIDI controller\n";
		tooltip += "modulates the destination parameter.\n";
		tooltip += "Negative values invert the modulation.\n";
		tooltip += "Range: -127 to +127.";
	}
	return tooltip;
}
