#include "1_comp_ToggleButtonAndAttachment.h"

#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



ToggleButtonAndAttachment::ToggleButtonAndAttachment(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	tooltipsUpdater{ paramIndex, toggle, exposedParams, unexposedParams }
{
	addAndMakeVisible(toggle);
	toggle.setComponentID(ID::component_RedToggle.toString());
	setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	toggle.setBounds(getLocalBounds());
}

void ToggleButtonAndAttachment::attachToggleToExposedParameter() {
	attachment.reset(new ButtonAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), toggle));
}

void ToggleButtonAndAttachment::deleteAttachmentBeforeToggleToPreventMemLeak() {
	attachment = nullptr;
}

