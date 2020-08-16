#pragma once

#include <JuceHeader.h>



class MidiOptions
{
	ValueTree midiParametersTree;

public:
	MidiOptions();

private:
	void fillMidiOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	uint8 channel();
	void setChannel(uint8 newChannel);
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	int programTransmitTime();
	void setProgramTransmitTime(int timeInMilliseconds);
	~MidiOptions();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};
