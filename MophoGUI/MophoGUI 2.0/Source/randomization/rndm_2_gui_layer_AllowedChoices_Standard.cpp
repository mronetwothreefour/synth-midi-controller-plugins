#include "rndm_2_gui_layer_AllowedChoices_Standard.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_AllowedChoices_Standard::GUI_Layer_AllowedChoices_Standard(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	info{ exposedParams->info.get() },
	allowChoiceToggles{ paramIndex, exposedParams, unexposedParams },
	btn_Close{ unexposedParams },
	repeatChoicesToggle{ paramIndex, exposedParams, unexposedParams },
	btn_Randomize{ paramIndex, exposedParams, unexposedParams },
	childrenShouldBeStackedVertically{ false },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	auto paramName{ info->exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };

	btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
	btn_AllowAll.onClick = [this, exposedParams, paramIndex] {
		auto randomization{ exposedParams->randomization.get() };
		randomization->allowAllChoicesForParam(paramIndex);
		allowChoiceToggles.restoreToggles(); 
	};
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices when\n";
		tip += "generating a random setting for\n";
		tip += paramName + ".";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setSize(GUI::btn_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(btn_AllowAll);

	addAndMakeVisible(repeatChoicesToggle);

	addAndMakeVisible(btn_Close);

	allowChoiceToggles.restoreToggles();
	addAndMakeVisible(allowChoiceToggles);

	addAndMakeVisible(btn_Randomize);

	background_w = 2 * GUI::allowedChoices_Inset;
	background_h = 2 * GUI::allowedChoices_Inset + allowChoiceToggles.getHeight();
	if (allowChoiceToggles.getWidth() < (btn_AllowAll.getWidth() + repeatChoicesToggle.getWidth() + btn_Close.getWidth()))
		childrenShouldBeStackedVertically = true;
	if (childrenShouldBeStackedVertically) {
		background_w += jmax(btn_Randomize.getWidth(), allowChoiceToggles.getWidth());
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
	auto controlCenter{ info->centerPointFor(paramIndex) };
	auto control_w{ info->widthFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	auto controlType{ info->controlTypeFor(paramIndex) };
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
		btn_AllowAll.setCentrePosition(center_x, center_y);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
		allowChoiceToggles.setCentrePosition(center_x, center_y);
		center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + repeatChoicesToggle.getHeight() / 2;
		repeatChoicesToggle.setCentrePosition(center_x, center_y);
		center_y += repeatChoicesToggle.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		btn_Randomize.setCentrePosition(center_x, center_y);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		btn_Close.setCentrePosition(center_x, center_y);
	}
	else {
		btn_AllowAll.setTopLeftPosition(background_x + GUI::allowedChoices_Inset, background_y + GUI::allowedChoices_Inset);
		center_y += GUI::redButton_h / 2;
		repeatChoicesToggle.setCentrePosition(center_x, center_y);
		btn_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, background_y + GUI::allowedChoices_Inset);
		center_y += GUI::redButton_h / 2 + GUI::allowedChoices_VertGap + allowChoiceToggles.getHeight() / 2;
		allowChoiceToggles.setCentrePosition(center_x, center_y);
		center_y += allowChoiceToggles.getHeight() / 2 + GUI::allowedChoices_VertGap + GUI::redButton_h / 2;
		btn_Randomize.setCentrePosition(center_x, center_y);
	}
}
