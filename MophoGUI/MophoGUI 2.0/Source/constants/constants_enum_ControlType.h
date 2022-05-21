#pragma once

#include <JuceHeader.h>


namespace mophoConstants
{
	const enum class ControlType {
		nullControl = -1, // needed by ExposedParamControl's default constructor
		knob,
		knobForPitch,
		knobForOscShape,
		toggleButton,
		comboBox,
		seqTrackStep,
		voiceNameChar
	};
}

