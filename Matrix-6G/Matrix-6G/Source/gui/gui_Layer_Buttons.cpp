#include "gui_Layer_Buttons.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForPushingPatchToHardware{ exposedParams, unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForPushingPatchToHardware);
    setSize(1252, 596);
}

void ButtonsLayer::resized() {
    auto smallButtons_y{ 367 };
    auto smallButtons_h{ 20 };
    auto quickEditButton_w{ 70 };
    auto otherSmallButtons_w{ 34 };
    button_ForActivatingQuickPatchEdit.setBounds(596, smallButtons_y, quickEditButton_w, smallButtons_h);
    button_ForPushingPatchToHardware.setBounds(788, smallButtons_y, otherSmallButtons_w, smallButtons_h);
}
