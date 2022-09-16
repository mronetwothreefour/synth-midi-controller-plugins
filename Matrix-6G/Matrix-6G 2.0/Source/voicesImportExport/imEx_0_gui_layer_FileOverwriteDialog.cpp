#include "imEx_0_gui_layer_FileOverwriteDialog.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

GUI_Layer_FileOverwriteDialog::GUI_Layer_FileOverwriteDialog(UnexposedParameters* unexposedParams)
{
	addAndMakeVisible(btn_Cancel);
	btn_Cancel.setComponentID(ID::btn_Cancel_FileOverwrite.toString());
	btn_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(btn_Write);
	btn_Write.setComponentID(ID::btn_Write.toString());
	btn_Write.addShortcut(KeyPress(KeyPress::returnKey));

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescription()) {
		btn_Cancel.setTooltip("Cancel file overwrite.");
		btn_Write.setTooltip("Confirm file overwrite.");
	}

	const int buttons_w{ 46 };
	const int buttons_y{ 313 };
	btn_Cancel.setBounds(577, buttons_y, buttons_w, GUI::buttons_small_h);
	btn_Write.setBounds(629, buttons_y, buttons_w, GUI::buttons_small_h);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_FileOverwriteDialog::addListenerToButtons(Button::Listener* listener) {
	btn_Cancel.addListener(listener);
	btn_Write.addListener(listener);
}

void GUI_Layer_FileOverwriteDialog::removeListenerFromButtons(Button::Listener* listener) {
	btn_Cancel.removeListener(listener);
	btn_Write.removeListener(listener);
}

void GUI_Layer_FileOverwriteDialog::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileOverwriteDialog_png, BinaryData::bkgrnd_FileOverwriteDialog_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 531, 238);
}
