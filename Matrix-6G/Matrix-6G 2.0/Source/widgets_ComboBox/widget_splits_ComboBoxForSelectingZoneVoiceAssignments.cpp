#include "widget_splits_ComboBoxForSelectingZoneVoiceAssignments.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingZoneVoiceAssignments::ComboBoxForSelectingZoneVoiceAssignments(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::split_ZoneVoiceAssignment }
{
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	StringArray choices;
	auto converter{ IntToZoneVoiceAssignment::get() };
	for (uint8 i = 0; i != 4; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ splitOptions->zoneVoiceAssignment() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingZoneVoiceAssignments::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects how the hardware's six voices are distributed\n";
		tooltipText += "between the lower and upper zones. Options where\n";
		tooltipText += "one of the zones is assigned no voices are intended\n";
		tooltipText += "for playing the Matrix-6R and another MIDI device\n";
		tooltipText += "with a single controller. Make sure MIDI Out is on\n";
		tooltipText += "for the zone that targets the additional device.\n";
		tooltipText += "NOTE: Changes made to split parameters are not\n";
		tooltipText += "sent to the hardware until you SAVE the split in\n";
		tooltipText += "one of the storage bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToZoneVoiceAssignment::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingZoneVoiceAssignments::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingZoneVoiceAssignments::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToZoneVoiceAssignment::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingZoneVoiceAssignments::~ComboBoxForSelectingZoneVoiceAssignments() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
