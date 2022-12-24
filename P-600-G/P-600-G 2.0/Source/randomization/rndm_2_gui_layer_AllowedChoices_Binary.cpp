#include "rndm_2_gui_layer_AllowedChoices_Binary.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_Binary::GUI_Layer_AllowedChoices_Binary(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	info{ exposedParams->info.get() },
	paramIndex{ paramIndex },
	repeatChoicesSwitch{ paramIndex, exposedParams, tooltips },
	btn_Randomize{ paramIndex, exposedParams, tooltips },
	btn_Exit{ tooltips },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(info->controlTypeFor(paramIndex) == ControlType::twoPoleSwitch);
	repeatChoicesSwitch.setTopLeftPosition(background_x + 31, background_y + 31);
	addAndMakeVisible(repeatChoicesSwitch);
	btn_Randomize.setTopLeftPosition(background_x + 79, background_y + 23);
	addAndMakeVisible(btn_Randomize);
	btn_Exit.setTopLeftPosition(background_x + 129, background_y + 23);
	addAndMakeVisible(btn_Exit);
	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_Binary::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex) };
	auto switch_w{ info->widthFor(paramIndex) };
	auto switch_h{ info->heightFor(paramIndex) };
	g.setColour(GUI::color_LED_Red);
	g.drawRect(controlCenter.x - switch_w / 2 - 2, controlCenter.y - switch_h / 2 - 2, switch_w + 4, switch_h + 4, 2);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_AllowedChoices_Toggles_png, BinaryData::bkgrnd_AllowedChoices_Toggles_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}
