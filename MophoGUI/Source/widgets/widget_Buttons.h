#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_Identifiers.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "widget_TooltipSetters.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;



class ToggleButtonWithWithExposedParamAttacher : public Component
{
protected:
	ToggleButton toggle;
	std::unique_ptr<ButtonAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamToggles tooltipSetter;

public:
	ToggleButtonWithWithExposedParamAttacher() = delete;

	explicit ToggleButtonWithWithExposedParamAttacher(uint8 param) :
		param{ param },
		tooltipSetter{ toggle, param }
	{
		addAndMakeVisible(toggle);
		toggle.setComponentID(ID::component_ToggleButton.toString());
		auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
		auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
		setSize(ctrlWidth, ctrlHeight);
		toggle.setSize(ctrlWidth, ctrlHeight);
	}

	~ToggleButtonWithWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		attachment.reset(new ButtonAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), toggle));
	}

	void deleteAttachment() {
		attachment = nullptr;
	}
};