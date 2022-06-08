#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class VoicesBanks :
	public ValueTree::Listener
{
	ValueTree customBank_1_VoiceDataHexStrings;
	ValueTree customBank_2_VoiceDataHexStrings;
	ValueTree customBank_3_VoiceDataHexStrings;
	ValueTree factoryBank_1_VoiceNameStrings;
	ValueTree factoryBank_2_VoiceNameStrings;
	ValueTree factoryBank_3_VoiceNameStrings;
	ValueTree customBank_1_VoiceNameStrings;
	ValueTree customBank_2_VoiceNameStrings;
	ValueTree customBank_3_VoiceNameStrings;

public:
	VoicesBanks();

private:
	void fillAllCustomVoiceDataBanks();
	void fillAllVoiceNameBanks();

public:
	const String nameOfVoiceInBankSlot(VoicesBank bank, uint8 slot);
	const String getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slot) const;

private:
	const String extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector);

public:
	void storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slot);
	void addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank);
	void removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~VoicesBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBanks)
};