#include "tooltipSetter_ForExposedParamToggles.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



TooltipSetterForExposedParamToggles::TooltipSetterForExposedParamToggles(Button& toggle, uint8 param, UnexposedParameters* unexposedParams) :
	TooltipSetter{ unexposedParams },
	toggle{ toggle },
	param{ param },
	unexposedParams{ unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	toggle.addListener(this);
}

void TooltipSetterForExposedParamToggles::buttonClicked(Button* /*button*/) {
}

void TooltipSetterForExposedParamToggles::buttonStateChanged(Button* button) {
	if (button == &toggle)
		setTooltip();
}

void TooltipSetterForExposedParamToggles::setTooltip() {
	auto tooltipText{ generateTooltipText() };
	toggle.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamToggles::generateTooltipText() {
	String tooltipText{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	if (tooltips->shouldShowDescription())
		tooltipText += info.descriptionFor(param) + "\n";
	if (tooltips->shouldShowCurrentValue()) {
		auto toggleState{ (uint8)toggle.getToggleState() };
		tooltipText += ("Current Setting: " + converter->verboseConvert(toggleState));
	}
	return tooltipText;
}

TooltipSetterForExposedParamToggles::~TooltipSetterForExposedParamToggles() {
	toggle.removeListener(this);
}

