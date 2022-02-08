#pragma once

#include <JuceHeader.h>



class SplitsBank :
	public ValueTree::Listener
{
	ValueTree splitsDataHexStrings;
	ValueTree splitsNameStrings;

public:
	SplitsBank();

private:
	void fillSplitsHexDataStrings();
	void fillSplitsNameStrings();

public:
	int splitSlotOutOfRange();
	const String nameOfSplitInSlot(uint8 slot);
	const String getSplitDataHexStringFromSlot(uint8 slot) const;
	void storeSplitDataHexStringInSlot(String splitDataHexString, uint8 slot);
	void addListenerToSplitsNameStrings(ValueTree::Listener* listener);
	void removeListenerFromSplitsNameStrings(ValueTree::Listener* listener);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~SplitsBank();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsBank)
};