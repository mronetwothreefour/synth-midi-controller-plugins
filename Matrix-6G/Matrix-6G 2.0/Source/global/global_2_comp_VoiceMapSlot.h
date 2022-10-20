#pragma once

#include <JuceHeader.h>

#include "global_1_comp_SliderForVoiceMapSlot.h"

class UnexposedParameters;

class VoiceMapSlot :
	public Component
{
	const uint8 mapSlotNum;
	SliderForVoiceMapSlot slider_InVoice;
	SliderForVoiceMapSlot slider_OutVoice;

	VoiceMapSlot();

public:
	VoiceMapSlot(uint8 mapSlotNum, UnexposedParameters* unexposedParams, UndoManager* undoManager);


private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceMapSlot)
};