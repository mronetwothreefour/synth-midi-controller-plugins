#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	const enum class ControlType {
		nullControl = -1,
		slider,
		sliderForPitch,
		sliderForOscBalance,
		comboBox
	};

	const enum class RangeType {
		unsignedValue = 0,
		signed_6_bitValue,
		signed_7_bitValue
	};

	const enum class SysExMessageType {
		voiceData = 1,
		splitData,
		globalData,
		dataRequest,
		activateQuickEdit,
		parameterChange,
		switchMode = 13
	};


	const enum class SysExDatatrRequestType {
		voice = 1,
		split,
		global
	};


	const enum class VoicesBank {
		analogSynthsA = 0,
		analogSynthsB,
		basses,
		brassAndWoodwinds,
		customA,
		customB,
		fxAndPercussion,
		keyboardsA,
		keyboardsB,
		leads,
		miscellaneousA,
		miscellaneousB,
		strings
	};
}
