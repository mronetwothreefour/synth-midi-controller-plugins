#include "gui_layer_CurrentVoiceNumber.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

GUI_Layer_CurrentVoiceNumber::GUI_Layer_CurrentVoiceNumber(UnexposedParameters* unexposedParams) :
    tooltips{ unexposedParams->getTooltipsOptions() },
    transmitOptions{unexposedParams->getVoiceTransmissionOptions() },
    voiceNumber{nullptr}
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    currentVoiceNumberAsValue = transmitOptions->getCurrentVoiceNumberAsValue();
    currentVoiceNumberAsValue.addListener(this);

    Rectangle<int> voiceNumberBounds{ 408, 42, 60, 50 };

    voiceNumber.setComponentID(ID::comp_VoiceNumberSlider.toString());
    voiceNumber.setRange(0.0, 99.0, 1.0);
    voiceNumber.addMouseListener(this, false);
    voiceNumber.setValue((double)transmitOptions->currentVoiceNumber());
    voiceNumber.setMouseDragSensitivity(160);
    voiceNumber.setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
    voiceNumber.onValueChange = [this] {
        auto newSetting{ (uint8)roundToInt(voiceNumber.getValue()) };
        transmitOptions->setCurrentVoiceNumber(newSetting);
    };
    voiceNumber.setBounds(voiceNumberBounds);
    addAndMakeVisible(voiceNumber);

    voiceNumberEditor.setComponentID(ID::comp_TextEditorForVoiceNumberSlider.toString());
    voiceNumberEditor.setInterceptsMouseClicks(false, true);
    voiceNumberEditor.setFont(GUI::font_VoiceNumberEditor);
    voiceNumberEditor.onEditorShow = [this] {
        auto editor{ voiceNumberEditor.getCurrentTextEditor() };
        editor->setInputRestrictions(2, "0123456789");
        editor->setJustification(Justification::centred);
        if (tooltips->shouldShowDescription())
            editor->setTooltip("Type in a new setting.\n(Range: 0 to 99)");
    };
    voiceNumberEditor.onTextChange = [this] {
        auto newSettingString{ voiceNumberEditor.getText() };
        if (newSettingString.isNotEmpty()) {
            auto newSetting{ (uint8)newSettingString.getIntValue() };
            transmitOptions->setCurrentVoiceNumber(newSetting);
        }
        else
            setVoiceNumberEditorText();
    };
    setVoiceNumberEditorText();
    voiceNumberEditor.setBounds(voiceNumberBounds);
    addAndMakeVisible(voiceNumberEditor);

    updateTooltip();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CurrentVoiceNumber::setVoiceNumberEditorText() {
    auto voiceNumberString{ String(transmitOptions->currentVoiceNumber()).paddedLeft('0', 2) };
    voiceNumberEditor.setText(voiceNumberString, dontSendNotification);
}

void GUI_Layer_CurrentVoiceNumber::updateTooltip() {
    String description{ "" };
    if (tooltips->shouldShowDescription()) {
        description += "Selects which program storage slot\n";
        description += "on the hardware is the target of the\n";
        description += "PUSH and PULL buttons to the right.\n";
        description += "Hold down the SHIFT key when using\n";
        description += "the mouse wheel to increment by 10.\n";
        description += "Range: 0 to 99.";
    }
    voiceNumber.setTooltip(description);
}

void GUI_Layer_CurrentVoiceNumber::mouseDoubleClick(const MouseEvent& /*event*/) {
    voiceNumberEditor.showEditor();
}

void GUI_Layer_CurrentVoiceNumber::valueChanged(Value& value) {
    if (value.refersToSameSourceAs(currentVoiceNumberAsValue)) {
        auto currentVoiceNumber{ transmitOptions->currentVoiceNumber() };
        voiceNumber.setValue((double)currentVoiceNumber, dontSendNotification);
        setVoiceNumberEditorText();
    }
    if (value.refersToSameSourceAs(shouldShowDescriptionAsValue))
        updateTooltip();
}

GUI_Layer_CurrentVoiceNumber::~GUI_Layer_CurrentVoiceNumber() {
    shouldShowDescriptionAsValue.removeListener(this);
    currentVoiceNumberAsValue.removeListener(this);
    voiceNumber.removeMouseListener(this);
}
