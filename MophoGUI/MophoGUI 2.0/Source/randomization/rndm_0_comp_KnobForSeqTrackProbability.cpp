#include "rndm_0_comp_KnobForSeqTrackProbability.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



KnobForSeqTrackProbability::KnobForSeqTrackProbability(KnobType knobType, Track track, UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMoveOverride{ unexposedParams },
	knobType{ knobType },
	track{ track },
	randomization{ unexposedParams->getRandomizationOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	if (knobType == KnobType::rest)
		jassert(track == Track::one);
	randomization->addListenerToSeqTrackTree(this, track);

	setRange(0.0, 100.0, 1.0);

	auto editModeIsAllSteps{ randomization->editModeIsAllStepsForSeqTrack(track) };
	auto selectedStep{ randomization->selectedStepForSeqTrack(track) };
	switch (knobType)
	{
	case KnobType::rest:
		setDoubleClickReturnValue(true, 10.0);
		break;
	case KnobType::duplicate:
		setDoubleClickReturnValue(true, 0.0);
		break;
	case KnobType::reset:
		setDoubleClickReturnValue(true, 0.0);
		break;
	default:
		break;
	}
}

void KnobForSeqTrackProbability::updateTooltip()
{
}

void KnobForSeqTrackProbability::valueChanged()
{
}

void KnobForSeqTrackProbability::valueTreePropertyChanged(ValueTree& tree, const Identifier& property)
{
}

KnobForSeqTrackProbability::~KnobForSeqTrackProbability()
{
}
