#pragma once

#include <JuceHeader.h>

#include "global_1_comp_SliderForVoiceMapSlot.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Voices.h"

using namespace Matrix_6G_Constants;

class UnexposedParameters;

class VoiceMapSlot :
	public Component
{
	SliderForVoiceMapSlot slider_InVoice;
	SliderForVoiceMapSlot slider_OutVoice;

	VoiceMapSlot() :
		slider_InVoice{ VCS::numberOfSlotsInVoicesBank, VoiceMapSliderType::null, nullptr, nullptr },
		slider_OutVoice{ VCS::numberOfSlotsInVoicesBank, VoiceMapSliderType::null, nullptr, nullptr }
	{
		// this default constructor is needed when initializing the vector in GUI_Layer_VoiceMap
	}

public:
	VoiceMapSlot(uint8 mapSlotNum, UnexposedParameters* unexposedParams, UndoManager* undoManager) :
		slider_InVoice{ mapSlotNum, VoiceMapSliderType::in, unexposedParams, undoManager },
		slider_OutVoice{ mapSlotNum, VoiceMapSliderType::out, unexposedParams, undoManager }
	{
		auto slot_w{ 57 };
		slider_InVoice.setTopLeftPosition(0, 0);
		addAndMakeVisible(slider_InVoice);

		slider_OutVoice.setTopRightPosition(slot_w, 0);
		addAndMakeVisible(slider_OutVoice);

		setSize(slot_w, GUI::control_h);
	}


private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceMapSlot)
};