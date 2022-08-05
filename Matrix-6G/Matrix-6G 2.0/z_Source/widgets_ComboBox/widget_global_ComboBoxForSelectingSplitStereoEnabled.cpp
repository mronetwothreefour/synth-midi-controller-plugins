#include "widget_global_ComboBoxForSelectingSplitStereoEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingSplitStereoEnabled::ComboBoxForSelectingSplitStereoEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_SplitStereoEnabled },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ globalOptions->splitStereoEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSplitStereoEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "If this is enabled while playing in Split mode,\n";
		tooltipText += "the Lower Split Zone patch will be output from the\n";
		tooltipText += "Left/Mono jack on the back panel of the hardware,\n";
		tooltipText += "and the Upper Zone patch will be output from the\n";
		tooltipText += "Right jack (normally, audio is only output from\n";
		tooltipText += "the Left/Mono jack). NOTE: Individual Master op-\n";
		tooltipText += "tions are not immediately updated on the hardware.\n";
		tooltipText += "Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingSplitStereoEnabled::~ComboBoxForSelectingSplitStereoEnabled() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
