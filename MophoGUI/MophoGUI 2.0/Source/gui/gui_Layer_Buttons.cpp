#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../global/global_GlobalParametersComponent.h"
#include "../global/global_NRPNisOffWarningComponent.h"
#include "../global/global_SysExIsOffWarningComponent.h"
#include "../midi/midi_GlobalParametersDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoicesBanksComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForEditingVoiceName{ exposedParams, unexposedParams },
    button_ForSendingEditBufferDataMessage{ exposedParams, unexposedParams },
    button_ForSendingEditBufferDataMessageRequest{ unexposedParams },
    button_ForShowingVoicesBanksComponent{ unexposedParams },
    button_ForShowingGlobalParametersComponent{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForClearingSequencerTrack1{ 1, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack2{ 2, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack3{ 3, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack4{ 4, exposedParams, unexposedParams },
    button_ForGoingToWebSite{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForEditingVoiceName);
    addAndMakeVisible(button_ForSendingEditBufferDataMessage);
    addAndMakeVisible(button_ForSendingEditBufferDataMessageRequest);
    addAndMakeVisible(button_ForShowingVoicesBanksComponent);
    button_ForShowingVoicesBanksComponent.onClick = [this] { showVoicesBanksComponent(); };
    addAndMakeVisible(button_ForShowingGlobalParametersComponent);
    button_ForShowingGlobalParametersComponent.onClick = [this] { prepareToShowGlobalParametersComponent(); };
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForClearingSequencerTrack1);
    addAndMakeVisible(button_ForClearingSequencerTrack2);
    addAndMakeVisible(button_ForClearingSequencerTrack3);
    addAndMakeVisible(button_ForClearingSequencerTrack4);
    button_ForGoingToWebSite.setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite);
}

void ButtonsLayer::showVoicesBanksComponent() {
    voicesBanksComponent.reset(new VoicesBanksComponent(exposedParams, unexposedParams));
    if (voicesBanksComponent != nullptr) {
        addAndMakeVisible(voicesBanksComponent.get());
        voicesBanksComponent->setBounds(getLocalBounds());
        voicesBanksComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::prepareToShowGlobalParametersComponent() {
    auto globalOptions{ unexposedParams->globalOptions_get() };
    globalOptions->resetAllOptionsToDefaults();
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    GlobalParametersDataMessage::addRequestForDataMessageToOutgoingMidiBuffers(outgoingMidiBuffers);
    callAfterDelay(300, [this, globalOptions] {
        if (globalOptions->sysExIsOn()) {
            if (globalOptions->hardwareIsNotSetToReceiveNRPNcontrollers())
                showNRPNisOffWarningComponent();
            else
                showGlobalParametersComponent();
        }
        else showSysExIsOffWarningComponent();
    });
}

void ButtonsLayer::showSysExIsOffWarningComponent() {
    sysExIsOffWarningComponent.reset(new SysExIsOffWarningComponent(unexposedParams));
    if (sysExIsOffWarningComponent != nullptr) {
        addAndMakeVisible(sysExIsOffWarningComponent.get());
        sysExIsOffWarningComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::showNRPNisOffWarningComponent() {
    nrpnIsOffWarningComponent.reset(new NRPNisOffWarningComponent(unexposedParams));
    if (nrpnIsOffWarningComponent != nullptr) {
        addAndMakeVisible(nrpnIsOffWarningComponent.get());
        nrpnIsOffWarningComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::showGlobalParametersComponent() {
    globalParamsComponent.reset(new GlobalParametersComponent(unexposedParams));
    if (globalParamsComponent != nullptr) {
        addAndMakeVisible(globalParamsComponent.get());
        globalParamsComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForEditingVoiceName.setBounds(GUI::bounds_MainWindowEditNameButtonAndEditor);
    button_ForSendingEditBufferDataMessage.setBounds(GUI::bounds_MainWindowWriteButton);
    button_ForSendingEditBufferDataMessageRequest.setBounds(GUI::bounds_MainWindowReadButton);
    button_ForShowingVoicesBanksComponent.setBounds(GUI::bounds_MainWindowBanksButton);
    button_ForShowingGlobalParametersComponent.setBounds(GUI::bounds_MainWindowGlobalButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_MainWindowUndoButton);
    button_ForPerformingRedo.setBounds(GUI::bounds_MainWindowRedoButton);
    button_ForClearingSequencerTrack1.setBounds(GUI::bounds_MainWindowSeqTrack1ClearButton);
    button_ForClearingSequencerTrack2.setBounds(GUI::bounds_MainWindowSeqTrack2ClearButton);
    button_ForClearingSequencerTrack3.setBounds(GUI::bounds_MainWindowSeqTrack3ClearButton);
    button_ForClearingSequencerTrack4.setBounds(GUI::bounds_MainWindowSeqTrack4ClearButton);
    button_ForGoingToWebSite.setBounds(GUI::bounds_MainWindowWebLinkButton);
}

ButtonsLayer::~ButtonsLayer() {
    voicesBanksComponent = nullptr;
    globalParamsComponent = nullptr;
    nrpnIsOffWarningComponent = nullptr;
    sysExIsOffWarningComponent = nullptr;
}
