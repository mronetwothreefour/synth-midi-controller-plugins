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

	explicit ComboBoxWithExposedParamAttacher(uint8 param) :
		param{ param },
		tooltipSetter{ comboBox, param }
	{
		StringArray choices;
		auto converter{ InfoForExposedParameters::get().converterFor(param) };
		for (uint8 i = 0; i != InfoForExposedParameters::get().numberOfStepsFor(param); ++i) {
			choices.add(converter->verboseConvert(i));
		}
		comboBox.addItemList(choices, 1);
		addAndMakeVisible(comboBox);
		auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		comboBox.setSize(ctrlWidth, ctrlHeight);
	}

	~ComboBoxWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {

		attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), comboBox));
	}

	void deleteAttachment() {
		attachment = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxWithExposedParamAttacher)
};