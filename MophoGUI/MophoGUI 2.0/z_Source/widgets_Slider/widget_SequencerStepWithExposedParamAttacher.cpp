#include "widget_SequencerStepWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



SequencerStepWithExposedParamAttacher::SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack, UnexposedParameters* unexposedParams) :
	param{ param },
	sequencerTrack{ sequencerTrack },
	unexposedParams{ unexposedParams },
	stepSlider{ sequencerTrack, unexposedParams },
	valueDisplay{ &stepSlider, sequencerTrack, unexposedParams },
	tooltipSetter{ stepSlider, param, unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto ctrlWidth{ info.controlWidthFor(param) };
	auto ctrlHeight{ info.controlHeightFor(param) };
	setSize(ctrlWidth, ctrlHeight);
	addChildComponent(trackDestination);
	trackDestination.setInterceptsMouseClicks(false, false);
	trackDestination.setBounds(getLocalBounds());
	trackDestination.addListener(this);
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
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::seqTrack1Dest.toString(), trackDestination));
		break;
	case 2:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::seqTrack2Dest.toString(), trackDestination));
		break;
	case 3:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::seqTrack3Dest.toString(), trackDestination));
		break;
	case 4:
		destinationAttachment.reset(new SliderAttachment(*exposedParams, ID::seqTrack4Dest.toString(), trackDestination));
		break;
	default:
		break;
	};
}

void SequencerStepWithExposedParamAttacher::sliderValueChanged(Slider* slider) {
	if (slider == &trackDestination) {
		auto destination{ roundToInt(trackDestination.getValue()) };
		auto osc1Pitch{ 1 };
		auto osc2Pitch{ 2 };
		auto osc1and2Pitch{ 3 };
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		if (destination == osc1Pitch || destination == osc2Pitch || destination == osc1and2Pitch)
			randomizationOptions->setTrackDestinationIsAnOscPitchParameter(sequencerTrack);
		else
			randomizationOptions->setTrackDestinationIsNotAnOscPitchParameter(sequencerTrack);
	}
}

void SequencerStepWithExposedParamAttacher::deleteAttachment() {
	stepAttachment = nullptr;
	destinationAttachment = nullptr;
}

SequencerStepWithExposedParamAttacher::~SequencerStepWithExposedParamAttacher() {
	trackDestination.removeListener(this);
}

