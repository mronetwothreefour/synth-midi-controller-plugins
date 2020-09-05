#include "widget_global_DisplayLabelForParameterReceive.h"

#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



DisplayLabelForParameterReceive::DisplayLabelForParameterReceive(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_ParameterReceiveType }
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

void DisplayLabelForParameterReceive::setTextAccordingToParameterSetting() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->hardwareIsNotSetToReceiveNRPNcontrollers())
		setColour(textColourId, Color::button);
	else
		setColour(textColourId, Color::black);
	auto paramValue{ midiOptions->parameterReceiveType() };
	setText(IntToParameterReceiveTypeString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForParameterReceive::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "The method by which the hardware receives parameter change messages via MIDI.\n";
		tooltipText += "WARNING: This plugin transmits parameter changes using NRPN. It is imperative\n";
		tooltipText += "that this be set to \"ALL\" or \"NRPN ONLY\" for the plugin to function correctly.\n";
		tooltipText += "This option cannot be changed remotely and must be set in the hardware itself.";
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
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
