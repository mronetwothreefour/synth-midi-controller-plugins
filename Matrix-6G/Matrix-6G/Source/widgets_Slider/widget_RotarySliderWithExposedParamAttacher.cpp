#include "widget_RotarySliderWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"



RotarySliderWithExposedParamAttacher::RotarySliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams }
{
	addAndMakeVisible(slider);
	auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
	auto ctrlHeight{ 20 };
	setSize(ctrlWidth, ctrlHeight);
	slider.setSize(ctrlWidth, ctrlHeight);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
}

void RotarySliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void RotarySliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
