#include "rndm_0_comp_KnobForSeqTrackProbability.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

KnobForSeqTrackProbability::KnobForSeqTrackProbability(
	KnobType knobType, Track track, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ nullptr },
	knobType{ knobType },
	track{ track },
	randomization{ randomization },
	textEditor{ knobType, track, randomization, unexposedParams->getTooltipsOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	if (knobType == KnobType::rest)
		jassert(track == Track::one);

	targetStepForSeqTrackValue = randomization->getTargetStepForSeqTrackValue(track);
	targetStepForSeqTrackValue.addListener(this);

	setRange(0.0, 1.0, 0.01);
	setMouseDragSensitivity(130);

	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	if (knobType == KnobType::reset) {
		seqTrackProbValue = randomization->getProbabilityOfResetForSeqTrackStepValue(track, targetStep);
		if (targetStep == Step::one) {
			setValue(0.0, dontSendNotification);
			setEnabled(false);
		}
		else
			setValue((double)randomization->probabilityOfResetForSeqTrackStep(track, targetStep), dontSendNotification);
	}
	else {
		seqTrackProbValue = randomization->getProbabilityOfRestForSeqTrack_1_StepValue(targetStep);
		setValue((double)randomization->probabilityOfRestForSeqTrack_1_Step(targetStep), dontSendNotification);
	}
	seqTrackProbValue.addListener(this);

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	updateTooltip();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobForSeqTrackProbability::updateTooltip() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	String tip{ "" };
	switch (knobType)
	{
	case KnobType::reset:
		if (targetStep == Step::all) {
			tip += "Sets the probability that any of the\n";
			tip += "steps in track " + String((int)track) + " will reset the track.\n";
			tip += "(this does not apply to step 1).\n";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track " + String((int)track) + " will reset the track.\n";
			tip += "(this is disabled for step 1).\n";
		}
		break;
	case KnobType::rest:
		if (targetStep == Step::all) {
			tip += "Sets the probability that any of the\n";
			tip += "steps in track 1 will be a rest.\n";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track 1 will be a rest.\n";
		}
		break;
	default:
		break;
	}
	if (track == Track::one) {
		tip += "The sum of the probabilities\n";
		tip += "cannot exceed 100 percent.";
	}
	setTooltip(tip);
}

void KnobForSeqTrackProbability::mouseDoubleClick(const MouseEvent& /*event*/) {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	if (knobType == KnobType::rest || targetStep != Step::one)
		textEditor.showEditor();
}

void KnobForSeqTrackProbability::valueChanged() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	auto newProbability{ (float)getValue() };
	switch (knobType)
	{
	case KnobType::reset: {
		if (track == Track::one && targetStep != Step::one) {
			auto probabilityOfRest{ randomization->probabilityOfRestForSeqTrack_1_Step(targetStep) };
			if (probabilityOfRest + newProbability > 1.0000f) {
				newProbability = 1.0000f - probabilityOfRest;
				setValue(newProbability, dontSendNotification);
			}
		}
		if (targetStep == Step::all)
			randomization->setProbabilityOfResetForAllSeqTrackSteps(newProbability, track);
		else
			randomization->setProbabilityOfResetForSeqTrackStep(newProbability, track, targetStep);
		break;
	}
	case KnobType::rest: {
		auto probabilityOfReset{ randomization->probabilityOfResetForSeqTrackStep(track, targetStep) };
		if (probabilityOfReset + newProbability > 1.0000f) {
			newProbability = 1.0000f - probabilityOfReset;
			setValue(newProbability, dontSendNotification);
		}
		if (targetStep == Step::all)
			randomization->setProbabilityOfRestForAllSeqTrack_1_Steps(newProbability);
		else
			randomization->setProbabilityOfRestForSeqTrack_1_Step(newProbability, targetStep);
		break;
	}
	default:
		break;
	}
}

void KnobForSeqTrackProbability::valueChanged(Value& value) {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	if (value.refersToSameSourceAs(targetStepForSeqTrackValue)) {
		if (knobType == KnobType::reset)
			seqTrackProbValue = randomization->getProbabilityOfResetForSeqTrackStepValue(track, targetStep);
		else
			seqTrackProbValue = randomization->getProbabilityOfRestForSeqTrack_1_StepValue(targetStep);
	}
	if (knobType == KnobType::reset) {
		if (targetStep == Step::one) {
			setValue(0.0, dontSendNotification);
			setEnabled(false);
		}
		else {
			setEnabled(true);
			setValue((double)randomization->probabilityOfResetForSeqTrackStep(track, targetStep), dontSendNotification);
		}
	}
	else {
		setValue((double)randomization->probabilityOfRestForSeqTrack_1_Step(targetStep), dontSendNotification);
	}
	updateTooltip();
}

KnobForSeqTrackProbability::~KnobForSeqTrackProbability() {
	targetStepForSeqTrackValue.removeListener(this);
	seqTrackProbValue.removeListener(this);
}
