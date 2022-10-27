#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

class SplitOptions;
class TooltipsOptions;
class UnexposedParameters;

class ComboBoxForSplitParameter :
	public ComboBox
{
	SplitParamComboBoxType comboBoxType;
	SplitOptions* splitOptions;
	TooltipsOptions* tooltips;
	Value splitParamAsValue;

public:
	ComboBoxForSplitParameter() = delete;

	ComboBoxForSplitParameter(SplitParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged(Value& value) override;
	~ComboBoxForSplitParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSplitParameter)
};