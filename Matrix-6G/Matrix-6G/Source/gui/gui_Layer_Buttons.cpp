#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../patches/patches_PatchBanksComponent.h"
#include "../splits/splits_SplitsComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForPullingPatchFromHardware{ unexposedParams },
    button_ForPushingPatchToHardware{ exposedParams, unexposedParams },
    button_ForShowingPatchBanksComponent{ unexposedParams },
    button_ForShowingSplitsComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForPullingPatchFromHardware);
    addAndMakeVisible(button_ForPushingPatchToHardware);
    addAndMakeVisible(button_ForShowingPatchBanksComponent);
    button_ForShowingPatchBanksComponent.onClick = [this] { showPatchBanksComponent(); };
    addAndMakeVisible(button_ForShowingSplitsComponent);
    button_ForShowingSplitsComponent.onClick = [this] { showSplitsComponent(); };
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

void ButtonsLayer::resized() {
    button_ForActivatingQuickPatchEdit.setBounds(GUI::bounds_MainWindowQuickEditButton);
    button_ForPullingPatchFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingPatchToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingPatchBanksComponent.setBounds(GUI::bounds_MainWindowPatchesButton);
    button_ForShowingSplitsComponent.setBounds(GUI::bounds_MainWindowSplitsButton);
}

ButtonsLayer::~ButtonsLayer() {
    splitsComponent = nullptr;
    patchBanksComponent = nullptr;
}
