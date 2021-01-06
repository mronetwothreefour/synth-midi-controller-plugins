#pragma once

#include <JuceHeader.h>



enum class PatchBank {
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



class PatchBanks :
	public ValueTree::Listener
{
	ValueTree analogSynthsBankApatchNameStrings;
	ValueTree analogSynthsBankBpatchNameStrings;
	ValueTree bassesBankPatchNameStrings;
	ValueTree brassAndWoodwindsBankPatchNameStrings;
	ValueTree customBankApatchDataHexStrings;
	ValueTree customBankBpatchDataHexStrings;
	ValueTree customBankApatchNameStrings;
	ValueTree customBankBpatchNameStrings;
	ValueTree fxAndPercussionBankPatchNameStrings;
	ValueTree keyboardsBankApatchNameStrings;
	ValueTree keyboardsBankBpatchNameStrings;
	ValueTree leadsBankPatchNameStrings;
	ValueTree miscellaneousBankApatchNameStrings;
	ValueTree miscellaneousBankBpatchNameStrings;
	ValueTree stringsBankPatchNameStrings;

public:
	PatchBanks();

private:
	void fillAllCustomPatchDataBanks();
	void fillAllPatchNameBanks();

public:
	int patchSlotOutOfRange();
	const String nameOfPatchInBankSlot(PatchBank bank, uint8 slot);
	const String getPatchDataHexStringFromBankSlot(PatchBank bank, uint8 slot) const;
	void storePatchDataHexStringInCustomBankSlot(String patchDataHexString, PatchBank bank, uint8 slot);
	void addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, PatchBank bank);
	void removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, PatchBank bank);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~PatchBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchBanks)
};