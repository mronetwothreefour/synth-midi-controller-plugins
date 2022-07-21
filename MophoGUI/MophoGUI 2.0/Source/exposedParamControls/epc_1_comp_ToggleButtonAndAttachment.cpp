#include "epc_1_comp_ToggleButtonAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;

ToggleButtonAndAttachment::ToggleButtonAndAttachment(
	const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	tooltipUpdater{ paramIndex, toggle, exposedParams, unexposedParams }
{
	setInterceptsMouseClicks(true, false);

	auto width{ info->widthFor(paramIndex) };
	toggle.setComponentID(ID::comp_RedToggle.toString());
	toggle.setSize(GUI::redToggle_diameter, GUI::redToggle_diameter);
	auto paramID{ info->IDfor(paramIndex) };
	if (paramID == ID::ep_012_OscSync)
		toggle.setTopRightPosition(width, 0);
	else if (paramID == ID::ep_100_SeqOnOff)
		toggle.setTopLeftPosition(0, 0);
	else
		toggle.setCentrePosition(width / 2, GUI::redToggle_diameter / 2);
	addAndMakeVisible(toggle);

	setSize(width, info->heightFor(paramIndex));
}

void ToggleButtonAndAttachment::attachToggleToExposedParameter() {
	attachment.reset(new ButtonAttachment(*state, info->IDfor(paramIndex).toString(), toggle));
}

void ToggleButtonAndAttachment::deleteAttachmentBeforeToggleToPreventMemLeak() {
	attachment = nullptr;
}

void ToggleButtonAndAttachment::mouseDown(const MouseEvent& /*event*/) {
	auto isToggled{ toggle.getToggleState() };
	toggle.setToggleState(isToggled ? false : true, sendNotification);
}


