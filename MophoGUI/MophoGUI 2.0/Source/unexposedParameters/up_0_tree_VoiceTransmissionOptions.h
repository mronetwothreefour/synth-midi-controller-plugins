#pragma once

#include <JuceHeader.h>

class VoiceTransmissionOptions
{
	ValueTree voiceTransmissionOptionsTree;

public:
	VoiceTransmissionOptions();
	const bool paramChangesShouldBeTransmitted();
	void dontTransmitParamChanges();
	void transmitParamChanges();
	const int voiceTransmitTime();
	void setVoiceTransmitTime(const int timeInMilliseconds);
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};
