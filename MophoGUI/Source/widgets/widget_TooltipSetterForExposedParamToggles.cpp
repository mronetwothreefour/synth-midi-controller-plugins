#include "widget_TooltipSetterForExposedParamToggles.h"



TooltipSetterForExposedParamToggles::TooltipSetterForExposedParamToggles(Button& toggle, uint8 param) :
	toggle{ toggle },
	param{ param },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	toggle.addListener(this);
}

TooltipSetterForExposedParamToggles::~TooltipSetterForExposedParamToggles() {
	toggle.removeListener(this);
}

void TooltipSetterForExposedParamToggles::buttonClicked(Button*) {
}

void TooltipSetterForExposedParamToggles::buttonStateChanged(Button* button) {
	if (button == &toggle)
		setTooltip();
}

void TooltipSetterForExposedParamToggles::setTooltip() noexcept {
	auto tooltipText{ generateTooltipText() };
	toggle.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamToggles::generateTooltipText() noexcept {
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
