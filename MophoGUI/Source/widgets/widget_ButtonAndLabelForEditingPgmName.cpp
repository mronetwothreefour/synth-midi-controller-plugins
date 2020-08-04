#include "widget_ButtonAndLabelForEditingPgmName.h"

#include "../helpers/helper_CustomColors.h"


ButtonAndLabelForEditingPgmName::ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams) :
	button{ "EDIT" },
	exposedParams{ exposedParams },
	pgmNameEditor{ "pgmNameEditor", getProgramNameFromExposedParemeters() }
{
	setInterceptsMouseClicks(false, true);

	pgmNameEditor.setInterceptsMouseClicks(false, true);
	pgmNameEditor.setComponentID("pgmNameEditor");
	pgmNameEditor.setJustificationType(Justification::centredLeft);
	pgmNameEditor.setColour(Label::backgroundColourId, Colours::transparentBlack);
	pgmNameEditor.setColour(Label::outlineColourId, Colours::transparentBlack);
	pgmNameEditor.setColour(Label::textWhenEditingColourId, Color::controlText);
	pgmNameEditor.setColour(Label::backgroundWhenEditingColourId, Color::black);
	pgmNameEditor.setColour(Label::outlineWhenEditingColourId, Color::black);
	pgmNameEditor.addListener(this);
	addAndMakeVisible(pgmNameEditor);

	addAndMakeVisible(button);
	String tooltipString;
	tooltipString =  "Opens an editor where you can\n";
	tooltipString += "type in a new program name.";
	button.setTooltip(tooltipString);
	button.onClick = [this] { showPgmNameEditor(); };

	auto buttonAndEditor_w{ 222 };
	auto buttonAndEditor_h{ 50 };
	setSize(buttonAndEditor_w, buttonAndEditor_h);
	button.setBounds(115, 0, 42, 16);
	pgmNameEditor.setBounds(0, 32, 242, 18);
}

void ButtonAndLabelForEditingPgmName::showPgmNameEditor() {
	pgmNameEditor.setText(getProgramNameFromExposedParemeters(), dontSendNotification);
	pgmNameEditor.showEditor();
	String basicASCIIcharacters{ " !\"#$ % &'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" };
	pgmNameEditor.getCurrentTextEditor()->setInputRestrictions(16, basicASCIIcharacters);
	String nameEditorTooltip;
	nameEditorTooltip =  "Type in a new name for the program (max. 16 characters) and hit Enter to apply it.\n";
	nameEditorTooltip += "Hit Esc to cancel. The Mopho's hardware LCD characters use the basic ASCII\n";
	nameEditorTooltip += "character set, with a few exceptions: 'backslash' becomes a yen sign and 'tilde'\n";
	nameEditorTooltip += "becomes a right arrow. The 'delete' character becomes a left arrow; obviously,\n";
	nameEditorTooltip += "you can't type that in the editor. However, you can access it by changing a\n";
	nameEditorTooltip += "character in the GUI's name display with the mouse. The hardware name display\n";
	nameEditorTooltip += "will not update immediately - press the Program Mode button to see the new name.";
	pgmNameEditor.getCurrentTextEditor()->setTooltip(nameEditorTooltip);
}

String ButtonAndLabelForEditingPgmName::getProgramNameFromExposedParemeters() {
	std::string pgmName{ "" };
	for (auto i = 1; i != 17; ++i) {
		auto param{ exposedParams->getParameter("nameChar" + (String)i) };
		pgmName += std::string(1, char(roundToInt(param->getValue() * 127)));
	}
	return pgmName;
}

void ButtonAndLabelForEditingPgmName::labelTextChanged(Label* labelThatHasChanged) {
	String newName{ labelThatHasChanged->getText() };
	addSpacesToEndOfName(newName);
}

void ButtonAndLabelForEditingPgmName::addSpacesToEndOfName(String& name) {
	for (auto i = name.length(); i != 16; ++i)
		name += " ";
	updateProgramNameOnHardware(name);
}

void ButtonAndLabelForEditingPgmName::updateProgramNameOnHardware(String newName) {
	programName = newName;
	nameCharacter = 0;
	startTimer(10);
}

void ButtonAndLabelForEditingPgmName::timerCallback() {
	stopTimer();
	if (nameCharacter > -1 && nameCharacter < 16) {
		updateNameCharacterInExposedParams();
	}
}

void ButtonAndLabelForEditingPgmName::updateNameCharacterInExposedParams() {
	auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharacter + 1)) };
	if (param != nullptr) {
		auto normalizedValue{ (char)programName[nameCharacter] / 127.0f };
		param->setValueNotifyingHost(normalizedValue);
	}
	if (nameCharacter < 15) {
		++nameCharacter;
		startTimer(10);
	}
	else
		nameCharacter = -1;
}

ButtonAndLabelForEditingPgmName::~ButtonAndLabelForEditingPgmName() {
	pgmNameEditor.removeListener(this);
}
