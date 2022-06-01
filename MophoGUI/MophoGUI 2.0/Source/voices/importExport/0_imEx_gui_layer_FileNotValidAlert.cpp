#include "0_imEx_gui_layer_FileNotValidAlert.h"

#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_Dimensions.h"

using namespace MophoConstants;



GUI_Layer_FileNotValidAlert::GUI_Layer_FileNotValidAlert(UnexposedParameters* unexposedParams) :
	button_Close{ unexposedParams }
{
	addAndMakeVisible(button_Close);
	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_FileNotValidAlert::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_FileNotValidAlert_png, BinaryData::bkgrnd_FileNotValidAlert_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 566, 274);
}

void GUI_Layer_FileNotValidAlert::resized() {
	button_Close.setBounds(612, 310, button_Close.getWidth(), button_Close.getHeight());
}
