#include "epc_1_comp_SliderAndAttachment_ForOscBalance.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

SliderAndAttachment_ForOscBalance::SliderAndAttachment_ForOscBalance(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ EP::indexForOscBalance },
	state{ exposedParams->state.get() },
	slider{ &exposedParams->undoManager },
	textEditor{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	tooltipUpdater{ paramIndex, slider, exposedParams, unexposedParams }
{
	slider.addMouseListener(this, false);
	slider.setMouseDragSensitivity(exposedParams->info->mouseDragSensitivityFor(paramIndex));
	setSize(exposedParams->info->widthFor(paramIndex), GUI::control_h);
	slider.setBounds(getLocalBounds());
	addAndMakeVisible(slider);

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);
}

void SliderAndAttachment_ForOscBalance::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderAndAttachment_ForOscBalance::attachSliderToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, ID::ep_20_OscBalance.toString(), slider });
	slider.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
}

void SliderAndAttachment_ForOscBalance::deleteAttachmentBeforeSliderToPreventMemLeak() {
	attachment = nullptr;
}

SliderAndAttachment_ForOscBalance::~SliderAndAttachment_ForOscBalance() {
	slider.removeMouseListener(this);
}
