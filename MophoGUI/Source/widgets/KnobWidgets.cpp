#include "KnobWidgets.h"

void KnobWidget_OscPitch::drawValue(double currentValue)
{
	auto noteNum{ roundToInt(currentValue) };
	auto pitchName{ valueConverters.intToPitchName(noteNum) };
	setValueDisplayLabelText(pitchName);
}

void KnobWidget_OscPitch::drawHoverHint(double currentValue) const
{
}
