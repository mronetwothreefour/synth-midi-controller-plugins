#include "1_rndm_gui_layer_AllowedChoices_OscShape.h"

#include "0_rndm_ParamRandomizationMethods.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_OscShape::GUI_Layer_AllowedChoices_OscShape(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	repeatValues{ paramIndex, unexposedParams },
	button_Close{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };

	button_ForAllowingAllShapes.setComponentID(ID::button_AllowAll.toString());
	button_ForAllowingAllShapes.onClick = [this] { allowAllShapes(); };
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the shapes when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_ForAllowingAllShapes.setTooltip(buttonTooltip);
	}
	button_ForAllowingAllShapes.setSize(GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_ForAllowingAllShapes);

	addAndMakeVisible(repeatValues);

	addAndMakeVisible(button_Close);

	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };

	toggle_ForAllowingOff.setComponentID(ID::component_ToggleAllowOscShape_Off_For_.toString() + paramID);
	toggle_ForAllowingOff.addListener(this);
	toggle_ForAllowingOff.setToggleState(randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::off, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingOff);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Off is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingOff.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSawtooth.setComponentID(ID::component_ToggleAllowOscShape_Saw_For_.toString() + paramID);
	toggle_ForAllowingSawtooth.addListener(this);
	toggle_ForAllowingSawtooth.setToggleState(randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::sawtooth, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSawtooth);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingSawtooth.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingTriangle.setComponentID(ID::component_ToggleAllowOscShape_Tri_For_.toString() + paramID);
	toggle_ForAllowingTriangle.addListener(this);
	toggle_ForAllowingTriangle.setToggleState(randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::triangle, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingTriangle);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Triangle is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingTriangle.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSawTriMix.setComponentID(ID::component_ToggleAllowOscShape_SawTri_For_.toString() + paramID);
	toggle_ForAllowingSawTriMix.addListener(this);
	toggle_ForAllowingSawTriMix.setToggleState(randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::sawTriMix, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSawTriMix);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth / Triangle Mixture is\n";
		toggleTooltip += "allowed when a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingSawTriMix.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingPulse.setComponentID(ID::component_ToggleAllowOscShape_Pulse_For_.toString() + paramID);
	toggle_ForAllowingPulse.addListener(this);
	toggle_ForAllowingPulse.setToggleState(randomizationOptions->oscShapeIsAllowedForParam(OscWaveShape::pulse, paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingPulse);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Pulse is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_ForAllowingPulse.setTooltip(toggleTooltip);
	}

	for (auto pulseWidth = 0; pulseWidth != 100; ++pulseWidth) {
		allowedPulseWidthsToggles[pulseWidth].setComponentID(ID::component_ToggleAllowPulseWidth_.toString() + (String)pulseWidth + "_For_" + paramID);
		auto pulseWidthIsAllowed{ randomizationOptions->pulseWidthIsAllowedForParam((uint8)pulseWidth, paramIndex) };
		allowedPulseWidthsToggles[pulseWidth].setToggleState(pulseWidthIsAllowed, dontSendNotification);
		allowedPulseWidthsToggles[pulseWidth].addListener(this);
		allowedPulseWidthsToggles[pulseWidth].setHelpText("PW " + (String)pulseWidth);
		addAndMakeVisible(allowedPulseWidthsToggles[pulseWidth]);
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click a pulse width to toggle whether or\n";
			buttonTooltip += "not it is allowed when generating a random\n";
			buttonTooltip += "shape for oscillator " + oscNumString + ".\n";
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
		button_ForRandomizingParameter.setTooltip("Click to generate a random\nshape for oscillator " + oscNumString + ".");
	button_ForRandomizingParameter.setSize(GUI::button_Randomize_w, GUI::redButton_h);
	addAndMakeVisible(button_ForRandomizingParameter);

	background_x = info.allowedChoicesBackground_x_For(paramIndex);
	background_y = info.allowedChoicesBackground_y_For(paramIndex);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_OscShape::paint(Graphics& g)
{
}

void GUI_Layer_AllowedChoices_OscShape::resized()
{
}

void GUI_Layer_AllowedChoices_OscShape::buttonClicked(Button* button)
{
}

void GUI_Layer_AllowedChoices_OscShape::allowAllShapes()
{
}

void GUI_Layer_AllowedChoices_OscShape::disablePulseWidthToggles()
{
}

void GUI_Layer_AllowedChoices_OscShape::restorePulseWidthToggles()
{
}
