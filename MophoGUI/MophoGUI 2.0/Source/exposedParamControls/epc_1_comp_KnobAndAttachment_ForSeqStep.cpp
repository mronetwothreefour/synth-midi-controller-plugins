#include "epc_1_comp_KnobAndAttachment_ForSeqStep.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_0_build_ChoiceNamesValueTree.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

KnobAndAttachment_ForSeqStep::KnobAndAttachment_ForSeqStep(
	const uint8 paramIndex, const Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	knob{ track, &exposedParams->undoManager },
	tooltipUpdater{ paramIndex, knob, exposedParams, unexposedParams },
	trackDestID{ info->IDfor(uint8(EP::firstSeqTrackDestParamIndex + ((int)track - 1))) }
{
	trackDestination.setInterceptsMouseClicks(false, false);
	trackDestination.onValueChange = [this] {
		auto destination{ roundToInt(trackDestination.getValue()) };
		knob.isModifyingPitch = destination > 0 && destination < 4 ? true : false;
		setEditorText();
		repaint();
	};

	knob.addMouseListener(this, false);
	knob.setMouseDragSensitivity(info->mouseDragSensitivityFor(paramIndex));
	knob.isModifyingPitch = false;
	knob.isModifyingSeqStep = true;
	knob.setAlpha(0.0f);
	knob.onValueChange = [this] { setEditorText(); };
	addAndMakeVisible(knob);

	textEditor.reset(new Label{});
	textEditor->setInterceptsMouseClicks(false, true);
	textEditor->setComponentID(ID::comp_TextEditorForSeqStep.toString());
	textEditor->setFont(GUI::font_SeqSteps);
	textEditor->onEditorShow = [this, track, unexposedParams] {
		auto editor{ textEditor->getCurrentTextEditor() };
		auto maxLength{ knob.isModifyingPitch ? 4 : 3 };
		String allowedChar{ knob.isModifyingPitch ? "abcdefgABCDEFG012345#+<" : "0123456789<" };
		if (track == Track::one)
			allowedChar += ".";
		editor->setInputRestrictions(maxLength, allowedChar);
		if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
			String description{ "" };
			if (knob.isModifyingPitch) {
				description += "Type in either a pitch name and octave number\n";
				description += "(e.g. " + GUI::openQuote + "C#5" + GUI::closeQuote + ") or a note number (e.g. " + GUI::openQuote + "122" + GUI::closeQuote + ").\n";
				description += "Range: C0 (0) to D5+ (125)\n";
			}
			else {
				description += "Type in a new setting.\n";
				description += "range (0 to 125)\n";
			}
			description += "Reset: " + GUI::openQuote + "<" + GUI::closeQuote + " or " + GUI::openQuote + "126" + GUI::closeQuote;
			if (track == Track::one)
				description += "\nRest: " + GUI::openQuote + "." + GUI::closeQuote + " or " + GUI::openQuote + "127" + GUI::closeQuote;
			editor->setTooltip(description);
		}
	};
	textEditor->onTextChange = [this, paramIndex] {
		auto newSettingString{ textEditor->getText() };
		if (newSettingString.isNotEmpty()) {
			auto newSetting{ -1.0 };
			if (newSettingString.containsAnyOf("abcdefgABCDEFG#+.<")) {
				newSettingString = newSettingString.toUpperCase();
				for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForSeqTrackSteps; ++choiceNum) {
					if (info->choiceNameFor(choiceNum, paramIndex).removeCharacters(" ") == newSettingString) {
						newSetting = (double)choiceNum;
						break;
					}
				}
				if (newSettingString == "<")
					newSetting = 126.0;
				if (newSettingString == ".")
					newSetting = 127.0;
			}
			else
				newSetting = newSettingString.getDoubleValue();
			if (newSetting > -1.0)
				knob.setValue(newSetting);
		}
		else
			setEditorText();
	};
	setEditorText();
	addAndMakeVisible(textEditor.get());

	setSize(GUI::seqSteps_w, GUI::seqSteps_h);
	knob.setBounds(getLocalBounds());
	textEditor->setBounds(getLocalBounds());
}

void KnobAndAttachment_ForSeqStep::setEditorText() {
	auto currentChoice{ (uint8)roundToInt(knob.getValue()) };
	if (knob.isModifyingPitch || currentChoice >= EP::choiceNumForSeqTrackStep_Reset)
		textEditor->setText(info->choiceNameFor(currentChoice, paramIndex), dontSendNotification);
	else
		textEditor->setText((String)currentChoice, dontSendNotification);
}

void KnobAndAttachment_ForSeqStep::paint(Graphics& g) {
	auto choiceNum{ (uint8)roundToInt(knob.getValue()) };
	g.setColour(GUI::color_White);
	if (choiceNum > -1 && choiceNum <= EP::choiceNumForSeqTrack_1_Step_Rest) {
		if (choiceNum < EP::choiceNumForSeqTrackStep_Reset) {
			auto choiceNameString{ String(choiceNum)};
			if (knob.isModifyingPitch)
				choiceNameString = info->choiceNameFor(choiceNum, paramIndex);
			paintChoiceNameString(g, choiceNameString);
		}
		if (choiceNum == EP::choiceNumForSeqTrackStep_Reset)
			paintResetSequenceArrow(g);
		if (choiceNum == EP::choiceNumForSeqTrack_1_Step_Rest)
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
	g.setFont(GUI::font_SeqSteps);
	g.drawText(stepChoiceName, getLocalBounds(), Justification::centred, false);
}

void KnobAndAttachment_ForSeqStep::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor->showEditor();
}

void KnobAndAttachment_ForSeqStep::attachKnobsToExposedParameters() {
	knobAttachment.reset(new SliderAttachment{ *state, info->IDfor(paramIndex).toString(), knob });
	knob.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
	trackDestinationAttachment.reset(new SliderAttachment{ *state, trackDestID.toString(), trackDestination });
	trackDestination.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
}

void KnobAndAttachment_ForSeqStep::setKnobIsModifyingPitch(bool isModifyingPitch) {
	knob.isModifyingPitch = isModifyingPitch;
}

void KnobAndAttachment_ForSeqStep::deleteAttachmentsBeforeKnobsToPreventMemLeaks() {
	knob.removeMouseListener(this);
	knobAttachment = nullptr;
	trackDestinationAttachment = nullptr;
	textEditor = nullptr;
}

