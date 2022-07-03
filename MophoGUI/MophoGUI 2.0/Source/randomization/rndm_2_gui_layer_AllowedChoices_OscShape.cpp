#include "rndm_2_gui_layer_AllowedChoices_OscShape.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_OscShape::GUI_Layer_AllowedChoices_OscShape(
	uint8 paramIndex, ExposedParameters* exposedParams, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	randomization{ unexposedParams->getRandomizationOptions() },
	repeatChoices{ paramIndex, exposedParams, unexposedParams },
	allowPulseWidthToggles{ paramIndex, exposedParams, unexposedParams },
	button_Close{ unexposedParams },
	button_Randomize{ paramIndex, exposedParams, randomize, unexposedParams },
	background_x{ exposedParams->info.allowedChoicesBackground_x_For(paramIndex) },
	background_y{ exposedParams->info.allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(exposedParams->info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramID{ exposedParams->info.IDfor(paramIndex).toString() };
	auto paramName{ exposedParams->info.exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };

	auto inset{ GUI::allowedChoices_Inset };
	auto inset_x{ background_x + inset };
	auto inset_y{ background_y + inset };
	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this] { allowAllChoices(); };
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the shapes when\n";
		tip += "generating a random setting for\n";
		tip += paramName + ".";
		button_AllowAll.setTooltip(tip);
	}
	button_AllowAll.setBounds(inset_x, inset_y, GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	repeatChoices.setTopLeftPosition(background_x + 192, background_y + 21);
	addAndMakeVisible(repeatChoices);

	button_Close.setTopRightPosition(background_x + background_w - inset, inset_y);
	addAndMakeVisible(button_Close);

	auto shapeTogglesRow_y{ background_y + 49 };
	toggle_Off.setComponentID(ID::component_RedToggle_AllowOscShape_Off.toString());
	toggle_Off.addListener(this);
	auto offIsAllowed{ randomization->oscShapeIsAllowedForParam(Shape::off, paramIndex) };
	toggle_Off.setToggleState(offIsAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Off is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Off.setTooltip(toggleTooltip);
	}
	toggle_Off.setBounds(inset_x, shapeTogglesRow_y, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_Off);

	toggle_Saw.setComponentID(ID::component_RedToggle_AllowOscShape_Saw.toString());
	toggle_Saw.addListener(this);
	auto sawtoothIsAllowed{ randomization->oscShapeIsAllowedForParam(Shape::sawtooth, paramIndex) };
	toggle_Saw.setToggleState(sawtoothIsAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Saw.setTooltip(toggleTooltip);
	}
	toggle_Saw.setBounds(background_x + 93, shapeTogglesRow_y, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_Saw);

	toggle_Tri.setComponentID(ID::component_RedToggle_AllowOscShape_Tri.toString());
	toggle_Tri.addListener(this);
	auto triangleIsAllowed{ randomization->oscShapeIsAllowedForParam(Shape::triangle, paramIndex) };
	toggle_Tri.setToggleState(triangleIsAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Triangle is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Tri.setTooltip(toggleTooltip);
	}
	toggle_Tri.setBounds(background_x + 219, shapeTogglesRow_y, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_Tri);

	toggle_SawTri.setComponentID(ID::component_RedToggle_AllowOscShape_SawTri.toString());
	toggle_SawTri.addListener(this);
	auto sawTriMixIsAllowed{ randomization->oscShapeIsAllowedForParam(Shape::sawTriMix, paramIndex) };
	toggle_SawTri.setToggleState(sawTriMixIsAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Sawtooth / Triangle Mixture is\n";
		toggleTooltip += "allowed when a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_SawTri.setTooltip(toggleTooltip);
	}
	toggle_SawTri.setBounds(background_x + 333, shapeTogglesRow_y, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_SawTri);

	toggle_Pulse.setComponentID(ID::component_RedToggle_AllowOscShape_Pulse.toString());
	toggle_Pulse.addListener(this);
	auto pulseIsAllowed{ randomization->oscShapeIsAllowedForParam(Shape::pulse, paramIndex) };
	toggle_Pulse.setToggleState(pulseIsAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not Pulse is allowed when\n";
		toggleTooltip += "a random shape is generated for oscillator " + oscNumString + ".\n";
		toggleTooltip += "at least one shape must always be allowed.\n";
		toggle_Pulse.setTooltip(toggleTooltip);
	}
	toggle_Pulse.setBounds(background_x + 192, background_y + 73, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_Pulse);

	if (pulseIsAllowed)
		allowPulseWidthToggles.restoreToggles();
	else
		allowPulseWidthToggles.disableToggles();
	allowPulseWidthToggles.setTopLeftPosition(inset_x, background_y + 92);
	addAndMakeVisible(allowPulseWidthToggles);

	button_Randomize.setTopLeftPosition(background_x + 189, background_y + 262);
	addAndMakeVisible(button_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_OscShape::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ exposedParams->info.centerPointFor(paramIndex) };
	g.setColour(GUI::color_ToggleOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
	MemoryInputStream memInputStream{ BinaryData::lbl_OscShapeCategories_png, BinaryData::lbl_OscShapeCategories_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x + GUI::allowedChoices_Inset, background_y + 49);
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
		randomization->setOscShapeIsAllowedForParam(clickedShape, shapeIsAllowed ? true : false, paramIndex);
		if (randomization->noOscShapeIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomization->setOscShapeIsAllowedForParam(clickedShape, true, paramIndex);
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
	randomization->clearAllowedOscShapesForParam(paramIndex);
	randomization->setOscShapeIsAllowedForParam(allowedShape, true, paramIndex);
	if (allowedShape == Shape::pulse)
		allowPulseWidthToggles.restoreToggles();
	else
		allowPulseWidthToggles.disableToggles();
}

void GUI_Layer_AllowedChoices_OscShape::allowAllChoices() {
	randomization->allowAllChoicesForOscShapeParam(paramIndex);
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