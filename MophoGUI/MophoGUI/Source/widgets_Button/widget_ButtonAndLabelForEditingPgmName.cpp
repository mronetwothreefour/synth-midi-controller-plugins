#include "widget_ButtonAndLabelForEditingPgmName.h"

#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonAndLabelForEditingPgmName::ButtonAndLabelForEditingPgmName(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	pgmNameEditor{ "pgmNameEditor", "" },
	button_ForOpeningPgmNameEditor{ exposedParams, unexposedParams, pgmNameEditor },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
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
	pgmNameEditor.setText(button_ForOpeningPgmNameEditor.getProgramNameFromExposedParemeters(), dontSendNotification);
	addAndMakeVisible(pgmNameEditor);
	addAndMakeVisible(button_ForOpeningPgmNameEditor);

	auto buttonAndEditor_w{ 222 };
	auto buttonAndEditor_h{ 50 };
	setSize(buttonAndEditor_w, buttonAndEditor_h);
	button_ForOpeningPgmNameEditor.setBounds(115, 0, 42, 16);
	pgmNameEditor.setBounds(0, 32, 242, 18);
}

void ButtonAndLabelForEditingPgmName::labelTextChanged(Label* labelThatHasChanged) {
	if (labelThatHasChanged == &pgmNameEditor) {
		String newName{ labelThatHasChanged->getText() };
		padNamesLessThan16CharactersLongWithSpaces(newName);
	}
}

void ButtonAndLabelForEditingPgmName::padNamesLessThan16CharactersLongWithSpaces(String& name) {
	for (auto i = name.length(); i != 16; ++i)
		name += " ";
	startUpdatingProgramName(name);
}

void ButtonAndLabelForEditingPgmName::startUpdatingProgramName(String newName) {
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