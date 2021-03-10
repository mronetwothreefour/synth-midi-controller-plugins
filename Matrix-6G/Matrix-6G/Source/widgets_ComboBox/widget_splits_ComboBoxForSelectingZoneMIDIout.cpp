#include "widget_splits_ComboBoxForSelectingZoneMIDIout.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingZoneMIDIout::ComboBoxForSelectingZoneMIDIout(UnexposedParameters* unexposedParams, Identifier parameterID) :
	unexposedParams{ unexposedParams },
	parameterID{ parameterID }
{
	jassert(parameterID == ID::split_LowerZoneMidiOut || parameterID == ID::split_UpperZoneMidiOut);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	StringArray choices;
	auto converter{ IntToOffOnString::get() };
	for (uint8 i = 0; i != 2; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ parameterID == ID::split_LowerZoneMidiOut ? splitOptions->lowerZoneMidiOut() : splitOptions->upperZoneMidiOut() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingZoneMIDIout::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects whether the zone transmits and receives MIDI\n";
		tooltipText += "messages on the basic channel (set in MASTER).\n";
		tooltipText += "NOTE: Changes made to split parameters are not\n";
		tooltipText += "sent to the hardware until you SAVE the split in\n";
		tooltipText += "one of the storage bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingZoneMIDIout::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingZoneMIDIout::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingZoneMIDIout::~ComboBoxForSelectingZoneMIDIout() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}