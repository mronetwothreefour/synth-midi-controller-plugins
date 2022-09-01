#include "gui_layer_CurrentVoiceNameAndNumber.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_0_tree_CurrentVoiceOptions.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;

GUI_Layer_CurrentVoiceNameAndNumber::GUI_Layer_CurrentVoiceNameAndNumber(CurrentVoiceOptions* currentVoiceOptions, TooltipsOptions* tooltips) :
    voiceNumber{ nullptr },
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

    Rectangle<int> voiceNumberBounds{ 840, 367, 28, 20 };

    voiceNumber.setRange(0.0, 99.0, 1.0);
    voiceNumber.addMouseListener(this, false);
    voiceNumber.setValue((double)currentVoiceOptions->currentVoiceNumber());
    voiceNumber.setMouseDragSensitivity(160);
    voiceNumber.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
    voiceNumber.onValueChange = [this, currentVoiceOptions] { 
        auto newSetting{ (uint8)roundToInt(voiceNumber.getValue()) };
        currentVoiceOptions->setCurrentVoiceNumber(newSetting);
    };
    voiceNumber.setBounds(voiceNumberBounds);
    addAndMakeVisible(voiceNumber);

    voiceNumberEditor.setInterceptsMouseClicks(false, true);
    voiceNumberEditor.setFont(GUI::font_LabelEditors);
    voiceNumberEditor.onEditorShow = [this, tooltips] {
        auto editor{ voiceNumberEditor.getCurrentTextEditor() };
        editor->setInputRestrictions(2, "0123456789");
        editor->setJustification(Justification::centredRight);
        if (tooltips->shouldShowDescription())
            editor->setTooltip("Type in a new setting.\n(Range: 0 to 99)");
    };
    voiceNumberEditor.onTextChange = [this, currentVoiceOptions] {
        auto newSettingString{ voiceNumberEditor.getText() };
        if (newSettingString.isNotEmpty()) {
            auto newSetting{ (uint8)newSettingString.getIntValue() };
            currentVoiceOptions->setCurrentVoiceNumber(newSetting);
        }
        else
            setVoiceNumberEditorText();
    };
    setVoiceNumberEditorText();
    voiceNumberEditor.setBounds(voiceNumberBounds);
    addAndMakeVisible(voiceNumberEditor);

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

void GUI_Layer_CurrentVoiceNameAndNumber::setVoiceNumberEditorText() {
    auto voiceNumberString{ String(currentVoiceOptions->currentVoiceNumber()).paddedLeft('0', 2) };
    voiceNumberEditor.setText(voiceNumberString, dontSendNotification);
}

void GUI_Layer_CurrentVoiceNameAndNumber::updateTooltips() {
    String voiceNumberDescription{ "" };
    String voiceNamDescription{ "" };
    if (tooltips->shouldShowDescription()) {
        voiceNumberDescription += "Selects which patch storage slot\n";
        voiceNumberDescription += "on the hardware is the target of the\n";
        voiceNumberDescription += "PUSH and PULL buttons to the left.\n";
        voiceNumberDescription += "Range: 0 to 99.";

        voiceNamDescription += "Click to edit the name of the patch (8 characters max.)\n";
        voiceNamDescription += "The name cannot be changed via Quick Patch Edit. Use the\n";
        voiceNamDescription += "PUSH button to send the entire patch instead.";
    }
    voiceNumber.setTooltip(voiceNumberDescription);
    voiceNameEditor.setTooltip(voiceNamDescription);
}

void GUI_Layer_CurrentVoiceNameAndNumber::mouseDoubleClick(const MouseEvent& /*event*/) {
    voiceNumberEditor.showEditor();
}

void GUI_Layer_CurrentVoiceNameAndNumber::valueChanged(Value& value) {
    if (value.refersToSameSourceAs(currentVoiceNumberValue)) {
        auto currentVoiceNumber{ currentVoiceOptions->currentVoiceNumber() };
        voiceNumber.setValue((double)currentVoiceNumber, dontSendNotification);
        setVoiceNumberEditorText();
    }
    if (value.refersToSameSourceAs(shouldShowDescriptionValue))
        updateTooltips();
}

GUI_Layer_CurrentVoiceNameAndNumber::~GUI_Layer_CurrentVoiceNameAndNumber() {
    shouldShowDescriptionValue.removeListener(this);
    currentVoiceNameValue.removeListener(this);
    currentVoiceNumberValue.removeListener(this);
    voiceNumber.removeMouseListener(this);
}
