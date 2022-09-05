#pragma once

#include <JuceHeader.h>

#include "voices_0_tree_FactoryVoiceDataHexStrings.h"
#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class VoicesBanks :
	public ValueTree::Listener
{
	const FactoryVoiceDataHexStrings factoryVoiceDataHexStrings;
	ValueTree factoryVoiceNameStrings;
	ValueTree customVoiceDataHexStrings;
	ValueTree customVoiceNameStrings;

public:
	VoicesBanks();
	const String nameOfVoiceInBankSlot(const VoicesBank bank, const uint8 slotNum) const;
	const String getVoiceDataHexStringFromBankSlot(const VoicesBank bank, const uint8 slotNum) const;

private:
	const String extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector);

public:
	void storeVoiceDataHexStringInCustomBankSlot(const String voiceDataHexString, const VoicesBank bank, const uint8 slotNum);
	Value getVoiceNameAsValueForCustomBankSlot(const VoicesBank bank, const uint8 slotNum);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~VoicesBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBanks)
};