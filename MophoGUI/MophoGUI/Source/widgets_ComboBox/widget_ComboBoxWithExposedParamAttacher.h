#pragma once

#include <JuceHeader.h>

#include "../tooltipSetters/tooltipSetter_ForExposedParamComboBoxes.h"

using ComboBoxAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;



class ComboBoxWithExposedParamAttacher : public Component
{
protected:
	ComboBox comboBox;
	std::unique_ptr<ComboBoxAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamComboBoxes tooltipSetter;

public:
	ComboBoxWithExposedParamAttacher() = delete;

	ComboBoxWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxWithExposedParamAttacher)
};