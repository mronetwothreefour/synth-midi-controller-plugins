#include "epc_0_comp_TextEditorForExposedParamKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_1_tree_InfoForExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForExposedParamKnob::TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	rangeType{ info->knobValueRangeTypeFor(paramIndex) },
	paramPtr{ exposedParams->state->getParameter(info->IDfor(paramIndex)) }
{
	parameterValue = exposedParams->state->getParameterAsValue(info->IDfor(paramIndex));
	parameterValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForKnob.toString());
	textEditor.setFont(GUI::font_KnobValueDisplays);
	setEditorText();
	switch (rangeType)
	{
	case RangeType::clockTempo:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_ClockTempo(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case RangeType::lfoFrequency:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_LFO_Freq(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case RangeType::lpfFrequency:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_LPF_Freq(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case RangeType::oscFineTune:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_OscFineTune(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case RangeType::oscPitch:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_OscPitch(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_PitchAndFreqRanges(); };
		break;
	case RangeType::oscShape:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_OscShape(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_OscShape(); };
		break;
	case RangeType::oscSlop:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_OscSlop(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case RangeType::pitchBend:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_PitchBend(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case RangeType::posNeg_127:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_PosNeg_127(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case RangeType::pos_127:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_Pos_127(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	default:
		break;
	}

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForExposedParamKnob::setEditorText() {
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	auto currentChoiceName{ info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" ") };
	if (rangeType == RangeType::pitchBend)
		currentChoiceName = currentChoiceName.removeCharacters("+/-");
	textEditor.setText(currentChoiceName, dontSendNotification);
}

void TextEditorForExposedParamKnob::onEditorShow_ClockTempo(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 30 to 250)");
}

void TextEditorForExposedParamKnob::onEditorShow_LFO_Freq(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(5, "abcdefgABCDEFG0123456789#:.");
	if (tooltipsOptions->shouldShowDescription()) {
		String description{ "" };
		description += "Type in a new LFO frequency.\n";
		description += "Unsynced: " + oq + "0" + cq + ".." + oq + "89" + cq + "\n";
		description += "Pitched: " + oq + "C0" + cq + ".." + oq + "C5" + cq + " or " + oq + "90" + cq + ".." + oq + "150" + cq + "\n";
		description += "Synced: " + oq + "1:32" + cq + ".." + oq + "16:1" + cq + " or " + oq + "151" + cq + ".." + oq + "166" + cq;
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_LPF_Freq(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	if (tooltipsOptions->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to G#13 (164)";
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscFineTune(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -50 to 50)");
}

void TextEditorForExposedParamKnob::onEditorShow_OscPitch(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	if (tooltipsOptions->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to C10 (120)";
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscShape(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "afiopqrstwAFIOPQRSTW0123456789/");
	if (tooltipsOptions->shouldShowDescription()) {
		String description{ "" };
		description += "Type in a new shape setting.\n";
		description += "Off: " + oq + "OFF" + cq + " or " + oq + "0" + cq + "\n";
		description += "Sawtooth: " + oq + "SAW" + cq + " or " + oq + "1" + cq + "\n";
		description += "Triangle: " + oq + "TRI" + cq + " or " + oq + "2" + cq + "\n";
		description += "Sawtooth/Triangle Mix: " + oq + "S/T" + cq + " or " + oq + "3" + cq + "\n";
		description += "Square (Pulse Width 50): " + oq + "SQR" + cq + " or " + oq + "54" + cq + "\n";
		description += "Pulse Width 0..99: " + oq + "PW0" + cq + ".." + oq + "PW99" + cq + " or " + oq + "4" + cq + ".." + oq + "104" + cq;
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamKnob::onEditorShow_OscSlop(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(1, "012345");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 5)");
}

void TextEditorForExposedParamKnob::onEditorShow_PitchBend(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 12)");
}

void TextEditorForExposedParamKnob::onEditorShow_PosNeg_127(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "-0123456789");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -127 to 127)");
}

void TextEditorForExposedParamKnob::onEditorShow_Pos_127(TooltipsOptions* tooltipsOptions) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (tooltipsOptions->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 127)");
}

void TextEditorForExposedParamKnob::onTextChange_NumericRanges() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getFloatValue() };
		if (rangeType == RangeType::clockTempo)
			newSetting -= 30.0f;
		if (rangeType == RangeType::oscFineTune)
			newSetting += 50.0f;
		if (rangeType == RangeType::posNeg_127)
			newSetting += 127.0f;
		paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
	}
	else
		setEditorText();
}

void TextEditorForExposedParamKnob::onTextChange_PitchAndFreqRanges() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1.0f };
		if (newSettingString.containsAnyOf("abcdefgABCDEFG#:.")) {
			newSettingString = newSettingString.toUpperCase();
			auto numberOfChoices{ EP::numberOfChoicesForOscPitch };
			if (rangeType == RangeType::lfoFrequency)
				numberOfChoices = EP::numberOfChoicesFor_LFO_Freq;
			if (rangeType == RangeType::lpfFrequency)
				numberOfChoices = EP::numberOfChoicesFor_LPF_Freq;
			for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
				if (info->choiceNameFor(choiceNum, paramIndex).removeCharacters(" ") == newSettingString) {
					newSetting = (float)choiceNum;
					break;
				}
			}
		}
		else
			newSetting = newSettingString.getFloatValue();
		if (newSetting > -1.0f)
			paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
		else
			setEditorText();
	}
	else
		setEditorText();
}

void TextEditorForExposedParamKnob::onTextChange_OscShape() {
	auto newSettingString{ textEditor.getText().toUpperCase() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1.0f };
		if (newSettingString.containsAnyOf("AFIOPQRSTW/")) {
			if (newSettingString == "OFF")
				newSetting = 0.0f;
			if (newSettingString == "SAW")
				newSetting = 1.0f;
			if (newSettingString == "TRI")
				newSetting = 2.0f;
			if (newSettingString == "S/T" || newSettingString == "ST")
				newSetting = 3.0f;
			if (newSettingString == "SQR")
				newSetting = 54.0f;
			if (newSettingString.startsWith("PW"))
				newSetting = newSettingString.fromFirstOccurrenceOf("PW", false, false).getFloatValue() + 4.0f;
		}
		else
			newSetting = newSettingString.getFloatValue();
		if (newSetting > -1.0f)
			paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
		else
			setEditorText();
	}
	else
		setEditorText();
}

void TextEditorForExposedParamKnob::showEditor() {
	textEditor.showEditor();
}

void TextEditorForExposedParamKnob::valueChanged(Value& /*value*/) {
	setEditorText();
}

TextEditorForExposedParamKnob::~TextEditorForExposedParamKnob() {
	parameterValue.removeListener(this);
}
