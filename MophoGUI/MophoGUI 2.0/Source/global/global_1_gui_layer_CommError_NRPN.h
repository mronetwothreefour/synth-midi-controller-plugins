#pragma once

#include <JuceHeader.h>

#include "global_0_gui_layer_CommError_Base.h"
#include "../constants/constants_GUI_Colors.h"

using namespace MophoConstants;

class UnexposedParameters;

class GUI_Layer_CommError_NRPN :
	public GUI_Layer_CommError_Base
{
public:
	GUI_Layer_CommError_NRPN() = delete;

	explicit GUI_Layer_CommError_NRPN(UnexposedParameters* unexposedParams) :
		GUI_Layer_CommError_Base{ unexposedParams }
	{
		btn_Close.setTopLeftPosition(820, 212);
		btn_RequestGlobalParamsDump.setTopLeftPosition(611, 387);
	}

private:
	void checkHardwareSettings() override {
		if (global->hardwareIsSetToReceiveNRPNcontrollers())
			btn_Close.triggerClick();
	}

public:
	void paint(Graphics& g) override {
		g.fillAll(GUI::color_Black.withAlpha(0.4f));
		PNGImageFormat imageFormat;
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_CommError_NRPN_png, BinaryData::bkgrnd_CommError_NRPN_pngSize, false };
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 396, 205);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError_NRPN)
};

