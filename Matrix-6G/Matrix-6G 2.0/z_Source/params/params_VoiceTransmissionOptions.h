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
	bool incomingVoiceShouldBeSavedInCustomBankA();
	bool incomingVoiceShouldBeSavedInCustomBankB();
	void setIncomingVoiceShouldBeSavedInCustomBankA();
	void setIncomingVoiceShouldBeSavedInCustomBankB();
	void setIncomingVoiceShouldNotBeSavedInCustomBank();
	bool paramChangeEchoesAreNotBlocked();
	void setParamChangeEchoesAreBlocked();
	void setParamChangeEchoesAreNotBlocked();
	const int voiceTransmitTime();
	void setVoiceTransmitTime(int timeInMilliseconds);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};