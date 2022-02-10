#pragma once

#include <JuceHeader.h>



class VoiceTransmissionOptions
{
	ValueTree voiceTransmissionOptionsTree;

public:
	VoiceTransmissionOptions();

private:
	void fillVoiceTransmissionOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	bool incomingVoiceShouldBeSavedInCustomBankA();
	bool incomingVoiceShouldBeSavedInCustomBankB();
	void setIncomingVoiceShouldBeSavedInCustomBankA();
	void setIncomingVoiceShouldBeSavedInCustomBankB();
	void setIncomingVoiceShouldNotBeSavedInCustomBank();
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	const int voiceTransmitTime();
	void setVoiceTransmitTime(int timeInMilliseconds);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};