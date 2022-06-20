#include "epc_1_comp_KnobAndAttachment.h"

#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;
using Info = InfoForExposedParameters;



KnobAndAttachment::KnobAndAttachment(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
		paramIndex{ paramIndex },
		exposedParams{ exposedParams },
		knob{ unexposedParams },
		tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
		choiceNameString{""}
{
	knob.addListener(this);
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(Info::get().mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());

	sliderValueChanged(&knob);
}

void KnobAndAttachment::paint(Graphics& g) {
	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.setColour(GUI::color_White);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, Info::get().IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment::setKnobIsModifyingPitch() {
	knob.isModifyingPitch = true;
}

void KnobAndAttachment::setKnobIsNotModifyingPitch() {
	knob.isModifyingPitch = false;
}

void KnobAndAttachment::sliderValueChanged(Slider* /*slider*/) {
	auto currentChoice{ roundToInt(knob.getValue()) };
	choiceNameString = Info::get().choiceNameFor((uint8)currentChoice, paramIndex);
	auto paramID{ Info::get().IDfor(paramIndex).toString() };
	if (paramID.contains("_LFO_") && paramID.endsWith("_Freq")) {
		if (currentChoice >= EP::firstLFO_PitchedFreqChoice && currentChoice < EP::firstLFO_SyncedFreqChoice)
			knob.isModifyingPitch = true;
		else
			knob.isModifyingPitch = false;
	}
	MessageManagerLock mmLock;
	repaint();
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment::~KnobAndAttachment() {
	knob.removeListener(this);
}

