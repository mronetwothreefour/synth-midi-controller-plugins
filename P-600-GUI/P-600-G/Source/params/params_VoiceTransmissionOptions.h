#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class VoiceTransmissionOptions
{
	UnexposedParameters* unexposedParams;
	ValueTree voiceTransmissionOptionsTree;

public:
	VoiceTransmissionOptions() = delete;

	explicit VoiceTransmissionOptions(UnexposedParameters* unexposedParams);

private:
	void fillVoiceTransmissionOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 currentVoiceNumber();
	void setCurrentVoiceNumber(uint8 newNumber);
	bool paramChangeEchoesAreNotBlocked();
	void setParamChangeEchoesAreBlocked();
	void setParamChangeEchoesAreNotBlocked();
	const int voiceTransmitTime();
	void setVoiceTransmitTime(int timeInMilliseconds);
	bool incomingVoiceShouldBeSavedInVoicesBank();
	void setIncomingVoiceShouldBeSavedInVoicesBank();
	void setIncomingVoiceShouldNotBeSavedInVoicesBank();
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};