#include "imEx_0_gui_layer_FileOverwriteDialog.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace MophoConstants;

GUI_Layer_FileOverwriteDialog::GUI_Layer_FileOverwriteDialog(TooltipsOptions* tooltips)
{
	addAndMakeVisible(btn_Cancel);
	btn_Cancel.setComponentID(ID::btn_Cancel_FileOverwrite.toString());
	btn_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(btn_Write);
	btn_Write.setComponentID(ID::btn_Write_OverFile.toString());
	btn_Write.addShortcut(KeyPress(KeyPress::returnKey));

	if (tooltips->shouldShowDescription()) {
		btn_Cancel.setTooltip("Cancel file overwrite.");
		btn_Write.setTooltip("Confirm file overwrite.");
	}

	const int buttons_y{ 321 };
	btn_Cancel.setBounds(582, buttons_y, GUI::btn_Cancel_w, GUI::redButton_h);
	btn_Write.setBounds(639, buttons_y, GUI::btn_Write_w, GUI::redButton_h);

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
	g.fillRect(GUI::bounds_ImportExport);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileOverwriteDialog_png, BinaryData::bkgrnd_FileOverwriteDialog_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 556, 264);
}
