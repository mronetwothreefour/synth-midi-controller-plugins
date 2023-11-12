#include "epc_1_comp_SwitchSliderAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace P_600_G_Constants;

SwitchSliderAndAttachment::SwitchSliderAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	switchSlider{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, switchSlider, exposedParams, tooltips }
{
	addAndMakeVisible(switchSlider);
	auto controlType{ info->controlTypeFor(paramIndex) };
	auto control_h{ controlType == ControlType::twoPoleSwitch ? GUI::switch_2_Pole_h : GUI::switch_3_Pole_h };
	setSize(GUI::switch_w, control_h);
	switchSlider.setBounds(getLocalBounds());
}

void SwitchSliderAndAttachment::attachSwitchSliderToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), switchSlider });
}

void SwitchSliderAndAttachment::deleteAttachmentBeforeSwitchSliderToPreventMemLeak() {
	attachment = nullptr;
}
