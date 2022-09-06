#include "rndm_0_comp_TextEditorForSeqTrackProbabilityKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForSeqTrackProbabilityKnob::TextEditorForSeqTrackProbabilityKnob(
	KnobType knobType, Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
    knobType{ knobType },
	track{ track },
	randomization{ randomization }
{
	targetStepForSeqTrackAsValue = randomization->getTargetStepForSeqTrackAsValue(track);
	targetStepForSeqTrackAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForKnob.toString());
	textEditor.setFont(GUI::font_KnobValueDisplays);
	textEditor.onEditorShow = [this, tooltips] {
		auto editor{ textEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(3, "0123456789");
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type in a new setting.\n(Range: 0 to 100)");
	};
	textEditor.onTextChange = [this, knobType, track, randomization] {
		auto newSettingString{ textEditor.getText() };
		if (newSettingString.isNotEmpty()) {
			auto targetStep{ randomization->targetStepForSeqTrack(track) };
			auto maxProbAllowed{ knobType == KnobType::reset && targetStep == Step::one ? 0.0f : 1.0f };
			auto newSetting{ newSettingString.getFloatValue() / 100.0f };
			if (track == Track::one) {
				if (knobType == KnobType::reset && targetStep != Step::one)
					maxProbAllowed = 1.0f - randomization->probabilityOfRestForSeqTrack_1_Step(targetStep);
				else
					maxProbAllowed = 1.0f - randomization->probabilityOfResetForSeqTrackStep(track, targetStep);
			}
			if (newSetting > maxProbAllowed)
				newSetting = maxProbAllowed;
			if (knobType == KnobType::reset)
				if (targetStep == Step::all)
					randomization->setProbabilityOfResetForAllSeqTrackSteps(newSetting, track);
				else
					randomization->setProbabilityOfResetForSeqTrackStep(newSetting, track, targetStep);
			else
				if (targetStep == Step::all)
					randomization->setProbabilityOfRestForAllSeqTrack_1_Steps(newSetting);
				else
					randomization->setProbabilityOfRestForSeqTrack_1_Step(newSetting, targetStep);
		}
	};
	setEditorText();
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	if (knobType == KnobType::reset)
		seqTrackProbAsValue = randomization->getProbabilityOfResetForSeqTrackStepAsValue(track, targetStep);
	else
		seqTrackProbAsValue = randomization->getProbabilityOfRestForSeqTrack_1_StepAsValue(targetStep);
	seqTrackProbAsValue.addListener(this);

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForSeqTrackProbabilityKnob::setEditorText() {
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	auto probValue{ 0 };
	if (knobType == KnobType::reset)
		probValue = roundToInt(randomization->probabilityOfResetForSeqTrackStep(track, targetStep) * 100.0f);
	else
		probValue = roundToInt(randomization->probabilityOfRestForSeqTrack_1_Step(targetStep) * 100.0f);
	textEditor.setText((String)probValue, dontSendNotification);
}

void TextEditorForSeqTrackProbabilityKnob::showEditor() {
    textEditor.showEditor();
}

void TextEditorForSeqTrackProbabilityKnob::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(targetStepForSeqTrackAsValue)) {
		auto targetStep{ randomization->targetStepForSeqTrack(track) };
		if (knobType == KnobType::reset)
			seqTrackProbAsValue = randomization->getProbabilityOfResetForSeqTrackStepAsValue(track, targetStep);
		else
			seqTrackProbAsValue = randomization->getProbabilityOfRestForSeqTrack_1_StepAsValue(targetStep);
	}
    setEditorText();
}

TextEditorForSeqTrackProbabilityKnob::~TextEditorForSeqTrackProbabilityKnob() {
	targetStepForSeqTrackAsValue.removeListener(this);
	seqTrackProbAsValue.removeListener(this);
}
