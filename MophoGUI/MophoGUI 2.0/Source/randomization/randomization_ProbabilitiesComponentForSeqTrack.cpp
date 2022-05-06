#include "randomization_ProbabilitiesComponentForSeqTrack.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ProbabilitiesComponentForSeqTrack::ProbabilitiesComponentForSeqTrack(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	knob_ForRestProbability{ unexposedParams },
	valueDisplay_ForRestProbability{ &knob_ForRestProbability, IntToPercentageString::get() },
	knob_ForRepeatValueProbability{ unexposedParams },
	valueDisplay_ForRepeatValueProbability{ &knob_ForRepeatValueProbability, IntToPercentageString::get() },
	knob_ForResetProbability{ unexposedParams },
	valueDisplay_ForResetProbability{ &knob_ForResetProbability, IntToPercentageString::get() }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };

	if (trackNum == 1) {
		knob_ForRestProbability.setComponentID(ID::component_KnobForRestProbabilityForSeqTrack1.toString());
		knob_ForRestProbability.setRange(0.0, 100.0, 1.0);
		knob_ForRestProbability.setDoubleClickReturnValue(true, 10.0);
		if (editModeIsSelectedStep)
			knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForParam(paramIndex) * 100.0);
		else
			knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForAllStepsInSeqTrack1() * 100.0);
		knob_ForRestProbability.setMouseDragSensitivity(130);
		knob_ForRestProbability.addListener(this);
		addAndMakeVisible(knob_ForRestProbability);

		addAndMakeVisible(valueDisplay_ForRestProbability);
		valueDisplay_ForRestProbability.setInterceptsMouseClicks(false, false);
	}

	knob_ForRepeatValueProbability.setComponentID(ID::component_KnobForRepeatValueProbabilityForSeqTrack.toString() + (String)trackNum);
	knob_ForRepeatValueProbability.setRange(0.0, 100.0, 1.0);
	knob_ForRepeatValueProbability.setDoubleClickReturnValue(true, 0.0);
	if (editModeIsSelectedStep)
		knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForParam(paramIndex) * 100.0);
	else
		knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForAllStepsInSeqTrack(trackNum) * 100.0);
	knob_ForRepeatValueProbability.setMouseDragSensitivity(130);
	if (editModeIsSelectedStep && selectedStep == 1)
		knob_ForRepeatValueProbability.setEnabled(false);
	knob_ForRepeatValueProbability.addListener(this);
	addAndMakeVisible(knob_ForRepeatValueProbability);

	addAndMakeVisible(valueDisplay_ForRepeatValueProbability);
	valueDisplay_ForRepeatValueProbability.setInterceptsMouseClicks(false, false);

	knob_ForResetProbability.setComponentID(ID::component_KnobForResetProbabilityForSeqTrack.toString() + (String)trackNum);
	knob_ForResetProbability.setRange(0.0, 100.0, 1.0);
	knob_ForResetProbability.setDoubleClickReturnValue(true, 0.0);
	if (editModeIsSelectedStep)
		knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForParam(paramIndex) * 100.0);
	else
		knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForAllStepsInSeqTrack(trackNum) * 100.0);
	knob_ForResetProbability.setMouseDragSensitivity(130);
	knob_ForResetProbability.addListener(this);
	addAndMakeVisible(knob_ForResetProbability);

	addAndMakeVisible(valueDisplay_ForResetProbability);
	valueDisplay_ForResetProbability.setInterceptsMouseClicks(false, false);

	generateTooltips();

	auto componentWidth{ trackNum == 1 ? GUI::randomizationProbabilitiesForSeqTrack1Component_w : GUI::randomizationProbabilitiesForSeqTracks2_3_4Component_w };

	setSize(componentWidth, GUI::randomizationProbabilitiesForSeqTrackComponent_h);
}

void ProbabilitiesComponentForSeqTrack::generateTooltips() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };

		if (trackNum == 1) {
			String restValueKnobTooltip{ "" };
			if (editModeIsSelectedStep) {
				restValueKnobTooltip += "Sets the probability that the selected\n";
				restValueKnobTooltip += "step in track 1 will be a rest.";
			}
			else {
				restValueKnobTooltip += "Sets the probability that any of the\n";
				restValueKnobTooltip += "steps in track 1 will be a rest.";
			}
			knob_ForRestProbability.setTooltip(restValueKnobTooltip);
		}

		String repeatValueKnobTooltip{ "" };
		if (editModeIsSelectedStep) {
			repeatValueKnobTooltip += "Sets the probability that the selected\n";
			repeatValueKnobTooltip += "step in track " + (String)trackNum + " will be assigned the\n";
			repeatValueKnobTooltip += "same value as its preceding step\n";
			repeatValueKnobTooltip += "(this is disabled for step 1).";
		}
		else {
			repeatValueKnobTooltip += "Sets the probability that any of\n";
			repeatValueKnobTooltip += "the steps in track " + (String)trackNum + " will be assigned\n";
			repeatValueKnobTooltip += "the same value as its preceding step\n";
			repeatValueKnobTooltip += "(this does not apply to step 1).";
		}
		knob_ForRepeatValueProbability.setTooltip(repeatValueKnobTooltip);

		String resetValueKnobTooltip{ "" };
		if (editModeIsSelectedStep) {
			resetValueKnobTooltip += "Sets the probability that the selected\n";
			resetValueKnobTooltip += "step in track " + (String)trackNum + " will reset the track.\n";
			resetValueKnobTooltip += "(this is disabled for step 1).";
		}
		else {
			resetValueKnobTooltip += "Sets the probability that any of the\n";
			resetValueKnobTooltip += "steps in track " + (String)trackNum + " will reset the track.\n";
			resetValueKnobTooltip += "(this does not apply to step 1).";
		}
		knob_ForResetProbability.setTooltip(resetValueKnobTooltip);
	}
}

void ProbabilitiesComponentForSeqTrack::paint(Graphics& g) {
	auto backgroundImageData{ getBackgroundImageData() };
	auto backgroundImageDataSize{ getBackgroundImageDataSize() };
	if (backgroundImageData != nullptr) {
		MemoryInputStream memInputStream{ backgroundImageData, backgroundImageDataSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 0, 0);
	}
}

const char* ProbabilitiesComponentForSeqTrack::getBackgroundImageData() {
	if (trackNum == 1)
		return BinaryData::ProbabilityControlsForTrack1_png;
	else
		return BinaryData::ProbabilityControlsForTracks2_3_4_png;
}

size_t ProbabilitiesComponentForSeqTrack::getBackgroundImageDataSize() {
	if (trackNum == 1)
		return BinaryData::ProbabilityControlsForTrack1_pngSize;
	else
		return BinaryData::ProbabilityControlsForTracks2_3_4_pngSize;
}

void ProbabilitiesComponentForSeqTrack::resized() {
	if (trackNum == 1) {
		knob_ForRestProbability.setBounds(0, 0, GUI::knob_diameter, GUI::knob_diameter);
		valueDisplay_ForRestProbability.setBounds(knob_ForRestProbability.getBounds());
	}
	knob_ForRepeatValueProbability.setBounds(trackNum == 1 ? 64 : 9, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForRepeatValueProbability.setBounds(knob_ForRepeatValueProbability.getBounds());
	knob_ForResetProbability.setBounds(trackNum == 1 ? 128 : 77, 0, GUI::knob_diameter, GUI::knob_diameter);
	valueDisplay_ForResetProbability.setBounds(knob_ForResetProbability.getBounds());
}

void ProbabilitiesComponentForSeqTrack::sliderValueChanged(Slider* slider) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };
	auto newValue{ (float)slider->getValue() / 100.0f };

	if (slider->getComponentID() == ID::component_KnobForRestProbabilityForSeqTrack1.toString()) {
		if (editModeIsSelectedStep)
			randomizationOptions->setProbabilityOfRestForParam(newValue, paramIndex);
		else
			randomizationOptions->setProbabilityOfRestForAllStepsInSeqTrack1(newValue);
	}
	if (slider->getComponentID() == ID::component_KnobForRepeatValueProbabilityForSeqTrack.toString() + (String)trackNum) {
		if (editModeIsSelectedStep)
			randomizationOptions->setProbabilityOfRepeatValueForParam(newValue, paramIndex);
		else
			randomizationOptions->setProbabilityOfRepeatForAllStepsInSeqTrack(newValue, trackNum);
	}
	if (slider->getComponentID() == ID::component_KnobForResetProbabilityForSeqTrack.toString() + (String)trackNum) {
		if (editModeIsSelectedStep)
			randomizationOptions->setProbabilityOfResetForParam(newValue, paramIndex);
		else
			randomizationOptions->setProbabilityOfResetForAllStepsInSeqTrack(newValue, trackNum);
	}
}

void ProbabilitiesComponentForSeqTrack::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
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
			if (trackNum == 1)
				knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForParam(paramIndex) * 100.0, sendNotification);
			knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForParam(paramIndex) * 100.0, sendNotification);
			knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForParam(paramIndex) * 100.0, sendNotification);
			if (selectedStep == 1) {
				knob_ForRepeatValueProbability.setEnabled(false);
				knob_ForResetProbability.setEnabled(false);
			}
			else {
				knob_ForRepeatValueProbability.setEnabled(true);
				knob_ForResetProbability.setEnabled(true);
			}
		}
		else {
			if (trackNum == 1)
				knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForAllStepsInSeqTrack1() * 100.0, sendNotification);
			knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForAllStepsInSeqTrack(trackNum) * 100.0, sendNotification);
			knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForAllStepsInSeqTrack(trackNum) * 100.0, sendNotification);
			knob_ForRepeatValueProbability.setEnabled(true);
			knob_ForResetProbability.setEnabled(true);
		}
		generateTooltips();
	}
}

ProbabilitiesComponentForSeqTrack::~ProbabilitiesComponentForSeqTrack() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
	if (trackNum == 1)
		knob_ForRestProbability.removeListener(this);
	knob_ForRepeatValueProbability.removeListener(this);
	knob_ForResetProbability.removeListener(this);
}
