#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPullingProgramFromHardware{ unexposedParams },
    button_ForPushingProgramToHardware{ exposedParams, unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPullingProgramFromHardware);
    addAndMakeVisible(button_ForPushingProgramToHardware);
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPullingProgramFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingProgramToHardware.setBounds(GUI::bounds_MainWindowPushButton);
}

ButtonsLayer::~ButtonsLayer() {
}
