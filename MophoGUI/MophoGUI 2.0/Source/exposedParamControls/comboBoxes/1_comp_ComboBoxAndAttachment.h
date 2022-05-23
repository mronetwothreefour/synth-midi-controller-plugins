#pragma once

#include <JuceHeader.h>

#include "../0_comp_TooltipUpdaterForExposedParamControl.h"

using ComboBoxAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;



class ComboBoxAndAttachment : 
	public Component
{
protected:
	uint8 paramIndex;
	ComboBox comboBox;
	AudioProcessorValueTreeState* exposedParams;
	std::unique_ptr<ComboBoxAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;

public:
	ComboBoxAndAttachment() = delete;

	ComboBoxAndAttachment(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void attachComboBoxToExposedParameter();
	void deleteAttachmentBeforeComboBoxToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxAndAttachment)
};