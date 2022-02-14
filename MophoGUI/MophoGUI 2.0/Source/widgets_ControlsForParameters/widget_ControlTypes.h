#pragma once

#include <JuceHeader.h>



enum class ControlType {
	nullControl = -1,
	knobWithValueStringDisplay,
	knobForPitchWithValueStringDisplay,
	knobWithWaveShapeDisplay,
	toggleButton,
	comboBox,
	sequencerStep,
	voiceNameChar
};

