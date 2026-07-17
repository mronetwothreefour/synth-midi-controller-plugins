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
	if (property == ID::tooltips_ShouldShowCurrentSettings || property == ID::tooltips_ShouldShowDescriptions)
		setTooltip();
}

TooltipSetter::~TooltipSetter() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
