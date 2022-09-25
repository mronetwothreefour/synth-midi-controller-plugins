#include "gui_layer_MainWindowButtons.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../global/global_1_gui_layer_CommError_NRPN.h"
#include "../global/global_1_gui_layer_CommError_SysEx.h"
#include "../global/global_2_gui_layer_GlobalParams.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../randomization/rndm_4_gui_layer_Randomization.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_8_gui_layer_VoicesBanks.h"

using namespace MophoConstants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    state{ exposedParams->state.get() },
    info{ exposedParams->info.get() },
    randomize{ exposedParams->randomize.get() },
    unexposedParams{ unexposedParams },
    global{ unexposedParams->getGlobalOptions() },
    tooltips{ unexposedParams->getTooltipsOptions() },
    btn_Hyperlink{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    voiceNameEditor.setInterceptsMouseClicks(false, true);
    voiceNameEditor.setFont(GUI::font_VoiceNameEditorText);
    voiceNameEditor.setComponentID(ID::lbl_VoiceNameEditor.toString());
    voiceNameEditor.setJustificationType(Justification::centredLeft);
    voiceNameEditor.setColour(Label::textColourId, GUI::color_White.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::outlineColourId, GUI::color_Black.withAlpha(0.0f));
    voiceNameEditor.setColour(Label::textWhenEditingColourId, GUI::color_White);
    voiceNameEditor.setColour(Label::backgroundWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.setColour(Label::outlineWhenEditingColourId, GUI::color_Black);
    voiceNameEditor.onTextChange = [this] {
        String newName{ voiceNameEditor.getText() };
        newName = newName.paddedRight(' ', VCS::numberOfCharsInVoiceName);
        startUpdatingVoiceName(newName);
    };
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    voiceNameEditor.setBounds(590, 38, 222, 26);
    addAndMakeVisible(voiceNameEditor);

    btn_ShowVoiceNameEditor.setComponentID(ID::btn_Edit.toString());
    btn_ShowVoiceNameEditor.onClick = [this] { showVoiceNameEditor(); };
    btn_ShowVoiceNameEditor.setBounds(708, 11, 34, 18);
    addAndMakeVisible(btn_ShowVoiceNameEditor);

    auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };

    const int rowBeneathProgramName_y{ 83 };
    const int writeReadButtons_w{ 44 };
    btn_WriteEditBuffer.setComponentID(ID::btn_Write_EditBuffer.toString());
    btn_WriteEditBuffer.onClick = [exposedParams, outgoingBuffers] {
        SysExMessages::addEditBufferDataMessageToOutgoingBuffers(exposedParams, outgoingBuffers);
    };
    btn_WriteEditBuffer.setBounds(580, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);
    btn_WriteEditBuffer.addShortcut(KeyPress{ 'w', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_WriteEditBuffer);

    btn_ReadEditBuffer.setComponentID(ID::btn_Read.toString());
    btn_ReadEditBuffer.onClick = [outgoingBuffers] {
        SysExMessages::addRequestForEditBufferDataToOutgoingBuffers(outgoingBuffers);
    };
    btn_ReadEditBuffer.setBounds(632, rowBeneathProgramName_y, writeReadButtons_w, GUI::redButton_h);
    btn_ReadEditBuffer.addShortcut(KeyPress{ 'r', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ReadEditBuffer);

    btn_ShowVoicesBanks.setComponentID(ID::btn_Banks.toString());
    btn_ShowVoicesBanks.onClick = [this] { showVoicesBanksLayer(); };
    btn_ShowVoicesBanks.setBounds(684, rowBeneathProgramName_y, 47, GUI::redButton_h);
    btn_ShowVoicesBanks.addShortcut(KeyPress{ 'b', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowVoicesBanks);

    btn_ShowGlobalParams.setComponentID(ID::btn_Global.toString());
    btn_ShowGlobalParams.onClick = [this] { prepareToShowGlobalParamsLayer(); };
    btn_ShowGlobalParams.setBounds(739, rowBeneathProgramName_y, 53, GUI::redButton_h);
    btn_ShowGlobalParams.addShortcut(KeyPress{ 'g', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowGlobalParams);

    btn_Randomize.setComponentID(ID::btn_Randomize.toString());
    btn_Randomize.addMouseListener(this, false);
    btn_Randomize.addListener(this);
    btn_Randomize.onClick = [this] {
        if (ModifierKeys::currentModifiers != ModifierKeys::ctrlModifier + ModifierKeys::altModifier && wasRightClicked == false)
            randomize->randomizeAllUnlockedParameters();
        wasRightClicked = false;
    };
    btn_Randomize.setBounds(800, rowBeneathProgramName_y, GUI::btn_Randomize_w, GUI::redButton_h);
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier + ModifierKeys::altModifier, 0 });
    addAndMakeVisible(btn_Randomize);

    const int undoRedoButtons_w{ 44 };
    const int undoRedoButtons_x{ 832 };
    btn_Undo.setComponentID(ID::btn_Undo.toString());
    btn_Undo.onClick = [exposedParams] {
        exposedParams->undoManager.undo();
    };
    btn_Undo.setBounds(undoRedoButtons_x, 19, undoRedoButtons_w, GUI::redButton_h);
    btn_Undo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Undo);

    btn_Redo.setComponentID(ID::btn_Redo.toString());
    btn_Redo.onClick = [exposedParams] {
        exposedParams->undoManager.redo();
    };
    btn_Redo.setBounds(undoRedoButtons_x, 48, undoRedoButtons_w, GUI::redButton_h);
    btn_Redo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier + ModifierKeys::shiftModifier, 0 });
    addAndMakeVisible(btn_Redo);

    btn_Hyperlink.setComponentID(ID::btn_Hyperlink.toString());
    btn_Hyperlink.setBounds(644, 122, 157, 9);
    addAndMakeVisible(btn_Hyperlink);

    const int clearButton_SeqTrack_1_y{ 160 };
    for (auto trackNum = 0; trackNum != 4; ++trackNum) {
        btns_ClearSeqTracks[trackNum].setComponentID(ID::btn_Clear.toString());
        btns_ClearSeqTracks[trackNum].onClick = [this, trackNum] { startClearingSeqTrack(trackNum); };
        btns_ClearSeqTracks[trackNum].setBounds(1212, clearButton_SeqTrack_1_y + trackNum * GUI::seqTrackControlsGroup_h, 46, 18);
        addAndMakeVisible(btns_ClearSeqTracks[trackNum]);
    }

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_ShowVoiceNameEditor{ shouldShow ? Description::buildForShowVoiceNameEditor() : String{ "" } };
    btn_ShowVoiceNameEditor.setTooltip(tipFor_btn_ShowVoiceNameEditor);

    auto tipFor_btn_Write{ shouldShow ? Description::buildForEditBufferWrite() : String{ "" } };
    btn_WriteEditBuffer.setTooltip(tipFor_btn_Write);

    auto tipFor_btn_Read{ shouldShow ? Description::buildForEditBufferRead() : String{ "" } };
    btn_ReadEditBuffer.setTooltip(tipFor_btn_Read);

    auto tipFor_btn_Banks{ shouldShow ? Description::buildForShowVoicesBanksLayer() : String{ "" } };
    btn_ShowVoicesBanks.setTooltip(tipFor_btn_Banks);

    auto tipFor_btn_Global{ shouldShow ? Description::buildForShowGlobalParamsLayer() : String{ "" } };
    btn_ShowGlobalParams.setTooltip(tipFor_btn_Global);

    auto tipFor_btn_Randomize{ shouldShow ? Description::buildForShowRandomizationLayer() : String{ "" } };
    btn_Randomize.setTooltip(tipFor_btn_Randomize);

    auto tipFor_btn_Undo{ shouldShow ? Description::buildForUndo() : String{ "" } };
    btn_Undo.setTooltip(tipFor_btn_Undo);

    auto tipFor_btn_Redo{ shouldShow ? Description::buildForRedo() : String{ "" } };
    btn_Redo.setTooltip(tipFor_btn_Redo);

    auto tipFor_btn_Hyperlink{ shouldShow ? Description::buildForHyperlink() : String{ "" } };
    btn_Hyperlink.setTooltip(tipFor_btn_Hyperlink);
}

void GUI_Layer_MainWindowButtons::showVoiceNameEditor() {
    voiceNameEditor.setText(getVoiceNameFromExposedParemeters(), dontSendNotification);
    voiceNameEditor.showEditor();
    voiceNameEditor.getCurrentTextEditor()->setInputRestrictions(VCS::numberOfCharsInVoiceName, basic_ASCII_Characters);
    auto shouldShow{ tooltips->shouldShowDescription() };
    auto tipFor_VoiceNameEditor{ shouldShow ? Description::buildForVoiceNameEditor() : String{ "" } };
    voiceNameEditor.getCurrentTextEditor()->setTooltip(tipFor_VoiceNameEditor);
}

String GUI_Layer_MainWindowButtons::getVoiceNameFromExposedParemeters() {
    std::string currentVoiceName{ "" };
    for (auto charNum = 0; charNum != VCS::numberOfCharsInVoiceName; ++charNum) {
        auto paramID{ info->IDfor(uint8(EP::firstVoiceNameCharParamIndex + charNum)) };
        auto paramPtr{ state->getParameter(paramID) };
        if (paramPtr != nullptr)
            currentVoiceName += std::string(1, char(roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue()))));
    }
    return currentVoiceName;
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
    auto paramID{ info->IDfor(uint8(EP::firstVoiceNameCharParamIndex + nameCharNum)) };
    auto paramPtr{ state->getParameter(paramID) };
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
    auto param{ state->getParameter(paramID) };
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
    auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
    SysExMessages::addRequestForGlobalParamsDataToOutgoingBuffers(outgoingBuffers);
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
    layer_Randomization.reset(new GUI_Layer_Randomization{ exposedParams, unexposedParams });
    if (layer_Randomization != nullptr) {
        addAndMakeVisible(layer_Randomization.get());
        layer_Randomization->setBounds(getLocalBounds());
        layer_Randomization->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& event) {
    if (btn_Randomize.isMouseOver() == true) {
        if (event.mods == ModifierKeys::rightButtonModifier) {
            wasRightClicked = true;
            showRandomizationLayer();
        }
    }
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
    if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier + ModifierKeys::altModifier)
        showRandomizationLayer();
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    layer_VoicesBanks = nullptr;
    layer_CommError_NRPN = nullptr;
    layer_CommError_SysEx = nullptr;
    layer_GlobalParams = nullptr;
    layer_Randomization = nullptr;
    shouldShowDescriptionAsValue.removeListener(this);
    btn_Randomize.removeListener(this);
    btn_Randomize.removeMouseListener(this);
}
