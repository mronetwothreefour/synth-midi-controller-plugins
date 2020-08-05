#pragma once

#include <JuceHeader.h>

#include "widget_SequencerStepValueRenderer.h"
#include "widget_CustomSliders.h"
#include "widget_TooltipSetterForExposedParamSliders.h"

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

	SequencerStepWithExposedParamAttacher(uint8 param, int sequencerTrack);
	~SequencerStepWithExposedParamAttacher();
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepWithExposedParamAttacher)
};

