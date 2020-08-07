#include "widget_TooltipSetterForExposedParamSliders.h"



TooltipSetterForExposedParamSliders::TooltipSetterForExposedParamSliders(Slider& slider, uint8 param) :
	slider{ slider },
	param{ param },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	slider.addListener(this);
	setTooltip();
}

TooltipSetterForExposedParamSliders::~TooltipSetterForExposedParamSliders() {
	slider.removeListener(this);
}

void TooltipSetterForExposedParamSliders::sliderValueChanged(Slider* sliderThatChanged) {
	if (sliderThatChanged == &slider)
		setTooltip();
}

void TooltipSetterForExposedParamSliders::setTooltip() noexcept {
	auto tooltipText{ generateTooltipText() };
	slider.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamSliders::generateTooltipText() noexcept {
	String tooltipText{ "" };
	auto& tooltips{ TooltipOptions::get() };
	auto& info{ InfoForExposedParameters::get() };
	if (tooltips.shouldShowDescription())
		tooltipText += info.descriptionFor(param) + "\n";
	if (tooltips.shouldShowCurrentValue()) {
		auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
		tooltipText += ("Current Setting: " + converter->verboseConvert(sliderValue));
	}
	return tooltipText;
}
