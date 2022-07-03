#include "rndm_2_gui_layer_AllowedChoices_Binary.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_Binary::GUI_Layer_AllowedChoices_Binary(
	uint8 paramIndex, ExposedParameters* exposedParams, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	paramIndex{ paramIndex },
	repeatChoicesToggle{ paramIndex, exposedParams, unexposedParams },
	button_Randomize{ paramIndex, exposedParams, randomize, unexposedParams },
	button_Close{ unexposedParams },
	background_x{ exposedParams->info.allowedChoicesBackground_x_For(paramIndex) },
	background_y{ exposedParams->info.allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::binary);
	repeatChoicesToggle.setTopLeftPosition(background_x + 19, background_y + GUI::allowedChoices_Inset);
	addAndMakeVisible(repeatChoicesToggle);
	button_Randomize.setTopLeftPosition(background_x + GUI::allowedChoices_Inset, background_y + 41);
	addAndMakeVisible(button_Randomize);
	button_Close.setTopLeftPosition(background_x + 30, background_y + 73);
	addAndMakeVisible(button_Close);
	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_Binary::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	g.setColour(GUI::color_ToggleOn);
	auto toggleCenter{ exposedParams->info.centerPointFor(paramIndex) };
	g.drawEllipse((float)toggleCenter.x - 11.0f, (float)toggleCenter.y - 11.0f, GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}
