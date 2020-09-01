#include "widget_global_ComboBoxForPedalMode.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForPedalMode::ComboBoxForPedalMode(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_PedalModeArpLatch }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToPedalModeString::get() };
	for (uint8 i = 0; i != 2; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ midiOptions->parameterReceiveType() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForPedalMode::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToPedalModeString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When Arpeggiator Latch mode is selected and the arpeggiator is on,\n";
		tooltipText += "MIDI sustain pedal on messages (CC# 64) will latch the arpeggiated notes.\n";
		tooltipText += "When the arpeggiator is off, sustain pedal on messages will behave normally.\n";
		tooltipText += "(This option is only available in Mopho OS version 1.4)";
	}
	return tooltipText;
}

void ComboBoxForPedalMode::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ComboBoxForPedalMode::~ComboBoxForPedalMode() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
