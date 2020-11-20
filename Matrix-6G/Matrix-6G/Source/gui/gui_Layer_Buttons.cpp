#include "gui_Layer_Buttons.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForSendingAllPatchData{ exposedParams, unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForSendingAllPatchData);
}

void ButtonsLayer::resized() {
    auto smallButtons_y{ 367 };
    auto smallButtons_h{ 20 };
    button_ForActivatingQuickPatchEdit.setBounds(596, smallButtons_y, 72, smallButtons_h);
    button_ForSendingAllPatchData.setBounds(762, smallButtons_y, 60, smallButtons_h);
}
