#pragma once

#include <JuceHeader.h>



enum class VoicesBank {
	analogSynthsA = 0,
	analogSynthsB,
	basses,
	brassAndWoodwinds,
	customA,
	customB,
	fxAndPercussion,
	keyboardsA,
	keyboardsB,
	leads,
	miscellaneousA,
	miscellaneousB,
	strings
};



class VoicesBanks :
	public ValueTree::Listener
{
	ValueTree analogSynthsBankAvoiceNameStrings;
	ValueTree analogSynthsBankBvoiceNameStrings;
	ValueTree bassesBankVoiceNameStrings;
	ValueTree brassAndWoodwindsBankVoiceNameStrings;
	ValueTree customBankAvoiceDataHexStrings;
	ValueTree customBankBvoiceDataHexStrings;
	ValueTree customBankAvoiceNameStrings;
	ValueTree customBankBvoiceNameStrings;
	ValueTree fxAndPercussionBankVoiceNameStrings;
	ValueTree keyboardsBankAvoiceNameStrings;
	ValueTree keyboardsBankBvoiceNameStrings;
	ValueTree leadsBankVoiceNameStrings;
	ValueTree miscellaneousBankAvoiceNameStrings;
	ValueTree miscellaneousBankBvoiceNameStrings;
	ValueTree stringsBankVoiceNameStrings;

public:
	VoicesBanks();

private:
	void fillAllCustomVoiceDataBanks();
	void fillAllVoiceNameBanks();

public:
	int slotOutOfRange();
	const String nameOfVoiceInBankSlot(VoicesBank bank, uint8 slot);
	const String getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slot) const;
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