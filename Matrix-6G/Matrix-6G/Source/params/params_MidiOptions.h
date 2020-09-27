#pragma once

#include <JuceHeader.h>



class MidiOptions
{
	ValueTree midiOptionsTree;

public:
	MidiOptions();

private:
	void fillMidiOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};