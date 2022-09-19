#pragma once

#include <JuceHeader.h>

namespace P_600_G_Constants
{
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
}