#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

using ComboBoxAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;

class ComboBoxAndAttachment :
	public Component
{
protected:
	const uint8 paramIndex;
	ComboBox comboBox;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	std::unique_ptr<ComboBoxAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	const int comboBox_w;

public:
	ComboBoxAndAttachment() = delete;

	ComboBoxAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void attachComboBoxToExposedParameter();
	void deleteAttachmentBeforeComboBoxToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxAndAttachment)
};