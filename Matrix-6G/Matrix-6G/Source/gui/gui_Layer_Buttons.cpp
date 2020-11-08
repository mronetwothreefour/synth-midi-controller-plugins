#include "gui_Layer_Buttons.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
}

void ButtonsLayer::resized() {
    auto smallButtons_y{ 367 };
    auto smallButtons_h{ 20 };
    button_ForActivatingQuickPatchEdit.setBounds(596, smallButtons_y, 72, smallButtons_h);
}

ButtonsLayer::~ButtonsLayer() {
}
