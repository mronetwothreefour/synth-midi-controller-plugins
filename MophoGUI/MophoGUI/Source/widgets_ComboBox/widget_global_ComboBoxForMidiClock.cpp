#include "widget_global_ComboBoxForMidiClock.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForMidiClock::ComboBoxForMidiClock(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_Clock }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToMidiClockString::get() };
	for (uint8 i = 0; i != 4; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ midiOptions->clockType() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForMidiClock::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToMidiClockString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the hardware's MIDI clock status.\n";
	}
	return tooltipText;
}

void ComboBoxForMidiClock::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ComboBoxForMidiClock::~ComboBoxForMidiClock() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
