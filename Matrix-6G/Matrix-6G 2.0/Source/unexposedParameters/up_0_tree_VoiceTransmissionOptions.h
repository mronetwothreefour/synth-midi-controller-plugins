#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

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
	const VoicesBank bankToStoreIn();
	void setIncomingVoiceShouldBeStoredInCustomBank(const VoicesBank bank);
	void setIncomingVoiceShouldNotBeStored();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceTransmissionOptions)
};
