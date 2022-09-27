#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;

class GUI_Layer_FolderExistsAlert :
	public Component
{
	ButtonForHidingLayer btn_Close;

public:
	GUI_Layer_FolderExistsAlert(TooltipsOptions* tooltips) :
		btn_Close{ tooltips }
	{
		btn_Close.setTopLeftPosition(612, 310);
		addAndMakeVisible(btn_Close);
		setSize(GUI::editor_w, GUI::editor_h);
	}

	void paint(Graphics& g) override {
		g.setColour(GUI::color_Black.withAlpha(0.4f));
		g.fillRect(GUI::bounds_NewFolder);
		g.setOpacity(1.0f);
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_FolderExistsAlert_png, BinaryData::bkgrnd_FolderExistsAlert_pngSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 541, 274);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FolderExistsAlert)
};