#include "gui_layer_MainWindowButtons.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_MainWindowButtonDescription.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../global/global_3_gui_layer_CommError.h"
#include "../global/global_4_gui_layer_GlobalParams.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../splits/splits_4_gui_layer_Splits.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_7_gui_layer_VoicesBanks.h"

using namespace Matrix_6G_Constants;
using Description = MainWindowButtonDescription;

GUI_Layer_MainWindowButtons::GUI_Layer_MainWindowButtons(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    global{ unexposedParams->getGlobalOptions() },
    outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
    tooltips{ unexposedParams->getTooltipsOptions() },
    btn_ActivateQuickEdit{ unexposedParams }
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

    auto tipFor_btn_ShowSplits{ shouldShow ? Description::buildForShowSplitsLayer() : String{ "" } };
    btn_ShowSplits.setTooltip(tipFor_btn_ShowSplits);

    auto tipFor_btn_ShowVoicesBanks{ shouldShow ? Description::buildForShowVoicesBanksLayer() : String{ "" } };
    btn_ShowVoicesBanks.setTooltip(tipFor_btn_ShowVoicesBanks);

    auto tipFor_btn_ShowGlobalParams{ shouldShow ? Description::buildForShowGlobalParamsLayer() : String{ "" } };
    btn_ShowGlobalParams.setTooltip(tipFor_btn_ShowGlobalParams);
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

void GUI_Layer_MainWindowButtons::mouseDown(const MouseEvent& /*event*/) {
}

void GUI_Layer_MainWindowButtons::buttonClicked(Button* /*button*/) {
}

void GUI_Layer_MainWindowButtons::valueChanged(Value& /*value*/) {
    updateTooltips();
}

GUI_Layer_MainWindowButtons::~GUI_Layer_MainWindowButtons() {
    layer_VoicesBanks = nullptr;
    layer_Splits = nullptr;
    layer_GlobalParams = nullptr;
    shouldShowDescriptionAsValue.removeListener(this);
}
