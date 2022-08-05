#include "widget_global_ComboBoxForSelectingVibratoWaveType.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingVibratoWaveType::ComboBoxForSelectingVibratoWaveType(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::global_VibratoWaveType }
{
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->addListener(this);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	StringArray choices;
	auto converter{ IntToLFOwaveTypeString::get() };
	for (uint8 i = 0; i != 6; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	auto paramValue{ globalOptions->vibratoWaveType() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingVibratoWaveType::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the modulation wave type for low-frequency oscillator 3,\n";
		tooltipText += "which is dedicated to vibrato.\n";
		tooltipText += "TRI: Triangle - a periodic wave that steadily rises and falls between\n";
		tooltipText += "its minimum and maximum values.\n";
		tooltipText += "UPSAW: Up (positive) sawtooth - a periodic wave that rises steadily\n";
		tooltipText += "to the maximum value then abruptly falls to the minimum value.\n";
		tooltipText += "DNSAW: Down (negative) sawtooth - a periodic wave that falls steadily\n";
		tooltipText += "to the minimum value then abruptly rises to the maximum value.\n";
		tooltipText += "SQUAR: Square - a periodic wave that switches abruptly between the\n";
		tooltipText += "minimum and maximum values.\n";
		tooltipText += "RANDM: Random - an aperiodic wave that outputs a series of random values.\n";
		tooltipText += "NOISE: Noise - a much faster version of the random waveform.\n";
		tooltipText += "NOTE: Individual Master options are not immediately updated on the\n";
		tooltipText += "hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToLFOwaveTypeString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingVibratoWaveType::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::global_VibratoWaveType) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingVibratoWaveType::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToLFOwaveTypeString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingVibratoWaveType::~ComboBoxForSelectingVibratoWaveType() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	globalOptions->removeListener(this);
}
