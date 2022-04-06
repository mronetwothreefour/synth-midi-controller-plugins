#include "randomization_ProbablitiesForSeqTrackComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ProbabilitiesForSeqTrackComponent::ProbabilitiesForSeqTrackComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	knob_ForRepeatValueProbability{ unexposedParams },
	valueDisplay_ForRepeatValueProbability{ &knob_ForRepeatValueProbability, IntToPercentageString::get() },
	knob_ForRestProbability{ unexposedParams },
	valueDisplay_ForRestProbability{ &knob_ForRestProbability, IntToPercentageString::get() },
	knob_ForResetProbability{ unexposedParams },
	valueDisplay_ForResetProbability{ &knob_ForResetProbability, IntToPercentageString::get() }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

	knob_ForRepeatValueProbability.setComponentID(ID::component_KnobForRepeatValueProbabilityForSeqTrack.toString() + (String)trackNum);
	knob_ForRepeatValueProbability.setRange(0.0, 100.0, 1.0);
	if (editModeIsSelectedStep)
		knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForSelectedStepInSeqTrack(selectedStep, trackNum));
	else
		knob_ForRepeatValueProbability.setValue((double)randomizationOptions->probabilityOfRepeatValueForAllStepsInSeqTrack(trackNum));
	knob_ForRepeatValueProbability.setMouseDragSensitivity(130);
	if (editModeIsSelectedStep && selectedStep == 1)
		knob_ForRepeatValueProbability.setEnabled(false);
	knob_ForRepeatValueProbability.addListener(this);
	addAndMakeVisible(knob_ForRepeatValueProbability);

	addAndMakeVisible(valueDisplay_ForRepeatValueProbability);
	valueDisplay_ForRepeatValueProbability.setInterceptsMouseClicks(false, false);

	if (trackNum == 1) {
		knob_ForRestProbability.setComponentID(ID::component_KnobForRestProbabilityForSeqTrack1.toString());
		knob_ForRestProbability.setRange(0.0, 100.0, 1.0);
		if (editModeIsSelectedStep)
			knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForSelectedStepInSeqTrack1(selectedStep));
		else
			knob_ForRestProbability.setValue((double)randomizationOptions->probabilityOfRestForAllStepsInSeqTrack1());
		knob_ForRestProbability.setMouseDragSensitivity(130);
		knob_ForRestProbability.addListener(this);
		addAndMakeVisible(knob_ForRestProbability);

		addAndMakeVisible(valueDisplay_ForRestProbability);
		valueDisplay_ForRestProbability.setInterceptsMouseClicks(false, false);
	}

	knob_ForResetProbability.setComponentID(ID::component_KnobForResetProbabilityForSeqTrack.toString() + (String)trackNum);
	knob_ForResetProbability.setRange(0.0, 100.0, 1.0);
	if (editModeIsSelectedStep)
		knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForSelectedStepInSeqTrack(selectedStep, trackNum));
	else
		knob_ForResetProbability.setValue((double)randomizationOptions->probabilityOfResetForAllStepsInSeqTrack(trackNum));
	knob_ForResetProbability.setMouseDragSensitivity(130);
	knob_ForResetProbability.addListener(this);
	addAndMakeVisible(knob_ForResetProbability);

	addAndMakeVisible(valueDisplay_ForResetProbability);
	valueDisplay_ForResetProbability.setInterceptsMouseClicks(false, false);

	generateTooltips();

	auto componentWidth{ trackNum == 1 ? GUI::randomizationProbabilitiesForSeqTrack1Component_w : GUI::randomizationProbabilitiesForSeqTracks2_3_4Component_w };

	setSize(componentWidth, GUI::randomizationProbabilitiesForSeqTrackComponent_h);
}

void ProbabilitiesForSeqTrackComponent::generateTooltips() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

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

void ProbabilitiesForSeqTrackComponent::paint(Graphics& g) {
	auto backgroundImageData{ getBackgroundImageData() };
	auto backgroundImageDataSize{ getBackgroundImageDataSize() };
	if (backgroundImageData != nullptr) {
		MemoryInputStream memInputStream{ backgroundImageData, backgroundImageDataSize, false };
		PNGImageFormat imageFormat;
		auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(backgroundImage, 0, 0);
	}
}

const char* ProbabilitiesForSeqTrackComponent::getBackgroundImageData() {
	if (trackNum == 1)
		return BinaryData::ProbabilityControlsForTrack1_png;
	else
		return BinaryData::ProbabilityControlsForTracks2_3_4_png;
}

size_t ProbabilitiesForSeqTrackComponent::getBackgroundImageDataSize() {
	if (trackNum == 1)
		return BinaryData::ProbabilityControlsForTrack1_pngSize;
	else
		return BinaryData::ProbabilityControlsForTracks2_3_4_pngSize;
}

void ProbabilitiesForSeqTrackComponent::resized() {
}

void ProbabilitiesForSeqTrackComponent::sliderValueChanged(Slider* slider)
{
}

void ProbabilitiesForSeqTrackComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property)
{
}

ProbabilitiesForSeqTrackComponent::~ProbabilitiesForSeqTrackComponent()
{
}
