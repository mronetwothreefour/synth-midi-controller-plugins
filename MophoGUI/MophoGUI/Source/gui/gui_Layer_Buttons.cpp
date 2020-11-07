#include "gui_Layer_Buttons.h"

#include "../banks/banks_ProgramBanksComponent.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForEditingPgmName{ exposedParams, unexposedParams },
    button_ForSendingProgramEditBufferDump{ exposedParams, unexposedParams },
    button_ForSendingProgramEditBufferDumpRequest{ unexposedParams },
    button_ForShowingProgramBanksComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForEditingPgmName);
    addAndMakeVisible(button_ForSendingProgramEditBufferDump);
    addAndMakeVisible(button_ForSendingProgramEditBufferDumpRequest);
    addAndMakeVisible(button_ForShowingProgramBanksComponent);
    button_ForShowingProgramBanksComponent.onClick = [this] { showProgramBanksComponent(); };
}

void ButtonsLayer::showProgramBanksComponent() {
    programBanksComponent.reset(new ProgramBanksComponent(exposedParams, unexposedParams));
    if (programBanksComponent != nullptr) {
        addAndMakeVisible(programBanksComponent.get());
        programBanksComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::resized() {
    button_ForEditingPgmName.setBounds(590, 11, button_ForEditingPgmName.getWidth(), button_ForEditingPgmName.getHeight());
    auto utilityButtons_y{ 83 };
    auto utilityButtons_w{ 53 };
    auto utilityButtons_h{ 22 };
    button_ForSendingProgramEditBufferDump.setBounds(580, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForSendingProgramEditBufferDumpRequest.setBounds(643, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForShowingProgramBanksComponent.setBounds(706, utilityButtons_y, utilityButtons_w, utilityButtons_h);
}

ButtonsLayer::~ButtonsLayer() {
    programBanksComponent = nullptr;
}
