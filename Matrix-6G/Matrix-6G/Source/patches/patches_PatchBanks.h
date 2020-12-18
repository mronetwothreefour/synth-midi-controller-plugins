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
	const String basicPatchDataHexString{ "000D000100040102010900080106030700000000000F010F010300020000000F0108010300010002000F0100000000020000000000070300000000020000000F0300000000000008020000000000000000090000000E010000000000000000090000000000000000000A0002030A000802000000000000000000000A0002030A00080200000000000000000000040100000401080200000000090000000F000F010F020F03000000000000000000000000000000000A02000000000F030F030F030F030F030F03000000000000000000000101000000010101000005010B00000009000401000008000000000000000000000000000000000000000000000000000000000000000000000000006" };
	const String basicPatchNameString{ "MATRIX6G" };

public:
	PatchBanks();

private:
	void fillAllCustomPatchDataBanks();
	void fillAllPatchNameBanks();

public:
	int patchSlotOutOfRange();
	const String nameOfPatchInBankSlot(PatchBank bank, uint8 slot);
	const String getPatchDataHexStringFromBankSlot(PatchBank bank, uint8 slot) const;

private:
	const String extractPatchNameFromDataVector(const std::vector<uint8>& dataVector);

public:
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