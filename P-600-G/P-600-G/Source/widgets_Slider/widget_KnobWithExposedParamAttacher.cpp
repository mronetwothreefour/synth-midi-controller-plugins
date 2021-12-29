#include "widget_KnobWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



KnobWithExposedParamAttacher::KnobWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
	slider.setComponentID(ID::component_Knob.toString());
}

void KnobWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void KnobWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
