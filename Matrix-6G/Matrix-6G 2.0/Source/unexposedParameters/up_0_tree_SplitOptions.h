#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class SplitOptions
{
	ValueTree splitOptionsTree;

public:
	SplitOptions();

	const String splitName();
	void setSplitName(const String newName);

	const SplitZoneVoiceAssignment zoneVoiceAssignment();
	void setZoneVoiceAssignment(const SplitZoneVoiceAssignment newAssignment);

	const uint8 zoneVolumeBalance();
	void setZoneVolumeBalance(const uint8 newBalance);

	const uint8 zoneLimit(SplitZone zone);
	void setZoneLimit(SplitZone zone, const uint8 newLimit);

	const uint8 zoneVoiceNumber(SplitZone zone);
	void setZoneVoiceNumber(SplitZone zone, const uint8 newVoiceNum);

	const uint8 zoneTranspose(SplitZone zone);
	void setZoneTranspose(SplitZone zone, const uint8 newTranspose);

	const bool zoneMidiOutIsEnabled(SplitZone zone);
	void setZoneMidiOutIsEnabled(SplitZone zone, const bool shouldBeEnabled);

	Value getSplitParamAsValue(const Identifier paramID);

	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitOptions)
};