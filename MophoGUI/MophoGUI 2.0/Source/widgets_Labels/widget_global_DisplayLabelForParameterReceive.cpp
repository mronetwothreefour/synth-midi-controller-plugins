#include "widget_global_DisplayLabelForParameterReceive.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



DisplayLabelForParameterReceive::DisplayLabelForParameterReceive(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_ParameterReceiveType }
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

void DisplayLabelForParameterReceive::setTextAccordingToParameterSetting() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	if (globalOptions->hardwareIsNotSetToReceiveNRPNcontrollers())
		setColour(textColourId, Color::button);
	else
		setColour(textColourId, Color::black);
	auto paramValue{ globalOptions->parameterReceiveType() };
	setText(IntToParameterReceiveTypeString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForParameterReceive::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "The type of MIDI parameter change messages recognized by the hardware.\n";
		tooltipText += "WARNING: This plugin transmits parameter changes using NRPN. It is\n";
		tooltipText += "imperative that this be set to " + GUI::openQuote + "ALL" + GUI::closeQuote + " or " + GUI::openQuote + "NRPN ONLY" + GUI::closeQuote + " for the plugin to\n";
		tooltipText += "function correctly. This option cannot be changed remotely and must\n";
		tooltipText += "be set within the hardware" + GUI::apostrophe + "s Global Parameters menus.";
	}
	return tooltipText;
}

void DisplayLabelForParameterReceive::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForParameterReceive::~DisplayLabelForParameterReceive() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
