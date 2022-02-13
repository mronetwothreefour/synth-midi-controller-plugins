#include "master_VoicesMapSlot.h"

#include "../gui/gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoicesMapSlot::VoicesMapSlot(UnexposedParameters* unexposedParams, uint8 programNumber) :
	unexposedParams{ unexposedParams },
	programNumber{ programNumber },
	slider_ForSettingInVoice{ unexposedParams, programNumber },
	slider_ForSettingOutProgramNumber{ unexposedParams, programNumber }
{
	slider_ForSettingInVoice.addListener(this);
	addAndMakeVisible(slider_ForSettingInVoice);
	slider_ForSettingOutProgramNumber.addListener(this);
	addAndMakeVisible(slider_ForSettingOutProgramNumber);
	setSize(GUI::voicesMapSlot_w, GUI::voicesMapSlot_h);
}

void VoicesMapSlot::resized() {
	slider_ForSettingInVoice.setBounds(GUI::bounds_VoicesMapSlotInSlider);
	slider_ForSettingOutProgramNumber.setBounds(GUI::bounds_VoicesMapSlotOutSlider);
}

void VoicesMapSlot::sliderValueChanged(Slider* slider) {
	auto masterOptions{ unexposedParams->globalOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingInVoice)
		masterOptions->setVoicesMapInVoiceForProgramNumber(currentValue, programNumber);
	if (slider == &slider_ForSettingOutProgramNumber)
		masterOptions->setVoicesMapOutVoiceForProgramNumber(currentValue, programNumber);
}

VoicesMapSlot::~VoicesMapSlot() {
	slider_ForSettingOutProgramNumber.removeListener(this);
	slider_ForSettingInVoice.removeListener(this);
}
