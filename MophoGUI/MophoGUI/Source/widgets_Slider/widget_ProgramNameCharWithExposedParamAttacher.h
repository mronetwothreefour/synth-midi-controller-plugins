#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class ProgramNameCharWithExposedParamAttacher :
	public Component,
	public Slider::Listener
{
	uint8 param;
	SliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> sliderAttachment;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	ProgramNameCharWithExposedParamAttacher() = delete;

	ProgramNameCharWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams);
	void sliderValueChanged(Slider* sliderThatChanged) override;
	void paint(Graphics& g) override;
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void limitSliderRangeToBasicASCIICharsThatAreVisible();
	void deleteAttachment();
	~ProgramNameCharWithExposedParamAttacher();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameCharWithExposedParamAttacher)
};