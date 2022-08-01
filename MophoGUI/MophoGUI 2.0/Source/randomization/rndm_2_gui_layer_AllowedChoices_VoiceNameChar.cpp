#include "rndm_2_gui_layer_AllowedChoices_VoiceNameChar.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_AllowedChoices_VoiceNameChar::GUI_Layer_AllowedChoices_VoiceNameChar(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams },
	btn_Close{ unexposedParams },
	repeatChoicesToggle{ paramIndex, exposedParams, unexposedParams },
	btn_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) },
	background_w{ 246 },
	background_h{ 258 }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramName{ info->exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	auto allowAllAndCloseButtons_y{ 88 };

	btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
	btn_AllowAll.onClick = [this, exposedParams, paramIndex] {
		auto randomization{ exposedParams->randomization.get() };
		randomization->allowAllChoicesForVoiceNameCharParam(paramIndex);
		allowChoiceToggles.restoreToggles();
	};
	btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all characters when\n";
		tip += "generating a random character for\n";
		tip += paramName + ".\n";
		tip += "Shortcut key: CTRL+A";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setBounds(background_x + GUI::allowedChoices_Inset, allowAllAndCloseButtons_y, GUI::btn_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(btn_AllowAll);

	repeatChoicesToggle.setTopLeftPosition(background_x + 99, 92);
	addAndMakeVisible(repeatChoicesToggle);

	btn_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(btn_Close);

	allowChoiceToggles.restoreToggles();
	allowChoiceToggles.setTopLeftPosition(background_x + 23, 120);
	addAndMakeVisible(allowChoiceToggles);

	btn_Randomize.setTopLeftPosition(background_x + 85, 290);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_VoiceNameChar::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex) };
	auto char_w{ info->widthFor(paramIndex) };
	auto char_h{ info->heightFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	g.drawRect(controlCenter.x - char_w / 2 - 2, controlCenter.y - char_h / 2 - 2, char_w + 4, char_h + 4, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}
