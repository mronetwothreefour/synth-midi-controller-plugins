#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace P_600_G_Constants;

class GUI_Layer_FileNotValidAlert :
	public Component
{
	TextButton btn_OK;

public:
	GUI_Layer_FileNotValidAlert(TooltipsOptions* tooltips)
	{
		btn_OK.setComponentID(ID::btn_OK.toString());
		btn_OK.addShortcut(KeyPress(KeyPress::escapeKey));
		btn_OK.addShortcut(KeyPress(KeyPress::returnKey));
		btn_OK.onClick = [this] {
			setVisible(false);
			getParentComponent()->grabKeyboardFocus();
		};
		btn_OK.setTooltip(tooltips->shouldShowDescription() ? "Click to close this alert." : "");
		btn_OK.setBounds(681, 179, GUI::buttons_w, GUI::buttons_h);
		addAndMakeVisible(btn_OK);
		setSize(GUI::editor_w, GUI::editor_h);
	}

	void paint(Graphics& g) override {
		g.setColour(GUI::color_Black.withAlpha(0.4f));
		g.fillRect(GUI::bounds_ImportExport);
		g.setOpacity(1.0f);
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileNotValidAlert_png, BinaryData::bkgrnd_FileNotValidAlert_pngSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 611, 133);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileNotValidAlert)
};