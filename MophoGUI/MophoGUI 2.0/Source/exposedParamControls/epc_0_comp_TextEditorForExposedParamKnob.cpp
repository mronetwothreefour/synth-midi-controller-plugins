#include "epc_0_comp_TextEditorForExposedParamKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
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
	
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	switch (rangeType)
	{
	case RangeType::fineTune:
		break;
	case RangeType::globalFineTune:
		break;
	case RangeType::lfoFrequencies:
		break;
	case RangeType::oscPitch:
	{
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" "), dontSendNotification);
		textEditor.onEditorShow = [this, tooltipsOptions] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
			if (tooltipsOptions->shouldShowDescription()) {
				String description{ "" };
				description += "Type in either a pitch name and octave number\n";
				description += "(e.g. " + GUI::openQuote + "C#5" + GUI::closeQuote + ") or a MIDI note number (e.g. " + GUI::openQuote + "61" + GUI::closeQuote + ").\n";
				description += "Range: C0 (0) to C10 (120)";
				editor->setTooltip(description);
			}
		};
		textEditor.onTextChange = [this, paramIndex] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ (float)EP::numberOfChoicesForOscPitch };
				if (newSettingString.containsAnyOf("abcdefgABCDEFG#")) {
					newSettingString = newSettingString.toUpperCase();
					for (auto choiceNum = (uint8)0; choiceNum < EP::numberOfChoicesForOscPitch; ++choiceNum) {
						if (info->choiceNameFor(choiceNum, paramIndex).removeCharacters(" ") == newSettingString) {
							newSetting = (float)choiceNum;
							break;
						}
					}
				}
				else
					newSetting = newSettingString.getFloatValue();
				if (newSetting < (float)EP::numberOfChoicesForOscPitch)
					paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
			}
		};
	}
		break;
	case RangeType::oscShape:
		break;
	case RangeType::oscSlop:
		textEditor.setText((String)currentChoice, dontSendNotification);
		textEditor.onEditorShow = [this, tooltipsOptions] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(1, "012345");
			if (tooltipsOptions->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: 0 to 5)");
		};
		textEditor.onTextChange = [this] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ newSettingString.getFloatValue() };
				paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
			}
		};
		break;
	case RangeType::posNeg_127:
		break;
	case RangeType::posNumbers:
		break;
	default:
		break;
	}

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForExposedParamKnob::showEditor() {
	textEditor.showEditor();
}

void TextEditorForExposedParamKnob::valueChanged(Value& /*value*/) {
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	switch (rangeType)
	{
	case RangeType::fineTune:
		break;
	case RangeType::globalFineTune:
		break;
	case RangeType::lfoFrequencies:
		break;
	case RangeType::oscShape:
		break;
	case RangeType::oscPitch:
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" "), dontSendNotification);
		break;
	case RangeType::oscSlop:
		textEditor.setText((String)currentChoice, dontSendNotification);
		break;
	case RangeType::posNeg_127:
		break;
	case RangeType::posNumbers:
		break;
	default:
		break;
	}
}

TextEditorForExposedParamKnob::~TextEditorForExposedParamKnob() {
	parameterValue.removeListener(this);
}
