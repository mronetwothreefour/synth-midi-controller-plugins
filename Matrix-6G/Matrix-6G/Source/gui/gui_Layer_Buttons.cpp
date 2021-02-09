#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../patches/patches_PatchBanksComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForPullingPatchFromHardware{ unexposedParams },
    button_ForPushingPatchToHardware{ exposedParams, unexposedParams },
    button_ForShowingPatchBanksComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForPullingPatchFromHardware);
    addAndMakeVisible(button_ForPushingPatchToHardware);
    addAndMakeVisible(button_ForShowingPatchBanksComponent);
    button_ForShowingPatchBanksComponent.onClick = [this] { showPatchBanksComponent(); };
    setSize(GUI::editor_w, GUI::editor_h);
}

void ButtonsLayer::showPatchBanksComponent() {
    patchBanksComponent.reset(new PatchBanksComponent(exposedParams, unexposedParams));
    if (patchBanksComponent != nullptr) {
        addAndMakeVisible(patchBanksComponent.get());
        patchBanksComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::resized() {
    button_ForActivatingQuickPatchEdit.setBounds(GUI::bounds_MainWindowQuickEditButton);
    button_ForPullingPatchFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingPatchToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingPatchBanksComponent.setBounds(GUI::bounds_MainWindowPatchesButton);
}

ButtonsLayer::~ButtonsLayer() {
    patchBanksComponent = nullptr;
}
