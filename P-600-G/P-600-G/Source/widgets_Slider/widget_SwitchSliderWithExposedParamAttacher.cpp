#include "widget_SwitchSliderWithExposedParamAttacher.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



SwitchSliderWithExposedParamAttacher::SwitchSliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams) :
	param{ param },
	slider{ unexposedParams },
	tooltipSetter{ slider, param, unexposedParams }
{
	addAndMakeVisible(slider);
	slider.setComponentID(ID::component_SwitchSlider.toString());
	auto controlType{ InfoForExposedParameters::get().controlTypeFor(param) };
	auto control_h{ controlType == ControlType::twoPoleSwitch ? GUI::switchTwoPole_h : GUI::switchThreePole_h };
	setSize(GUI::switches_w, control_h);
	slider.setBounds(getLocalBounds());
}

void SwitchSliderWithExposedParamAttacher::attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
}

void SwitchSliderWithExposedParamAttacher::deleteAttachment() {
	attachment = nullptr;
}
