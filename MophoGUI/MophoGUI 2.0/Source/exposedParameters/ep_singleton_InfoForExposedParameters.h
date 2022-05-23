#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;




class InfoForExposedParameters
{
	ValueTree exposedParamsInfoTree;

public:
	InfoForExposedParameters();
	void fillExposedParamsInfoTree();

	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	uint8 NRPNfor(uint8 paramIndex) const;
	uint8 numberOfChoicesFor(uint8 paramIndex) const;
	uint8 lastChoiceFor(uint8 paramIndex) const;
	uint8 defaultChoiceFor(uint8 paramIndex) const;
	Point<int> centerPointFor(uint8 paramIndex) const;
	int widthFor(uint8 paramIndex) const;
	int heightFor(uint8 paramIndex) const;
	String choiceNameFor(uint8 choiceNum, uint8 paramIndex) const;
	String verboseChoiceNameFor(uint8 choiceNum, uint8 paramIndex) const;
	StringArray choiceNamesListFor(uint8 paramIndex) const;
	StringArray verboseChoiceNamesListFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	int mouseDragSensitivityFor(uint8 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};