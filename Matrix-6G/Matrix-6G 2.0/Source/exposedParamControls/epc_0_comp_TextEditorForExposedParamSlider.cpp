#include "epc_0_comp_TextEditorForExposedParamSlider.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_1_tree_InfoForExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForExposedParamSlider::TextEditorForExposedParamSlider(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	editorType{ info->sliderTextEditorTypeFor(paramIndex) },
	paramPtr{ exposedParams->state->getParameter(info->IDfor(paramIndex)) }
{
	paramAsValue = exposedParams->state->getParameterAsValue(info->IDfor(paramIndex));
	paramAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForSlider.toString());
	textEditor.setFont(GUI::font_LabelEditors);
	switch (editorType)
	{
	case EditorType::oscPitch:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_Pitch(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_Pitch(); };
		break;
	case EditorType::signed_6_bitValue:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_SignedRanges(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::signed_7_bitValue:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_SignedRanges(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	case EditorType::unsignedValue:
		textEditor.onEditorShow = [this, tooltipsOptions] { onEditorShow_UnsignedRanges(tooltipsOptions); };
		textEditor.onTextChange = [this] { onTextChange_NumericRanges(); };
		break;
	default:
		break;
	}
	textEditor.onTextChange();

	setSize(info->widthFor(paramIndex), GUI::control_h);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForExposedParamSlider::setEditorText() {
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	auto currentChoiceName{ info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" +") };
	textEditor.setText(currentChoiceName, dontSendNotification);
}

void TextEditorForExposedParamSlider::onEditorShow_Pitch(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	editor->setJustification(Justification::centredRight);
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to D#5 (63)";
		editor->setTooltip(description);
	}
}

void TextEditorForExposedParamSlider::onEditorShow_SignedRanges(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	editor->setJustification(Justification::centredRight);
	if (tooltips->shouldShowDescription()) {
		String valueRangeString{ editorType == EditorType::signed_7_bitValue ? "-63 to 63" : "-31 to 31" };
		editor->setTooltip("Type in a new setting.\n(Range: " + valueRangeString + ")");
	}
}

void TextEditorForExposedParamSlider::onEditorShow_UnsignedRanges(TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (info->controlTypeFor(paramIndex) == ControlType::sliderForOscBalance)
		editor->setJustification(Justification::centred);
	else
		editor->setJustification(Justification::centredRight);
	if (tooltips->shouldShowDescription()) {
		auto maxValue{ info->numberOfChoicesFor(paramIndex) - 1 };
		editor->setTooltip("Type in a new setting.\n(Range: 0 to " + (String)maxValue + ")");
	}
}

void TextEditorForExposedParamSlider::onTextChange_Pitch() {
	auto newSettingString{ textEditor.getText().toUpperCase() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1.0f };
		if (newSettingString.containsAnyOf("abcdefgABCDEFG#")) {
			auto numberOfChoices{ EP::numberOfChoicesForOscPitch };
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

void TextEditorForExposedParamSlider::onTextChange_NumericRanges() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getFloatValue() };
		if (editorType == EditorType::signed_6_bitValue)
			newSetting += 31.0f;
		if (editorType == EditorType::signed_7_bitValue)
			newSetting += 63.0f;
		paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
	}
	else
		setEditorText();
}

void TextEditorForExposedParamSlider::showEditor() {
	textEditor.showEditor();
}

void TextEditorForExposedParamSlider::valueChanged(Value& /*value*/) {
	setEditorText();
}

TextEditorForExposedParamSlider::~TextEditorForExposedParamSlider() {
	paramAsValue.removeListener(this);
}
