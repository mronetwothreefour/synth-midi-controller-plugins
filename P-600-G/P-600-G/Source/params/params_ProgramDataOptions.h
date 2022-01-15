#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ProgramDataOptions
{
	UnexposedParameters* unexposedParams;
	ValueTree programDataOptionsTree;

public:
	ProgramDataOptions() = delete;

	explicit ProgramDataOptions(UnexposedParameters* unexposedParams);

private:
	void fillCurrentProgramOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 currentProgramNumber();
	void setCurrentProgramNumber(uint8 newNumber);
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	const int programTransmitTime();
	void setProgramTransmitTime(int timeInMilliseconds);
	bool incomingPgmDataDumpShouldBeSavedInStorageBank();
	void setIncomingPgmDataDumpShouldBeSavedInStorageBank();
	void setIncomingPgmDataDumpShouldNotBeSavedInStorageBank();
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataOptions)
};