#pragma once

#include <JuceHeader.h>



enum class VoicesBank {
	factory1 = 0,
	factory2,
	factory3,
	custom1,
	custom2,
	custom3
};




class VoicesBanks :
	public ValueTree::Listener
{
	ValueTree customBank1VoiceDataHexStrings;
	ValueTree customBank2VoiceDataHexStrings;
	ValueTree customBank3VoiceDataHexStrings;
	ValueTree factoryBank1VoiceNameStrings;
	ValueTree factoryBank2VoiceNameStrings;
	ValueTree factoryBank3VoiceNameStrings;
	ValueTree customBank1VoiceNameStrings;
	ValueTree customBank2VoiceNameStrings;
	ValueTree customBank3VoiceNameStrings;

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