#include "widget_master_ComboBoxForSelectingVibratoModSource.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingVibratoModSource::ComboBoxForSelectingVibratoModSource(UnexposedParameters* unexposedParams, const Identifier& propertyID) :
	unexposedParams{ unexposedParams },
	propertyID{ propertyID }
{
	jassert(propertyID == ID::global_VibratoAmplitudeModSource || propertyID == ID::global_VibratoSpeedModSource);
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->addListener(this);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	StringArray choices;
	auto converter{ IntToVibratoModSource::get() };
	for (uint8 i = 0; i != 3; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ propertyID == ID::global_VibratoAmplitudeModSource ? masterOptions->vibratoAmplitudeModSource() : masterOptions->vibratoSpeedModSource() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingVibratoModSource::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the source for modulating the\n";
		tooltipText += propertyID == ID::global_VibratoAmplitudeModSource ? "amplitude" : "speed";
		tooltipText += " of low-frequency oscillator 3,\n";
		tooltipText += "which is dedicated to vibrato.\n";
		tooltipText += "Options: Off (no modulation), Lever 2,\n";
		tooltipText += "or Pedal 1. NOTE: Individual Master\n";
		tooltipText += "options are not immediately updated\n";
		tooltipText += "on the hardware. Click the PUSH button\n";
		tooltipText += "to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToVibratoModSource::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingVibratoModSource::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == propertyID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingVibratoModSource::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToVibratoModSource::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingVibratoModSource::~ComboBoxForSelectingVibratoModSource() {
	auto masterOptions{ unexposedParams->globalOptions_get() };
	masterOptions->removeListener(this);
}