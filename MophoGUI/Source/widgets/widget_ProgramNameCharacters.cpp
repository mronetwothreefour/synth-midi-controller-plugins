#include "widget_ProgramNameCharacters.h"

#include "..\helpers\helper_CustomColors.h"
#include "..\helpers\helper_LCDcharacterPaths_Singleton.h"



PgmNameCharWithExposedParamAttacher::PgmNameCharWithExposedParamAttacher(uint8 param) :
	param{ param },
	tooltipSetter{ slider, param }
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

PgmNameCharWithExposedParamAttacher::~PgmNameCharWithExposedParamAttacher() {
	slider.removeListener(this);
}

void PgmNameCharWithExposedParamAttacher::sliderValueChanged(Slider* sliderThatChanged) {
	if (sliderThatChanged == &slider)
		repaint();
}

void PgmNameCharWithExposedParamAttacher::paint(Graphics& g) {
	auto charNum{ (uint8)roundToInt(slider.getValue()) };
	auto& charPaths{ LCDcharacterPaths::get() };
	g.setColour(Color::controlText);
	g.fillPath(charPaths.getPathForChar(charNum));
}

void PgmNameCharWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	auto& info{ InfoForExposedParameters::get() };
	sliderAttachment.reset(new SliderAttachment(*exposedParams, info.IDfor(param).toString(), slider));
	limitSliderRangeToBasicASCIICharsThatAreVisible();
}

void PgmNameCharWithExposedParamAttacher::limitSliderRangeToBasicASCIICharsThatAreVisible() {
	slider.setRange(32.0, 127.0, 1.0);
}

void PgmNameCharWithExposedParamAttacher::deleteAttachment() {
	sliderAttachment = nullptr;
}