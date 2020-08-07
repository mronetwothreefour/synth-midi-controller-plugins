#pragma once

#include <JuceHeader.h>



class MidiOptions
{
	ValueTree midiParametersTree;

	MidiOptions();
	~MidiOptions();

	void fillMidiOptionsTreeWithProperties();

public:
	MidiOptions(MidiOptions&&) = delete;
	MidiOptions& operator=(MidiOptions&&) = delete;

	static MidiOptions& get();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	uint8 channel();
	void setChannel(uint8 newChannel);
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};
