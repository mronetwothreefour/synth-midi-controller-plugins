#include "epc_1_comp_SliderAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

SliderAndAttachment::SliderAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	slider{ &exposedParams->undoManager },
	textEditor{ paramIndex, exposedParams, unexposedParams->getTooltipsOptions() },
	tooltipUpdater{ paramIndex, slider, exposedParams, unexposedParams },
	slider_w{ info->widthFor(paramIndex) }
{
	slider.addMouseListener(this, false);
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	setSize(slider_w, GUI::control_h);
	slider.setBounds(getLocalBounds());

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);
}

void SliderAndAttachment::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	auto currentChoice{ roundToInt(slider.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	auto choiceNamePath{ LED_Path::buildLabelText(choiceNameString, slider_w) };
	g.fillPath(choiceNamePath);
}

void SliderAndAttachment::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderAndAttachment::attachSliderToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), slider });
	slider.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
}

void SliderAndAttachment::setKnobIsModifyingPitch(bool isModifyingPitch) {
	slider.isModifyingPitch = isModifyingPitch;
}

void SliderAndAttachment::deleteAttachmentBeforeSliderToPreventMemLeak() {
	attachment = nullptr;
}

SliderAndAttachment::~SliderAndAttachment() {
	slider.removeMouseListener(this);
}
