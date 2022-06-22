#include "epc_1_comp_KnobAndAttachment_ForSeqStep.h"

#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;
using Info = InfoForExposedParameters;



KnobAndAttachment_ForSeqStep::KnobAndAttachment_ForSeqStep(
    uint8 paramIndex, int trackNum, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
		paramIndex{ paramIndex },
		exposedParams{ exposedParams },
		knob{ trackNum, unexposedParams },
		tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
		choiceNum{ 0 }
{
	knob.addListener(this);
	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(Info::get().mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.isModifyingPitch = false;
	knob.isModifyingSeqStep = true;
	setSize(GUI::seqSteps_w, GUI::seqSteps_h);
	knob.setAlpha(0.0f);
	knob.setBounds(getLocalBounds());

	trackDestIndex = uint8(100 + trackNum);
	trackDestination.addListener(this);

	sliderValueChanged(&trackDestination);
	sliderValueChanged(&knob);
}

void KnobAndAttachment_ForSeqStep::paint(Graphics& g) {
	g.setColour(GUI::color_White);
	if (choiceNum > -1 && choiceNum <= EP::choiceNumForSeqTrack1Step_Rest) {
		if (choiceNum < EP::choiceNumForSeqStep_Reset) {
			auto choiceNameString{ Info::get().choiceNameFor((uint8)choiceNum, paramIndex) };
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

void KnobAndAttachment_ForSeqStep::attachKnobsToExposedParameters() {
	knobAttachment.reset(new SliderAttachment(*exposedParams, Info::get().IDfor(paramIndex).toString(), knob));
	trackDestinationAttachment.reset(new SliderAttachment(*exposedParams, Info::get().IDfor(trackDestIndex).toString(), trackDestination));
}

void KnobAndAttachment_ForSeqStep::setKnobIsModifyingPitch() {
	knob.isModifyingPitch = true;
}

void KnobAndAttachment_ForSeqStep::setKnobIsNotModifyingPitch() {
	knob.isModifyingPitch = false;
}

void KnobAndAttachment_ForSeqStep::sliderValueChanged(Slider* slider) {
	auto currentChoice{ roundToInt(knob.getValue()) };
	if (slider == &trackDestination) {
		auto destination{ roundToInt(trackDestination.getValue()) };
		if (destination > 0 && destination < 4)
			knob.isModifyingPitch = true;
		else
			knob.isModifyingPitch = false;
	}
	else {
		choiceNum = currentChoice;
	}
	repaint();
}

void KnobAndAttachment_ForSeqStep::deleteAttachmentsBeforeKnobsToPreventMemLeaks() {
	knobAttachment = nullptr;
	trackDestinationAttachment = nullptr;
}

KnobAndAttachment_ForSeqStep::~KnobAndAttachment_ForSeqStep() {
	trackDestination.removeListener(this);
	knob.addListener(this);
}
