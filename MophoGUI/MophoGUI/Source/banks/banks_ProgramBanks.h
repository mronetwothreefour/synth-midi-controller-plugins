#pragma once

#include <JuceHeader.h>

enum class ProgramBank {
	factory1 = 0,
	factory2,
	factory3,
	custom1,
	custom2,
	custom3
};

class ProgramBanks :
	public ValueTree::Listener
{
	ValueTree customBank1ProgramDataHexStrings;
	ValueTree customBank2ProgramDataHexStrings;
	ValueTree customBank3ProgramDataHexStrings;
	ValueTree factoryBank1ProgramNameStrings;
	ValueTree factoryBank2ProgramNameStrings;
	ValueTree factoryBank3ProgramNameStrings;
	ValueTree customBank1ProgramNameStrings;
	ValueTree customBank2ProgramNameStrings;
	ValueTree customBank3ProgramNameStrings;
	const String basicPatchDataHexString{ "00183101000100180033010001000000400204004000001400000000017F00000000000000007F00000000004040785000010000005001000000005001000000005001000000007F000000000000000000007F00007F0000007F00007F007F00007F007F007F007F00003C6400780200000000000101090000050B2B170000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000426173696300205061746368200020202020" };
	const String basicPatchNameString{ "Basic Patch     " };

public:
	ProgramBanks();

private:
	void fillAllCustomProgramDataBanks();
	void fillAllProgramNameBanks();

public:
	int programSlotOutOfRange();
	const String nameOfProgramInBankSlot(ProgramBank bank, uint8 slot);
	const String getProgramDataHexStringFromBankSlot(ProgramBank bank, uint8 slot) const;

private:
	const String extractProgramNameFromDataVector(const std::vector<uint8>& dataVector);

public:
	void storeProgramDataHexStringInCustomBankSlot(String programDataHexString, ProgramBank bank, uint8 slot);
	void addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, ProgramBank bank);
	void removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, ProgramBank bank);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~ProgramBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanks)
};