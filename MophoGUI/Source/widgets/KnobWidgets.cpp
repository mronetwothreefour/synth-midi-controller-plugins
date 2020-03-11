#include "KnobWidgets.h"

void KnobWidget_OscPitch::drawValue(const double& currentValue)
{
	setValueDisplayLabelText(valueConverters.intToPitchName(roundToInt(currentValue), false));
}

String KnobWidget_OscPitch::createTooltipString(const double& currentValue) const
{
	String tooltip{ "Current Value: " + valueConverters.intToPitchName(roundToInt(currentValue), true) + "\n" };
	tooltip += "Sets the oscillator's base pitch in semitone steps\n";
	tooltip += "Range: C 0 (8 Hz) to C 10 (8 kHz). Middle C is C 3";
	return tooltip;
}

void KnobWidget_FineTune::drawValue(const double& currentValue)
{
	setValueDisplayLabelText(valueConverters.intToFineTuneRange(roundToInt(currentValue), false));
}

String KnobWidget_FineTune::createTooltipString(const double& currentValue) const
{
	String tooltip{ "Current Value: " + valueConverters.intToFineTuneRange(roundToInt(currentValue), true) + "\n" };
	tooltip += "Fine tuning of the oscillator's base pitch\n";
	tooltip += "Range: -50 cents to +50 cents\n";
	tooltip += "0 = no detuning (centered)";
	return tooltip;
}
