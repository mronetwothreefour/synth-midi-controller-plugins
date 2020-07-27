#pragma once

#include <JuceHeader.h>


// TODO make tooltipOptionsTree with public 
struct TooltipOptions_Singleton
{
	TooltipOptions_Singleton() :
		tooltipOptionsTree{ ID::tooltips_Options }
	{
		addTooltipOptionsProperties();
	}

	~TooltipOptions_Singleton() {
	}

	void addTooltipOptionsProperties() {
		tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
		tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
		tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
	}

public:
	ValueTree tooltipOptionsTree;

	TooltipOptions_Singleton(TooltipOptions_Singleton&&) = delete;
	TooltipOptions_Singleton& operator=(TooltipOptions_Singleton&&) = delete;

	static ValueTree& get() {
		static TooltipOptions_Singleton tooltipOptions_Singleton;
		return tooltipOptions_Singleton.tooltipOptionsTree;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions_Singleton)
};



struct MidiParameters_Singleton
{
	MidiParameters_Singleton() :
		midiParametersTree{ ID::midi_Parameters }
	{
		addMidiParametersProperties();
	}

	~MidiParameters_Singleton() {
	}

	void addMidiParametersProperties() {
		midiParametersTree.setProperty(ID::midi_Channel, 0, nullptr);
		midiParametersTree.setProperty(ID::midi_ParamChangeEchoIsBlocked, (bool)false, nullptr);
	}

public:
	ValueTree midiParametersTree;

	MidiParameters_Singleton(MidiParameters_Singleton&&) = delete;
	MidiParameters_Singleton& operator=(MidiParameters_Singleton&&) = delete;

	static ValueTree& get() {
		static MidiParameters_Singleton midiParameters_Singleton;
		return midiParameters_Singleton.midiParametersTree;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiParameters_Singleton)
};
