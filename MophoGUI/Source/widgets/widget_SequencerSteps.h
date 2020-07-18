#pragma once

#include <JuceHeader.h>

#include "widget_SequencerStepValueRenderer.h"
#include "widget_Sliders.h"
#include "widget_TooltipSetters.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class SeqTrack1StepWithExposedParamAttacher : public Component
{
	uint8 param;
	SliderForTrack1Steps stepSlider;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> stepAttachment;
	std::unique_ptr<SliderAttachment> destinationAttachment;
	SequencerStepValueRenderer valueRenderer;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	SeqTrack1StepWithExposedParamAttacher() = delete;

	explicit SeqTrack1StepWithExposedParamAttacher(uint8 param) :
		param{ param },
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

	~SeqTrack1StepWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		auto& info{ InfoForExposedParameters::get() };
		stepAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), stepSlider));
		auto nrpn{ info.NRPNfor(param) };
		jassert(nrpn > 119 && nrpn < 136);
		if (nrpn > 119 && nrpn < 136) // track 1 steps
			destinationAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(101).toString(), trackDestination));
	}

	void deleteAttachment() {
		stepAttachment = nullptr;
		destinationAttachment = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrack1StepWithExposedParamAttacher)
};



class SeqTracks2_3_4StepWithExposedParamAttacher : public Component
{
	uint8 param;
	SliderForTracks2_3_4Steps stepSlider;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> stepAttachment;
	std::unique_ptr<SliderAttachment> destinationAttachment;
	SequencerStepValueRenderer valueRenderer;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	SeqTracks2_3_4StepWithExposedParamAttacher() = delete;

	explicit SeqTracks2_3_4StepWithExposedParamAttacher(uint8 param) :
		param{ param },
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

	~SeqTracks2_3_4StepWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		auto& info{ InfoForExposedParameters::get() };
		stepAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), stepSlider));
		auto nrpn{ info.NRPNfor(param) };
		jassert(nrpn > 135 && nrpn < 184);
		if (nrpn > 135 && nrpn < 152) // track 2 steps
			destinationAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(102).toString(), trackDestination));
		if (nrpn > 151 && nrpn < 168) // track 3 steps
			destinationAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(103).toString(), trackDestination));
		if (nrpn > 167 && nrpn < 184) // track 4 steps
			destinationAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(104).toString(), trackDestination));
	}

	void deleteAttachment() {
		stepAttachment = nullptr;
		destinationAttachment = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTracks2_3_4StepWithExposedParamAttacher)
};
