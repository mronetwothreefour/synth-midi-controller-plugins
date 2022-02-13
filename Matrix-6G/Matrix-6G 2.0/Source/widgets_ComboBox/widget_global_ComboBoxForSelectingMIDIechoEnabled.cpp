#include "widget_global_ComboBoxForSelectingMIDIechoEnabled.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingMIDIechoEnabled::ComboBoxForSelectingMIDIechoEnabled(UnexposedParameters* unexposedParams) :
	BaseComboBoxForOffOnValueTreeProperty{ unexposedParams, ID::global_MIDIechoEnabled },
	unexposedParams{ unexposedParams }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto paramValue{ globalOptions->midiEchoEnabled() };
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
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
