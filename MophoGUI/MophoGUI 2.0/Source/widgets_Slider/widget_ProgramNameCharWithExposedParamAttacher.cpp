#include "widget_ProgramNameCharWithExposedParamAttacher.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_LCDcharacterPaths_Singleton.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"



ProgramNameCharWithExposedParamAttacher::ProgramNameCharWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams }
{
	slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
	slider.setAlpha(0.0f);
	slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
	slider.addListener(this);
	addAndMakeVisible(slider);

	auto char_w{ 12 };
	auto char_h{ 17 };
	setSize(char_w, char_h);
	slider.setBounds(getLocalBounds());
}

void ProgramNameCharWithExposedParamAttacher::sliderValueChanged(Slider* sliderThatChanged) {
	if (sliderThatChanged == &slider)
		repaint();
}

void ProgramNameCharWithExposedParamAttacher::paint(Graphics& g) {
	auto charNum{ (uint8)roundToInt(slider.getValue()) };
	auto& charPaths{ LCDcharacterPaths::get() };
	g.setColour(Color::controlText);
	g.fillPath(charPaths.getPathForChar(charNum));
}

void ProgramNameCharWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	sliderAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), slider));
	limitSliderRangeToBasicASCIICharsThatAreVisible();
}

void ProgramNameCharWithExposedParamAttacher::limitSliderRangeToBasicASCIICharsThatAreVisible() {
	slider.setRange(32.0, 127.0, 1.0);
}

void ProgramNameCharWithExposedParamAttacher::deleteAttachment() {
	sliderAttachment = nullptr;
}

ProgramNameCharWithExposedParamAttacher::~ProgramNameCharWithExposedParamAttacher() {
	slider.removeListener(this);
}
