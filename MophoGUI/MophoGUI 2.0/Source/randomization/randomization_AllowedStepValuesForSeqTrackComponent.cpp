#include "randomization_AllowedStepValuesForSeqTrackComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



AllowedStepValuesForSeqTrackComponent::AllowedStepValuesForSeqTrackComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	knob_ForMinStepValue{ unexposedParams },
	valueDisplay_ForMinStepValue{ &knob_ForMinStepValue, IntToPlainValueString::get() },
	knob_ForMaxStepValue{ unexposedParams },
	valueDisplay_ForMaxStepValue{ &knob_ForMaxStepValue, IntToPlainValueString::get() }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackAllowedStepValuesTree(this);
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

	knob_ForMinStepValue.setComponentID(ID::component_KnobForMinStepValueForSeqTrack.toString() + (String)trackNum);
	knob_ForMinStepValue.setRange(0.0, (double)params::maxValueForSeqTrackStep, 1.0);
	if (editModeIsSelectedStep)
		knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForSelectedStepInSeqTrack(selectedStep, trackNum));
	else
		knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForAllStepsInSeqTrack(trackNum));
	knob_ForMinStepValue.setMouseDragSensitivity(142);
	knob_ForMinStepValue.addListener(this);
	addAndMakeVisible(knob_ForMinStepValue);

	addAndMakeVisible(valueDisplay_ForMinStepValue);
	valueDisplay_ForMinStepValue.setInterceptsMouseClicks(false, false);

	knob_ForMaxStepValue.setComponentID(ID::component_KnobForMaxStepValueForSeqTrack.toString() + (String)trackNum);
	knob_ForMaxStepValue.setRange(0.0, (double)params::maxValueForSeqTrackStep, 1.0);
	if (editModeIsSelectedStep)
		knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForSelectedStepInSeqTrack(selectedStep, trackNum));
	else
		knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum));
	knob_ForMaxStepValue.setMouseDragSensitivity(142);
	knob_ForMaxStepValue.addListener(this);
	addAndMakeVisible(knob_ForMaxStepValue);

	addAndMakeVisible(valueDisplay_ForMaxStepValue);
	valueDisplay_ForMaxStepValue.setInterceptsMouseClicks(false, false);

	generateTooltips();

	setSize(GUI::randomizationAllowedStepValuesForSeqTrackComponent_w, GUI::randomizationAllowedStepValuesForSeqTrackComponent_h);
}

void AllowedStepValuesForSeqTrackComponent::generateTooltips() {
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
			minValueKnobTooltip += "Sets the minimum value that\n";
			minValueKnobTooltip += "can be generated for all steps\n";
			minValueKnobTooltip += "in track " + (String)trackNum + " (if the track destination\n";
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
			maxValueKnobTooltip += "Sets the maximum value that\n";
			maxValueKnobTooltip += "can be generated for all steps\n";
			maxValueKnobTooltip += "in track " + (String)trackNum + " (if the track destination\n";
			maxValueKnobTooltip += "is not an oscillator pitch).\n";
			maxValueKnobTooltip += "Range: 0 to 125.";
		}
		knob_ForMaxStepValue.setTooltip(maxValueKnobTooltip);
	}
}

void AllowedStepValuesForSeqTrackComponent::resized() {
	knob_ForMinStepValue.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMinStepValue.setBounds(knob_ForMinStepValue.getBounds());
	knob_ForMaxStepValue.setBounds(GUI::randomizationSeqTrackOptions_HorizKnobSpacing, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForMaxStepValue.setBounds(knob_ForMaxStepValue.getBounds());
}

void AllowedStepValuesForSeqTrackComponent::sliderValueChanged(Slider* slider) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	if (slider->getComponentID() == ID::component_KnobForMinStepValueForSeqTrack.toString() + (String)trackNum) {
		auto newMinValue{ (uint8)slider->getValue() };
		if (editModeIsSelectedStep)
			randomizationOptions->setMinValueForSelectedStepInSeqTrack(newMinValue, selectedStep, trackNum);
		else
			randomizationOptions->setMinValueForAllStepsInSeqTrack(newMinValue, trackNum);
		auto maxValue{ editModeIsSelectedStep ? randomizationOptions->maxValueForSelectedStepInSeqTrack(selectedStep, trackNum) :
												randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum) };
		if (newMinValue > maxValue) {
			knob_ForMaxStepValue.setValue((double)newMinValue, sendNotification);
			if (editModeIsSelectedStep)
				randomizationOptions->setMaxValueForSelectedStepInSeqTrack(newMinValue, selectedStep, trackNum);
			else
				randomizationOptions->setMaxValueForAllStepsInSeqTrack(newMinValue, trackNum);
		}
	}
	if (slider->getComponentID() == ID::component_KnobForMaxStepValueForSeqTrack.toString() + (String)trackNum) {
		auto newMaxValue{ (uint8)slider->getValue() };
		if (editModeIsSelectedStep)
			randomizationOptions->setMaxValueForSelectedStepInSeqTrack(newMaxValue, selectedStep, trackNum);
		else
			randomizationOptions->setMaxValueForAllStepsInSeqTrack(newMaxValue, trackNum);
		auto minValue{ editModeIsSelectedStep ? randomizationOptions->minValueForSelectedStepInSeqTrack(selectedStep, trackNum) :
												randomizationOptions->minValueForAllStepsInSeqTrack(trackNum) };
		if (newMaxValue > minValue) {
			knob_ForMinStepValue.setValue((double)newMaxValue, sendNotification);
			if (editModeIsSelectedStep)
				randomizationOptions->setMinValueForSelectedStepInSeqTrack(newMaxValue, selectedStep, trackNum);
			else
				randomizationOptions->setMinValueForAllStepsInSeqTrack(newMaxValue, trackNum);
		}
	}
}

void AllowedStepValuesForSeqTrackComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == "editModeIsSelectedStepForSeqTrack" + (String)trackNum || 
		propertyID.toString() == "stepSelectedForEditingInSeqTrack" + (String)trackNum) 
	{
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
		if (editModeIsSelectedStep) {
			knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForSelectedStepInSeqTrack(selectedStep, trackNum), sendNotification);
			knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForSelectedStepInSeqTrack(selectedStep, trackNum), sendNotification);
		}
		else {
			knob_ForMinStepValue.setValue((double)randomizationOptions->minValueForAllStepsInSeqTrack(trackNum), sendNotification);
			knob_ForMaxStepValue.setValue((double)randomizationOptions->maxValueForAllStepsInSeqTrack(trackNum), sendNotification);
		}
		generateTooltips();
	}
}

AllowedStepValuesForSeqTrackComponent::~AllowedStepValuesForSeqTrackComponent() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackAllowedStepValuesTree(this);
	knob_ForMinStepValue.removeListener(this);
	knob_ForMaxStepValue.removeListener(this);
}
