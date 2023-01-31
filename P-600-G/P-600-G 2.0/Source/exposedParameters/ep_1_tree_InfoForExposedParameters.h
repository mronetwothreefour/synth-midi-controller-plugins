#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace P_600_G_Constants;

class InfoForExposedParameters
{
	ValueTree exposedParamsInfoTree;

public:
	InfoForExposedParameters();
	Identifier IDfor(const uint8 paramIndex) const;
	String exposedNameFor(const uint8 paramIndex) const;
	ControlType controlTypeFor(const uint8 paramIndex) const;
	uint8 firstNybbleIndexFor(const uint8 paramIndex) const;
	uint8 firstBitIndexFor(const uint8 paramIndex) const;
	uint8 numberOfBitsFor(const uint8 paramIndex) const;
	uint8 numberOfChoicesFor(const uint8 paramIndex) const;
	uint8 defaultChoiceFor(const uint8 paramIndex) const;
	Point<int> centerPointFor(const uint8 paramIndex) const;
	int widthFor(const uint8 paramIndex) const;
	int heightFor(const uint8 paramIndex) const;
	String descriptionFor(const uint8 paramIndex) const;
	String choiceNameFor(const uint8 choiceNum, const uint8 paramIndex) const;
	String verboseChoiceNameFor(const uint8 choiceNum, const uint8 paramIndex) const;
	StringArray choiceNamesListFor(const uint8 paramIndex) const;
	StringArray verboseChoiceNamesListFor(const uint8 paramIndex) const;
	int mouseDragSensitivityFor(const uint8 paramIndex) const;
	int numberOfAllowChoiceToggleColumnsFor(const uint8 paramIndex) const;
	int widthOfAllowChoiceToggleColumnFor(const uint8 paramIndex) const;
	int numberOfAllowChoiceToggleRowsFor(const uint8 paramIndex) const;
	int allowedChoicesBackground_x_For(const uint8 paramIndex) const;
	int allowedChoicesBackground_y_For(const uint8 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};