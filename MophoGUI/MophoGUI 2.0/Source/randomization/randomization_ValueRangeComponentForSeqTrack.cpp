#include "randomization_ValueRangeComponentForSeqTrack.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ValueRangeComponentForSeqTrack::ValueRangeComponentForSeqTrack(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	knob_ForMinStepValue{ unexposedParams },
	valueDisplay_ForMinStepValue{ &knob_ForMinStepValue, IntToPlainValueString::get() },
	knob_ForMaxStepValue{ unexposedParams },
	valueDisplay_ForMaxStepValue{ &knob_ForMaxStepValue, IntToPlainValueString::get() }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };

	knob_ForMinStepValue.setComponentID(ID::component_KnobForMinRandomValueFor_.toString() + "SeqTrack" + (String)trackNum);
	knob_ForMinStepValue.setRange(0.0, (double)params::maxValueForSeqTrackStep, 1.0);
	knob_ForMinStepValue.setDoubleClickReturnValue(true, 0.0);
	if (editModeIsSelectedStep)
		knob_ForMinStepValue.setValue((double)randomizationOptions->minValueAllowedForParam(paramIndex));
	else
		knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForAllStepsInSeqTrack(trackNum));
	knob_ForMinStepValue.setMouseDragSensitivity(142);
	knob_ForMinStepValue.addListener(this);
	addAndMakeVisible(knob_ForMinStepValue);

	addAndMakeVisible(valueDisplay_ForMinStepValue);
	valueDisplay_ForMinStepValue.setInterceptsMouseClicks(false, false);

	knob_ForMaxStepValue.setComponentID(ID::component_KnobForMaxRandomValueFor_.toString() + "SeqTrack" + (String)trackNum);
	knob_ForMaxStepValue.setRange(0.0, (double)params::maxValueForSeqTrackStep, 1.0);
	knob_ForMaxStepValue.setDoubleClickReturnValue(true, (double)params::maxValueForSeqTrackStep);
	if (editModeIsSelectedStep)
		knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueAllowedForParam(paramIndex));
	else
		knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum));
	knob_ForMaxStepValue.setMouseDragSensitivity(142);
	knob_ForMaxStepValue.addListener(this);
	addAndMakeVisible(knob_ForMaxStepValue);

	addAndMakeVisible(valueDisplay_ForMaxStepValue);
	valueDisplay_ForMaxStepValue.setInterceptsMouseClicks(false, false);

	generateTooltips();

	setSize(GUI::randomizationValueRangeComponentForSeqTrack_w, GUI::randomizationValueRangeComponentForSeqTrack_h);
}

void ValueRangeComponentForSeqTrack::generateTooltips() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };

		String minValueKnobTooltip{ "" };
		if (editModeIsSelectedStep) {
			minValueKnobTooltip += "Sets the minimum value that can be\n";
			minValueKnobTooltip += "generated for the selected step\n";
			minValueKnobTooltip += "in track " + (String)trackNum + " (if the track destination\n";
			minValueKnobTooltip += "is not an oscillator pitch).\n";
			minValueKnobTooltip += "Range: 0 to 125.";
		}
		else {
			minValueKnobTooltip += "Sets the minimum value that can\n";
			minValueKnobTooltip += "be generated for all steps in\n";
			minValueKnobTooltip += "track " + (String)trackNum + " (if the track destination\n";
			minValueKnobTooltip += "is not an oscillator pitch).\n";
			minValueKnobTooltip += "Range: 0 to 125.";
		}
		knob_ForMinStepValue.setTooltip(minValueKnobTooltip);

		String maxValueKnobTooltip{ "" };
		if (editModeIsSelectedStep) {
			maxValueKnobTooltip += "Sets the maximum value that can be\n";
			maxValueKnobTooltip += "generated for the selected step\n";
			maxValueKnobTooltip += "in track " + (String)trackNum + " (if the track destination\n";
			maxValueKnobTooltip += "is not an oscillator pitch).\n";
			maxValueKnobTooltip += "Range: 0 to 125.";
		}
		else {
			maxValueKnobTooltip += "Sets the maximum value that can\n";
			maxValueKnobTooltip += "be generated for all steps in\n";
			maxValueKnobTooltip += "track " + (String)trackNum + " (if the track destination\n";
			maxValueKnobTooltip += "is not an oscillator pitch).\n";
			maxValueKnobTooltip += "Range: 0 to 125.";
		}
		knob_ForMaxStepValue.setTooltip(maxValueKnobTooltip);
	}
}

void ValueRangeComponentForSeqTrack::resized() {
	knob_ForMinStepValue.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinStepValue.setBounds(knob_ForMinStepValue.getBounds());
	knob_ForMaxStepValue.setBounds(60, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxStepValue.setBounds(knob_ForMaxStepValue.getBounds());
}

void ValueRangeComponentForSeqTrack::sliderValueChanged(Slider* slider) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };
	if (slider->getComponentID() == ID::component_KnobForMinRandomValueFor_.toString() + "SeqTrack" + (String)trackNum) {
		auto newMinValue{ (uint8)slider->getValue() };
		if (editModeIsSelectedStep)
			randomizationOptions->setMinValueAllowedForParam(newMinValue, paramIndex);
		else
			randomizationOptions->setMinValueForAllStepsInSeqTrack(newMinValue, trackNum);
		auto maxValue{ editModeIsSelectedStep ? randomizationOptions->maxValueAllowedForParam(paramIndex) :
												randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum) };
		if (newMinValue > maxValue) {
			knob_ForMaxStepValue.setValue((double)newMinValue, sendNotification);
			if (editModeIsSelectedStep)
				randomizationOptions->setMaxValueAllowedForParam(newMinValue, paramIndex);
			else
				randomizationOptions->setMaxValueForAllStepsInSeqTrack(newMinValue, trackNum);
		}
	}
	if (slider->getComponentID() == ID::component_KnobForMaxRandomValueFor_.toString() + "SeqTrack" + (String)trackNum) {
		auto newMaxValue{ (uint8)slider->getValue() };
		if (editModeIsSelectedStep)
			randomizationOptions->setMaxValueAllowedForParam(newMaxValue, paramIndex);
		else
			randomizationOptions->setMaxValueForAllStepsInSeqTrack(newMaxValue, trackNum);
		auto minValue{ editModeIsSelectedStep ? randomizationOptions->minValueAllowedForParam(paramIndex) :
												randomizationOptions->minValueForAllStepsInSeqTrack(trackNum) };
		if (newMaxValue < minValue) {
			knob_ForMinStepValue.setValue((double)newMaxValue, sendNotification);
			if (editModeIsSelectedStep)
				randomizationOptions->setMinValueAllowedForParam(newMaxValue, paramIndex);
			else
				randomizationOptions->setMinValueForAllStepsInSeqTrack(newMaxValue, trackNum);
		}
	}
	auto trackDestinationIsNotAnOscPitchParameter{ !randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum) };
	if (trackDestinationIsNotAnOscPitchParameter) {
		if (editModeIsSelectedStep) {
			if (randomizationOptions->minValueAllowedForParam(paramIndex) == randomizationOptions->maxValueAllowedForParam(paramIndex)) {
				randomizationOptions->setValueIsOnlyOneAllowedForParam(randomizationOptions->minValueAllowedForParam(paramIndex), paramIndex);
			}
			else
				randomizationOptions->setMoreThanOneValueIsAllowedForParam(paramIndex);
		}
		else {
			if (randomizationOptions->minValueForAllStepsInSeqTrack(trackNum) == randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum)) {
				randomizationOptions->setValueIsOnlyOneAllowedForAllStepsInSeqTrack(randomizationOptions->minValueAllowedForParam(paramIndex), trackNum);
			}
			else
				randomizationOptions->setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
		}
	}
}

void ValueRangeComponentForSeqTrack::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == "editModeIsSelectedStepForSeqTrack" + (String)trackNum || 
		propertyID.toString() == "stepSelectedForEditingInSeqTrack" + (String)trackNum) 
	{
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
		if (editModeIsSelectedStep) {
			auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
			auto& info{ InfoForExposedParameters::get() };
			auto paramIndex{ info.indexForParamID(paramID) };
			knob_ForMinStepValue.setValue((double)randomizationOptions->minValueAllowedForParam(paramIndex), sendNotification);
			knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueAllowedForParam(paramIndex), sendNotification);
		}
		else {
			knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForAllStepsInSeqTrack(trackNum), sendNotification);
			knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum), sendNotification);
		}
		generateTooltips();
	}
}

ValueRangeComponentForSeqTrack::~ValueRangeComponentForSeqTrack() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
	knob_ForMinStepValue.removeListener(this);
	knob_ForMaxStepValue.removeListener(this);
}
