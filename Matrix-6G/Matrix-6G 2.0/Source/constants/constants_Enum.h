#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	enum class ControlType {
		nullControl = -1,
		rotarySlider,
		rotarySliderForPitch,
		linearSlider,
		comboBox
	};

	enum class RangeType {
		unsignedValue = 0,
		signed_6_bitValue,
		signed_7_bitValue
	};
}
