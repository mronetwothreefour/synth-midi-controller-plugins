#pragma once

#include <JuceHeader.h>

class InfoForExposedParameters;

class ExposedParamsRandomizationOptions
{
	ValueTree randomizationOptionsTree;
	InfoForExposedParameters* info;

public:
	ExposedParamsRandomizationOptions() = delete;

	explicit ExposedParamsRandomizationOptions(InfoForExposedParameters* info);

	const bool transmitMethodIsQuickEdit();
	void setTransmitMethodIsQuickEdit(bool shouldBeQuickEdit);

	const bool paramIsLocked(uint8 paramIndex);
	const bool paramIsUnlocked(uint8 paramIndex);
	void setParamIsLocked(uint8 paramIndex, bool shouldBeLocked);
	Value getParamIsLockedAsValue(uint8 paramIndex);

	const bool choiceIsAllowedForParam(uint8 choiceNum, uint8 paramIndex);
	void setChoiceIsAllowedForParam(uint8 choiceNum, bool shouldBeAllowed, uint8 paramIndex);
	void clearAllowedChoicesForParam(uint8 paramIndex);
	void allowAllChoicesForParam(uint8 paramIndex);

private:
	void checkNumberOfChoicesAllowedForParam(uint8 paramIndex);


public:
	const bool onlyOneChoiceIsAllowedForParam(uint8 paramIndex);
	Value getOnlyOneChoiceIsAllowedForParamAsValue(uint8 paramIndex);
	const bool noChoiceIsAllowedForParam(uint8 paramIndex);

	const bool repeatChoicesAreAllowedForParam(uint8 paramIndex);
	const bool repeatChoicesAreForbiddenForParam(uint8 paramIndex);
	void setRepeatChoicesAreAllowedForParam(bool shouldBeAllowed, uint8 paramIndex);

	ValueTree getCopyOfAllowedChoicesTreeForParam(uint8 paramIndex);

	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationOptions)

};
