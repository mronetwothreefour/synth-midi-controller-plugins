#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../midi/midi_MasterOptionsDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../master/master_MasterOptionsComponent.h"
#include "../master/master_SysExIsOffWarningComponent.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../patches/patches_PatchBanksComponent.h"
#include "../splits/splits_SplitsComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForPullingPatchFromHardware{ unexposedParams },
    button_ForPushingPatchToHardware{ exposedParams, unexposedParams },
    button_ForShowingPatchBanksComponent{ unexposedParams },
    button_ForShowingSplitsComponent{ unexposedParams },
    button_ForShowingMasterOptionsComponent{ unexposedParams },
    button_ForGoingToWebSite{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForPullingPatchFromHardware);
    addAndMakeVisible(button_ForPushingPatchToHardware);
    addAndMakeVisible(button_ForShowingPatchBanksComponent);
    button_ForShowingPatchBanksComponent.onClick = [this] { showPatchBanksComponent(); };
    addAndMakeVisible(button_ForShowingSplitsComponent);
    button_ForShowingSplitsComponent.onClick = [this] { showSplitsComponent(); };
    addAndMakeVisible(button_ForShowingMasterOptionsComponent);
    button_ForShowingMasterOptionsComponent.onClick = [this] { prepareToShowMasterOptionsComponent(); };
    button_ForGoingToWebSite.setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite);
    setSize(GUI::editor_w, GUI::editor_h);
}

void ButtonsLayer::showPatchBanksComponent() {
    patchBanksComponent.reset(new PatchBanksComponent(exposedParams, unexposedParams));
    if (patchBanksComponent != nullptr) {
        addAndMakeVisible(patchBanksComponent.get());
        patchBanksComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::showSplitsComponent() {
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    auto switchToSplitModeMessage{ RawSysExDataVector::createSwitchToSplitModeMessage() };
    outgoingMidiBuffers->addDataMessage(switchToSplitModeMessage);

    splitsComponent.reset(new SplitsComponent(unexposedParams));
    if (splitsComponent != nullptr) {
        addAndMakeVisible(splitsComponent.get());
        splitsComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::prepareToShowMasterOptionsComponent() {
    auto masterOptions{ unexposedParams->masterOptions_get() };
    masterOptions->resetMasterOptionsToDefaults();
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    MasterOptionsDataMessage::addRequestForMasterOptionsDataToOutgoingMidiBuffers(outgoingMidiBuffers);
    callAfterDelay(300, [this, masterOptions] {
        if (masterOptions->sysExEnabled())
            showMasterOptionsComponent();
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

void ButtonsLayer::showMasterOptionsComponent() {
    masterOptionsComponent.reset(new MasterOptionsComponent(unexposedParams));
    if (masterOptionsComponent != nullptr) {
        addAndMakeVisible(masterOptionsComponent.get());
        masterOptionsComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForActivatingQuickPatchEdit.setBounds(GUI::bounds_MainWindowQuickEditButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_MainWindowUndoButton);
    button_ForPerformingRedo.setBounds(GUI::bounds_MainWindowRedoButton);
    button_ForPullingPatchFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingPatchToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingPatchBanksComponent.setBounds(GUI::bounds_MainWindowPatchesButton);
    button_ForShowingSplitsComponent.setBounds(GUI::bounds_MainWindowSplitsButton);
    button_ForShowingMasterOptionsComponent.setBounds(GUI::bounds_MainWindowMasterOptionsButton);
    button_ForGoingToWebSite.setBounds(GUI::bounds_MainWindowWebLinkButton);
}

ButtonsLayer::~ButtonsLayer() {
    masterOptionsComponent = nullptr;
    sysExIsOffWarningComponent = nullptr;
    splitsComponent = nullptr;
    patchBanksComponent = nullptr;
}
