#include "global_0_comp_TextEditorForVoiceMapSlider.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_GlobalOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

TextEditorForVoiceMapSlider::TextEditorForVoiceMapSlider(uint8 mapSlotNum, VoiceMapSliderType type, GlobalOptions* global, TooltipsOptions* tooltips)
{
	Identifier paramID{ (type == VoiceMapSliderType::in ? ID::global_VoiceMapIn_.toString() : ID::global_VoiceMapOut_.toString()) + (String)mapSlotNum };
	globalParamAsValue = global->getGobalParamAsValue(paramID);
	globalParamAsValue.addListener(this);

	setInterceptsMouseClicks(false, true);
	textEditor.setInterceptsMouseClicks(false, true);
	textEditor.setComponentID(ID::comp_TextEditorForSlider.toString());
	textEditor.onEditorShow = [this, tooltips] {
		auto editor{ textEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(2, "0123456789");
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type in a new setting.\n(Range: 0 to 99)");
	};
	textEditor.onTextChange = [this] {
		auto newSettingString{ textEditor.getText() };
		if (newSettingString.isNotEmpty()) {
			auto newSetting{ newSettingString.getIntValue() };
			if (newSetting < 0)
				newSetting = 0;
			if (newSetting > 99)
				newSetting = 99;
			globalParamAsValue.setValue((uint8)newSetting);
		}
		else
			setEditorTextUsingStoredValue();
	};
	setEditorTextUsingStoredValue();
	setSize(GUI::voiceMapSlider_w, GUI::control_h);
	textEditor.setBounds(getLocalBounds());
	addAndMakeVisible(textEditor);
}

void TextEditorForVoiceMapSlider::setEditorTextUsingStoredValue() {
	auto paramValue{ (int)globalParamAsValue.getValue() };
	textEditor.setText((String)paramValue, dontSendNotification);
}

void TextEditorForVoiceMapSlider::showEditor() {
	textEditor.showEditor();
}

void TextEditorForVoiceMapSlider::valueChanged(Value& /*value*/) {
	setEditorTextUsingStoredValue();
}

TextEditorForVoiceMapSlider::~TextEditorForVoiceMapSlider() {
	globalParamAsValue.removeListener(this);
}
