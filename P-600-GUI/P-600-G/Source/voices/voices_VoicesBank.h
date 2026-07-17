#pragma once

#include <JuceHeader.h>



class VoicesBank
{
	ValueTree voiceDataHexStrings;

public:
	VoicesBank();

private:
	void fillVoiceDataHexStrings();

public:
	int slotOutOfRange();
	void addListenerToVoiceDataHexStrings(ValueTree::Listener* listener);
	void removeListenerFromVoiceDataHexStrings(ValueTree::Listener* listener);
	const String nameOfVoiceInSlot(uint8 slot);
	void setNameOfVoiceInSlot(String newName, uint8 slot);
	const String getVoiceDataHexStringFromSlot(uint8 slot) const;
	void storeVoiceDataHexStringInSlot(String voiceDataHexString, uint8 slot);
	void restoreFactoryVoicesBank();
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBank)
};