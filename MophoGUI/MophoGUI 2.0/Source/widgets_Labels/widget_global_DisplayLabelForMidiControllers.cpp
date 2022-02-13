#include "widget_global_DisplayLabelForMidiControllers.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



DisplayLabelForMidiControllers::DisplayLabelForMidiControllers(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_ControllersOn }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setComponentID(ID::component_DisplayLabel.toString());
	setEditable(false, false);
	setTextAccordingToParameterSetting();
	setTooltip(generateTooltipString());
}

void DisplayLabelForMidiControllers::setTextAccordingToParameterSetting() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	if (globalOptions->controllersAreOff())
		setColour(textColourId, Color::button);
	else
		setColour(textColourId, Color::black);
	auto paramValue{ globalOptions->controllersAreOn() };
	setText(IntToMidiControllersOffOnString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForMidiControllers::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether or not the hardware will respond to MIDI controller messages.\n";
		tooltipText += "WARNING: Controller messages are used to communicate with the hardware.\n";
		tooltipText += "It is imperative that this be set to " + GUI::openQuote + "ON" + GUI::closeQuote + " for this plugin to function correctly.\n";
		tooltipText += "This option cannot be changed remotely and must be set within the\n";
		tooltipText += "hardware" + GUI::apostrophe + "s Global Parameters menus.";
	}
	return tooltipText;
}

void DisplayLabelForMidiControllers::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForMidiControllers::~DisplayLabelForMidiControllers() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
