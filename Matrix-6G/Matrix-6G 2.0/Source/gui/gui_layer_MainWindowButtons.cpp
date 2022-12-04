#include "gui_layer_MainWindowButtons.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../global/global_3_gui_layer_CommError.h"
#include "../global/global_4_gui_layer_GlobalParams.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../randomization/rndm_3_gui_layer_Randomization.h"
#include "../splits/splits_4_gui_layer_Splits.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_7_gui_layer_VoicesBanks.h"

using namespace Matrix_6G_Constants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    info{ exposedParams->info.get() },
    randomize{ exposedParams->randomize.get() },
    unexposedParams{ unexposedParams },
    global{ unexposedParams->getGlobalOptions() },
    outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
    tooltips{ unexposedParams->getTooltipsOptions() },
    btn_ActivateQuickEdit{ unexposedParams },
    btn_Hyperlink{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);

    shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
    shouldShowDescriptionAsValue.addListener(this);

    const int smallButtons_y{ 367 };
    btn_ActivateQuickEdit.setBounds(596, smallButtons_y, 34, GUI::buttons_small_h);
    addAndMakeVisible(btn_ActivateQuickEdit);

    const int pullAndPushButtons_w{ 28 };
    btn_Push.setComponentID(ID::btn_Push.toString());
    btn_Push.onClick = [this, exposedParams] {
        SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, outgoingBuffers);
        addProgramChangeMessageToOutgoingBuffersAfterDelay(10);
    };
    btn_Push.setBounds(633, smallButtons_y, pullAndPushButtons_w, GUI::buttons_small_h);
    btn_Push.addShortcut(KeyPress{ ']', ModifierKeys::ctrlModifier, 0});
    addAndMakeVisible(btn_Push);

    btn_Pull.setComponentID(ID::btn_Pull.toString());
    btn_Pull.onClick = [this, exposedParams, unexposedParams] {
        auto currentVoiceNumber{ exposedParams->currentVoiceOptions->currentVoiceNumber() };
        SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(currentVoiceNumber, outgoingBuffers);
        auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
        addProgramChangeMessageToOutgoingBuffersAfterDelay(transmitOptions->voiceTransmitTime());
    };
    btn_Pull.setBounds(664, smallButtons_y, pullAndPushButtons_w, GUI::buttons_small_h);
    btn_Pull.addShortcut(KeyPress{ '[', ModifierKeys::ctrlModifier, 0});
    addAndMakeVisible(btn_Pull);

    const int undoRedoButtons_w{ 30 };
    btn_Undo.setComponentID(ID::btn_Undo.toString());
    btn_Undo.onClick = [exposedParams] { exposedParams->undoManager.undo(); };
    btn_Undo.setBounds(695, smallButtons_y, undoRedoButtons_w, GUI::buttons_small_h);
    btn_Undo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_Undo);

    btn_Redo.setComponentID(ID::btn_Redo.toString());
    btn_Redo.onClick = [exposedParams] { exposedParams->undoManager.redo(); };
    btn_Redo.setBounds(728, smallButtons_y, undoRedoButtons_w, GUI::buttons_small_h);
    btn_Redo.addShortcut(KeyPress{ 'z', ModifierKeys::ctrlModifier + ModifierKeys::shiftModifier, 0 });
    addAndMakeVisible(btn_Redo);

    btn_Randomize.setComponentID(ID::btn_Randomize.toString());
    btn_Randomize.addMouseListener(this, false);
    btn_Randomize.addListener(this);
    btn_Randomize.onClick = [this] {
        if (ModifierKeys::currentModifiers != ModifierKeys::ctrlModifier + ModifierKeys::altModifier && wasRightClicked == false)
            randomize->randomizeAllUnlockedParameters();
        wasRightClicked = false;
    };
    btn_Randomize.setBounds(761, smallButtons_y, GUI::btn_Randomize_w, GUI::buttons_small_h);
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
    btn_Randomize.addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier + ModifierKeys::altModifier, 0 });
    addAndMakeVisible(btn_Randomize);

    auto largeButtons_y{ 353 };
    btn_ShowVoicesBanks.setComponentID(ID::btn_Patches.toString());
    btn_ShowVoicesBanks.onClick = [this] { showVoicesBanksLayer(); };
    btn_ShowVoicesBanks.setBounds(1006, largeButtons_y, GUI::buttons_large_w, GUI::buttons_large_h);
    btn_ShowVoicesBanks.addShortcut(KeyPress{ 'p', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowVoicesBanks);

    btn_ShowSplits.setComponentID(ID::btn_Splits.toString());
    btn_ShowSplits.onClick = [this] { showSplitsLayer(); };
    btn_ShowSplits.setBounds(1085, largeButtons_y, GUI::buttons_large_w, GUI::buttons_large_h);
    btn_ShowSplits.addShortcut(KeyPress{ 's', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowSplits);

    btn_ShowGlobalParams.setComponentID(ID::btn_Master.toString());
    btn_ShowGlobalParams.onClick = [this] { prepareToShowGlobalParamsLayer(); };
    btn_ShowGlobalParams.setBounds(1164, largeButtons_y, GUI::buttons_large_w, GUI::buttons_large_h);
    btn_ShowGlobalParams.addShortcut(KeyPress{ 'm', ModifierKeys::ctrlModifier, 0 });
    addAndMakeVisible(btn_ShowGlobalParams);

    btn_Hyperlink.setComponentID(ID::btn_Hyperlink.toString());
    btn_Hyperlink.setBounds(176, 386, 146, 9);
    addAndMakeVisible(btn_Hyperlink);

    updateTooltips();

    setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_MainWindowButtons::updateTooltips() {
    auto shouldShow{ tooltips->shouldShowDescription() };

    auto tipFor_btn_ActivateQuickEdit{ shouldShow ? Description::buildForActivateQuickEdit() : String{ "" } };
    btn_ActivateQuickEdit.setTooltip(tipFor_btn_ActivateQuickEdit);

    auto tipFor_btn_Pull{ shouldShow ? Description::buildForPull() : String{ "" } };
    btn_Pull.setTooltip(tipFor_btn_Pull);

    auto tipFor_btn_Push{ shouldShow ? Description::buildForPush() : String{ "" } };
    btn_Push.setTooltip(tipFor_btn_Push);

    auto tipFor_btn_Undo{ shouldShow ? Description::buildForUndo() : String{ "" } };
    btn_Undo.setTooltip(tipFor_btn_Undo);

    auto tipFor_btn_Redo{ shouldShow ? Description::buildForRedo() : String{ "" } };
    btn_Redo.setTooltip(tipFor_btn_Redo);

    auto tipFor_btn_Randomize{ shouldShow ? Description::buildForShowRandomizationLayer() : String{ "" } };
    btn_Randomize.setTooltip(tipFor_btn_Randomize);

    auto tipFor_btn_ShowSplits{ shouldShow ? Description::buildForShowSplitsLayer() : String{ "" } };
    btn_ShowSplits.setTooltip(tipFor_btn_ShowSplits);

    auto tipFor_btn_ShowVoicesBanks{ shouldShow ? Description::buildForShowVoicesBanksLayer() : String{ "" } };
    btn_ShowVoicesBanks.setTooltip(tipFor_btn_ShowVoicesBanks);

    auto tipFor_btn_ShowGlobalParams{ shouldShow ? Description::buildForShowGlobalParamsLayer() : String{ "" } };
    btn_ShowGlobalParams.setTooltip(tipFor_btn_ShowGlobalParams);

    auto tipFor_btn_Hyperlink{ shouldShow ? Description::buildForHyperlink() : String{ "" } };
    btn_Hyperlink.setTooltip(tipFor_btn_Hyperlink);
}

void GUI_Layer_MainWindowButtons::timerCallback() {
}

void GUI_Layer_MainWindowButtons::addProgramChangeMessageToOutgoingBuffersAfterDelay(int delayInMilliseconds) {
    callAfterDelay(delayInMilliseconds, [this] {
        auto channel{ unexposedParams->getGlobalOptions()->basicChannel() };
        auto currentVoiceNumber{ exposedParams->currentVoiceOptions.get()->currentVoiceNumber()};
        outgoingBuffers->addProgramChangeMessage(channel, currentVoiceNumber);
    });
}

void GUI_Layer_MainWindowButtons::showRandomizationLayer() {
    layer_Randomization = nullptr;
    layer_Randomization.reset(new GUI_Layer_Randomization{ exposedParams, tooltips, outgoingBuffers });
    if (layer_Randomization != nullptr) {
        addAndMakeVisible(layer_Randomization.get());
        layer_Randomization->setBounds(getLocalBounds());
        layer_Randomization->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showSplitsLayer() {
    SysExMessages::addSwitchToSplitModeMessageToOutgoingBuffers(outgoingBuffers);
    layer_Splits.reset(new GUI_Layer_Splits{ unexposedParams, &exposedParams->undoManager });
    if (layer_Splits != nullptr) {
        addAndMakeVisible(layer_Splits.get());
        layer_Splits->setBounds(getLocalBounds());
        layer_Splits->grabKeyboardFocus();
    }
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
    SysExMessages::addRequestForGlobalDataToOutgoingBuffers(outgoingBuffers);
    callAfterDelay(600, [this] {
        if (global->sysExIsEnabled())
            showGlobalParamsLayer();
        else showCommErrorLayer();
    });
}

void GUI_Layer_MainWindowButtons::showCommErrorLayer() {
    layer_CommError.reset(new GUI_Layer_CommError{ unexposedParams });
    if (layer_CommError != nullptr) {
        addAndMakeVisible(layer_CommError.get());
        layer_CommError->setBounds(getLocalBounds());
        layer_CommError->grabKeyboardFocus();
    }
}

void GUI_Layer_MainWindowButtons::showGlobalParamsLayer() {
    layer_GlobalParams.reset(new GUI_Layer_GlobalParameters{ unexposedParams, &exposedParams->undoManager });
    if (layer_GlobalParams != nullptr) {
        addAndMakeVisible(layer_GlobalParams.get());
        layer_GlobalParams->setBounds(getLocalBounds());
        layer_GlobalParams->grabKeyboardFocus();
    }
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
    layer_Randomization = nullptr;
    layer_VoicesBanks = nullptr;
    layer_Splits = nullptr;
    layer_GlobalParams = nullptr;
    shouldShowDescriptionAsValue.removeListener(this);
    btn_Randomize.removeListener(this);
    btn_Randomize.removeMouseListener(this);
}
