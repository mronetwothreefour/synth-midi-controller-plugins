#include "widget_global_ToggleButtonForSysEx.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ToggleButtonForSysEx::ToggleButtonForSysEx(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_SysExOn }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_ToggleButton.toString());
	setToggleState(midiOptions->sysExIsOn(), dontSendNotification);
	setTooltip(generateTooltipString());
}

String ToggleButtonForSysEx::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnWithWarningString::get() };
		auto currentValue{ (uint8)getToggleState() };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets whether the hardware should tramsmit and\n";
		tooltipText += "respond to MIDI system exclusive messages.\n";
		tooltipText += "WARNING: Turning this off will prevent the\n";
		tooltipText += "transmission of programs between the hardware\n";
		tooltipText += "and the plugin! It is strongly recommended\n";
		tooltipText += "that this option always be turned on.\n";
	}
	return tooltipText;
}

void ToggleButtonForSysEx::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setToggleState((bool)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ToggleButtonForSysEx::~ToggleButtonForSysEx() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
