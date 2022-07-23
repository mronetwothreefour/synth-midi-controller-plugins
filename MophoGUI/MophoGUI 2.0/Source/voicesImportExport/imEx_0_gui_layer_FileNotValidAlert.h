#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;

class GUI_Layer_FileNotValidAlert :
	public Component
{
	ButtonForHidingLayer button_Close;

public:
	GUI_Layer_FileNotValidAlert(UnexposedParameters* unexposedParams) :
		button_Close{ unexposedParams }
	{
		button_Close.setTopLeftPosition(612, 310);
		addAndMakeVisible(button_Close);
		setSize(GUI::editor_w, GUI::editor_h);
	}

	void paint(Graphics& g) override {
		g.setColour(GUI::color_Black.withAlpha(0.4f));
		g.fillRect(getParentComponent()->getBounds());
		g.setOpacity(1.0f);
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileNotValidAlert_png, BinaryData::bkgrnd_FileNotValidAlert_pngSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 566, 274);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileNotValidAlert)
};