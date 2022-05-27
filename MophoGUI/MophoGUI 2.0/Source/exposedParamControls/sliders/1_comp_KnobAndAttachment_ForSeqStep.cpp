#include "1_comp_KnobAndAttachment_ForSeqStep.h"

#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



KnobAndAttachment_ForSeqStep::KnobAndAttachment_ForSeqStep(
    uint8 paramIndex, int trackNum, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
		paramIndex{ paramIndex },
		exposedParams{ exposedParams },
		unexposedParams{ unexposedParams },
		knob{ trackNum, unexposedParams },
		tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
		choiceNum{ 0 }
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->addListener(this);
	trackDestIndex = (uint8)100 + (uint8)trackNum;
	auto trackDestParamID{ info.IDfor(trackDestIndex) };
	auto trackDestParamaterPtr{ exposedParams->getParameter(trackDestParamID) };
	trackDestParamaterPtr->addListener(this);

	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.isModifyingPitch = false;
	knob.isModifyingSeqStep = true;
	setSize(GUI::seqSteps_w, GUI::seqSteps_h);
	knob.setAlpha(0.0f);
	knob.setBounds(getLocalBounds());

	parameterValueChanged(trackDestIndex, trackDestParamaterPtr->getValue());
	parameterValueChanged(paramIndex, paramaterPtr->getValue());
}

void KnobAndAttachment_ForSeqStep::paint(Graphics& g) {
	g.setColour(GUI::color_White);
	if (choiceNum > -1 && choiceNum <= EP::choiceNumForSeqTrack1Step_Rest) {
		if (choiceNum < EP::choiceNumForSeqStep_Reset) {
			auto& info{ InfoForExposedParameters::get() };
			auto choiceNameString{ info.choiceNameFor((uint8)choiceNum, paramIndex) };
			if (knob.isModifyingPitch)
				choiceNameString = choiceNameString.fromFirstOccurrenceOf("(", false, false).upToFirstOccurrenceOf(")", false, false);
			else
				choiceNameString = choiceNameString.upToFirstOccurrenceOf(" ", false, false);
			paintChoiceNameString(g, choiceNameString);
		}
		if (choiceNum == EP::choiceNumForSeqStep_Reset)
			paintResetSequenceArrow(g);
		if (choiceNum == EP::choiceNumForSeqTrack1Step_Rest)
			paintTrack1RestDot(g);
	}
	else
		paintChoiceNameString(g, "ERR");
}

void KnobAndAttachment_ForSeqStep::paintResetSequenceArrow(Graphics& g) {
	Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
	g.drawArrow(l, 5.0f, 10.0f, 8.0f);
}

void KnobAndAttachment_ForSeqStep::paintTrack1RestDot(Graphics& g) {
	g.fillEllipse(10.0f, 10.0f, 6.0f, 6.0f);
}

void KnobAndAttachment_ForSeqStep::paintChoiceNameString(Graphics& g, String stepChoiceName) {
	g.setFont(GUI::fontFor_SeqSteps);
	g.drawText(stepChoiceName, getLocalBounds(), Justification::centred, false);
}

void KnobAndAttachment_ForSeqStep::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment_ForSeqStep::setKnobIsModifyingPitch() {
	knob.isModifyingPitch = true;
}

void KnobAndAttachment_ForSeqStep::setKnobIsNotModifyingPitch() {
	knob.isModifyingPitch = false;
}

void KnobAndAttachment_ForSeqStep::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex == trackDestIndex || changedParamIndex == paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor((uint8)changedParamIndex) };
		auto paramaterPtr{ exposedParams->getParameter(paramID) };
		auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(newValue)) };
		if (changedParamIndex == trackDestIndex) {
			if (currentChoice > 0 && currentChoice < 4)
				knob.isModifyingPitch = true;
			else
				knob.isModifyingPitch = false;
		}
		else {
			choiceNum = currentChoice;
		}
		MessageManagerLock mmLock;
		repaint();
	}
}

void KnobAndAttachment_ForSeqStep::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void KnobAndAttachment_ForSeqStep::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment_ForSeqStep::~KnobAndAttachment_ForSeqStep() {
	auto& info{ InfoForExposedParameters::get() };
	auto trackDestParamID{ info.IDfor(trackDestIndex) };
	auto trackDestParamaterPtr{ exposedParams->getParameter(trackDestParamID) };
	trackDestParamaterPtr->removeListener(this);
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->removeListener(this);
}
