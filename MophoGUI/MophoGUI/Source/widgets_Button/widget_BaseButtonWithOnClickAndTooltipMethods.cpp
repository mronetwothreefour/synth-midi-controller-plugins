#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



BaseButtonWithOnClickAndTooltipMethods::BaseButtonWithOnClickAndTooltipMethods(String buttonText, UnexposedParameters* unexposedParams) :
	TextButton{ buttonText },
	unexposedParams{ unexposedParams }
{
	unexposedParams->tooltipOptions_get()->addListener(this);
	onClick = [this] { onClickMethod(); };
}

void BaseButtonWithOnClickAndTooltipMethods::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowDescription)
		setTooltip(createButtonTooltipString());
}

BaseButtonWithOnClickAndTooltipMethods::~BaseButtonWithOnClickAndTooltipMethods() {
	unexposedParams->tooltipOptions_get()->removeListener(this);
}
