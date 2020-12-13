#include "widget_ButtonForOpeningPgmNameEditor.h"

#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonForOpeningPgmNameEditor::ButtonForOpeningPgmNameEditor(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, Label& pgmNameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	pgmNameEditor{ pgmNameEditor }
{
	setComponentID(ID::button_PgmNameEdit.toString());
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
		nameEditorTooltip += "Type in a new name for the program (max. 16 characters) and hit Enter\n";
		nameEditorTooltip += "to apply it. Hit Esc to cancel. The Mopho's hardware LCD characters use\n";
		nameEditorTooltip += "the basic ASCII character set, with a few exceptions: 'backslash' becomes\n";
		nameEditorTooltip += "a yen sign and 'tilde' becomes a right arrow. The 'delete' character\n";
		nameEditorTooltip += "becomes a left arrow; obviously, you can't type that in the editor. However,\n";
		nameEditorTooltip += "you can access it by changing a character in the GUI's name display with\n";
		nameEditorTooltip += "the mouse. The hardware name display will not update immediately - press\n";
		nameEditorTooltip += "the Program Mode button to see the new name.";
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

