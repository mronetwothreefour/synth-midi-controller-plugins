#pragma once

#include <JuceHeader.h>



class ProgramDataBank
{
	ValueTree pgmDataHexStrings;

public:
	ProgramDataBank();

private:
	void fillPgmDataHexStrings();

public:
	int pgmSlotOutOfRange();
	const String nameOfPgmInSlot(uint8 slot);
	void setNameOfPgmInSlot(String newName, uint8 slot);
	const String getPgmDataHexStringFromSlot(uint8 slot) const;
	void storePgmDataHexStringInSlot(String pgmDataHexString, uint8 slot);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBank)
};