#pragma once

#include <JuceHeader.h>



class TooltipSetterForExposedParamSliders :
	public Slider::Listener,
	public ValueTree::Listener
{
	Slider& slider;
	uint16 paramIndex;

public:
	TooltipSetterForExposedParamSliders(Slider& slider, uint16 paramIndex) :
		slider{ slider },
		paramIndex{ paramIndex }
	{
		slider.addListener(this);
		auto& tooltipOptions{ TooltipOptions_Singleton::get() };
		tooltipOptions.addListener(this);
		setTooltip();
	}

	~TooltipSetterForExposedParamSliders() {
		auto& tooltipOptions{ TooltipOptions_Singleton::get() };
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
		auto& exposedParamsInfo{ ExposedParamsInfo_Singleton::get() };
		auto paramInfo{ exposedParamsInfo[paramIndex] };
		auto& tooltipOptions{ TooltipOptions_Singleton::get() };
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowCurrentValue)) {
			auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
			IntToContextualStringConverter* converter{ paramInfo.converter };
			tooltipText += ("Current Value: " + converter->verboseConvert(sliderValue) + "\n");
		}
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowDescription)) {
			String description{ paramInfo.description };
			tooltipText += description;
		}
		return tooltipText;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamSliders)
};



