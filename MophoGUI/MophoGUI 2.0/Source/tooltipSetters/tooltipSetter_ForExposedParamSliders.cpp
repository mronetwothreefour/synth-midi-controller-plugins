#include "tooltipSetter_ForExposedParamSliders.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



TooltipSetterForExposedParamSliders::TooltipSetterForExposedParamSliders(Slider& slider, uint8 param, UnexposedParameters* unexposedParams) :
	TooltipSetter{ unexposedParams },
	slider{ slider },
	param{ param },
	unexposedParams{ unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	slider.addListener(this);
	setTooltip();
}

void TooltipSetterForExposedParamSliders::sliderValueChanged(Slider* sliderThatChanged) {
	if (sliderThatChanged == &slider)
		setTooltip();
}

void TooltipSetterForExposedParamSliders::setTooltip() {
	auto tooltipText{ generateTooltipText() };
	slider.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamSliders::generateTooltipText() {
	String tooltipText{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	if (tooltips->shouldShowDescriptions())
		tooltipText += info.descriptionFor(param) + "\n";
	if (tooltips->shouldShowCurrentValue()) {
		auto sliderValue{ (uint8)roundToInt(slider.getValue()) };
		tooltipText += ("Current Setting: " + converter->verboseConvert(sliderValue));
	}
	return tooltipText;
}

TooltipSetterForExposedParamSliders::~TooltipSetterForExposedParamSliders() {
	slider.removeListener(this);
}
