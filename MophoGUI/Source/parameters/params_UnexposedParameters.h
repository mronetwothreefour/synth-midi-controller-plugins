#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"


// TODO make tooltipOptionsTree with public 
class TooltipOptions_Singleton
{
	ValueTree tooltipOptionsTree;

	TooltipOptions_Singleton();
	~TooltipOptions_Singleton();

	void addTooltipOptionsProperties();

public:
	TooltipOptions_Singleton(TooltipOptions_Singleton&&) = delete;
	TooltipOptions_Singleton& operator=(TooltipOptions_Singleton&&) = delete;

	static TooltipOptions_Singleton& get();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	bool shouldShowCurrentValue();
	bool shouldShowDescription();
	void setShouldShowCurrentValue();
	void setShouldNotShowCurrentValue();
	void setShouldShowDescription();
	void setShouldNotShowDescription();
	int delayInMilliseconds();
	void setDelayInMilliseconds(int newDelay);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions_Singleton)
};



class MidiParameters_Singleton
{
	ValueTree midiParametersTree;

	MidiParameters_Singleton();
	~MidiParameters_Singleton();

	void addMidiParametersProperties();

public:
	MidiParameters_Singleton(MidiParameters_Singleton&&) = delete;
	MidiParameters_Singleton& operator=(MidiParameters_Singleton&&) = delete;

	static MidiParameters_Singleton& get();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	uint8 channel();
	void setChannel(uint8 newChannel);
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiParameters_Singleton)
};
