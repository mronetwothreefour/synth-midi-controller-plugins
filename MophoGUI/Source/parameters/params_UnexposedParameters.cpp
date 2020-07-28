#include "params_UnexposedParameters.h"



TooltipOptions_Singleton::TooltipOptions_Singleton() :
	tooltipOptionsTree{ ID::tooltips_Options }
{
	addTooltipOptionsProperties();
}

TooltipOptions_Singleton::~TooltipOptions_Singleton() {
}

void TooltipOptions_Singleton::addTooltipOptionsProperties() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
}

TooltipOptions_Singleton& TooltipOptions_Singleton::get() {
	static TooltipOptions_Singleton tooltipOptions_Singleton;
	return tooltipOptions_Singleton;
}

void TooltipOptions_Singleton::addListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.addListener(listener);
}

void TooltipOptions_Singleton::removeListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.removeListener(listener);
}

bool TooltipOptions_Singleton::shouldShowCurrentValue() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentValue);
}

bool TooltipOptions_Singleton::shouldShowDescription() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowDescription);
}

void TooltipOptions_Singleton::setShouldShowCurrentValue() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
}

void TooltipOptions_Singleton::setShouldNotShowCurrentValue() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)false, nullptr);
}

void TooltipOptions_Singleton::setShouldShowDescription() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
}

void TooltipOptions_Singleton::setShouldNotShowDescription() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)false, nullptr);
}

int TooltipOptions_Singleton::delayInMilliseconds() {
	return (int)tooltipOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipOptions_Singleton::setDelayInMilliseconds(int newDelay) {
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}


//================================================================================


MidiParameters_Singleton::MidiParameters_Singleton() :
	midiParametersTree{ ID::midi_Parameters }
{
	addMidiParametersProperties();
}

MidiParameters_Singleton::~MidiParameters_Singleton() {
}

void MidiParameters_Singleton::addMidiParametersProperties() {
	midiParametersTree.setProperty(ID::midi_Channel, (uint8)0, nullptr);
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

MidiParameters_Singleton& MidiParameters_Singleton::get() {
	static MidiParameters_Singleton midiParameters_Singleton;
	return midiParameters_Singleton;
}

void MidiParameters_Singleton::addListener(ValueTree::Listener* listener) {
	midiParametersTree.addListener(listener);
}

void MidiParameters_Singleton::removeListener(ValueTree::Listener* listener) {
	midiParametersTree.removeListener(listener);
}

uint8 MidiParameters_Singleton::channel() {
	return (uint8)(int)midiParametersTree.getProperty(ID::midi_Channel);
}

void MidiParameters_Singleton::setChannel(uint8 newChannel) {
	midiParametersTree.setProperty(ID::midi_Channel, newChannel, nullptr);
}

bool MidiParameters_Singleton::paramChangeEchosAreNotBlocked() {
	return !(bool)midiParametersTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void MidiParameters_Singleton::setParamChangeEchosAreBlocked() {
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void MidiParameters_Singleton::setParamChangeEchosAreNotBlocked() {
	midiParametersTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

