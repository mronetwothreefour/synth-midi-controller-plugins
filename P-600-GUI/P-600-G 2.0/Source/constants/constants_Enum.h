#pragma once

#include <JuceHeader.h>

namespace P_600_G_Constants
{
	const enum class BankTransmitType {
		push = 0,
		pull
	};


	const enum class ChoiceNameType {
		concise = 0,
		verbose
	};


	enum class ControlType {
		nullControl = -1,
		knob,
		knobForPitch,
		twoPoleSwitch,
		threePoleSwitch
	};


	enum class EnvelopeType {
		amplifier = 0,
		filter,
	};


	const enum class ImportExportType {
		exportVoice = 0,
		exportVoicesBank,
		importVoice,
		importVoicesBank
	};


	const enum class LockStateGroup {
		all = 0,
		osc_A,
		osc_B,
		filter,
		amp,
		polyMod,
		lfo
	};
}