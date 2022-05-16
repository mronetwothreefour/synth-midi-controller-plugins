#include "randomization_ParamOptionsComponent_OscShape.h"

#include "randomization_ParamRandomizationMethods.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ParamRandomizationOptionsComponent_OscShape::ParamRandomizationOptionsComponent_OscShape(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	repeatValues{ paramIndex, unexposedParams },
	pulseWidthToggleWidth{ 42 },
	numberOfPulseWidthToggleColumns{ 10 },
	numberOfPulseWidthToggleRows{ 10 },
	background_w{ 454 },
	background_h{ 301 }
{
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.randomizationOptionsTypeFor(paramIndex) == RandomizationOptionsType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto oscNum{ paramID.fromFirstOccurrenceOf("osc", false, false).upToFirstOccurrenceOf("_", false, false) };

	button_ForAllowingAllShapes.setComponentID(ID::button_AllValuesFor_.toString() + paramID);
	button_ForAllowingAllShapes.onClick = [this] { allowAllShapes(); };
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the shapes when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_ForAllowingAllShapes.setTooltip(buttonTooltip);
	}
	button_ForAllowingAllShapes.setSize(GUI::randomizationAllowAllValuesButton_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForAllowingAllShapes);

	addAndMakeVisible(repeatValues);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	button_ForClosingComponent.setSize(GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForClosingComponent);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };

	toggle_ForAllowingOff.setComponentID(ID::component_ToggleButton_AllowOscShape_Off_For_.toString() + paramID);
	toggle_ForAllowingOff.addListener(this);
	toggle_ForAllowingOff.setToggleState(randomizationOptions->oscShapeIsAllowedForParam((int)OscWaveShape::off, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingOff);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Off is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNum + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingOff.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSawtooth.setComponentID(ID::component_ToggleButton_AllowOscShape_Saw_For_.toString() + paramID);
	toggle_ForAllowingSawtooth.addListener(this);
	toggle_ForAllowingSawtooth.setToggleState(randomizationOptions->oscShapeIsAllowedForParam((int)OscWaveShape::sawtooth, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSawtooth);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNum + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingSawtooth.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingTriangle.setComponentID(ID::component_ToggleButton_AllowOscShape_Tri_For_.toString() + paramID);
	toggle_ForAllowingTriangle.addListener(this);
	toggle_ForAllowingTriangle.setToggleState(randomizationOptions->oscShapeIsAllowedForParam((int)OscWaveShape::triangle, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingTriangle);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Triangle is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNum + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingTriangle.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSawTriMix.setComponentID(ID::component_ToggleButton_AllowOscShape_SawTri_For_.toString() + paramID);
	toggle_ForAllowingSawTriMix.addListener(this);
	toggle_ForAllowingSawTriMix.setToggleState(randomizationOptions->oscShapeIsAllowedForParam((int)OscWaveShape::sawTriMix, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSawTriMix);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth / Triangle Mixture is\n";
		toggleTooltip += "allowed when a random shape is generated for oscillator " + oscNum + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingSawTriMix.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingPulse.setComponentID(ID::component_ToggleButton_AllowOscShape_Pulse_For_.toString() + paramID);
	toggle_ForAllowingPulse.addListener(this);
	toggle_ForAllowingPulse.setToggleState(randomizationOptions->oscShapeIsAllowedForParam((int)OscWaveShape::pulse, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingPulse);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Pulse is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNum + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingPulse.setTooltip(toggleTooltip);
	}

	for (auto pulseWidth = 0; pulseWidth != 100; ++pulseWidth) {
		allowedPulseWidthsToggles[pulseWidth].setComponentID(ID::component_Allow_ToggleButton_PulseWidth_.toString() + (String)pulseWidth + "_For_" + paramID);
		auto pulseWidthIsAllowed{ randomizationOptions->valueIsAllowedForParam((uint8)pulseWidth, paramIndex) };
		allowedPulseWidthsToggles[pulseWidth].setToggleState(pulseWidthIsAllowed, dontSendNotification);
		allowedPulseWidthsToggles[pulseWidth].addListener(this);
		allowedPulseWidthsToggles[pulseWidth].setHelpText("PW " + (String)pulseWidth);
		addAndMakeVisible(allowedPulseWidthsToggles[pulseWidth]);
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click a pulse width to toggle whether or\n";
			buttonTooltip += "not it is allowed when generating a random\n";
			buttonTooltip += "shape for oscillator " + oscNum + ".\n";
			buttonTooltip += "CTRL-click a pulse width make it the only one\n";
			buttonTooltip += "allowed. SHIFT-click to allow a range of\n";
			buttonTooltip += "pulse widths. ALT-click to allow a range of\n";
			buttonTooltip += "pulse widths that are all in the same row.";
			allowedPulseWidthsToggles[pulseWidth].setTooltip(buttonTooltip);
		}
	}

	button_ForRandomizingParameter.setComponentID(ID::button_Randomize.toString());
	button_ForRandomizingParameter.onClick = [exposedParams, unexposedParams, paramIndex] {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex).toString() };
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		paramRandomizationMethods.randomizeParameter(paramID);
	};
	if (shouldShowDescriptions)
		button_ForRandomizingParameter.setTooltip("Click to generate a random\nshape for oscillator " + oscNum + ".");
	button_ForRandomizingParameter.setSize(GUI::randomizeButton_w, GUI::secondaryWindowsControls_h);
	addAndMakeVisible(button_ForRandomizingParameter);

	background_x = info.randomizationOptions_x_For(paramIndex);
	background_y = info.randomizationOptions_y_For(paramIndex);

	setSize(GUI::editor_w, GUI::editor_h);
}

void ParamRandomizationOptionsComponent_OscShape::paint(Graphics& /*g*/)
{
}

void ParamRandomizationOptionsComponent_OscShape::resized()
{
}

void ParamRandomizationOptionsComponent_OscShape::buttonClicked(Button* /*button*/)
{
}

void ParamRandomizationOptionsComponent_OscShape::allowAllShapes()
{
}

void ParamRandomizationOptionsComponent_OscShape::turnOffAllPulseWidthToggles()
{
}

void ParamRandomizationOptionsComponent_OscShape::restorePulseWidthToggles()
{
}

void ParamRandomizationOptionsComponent_OscShape::hideThisComponent()
{
}
