#include "global_0_comp_TextEditorForGlobalParamKnob.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TextEditorForGlobalParamKnob::TextEditorForGlobalParamKnob(KnobType knobType, UnexposedParameters* unexposedParams) :
    knobType{ knobType }
{
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto tooltips{ unexposedParams->getTooltipsOptions() };

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForKnob.toString());
	textEditor.setFont(GUI::font_KnobValueDisplays);
	switch (knobType)
	{
	case KnobType::globalTranspose:
		globalParamAsValue = globalOptions->getGobalParamAsValue(ID::global_Transpose);
		textEditor.onEditorShow = [this, tooltips] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(3, "-0123456789");
			if (tooltips->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: -12 to 12)");
		};
		textEditor.onTextChange = [this, globalOptions] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ newSettingString.getIntValue() };
				if (newSetting < -12)
					newSetting = -12;
				if (newSetting > 12)
					newSetting = 12;
				globalOptions->setGlobalTranspose(uint8(newSetting + 12));
			}
			else
				setEditorTextUsingStoredValue();
		};
		break;
	case KnobType::globalFineTune:
		globalParamAsValue = globalOptions->getGobalParamAsValue(ID::global_FineTune);
		textEditor.onEditorShow = [this, tooltips] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(3, "-0123456789");
			if (tooltips->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: -50 to 50)");
		};
		textEditor.onTextChange = [this, globalOptions] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				auto newSetting{ newSettingString.getIntValue() };
				if (newSetting < -50)
					newSetting = -50;
				if (newSetting > 50)
					newSetting = 50;
				globalOptions->setGlobalFineTune(uint8(newSetting + 50));
			}
			else
				setEditorTextUsingStoredValue();
		};
		break;
	case KnobType::hardwareReceiveChannel:
		globalParamAsValue = globalOptions->getGobalParamAsValue(ID::global_HardwareReceiveChannel);
		textEditor.onEditorShow = [this, tooltips] {
			auto editor{ textEditor.getCurrentTextEditor() };
			editor->setInputRestrictions(3, "alAL0123456789");
			auto oq{ GUI::openQuote };
			auto cq{ GUI::closeQuote };
			if (tooltips->shouldShowDescription())
				editor->setTooltip("Type in a new setting.\n(Range: 1 to 16\nAll: " + oq + "ALL" + cq + " or " + oq + "0" + cq + ")");
		};
		textEditor.onTextChange = [this, globalOptions] {
			auto newSettingString{ textEditor.getText() };
			if (newSettingString.isNotEmpty()) {
				if (newSettingString.toUpperCase() == "ALL")
					globalOptions->setHardwareReceiveChannel((uint8)0);
				else {
					auto newSetting{ uint8(newSettingString.getIntValue()) };
					if (newSetting > (uint8)16)
						newSetting = (uint8)16;
					globalOptions->setHardwareReceiveChannel(newSetting);
				}
			}
			else
				setEditorTextUsingStoredValue();
		};
		break;
	default:
		break;
	}
	setEditorTextUsingStoredValue();
	globalParamAsValue.addListener(this);

	setSize(GUI::knob_diameter, GUI::knob_diameter);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForGlobalParamKnob::setEditorTextUsingStoredValue() {
	auto paramValue{ (int)globalParamAsValue.getValue() };
	switch (knobType)
	{
	case MophoConstants::GlobalParamKnobType::globalTranspose:
		textEditor.setText(String(paramValue - 12), dontSendNotification);
		break;
	case MophoConstants::GlobalParamKnobType::globalFineTune:
		textEditor.setText(String(paramValue - 50), dontSendNotification);
		break;
	case MophoConstants::GlobalParamKnobType::hardwareReceiveChannel:
		if (paramValue == 0)
			textEditor.setText("ALL", dontSendNotification);
		else
			textEditor.setText((String)paramValue, dontSendNotification);
		break;
	default:
		break;
	}
}

void TextEditorForGlobalParamKnob::showEditor() {
    textEditor.showEditor();
}

void TextEditorForGlobalParamKnob::valueChanged(Value& /*value*/) {
    setEditorTextUsingStoredValue();
}

TextEditorForGlobalParamKnob::~TextEditorForGlobalParamKnob() {
	globalParamAsValue.removeListener(this);
}
