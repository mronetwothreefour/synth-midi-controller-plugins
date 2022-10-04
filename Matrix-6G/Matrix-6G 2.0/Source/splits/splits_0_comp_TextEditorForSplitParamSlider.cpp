#include "splits_0_comp_TextEditorForSplitParamSlider.h"

#include "splits_0_build_ChoiceName.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TextEditorForSplitParamSlider::TextEditorForSplitParamSlider(SliderType sliderType, UnexposedParameters* unexposedParams) :
	sliderType{ sliderType }
{
	auto splitOptions{ unexposedParams->getSplitOptions() };
	auto tooltips{ unexposedParams->getTooltipsOptions() };

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForSlider.toString());
	auto lowerZone{ true };
	auto upperZone{ false };
	switch (sliderType)
	{
	case SliderType::zoneVolumeBalance:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_ZoneVolumeBalance);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneVolumeBalance(splitOptions, tooltips); };
		textEditor.onTextChange = [this, splitOptions] { onTextChange_ZoneVolumeBalance(splitOptions); };
		break;
	case SliderType::lowerZoneLimit:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneLimit);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneLimit(splitOptions, tooltips); };
		textEditor.onTextChange = [this, lowerZone, splitOptions] { onTextChange_ZoneLimit(lowerZone, splitOptions); };
		textEditor.setSize(172, 20);
		break;
	case SliderType::lowerZoneVoiceNum:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneVoiceNumber);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneVoiceNumber(splitOptions, tooltips); };
		textEditor.onTextChange = [this, lowerZone, splitOptions] { onTextChange_ZoneVoiceNumber(lowerZone, splitOptions); };
		break;
	case SliderType::lowerZoneTranspose:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_LowerZoneTranspose);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneTranspose(splitOptions, tooltips); };
		textEditor.onTextChange = [this, lowerZone, splitOptions] { onTextChange_ZoneTranspose(lowerZone, splitOptions); };
		break;
	case SliderType::upperZoneLimit:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneLimit);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneLimit(splitOptions, tooltips); };
		textEditor.onTextChange = [this, upperZone, splitOptions] { onTextChange_ZoneLimit(upperZone, splitOptions); };
		break;
	case SliderType::upperZoneVoiceNum:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneVoiceNumber);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneVoiceNumber(splitOptions, tooltips); };
		textEditor.onTextChange = [this, upperZone, splitOptions] { onTextChange_ZoneVoiceNumber(upperZone, splitOptions); };
		break;
	case SliderType::upperZoneTranspose:
		splitParamAsValue = splitOptions->getSplitParamAsValue(ID::split_UpperZoneTranspose);
		textEditor.onEditorShow = [this, splitOptions, tooltips] { onEditorShow_ZoneTranspose(splitOptions, tooltips); };
		textEditor.onTextChange = [this, upperZone, splitOptions] { onTextChange_ZoneTranspose(upperZone, splitOptions); };
		break;
	default:
		break;
	}
	setEditorTextUsingStoredValue();
	setSize(getParentComponent()->getWidth(), GUI::control_h);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForSplitParamSlider::setEditorTextUsingStoredValue() {
	auto paramValue{ (int)splitParamAsValue.getValue() };
	if (sliderType == SliderType::zoneVolumeBalance)
		textEditor.setText(String(paramValue - 31), dontSendNotification);
	if (sliderType == SliderType::lowerZoneLimit || sliderType == SliderType::upperZoneLimit)
		textEditor.setText(SplitParamChoiceName::buildForZoneLimit(paramValue, false), dontSendNotification);
	if (sliderType == SliderType::lowerZoneVoiceNum || sliderType == SliderType::upperZoneVoiceNum)
		textEditor.setText(String(paramValue).paddedLeft('0', 2), dontSendNotification);
	if (sliderType == SliderType::lowerZoneTranspose || sliderType == SliderType::upperZoneTranspose)
		SplitParamChoiceName::buildForZoneTranspose(paramValue, false);
}

void TextEditorForSplitParamSlider::onEditorShow_ZoneVolumeBalance(SplitOptions* splitOptions, TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -31 to 31)");
}

void TextEditorForSplitParamSlider::onEditorShow_ZoneLimit(SplitOptions* splitOptions, TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(4, "abcdefgABCDEFG0123456789#");
	if (tooltips->shouldShowDescription()) {
		String description{ "" };
		description += "Type in either a pitch name and octave number\n";
		description += "(e.g. " + oq + "C#5" + cq + ") or a MIDI note number (e.g. " + oq + "61" + cq + ").\n";
		description += "Range: C0 (0) to G10 (127)";
		editor->setTooltip(description);
	}
}

void TextEditorForSplitParamSlider::onEditorShow_ZoneVoiceNumber(SplitOptions* splitOptions, TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new patch number.\n(Range: 0 to 99)");
}

void TextEditorForSplitParamSlider::onEditorShow_ZoneTranspose(SplitOptions* splitOptions, TooltipsOptions* tooltips) {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -36 to 24)");
}

void TextEditorForSplitParamSlider::onTextChange_ZoneVolumeBalance(SplitOptions* splitOptions) {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < -31)
			newSetting = -31;
		if (newSetting > 31)
			newSetting = 31;
		splitOptions->setZoneVolumeBalance(uint8(newSetting + 31));
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForSplitParamSlider::onTextChange_ZoneLimit(bool isLowerZone, SplitOptions* splitOptions) {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ -1 };
		if (newSettingString.containsAnyOf("abcdefgABCDEFG#")) {
			newSettingString = newSettingString.toUpperCase();
			for (auto choiceNum = 0; choiceNum != SPLT::numberOfChoicesForZoneLimit; ++choiceNum) {
				if (SplitParamChoiceName::buildForZoneLimit(choiceNum, false).removeCharacters(" ") == newSettingString) {
					newSetting = choiceNum;
					break;
				}
			}
		}
		else
			newSetting = newSettingString.getIntValue();
		if (newSetting > -1) {
			if (isLowerZone)
				splitOptions->setLowerZoneLimit(newSetting);
			else
				splitOptions->setUpperZoneLimit(newSetting);
		}
		else
			setEditorTextUsingStoredValue();
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForSplitParamSlider::onTextChange_ZoneVoiceNumber(bool isLowerZone, SplitOptions* splitOptions) {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting > 99)
			newSetting = 99;
		splitOptions->setZoneVolumeBalance(uint8(newSetting));
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForSplitParamSlider::onTextChange_ZoneTranspose(bool isLowerZone, SplitOptions* splitOptions) {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < -36)
			newSetting = -36;
		if (newSetting > 24)
			newSetting = 24;
		splitOptions->setZoneVolumeBalance(uint8(newSetting + 36));
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForSplitParamSlider::showEditor() {
	textEditor.showEditor();
}

void TextEditorForSplitParamSlider::valueChanged(Value& value) {
	setEditorTextUsingStoredValue();
}

TextEditorForSplitParamSlider::~TextEditorForSplitParamSlider() {
	paramAsValue.removeListener(this);
}
