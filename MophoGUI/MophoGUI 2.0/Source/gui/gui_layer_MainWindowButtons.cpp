#include "gui_layer_MainWindowButtons.h"

#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Voices.h"
#include "../constants/constants_Identifiers.h"
#include "../global/global_1_gui_layer_CommError_NRPN.h"
#include "../global/global_1_gui_layer_CommError_SysEx.h"
#include "../global/global_2_gui_layer_GlobalParams.h"
#include "../midi/midi_1_EditBufferDataMessage.h"
#include "../midi/midi_1_GlobalParametersDataRequest.h"
#include "../randomization/rndm_0_ParamRandomizationMethods.h"
#include "../randomization//rndm_4_gui_layer_Randomization.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"
#include "../voices/voices_7_gui_layer_VoicesBanks.h"

using namespace MophoConstants;
using Description = MainWindowButtonDescription;
using EditBuffer = EditBufferDataMessage;



GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    info{ unexposedParams->getInfoForExposedParameters() },
    global{ unexposedParams->getGlobalOptions() },
    randomize{ new ParamRandomizationMethods(exposedParams, unexposedParams) },
    tooltips{ unexposedParams->getTooltipsOptions() },
    voiceNameEditor{ "voiceNameEditor", "" },
    button_Hyperlink{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);

    tooltips->addListener(this);

    voiceNameEditor.setInterceptsMouseClicks(false, true);
    voiceNameEditor.setFont(GUI::fontFor_VoiceNameEditorText);
    voiceNameEditor.setComponentID(ID::label_VoiceNameEditor.toString());
    voiceNameEditor.setJustificationType(Justification::centredLeft);
    voiceNameEditor.setColour(Label::textColourId, GUI::color_White.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::outlineColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::textWhenEditingColourId, GUI::color_White);
    voiceNameEditor.setColour(Label::backgroundWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.setColour(Label::outlineWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.addListener(this);
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    voiceNameEditor.setBounds(590, 38, 222, 26);
    addAndMakeVisible(voiceNameEditor);

    button_ShowVoiceNameEditor.setComponentID(ID::button_Edit.toString());
    button_ShowVoiceNameEditor.onClick = [this] { showVoiceNameEditor(); };
    button_ShowVoiceNameEditor.setBounds(708, 11, 34, 18);
    addAndMakeVisible(button_ShowVoiceNameEditor);

    const int rowBeneathProgramName_y{ 83 };
    const int writeReadButtons_w{ 44 };
    button_WriteEditBuffer.setComponentID(ID::button_Write_EditBuffer.toString());
    button_WriteEditBuffer.onClick = [exposedParams, unexposedParams] {
        EditBuffer::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams);
    };
    button_WriteEditBuffer.setBounds(580, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);
    addAndMakeVisible(button_WriteEditBuffer);

    auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };

    button_ReadEditBuffer.setComponentID(ID::button_Read.toString());
    button_ReadEditBuffer.onClick = [outgoingBuffers] {
        EditBuffer::addRequestForEditBufferDataMessageToOutgoingMidiBuffers(outgoingBuffers);
    };
    button_ReadEditBuffer.setBounds(632, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);
    addAndMakeVisible(button_ReadEditBuffer);

    button_ShowVoicesBanks.setComponentID(ID::button_Banks.toString());
    button_ShowVoicesBanks.onClick = [this] { showVoicesBanksLayer(); };
    button_ShowVoicesBanks.setBounds(684, rowBeneathProgramName_y, 47, GUI::redButton_h);
    addAndMakeVisible(button_ShowVoicesBanks);

    button_ShowGlobalParams.setComponentID(ID::button_Global.toString());
    button_ShowGlobalParams.onClick = [this] { prepareToShowGlobalParamsLayer(); };
    button_ShowGlobalParams.setBounds(739, rowBeneathProgramName_y, 53, GUI::redButton_h);
    addAndMakeVisible(button_ShowGlobalParams);

    button_Randomize.setComponentID(ID::button_Randomize.toString());
    button_Randomize.addMouseListener(this, false);
    button_Randomize.setBounds(800, rowBeneathProgramName_y, GUI::button_Randomize_w, GUI::redButton_h);
    addAndMakeVisible(button_Randomize);

    const int undoRedoButtons_w{ 44 };
    const int undoRedoButtons_x{ 832 };
    button_Undo.setComponentID(ID::button_Undo.toString());
    button_Undo.onClick = [unexposedParams] {
        unexposedParams->getUndoManager()->undo();
    };
    button_Undo.setBounds(undoRedoButtons_x, 19, undoRedoButtons_w, GUI::redButton_h);
    addAndMakeVisible(button_Undo);

    button_Redo.setComponentID(ID::button_Redo.toString());
    button_Redo.onClick = [unexposedParams] {
        unexposedParams->getUndoManager()->redo();
    };
    button_Redo.setBounds(undoRedoButtons_x, 48, undoRedoButtons_w, GUI::redButton_h);
    addAndMakeVisible(button_Redo);

    button_Hyperlink.setComponentID(ID::button_Hyperlink.toString());
    button_Hyperlink.setBounds(644, 122, 157, 9);
    addAndMakeVisible(button_Hyperlink);

    const int clearButton_SeqTrack_1_y{ 160 };
    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        buttons_ForClearingSeqTracks[trackNum].setComponentID(ID::button_Clear.toString());
        buttons_ForClearingSeqTracks[trackNum].onClick = [this, trackNum] { startClearingSeqTrack(trackNum); };
        buttons_ForClearingSeqTracks[trackNum].setBounds(1212, clearButton_SeqTrack_1_y + trackNum * GUI::seqTrackControlsGroup_h, 46, 18);
        addAndMakeVisible(buttons_ForClearingSeqTracks[trackNum]);
    }

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_ShowDescription)
        updateTooltips();
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescriptions() };

    auto tipFor_button_ShowVoiceNameEditor{ shouldShow ? Description::buildFor_ShowVoiceNameEditor() : String{ "" } };
    button_ShowVoiceNameEditor.setTooltip(tipFor_button_ShowVoiceNameEditor);

    auto tipFor_button_Write{ shouldShow ? Description::buildFor_EditBufferWrite() : String{ "" } };
    button_WriteEditBuffer.setTooltip(tipFor_button_Write);

    auto tipFor_button_Read{ shouldShow ? Description::buildFor_EditBufferRead() : String{ "" } };
    button_ReadEditBuffer.setTooltip(tipFor_button_Read);

    auto tipFor_button_Banks{ shouldShow ? Description::buildFor_ShowVoicesBanksLayer() : String{ "" } };
    button_ShowVoicesBanks.setTooltip(tipFor_button_Banks);

    auto tipFor_button_Global{ shouldShow ? Description::buildFor_ShowGlobalParamsLayer() : String{ "" } };
    button_ShowGlobalParams.setTooltip(tipFor_button_Global);

    auto tipFor_button_Randomize{ shouldShow ? Description::buildFor_ShowRandomizationLayer() : String{ "" } };
    button_Randomize.setTooltip(tipFor_button_Randomize);

    auto tipFor_button_Undo{ shouldShow ? Description::buildFor_Undo() : String{ "" } };
    button_Undo.setTooltip(tipFor_button_Undo);

    auto tipFor_button_Redo{ shouldShow ? Description::buildFor_Redo() : String{ "" } };
    button_Redo.setTooltip(tipFor_button_Redo);

    auto tipFor_button_Hyperlink{ shouldShow ? Description::buildFor_Hyperlink() : String{ "" } };
    button_Hyperlink.setTooltip(tipFor_button_Hyperlink);

    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        auto tipFor_button_Clear{ shouldShow ? Description::buildFor_ClearSeqTrack(trackNum) : String{ "" } };
        buttons_ForClearingSeqTracks[trackNum].setTooltip(tipFor_button_Clear);
    }
}

void GUI_Layer_MainWindowButtons::showVoiceNameEditor() {
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    voiceNameEditor.showEditor();
    voiceNameEditor.getCurrentTextEditor()->setInputRestrictions(VCS::numberOfCharsInVoiceName, basicASCIIcharacters);
    auto shouldShow{ tooltips->shouldShowDescriptions() };
    auto tipFor_VoiceNameEditor{ shouldShow ? Description::buildFor_VoiceNameEditor() : String{ "" } };
    voiceNameEditor.getCurrentTextEditor()->setTooltip(tipFor_VoiceNameEditor);
}

String GUI_Layer_MainWindowButtons::getVoiceNameFromExposedParemeters() {
    std::string currentVoiceName{ "" };
    for (auto charNum = 0; charNum != VCS::numberOfCharsInVoiceName; ++charNum) {
        auto paramID{ info->IDfor(uint8(EP::firstVoiceNameCharParamNumber + charNum)) };
        auto paramPtr{ exposedParams->getParameter(paramID) };
        if (paramPtr != nullptr)
            currentVoiceName += std::string(1, char(roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue()))));
    }
    return currentVoiceName;
}

void GUI_Layer_MainWindowButtons::labelTextChanged(Label* labelThatHasChanged) {
    String newName{ labelThatHasChanged->getText() };
    newName = newName.paddedRight(' ', VCS::numberOfCharsInVoiceName);
    startUpdatingVoiceName(newName);
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
        if (nameCharNum > -1 && nameCharNum < VCS::numberOfCharsInVoiceName) {
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
    auto paramID{ info->IDfor(uint8(EP::firstVoiceNameCharParamNumber + nameCharNum)) };
    auto paramPtr{ exposedParams->getParameter(paramID) };
    if (paramPtr != nullptr)
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1((float)voiceName[nameCharNum]));
    if (nameCharNum < VCS::numberOfCharsInVoiceName - 1) {
        ++nameCharNum;
        MultiTimer::startTimer(timerID_VoiceNameEdit, 10);
    }
    else
        nameCharNum = -1;
}

void GUI_Layer_MainWindowButtons::clearSequencerStep(int trackNum, int stepNum) {
    auto clearedValue{ trackNum == 0 ? 1.0f : 0.0f };
    auto paramID{ info->IDfor(uint8(EP::firstSeqStepParamIndex + trackNum * 16 + stepNum)) };
    auto param{ exposedParams->getParameter(paramID) };
    if (param != nullptr)
        param->setValueNotifyingHost(clearedValue);
}

void GUI_Layer_MainWindowButtons::showVoicesBanksLayer() {
    layer_VoicesBanks.reset(new GUI_Layer_VoicesBanks{ exposedParams, unexposedParams });
    if (layer_VoicesBanks != nullptr) {
        addAndMakeVisible(layer_VoicesBanks.get());
        layer_VoicesBanks->setBounds(getLocalBounds());
        layer_VoicesBanks->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::prepareToShowGlobalParamsLayer() {
    layer_GlobalParams = nullptr;
    global->resetAllOptionsToDefaults();
    auto outgoingMidiBuffers{ unexposedParams->getOutgoingMidiBuffers() };
    GlobalParametersDataRequest::addToOutgoingMidiBuffers(outgoingMidiBuffers);
    callAfterDelay(300, [this] {
        if (global->sysExIsEnabled()) {
            if (global->hardwareIsNotSetToReceiveNRPNcontrollers())
                showCommError_NRPN_Layer();
            else
                showGlobalParamsLayer();
        }
        else showCommError_SysExLayer();
    });
}

void GUI_Layer_MainWindowButtons::showCommError_SysExLayer() {
    layer_CommError_SysEx.reset(new GUI_Layer_CommError_SysEx{ unexposedParams });
    if (layer_CommError_SysEx != nullptr) {
        addAndMakeVisible(layer_CommError_SysEx.get());
        layer_CommError_SysEx->setBounds(getLocalBounds());
        layer_CommError_SysEx->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showCommError_NRPN_Layer() {
    layer_CommError_NRPN.reset(new GUI_Layer_CommError_NRPN{ unexposedParams });
    if (layer_CommError_NRPN != nullptr) {
        addAndMakeVisible(layer_CommError_NRPN.get());
        layer_CommError_NRPN->setBounds(getLocalBounds());
        layer_CommError_NRPN->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showGlobalParamsLayer() {
    layer_GlobalParams.reset(new GUI_Layer_GlobalParameters{ unexposedParams });
    if (layer_GlobalParams != nullptr) {
        addAndMakeVisible(layer_GlobalParams.get());
        layer_GlobalParams->setBounds(getLocalBounds());
        layer_GlobalParams->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showRandomizationLayer() {
    layer_Randomization = nullptr;
    layer_Randomization.reset(new GUI_Layer_Randomization{ exposedParams, unexposedParams, randomize.get() });
    if (layer_Randomization != nullptr) {
        addAndMakeVisible(layer_Randomization.get());
        layer_Randomization->setBounds(getLocalBounds());
        layer_Randomization->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& event) {
    if (event.mods == ModifierKeys::rightButtonModifier)
        showRandomizationLayer();
    else
        randomize->randomizeAllUnlockedParameters();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    layer_GlobalParams = nullptr;
    layer_VoicesBanks = nullptr;
    layer_CommError_NRPN = nullptr;
    layer_CommError_SysEx = nullptr;
    layer_Randomization = nullptr;
    randomize = nullptr;
    tooltips->removeListener(this);
    button_Randomize.removeMouseListener(this);
    voiceNameEditor.removeListener(this);
}
