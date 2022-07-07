#include "rndm_0_comp_KnobForSeqTrackProbability.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



KnobForSeqTrackProbability::KnobForSeqTrackProbability(
	KnobType knobType, Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ &exposedParams->undoManager },
	knobType{ knobType },
	track{ track },
	randomization{ exposedParams->randomization.get() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	if (knobType == KnobType::rest)
		jassert(track == Track::one);
	randomization->addListenerToSeqTrackTree(this, track);

	setRange(0.0, 100.0, 1.0);
	setMouseDragSensitivity(130);

	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	switch (knobType)
	{
	case KnobType::rest:
		setDoubleClickReturnValue(true, 10.0);
		setValue((double)randomization->probabilityOfRestForSeqTrack_1_Step(targetStep));
		break;
	case KnobType::duplicate:
		setValue((double)randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep));
		setDoubleClickReturnValue(true, 0.0);
		break;
	case KnobType::reset:
		setValue((double)randomization->probabilityOfResetForSeqTrackStep(track, targetStep));
		setDoubleClickReturnValue(true, 0.0);
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
			tip += "steps in track 1 will be a rest.";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track 1 will be a rest.";
		}
		break;
	case KnobType::duplicate:
		if (targetStep == Step::all) {
			tip += "Sets the probability that any of the\n";
			tip += "steps in track " + String((int)track) + " will be assigned the\n";
			tip += "same value as the step preceding it.\n";
			tip += "(this does not apply to step 1).";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track " + String((int)track) + " will be assigned the\n";
			tip += "same value as the step preceding it.\n";
			tip += "(this is disabled for step 1).";
		}
		break;
	case KnobType::reset:
		if (targetStep == Step::all) {
			tip += "Sets the probability that any of the\n";
			tip += "steps in track " + String((int)track) + " will reset the track.\n";
			tip += "(this does not apply to step 1).";
		}
		else {
			tip += "Sets the probability that the target\n";
			tip += "step in track " + String((int)track) + " will reset the track.\n";
			tip += "(this is disabled for step 1).";
		}
		break;
	default:
		break;
	}
}

void KnobForSeqTrackProbability::valueChanged() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	auto newValue{ (float)getValue() / 100.0f };
	switch (knobType)
	{
	case KnobType::rest:
		randomization->setProbabilityOfRestForSeqTrack_1_Step(newValue, targetStep);
		break;
	case KnobType::duplicate:
		randomization->setProbabilityOfDuplicateForSeqTrackStep(newValue, track, targetStep);
		break;
	case KnobType::reset:
		randomization->setProbabilityOfResetForSeqTrackStep(newValue, track, targetStep);
		break;
	default:
		break;
	}
}

void KnobForSeqTrackProbability::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::rndm_SeqTrackTargetStep) {
		auto targetStep{ randomization->targetStepForSeqTrack(track) };
		switch (knobType)
		{
		case KnobType::rest:
			setValue(randomization->probabilityOfRestForSeqTrack_1_Step(targetStep) * 100.0, sendNotification);
			break;
		case KnobType::duplicate:
			if (targetStep == Step::one) {
				setValue(0.0, dontSendNotification);
				setEnabled(false);
			}
			else {
				setEnabled(true);
				setValue(randomization->probabilityOfDuplicateForSeqTrackStep(track, targetStep) * 100.0, sendNotification);
			}
			break;
		case KnobType::reset:
			if (targetStep == Step::one) {
				setValue(0.0, dontSendNotification);
				setEnabled(false);
			}
			else {
				setEnabled(true);
				setValue(randomization->probabilityOfResetForSeqTrackStep(track, targetStep) * 100.0, sendNotification);
			}
			break;
		default:
			break;
		}
		updateTooltip();
	}
}

KnobForSeqTrackProbability::~KnobForSeqTrackProbability() {
	randomization->removeListenerFromSeqTrackTree(this, track);
}
