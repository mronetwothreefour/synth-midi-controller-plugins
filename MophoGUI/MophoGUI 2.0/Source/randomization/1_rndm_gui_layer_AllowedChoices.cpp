#include "1_rndm_gui_layer_AllowedChoices.h"

#include "0_rndm_ParamRandomizationMethods.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices::GUI_Layer_AllowedChoices(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	button_Close{ unexposedParams },
	allowChoiceToggles{ paramIndex, unexposedParams },
	repeatChoicesToggle{ paramIndex, unexposedParams },
	childrenShouldBeStackedVertically{ false }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this] { allowChoiceToggles.allowAllChoices(); };
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the choices when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_AllowAll.setTooltip(buttonTooltip);
	}
	button_AllowAll.setSize(GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	addAndMakeVisible(repeatChoicesToggle);

	addAndMakeVisible(button_Close);

	addAndMakeVisible(allowChoiceToggles);

	button_Randomize.setComponentID(ID::button_Randomize.toString());
	button_Randomize.onClick = [exposedParams, unexposedParams, paramIndex] {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex).toString() };
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		paramRandomizationMethods.randomizeParameter(paramID);
	};
	if (shouldShowDescriptions)
		button_Randomize.setTooltip("Click to assign a random setting\nto " + paramName + ".");
	button_Randomize.setSize(GUI::button_Randomize_w, GUI::redButton_h);
	addAndMakeVisible(button_Randomize);

	background_x = info.allowedChoicesBackground_x_For(paramIndex);
	background_y = info.allowedChoicesBackground_y_For(paramIndex);
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

void GUI_Layer_AllowedChoices::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.centerPointFor(paramIndex) };
	auto control_w{ info.widthFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	auto controlType{ info.controlTypeFor(paramIndex) };
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

void GUI_Layer_AllowedChoices::resized() {
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
