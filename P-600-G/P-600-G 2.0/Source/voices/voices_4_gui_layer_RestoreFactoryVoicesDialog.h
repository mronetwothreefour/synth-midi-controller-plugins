#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

class GUI_Layer_RestoreFactoryVoicesDialog :
	public Component
{
	TextButton button_Esc;
	TextButton button_OK;

public:
	GUI_Layer_RestoreFactoryVoicesDialog() = delete;

	explicit GUI_Layer_RestoreFactoryVoicesDialog(UnexposedParameters* unexposedParams) {
		auto buttons_y{ 204 };

		button_Esc.setComponentID(ID::btn_Esc.toString());
		button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
		button_Esc.onClick = [this] { hideThisLayer(); };
		button_Esc.setBounds(656, buttons_y, GUI::buttons_w, GUI::buttons_h);
		addAndMakeVisible(button_Esc);

		button_OK.setComponentID(ID::btn_OK.toString());
		button_OK.addShortcut(KeyPress(KeyPress::returnKey));
		button_OK.setBounds(706, buttons_y, GUI::buttons_w, GUI::buttons_h);
		button_OK.onClick = [this, unexposedParams] {
			auto voicesBank{ unexposedParams->getVoicesBank() };
			voicesBank->restoreFactoryVoicesBank();
			hideThisLayer();
		};
		addAndMakeVisible(button_OK);

		if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
			button_Esc.setTooltip("Cancel restore.");
			button_OK.setTooltip("Confirm restore.");
		}
	}

	void paint(Graphics& g) override {
		g.setColour(GUI::color_Black.withAlpha(0.4f));
		g.fillRect(GUI::bounds_VoicesBanks);
		g.setOpacity(1.0f);
		MemoryInputStream memInputStream{ BinaryData::bkgrnd_FactoryRestoreDialog_png, BinaryData::bkgrnd_FactoryRestoreDialog_pngSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 554, 133);
	}

	void hideThisLayer() {
		getParentComponent()->grabKeyboardFocus();
		setVisible(false);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_RestoreFactoryVoicesDialog)
};