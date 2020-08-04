#include "widget_ToggleButtonWithWithExposedParamAttacher.h"



ToggleButtonWithWithExposedParamAttacher::ToggleButtonWithWithExposedParamAttacher(uint8 param) :
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

ToggleButtonWithWithExposedParamAttacher::~ToggleButtonWithWithExposedParamAttacher() {
}

void ToggleButtonWithWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ButtonAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), toggle));
}

void ToggleButtonWithWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
