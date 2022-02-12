#include "widget_global_ComboBoxForVoiceChange.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForVoiceChange::ComboBoxForVoiceChange(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_VoiceChangeOn }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToDisabledEnabledString::get() };
	for (uint8 i = 0; i != 2; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ midiOptions->voiceChangeIsOn() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForVoiceChange::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When enabled, the hardware will respond to incoming\n";
		tooltipText += "MIDI program change and bank change messages.\n";
		tooltipText += "(This option was added in Mopho firmware version 1.4)\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToDisabledEnabledString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForVoiceChange::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ComboBoxForVoiceChange::~ComboBoxForVoiceChange() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
