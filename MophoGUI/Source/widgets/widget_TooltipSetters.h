#pragma once

#include <JuceHeader.h>



class TooltipSetterForExposedParamSliders :
	public Slider::Listener,
	public ValueTree::Listener
{
	Slider& slider;
	IntToContextualStringConverter* converter;
	String description;
	ValueTree& tooltipOptions;

public:
	TooltipSetterForExposedParamSliders(Slider& slider, uint16 paramIndex) :
		slider{ slider },
		converter{ ExposedParamsInfo_Singleton::get()[paramIndex].converter },
		description{ ExposedParamsInfo_Singleton::get()[paramIndex].description },
		tooltipOptions{ TooltipOptions_Singleton::get() }
	{
		slider.addListener(this);
		tooltipOptions.addListener(this);
		setTooltip();
	}

	~TooltipSetterForExposedParamSliders() {
		tooltipOptions.removeListener(this);
		slider.removeListener(this);
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override {
		if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription)
			setTooltip();
	}

	void sliderValueChanged(Slider* sliderThatChanged) override {
		if (sliderThatChanged == &slider)
			setTooltip();
	}

	void setTooltip() {
		auto tooltipText{ generateTooltipText() };
		slider.setTooltip(tooltipText);
	}

	String generateTooltipText() {
		String tooltipText{ "" };
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowCurrentValue)) {
			auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
			tooltipText += ("Current Value: " + converter->verboseConvert(sliderValue) + "\n");
		}
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowDescription)) {
			tooltipText += description;
		}
		return tooltipText;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamSliders)
};



