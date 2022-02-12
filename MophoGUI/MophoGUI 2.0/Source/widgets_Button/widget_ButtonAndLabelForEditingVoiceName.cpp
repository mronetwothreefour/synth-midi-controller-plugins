#include "widget_ButtonAndLabelForEditingVoiceName.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"

using namespace constants;



ButtonAndLabelForEditingVoiceName::ButtonAndLabelForEditingVoiceName(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	voiceNameEditor{ "voiceNameEditor", "" },
	button_ForOpeningVoiceNameEditor{ exposedParams, unexposedParams, voiceNameEditor },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams }
{
	setInterceptsMouseClicks(false, true);

	voiceNameEditor.setInterceptsMouseClicks(false, true);
	voiceNameEditor.setFont(FontsMenu::fontFor_VoiceNameEditorText);
	voiceNameEditor.setComponentID(ID::component_VoiceNameEditLabel.toString());
	voiceNameEditor.setJustificationType(Justification::centredLeft);
	voiceNameEditor.setColour(Label::backgroundColourId, Colours::transparentBlack);
	voiceNameEditor.setColour(Label::outlineColourId, Colours::transparentBlack);
	voiceNameEditor.setColour(Label::textWhenEditingColourId, Color::controlText);
	voiceNameEditor.setColour(Label::backgroundWhenEditingColourId, Color::black);
	voiceNameEditor.setColour(Label::outlineWhenEditingColourId, Color::black);
	voiceNameEditor.addListener(this);
	voiceNameEditor.setText(button_ForOpeningVoiceNameEditor.getVoiceNameFromExposedParemeters(), dontSendNotification);
	addAndMakeVisible(voiceNameEditor);
	addAndMakeVisible(button_ForOpeningVoiceNameEditor);

	setSize(GUI::editVoiceNameButtonAndLabel_w, GUI::editVoiceNameButtonAndLabel_h);
	button_ForOpeningVoiceNameEditor.setBounds(GUI::bounds_VoiceNameEditorButton);
	voiceNameEditor.setBounds(GUI::bounds_VoiceNameEditorLabel);
}

void ButtonAndLabelForEditingVoiceName::labelTextChanged(Label* labelThatHasChanged) {
	if (labelThatHasChanged == &voiceNameEditor) {
		String newName{ labelThatHasChanged->getText() };
		newName = newName.paddedRight(' ', voices::numberOfCharsInVoiceName);
		startUpdatingVoiceName(newName);
	}
}

void ButtonAndLabelForEditingVoiceName::startUpdatingVoiceName(String newName) {
	voiceName = newName;
	nameCharacter = 0;
	startTimer(10);
}

void ButtonAndLabelForEditingVoiceName::timerCallback() {
	stopTimer();
	if (nameCharacter > -1 && nameCharacter < voices::numberOfCharsInVoiceName) {
		updateNameCharacterInExposedParams();
	}
}

void ButtonAndLabelForEditingVoiceName::updateNameCharacterInExposedParams() {
	auto param{ exposedParams->getParameter("nameChar" + (String)(nameCharacter + 1)) };
	if (param != nullptr) {
		auto normalizedValue{ (char)voiceName[nameCharacter] / 127.0f };
		param->setValueNotifyingHost(normalizedValue);
	}
	if (nameCharacter < voices::numberOfCharsInVoiceName - 1) {
		++nameCharacter;
		startTimer(10);
	}
	else
		nameCharacter = -1;
}

ButtonAndLabelForEditingVoiceName::~ButtonAndLabelForEditingVoiceName() {
	voiceNameEditor.removeListener(this);
}
