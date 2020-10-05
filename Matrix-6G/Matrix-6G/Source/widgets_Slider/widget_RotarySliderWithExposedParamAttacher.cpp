#include "widget_RotarySliderWithExposedParamAttacher.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../gui/gui_Colors.h"
#include "../guiRenderers/guiRenderer_ControlValue.h"



RotarySliderWithExposedParamAttacher::RotarySliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	slider.addListener(this);
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

void RotarySliderWithExposedParamAttacher::sliderValueChanged(Slider* sliderThatChanged) {
	if (sliderThatChanged == &slider) {
		repaint();
	}
}

void RotarySliderWithExposedParamAttacher::paint(Graphics& g) {
	g.fillAll(Color::black);
	auto currentValue{ (int8)roundToInt(slider.getValue()) };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintLEDcharacters(valueString, g, this);
}

void RotarySliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
	slider.removeListener(this);
}

