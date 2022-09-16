#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

class GUI_Layer_CommError_Base :
	public Component,
	private Timer
{
protected:
	GlobalOptions* global;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	ButtonForHidingLayer btn_Close;
	TextButton btn_RequestGlobalParamsDump;

public:
	GUI_Layer_CommError_Base() = delete;

	explicit GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams) :
		global{ unexposedParams->getGlobalOptions() },
		outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
		btn_Close{ unexposedParams->getTooltipsOptions() },
		btn_RequestGlobalParamsDump{ "" }
	{
		addAndMakeVisible(btn_Close);

		btn_RequestGlobalParamsDump.setComponentID(ID::btn_Retry.toString());
		btn_RequestGlobalParamsDump.onClick = [this] { requestGlobalParamsDump(); };
		btn_RequestGlobalParamsDump.addShortcut(KeyPress(KeyPress::returnKey));
		btn_RequestGlobalParamsDump.setSize(50, GUI::redButton_h);
		addAndMakeVisible(btn_RequestGlobalParamsDump);

		setSize(GUI::editor_w, GUI::editor_h);
	}


private:
	void requestGlobalParamsDump() {
		SysExMessages::addRequestForGlobalParamsDataToOutgoingBuffers(outgoingBuffers);
		callAfterDelay(300, [this] { checkHardwareSettings(); });
	}

protected:
	virtual void checkHardwareSettings() = 0;

private:
	void timerCallback() override {
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError_Base)
};

