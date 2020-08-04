#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_UnexposedParameters.h"



class TooltipSetter : public ValueTree::Listener
{
protected:
	TooltipSetter() {
		auto& tooltipOptions{ TooltipOptions_Singleton::get() };
		tooltipOptions.addListener(this);
	}

	~TooltipSetter() {
		auto& tooltipOptions{ TooltipOptions_Singleton::get() };
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
		auto& tooltips{ TooltipOptions_Singleton::get() };
		auto& info{ InfoForExposedParameters::get() };
		if (tooltips.shouldShowDescription())
			tooltipText += info.descriptionFor(param) + "\n";
		if (tooltips.shouldShowCurrentValue()) {
			auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
			tooltipText += ("Current Setting: " + converter->verboseConvert(sliderValue));
		}
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
		auto& tooltips{ TooltipOptions_Singleton::get() };
		auto& info{ InfoForExposedParameters::get() };
		if (tooltips.shouldShowDescription())
			tooltipText += info.descriptionFor(param) + "\n";
		if (tooltips.shouldShowCurrentValue()) {
			auto toggleState{ (uint8)toggle.getToggleState() };
			tooltipText += ("Current Setting: " + converter->verboseConvert(toggleState));
		}
		return tooltipText;
	}

public:
	TooltipSetterForExposedParamToggles(Button& toggle, uint8 param) :
		toggle{ toggle },
		param{ param },
		converter{ InfoForExposedParameters::get().converterFor(param) }
	{
		toggle.addListener(this);
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



class TooltipSetterForExposedParamComboBoxes :
	public TooltipSetter,
	public ComboBox::Listener
{
	ComboBox& comboBox;
	uint8 param;
	IntToContextualStringConverter* converter;

	void setTooltip() noexcept override {
		auto tooltipText{ generateTooltipText() };
		comboBox.setTooltip(tooltipText);
	}

	String generateTooltipText() noexcept override {
		String tooltipText{ "" };
		auto& tooltips{ TooltipOptions_Singleton::get() };
		auto& info{ InfoForExposedParameters::get() };
		if (tooltips.shouldShowDescription())
			tooltipText += info.descriptionFor(param) + "\n";
		if (tooltips.shouldShowCurrentValue()) {
			auto selectedItem{ (uint8)comboBox.getSelectedItemIndex() };
			tooltipText += ("Current Setting: " + converter->verboseConvert(selectedItem));
		}
		return tooltipText;
	}

public:
	TooltipSetterForExposedParamComboBoxes(ComboBox& comboBox, uint8 param) :
		comboBox{ comboBox },
		param{ param },
		converter{ InfoForExposedParameters::get().converterFor(param) }
	{
		comboBox.addListener(this);
	}

	~TooltipSetterForExposedParamComboBoxes() {
		comboBox.removeListener(this);
	}

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override {
		if (comboBoxThatHasChanged == &comboBox)
			setTooltip();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamComboBoxes)
};



