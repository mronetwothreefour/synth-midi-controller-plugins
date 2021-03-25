#pragma once

#include <JuceHeader.h>



class PatchTransmissionOptions
{
	ValueTree patchTransmissionOptionsTree;

public:
	PatchTransmissionOptions();

private:
	void fillPatchTransmissionOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	bool incomingPatchShouldBeSavedInCustomBankA();
	bool incomingPatchShouldBeSavedInCustomBankB();
	void setIncomingPatchShouldBeSavedInCustomBankA();
	void setIncomingPatchShouldBeSavedInCustomBankB();
	void setIncomingPatchShouldNotBeSavedInCustomBank();
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	const int patchTransmitTime();
	void setPatchTransmitTime(int timeInMilliseconds);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchTransmissionOptions)
};