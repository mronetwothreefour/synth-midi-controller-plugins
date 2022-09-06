#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class GlobalOptions;
class UnexposedParameters;

class ComboBoxForGlobalParameter :
	public ComboBox
{
	GlobalParamComboBoxType comboBoxType;
	Identifier paramID;
	GlobalOptions* global;
	Value globalParamAsValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	ComboBoxForGlobalParameter() = delete;

	ComboBoxForGlobalParameter(GlobalParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged(Value& value) override;
	~ComboBoxForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForGlobalParameter)
};