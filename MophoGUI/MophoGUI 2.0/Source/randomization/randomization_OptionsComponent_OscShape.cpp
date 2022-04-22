#include "randomization_OptionsComponent_OscShape.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_OscShape::RandomizationOptionsComponent_OscShape(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	knob_ForMinWidth{ unexposedParams },
	valueDisplay_ForMinWidth{ &knob_ForMinWidth, IntToPlainValueString::get() },
	knob_ForMaxWidth{ unexposedParams },
	valueDisplay_ForMaxWidth{ &knob_ForMaxWidth, IntToPlainValueString::get() }
{
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.randomizationOptionsTypeFor(paramIndex) == RandomizationOptionsType::oscShape);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto oscNum{ paramID.fromFirstOccurrenceOf("osc", false, false).upToFirstOccurrenceOf("_", false, false) };

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

	button_ForAllowingAllShapes.setComponentID(ID::button_AllShapesFor_.toString() + paramID);
	button_ForAllowingAllShapes.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all shapes (and pulse widths)\n";
		buttonTooltip += "when generating a random shape for oscillator " + oscNum + ".";
		button_ForAllowingAllShapes.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllShapes);

	knob_ForMinWidth.setComponentID(ID::component_KnobForMinPulseWidthFor_.toString() + paramID);
	knob_ForMinWidth.setRange(0.0, (double)params::maxPulseWidth, 1.0);
	knob_ForMinWidth.setValue((double)randomizationOptions->minPulseWidthAllowedForParam(paramIndex));
	knob_ForMinWidth.setDoubleClickReturnValue(true, 0.0);
	knob_ForMinWidth.setMouseDragSensitivity(130);
	knob_ForMinWidth.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the minimum pulse width\n";
		knobTooltip += "allowed for oscillator " + oscNum + ".\n";
		knobTooltip += "Range: 0 to 99.";
		knob_ForMinWidth.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMinWidth);

	addAndMakeVisible(valueDisplay_ForMinWidth);
	valueDisplay_ForMinWidth.setInterceptsMouseClicks(false, false);

	knob_ForMaxWidth.setComponentID(ID::component_KnobForMaxPulseWidthFor_.toString() + paramID);
	knob_ForMaxWidth.setRange(0.0, (double)params::maxPulseWidth, 1.0);
	knob_ForMaxWidth.setValue((double)randomizationOptions->maxPulseWidthAllowedForParam(paramIndex));
	knob_ForMaxWidth.setDoubleClickReturnValue(true, (double)params::maxPulseWidth);
	knob_ForMaxWidth.setMouseDragSensitivity(130);
	knob_ForMaxWidth.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the maximum pulse width\n";
		knobTooltip += "allowed for oscillator " + oscNum + ".\n";
		knobTooltip += "Range: 0 to 99.";
		knob_ForMaxWidth.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMaxWidth);

	addAndMakeVisible(valueDisplay_ForMaxWidth);
	valueDisplay_ForMaxWidth.setInterceptsMouseClicks(false, false);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	background_x = 178;
	background_y = controlCenter.y - GUI::knob_diameter / 2;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_OscShape::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsOscShapeBackground_png, BinaryData::RandomizationOptionsOscShapeBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}

void RandomizationOptionsComponent_OscShape::resized() {
	toggle_ForAllowingOff.setBounds(background_x + GUI::randomizationOscShapeOptionsToggles_x, background_y + GUI::randomizationOscShapeOptionsToggleForOff_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingSawtooth.setBounds(background_x + GUI::randomizationOscShapeOptionsToggles_x, background_y + GUI::randomizationOscShapeOptionsToggleForSaw_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingTriangle.setBounds(background_x + GUI::randomizationOscShapeOptionsToggles_x, background_y + GUI::randomizationOscShapeOptionsToggleForTri_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingSawTriMix.setBounds(background_x + GUI::randomizationOscShapeOptionsToggles_x, background_y + GUI::randomizationOscShapeOptionsToggleForSawTri_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingPulse.setBounds(background_x + GUI::randomizationOscShapeOptionsToggles_x, background_y + GUI::randomizationOscShapeOptionsToggleForPulse_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllShapes.setBounds(background_x + GUI::randomizationAllowAllShapesButton_x, background_y + GUI::randomizationAllowAllShapesButton_y, GUI::randomizationAllowAllShapesButton_w, GUI::secondaryWindowsControls_h);

	knob_ForMinWidth.setBounds( background_x + GUI::randomizationOptionsComponent_OscShape_MinKnob_x, background_y + GUI::randomizationOptionsComponent_OscShape_Knobs_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinWidth.setBounds(knob_ForMinWidth.getBounds());
	knob_ForMaxWidth.setBounds( background_x + GUI::randomizationOptionsComponent_OscShape_MaxKnob_x, background_y + GUI::randomizationOptionsComponent_OscShape_Knobs_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxWidth.setBounds(knob_ForMaxWidth.getBounds());

	button_ForClosingComponent.setBounds(background_x + GUI::randomizationOptionsComponent_OscShape_CloseButton_x, background_y + GUI::randomizationOptionsComponent_OscShape_CloseButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_OscShape::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto toggledOn{ button->getToggleState() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (buttonID.startsWith("component_ToggleButton_AllowOscShape")) {
		auto clickedShapeIndex{ buttonID.fromFirstOccurrenceOf("(", false, false).upToFirstOccurrenceOf(")", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			toggle_ForAllowingOff.setToggleState(false, dontSendNotification);
			toggle_ForAllowingSawtooth.setToggleState(false, dontSendNotification);
			toggle_ForAllowingTriangle.setToggleState(false, dontSendNotification);
			toggle_ForAllowingSawTriMix.setToggleState(false, dontSendNotification);
			toggle_ForAllowingPulse.setToggleState(false, dontSendNotification);
			randomizationOptions->setOscShapeIsTheOnlyAllowedForParam(clickedShapeIndex, paramIndex);
			button->setToggleState(true, dontSendNotification);
		}
		else {
			if (toggledOn)
				randomizationOptions->setOscShapeIsAllowedForParam(clickedShapeIndex, paramIndex);
			else {
				randomizationOptions->setOscShapeIsNotAllowedForParam(clickedShapeIndex, paramIndex);
				if (randomizationOptions->noOscShapeIsAllowedForParam(paramIndex)) {
					button->setToggleState(true, dontSendNotification);
					randomizationOptions->setOscShapeIsAllowedForParam(clickedShapeIndex, paramIndex);
				}
			}
		}
	}
	if (buttonID == ID::button_AllShapesFor_.toString() + paramID) {
		toggle_ForAllowingOff.setToggleState(true, dontSendNotification);
		randomizationOptions->setOscShapeIsAllowedForParam((int)OscWaveShape::off, paramIndex);
		toggle_ForAllowingSawtooth.setToggleState(true, dontSendNotification);
		randomizationOptions->setOscShapeIsAllowedForParam((int)OscWaveShape::sawtooth, paramIndex);
		toggle_ForAllowingTriangle.setToggleState(true, dontSendNotification);
		randomizationOptions->setOscShapeIsAllowedForParam((int)OscWaveShape::triangle, paramIndex);
		toggle_ForAllowingSawTriMix.setToggleState(true, dontSendNotification);
		randomizationOptions->setOscShapeIsAllowedForParam((int)OscWaveShape::sawTriMix, paramIndex);
		toggle_ForAllowingPulse.setToggleState(true, dontSendNotification);
		randomizationOptions->setOscShapeIsAllowedForParam((int)OscWaveShape::pulse, paramIndex);
		knob_ForMinWidth.setValue(0.0, sendNotification);
		randomizationOptions->setMinPulseWidthAllowedForParam((uint8)0, paramIndex);
		knob_ForMaxWidth.setValue(params::maxPulseWidth, sendNotification);
		randomizationOptions->setMaxPulseWidthAllowedForParam(params::maxPulseWidth, paramIndex);
	}
}

void RandomizationOptionsComponent_OscShape::sliderValueChanged(Slider* slider) {
	auto sliderID{ slider->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (sliderID == ID::component_KnobForMinPulseWidthFor_.toString() + paramID) {
		auto newMinWidth{ (uint8)slider->getValue() };
		randomizationOptions->setMinPulseWidthAllowedForParam(newMinWidth, paramIndex);
		auto maxWidth{ randomizationOptions->maxPulseWidthAllowedForParam(paramIndex) };
		if (newMinWidth > maxWidth) {
			knob_ForMaxWidth.setValue((double)newMinWidth, sendNotification);
			randomizationOptions->setMaxPulseWidthAllowedForParam(newMinWidth, paramIndex);
		}
	}
	if (sliderID == ID::component_KnobForMaxPulseWidthFor_.toString() + paramID) {
		auto newMaxWidth{ (uint8)slider->getValue() };
		randomizationOptions->setMaxPulseWidthAllowedForParam(newMaxWidth, paramIndex);
		auto minWidth{ randomizationOptions->minPulseWidthAllowedForParam(paramIndex) };
		if (newMaxWidth < minWidth) {
			knob_ForMinWidth.setValue((double)newMaxWidth, sendNotification);
			randomizationOptions->setMinPulseWidthAllowedForParam(newMaxWidth, paramIndex);
		}
	}
}

void RandomizationOptionsComponent_OscShape::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_OscShape::~RandomizationOptionsComponent_OscShape() {
	knob_ForMaxWidth.removeListener(this);
	knob_ForMinWidth.removeListener(this);
	toggle_ForAllowingPulse.removeListener(this);
	toggle_ForAllowingSawTriMix.removeListener(this);
	toggle_ForAllowingTriangle.removeListener(this);
	toggle_ForAllowingSawtooth.removeListener(this);
	toggle_ForAllowingOff.removeListener(this);
}
