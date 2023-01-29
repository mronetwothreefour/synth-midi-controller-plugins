#include "rndm_2_gui_layer_AllowedChoices_FilterKeyTrack.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_FilterKeyTrack::GUI_Layer_AllowedChoices_FilterKeyTrack(
	ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	info{ exposedParams->info.get() },
	repeatChoicesSwitch{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	btn_Exit{ unexposedParams->getTooltipsOptions() },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	btn_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	auto shouldShowDescriptions{ unexposedParams->getTooltipsOptions()->shouldShowDescription() };

	repeatChoicesSwitch.setTopLeftPosition(background_x + 29, background_y + 31);
	addAndMakeVisible(repeatChoicesSwitch);

	btn_Exit.setTopLeftPosition(background_x + 77, background_y + 23);
	addAndMakeVisible(btn_Exit);

	allowChoiceToggles.setTopLeftPosition(background_x + 58, background_y + 73);
	addAndMakeVisible(allowChoiceToggles);

	btn_AllowAll.setComponentID(ID::btn_All.toString());
	btn_AllowAll.onClick = [this, exposedParams] {
		auto randomization{ exposedParams->randomization.get() };
		randomization->allowAllChoicesForParam(paramIndex);
	};
	btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices when\n";
		tip += "generating a random setting for\n";
		tip += info->exposedNameFor(paramIndex) + ".\n";
		tip += "Shortcut key: CTRL+A";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setBounds(background_x + 27, background_y + 131, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_AllowAll);

	btn_Randomize.setBounds(background_x + 77, background_y + 131, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_FilterKeyTrack::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex) };
	auto switch_w{ info->widthFor(paramIndex) };
	auto switch_h{ info->heightFor(paramIndex) };
	g.setColour(GUI::color_LED_Red);
	g.drawRect(controlCenter.x - switch_w / 2 - 2, controlCenter.y - switch_h / 2 - 2, switch_w + 4, switch_h + 4, 2);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_AllowedChoices_KeyTrackpng_png, BinaryData::bkgrnd_AllowedChoices_KeyTrackpng_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}
