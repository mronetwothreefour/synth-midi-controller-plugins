#pragma once

#include <JuceHeader.h>


namespace mophoConstants
{
	const enum class ControlType {
		nullControl = -1,
		knob,
		knobForPitch,
		knobForWaveShape,
		toggleButton,
		comboBox,
		seqTrackStep,
		voiceNameChar
	};
}

