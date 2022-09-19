#include "imEx_0_gui_layer_FileOverwriteDialog.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace P_600_G_Constants;

GUI_Layer_FileOverwriteDialog::GUI_Layer_FileOverwriteDialog(TooltipsOptions* tooltips)
{
	addAndMakeVisible(btn_Esc);
	btn_Esc.setComponentID(ID::btn_Esc_FileOverwrite.toString());
	btn_Esc.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(btn_OK);
	btn_OK.setComponentID(ID::btn_OK_FileOverwrite.toString());
	btn_OK.addShortcut(KeyPress(KeyPress::returnKey));

	if (tooltips->shouldShowDescription()) {
		btn_Esc.setTooltip("Cancel file overwrite.");
		btn_OK.setTooltip("Confirm file overwrite.");
	}

	const int buttons_y{ 191 };
	btn_Esc.setBounds(656, buttons_y, GUI::buttons_w, GUI::buttons_h);
	btn_OK.setBounds(706, buttons_y, GUI::buttons_w, GUI::buttons_h);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_FileOverwriteDialog::addListenerToButtons(Button::Listener* listener) {
	btn_Esc.addListener(listener);
	btn_OK.addListener(listener);
}

void GUI_Layer_FileOverwriteDialog::removeListenerFromButtons(Button::Listener* listener) {
	btn_Esc.removeListener(listener);
	btn_OK.removeListener(listener);
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
