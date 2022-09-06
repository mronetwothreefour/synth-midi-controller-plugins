#include "epc_0_comp_TextEditorForExposedParamKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_1_tree_InfoForExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForExposedParamKnob::TextEditorForExposedParamKnob(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltipsOptions) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	paramPtr{ exposedParams->state->getParameter(info->IDfor(paramIndex)) }
{
	auto controlType{ info->controlTypeFor(paramIndex) };
	jassert(controlType == ControlType::knob || controlType == ControlType::knobForPitch);

	paramAsValue = exposedParams->state->getParameterAsValue(info->IDfor(paramIndex));
	paramAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForKnob.toString());
	textEditor.setFont(GUI::font_KnobValueDisplay);
	if (controlType == ControlType::knob) {
		textEditor.onEditorShow = [this, paramIndex, tooltipsOptions] {
			auto maxValue{ info->numberOfChoicesFor(paramIndex) - 1 };
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(maxValue > 99 ? 3 : 2, "0123456789");
			editor->setJustification(Justification::centred);
			if (tooltipsOptions->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: 0 to " + (String)maxValue + ")");
		};
		textEditor.onTextChange = [this] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty())
				paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newSettingString.getFloatValue()));
			else
				setEditorText();
		};
	}
	else {
		textEditor.onEditorShow = [this, paramIndex, tooltipsOptions] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(3, "abcdefgABCDEFG0123456789#");
			editor->setJustification(Justification::centred);
			if (tooltipsOptions->shouldShowDescription()) {
				String description{ "" };
				description += "Type in either a pitch name and octave number\n";
				description += "(e.g. " + oq + "C#3" + cq + ") or a MIDI note number (e.g. " + oq + "37" + cq + ").\n";
				description += "Range: C0 (0) to C4 (48)";
				editor->setTooltip(description);
			}
		};
		textEditor.onTextChange = [this, paramIndex] {
			auto newSettingString{ textEditor.getText().toUpperCase() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ -1.0f };
				if (newSettingString.containsAnyOf("abcdefgABCDEFG#")) {
					auto numberOfChoices{ EP::numberOfChoicesForOscFreq };
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
		};
	}
	setEditorText();

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForExposedParamKnob::setEditorText() {
	auto currentChoice{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
	auto currentChoiceName{ info->choiceNameFor(currentChoice, paramIndex).removeCharacters(" ") };
	textEditor.setText(currentChoiceName, dontSendNotification);
}

void TextEditorForExposedParamKnob::showEditor() {
	textEditor.showEditor();
}

void TextEditorForExposedParamKnob::valueChanged(Value& /*value*/) {
	setEditorText();
}

TextEditorForExposedParamKnob::~TextEditorForExposedParamKnob() {
	paramAsValue.removeListener(this);
}
