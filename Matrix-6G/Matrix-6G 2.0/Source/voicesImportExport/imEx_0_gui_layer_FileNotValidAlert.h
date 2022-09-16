#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;

class GUI_Layer_FileNotValidAlert :
	public Component
{
	TextButton btn_Close;

public:
	GUI_Layer_FileNotValidAlert(TooltipsOptions* tooltips)
	{
		btn_Close.setComponentID(ID::btn_Close.toString());
		btn_Close.addShortcut(KeyPress(KeyPress::escapeKey));
		btn_Close.addShortcut(KeyPress(KeyPress::returnKey));
		btn_Close.onClick = [this] {
			getParentComponent()->grabKeyboardFocus();
			setVisible(false);
		};
		btn_Close.setTooltip(tooltips->shouldShowDescription() ? "Click to close this alert." : "");
		btn_Close.setBounds(605, 301, 42, GUI::buttons_small_h);
		addAndMakeVisible(btn_Close);
		setSize(GUI::editor_w, GUI::editor_h);
	}

	void paint(Graphics& g) override {
		g.setColour(GUI::color_Black.withAlpha(0.4f));
		g.fillRect(getParentComponent()->getBounds());
		g.setOpacity(1.0f);
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileNotValidAlert_png, BinaryData::bkgrnd_FileNotValidAlert_pngSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 545, 255);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileNotValidAlert)
};