#pragma once

#include <JuceHeader.h>

#include "voices_0_tree_FactoryVoiceDataHexStrings.h"

class VoicesBank
{
	const FactoryVoiceDataHexStrings factoryVoiceDataHexStrings;
	ValueTree voiceDataHexStrings;

public:
	VoicesBank();
	const String nameOfVoiceInSlot(const uint8 slotNum) const;
	void setNameOfVoiceInSlot(const String newName, const uint8 slotNum);
	const String getVoiceDataHexStringFromSlot(const uint8 slotNum) const;
	const String getVoiceDataHexStringWithoutNameFromSlot(const uint8 slotNum) const;
	void storeVoiceDataHexStringInSlot(const String voiceDataHexString, const uint8 slotNum);
	Value getVoiceDataHexStringAsValueForSlot(const uint8 slotNum);
	void restoreFactoryVoicesBank();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBank)
};