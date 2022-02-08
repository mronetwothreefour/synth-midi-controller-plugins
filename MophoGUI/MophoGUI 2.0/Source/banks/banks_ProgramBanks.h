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

public:
	ProgramBanks();

private:
	void fillAllCustomProgramDataBanks();
	void fillAllProgramNameBanks();

public:
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