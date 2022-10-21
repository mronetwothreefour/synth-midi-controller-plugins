#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using ComboBoxType = GlobalParamComboBoxType;

class GlobalOptions;
class UnexposedParameters;

class ComboBoxForGlobalParameter :
	public ComboBox
{
	ComboBoxType comboBoxType;
	Value globalParamAsValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;
	const bool disabled{ false };
	const bool enabled{ true };

public:
	ComboBoxForGlobalParameter() = delete;

	ComboBoxForGlobalParameter(ComboBoxType comboBoxType, UnexposedParameters* unexposedParams);
	StringArray choiceNamesList_OffOn();
	StringArray choiceNamesList_VibratoWaveType();
	StringArray choiceNamesList_VibratoModSource();
	void updateTooltip();
	void valueChanged(Value& value) override;
	~ComboBoxForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForGlobalParameter)
};