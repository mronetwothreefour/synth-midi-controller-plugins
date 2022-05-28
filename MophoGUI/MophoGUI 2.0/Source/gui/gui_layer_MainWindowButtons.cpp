#include "gui_layer_MainWindowButtons.h"

#include "gui_build_ButtonDescriptionString.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Voices.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../midi/1_midi_EditBufferDataMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using EditBuffer = EditBufferDataMessage;
using TipString = ButtonDescriptionString;



GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    voiceNameEditor{ "voiceNameEditor", "" },
    button_Hyperlink{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);

    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    tooltipsOptions->addListener(this);

    voiceNameEditor.setInterceptsMouseClicks(false, true);
    voiceNameEditor.setFont(GUI::fontFor_VoiceNameEditorText);
    voiceNameEditor.setComponentID(ID::label_VoiceNameEditor.toString());
    voiceNameEditor.setJustificationType(Justification::centredLeft);
    voiceNameEditor.setColour(Label::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::outlineColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::textWhenEditingColourId, GUI::color_White);
    voiceNameEditor.setColour(Label::backgroundWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.setColour(Label::outlineWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.addListener(this);
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    addAndMakeVisible(voiceNameEditor);

    button_ShowVoiceNameEditor.setComponentID(ID::button_Edit.toString());
    button_ShowVoiceNameEditor.onClick = [this] { showVoiceNameEditor(); };
    addAndMakeVisible(button_ShowVoiceNameEditor);

    auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };

    button_WriteEditBuffer.setComponentID(ID::button_Write.toString());
    button_WriteEditBuffer.onClick = [exposedParams, outgoingBuffers] {
        EditBuffer::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, outgoingBuffers);
    };
    addAndMakeVisible(button_WriteEditBuffer);

    button_ReadEditBuffer.setComponentID(ID::button_Read.toString());
    button_ReadEditBuffer.onClick = [outgoingBuffers] {
        EditBuffer::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(outgoingBuffers);
    };
    addAndMakeVisible(button_ReadEditBuffer);

    button_Undo.setComponentID(ID::button_Undo.toString());
    button_Undo.onClick = [unexposedParams] {
        unexposedParams->getUndoManager()->undo();
    };
    addAndMakeVisible(button_Undo);

    button_Redo.setComponentID(ID::button_Redo.toString());
    button_Redo.onClick = [unexposedParams] {
        unexposedParams->getUndoManager()->redo();
    };
    addAndMakeVisible(button_Redo);

    button_Hyperlink.setComponentID(ID::button_Hyperlink.toString());
    addAndMakeVisible(button_Hyperlink);

    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        buttons_ForClearingSeqTracks[trackNum].setComponentID(ID::button_Clear.toString());
        buttons_ForClearingSeqTracks[trackNum].onClick = [this, trackNum] { startClearingSeqTrack(trackNum); };
        addAndMakeVisible(buttons_ForClearingSeqTracks[trackNum]);
    }

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_ShouldShowDescription)
        updateTooltips();
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    auto shouldShow{ tooltipsOptions->shouldShowDescriptions() };

    auto tipFor_button_ShowVoiceNameEditor{ shouldShow ? TipString::buildFor_ShowVoiceNameEditor() : String{ "" } };
    button_ShowVoiceNameEditor.setTooltip(tipFor_button_ShowVoiceNameEditor);

    auto tipFor_button_Write{ shouldShow ? TipString::buildFor_EditBufferWrite() : String{ "" } };
    button_WriteEditBuffer.setTooltip(tipFor_button_Write);

    auto tipFor_button_Read{ shouldShow ? TipString::buildFor_EditBufferRead() : String{ "" } };
    button_ReadEditBuffer.setTooltip(tipFor_button_Read);

    auto tipFor_button_Undo{ shouldShow ? TipString::buildFor_Undo() : String{ "" } };
    button_Undo.setTooltip(tipFor_button_Undo);

    auto tipFor_button_Redo{ shouldShow ? TipString::buildFor_Redo() : String{ "" } };
    button_Redo.setTooltip(tipFor_button_Redo);

    auto tipFor_button_Hyperlink{ shouldShow ? TipString::buildFor_Hyperlink() : String{ "" } };
    button_Hyperlink.setTooltip(tipFor_button_Hyperlink);

    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        auto tipFor_button_Clear{ shouldShow ? TipString::buildFor_ClearSeqTrack(trackNum) : String{ "" } };
        buttons_ForClearingSeqTracks[trackNum].setTooltip(tipFor_button_Clear);
    }
}

void GUI_Layer_MainWindowButtons::showVoiceNameEditor() {
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    voiceNameEditor.showEditor();
    voiceNameEditor.getCurrentTextEditor()->setInputRestrictions(Voices::numberOfCharsInVoiceName, basicASCIIcharacters);
    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    auto shouldShow{ tooltipsOptions->shouldShowDescriptions() };
    auto tipFor_VoiceNameEditor{ shouldShow ? TipString::buildFor_VoiceNameEditor() : String{ "" } };
    voiceNameEditor.getCurrentTextEditor()->setTooltip(tipFor_VoiceNameEditor);
}

String GUI_Layer_MainWindowButtons::getVoiceNameFromExposedParemeters() {
    std::string currentVoiceName{ "" };
    auto& info{ InfoForExposedParameters::get() };
    for (auto charNum = 0; charNum != Voices::numberOfCharsInVoiceName; ++charNum) {
        auto paramID{ info.IDfor(uint8(EP::firstVoiceNameCharParamNumber + charNum)) };
        auto paramPtr{ exposedParams->getParameter(paramID) };
        if (paramPtr != nullptr)
            currentVoiceName += std::string(1, char(roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue()))));
    }
    return currentVoiceName;
}

void GUI_Layer_MainWindowButtons::labelTextChanged(Label* labelThatHasChanged) {
    if (labelThatHasChanged == &voiceNameEditor) {
        String newName{ labelThatHasChanged->getText() };
        newName = newName.paddedRight(' ', Voices::numberOfCharsInVoiceName);
        startUpdatingVoiceName(newName);
    }
}

void GUI_Layer_MainWindowButtons::startUpdatingVoiceName(String newName) {
    voiceName = newName;
    nameCharNum = 0;
    MultiTimer::startTimer(timerID_VoiceNameEdit, 10);
}

void GUI_Layer_MainWindowButtons::startClearingSeqTrack(int trackNum) {
    sequencerStep = 0;
    MultiTimer::startTimer(trackNum, 10);
}

void GUI_Layer_MainWindowButtons::timerCallback(int timerID) {
    MultiTimer::stopTimer(timerID);
    if (timerID == timerID_VoiceNameEdit) {
        if (nameCharNum > -1 && nameCharNum < Voices::numberOfCharsInVoiceName) {
            updateExposedParamForNameChar();
        }
    }
    else {
        if (sequencerStep > -1 && sequencerStep < 16) {
            clearSequencerStep(timerID, sequencerStep);
            if (sequencerStep < 15) {
                ++sequencerStep;
                MultiTimer::startTimer(timerID, 10);
            }
            else
                sequencerStep = -1;
        }
    }
}

void GUI_Layer_MainWindowButtons::updateExposedParamForNameChar() {
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(uint8(EP::firstVoiceNameCharParamNumber + nameCharNum)) };
    auto paramPtr{ exposedParams->getParameter(paramID) };
    if (paramPtr != nullptr)
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1((float)voiceName[nameCharNum]));
    if (nameCharNum < Voices::numberOfCharsInVoiceName - 1) {
        ++nameCharNum;
        MultiTimer::startTimer(timerID_VoiceNameEdit, 10);
    }
    else
        nameCharNum = -1;
}

void GUI_Layer_MainWindowButtons::clearSequencerStep(int trackNum, int stepNum) {
    auto clearedValue{ trackNum == 0 ? 1.0f : 0.0f };
    auto& info{ InfoForExposedParameters::get() };
    auto paramID{ info.IDfor(uint8(EP::firstSeqStepParamNumber + trackNum * 16 + stepNum)) };
    auto param{ exposedParams->getParameter(paramID) };
    if (param != nullptr)
        param->setValueNotifyingHost(clearedValue);
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& /*event*/) {
    // todo: use for opening randomization layer with right-click
}

void GUI_Layer_MainWindowButtons::resized() {
    button_ShowVoiceNameEditor.setBounds(708, 11, 34, 18);
    voiceNameEditor.setBounds(590, 38, 222, 26);

    const int rowBeneathProgramName_y{ 83 };
    const int writeReadButtons_w{ 44 };
    button_WriteEditBuffer.setBounds(580, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);
    button_ReadEditBuffer.setBounds(632, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);

    const int undoRedoButtons_w{ 44 };
    const int undoRedoButtons_x{ 832 };
    button_Undo.setBounds(undoRedoButtons_x, 19, undoRedoButtons_w, GUI::redButton_h);
    button_Redo.setBounds(undoRedoButtons_x, 48, undoRedoButtons_w, GUI::redButton_h);

    button_Hyperlink.setBounds(644, 122, 157, 9);

    const int clearButton_SeqTrack_1_y{ 160 };
    for (auto trackNum = 0; trackNum != 4; ++trackNum)
        buttons_ForClearingSeqTracks[trackNum].setBounds(1166, clearButton_SeqTrack_1_y + trackNum * GUI::seqTrackControlsGroup_h, 46, 18);
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
    tooltipsOptions->removeListener(this);
    voiceNameEditor.removeListener(this);
}
