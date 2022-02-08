#include "widget_master_ComboBoxForSelectingMIDImonoEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingMIDImonoEnabled::ComboBoxForSelectingMIDImonoEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::master_MIDImonoEnabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->midiMonoEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingMIDImonoEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, each of the six voices will be assigned a separate\n";
		tooltipText += "MIDI channel and will only respond to notes and controller messages\n";
		tooltipText += "coming in on that channel. Voice 1 is assigned to the Basic Channel\n";
		tooltipText += "and the subsequent voices increment the assigned channel by 1, e.g. if\n";
		tooltipText += "Voice 1 is assigned channel 1, voice 6 is assigned channel 6. Channel\n";
		tooltipText += "numbers higher than 16 wrap around to the start, e.g. if Voice 1 is\n";
		tooltipText += "assigned channel 12, voice 6 is assigned channel 1. This mode is\n";
		tooltipText += "especially useful with a MIDI guitar controller. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware. Click the PUSH\n";
		tooltipText += "button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingMIDImonoEnabled::~ComboBoxForSelectingMIDImonoEnabled() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
