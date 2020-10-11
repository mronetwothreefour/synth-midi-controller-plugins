#pragma once

#include <JuceHeader.h>

#include "../widgets_ComboBox/widget_ComboBoxWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_RotarySliderWithExposedParamAttacher.h"



enum class ControlType;

class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<RotarySliderWithExposedParamAttacher> rotarySlider;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams);

private:
	void buildRotarySliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildComboBoxControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};
