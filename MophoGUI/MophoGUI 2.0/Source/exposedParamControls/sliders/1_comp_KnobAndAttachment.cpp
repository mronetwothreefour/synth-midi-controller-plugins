#include "1_comp_KnobAndAttachment.h"

#include "../../constants/constants_GUI_Bounds.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace mophoConstants;



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
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.isModifyingPitch = true;
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());
}

void KnobAndAttachment::paint(Graphics& g) {
	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.setColour(GUI::color_White);
	g.drawText(choiceNameString, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex == paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto paramaterPtr{ exposedParams->getParameter(paramID) };
		auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(newValue)) };
		choiceNameString = info.verboseChoiceNameFor((uint8)currentChoice, paramIndex);
		repaint();
	}
}

void KnobAndAttachment::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void KnobAndAttachment::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

