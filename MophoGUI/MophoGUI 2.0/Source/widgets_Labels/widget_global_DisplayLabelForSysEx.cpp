#include "widget_global_DisplayLabelForSysEx.h"

#include "../gui/gui_Constants.h"
#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



DisplayLabelForSysEx::DisplayLabelForSysEx(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_SysExOn }
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

void DisplayLabelForSysEx::setTextAccordingToParameterSetting() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->sysExIsOff())
		setColour(textColourId, Color::button);
	else
		setColour(textColourId, Color::black);
	auto paramValue{ midiOptions->sysExIsOn() };
	setText(IntToSysExOffOnString::get()->verboseConvert(paramValue), dontSendNotification);
}

String DisplayLabelForSysEx::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether or not the hardware will transmit / receive\n";
		tooltipText += "MIDI system exclusive messages. WARNING: Program data is\n";
		tooltipText += "transferred between the plugin and the hardware via system\n";
		tooltipText += "exclusive messages. It is imperative that this option\n";
		tooltipText += "be set to " + GUI::openQuote + "ON" + GUI::closeQuote + " for the plugin to function correctly.";
	}
	return tooltipText;
}

void DisplayLabelForSysEx::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setTextAccordingToParameterSetting();
	}
	if (property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

DisplayLabelForSysEx::~DisplayLabelForSysEx() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
