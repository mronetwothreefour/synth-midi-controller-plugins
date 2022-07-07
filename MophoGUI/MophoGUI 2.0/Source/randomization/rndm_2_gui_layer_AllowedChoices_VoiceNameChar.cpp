#include "rndm_2_gui_layer_AllowedChoices_VoiceNameChar.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_VoiceNameChar::GUI_Layer_AllowedChoices_VoiceNameChar(
	uint8 paramIndex, ExposedParameters* exposedParams, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams },
	button_Close{ unexposedParams },
	repeatChoicesToggle{ paramIndex, exposedParams, unexposedParams },
	button_Randomize{ paramIndex, exposedParams, randomize, unexposedParams },
	background_x{ exposedParams->info.allowedChoicesBackground_x_For(paramIndex) },
	background_y{ exposedParams->info.allowedChoicesBackground_y_For(paramIndex) },
	background_w{ 246 },
	background_h{ 258 }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramName{ exposedParams->info.exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	auto allowAllAndCloseButtons_y{ 88 };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this, unexposedParams, paramIndex] {
		auto randomization{ unexposedParams->getRandomizationOptions() };
		randomization->allowAllChoicesForVoiceNameCharParam(paramIndex);
		allowChoiceToggles.restoreToggles();
	};
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all characters when\n";
		tip += "generating a random character for\n";
		tip += paramName + ".";
		button_AllowAll.setTooltip(tip);
	}
	button_AllowAll.setBounds(background_x + GUI::allowedChoices_Inset, allowAllAndCloseButtons_y, GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	repeatChoicesToggle.setTopLeftPosition(background_x + 99, 92);
	addAndMakeVisible(repeatChoicesToggle);

	button_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(button_Close);

	allowChoiceToggles.restoreToggles();
	allowChoiceToggles.setTopLeftPosition(background_x + 23, 120);
	addAndMakeVisible(allowChoiceToggles);

	button_Randomize.setTopLeftPosition(background_x + 85, 290);
	addAndMakeVisible(button_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_VoiceNameChar::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ exposedParams->info.centerPointFor(paramIndex) };
	auto char_w{ exposedParams->info.widthFor(paramIndex) };
	auto char_h{ exposedParams->info.heightFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	g.drawRect(controlCenter.x - char_w / 2 - 2, controlCenter.y - char_h / 2 - 2, char_w + 4, char_h + 4, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}
