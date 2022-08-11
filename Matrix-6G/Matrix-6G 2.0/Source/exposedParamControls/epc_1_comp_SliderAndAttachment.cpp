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
	sliderWidth{ info->widthFor(paramIndex) }
{
	addAndMakeVisible(slider);
	slider.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	setSize(sliderWidth, GUI::control_h);
	slider.setBounds(getLocalBounds());
}

void SliderAndAttachment::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	auto currentChoice{ roundToInt(slider.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	Path positionPath;
	auto lastCharacter_x{ sliderWidth - GUI::ledDisplayRightSideInset - GUI::ledDisplayCharacter_w };
	auto lastCharacterIndex{ (int)choiceNameString.toStdString().size() - 1 };
	for (auto i = lastCharacterIndex; i != -1; --i) {
		auto charNum{ (uint8)choiceNameString[i] };
		auto character_x{ lastCharacter_x - (GUI::ledDisplayCharacter_w * (lastCharacterIndex - i)) };
		positionPath.addPath(LED_Path::buildForChar(charNum), AffineTransform::translation((float)character_x, (float)GUI::ledDisplay_y));
	}
	g.fillPath(positionPath);
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
