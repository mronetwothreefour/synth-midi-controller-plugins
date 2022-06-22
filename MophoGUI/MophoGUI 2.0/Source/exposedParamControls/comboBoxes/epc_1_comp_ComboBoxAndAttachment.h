#pragma once

#include <JuceHeader.h>

#include "../epc_0_comp_TooltipUpdaterForExposedParamControl.h"

using ComboBoxAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;
using ExposedParameters = AudioProcessorValueTreeState;




class ComboBoxAndAttachment : 
	public Component
{
protected:
	uint8 paramIndex;
	ComboBox comboBox;
	ExposedParameters* exposedParams;
	std::unique_ptr<ComboBoxAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;

public:
	ComboBoxAndAttachment() = delete;

	ComboBoxAndAttachment(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void attachComboBoxToExposedParameter();
	void deleteAttachmentBeforeComboBoxToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxAndAttachment)
};