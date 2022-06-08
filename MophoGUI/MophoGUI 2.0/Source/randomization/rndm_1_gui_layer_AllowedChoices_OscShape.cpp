#include "rndm_1_gui_layer_AllowedChoices_OscShape.h"

#include "rndm_0_ParamRandomizationMethods.h"
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
	jassert(info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto oscNumString{ paramID.fromFirstOccurrenceOf("Osc_", false, false).upToFirstOccurrenceOf("_Shape", false, false) };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this] { allowAllShapes(); };
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

	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };

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

	for (auto pulseWidth = 0; pulseWidth != numberOfPulseWidths; ++pulseWidth) {
		allowPulseWidthToggles[pulseWidth].setComponentID(ID::component_ToggleAllow_PulseWidth_.toString() + (String)pulseWidth);
		auto pulseWidthIsAllowed{ randomizationOptions->pulseWidthIsAllowedForParam((uint8)pulseWidth, paramIndex) };
		allowPulseWidthToggles[pulseWidth].setToggleState(pulseWidthIsAllowed ? true : false, dontSendNotification);
		allowPulseWidthToggles[pulseWidth].addListener(this);
		allowPulseWidthToggles[pulseWidth].setName("PW " + (String)pulseWidth);
		addAndMakeVisible(allowPulseWidthToggles[pulseWidth]);
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click a pulse width to toggle whether or\n";
			buttonTooltip += "not it is allowed when generating a random\n";
			buttonTooltip += "shape for oscillator " + oscNumString + ".\n";
			buttonTooltip += "CTRL-click a pulse width make it the only one\n";
			buttonTooltip += "allowed. SHIFT-click to allow a range of\n";
			buttonTooltip += "pulse widths. ALT-click to allow a range of\n";
			buttonTooltip += "pulse widths that are all in the same row.";
			allowPulseWidthToggles[pulseWidth].setTooltip(buttonTooltip);
		}
		allowPulseWidthToggles[pulseWidth].setSize(pulseWidthToggle_w, GUI::allowChoiceToggle_h);
	}

	button_Randomize.setComponentID(ID::button_Randomize.toString());
	button_Randomize.onClick = [exposedParams, unexposedParams, paramIndex] {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex).toString() };
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		paramRandomizationMethods.randomizeParameter(paramID);
	};
	if (shouldShowDescriptions)
		button_Randomize.setTooltip("Click to generate a random\nshape for oscillator " + oscNumString + ".");
	button_Randomize.setSize(GUI::button_Randomize_w, GUI::redButton_h);
	addAndMakeVisible(button_Randomize);

	background_x = info.allowedChoicesBackground_x_For(paramIndex);
	background_y = info.allowedChoicesBackground_y_For(paramIndex);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_OscShape::paint(Graphics& g) {
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
	auto rowCount{ 0 };
	auto colCount{ 0 };
	for (auto pulseWidth = 0; pulseWidth < numberOfPulseWidths; ++pulseWidth) {
		if (rowCount == numberOfRows) {
			rowCount = 0;
			++colCount;
		}
		allowPulseWidthToggles[pulseWidth].setTopLeftPosition(colCount * pulseWidthToggle_w, rowCount * GUI::allowChoiceToggle_h);
		++rowCount;
	}
}

void GUI_Layer_AllowedChoices_OscShape::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	if (buttonID.startsWith(ID::component_ToggleAllow_PulseWidth_.toString())) {
		auto clickedPulseWidth{ buttonID.fromFirstOccurrenceOf("Width_", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto pulseWidth = 0; pulseWidth != numberOfPulseWidths; ++pulseWidth) {
				if (pulseWidth == clickedPulseWidth) {
					allowPulseWidthToggles[clickedPulseWidth].setToggleState(true, dontSendNotification);
					randomizationOptions->allowPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
				}
				else {
					allowPulseWidthToggles[pulseWidth].setToggleState(false, dontSendNotification);
					randomizationOptions->forbidPulseWidthForParam((uint8)pulseWidth, paramIndex);
				}
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::shiftModifier) {
			auto nextAllowedPulseWidth{ numberOfPulseWidths };
			for (auto nextPulseWidth = clickedPulseWidth - 1; nextPulseWidth > -1; --nextPulseWidth) {
				if (randomizationOptions->pulseWidthIsAllowedForParam((uint8)nextPulseWidth, paramIndex)) {
					nextAllowedPulseWidth = nextPulseWidth;
					break;
				}
			}
			if (nextAllowedPulseWidth == numberOfPulseWidths) {
				for (auto nextPulseWidth = clickedPulseWidth + 1; nextPulseWidth < numberOfPulseWidths; ++nextPulseWidth) {
					if (randomizationOptions->pulseWidthIsAllowedForParam((uint8)nextPulseWidth, paramIndex)) {
						nextAllowedPulseWidth = nextPulseWidth;
						break;
					}
				}
			}
			if (nextAllowedPulseWidth != numberOfPulseWidths) {
				if (nextAllowedPulseWidth < clickedPulseWidth) {
					for (auto pulseWidth = nextAllowedPulseWidth; pulseWidth <= clickedPulseWidth; ++pulseWidth) {
						allowPulseWidthToggles[pulseWidth].setToggleState(true, dontSendNotification);
						randomizationOptions->allowPulseWidthForParam((uint8)pulseWidth, paramIndex);
					}
				}
				else {
					for (auto pulseWidth = clickedPulseWidth; pulseWidth <= nextAllowedPulseWidth; ++pulseWidth) {
						allowPulseWidthToggles[pulseWidth].setToggleState(true, dontSendNotification);
						randomizationOptions->allowPulseWidthForParam((uint8)pulseWidth, paramIndex);
					}
				}
			}
			else {
				allowPulseWidthToggles[clickedPulseWidth].setToggleState(true, dontSendNotification);
				randomizationOptions->allowPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
			auto nextAllowedPulseWidth{ numberOfPulseWidths };
			for (auto nextPulseWidth = clickedPulseWidth - numberOfRows; nextPulseWidth > -1; nextPulseWidth -= numberOfRows) {
				if (randomizationOptions->pulseWidthIsAllowedForParam((uint8)nextPulseWidth, paramIndex)) {
					nextAllowedPulseWidth = nextPulseWidth;
					break;
				}
			}
			if (nextAllowedPulseWidth == numberOfPulseWidths) {
				for (auto nextPulseWidth = clickedPulseWidth + numberOfRows; nextPulseWidth < numberOfPulseWidths; nextPulseWidth += numberOfRows) {
					if (randomizationOptions->pulseWidthIsAllowedForParam((uint8)nextPulseWidth, paramIndex)) {
						nextAllowedPulseWidth = nextPulseWidth;
						break;
					}
				}
			}
			if (nextAllowedPulseWidth != numberOfPulseWidths) {
				if (nextAllowedPulseWidth < clickedPulseWidth) {
					for (auto nextPulseWidth = nextAllowedPulseWidth; nextPulseWidth <= clickedPulseWidth; nextPulseWidth += numberOfRows) {
						allowPulseWidthToggles[nextPulseWidth].setToggleState(true, dontSendNotification);
						randomizationOptions->allowPulseWidthForParam((uint8)nextPulseWidth, paramIndex);
					}
				}
				else {
					for (auto nextPulseWidth = clickedPulseWidth; nextPulseWidth <= nextAllowedPulseWidth; nextPulseWidth += numberOfRows) {
						allowPulseWidthToggles[nextPulseWidth].setToggleState(true, dontSendNotification);
						randomizationOptions->allowPulseWidthForParam((uint8)nextPulseWidth, paramIndex);
					}
				}
			}
			else {
				allowPulseWidthToggles[clickedPulseWidth].setToggleState(true, dontSendNotification);
				randomizationOptions->allowPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
			}
		}
		else {
			auto pulseWidthIsAllowed{ button->getToggleState() };
			if (pulseWidthIsAllowed)
				randomizationOptions->allowPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
			else
				randomizationOptions->forbidPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
		}
		if (randomizationOptions->noPulseWidthIsAllowedForParam(paramIndex)) {
			if (clickedPulseWidth > -1 && clickedPulseWidth < numberOfPulseWidths) {
				allowPulseWidthToggles[clickedPulseWidth].setToggleState(true, dontSendNotification);
				randomizationOptions->allowPulseWidthForParam((uint8)clickedPulseWidth, paramIndex);
			}
		}
	}
	else {
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
			if (button->getToggleState() == true) {
				randomizationOptions->allowOscShapeForParam(clickedShape, paramIndex);
				if (clickedShape == Shape::pulse)
					restorePulseWidthToggles();
			}
			else {
				randomizationOptions->forbidOscShapeForParam(clickedShape, paramIndex);
				if (clickedShape == Shape::pulse)
					disablePulseWidthToggles();
			}
		}
	}
}

void GUI_Layer_AllowedChoices_OscShape::makeShapeTheOnlyOneAllowed(Shape shape) {
	toggle_Off.setToggleState(shape == Shape::off ? true : false, dontSendNotification);
	toggle_Saw.setToggleState(shape == Shape::sawtooth ? true : false, dontSendNotification);
	toggle_Tri.setToggleState(shape == Shape::triangle ? true : false, dontSendNotification);
	toggle_SawTri.setToggleState(shape == Shape::sawTriMix ? true : false, dontSendNotification);
	toggle_Pulse.setToggleState(shape == Shape::pulse ? true : false, dontSendNotification);
	for (auto shapeIndex = (int)Shape::off; shapeIndex <= (int)Shape::pulse; ++shapeIndex) {
		auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
		if (shapeIndex == (int)shape)
			randomizationOptions->allowOscShapeForParam(shape, paramIndex);
		else
			randomizationOptions->forbidOscShapeForParam(Shape{ shapeIndex }, paramIndex);
	}
	if (shape == Shape::pulse)
		restorePulseWidthToggles();
	else
		disablePulseWidthToggles();
}

void GUI_Layer_AllowedChoices_OscShape::allowAllShapes() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	toggle_Off.setToggleState(true, dontSendNotification);
	randomizationOptions->allowOscShapeForParam(Shape::off, paramIndex);
	toggle_Saw.setToggleState(true, dontSendNotification);
	randomizationOptions->allowOscShapeForParam(Shape::sawtooth, paramIndex);
	toggle_Tri.setToggleState(true, dontSendNotification);
	randomizationOptions->allowOscShapeForParam(Shape::triangle, paramIndex);
	toggle_SawTri.setToggleState(true, dontSendNotification);
	randomizationOptions->allowOscShapeForParam(Shape::sawTriMix, paramIndex);
	toggle_Pulse.setToggleState(true, dontSendNotification);
	randomizationOptions->allowOscShapeForParam(Shape::pulse, paramIndex);
	for (auto pulseWidth = (uint8)0; pulseWidth != numberOfPulseWidths; ++pulseWidth) {
		allowPulseWidthToggles[pulseWidth].setToggleState(true, dontSendNotification);
		allowPulseWidthToggles[pulseWidth].setEnabled(true);
		randomizationOptions->allowPulseWidthForParam(pulseWidth, paramIndex);
	}
}

void GUI_Layer_AllowedChoices_OscShape::disablePulseWidthToggles() {
	for (auto pulseWidth = 0; pulseWidth != numberOfPulseWidths; ++pulseWidth) {
		allowPulseWidthToggles[pulseWidth].setToggleState(false, dontSendNotification);
		allowPulseWidthToggles[pulseWidth].setEnabled(false);
	}
}

void GUI_Layer_AllowedChoices_OscShape::restorePulseWidthToggles() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	for (auto pulseWidth = 0; pulseWidth != numberOfPulseWidths; ++pulseWidth) {
		auto allowed{ randomizationOptions->pulseWidthIsAllowedForParam(pulseWidth, paramIndex) };
		allowPulseWidthToggles[pulseWidth].setToggleState(allowed ? true : false, dontSendNotification);
		allowPulseWidthToggles[pulseWidth].setEnabled(true);
	}
}

GUI_Layer_AllowedChoices_OscShape::~GUI_Layer_AllowedChoices_OscShape() {
	toggle_Off.removeListener(this);
	toggle_Saw.removeListener(this);
	toggle_Tri.removeListener(this);
	toggle_SawTri.removeListener(this);
	toggle_Pulse.removeListener(this);
	for (auto pulseWidth = 0; pulseWidth != numberOfPulseWidths; ++pulseWidth)
		allowPulseWidthToggles[pulseWidth].removeListener(this);
}
