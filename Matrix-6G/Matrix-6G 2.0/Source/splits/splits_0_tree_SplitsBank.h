#pragma once

#include <JuceHeader.h>

class SplitsBank :
	public ValueTree::Listener
{
	ValueTree splitDataHexStrings;
	ValueTree splitNameStrings;

public:
	SplitsBank();
	const String nameOfSplitInSlot(const uint8 slotNum) const;
	const String getSplitDataHexStringFromSlot(const uint8 slotNum) const;

private:
	const String extractSplitNameFromDataVector(const std::vector<uint8>& dataVector);

public:
	void storeSplitDataHexStringInSlot(const String splitDataHexString, const uint8 slotNum);
	Value getSplitNameAsValueForSlot(const uint8 slotNum);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~SplitsBank();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsBank)
};