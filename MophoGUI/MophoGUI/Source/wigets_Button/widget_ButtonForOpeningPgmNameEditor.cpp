#include "widget_ButtonForOpeningPgmNameEditor.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonForOpeningPgmNameEditor::ButtonForOpeningPgmNameEditor(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, Label& pgmNameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ "EDIT", unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	pgmNameEditor{ pgmNameEditor }
{
	setTooltip(createButtonTooltipString());
}

const String ButtonForOpeningPgmNameEditor::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Opens an editor where you can\n";
		buttonTooltip += "type in a new program name.";
	}
	return buttonTooltip;
}

void ButtonForOpeningPgmNameEditor::onClickMethod() {
	pgmNameEditor.setText(getProgramNameFromExposedParemeters(), dontSendNotification);
	pgmNameEditor.showEditor();
	String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
	pgmNameEditor.getCurrentTextEditor()->setInputRestrictions(16, basicASCIIcharacters);
	String nameEditorTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		nameEditorTooltip += "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
		nameEditorTooltip += "Hit Esc to cancel. The Mopho's hardware LCD characters use the basic ASCII\n";
		nameEditorTooltip += "character set, with a few exceptions: 'backslash' becomes a yen sign and 'tilde'\n";
		nameEditorTooltip += "becomes a right arrow. The 'delete' character becomes a left arrow; obviously,\n";
		nameEditorTooltip += "you can't type that in the editor. However, you can access it by changing a\n";
		nameEditorTooltip += "character in the GUI's name display with the mouse. The hardware name display\n";
		nameEditorTooltip += "will not update immediately - press the Program Mode button to see the new name.";
	}
	pgmNameEditor.getCurrentTextEditor()->setTooltip(nameEditorTooltip);
}

String ButtonForOpeningPgmNameEditor::getProgramNameFromExposedParemeters() {
	std::string pgmName{ "" };
	for (auto i = 1; i != 17; ++i) {
		auto param{ exposedParams->getParameter("nameChar" + (String)i) };
		pgmName += std::string(1, char(roundToInt(param->getValue() * 127)));
	}
	return pgmName;
}

ButtonForOpeningPgmNameEditor::~ButtonForOpeningPgmNameEditor() {
}
