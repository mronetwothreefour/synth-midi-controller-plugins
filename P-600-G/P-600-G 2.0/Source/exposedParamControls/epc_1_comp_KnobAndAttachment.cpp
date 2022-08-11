#include "epc_1_comp_KnobAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace P_600_G_Constants;

KnobAndAttachment::KnobAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	knob{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, knob, exposedParams, unexposedParams }
{
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());
}

void KnobAndAttachment::paint(Graphics& g) {
	auto currentChoice{ roundToInt(knob.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	g.setFont(GUI::font_KnobValueDisplay);
	g.setColour(GUI::color_OffWhite);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), knob });
}

void KnobAndAttachment::setKnobIsModifyingPitch(bool isModifyingPitch) {
	knob.isModifyingPitch = isModifyingPitch;
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}
