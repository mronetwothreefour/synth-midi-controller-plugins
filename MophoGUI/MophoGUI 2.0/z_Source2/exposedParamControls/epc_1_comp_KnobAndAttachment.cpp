#include "epc_1_comp_KnobAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;



KnobAndAttachment::KnobAndAttachment(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	knob{ &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, knob, exposedParams, unexposedParams }
{
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());
}

void KnobAndAttachment::paint(Graphics& g) {
	auto currentChoice{ roundToInt(knob.getValue()) };
	auto choiceNameString{ info->choiceNameFor((uint8)currentChoice, paramIndex) };
	auto paramID{ info->IDfor(paramIndex).toString() };
	if (paramID.contains("_LFO_") && paramID.endsWith("_Freq")) {
		if (currentChoice >= EP::firstLFO_PitchedFreqChoice && currentChoice < EP::firstLFO_SyncedFreqChoice)
			knob.isModifyingPitch = true;
		else
			knob.isModifyingPitch = false;
	}
	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.setColour(GUI::color_White);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*state, info->IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment::setKnobIsModifyingPitch() {
	knob.isModifyingPitch = true;
}

void KnobAndAttachment::setKnobIsNotModifyingPitch() {
	knob.isModifyingPitch = false;
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

