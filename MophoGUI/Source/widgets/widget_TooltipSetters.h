#pragma once

#include <JuceHeader.h>



class TooltipSetter : public ValueTree::Listener
{
protected:
	ValueTree& tooltipOptions;

	TooltipSetter() :
		tooltipOptions{ TooltipOptions_Singleton::get() }
	{
		tooltipOptions.addListener(this);
	}

	~TooltipSetter() {
		tooltipOptions.removeListener(this);
	}

	virtual void setTooltip() noexcept = 0;
	virtual String generateTooltipText() noexcept = 0;

public:
	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override {
		if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription)
			setTooltip();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetter)
};



class TooltipSetterForExposedParamSliders :
	public TooltipSetter,
	public Slider::Listener
{
	Slider& slider;
	uint8 param;
	IntToContextualStringConverter* converter;

	void setTooltip() noexcept override {
		auto tooltipText{ generateTooltipText() };
		slider.setTooltip(tooltipText);
	}

	String generateTooltipText() noexcept override {
		String tooltipText{ "" };
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowCurrentValue)) {
			auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
			tooltipText += ("Current Value: " + converter->verboseConvert(sliderValue) + "\n");
		}
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowDescription))
			tooltipText += InfoForExposedParameters::get().descriptionFor(param);
		return tooltipText;
	}

public:
	TooltipSetterForExposedParamSliders(Slider& slider, uint8 param) :
		slider{ slider },
		param{ param },
		converter{ InfoForExposedParameters::get().converterFor(param) }
	{
		slider.addListener(this);
		setTooltip();
	}

	~TooltipSetterForExposedParamSliders() {
		slider.removeListener(this);
	}

	void sliderValueChanged(Slider* sliderThatChanged) override {
		if (sliderThatChanged == &slider)
			setTooltip();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamSliders)
};



class TooltipSetterForExposedParamToggles :
	public TooltipSetter,
	public Button::Listener
{
	Button& toggle;
	uint8 param;
	IntToContextualStringConverter* converter;

	void setTooltip() noexcept override {
		auto tooltipText{ generateTooltipText() };
		toggle.setTooltip(tooltipText);
	}

	String generateTooltipText() noexcept override {
		String tooltipText{ "" };
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowCurrentValue)) {
			auto toggleState{ (uint8)toggle.getToggleState() };
			tooltipText += ("Current Value: " + converter->verboseConvert(toggleState) + "\n");
		}
		if ((bool)tooltipOptions.getProperty(ID::tooltips_ShouldShowDescription))
			tooltipText += InfoForExposedParameters::get().descriptionFor(param);
		return tooltipText;
	}

public:
	TooltipSetterForExposedParamToggles(Button& toggle, uint8 param) :
		toggle{ toggle },
		param{ param },
		converter{ InfoForExposedParameters::get().converterFor(param) }
	{
		toggle.addListener(this);
		setTooltip();
	}

	~TooltipSetterForExposedParamToggles() {
		toggle.removeListener(this);
	}

	void buttonClicked(Button* /*button*/) override {
	}

	void buttonStateChanged(Button* button) override {
		if (button == &toggle)
			setTooltip();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamToggles)
};



