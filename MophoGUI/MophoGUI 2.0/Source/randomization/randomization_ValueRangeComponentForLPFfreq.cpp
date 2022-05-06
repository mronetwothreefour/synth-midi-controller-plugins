#include "randomization_ValueRangeComponentForLPFfreq.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ValueRangeComponentForLPFfreq::ValueRangeComponentForLPFfreq(UnexposedParameters* unexposedParams) :
	paramIndex{ InfoForExposedParameters::get().indexForParamID(ID::lpfFreq.toString()) },
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
		knobTooltip += "Sets the minimum LPF cutoff frequency\n";
		knobTooltip += "that can be randomly generated.";
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
		knobTooltip += "Sets the maximum LPF cutoff frequency\n";
		knobTooltip += "that can be randomly generated.";
		knob_ForMaxValue.setTooltip(knobTooltip);
	}
	addAndMakeVisible(knob_ForMaxValue);

	addAndMakeVisible(valueDisplay_ForMaxValue);
	valueDisplay_ForMaxValue.setInterceptsMouseClicks(false, false);

	setSize(GUI::randomizationValueRangeComponentForLPFfreq_w, GUI::knob_diameter);
}

void ValueRangeComponentForLPFfreq::resized() {
	knob_ForMinValue.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinValue.setBounds(knob_ForMinValue.getBounds());
	knob_ForMaxValue.setBounds(GUI::randomizationLPFOptions_HorizKnobSpacing, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxValue.setBounds(knob_ForMaxValue.getBounds());
}

void ValueRangeComponentForLPFfreq::sliderValueChanged(Slider* slider) {
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
	randomizationOptions->checkIfOnlyOneValueIsAllowedForLPFfreqParam();
}

ValueRangeComponentForLPFfreq::~ValueRangeComponentForLPFfreq() {
	knob_ForMinValue.removeListener(this);
	knob_ForMaxValue.removeListener(this);
}
