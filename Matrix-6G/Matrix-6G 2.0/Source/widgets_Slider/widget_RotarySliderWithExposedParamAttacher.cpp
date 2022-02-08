#include "widget_RotarySliderWithExposedParamAttacher.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"

using namespace constants;



RotarySliderWithExposedParamAttacher::RotarySliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
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

void RotarySliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void RotarySliderWithExposedParamAttacher::paint(Graphics& g) {
	auto currentValue{ (int8)roundToInt(slider.getValue()) };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

void RotarySliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}

