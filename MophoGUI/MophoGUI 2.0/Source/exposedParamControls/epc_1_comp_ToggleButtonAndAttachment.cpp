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
	tooltipUpdater{ paramIndex, redToggle, exposedParams, unexposedParams }
{
	setInterceptsMouseClicks(true, false);

	auto width{ info->widthFor(paramIndex) };
	redToggle.setComponentID(ID::comp_RedToggle.toString());
	redToggle.setSize(GUI::redToggle_diameter, GUI::redToggle_diameter);
	auto paramID{ info->IDfor(paramIndex) };
	if (paramID == ID::ep_012_OscSync)
		redToggle.setTopRightPosition(width, 0);
	else if (paramID == ID::ep_100_SeqOnOff)
		redToggle.setTopLeftPosition(0, 0);
	else
		redToggle.setCentrePosition(width / 2, GUI::redToggle_diameter / 2);
	addAndMakeVisible(redToggle);

	setSize(width, info->heightFor(paramIndex));
}

void ToggleButtonAndAttachment::attachToggleToExposedParameter() {
	attachment.reset(new ButtonAttachment(*state, info->IDfor(paramIndex).toString(), redToggle));
}

void ToggleButtonAndAttachment::deleteAttachmentBeforeToggleToPreventMemLeak() {
	attachment = nullptr;
}

void ToggleButtonAndAttachment::mouseDown(const MouseEvent& /*event*/) {
	redToggle.triggerClick();
}


