#include "rndm_2_gui_layer_AllowedChoices_Numeric.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_AllowedChoices_Numeric::GUI_Layer_AllowedChoices_Numeric(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	btn_Exit{ unexposedParams->getTooltipsOptions() },
	repeatChoicesSwitch{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	btn_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->controlTypeFor(paramIndex) == ControlType::knob);
	auto paramName{ info->exposedNameFor(paramIndex) };
	auto shouldShowDescriptions{ unexposedParams->getTooltipsOptions()->shouldShowDescription() };
	auto numChoices{ info->numberOfChoicesFor(paramIndex) };

	auto repeatChoices_x{ numChoices == 128 ? 164 : numChoices == 64 ? 44 : 29 };
	repeatChoicesSwitch.setTopLeftPosition(repeatChoices_x, 31);
	addAndMakeVisible(repeatChoicesSwitch);

	btn_Exit.setTopLeftPosition(repeatChoices_x + 48, 23);
	addAndMakeVisible(btn_Exit);

	auto allowChoiceToggles_x{ numChoices <= 32 ? 36 : 15  };
	allowChoiceToggles.setTopLeftPosition(allowChoiceToggles_x, 73);
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
	auto allowAll_x{ numChoices == 128 ? 162 : numChoices == 64 ? 42 : 27 };
	auto allowAllAndRand_y{ numChoices == 128 ? 204 : numChoices == 16 ? 57 : 211 };
	btn_AllowAll.setBounds(allowAll_x, allowAllAndRand_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_AllowAll);

	btn_Randomize.setTopLeftPosition(allowAll_x + 50, allowAllAndRand_y);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_Numeric::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex) };
	g.setColour(GUI::color_LED_Red);
	g.drawEllipse((float)controlCenter.x - 19.0f, (float)controlCenter.y - 19.0f, GUI::knob_diameter + 4, GUI::knob_diameter + 4, 2);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_AllowedChoices_Pitch_png, BinaryData::bkgrnd_AllowedChoices_Pitch_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}
