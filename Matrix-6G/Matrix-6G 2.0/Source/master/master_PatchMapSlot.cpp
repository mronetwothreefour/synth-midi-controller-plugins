#include "master_PatchMapSlot.h"

#include "../gui/gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchMapSlot::PatchMapSlot(UnexposedParameters* unexposedParams, uint8 programNumber) :
	unexposedParams{ unexposedParams },
	programNumber{ programNumber },
	slider_ForSettingInPatch{ unexposedParams, programNumber },
	slider_ForSettingOutPatch{ unexposedParams, programNumber }
{
	slider_ForSettingInPatch.addListener(this);
	addAndMakeVisible(slider_ForSettingInPatch);
	slider_ForSettingOutPatch.addListener(this);
	addAndMakeVisible(slider_ForSettingOutPatch);
	setSize(GUI::patchMapSlot_w, GUI::patchMapSlot_h);
}

void PatchMapSlot::resized() {
	slider_ForSettingInPatch.setBounds(GUI::bounds_PatchMapSlotInSlider);
	slider_ForSettingOutPatch.setBounds(GUI::bounds_PatchMapSlotOutSlider);
}

void PatchMapSlot::sliderValueChanged(Slider* slider) {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingInPatch)
		masterOptions->setPatchMapInPatchForProgramNumber(currentValue, programNumber);
	if (slider == &slider_ForSettingOutPatch)
		masterOptions->setPatchMapOutPatchForProgramNumber(currentValue, programNumber);
}

PatchMapSlot::~PatchMapSlot() {
	slider_ForSettingOutPatch.removeListener(this);
	slider_ForSettingInPatch.removeListener(this);
}
