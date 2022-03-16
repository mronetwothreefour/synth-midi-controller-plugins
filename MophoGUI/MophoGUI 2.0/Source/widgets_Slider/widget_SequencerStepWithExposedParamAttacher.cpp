#include "widget_SequencerStepWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



SequencerStepWithExposedParamAttacher::SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack, UnexposedParameters* unexposedParams) :
	param{ param },
	sequencerTrack{ sequencerTrack },
	stepSlider{ sequencerTrack, unexposedParams },
	valueDisplay{ &stepSlider, &trackDestination },
	tooltipSetter{ stepSlider, param, unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto ctrlWidth{ info.controlWidthFor(param) };
	auto ctrlHeight{ info.controlHeightFor(param) };
	setSize(ctrlWidth, ctrlHeight);
	addChildComponent(trackDestination);
	trackDestination.setInterceptsMouseClicks(false, false);
	trackDestination.setBounds(getLocalBounds());
	addAndMakeVisible(stepSlider);
	stepSlider.setMouseDragSensitivity(80 + info.numberOfStepsFor(param) / 2);
	stepSlider.setComponentID(ID::component_SeqStep.toString());
	stepSlider.setBounds(getLocalBounds());
	addAndMakeVisible(valueDisplay);
	valueDisplay.setInterceptsMouseClicks(false, false);
	valueDisplay.setBounds(getLocalBounds());
}

void SequencerStepWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	stepAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), stepSlider));
	jassert(sequencerTrack > 0 && sequencerTrack < 5);
	switch (sequencerTrack)
	{
	case 1:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::SeqTrack1Dest.toString(), trackDestination));
		break;
	case 2:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::SeqTrack2Dest.toString(), trackDestination));
		break;
	case 3:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::SeqTrack3Dest.toString(), trackDestination));
		break;
	case 4:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::SeqTrack4Dest.toString(), trackDestination));
		break;
	default:
		break;
	};
}

void SequencerStepWithExposedParamAttacher::deleteAttachment() {
	stepAttachment = nullptr;
	destinationAttachment = nullptr;
}

