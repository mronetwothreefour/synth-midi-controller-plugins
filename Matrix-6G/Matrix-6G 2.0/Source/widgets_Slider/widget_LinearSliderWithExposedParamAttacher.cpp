#include "widget_LinearSliderWithExposedParamAttacher.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"

using namespace constants;



LinearSliderWithExposedParamAttacher::LinearSliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	addAndMakeVisible(slider);
	auto ctrlWidth{ InfoForExposedParameters::get().controlWidthFor(param) };
	setSize(ctrlWidth, GUI::controls_h);
	slider.setSize(ctrlWidth, GUI::controls_h);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
}

void LinearSliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void LinearSliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
