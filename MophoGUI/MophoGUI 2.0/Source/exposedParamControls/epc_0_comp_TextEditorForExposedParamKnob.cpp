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
	case RangeType::lfoFrequency:
		break;
	case RangeType::oscFineTune:
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex), dontSendNotification);
		textEditor.onEditorShow = [this, tooltipsOptions] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(3, "-0123456789");
			if (tooltipsOptions->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: -50 to 50)");
		};
		textEditor.onTextChange = [this, paramIndex] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ newSettingString.getFloatValue() + 50.0f };
				if (newSetting < 0.0f)
					newSetting = 0.0f;
				if (newSetting > 101.0f)
					newSetting = 101.0f;
				paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
			}
		};
		break;
	case RangeType::oscPitch:
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
				auto newSetting{ -1.0f };
				if (newSettingString.containsAnyOf("abcdefgABCDEFG#")) {
					newSettingString = newSettingString.toUpperCase();
					for (auto choiceNum = (uint8)0; choiceNum != EP::numberOfChoicesForOscPitch; ++choiceNum) {
						if (info->choiceNameFor(choiceNum, paramIndex).removeCharacters(" ") == newSettingString) {
							newSetting = (float)choiceNum;
							break;
						}
					}
				}
				else 				{
					newSetting = newSettingString.getFloatValue();
					if (newSetting >= (float)EP::numberOfChoicesForOscPitch)
						newSetting = (float)EP::numberOfChoicesForOscPitch - 1.0f;
				}
				if (newSetting > -1.0f)
					paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
			}
		};
		break;
	case RangeType::oscShape:
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex), dontSendNotification);
		textEditor.onEditorShow = [this, tooltipsOptions] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(4, "afiopqrstwAFIOPQRSTW0123456789/");
			if (tooltipsOptions->shouldShowDescription()) {
				String description{ "" };
				description += "Type in a new shape setting.\n";
				description += "Off: " + GUI::openQuote + "OFF" + GUI::closeQuote + " or " + GUI::openQuote + "0" + GUI::closeQuote + "\n";
				description += "Sawtooth: " + GUI::openQuote + "SAW" + GUI::closeQuote + " or " + GUI::openQuote + "1" + GUI::closeQuote + "\n";
				description += "Triangle: " + GUI::openQuote + "TRI" + GUI::closeQuote + " or " + GUI::openQuote + "2" + GUI::closeQuote + "\n";
				description += "Sawtooth/Triangle Mix: " + GUI::openQuote + "S/T" + GUI::closeQuote + " or " + GUI::openQuote + "3" + GUI::closeQuote + "\n";
				description += "Square (Pulse Width 50): " + GUI::openQuote + "SQR" + GUI::closeQuote + " or " + GUI::openQuote + "54" + GUI::closeQuote + "\n";
				description += "Pulse Width 0..99: " + GUI::openQuote + "PW0" + GUI::closeQuote + ".." + GUI::openQuote + "PW99" + GUI::closeQuote + " or " + GUI::openQuote + "4" + GUI::closeQuote + ".." + GUI::openQuote + "104" + GUI::closeQuote;
				editor->setTooltip(description);
			}
		};
		textEditor.onTextChange = [this, paramIndex] {
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
				if (newSetting > -1.0f) {
					if (newSetting >= (float)EP::numberOfChoicesForOscWaveShape)
						newSetting = (float)EP::numberOfChoicesForOscWaveShape;
					paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSetting));
				}
			}
		};
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
	case RangeType::lfoFrequency:
		break;
	case RangeType::oscFineTune:
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex), dontSendNotification);
		break;
	case RangeType::oscShape:
		textEditor.setText(info->choiceNameFor(currentChoice, paramIndex), dontSendNotification);
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
