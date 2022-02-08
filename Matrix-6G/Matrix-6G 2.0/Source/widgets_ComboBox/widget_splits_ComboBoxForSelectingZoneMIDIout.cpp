#include "widget_splits_ComboBoxForSelectingZoneMIDIout.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingZoneMIDIout::ComboBoxForSelectingZoneMIDIout(UnexposedParameters* unexposedParams, Identifier parameterID) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, parameterID == ID::split_LowerZoneMidiOut ? ID::split_LowerZoneMidiOut : ID::split_UpperZoneMidiOut },
	unexposedParams{ unexposedParams },
	parameterID{ parameterID }
{
	jassert(parameterID == ID::split_LowerZoneMidiOut || parameterID == ID::split_UpperZoneMidiOut);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	auto paramValue{ parameterID == ID::split_LowerZoneMidiOut ? splitOptions->lowerZoneMidiOut() : splitOptions->upperZoneMidiOut() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingZoneMIDIout::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether the zone transmits and receives MIDI\n";
		tooltipText += "messages on the basic channel (set in MASTER).\n";
		tooltipText += "NOTE: Changes made to split parameters are not\n";
		tooltipText += "sent to the hardware until you SAVE the split in\n";
		tooltipText += "one of the storage bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingZoneMIDIout::~ComboBoxForSelectingZoneMIDIout() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}