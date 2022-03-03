#include "widget_global_ComboBoxForMidiClock.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ComboBoxForMidiClock::ComboBoxForMidiClock(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_Clock }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToMidiClockString::get() };
	for (uint8 i = 0; i != 4; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ globalOptions->clockType() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForMidiClock::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		tooltipText += "Selects the hardware" + GUI::apostrophe + "s MIDI clock status.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToMidiClockString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
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
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
