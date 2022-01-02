#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPullingProgramFromHardware{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPullingProgramFromHardware);
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPullingProgramFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
}

ButtonsLayer::~ButtonsLayer() {
}
