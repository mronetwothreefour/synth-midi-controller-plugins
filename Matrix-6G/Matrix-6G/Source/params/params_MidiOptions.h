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
	const uint8 basicChannel();
	void setBasicChannel(uint8 newChannel);
	bool incomingPatchShouldBeSavedInCustomBankA();
	void setIncomingPatchShouldBeSavedInCustomBankA();
	void setIncomingPatchShouldNotBeSavedInCustomBankA();
	bool incomingPatchShouldBeSavedInCustomBankB();
	void setIncomingPatchShouldBeSavedInCustomBankB();
	void setIncomingPatchShouldNotBeSavedInCustomBankB();
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	const int patchTransmitTime();
	void setPatchTransmitTime(int timeInMilliseconds);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};