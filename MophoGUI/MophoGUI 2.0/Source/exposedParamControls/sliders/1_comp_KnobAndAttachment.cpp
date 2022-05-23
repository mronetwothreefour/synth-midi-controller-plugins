#include "1_comp_KnobAndAttachment.h"

#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



KnobAndAttachment::KnobAndAttachment(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
		paramIndex{ paramIndex },
		exposedParams{ exposedParams },
		unexposedParams{ unexposedParams },
		knob{ unexposedParams },
		tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
		choiceNameString{""}
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->addListener(this);

	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.isModifyingPitch = true;
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());

	parameterValueChanged(paramIndex, paramaterPtr->getValue());
}

void KnobAndAttachment::paint(Graphics& g) {
	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.setColour(GUI::color_White);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment::setKnobIsModifyingPitch() {
	knob.isModifyingPitch = true;
}

void KnobAndAttachment::setKnobIsNotModifyingPitch() {
	knob.isModifyingPitch = false;
}

void KnobAndAttachment::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex == paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto paramaterPtr{ exposedParams->getParameter(paramID) };
		auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(newValue)) };
		choiceNameString = info.choiceNameFor((uint8)currentChoice, paramIndex);
		repaint();
		if (paramID.toString().contains("_LFO_") && paramID.toString().endsWith("_Freq")) {
			if (currentChoice >= EP::firstLFO_PitchedFreqChoice && currentChoice < EP::firstLFO_SyncedFreqChoice)
				knob.isModifyingPitch = true;
			else
				knob.isModifyingPitch = false;
		}
	}
}

void KnobAndAttachment::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment::~KnobAndAttachment() {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->removeListener(this);
}

