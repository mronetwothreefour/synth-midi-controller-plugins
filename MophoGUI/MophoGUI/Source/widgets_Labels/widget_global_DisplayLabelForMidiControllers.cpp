#include "widget_global_DisplayLabelForMidiControllers.h"

#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



DisplayLabelForMidiControllers::DisplayLabelForMidiControllers(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_ControllersOn }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_DisplayLabel.toString());
	setEditable(false, false);
	setTextAccordingToParameterSetting();
	setTooltip(generateTooltipString());
}

void DisplayLabelForMidiControllers::setTextAccordingToParameterSetting() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->controllersAreOff())
		setColour(textColourId, Color::button);
	else
		setColour(textColourId, Color::black);
	auto paramValue{ midiOptions->controllersAreOn() };
	setText(IntToMidiControllersOffOnString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForMidiControllers::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether or not the hardware will respond to MIDI controller messages.\n";
		tooltipText += "WARNING: This plugin uses controller messages to communicate with the hardware.\n";
		tooltipText += "It is imperative that this be set to \"ON\" for the plugin to function correctly.\n";
		tooltipText += "This option cannot be changed remotely and must be set in the hardware itself.";
	}
	return tooltipText;
}

void DisplayLabelForMidiControllers::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForMidiControllers::~DisplayLabelForMidiControllers() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
