#pragma once

#include <JuceHeader.h>

#include "widget_CustomSliders.h"
#include "widget_TooltipSetterForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class PgmNameCharWithExposedParamAttacher : 
	public Component,
	public Slider::Listener
{
	uint8 param;
	SliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> sliderAttachment;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	PgmNameCharWithExposedParamAttacher() = delete;

	explicit PgmNameCharWithExposedParamAttacher(uint8 param);
	~PgmNameCharWithExposedParamAttacher();
	void sliderValueChanged(Slider* sliderThatChanged) override;
	void paint(Graphics& g) override;
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void limitSliderRangeToBasicASCIICharsThatAreVisible();
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PgmNameCharWithExposedParamAttacher)
};