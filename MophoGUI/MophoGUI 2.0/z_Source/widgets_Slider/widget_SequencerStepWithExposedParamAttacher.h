#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../guiRenderers/guiRenderer_ForSequencerStepValues.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class UnexposedParameters;

class SequencerStepWithExposedParamAttacher :
	public Component,
	public Slider::Listener
{
	uint8 param;
	const int sequencerTrack;
	UnexposedParameters* unexposedParams;
	SliderForSequencerSteps stepSlider;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> stepAttachment;
	std::unique_ptr<SliderAttachment> destinationAttachment;
	RendererForSequencerStepValues valueDisplay;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	SequencerStepWithExposedParamAttacher() = delete;

	SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void sliderValueChanged(Slider* slider) override;
	void deleteAttachment();
	~SequencerStepWithExposedParamAttacher();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepWithExposedParamAttacher)
};

