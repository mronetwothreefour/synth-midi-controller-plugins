#include "widget_master_ComboBoxForSelectingMIDIechoEnabled.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingMIDIechoEnabled::ComboBoxForSelectingMIDIechoEnabled(UnexposedParameters* unexposedParams) :
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
	auto paramValue{ masterOptions->midiEchoEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingMIDIechoEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set to on, patch changes and controller messages\n";
		tooltipText += "which come into the Matrix-6R are echoed through the MIDI\n";
		tooltipText += "Out port (normally they are only echoed via the MIDI Thru\n";
		tooltipText += "port). This allows for enhanced control of additional instru-\n";
		tooltipText += "ments further on in the MIDI chain. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated on the hardware. Click\n";
		tooltipText += "the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingMIDIechoEnabled::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_MIDIechoEnabled) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingMIDIechoEnabled::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingMIDIechoEnabled::~ComboBoxForSelectingMIDIechoEnabled() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
