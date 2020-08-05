#pragma once

#include <JuceHeader.h>

#include "widget_TooltipSetter.h"



class TooltipSetterForExposedParamComboBoxes :
	public TooltipSetter,
	public ComboBox::Listener
{
	ComboBox& comboBox;
	uint8 param;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamComboBoxes() = delete;

	TooltipSetterForExposedParamComboBoxes(ComboBox& comboBox, uint8 param);
	~TooltipSetterForExposedParamComboBoxes();
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

private:
	void setTooltip() noexcept override;
	String generateTooltipText() noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamComboBoxes)
};

