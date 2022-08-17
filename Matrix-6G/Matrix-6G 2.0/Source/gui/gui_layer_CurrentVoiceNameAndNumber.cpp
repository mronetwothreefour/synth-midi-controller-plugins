#include "gui_layer_CurrentVoiceNameAndNumber.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_0_tree_CurrentVoiceOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;

GUI_Layer_CurrentVoiceNameAndNumber::GUI_Layer_CurrentVoiceNameAndNumber(CurrentVoiceOptions* currentVoiceOptions, TooltipsOptions* tooltips) :
    currentVoiceOptions{ currentVoiceOptions },
    tooltips{ tooltips }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionValue.addListener(this);

    currentVoiceNameValue = currentVoiceOptions->getCurrentVoicePropertyAsValue(ID::currentVoice_Name);
    currentVoiceNameValue.addListener(this);

    currentVoiceNumberValue = currentVoiceOptions->getCurrentVoicePropertyAsValue(ID::currentVoice_Number);
    currentVoiceNumberValue.addListener(this);

    voiceNameEditor.setFont(GUI::font_LabelEditors);
    voiceNameEditor.setComponentID(ID::comp_VoiceNameEditor.toString());
    voiceNameEditor.setEditable(true);
    voiceNameEditor.setText(currentVoiceOptions->currentVoiceName(), dontSendNotification);
    voiceNameEditor.onEditorShow = [this] {
        auto editor{ voiceNameEditor.getCurrentTextEditor() };
        editor->setInputRestrictions(VCS::numberOfCharsInVoiceName, allowed_ASCII_Characters);
    };
    voiceNameEditor.onTextChange = [this, currentVoiceOptions] {
        String labelText{ voiceNameEditor.getText() };
        String newName(labelText.toUpperCase());
        newName = newName.paddedRight(' ', VCS::numberOfCharsInVoiceName);
        voiceNameEditor.setText(newName, dontSendNotification);
        currentVoiceOptions->setCurrentVoiceName(newName);
    };
    voiceNameEditor.setBounds(873, 367, 117, 20);
    addAndMakeVisible(voiceNameEditor);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CurrentVoiceNameAndNumber::updateTooltips() {
}

void GUI_Layer_CurrentVoiceNameAndNumber::valueChanged(Value& value) {
    if (value.refersToSameSourceAs(shouldShowDescriptionValue))
        updateTooltips();
}

GUI_Layer_CurrentVoiceNameAndNumber::~GUI_Layer_CurrentVoiceNameAndNumber() {
    shouldShowDescriptionValue.removeListener(this);
    currentVoiceNameValue.removeListener(this);
    currentVoiceNumberValue.removeListener(this);
}
