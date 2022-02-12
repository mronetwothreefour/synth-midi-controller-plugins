#include "widget_ButtonForOpeningVoiceNameEditor.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForOpeningVoiceNameEditor::ButtonForOpeningVoiceNameEditor(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, Label& voiceNameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	voiceNameEditor{ voiceNameEditor }
{
	setComponentID(ID::button_VoiceNameEdit.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForOpeningVoiceNameEditor::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens an editor where you can\n";
		buttonTooltip += "type in a new program name.";
	}
	return buttonTooltip;
}

void ButtonForOpeningVoiceNameEditor::onClickMethod() {
	voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
	voiceNameEditor.showEditor();
	String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
	voiceNameEditor.getCurrentTextEditor()->setInputRestrictions(16, basicASCIIcharacters);
	String nameEditorTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		nameEditorTooltip += "Type in a new name for the program (max. 16 characters) and hit ENTER\n";
		nameEditorTooltip += "to apply it. Hit ESC to cancel. The Mopho" + GUI::apostrophe + "s hardware LCD characters use\n";
		nameEditorTooltip += "the basic ASCII character set, with a few exceptions: " + GUI::openQuote + "\\" + GUI::closeQuote + " becomes\n";
		nameEditorTooltip += "a yen sign and " + GUI::openQuote + "~" + GUI::closeQuote + " (tilde) becomes a right arrow. The " + GUI::openQuote + "delete" + GUI::closeQuote + " character\n";
		nameEditorTooltip += "becomes a left arrow; obviously, you can" + GUI::apostrophe + "t type that in the editor. However,\n";
		nameEditorTooltip += "you can access it by changing a character in the GUI" + GUI::apostrophe + "s name display with\n";
		nameEditorTooltip += "the mouse. The hardware name display will not update immediately - press\n";
		nameEditorTooltip += "the Program Mode button to see the new name.";
	}
	voiceNameEditor.getCurrentTextEditor()->setTooltip(nameEditorTooltip);
}

String ButtonForOpeningVoiceNameEditor::getVoiceNameFromExposedParemeters() {
	std::string voiceName{ "" };
	for (auto i = 1; i != 17; ++i) {
		auto param{ exposedParams->getParameter("nameChar" + (String)i) };
		voiceName += std::string(1, char(roundToInt(param->getValue() * 127)));
	}
	return voiceName;
}

