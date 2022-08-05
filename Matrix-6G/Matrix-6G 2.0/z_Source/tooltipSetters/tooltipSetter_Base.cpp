#include "tooltipSetter_Base.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



TooltipSetter::TooltipSetter(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
}

void TooltipSetter::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription)
		setTooltip();
}

TooltipSetter::~TooltipSetter() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
