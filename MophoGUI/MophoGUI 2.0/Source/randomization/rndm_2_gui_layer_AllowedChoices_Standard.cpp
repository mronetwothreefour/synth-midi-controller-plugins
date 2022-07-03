#include "rndm_2_gui_layer_AllowedChoices_Standard.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_Standard::GUI_Layer_AllowedChoices_Standard(
	uint8 paramIndex, ExposedParameters* exposedParams, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams },
	button_Close{ unexposedParams },
	repeatChoicesToggle{ paramIndex, exposedParams, unexposedParams },
	button_Randomize{ paramIndex, exposedParams, randomize, unexposedParams },
	childrenShouldBeStackedVertically{ false },
	background_x{ exposedParams->info.allowedChoicesBackground_x_For(paramIndex) },
	background_y{ exposedParams->info.allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramName{ exposedParams->info.exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this, unexposedParams, paramIndex] {
		auto randomization{ unexposedParams->getRandomizationOptions() };
		randomization->allowAllChoicesForParam(paramIndex);
		allowChoiceToggles.restoreToggles(); 
	};
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices when\n";
		tip += "generating a random setting for\n";
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

	background_w = 2 * GUI::allowedChoices_Inset;
	background_h = 2 * GUI::allowedChoices_Inset + allowChoiceToggles.getHeight();
	if (allowChoiceToggles.getWidth() < (button_AllowAll.getWidth() + repeatChoicesToggle.getWidth() + button_Close.getWidth()))
		childrenShouldBeStackedVertically = true;
	if (childrenShouldBeStackedVertically) {
		background_w += jmax(button_Randomize.getWidth(), allowChoiceToggles.getWidth());
		background_h += 3 * GUI::redButton_h;
		background_h += repeatChoicesToggle.getHeight();
		background_h += 4 * GUI::allowedChoices_VertGap;
	}
	else {
		background_w += allowChoiceToggles.getWidth();
		background_h += 2 * GUI::redButton_h;
		background_h += 2 * GUI::allowedChoices_VertGap;
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_Standard::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ exposedParams->info.centerPointFor(paramIndex) };
	auto control_w{ exposedParams->info.widthFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	auto controlType{ exposedParams->info.controlTypeFor(paramIndex) };
	if (controlType == ControlType::knob ||
		controlType == ControlType::knobForPitch)
		g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	if (controlType == ControlType::comboBox)
		g.drawRect(controlCenter.x - control_w / 2 - 2, controlCenter.y - GUI::comboBox_h / 2 - 2, control_w + 4, GUI::comboBox_h + 4, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void GUI_Layer_AllowedChoices_Standard::resized() {
	auto center_x{ background_x + (background_w / 2) };
	auto center_y{ background_y + GUI::allowedChoices_Inset };
	if (childrenShouldBeStackedVertically) {
		center_y += GUI::redButton_h / 2;
		button_AllowAll.setCentrePosition(center_x, center_y);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
		allowChoiceToggles.setCentrePosition(center_x, center_y);
		center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + repeatChoicesToggle.getHeight() / 2;
		repeatChoicesToggle.setCentrePosition(center_x, center_y);
		center_y += repeatChoicesToggle.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		button_Randomize.setCentrePosition(center_x, center_y);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		button_Close.setCentrePosition(center_x, center_y);
	}
	else {
		button_AllowAll.setTopLeftPosition(background_x + GUI::allowedChoices_Inset, background_y + GUI::allowedChoices_Inset);
		center_y += GUI::redButton_h / 2;
		repeatChoicesToggle.setCentrePosition(center_x, center_y);
		button_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, background_y + GUI::allowedChoices_Inset);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
		allowChoiceToggles.setCentrePosition(center_x, center_y);
		center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		button_Randomize.setCentrePosition(center_x, center_y);
	}
}
