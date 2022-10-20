#pragma once

#include "global_2_comp_VoiceMapSlot.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class UnexposedParameters;

class GUI_Layer_VoiceMap :
	public Component
{
	ButtonForHidingLayer btn_Close;
	TextButton btn_Reset;
	std::vector<std::unique_ptr<VoiceMapSlot>> voiceMapSlots;
	const Rectangle<int> borderBounds{ 173, 111, 906, 374 };
	const int voiceMapSlots_HorizGap{ 30 };

public: 
	GUI_Layer_VoiceMap() = delete;

	GUI_Layer_VoiceMap(UnexposedParameters* unexposedParams, UndoManager* undoManager);
	void paint(Graphics& g) override;
	~GUI_Layer_VoiceMap();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_VoiceMap)
};