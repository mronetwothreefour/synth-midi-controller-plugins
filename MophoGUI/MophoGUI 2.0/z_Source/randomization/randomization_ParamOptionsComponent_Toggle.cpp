#include "randomization_ParamOptionsComponent_Toggle.h"

#include "randomization_ParamRandomizationMethods.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ParamRandomizationOptionsComponent_Toggle::ParamRandomizationOptionsComponent_Toggle(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	repeatValues{ paramIndex, unexposedParams },
	background_w{ 110 },
	background_h{ 112 }
{
	jassert(paramIndex < params::numberOfExposedParams);
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	addAndMakeVisible(repeatValues);

	button_ForRandomizingParameter.setComponentID(ID::button_Randomize.toString());
	button_ForRandomizingParameter.onClick = [exposedParams, unexposedParams, paramIndex] {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex).toString() };
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		paramRandomizationMethods.randomizeParameter(paramID);
	};
	if (shouldShowDescriptions)
		button_ForRandomizingParameter.setTooltip("Click to generate a random setting\nfor " + paramName + ".");
	button_ForRandomizingParameter.setSize(GUI::randomizeButton_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForRandomizingParameter);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	button_ForClosingComponent.setSize(GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForClosingComponent);

	background_x = info.randomizationOptions_x_For(paramIndex);
	background_y = info.randomizationOptions_y_For(paramIndex);

	setSize(GUI::editor_w, GUI::editor_h);
}

void ParamRandomizationOptionsComponent_Toggle::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 11.0f, (float)controlCenter.y - 11.0f, GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter, 2);
	g.setColour(Color::black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(Color::device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void ParamRandomizationOptionsComponent_Toggle::resized() {
	auto center_x{ background_x + (background_w / 2) };
	auto center_y{ background_y + GUI::randomizationOptionsComponents_Inset };
		center_y += GUI::randomizationRepeatValuesComponents_h / 2;
		repeatValues.setCentrePosition(center_x, center_y);
		center_y += GUI::randomizationRepeatValuesComponents_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::secondaryWindowsControls_h / 2;
		button_ForRandomizingParameter.setCentrePosition(center_x, center_y);
		center_y += GUI::secondaryWindowsControls_h / 2 + GUI::randomizationOptionsComponents_VertGapBetweenChildren + GUI::secondaryWindowsControls_h / 2;
		button_ForClosingComponent.setCentrePosition(center_x, center_y);
}

void ParamRandomizationOptionsComponent_Toggle::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
