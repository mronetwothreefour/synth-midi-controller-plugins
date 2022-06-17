#include "rndm_2_gui_layer_AllowedChoices_OscShape.h"

#include "rndm_0_ParamRandomizationMethods.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



GUI_Layer_AllowedChoices_OscShape::GUI_Layer_AllowedChoices_OscShape(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	randomizationOptions{ unexposedParams->getRandomizationOptions() },
	repeatValues{ paramIndex, unexposedParams },
	allowPulseWidthToggles{ paramIndex, unexposedParams },
	button_Close{ unexposedParams },
	button_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ Info::get().allowedChoicesBackground_x_For(paramIndex) },
	background_y{ Info::get().allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramID{ Info::get().IDfor(paramIndex).toString() };
	auto paramName{ Info::get().exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this] { allowAllChoices(); };
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the shapes when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_AllowAll.setTooltip(buttonTooltip);
	}
	button_AllowAll.setSize(GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	addAndMakeVisible(repeatValues);

	addAndMakeVisible(button_Close);

	toggle_Off.setComponentID(ID::component_RedToggle_AllowOscShape_Off.toString());
	toggle_Off.addListener(this);
	auto offIsAllowed{ randomizationOptions->oscShapeIsAllowedForParam(Shape::off, paramIndex) };
	toggle_Off.setToggleState(offIsAllowed ? true : false, dontSendNotification);
	addAndMakeVisible(toggle_Off);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Off is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Off.setTooltip(toggleTooltip);
	}

	toggle_Saw.setComponentID(ID::component_RedToggle_AllowOscShape_Saw.toString());
	toggle_Saw.addListener(this);
	auto sawtoothIsAllowed{ randomizationOptions->oscShapeIsAllowedForParam(Shape::sawtooth, paramIndex) };
	toggle_Saw.setToggleState(sawtoothIsAllowed ? true : false, dontSendNotification);
	addAndMakeVisible(toggle_Saw);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Saw.setTooltip(toggleTooltip);
	}

	toggle_Tri.setComponentID(ID::component_RedToggle_AllowOscShape_Tri.toString());
	toggle_Tri.addListener(this);
	auto triangleIsAllowed{ randomizationOptions->oscShapeIsAllowedForParam(Shape::triangle, paramIndex) };
	toggle_Tri.setToggleState(triangleIsAllowed ? true : false, dontSendNotification);
	addAndMakeVisible(toggle_Tri);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Triangle is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Tri.setTooltip(toggleTooltip);
	}

	toggle_SawTri.setComponentID(ID::component_RedToggle_AllowOscShape_SawTri.toString());
	toggle_SawTri.addListener(this);
	auto sawTriMixIsAllowed{ randomizationOptions->oscShapeIsAllowedForParam(Shape::sawTriMix, paramIndex) };
	toggle_SawTri.setToggleState(sawTriMixIsAllowed ? true : false, dontSendNotification);
	addAndMakeVisible(toggle_SawTri);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth / Triangle Mixture is\n";
		toggleTooltip += "allowed when a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_SawTri.setTooltip(toggleTooltip);
	}

	toggle_Pulse.setComponentID(ID::component_RedToggle_AllowOscShape_Pulse.toString());
	toggle_Pulse.addListener(this);
	auto pulseIsAllowed{ randomizationOptions->oscShapeIsAllowedForParam(Shape::pulse, paramIndex) };
	toggle_Pulse.setToggleState(pulseIsAllowed ? true : false, dontSendNotification);
	addAndMakeVisible(toggle_Pulse);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Pulse is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Pulse.setTooltip(toggleTooltip);
	}

	if (pulseIsAllowed)
		allowPulseWidthToggles.restoreToggles();
	else
		allowPulseWidthToggles.disableToggles();
	addAndMakeVisible(allowPulseWidthToggles);

	addAndMakeVisible(button_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_OscShape::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ Info::get().centerPointFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void GUI_Layer_AllowedChoices_OscShape::resized() {
	auto inset{ GUI::allowedChoices_Inset };
	auto inset_x{ background_x + inset };
	auto inset_y{ background_y + inset };
	button_AllowAll.setTopLeftPosition(inset_x, inset_y);
	button_Close.setTopRightPosition(background_x + background_w - inset, inset_y);
	repeatValues.setTopLeftPosition(background_x + 192, background_y + 21);
	auto shapeTogglesRow_y{ background_y + 49 };
	toggle_Off.setTopLeftPosition(inset_x, shapeTogglesRow_y);
	toggle_Saw.setTopLeftPosition(background_x + 93, shapeTogglesRow_y);
	toggle_Tri.setTopLeftPosition(background_x + 219, shapeTogglesRow_y);
	toggle_SawTri.setTopLeftPosition(background_x + 333, shapeTogglesRow_y);
	toggle_Pulse.setTopLeftPosition(background_x + 192, background_y + 73);
	allowPulseWidthToggles.setTopLeftPosition(inset_x, background_y + 92);
}

void GUI_Layer_AllowedChoices_OscShape::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto clickedShape{ Shape::off };
	if (button == &toggle_Saw)
		clickedShape = Shape::sawtooth;
	if (button == &toggle_Tri)
		clickedShape = Shape::triangle;
	if (button == &toggle_SawTri)
		clickedShape = Shape::sawTriMix;
	if (button == &toggle_Pulse)
		clickedShape = Shape::pulse;
	if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier)
		makeShapeTheOnlyOneAllowed(clickedShape);
	else {
		auto shapeIsAllowed{ button->getToggleState() };
		randomizationOptions->setOscShapeIsAllowedForParam(clickedShape, shapeIsAllowed ? true : false, paramIndex);
		if (randomizationOptions->noOscShapeIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setOscShapeIsAllowedForParam(clickedShape, true, paramIndex);
		}
		if (clickedShape == Shape::pulse) {
			if (shapeIsAllowed)
				allowPulseWidthToggles.restoreToggles();
			else
				allowPulseWidthToggles.disableToggles();
		}
	}
}

void GUI_Layer_AllowedChoices_OscShape::makeShapeTheOnlyOneAllowed(Shape allowedShape) {
	toggle_Off.setToggleState(allowedShape == Shape::off ? true : false, dontSendNotification);
	toggle_Saw.setToggleState(allowedShape == Shape::sawtooth ? true : false, dontSendNotification);
	toggle_Tri.setToggleState(allowedShape == Shape::triangle ? true : false, dontSendNotification);
	toggle_SawTri.setToggleState(allowedShape == Shape::sawTriMix ? true : false, dontSendNotification);
	toggle_Pulse.setToggleState(allowedShape == Shape::pulse ? true : false, dontSendNotification);
	randomizationOptions->clearAllowedOscShapesForParam(paramIndex);
	randomizationOptions->setOscShapeIsAllowedForParam(allowedShape, true, paramIndex);
	if (allowedShape == Shape::pulse)
		allowPulseWidthToggles.restoreToggles();
	else
		allowPulseWidthToggles.disableToggles();
}

void GUI_Layer_AllowedChoices_OscShape::allowAllChoices() {
	randomizationOptions->allowAllChoicesForOscShapeParam(paramIndex);
	toggle_Off.setToggleState(true, dontSendNotification);
	toggle_Saw.setToggleState(true, dontSendNotification);
	toggle_Tri.setToggleState(true, dontSendNotification);
	toggle_SawTri.setToggleState(true, dontSendNotification);
	toggle_Pulse.setToggleState(true, dontSendNotification);
	allowPulseWidthToggles.restoreToggles();
}

GUI_Layer_AllowedChoices_OscShape::~GUI_Layer_AllowedChoices_OscShape() {
	toggle_Off.removeListener(this);
	toggle_Saw.removeListener(this);
	toggle_Tri.removeListener(this);
	toggle_SawTri.removeListener(this);
	toggle_Pulse.removeListener(this);
}
