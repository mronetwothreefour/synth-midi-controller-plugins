#include "rndm_2_gui_layer_AllowedChoices_OscPitch.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_OscPitch::GUI_Layer_AllowedChoices_OscPitch(
	uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	repeatChoicesSwitch{ paramIndex, exposedParams, tooltips },
	btn_Exit{ tooltips },
	allowChoiceToggles{ paramIndex, exposedParams, tooltips },
	btn_Randomize{ paramIndex, exposedParams, tooltips },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->controlTypeFor(paramIndex) == ControlType::knobForPitch);
	auto paramName{ info->exposedNameFor(paramIndex) };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };

	repeatChoicesSwitch.setTopLeftPosition(background_x + 37, background_y + 31);
	addAndMakeVisible(repeatChoicesSwitch);

	btn_Exit.setTopLeftPosition(background_x + 85, background_y + 23);
	addAndMakeVisible(btn_Exit);

	allowChoiceToggles.setTopLeftPosition(background_x + 15, background_y + 73);
	addAndMakeVisible(allowChoiceToggles);

	btn_AllowAll.setComponentID(ID::btn_All.toString());
	btn_AllowAll.onClick = [this, exposedParams, paramIndex] {
		auto randomization{ exposedParams->randomization.get() };
		randomization->allowAllChoicesForParam(paramIndex);
	};
	btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices when\n";
		tip += "generating a random setting for\n";
		tip += paramName + ".\n";
		tip += "Shortcut key: CTRL+A";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setBounds(background_x + 35, background_y + 275, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_AllowAll);

	btn_Randomize.setBounds(background_x + 85, background_y + 275, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_OscPitch::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_AllowedChoices_Pitch_png, BinaryData::bkgrnd_AllowedChoices_Pitch_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}
