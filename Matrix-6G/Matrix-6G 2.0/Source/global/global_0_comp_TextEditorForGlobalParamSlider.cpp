#include "global_0_comp_TextEditorForGlobalParamSlider.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TextEditorForGlobalParamSlider::TextEditorForGlobalParamSlider(GlobalParamSliderType sliderType, UnexposedParameters* unexposedParams) :
	sliderType{ sliderType },
	global{ unexposedParams->getGlobalOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForSlider.toString());
	auto slider_w{ GUI::global_MIDI_Control_w };
	switch (sliderType)
	{
	case GlobalParamSliderType::basicChannel:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_BasicChannel);
		textEditor.onEditorShow = [this] { onEditorShow_BasicChannel(); };
		textEditor.onTextChange = [this] { onTextChange_BasicChannel(); };
		break;
	case GlobalParamSliderType::pedal_1_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_1_ControllerNumber);
		textEditor.onEditorShow = [this] { onEditorShow_ControllerNum(); };
		textEditor.onTextChange = [this] { onTextChange_ControllerNum(); };
		break;
	case GlobalParamSliderType::pedal_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Pedal_2_ControllerNumber);
		textEditor.onEditorShow = [this] { onEditorShow_ControllerNum(); };
		textEditor.onTextChange = [this] { onTextChange_ControllerNum(); };
		break;
	case GlobalParamSliderType::lever_2_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_2_ControllerNumber);
		textEditor.onEditorShow = [this] { onEditorShow_ControllerNum(); };
		textEditor.onTextChange = [this] { onTextChange_ControllerNum(); };
		break;
	case GlobalParamSliderType::lever_3_ControllerNum:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Lever_3_ControllerNumber);
		textEditor.onEditorShow = [this] { onEditorShow_ControllerNum(); };
		textEditor.onTextChange = [this] { onTextChange_ControllerNum(); };
		slider_w = 37;
		break;
	case GlobalParamSliderType::vibratoSpeed:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeed);
		textEditor.onEditorShow = [this] { onEditorShow_VibratoSliders(); };
		textEditor.onTextChange = [this] { onTextChange_VibratoSliders(); };
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoAmplitude:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmplitude);
		textEditor.onEditorShow = [this] { onEditorShow_VibratoSliders(); };
		textEditor.onTextChange = [this] { onTextChange_VibratoSliders(); };
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoSpeedModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoSpeedModAmount);
		textEditor.onEditorShow = [this] { onEditorShow_VibratoSliders(); };
		textEditor.onTextChange = [this] { onTextChange_VibratoSliders(); };
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::vibratoAmpModAmount:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_VibratoAmpModAmount);
		textEditor.onEditorShow = [this] { onEditorShow_VibratoSliders(); };
		textEditor.onTextChange = [this] { onTextChange_VibratoSliders(); };
		slider_w = GUI::global_VibratoControl_w;
		break;
	case GlobalParamSliderType::globalTune:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_Tune);
		textEditor.onEditorShow = [this] { onEditorShow_GlobalTune(); };
		textEditor.onTextChange = [this] { onTextChange_GlobalTune(); };
		slider_w = GUI::global_MiscControl_w;
		break;
	case GlobalParamSliderType::displayBrightness:
		globalParamAsValue = global->getGobalParamAsValue(ID::global_DisplayBrightness);
		textEditor.onEditorShow = [this] { onEditorShow_DisplayBrightness(); };
		textEditor.onTextChange = [this] { onTextChange_DisplayBrightness(); };
		slider_w = GUI::global_MiscControl_w;
		break;
	default:
		break;
	}
	setEditorTextUsingStoredValue();
	globalParamAsValue.addListener(this);

	setSize(slider_w, GUI::control_h);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForGlobalParamSlider::setEditorTextUsingStoredValue() {
	auto paramValue{ (int)globalParamAsValue.getValue() };
	String valueString{ "" };
	if (sliderType == GlobalParamSliderType::globalTune)
		textEditor.setText(String(paramValue - EP::offsetForSigned_7_BitRange), dontSendNotification);
	else
		textEditor.setText((String)paramValue, dontSendNotification);
}

void TextEditorForGlobalParamSlider::onEditorShow_BasicChannel() {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 1 to 16)");
}

void TextEditorForGlobalParamSlider::onEditorShow_ControllerNum() {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 121)");
}

void TextEditorForGlobalParamSlider::onEditorShow_VibratoSliders() {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 0 to 63)");
}

void TextEditorForGlobalParamSlider::onEditorShow_GlobalTune() {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(3, "-0123456789");
	editor->setJustification(Justification::centred);
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: -63 to 63)");
}

void TextEditorForGlobalParamSlider::onEditorShow_DisplayBrightness() {
	auto editor{ textEditor.getCurrentTextEditor() };
	editor->setInputRestrictions(2, "0123456789");
	if (tooltips->shouldShowDescription())
		editor->setTooltip("Type in a new setting.\n(Range: 1 to 31)");
}

void TextEditorForGlobalParamSlider::onTextChange_BasicChannel() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < 1)
			newSetting = 1;
		if (newSetting > 16)
			newSetting = 16;
		global->setBasicChannel((uint8)newSetting);
	}
}

void TextEditorForGlobalParamSlider::onTextChange_ControllerNum() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < 0)
			newSetting = 0;
		if (newSetting > 121)
			newSetting = 121;
		globalParamAsValue.setValue(newSetting);
	}
}

void TextEditorForGlobalParamSlider::onTextChange_VibratoSliders() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < 0)
			newSetting = 0;
		if (newSetting > 63)
			newSetting = 63;
		globalParamAsValue.setValue(newSetting);
	}
}

void TextEditorForGlobalParamSlider::onTextChange_GlobalTune() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < -63)
			newSetting = -63;
		if (newSetting > 63)
			newSetting = 63;
		global->setGlobalTune(uint8(newSetting + EP::offsetForSigned_7_BitRange));
	}
	else
		setEditorTextUsingStoredValue();
}

void TextEditorForGlobalParamSlider::onTextChange_DisplayBrightness() {
	auto newSettingString{ textEditor.getText() };
	if (newSettingString.isNotEmpty()) {
		auto newSetting{ newSettingString.getIntValue() };
		if (newSetting < 0)
			newSetting = 0;
		if (newSetting > 31)
			newSetting = 31;
		globalParamAsValue.setValue(newSetting);
	}
}

void TextEditorForGlobalParamSlider::showEditor() {
	textEditor.showEditor();
}

void TextEditorForGlobalParamSlider::valueChanged(Value& /*value*/) {
	setEditorTextUsingStoredValue();
}

TextEditorForGlobalParamSlider::~TextEditorForGlobalParamSlider() {
	globalParamAsValue.removeListener(this);
}
