#pragma once

#include <JuceHeader.h>

namespace MophoConstants
{
	const enum class AllowedChoicesType {
		standard = 0,
		oscShape,
		binary,
		lfoFreq,
		seqTrackStep,
		voiceNameChar
	};


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
		lpf,
		vca
	};


	const enum class OscWaveShape {
		off = 0,
		sawtooth,
		triangle,
		sawTriMix,
		pulse
	};


	const enum class SeqTrackNum {
		one = 1, two, three, four
	};


	const enum class SeqTrackProbabilityKnobType {
		rest = 0,
		duplicate,
		reset
	};


	const enum class SeqTrackStepNum {
		all = 0, one, two, three, four, five, six, seven, eight,
		nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen
	};

	const enum class SysExMessageType {
		voiceData = 2,
		editBufferData = 3,
		voiceDataRequest = 5,
		editBufferDataRequest = 6,
		globalParametersDataRequest = 14,
		globalParametersData = 15
	};
}