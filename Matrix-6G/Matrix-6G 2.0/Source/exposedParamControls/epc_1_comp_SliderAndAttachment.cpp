#include "epc_1_comp_SliderAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../gui/gui_build_LED_Path.h"

using namespace Matrix_6G_Constants;

SliderAndAttachment::SliderAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	slider{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, slider, exposedParams, unexposedParams },
	slider_w{ info->widthFor(paramIndex) }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	setSize(slider_w, GUI::control_h);
	slider.setBounds(getLocalBounds());
}

void SliderAndAttachment::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	auto currentChoice{ roundToInt(slider.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	auto choiceNamePath{ LED_Path::buildLabelText(choiceNameString, slider_w) };
	g.fillPath(choiceNamePath);
}

void SliderAndAttachment::attachSliderToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), slider });
}

void SliderAndAttachment::setKnobIsModifyingPitch(bool isModifyingPitch) {
	slider.isModifyingPitch = isModifyingPitch;
}

void SliderAndAttachment::deleteAttachmentBeforeSliderToPreventMemLeak() {
	attachment = nullptr;
}
