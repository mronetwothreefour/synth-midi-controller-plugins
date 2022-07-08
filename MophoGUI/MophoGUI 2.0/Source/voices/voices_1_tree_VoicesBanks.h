#pragma once

#include <JuceHeader.h>

#include "voices_0_tree_FactoryVoiceDataHexStrings.h"
#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class VoicesBanks :
	public ValueTree::Listener
{
	FactoryVoiceDataHexStrings factoryVoiceDataHexStrings;
	ValueTree factoryVoiceNameStrings;
	ValueTree customVoiceDataHexStrings;
	ValueTree customVoiceNameStrings;

public:
	VoicesBanks();
	const String nameOfVoiceInBankSlot(VoicesBank bank, uint8 slotNum);
	const String getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slotNum) const;

private:
	const String extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector);

public:
	void storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slotNum);
	void addListenerToCustomVoiceNameStringsTree(ValueTree::Listener* listener);
	void removeListenerFromCustomVoiceNameStringsTree(ValueTree::Listener* listener);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~VoicesBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBanks)
};