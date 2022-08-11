#include "epc_1_comp_SliderAndAttachment_ForOscBalance.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace Matrix_6G_Constants;

SliderAndAttachment_ForOscBalance::SliderAndAttachment_ForOscBalance(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ EP::indexForOscBalance },
	state{ exposedParams->state.get() },
	slider{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, slider, exposedParams, unexposedParams }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(exposedParams->info->mouseDragSensitivityFor(paramIndex));
	setSize(exposedParams->info->widthFor(paramIndex), GUI::control_h);
	slider.setBounds(getLocalBounds());
}

void SliderAndAttachment_ForOscBalance::attachSliderToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, ID::ep_20_OscBalance.toString(), slider });
}

void SliderAndAttachment_ForOscBalance::deleteAttachmentBeforeSliderToPreventMemLeak() {
	attachment = nullptr;
}
