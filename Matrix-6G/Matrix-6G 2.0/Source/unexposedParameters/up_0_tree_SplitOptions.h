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

	const uint8 lowerZoneLimit();
	void setLowerZoneLimit(const uint8 newLimit);

	const uint8 lowerZoneVoiceNumber();
	void setLowerZoneVoiceNumber(const uint8 newVoiceNum);

	const uint8 lowerZoneTranspose();
	void setLowerZoneTranspose(const uint8 newTranspose);

	const bool lowerZoneMidiOutIsEnabled();
	void setLowerZoneMidiOutIsEnabled(const bool shouldBeEnabled);

	const uint8 upperZoneLimit();
	void setUpperZoneLimit(const uint8 newLimit);

	const uint8 upperZoneVoiceNumber();
	void setUpperZoneVoiceNumber(const uint8 newVoiceNum);

	const uint8 upperZoneTranspose();
	void setUpperZoneTranspose(const uint8 newTranspose);

	const bool upperZoneMidiOutIsEnabled();
	void setUpperZoneMidiOutIsEnabled(const bool shouldBeEnabled);

	Value getSplitParamAsValue(const Identifier paramID);

	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitOptions)
};