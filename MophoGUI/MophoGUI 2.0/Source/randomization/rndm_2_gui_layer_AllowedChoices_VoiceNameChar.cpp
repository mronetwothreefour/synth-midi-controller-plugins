#include "rndm_2_gui_layer_AllowedChoices_VoiceNameChar.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using Info = InfoForExposedParameters;



GUI_Layer_AllowedChoices_VoiceNameChar::GUI_Layer_AllowedChoices_VoiceNameChar(
	uint8 paramIndex, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	allowChoiceToggles{ paramIndex, unexposedParams },
	button_Close{ unexposedParams },
	repeatChoicesToggle{ paramIndex, unexposedParams },
	button_Randomize{ paramIndex, randomize, unexposedParams },
	background_x{ Info::get().allowedChoicesBackground_x_For(paramIndex) },
	background_y{ Info::get().allowedChoicesBackground_y_For(paramIndex) },
	background_w{ 246 },
	background_h{ 258 }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	auto paramName{ Info::get().exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

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
	button_AllowAll.setSize(GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	addAndMakeVisible(repeatChoicesToggle);

	addAndMakeVisible(button_Close);

	allowChoiceToggles.restoreToggles();
	addAndMakeVisible(allowChoiceToggles);

	addAndMakeVisible(button_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_VoiceNameChar::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ Info::get().centerPointFor(paramIndex) };
	auto char_w{ Info::get().widthFor(paramIndex) };
	auto char_h{ Info::get().heightFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	g.drawRect(controlCenter.x - char_w / 2 - 2, controlCenter.y - char_h / 2 - 2, char_w + 4, char_h + 4, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}
