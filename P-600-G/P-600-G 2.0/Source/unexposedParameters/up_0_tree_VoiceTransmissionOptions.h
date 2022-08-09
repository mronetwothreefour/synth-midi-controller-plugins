#pragma once

#include <JuceHeader.h>

class VoiceTransmissionOptions
{
	ValueTree voiceTransmissionOptionsTree;

public:
	VoiceTransmissionOptions();
	const bool paramChangesShouldBeTransmitted();
	void setParamChangesShouldBeTransmitted(const bool shouldBeTransmitted);
	const int voiceTransmitTime();
	void setVoiceTransmitTime(const int timeInMilliseconds);
	const bool incomingVoiceShouldBeStored();
	void setIncomingVoiceShouldBeStored(const bool shouldBeStored);
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};
