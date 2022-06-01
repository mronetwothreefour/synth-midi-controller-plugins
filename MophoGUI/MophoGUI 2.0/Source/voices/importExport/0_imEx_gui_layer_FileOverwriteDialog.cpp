#include "0_imEx_gui_layer_FileOverwriteDialog.h"

#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_Identifiers.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_FileOverwriteDialog::GUI_Layer_FileOverwriteDialog(UnexposedParameters* unexposedParams)
{
	addAndMakeVisible(button_Cancel);
	button_Cancel.setComponentID(ID::button_Cancel_FileOverwrite.toString());
	button_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(button_Write);
	button_Write.setComponentID(ID::button_Write_OverFile.toString());
	button_Write.addShortcut(KeyPress(KeyPress::returnKey));

	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Cancel.setTooltip("Cancel file overwrite.");
		button_Write.setTooltip("Confirm file overwrite.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_FileOverwriteDialog::addListenerToButtons(Button::Listener* listener) {
	button_Cancel.addListener(listener);
	button_Write.addListener(listener);
}

void GUI_Layer_FileOverwriteDialog::removeListenerFromButtons(Button::Listener* listener) {
	button_Cancel.removeListener(listener);
	button_Write.removeListener(listener);
}

void GUI_Layer_FileOverwriteDialog::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileOverwriteDialog_png, BinaryData::bkgrnd_FileOverwriteDialog_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 556, 264);
}

void GUI_Layer_FileOverwriteDialog::resized() {
	const int buttons_y{ 321 };
	button_Cancel.setBounds(582, buttons_y, GUI::button_Cancel_w, GUI::redButton_h);
	button_Write.setBounds(639, buttons_y, GUI::button_Write_w, GUI::redButton_h);
}
