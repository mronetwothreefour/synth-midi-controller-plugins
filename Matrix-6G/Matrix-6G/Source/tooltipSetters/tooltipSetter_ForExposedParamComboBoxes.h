#pragma once

#include <JuceHeader.h>

#include "tooltipSetter_Base.h"
#include "../params/params_IntToContextualStringConverters.h"



class TooltipSetterForExposedParamComboBoxes :
	public TooltipSetter,
	public ComboBox::Listener
{
	ComboBox& comboBox;
	uint16 param;
	UnexposedParameters* unexposedParams;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamComboBoxes() = delete;

	TooltipSetterForExposedParamComboBoxes(ComboBox& comboBox, uint16 param, UnexposedParameters* unexposedParams);
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

private:
	void setTooltip() override;
	String generateTooltipText() override;

public:
	~TooltipSetterForExposedParamComboBoxes();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamComboBoxes)
};
