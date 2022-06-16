#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;




class InfoForExposedParameters
{
	ValueTree exposedParamsInfoTree;

	InfoForExposedParameters();
	void setDataByteLocationPropertiesForAllParams();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	uint8 NRPNfor(uint8 paramIndex) const;
	uint8 paramIndexForNRPN(const uint8 NRPN) const;
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
	uint16 msBitPackedByteLocationFor(uint8 paramIndex) const;
	uint8 msBitMaskFor(uint8 paramIndex) const;
	uint16 lsByteLocationFor(uint8 paramIndex) const;
	AllowedChoicesType allowedChoicesTypeFor(uint8 paramIndex) const;
	int numberOfAllowChoiceToggleColumnsFor(uint8 paramIndex) const;
	int widthOfAllowChoiceToggleColumnFor(uint8 paramIndex) const;
	int numberOfAllowChoiceToggleRowsFor(uint8 paramIndex) const;
	int firstAllowChoiceToggleRowFor(uint8 paramIndex) const;
	int allowedChoicesBackground_x_For(uint8 paramIndex) const;
	int allowedChoicesBackground_y_For(uint8 paramIndex) const;
	int seqTrackNum_For(uint8 paramIndex) const;
	int seqTrackStepNum_For(uint8 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};