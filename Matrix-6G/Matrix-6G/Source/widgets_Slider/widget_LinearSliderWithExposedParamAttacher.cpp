#include "widget_LinearSliderWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"



LinearSliderWithExposedParamAttacher::LinearSliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	addAndMakeVisible(slider);
	auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
	auto ctrlHeight{ 20 };
	setSize(ctrlWidth, ctrlHeight);
	slider.setSize(ctrlWidth, ctrlHeight);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
}

void LinearSliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void LinearSliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
