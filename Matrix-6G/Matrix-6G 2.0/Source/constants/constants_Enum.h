#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	enum class ControlType {
		nullControl = -1,
		slider,
		sliderForPitch,
		sliderForOscBalance,
		comboBox
	};

	enum class RangeType {
		unsignedValue = 0,
		signed_6_bitValue,
		signed_7_bitValue
	};

	enum class VoicesBank {
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
