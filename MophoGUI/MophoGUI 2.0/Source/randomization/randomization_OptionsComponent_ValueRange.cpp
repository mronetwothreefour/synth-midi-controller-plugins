#include "randomization_OptionsComponent_ValueRange.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_ValueRange::RandomizationOptionsComponent_ValueRange(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	knob_ForMinValue{ unexposedParams },
	valueDisplay_ForMinValue{ &knob_ForMinValue, InfoForExposedParameters::get().converterFor(paramIndex) },
	knob_ForMaxValue{ unexposedParams },
	valueDisplay_ForMaxValue{ &knob_ForMaxValue, InfoForExposedParameters::get().converterFor(paramIndex) }
{
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto paramID{ info.IDfor(paramIndex) };

	knob_ForMinValue.setComponentID(ID::component_KnobForMinRandomValueFor_.toString() + paramID.toString());
	knob_ForMinValue.setRange(0.0, (double)info.maxValueFor(paramIndex), 1.0);
	knob_ForMinValue.setDoubleClickReturnValue(true, 0.0);
	knob_ForMinValue.setValue((double)randomizationOptions->minValueAllowedForParam(paramIndex));
	knob_ForMinValue.setMouseDragSensitivity(80 + info.numberOfStepsFor(paramIndex) / 2);
	knob_ForMinValue.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the minimum value that\n";
		knobTooltip += "can be randomly generated for\n";
		knobTooltip += info.exposedNameFor(paramIndex);
		knob_ForMinValue.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMinValue);

	addAndMakeVisible(valueDisplay_ForMinValue);
	valueDisplay_ForMinValue.setInterceptsMouseClicks(false, false);

	knob_ForMaxValue.setComponentID(ID::component_KnobForMaxRandomValueFor_.toString() + paramID.toString());
	knob_ForMaxValue.setRange(0.0, (double)info.maxValueFor(paramIndex), 1.0);
	knob_ForMaxValue.setDoubleClickReturnValue(true, (double)info.maxValueFor(paramIndex));
	knob_ForMaxValue.setValue((double)randomizationOptions->maxValueAllowedForParam(paramIndex));
	knob_ForMaxValue.setMouseDragSensitivity(80 + info.numberOfStepsFor(paramIndex) / 2);
	knob_ForMaxValue.addListener(this);
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Sets the maximum value that\n";
		knobTooltip += "can be randomly generated for\n";
		knobTooltip += info.exposedNameFor(paramIndex);
		knob_ForMaxValue.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMaxValue);

	addAndMakeVisible(valueDisplay_ForMaxValue);
	valueDisplay_ForMaxValue.setInterceptsMouseClicks(false, false);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	if (controlCenter.x < 1200)
		background_x = controlCenter.x + GUI::knob_diameter;
	else
		background_x = controlCenter.x - GUI::knob_diameter - GUI::randomizationOptionsComponent_ValueRange_w;
	if (controlCenter.y < 450)
		background_y = controlCenter.y - GUI::knob_diameter / 2;
	else
		background_y = controlCenter.y - GUI::randomizationOptionsComponent_ValueRange_h +GUI::knob_diameter / 2;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_ValueRange::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsValueRangeBackground_png, BinaryData::RandomizationOptionsValueRangeBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}

void RandomizationOptionsComponent_ValueRange::resized() {
	knob_ForMinValue.setBounds(background_x + GUI::randomizationOptionsComponent_ValueRange_MinKnob_x, background_y + GUI::randomizationOptionsComponent_ValueRange_Knobs_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinValue.setBounds(knob_ForMinValue.getBounds());
	knob_ForMaxValue.setBounds(background_x + GUI::randomizationOptionsComponent_ValueRange_MaxKnob_x, background_y + GUI::randomizationOptionsComponent_ValueRange_Knobs_y, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxValue.setBounds(knob_ForMaxValue.getBounds());
	button_ForClosingComponent.setBounds(background_x + GUI::randomizationOptionsComponent_ValueRange_CloseButton_x, background_y + GUI::randomizationOptionsComponent_ValueRange_CloseButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_ValueRange::sliderValueChanged(Slider* slider) {
	auto& info{ InfoForExposedParameters::get() };
	auto sliderID{ slider->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto paramID{ info.IDfor(paramIndex) };

	if (sliderID == ID::component_KnobForMinRandomValueFor_.toString() + paramID.toString()) {
		auto newMinValue{ (uint8)slider->getValue() };
		randomizationOptions->setMinValueAllowedForParam(newMinValue, paramIndex);
		auto maxValue{ randomizationOptions->maxValueAllowedForParam(paramIndex) };
		if (newMinValue > maxValue) {
			knob_ForMaxValue.setValue((double)newMinValue, sendNotification);
			randomizationOptions->setMaxValueAllowedForParam(newMinValue, paramIndex);
		}
	}
	if (sliderID == ID::component_KnobForMaxRandomValueFor_.toString() + paramID.toString()) {
		auto newMaxValue{ (uint8)slider->getValue() };
		randomizationOptions->setMaxValueAllowedForParam(newMaxValue, paramIndex);
		auto minValue{ randomizationOptions->minValueAllowedForParam(paramIndex) };
		if (newMaxValue < minValue) {
			knob_ForMinValue.setValue((double)newMaxValue, sendNotification);
			randomizationOptions->setMinValueAllowedForParam(newMaxValue, paramIndex);
		}
	}
}

void RandomizationOptionsComponent_ValueRange::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_ValueRange::~RandomizationOptionsComponent_ValueRange() {
	knob_ForMinValue.removeListener(this);
	knob_ForMaxValue.removeListener(this);
}
