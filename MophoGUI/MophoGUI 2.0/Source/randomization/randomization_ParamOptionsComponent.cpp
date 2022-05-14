#include "randomization_ParamOptionsComponent.h"

#include "randomization_ParamRandomizationMethods.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



ParamRandomizationOptionsComponent::ParamRandomizationOptionsComponent(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	allowedValuesToggles{ paramIndex, unexposedParams },
	repeatValues{ paramIndex, unexposedParams },
	childrenShouldBeStackedVertically{ false }
{
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	button_ForAllowingAllValues.setComponentID(ID::button_AllValuesFor_.toString() + paramID);
	button_ForAllowingAllValues.onClick = [this] { allowedValuesToggles.allowAllValues(); };
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the values when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_ForAllowingAllValues.setTooltip(buttonTooltip);
	}
	button_ForAllowingAllValues.setSize(GUI::randomizationAllowAllValuesButton_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForAllowingAllValues);

	addAndMakeVisible(repeatValues);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	button_ForClosingComponent.setSize(GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForClosingComponent);

	addAndMakeVisible(allowedValuesToggles);

	button_ForRandomizingParameter.setComponentID(ID::button_Randomize.toString());
	button_ForRandomizingParameter.onClick = [exposedParams, unexposedParams, paramIndex] {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex).toString() };
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		paramRandomizationMethods.randomizeParameter(paramID);
	};
	if (shouldShowDescriptions)
		button_ForRandomizingParameter.setTooltip("Click to generate a random value\nfor " + paramName + ".");
	button_ForRandomizingParameter.setSize(GUI::randomizeButton_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForRandomizingParameter);

	background_x = info.randomizationOptions_x_For(paramIndex);
	background_y = info.randomizationOptions_y_For(paramIndex);
	background_w = 2 * GUI::randomizationOptionsComponents_Inset;
	background_h = 2 * GUI::randomizationOptionsComponents_Inset + allowedValuesToggles.getHeight();
	if (allowedValuesToggles.getWidth() < (GUI::randomizationAllowAllValuesButton_w + GUI::randomizationRepeatValuesComponents_w + GUI::secondaryWindowsControls_w))
		childrenShouldBeStackedVertically = true;
	if (childrenShouldBeStackedVertically) {
		background_w += jmax(GUI::randomizeButton_w, allowedValuesToggles.getWidth());
		background_h += 3 * GUI::secondaryWindowsControls_h;
		background_h += GUI::randomizationRepeatValuesComponents_h;
		background_h += 4 * GUI::randomizationOptionsComponents_VertGapBetweenChildren;
	}
	else {
		background_w += allowedValuesToggles.getWidth();
		background_h += 2 * GUI::secondaryWindowsControls_h;
		background_h += 2 * GUI::randomizationOptionsComponents_VertGapBetweenChildren;
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void ParamRandomizationOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	auto control_w{ info.controlWidthFor(paramIndex) };
	g.setColour(Color::switchOn);
	auto controlType{ info.controlTypeFor(paramIndex) };
	if (controlType == ControlType::knobForPitchWithValueStringDisplay ||
		controlType == ControlType::knobWithValueStringDisplay)
		g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	if (controlType == ControlType::comboBox)
		g.drawRect(controlCenter.x - control_w / 2 - 2, controlCenter.y - GUI::comboBox_h / 2 - 2, control_w + 4, GUI::comboBox_h + 4, 2);
	g.setColour(Color::black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(Color::device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void ParamRandomizationOptionsComponent::resized() {
	auto center_x{ background_x + (background_w / 2) };
	auto center_y{ background_y + GUI::randomizationOptionsComponents_Inset };
	if (childrenShouldBeStackedVertically) {
		center_y += GUI::secondaryWindowsControls_h / 2;
		button_ForAllowingAllValues.setCentrePosition(center_x, center_y);
		center_y += GUI::secondaryWindowsControls_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + allowedValuesToggles.getHeight() / 2;
		allowedValuesToggles.setCentrePosition(center_x, center_y);
		center_y += allowedValuesToggles.getHeight() / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::randomizationRepeatValuesComponents_h / 2;
		repeatValues.setCentrePosition(center_x, center_y);
		center_y += GUI::randomizationRepeatValuesComponents_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::secondaryWindowsControls_h / 2;
		button_ForRandomizingParameter.setCentrePosition(center_x, center_y);
		center_y += GUI::secondaryWindowsControls_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::secondaryWindowsControls_h / 2;
		button_ForClosingComponent.setCentrePosition(center_x, center_y);
	}
	else {
		button_ForAllowingAllValues.setTopLeftPosition(background_x + GUI::randomizationOptionsComponents_Inset, background_y + GUI::randomizationOptionsComponents_Inset);
		center_y += GUI::secondaryWindowsControls_h / 2;
		repeatValues.setCentrePosition(center_x, center_y);
		button_ForClosingComponent.setTopRightPosition(background_x + background_w - GUI::randomizationOptionsComponents_Inset, background_y + GUI::randomizationOptionsComponents_Inset);
		center_y += GUI::secondaryWindowsControls_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + allowedValuesToggles.getHeight() / 2;
		allowedValuesToggles.setCentrePosition(center_x, center_y);
		center_y += allowedValuesToggles.getHeight() / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::secondaryWindowsControls_h / 2;
		button_ForRandomizingParameter.setCentrePosition(center_x, center_y);
	}
}

void ParamRandomizationOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
