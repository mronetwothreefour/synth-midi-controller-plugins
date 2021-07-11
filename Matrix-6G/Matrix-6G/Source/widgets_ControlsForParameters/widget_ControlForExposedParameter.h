#pragma once

#include <JuceHeader.h>

#include "../widgets_ComboBox/widget_ComboBoxWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_RotarySliderForPitchWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_RotarySliderWithExposedParamAttacher.h"
#include "../widgets_Slider/widget_LinearSliderWithExposedParamAttacher.h"



enum class ControlType;

class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<ComboBoxWithExposedParamAttacher> comboBox;
	std::unique_ptr<LinearSliderWithExposedParamAttacher> linearSlider;
	std::unique_ptr<RotarySliderWithExposedParamAttacher> rotarySlider;
	std::unique_ptr<RotarySliderForPitchWithExposedParamAttacher> rotarySliderForPitch;

	ControlForExposedParameter();

public:
	ControlForExposedParameter(uint8 param, UnexposedParameters* unexposedParams);

private:
	void buildComboBoxControlForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildLinearSliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildRotarySliderForExposedParam(uint8 param, UnexposedParameters* unexposedParams);
	void buildRotarySliderForExposedPitchParam(uint8 param, UnexposedParameters* unexposedParams);

public:
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const;
	void deleteAttachment() const;
	~ControlForExposedParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

