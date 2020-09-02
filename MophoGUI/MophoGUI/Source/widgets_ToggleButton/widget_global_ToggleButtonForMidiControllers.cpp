#include "widget_global_ToggleButtonForMidiControllers.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ToggleButtonForMidiControllers::ToggleButtonForMidiControllers(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_ControllersOn }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_ToggleButton.toString());
	setToggleState(midiOptions->controllersAreOn(), dontSendNotification);
	setTooltip(generateTooltipString());
}

String ToggleButtonForMidiControllers::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnWithWarningString::get() };
		auto currentValue{ (uint8)getToggleState() };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets whether the hardware should respond to MIDI controller (CC) messages.\n";
		tooltipText += "WARNING: It is imperative that this option is turned on for this plugin to\n";
		tooltipText += "function correctly! If it gets turned off, you will have to turn it back on\n";
		tooltipText += "in the hardware's global parameters menu to restore full functionality.\n";
	}
	return tooltipText;
}

void ToggleButtonForMidiControllers::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setToggleState((bool)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ToggleButtonForMidiControllers::~ToggleButtonForMidiControllers() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
