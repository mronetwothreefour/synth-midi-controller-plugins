#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobWithExposedParamAttacherForOscWaveShapes : public Component
{
protected:
	uint8 param;
	SliderForOscWaveShapes slider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	KnobWithExposedParamAttacherForOscWaveShapes() = delete;

	KnobWithExposedParamAttacherForOscWaveShapes(uint8 param, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithExposedParamAttacherForOscWaveShapes)
};


