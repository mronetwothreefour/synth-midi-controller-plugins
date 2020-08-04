#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "widget_TooltipSetters.h"

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

	explicit ComboBoxWithExposedParamAttacher(uint8 param);
	~ComboBoxWithExposedParamAttacher();
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxWithExposedParamAttacher)
};