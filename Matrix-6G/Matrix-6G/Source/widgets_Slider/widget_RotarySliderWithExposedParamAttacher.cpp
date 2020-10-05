#include "widget_RotarySliderWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



RotarySliderWithExposedParamAttacher::RotarySliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
}

void RotarySliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void RotarySliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
