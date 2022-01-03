#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPullingProgramFromHardware{ unexposedParams },
    button_ForPushingProgramToHardware{ exposedParams, unexposedParams },
    button_ForShowingProgramBankComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPullingProgramFromHardware);
    addAndMakeVisible(button_ForPushingProgramToHardware);
    addAndMakeVisible(button_ForShowingProgramBankComponent);
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPullingProgramFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingProgramToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingProgramBankComponent.setBounds(GUI::bounds_MainWindowPgmBankButton);
}

ButtonsLayer::~ButtonsLayer() {
}
