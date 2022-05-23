#pragma once

#include <JuceHeader.h>


namespace MophoConstants
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




	const enum class EnvelopeType {
		env_3 = 0,
		vca,
		vcf
	};




	const enum class OscWaveShape {
		off = 0,
		sawtooth,
		triangle,
		sawTriMix,
		pulse
	};
}

