#pragma once

#include <JuceHeader.h>



class SplitOptions
{
	ValueTree splitOptionsTree;

public:
	SplitOptions();

private:
	void fillSplitOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const String splitName();
	void setSplitName(String newName);
	const uint8 zoneVoiceAssignment();
	void setZoneVoiceAssignment(uint8 newValue);
	const uint8 zoneVolumeBalance();
	void setZoneVolumeBalance(uint8 newValue);
	const uint8 lowerZoneLimit();
	void setLowerZoneLimit(uint8 newValue);
	const uint8 lowerZonePatchNumber();
	void setLowerZonePatchNumber(uint8 newValue);	
	const uint8 lowerZoneTranspose();
	void setLowerZoneTranspose(uint8 newValue);
	const uint8 lowerZoneMidiOut();
	void setLowerZoneMidiOut(uint8 newValue);
	const uint8 upperZoneLimit();
	void setUpperZoneLimit(uint8 newValue);
	const uint8 upperZonePatchNumber();
	void setUpperZonePatchNumber(uint8 newValue);
	const uint8 upperZoneTranspose();
	void setUpperZoneTranspose(uint8 newValue);
	const uint8 upperZoneMidiOut();
	void setUpperZoneMidiOut(uint8 newValue);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitOptions)
};