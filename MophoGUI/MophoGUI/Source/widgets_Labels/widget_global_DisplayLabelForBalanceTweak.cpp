#include "widget_global_DisplayLabelForBalanceTweak.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



DisplayLabelForBalanceTweak::DisplayLabelForBalanceTweak(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_Balance }
{
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_DisplayLabel.toString());
	auto paramValue{ globalAudioOptions->globalBalance() };
	setText(IntToBalanceTweakString::get()->verboseConvert(paramValue), dontSendNotification);
	setEditable(false, false);
	setTooltip(generateTooltipString());
}

String DisplayLabelForBalanceTweak::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Applies a small adjustment to the balance of the hardware's audio output jacks.\n";
		tooltipText += "This option cannot be changed remotely and must be set in the hardware itself.";
		tooltipText += "(This option is only available in Mopho OS version 1.4)";
	}
	return tooltipText;
}

void DisplayLabelForBalanceTweak::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
		auto paramValue{ globalAudioOptions->globalBalance() };
		setText(IntToBalanceTweakString::get()->verboseConvert(paramValue), dontSendNotification);
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForBalanceTweak::~DisplayLabelForBalanceTweak() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
	globalAudioOptions->removeListener(this);
}
