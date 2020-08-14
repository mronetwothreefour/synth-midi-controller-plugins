#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../guiRenderers/guiRenderer_ForSequencerStepValues.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class SequencerStepWithExposedParamAttacher : public Component
{
	uint8 param;
	const int sequencerTrack;
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
	void deleteAttachment();
	~SequencerStepWithExposedParamAttacher();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepWithExposedParamAttacher)
};

