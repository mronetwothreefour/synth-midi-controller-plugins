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
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	if (knobType == KnobType::rest)
		jassert(track == Track::one);

	targetStepForSeqTrackValue = randomization->getTargetStepForSeqTrackValue(track);
	targetStepForSeqTrackValue.addListener(this);

	setRange(0.0, 1.0, 0.01);
	setMouseDragSensitivity(130);

	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	switch (knobType)
	{
	case KnobType::rest:
		setDoubleClickReturnValue(true, 10.0);
		setValue((double)randomization->probabilityOfRestForSeqTrack_1_Step(targetStep));
		break;
	case KnobType::duplicate:
		if (targetStep == Step::one) {
			setValue(0.0);
			setEnabled(false);
		}
		else {
			setValue((double)randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep));
			setDoubleClickReturnValue(true, 0.0);
		}
		break;
	case KnobType::reset:
		if (targetStep == Step::one) {
			setValue(0.0);
			setEnabled(false);
		}
		else {
			setValue((double)randomization->probabilityOfResetForSeqTrackStep(track, targetStep));
			setDoubleClickReturnValue(true, 0.0);
		}
		break;
	default:
		break;
	}

	updateTooltip();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
}

void KnobForSeqTrackProbability::updateTooltip() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	String tip{ "" };
	switch (knobType)
	{
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
	case KnobType::duplicate:
		if (targetStep == Step::all) {
			tip += "Sets the probability that any of the\n";
			tip += "steps in track " + String((int)track) + " will be assigned the\n";
			tip += "same value as the step preceding it.\n";
			tip += "(this does not apply to step 1).\n";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track " + String((int)track) + " will be assigned the\n";
			tip += "same value as the step preceding it.\n";
			tip += "(this is disabled for step 1).\n";
		}
		break;
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
	default:
		break;
	}
	tip += "The sum of all the probabilities\n";
	tip += "cannot exceed 100 percent.";
	setTooltip(tip);
}

void KnobForSeqTrackProbability::valueChanged() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	auto newValue{ (float)getValue() };
	switch (knobType)
	{
	case KnobType::rest: {
		auto sumOfOtherProbabilities{ randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep) +
			randomization->probabilityOfResetForSeqTrackStep(track, targetStep)
		};
		if (sumOfOtherProbabilities + newValue > 1.0000f) {
			setValue(1.0000f - sumOfOtherProbabilities, dontSendNotification);
			randomization->setProbabilityOfRestForSeqTrack_1_Step(1.0000f - sumOfOtherProbabilities, targetStep);
		}
		else
			randomization->setProbabilityOfRestForSeqTrack_1_Step(newValue, targetStep);
		break;
	}
	case KnobType::duplicate: {
		auto sumOfOtherProbabilities{ track == Track::one ? randomization->probabilityOfRestForSeqTrack_1_Step(targetStep) : 0.0f };
		sumOfOtherProbabilities += randomization->probabilityOfResetForSeqTrackStep(track, targetStep);
		if (sumOfOtherProbabilities + newValue > 1.0000f) {
			setValue(1.0000f - sumOfOtherProbabilities, dontSendNotification);
			randomization->setProbabilityOfDuplicateForSeqTrackStep(1.0000f - sumOfOtherProbabilities, track, targetStep);
		}
		else
			randomization->setProbabilityOfDuplicateForSeqTrackStep(newValue, track, targetStep);
		break;
	}
	case KnobType::reset: {
		auto sumOfOtherProbabilities{ track == Track::one ? randomization->probabilityOfRestForSeqTrack_1_Step(targetStep) : 0.0f };
		sumOfOtherProbabilities += randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep);
		if (sumOfOtherProbabilities + newValue > 1.0000f) {
			setValue(1.0000f - sumOfOtherProbabilities, dontSendNotification);
			randomization->setProbabilityOfResetForSeqTrackStep(1.0000f - sumOfOtherProbabilities, track, targetStep);
		}
		else
			randomization->setProbabilityOfResetForSeqTrackStep(newValue, track, targetStep);
		break;
	}
	default:
		break;
	}
}

void KnobForSeqTrackProbability::valueChanged(Value& /*value*/)
{
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	switch (knobType)
	{
	case KnobType::rest:
		setValue((double)randomization->probabilityOfRestForSeqTrack_1_Step(targetStep), sendNotification);
		break;
	case KnobType::duplicate:
		if (targetStep == Step::one) {
			setValue(0.0, dontSendNotification);
			setEnabled(false);
		}
		else {
			setEnabled(true);
			setValue((double)randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep), sendNotification);
		}
		break;
	case KnobType::reset:
		if (targetStep == Step::one) {
			setValue(0.0, dontSendNotification);
			setEnabled(false);
		}
		else {
			setEnabled(true);
			setValue((double)randomization->probabilityOfResetForSeqTrackStep(track, targetStep), sendNotification);
		}
		break;
	default:
		break;
	}
	updateTooltip();
}

KnobForSeqTrackProbability::~KnobForSeqTrackProbability() {
	targetStepForSeqTrackValue.removeListener(this);
}
