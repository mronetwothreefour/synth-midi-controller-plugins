#include "widget_master_ComboBoxForSelectingSysExEnabled.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingSysExEnabled::ComboBoxForSelectingSysExEnabled(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToOffOnString::get() };
	choices.add(converter->convert(0));
	choices.add(converter->convert(1));
	addItemList(choices, 1);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	auto paramValue{ masterOptions->sysExEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSysExEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, the hardware will respond to MIDI\n";
		tooltipText += "System Exclusive (SysEx) messages. IMPORTANT: This\n";
		tooltipText += "plugin uses SysEx to communicate with the hardware and\n";
		tooltipText += "it is imperative that this option be set to on. If it\n";
		tooltipText += "gets turned off, it can only be turned back on in the\n";
		tooltipText += "Master Edit page on the hardware itself (parameter 04).\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingSysExEnabled::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_SysExEnabled) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingSysExEnabled::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingSysExEnabled::~ComboBoxForSelectingSysExEnabled() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
