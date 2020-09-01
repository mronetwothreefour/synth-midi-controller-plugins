#include "widget_global_ComboBoxForParameterReceive.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForParameterReceive::ComboBoxForParameterReceive(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_ParameterReceiveType }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToParameterReceiveTypeString::get() };
	for (uint8 i = 0; i != 4; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ midiOptions->parameterReceiveType() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForParameterReceive::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToParameterReceiveTypeString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current value: ";
		tooltipText += converter->verboseConvert(currentValue) + "\n";
	}
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the method by which the hardware receives parameter changes via MIDI.\n";
		tooltipText += "WARNING: For this plugin to function correctly, it is imperative that this option\n";
		tooltipText += "be set to NRPN or to All. If NRPN gets turned off, you will have to go to the global\n";
		tooltipText += "parameters menu in the hardware itself to turn it back on and restore functionality.";
	}
	return tooltipText;
}

void ComboBoxForParameterReceive::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

ComboBoxForParameterReceive::~ComboBoxForParameterReceive() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
