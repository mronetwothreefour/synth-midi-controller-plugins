#pragma once

#include <JuceHeader.h>

#include "../gui/gui_comp_ButtonForHidingLayer.h"

class UnexposedParameters;

class GUI_Layer_CommError :
	public Component,
	private Timer
{
protected:
	GlobalOptions* global;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	ButtonForHidingLayer btn_Close;
	TextButton btn_RequestGlobalParamsDump;

public:
	GUI_Layer_CommError() = delete;

	explicit GUI_Layer_CommError(UnexposedParameters* unexposedParams);

private:
	void paint(Graphics& g) override;
	void requestGlobalParamsDump();

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError)
};

