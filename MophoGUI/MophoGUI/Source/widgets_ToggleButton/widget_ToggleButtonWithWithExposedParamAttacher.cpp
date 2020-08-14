#include "widget_ToggleButtonWithWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



ToggleButtonWithWithExposedParamAttacher::ToggleButtonWithWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	tooltipSetter{ toggle, param, unexposedParams }
{
	addAndMakeVisible(toggle);
	toggle.setComponentID(ID::component_ToggleButton.toString());
	auto ctrlWidth{ InfoForExposedParameters::get().ctrlWidthFor(param) };
	auto ctrlHeight{ InfoForExposedParameters::get().ctrlHeightFor(param) };
	setSize(ctrlWidth, ctrlHeight);
	toggle.setSize(ctrlWidth, ctrlHeight);
}

void ToggleButtonWithWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new ButtonAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), toggle));
}

void ToggleButtonWithWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

ToggleButtonWithWithExposedParamAttacher::~ToggleButtonWithWithExposedParamAttacher() {
}
