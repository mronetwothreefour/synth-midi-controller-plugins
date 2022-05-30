#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class UnexposedParameters;

class ComboBoxForGlobalParameter :
	public ComboBox,
	public ValueTree::Listener
{
	GlobalParamComboBoxType comboBoxType;
	Identifier paramID;
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForGlobalParameter() = delete;

	ComboBoxForGlobalParameter(GlobalParamComboBoxType comboBoxType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ComboBoxForGlobalParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForGlobalParameter)

};