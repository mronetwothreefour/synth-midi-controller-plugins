#include "widget_master_ComboBoxForSelectingMIDIechoEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingMIDIechoEnabled::ComboBoxForSelectingMIDIechoEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::master_MIDIechoEnabled },
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto paramValue{ masterOptions->midiEchoEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingMIDIechoEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, patch changes and controller messages\n";
		tooltipText += "which come into the Matrix-6R are echoed through the MIDI\n";
		tooltipText += "Out port (normally they are only echoed via the MIDI Thru\n";
		tooltipText += "port). This allows for enhanced control of additional instru-\n";
		tooltipText += "ments further on in the MIDI chain. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware. Click\n";
		tooltipText += "the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

ComboBoxForSelectingMIDIechoEnabled::~ComboBoxForSelectingMIDIechoEnabled() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
