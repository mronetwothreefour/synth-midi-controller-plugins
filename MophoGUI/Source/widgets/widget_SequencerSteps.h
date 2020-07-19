#pragma once

#include <JuceHeader.h>

#include "widget_SequencerStepValueRenderer.h"
#include "widget_Sliders.h"
#include "widget_TooltipSetters.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class SequencerStepWithExposedParamAttacher : public Component
{
	uint8 param;
	const int sequencerTrack;
	SliderForSequencerSteps stepSlider;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> stepAttachment;
	std::unique_ptr<SliderAttachment> destinationAttachment;
	SequencerStepValueRenderer valueRenderer;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	SequencerStepWithExposedParamAttacher() = delete;

	SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack) :
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

	~SequencerStepWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		auto& info{ InfoForExposedParameters::get() };
		stepAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), stepSlider));
		jassert(sequencerTrack > 0 && sequencerTrack < 5);
		switch (sequencerTrack)
		{
		case 1:
			destinationAttachment.reset(new SliderAttachment(*exposedParams, "seqTrack1Dest", trackDestination));
			break;
		case 2:
			destinationAttachment.reset(new SliderAttachment(*exposedParams, "seqTrack2Dest", trackDestination));
			break;
		case 3:
			destinationAttachment.reset(new SliderAttachment(*exposedParams, "seqTrack3Dest", trackDestination));
			break;
		case 4:
			destinationAttachment.reset(new SliderAttachment(*exposedParams, "seqTrack4Dest", trackDestination));
			break;
		default:
			break;
		};
	}

	void deleteAttachment() {
		stepAttachment = nullptr;
		destinationAttachment = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepWithExposedParamAttacher)
};

