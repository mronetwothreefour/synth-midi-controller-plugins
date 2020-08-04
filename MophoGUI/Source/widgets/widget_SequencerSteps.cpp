#include "widget_SequencerSteps.h"



SequencerStepWithExposedParamAttacher::SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack) :
	param{ param },
	sequencerTrack{ sequencerTrack },
	stepSlider{ sequencerTrack },
	valueRenderer{ &stepSlider, &trackDestination },
	tooltipSetter{ stepSlider, param }
{
	auto& info{ InfoForExposedParameters::get() };
	auto ctrlWidth{ info.ctrlWidthFor(param) };
	auto ctrlHeight{ info.ctrlHeightFor(param) };
	setSize(ctrlWidth, ctrlHeight);
	addChildComponent(trackDestination);
	trackDestination.setInterceptsMouseClicks(false, false);
	trackDestination.setBounds(getLocalBounds());
	addAndMakeVisible(stepSlider);
	stepSlider.setMouseDragSensitivity(80 + info.numberOfStepsFor(param) / 2);
	stepSlider.setComponentID(ID::component_SeqStep.toString());
	stepSlider.setBounds(getLocalBounds());
	addAndMakeVisible(valueRenderer);
	valueRenderer.setInterceptsMouseClicks(false, false);
	valueRenderer.setBounds(getLocalBounds());
}

SequencerStepWithExposedParamAttacher::~SequencerStepWithExposedParamAttacher() {
}

void SequencerStepWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	stepAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), stepSlider));
	jassert(sequencerTrack > 0 && sequencerTrack < 5);
	switch (sequencerTrack)
	{
	case 1:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::param_SeqTrack1Dest.toString(), trackDestination));
		break;
	case 2:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::param_SeqTrack2Dest.toString(), trackDestination));
		break;
	case 3:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::param_SeqTrack3Dest.toString(), trackDestination));
		break;
	case 4:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::param_SeqTrack4Dest.toString(), trackDestination));
		break;
	default:
		break;
	};
}

void SequencerStepWithExposedParamAttacher::deleteAttachment() {
	stepAttachment = nullptr;
	destinationAttachment = nullptr;
}
