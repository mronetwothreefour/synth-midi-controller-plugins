#pragma once

#include <JuceHeader.h>



enum class ControlType {
	nullControl = -1,
	knobWithValueStringDisplay,
	knobForPitchWithValueStringDisplay,
	knobWithWaveShapeDisplay,
	toggleButton,
	pgmSlotRadioButton,
	utilityButton,
	comboBox,
	sequencerStep,
	voiceNameChar
};

