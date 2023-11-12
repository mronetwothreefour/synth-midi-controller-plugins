#include "epc_1_comp_KnobAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;

KnobAndAttachment::KnobAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	knob{ &exposedParams->undoManager },
	textEditor{ paramIndex, exposedParams, tooltips },
	tooltipUpdater{ paramIndex, knob, exposedParams, tooltips }
{
	knob.addMouseListener(this, false);
	knob.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());
	addAndMakeVisible(knob);

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);
}

void KnobAndAttachment::paint(Graphics& g) {
	auto currentChoice{ roundToInt(knob.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	if (paramID.contains("_LFO_") && paramID.endsWith("_Freq")) {
		if (currentChoice >= EP::first_LFO_PitchedFreqChoice && currentChoice < EP::first_LFO_SyncedFreqChoice)
			knob.isModifyingPitch = true;
		else
			knob.isModifyingPitch = false;
	}
	g.setFont(GUI::font_KnobValueDisplays);
	g.setColour(GUI::color_White);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), knob });
	knob.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
}

void KnobAndAttachment::setKnobIsModifyingPitch(bool isModifyingPitch) {
	knob.isModifyingPitch = isModifyingPitch;
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment::~KnobAndAttachment() {
	knob.removeMouseListener(this);	
}

