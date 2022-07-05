#include "epc_1_comp_ToggleButtonAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;



ToggleButtonAndAttachment::ToggleButtonAndAttachment(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	tooltipUpdater{ paramIndex, toggle, exposedParams, unexposedParams }
{
	addAndMakeVisible(toggle);
	toggle.setComponentID(ID::component_RedToggle.toString());
	setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	toggle.setBounds(getLocalBounds());
}

void ToggleButtonAndAttachment::attachToggleToExposedParameter() {
	attachment.reset(new ButtonAttachment(*state, info->IDfor(paramIndex).toString(), toggle));
}

void ToggleButtonAndAttachment::deleteAttachmentBeforeToggleToPreventMemLeak() {
	attachment = nullptr;
}

