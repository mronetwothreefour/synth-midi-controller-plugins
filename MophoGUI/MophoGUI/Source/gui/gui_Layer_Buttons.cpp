#include "gui_Layer_Buttons.h"

#include "../params/params_UnexposedParameters_Facade.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    button_ForEditingPgmName{ exposedParams, unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForEditingPgmName);
    button_ForEditingPgmName.setBounds(590, 11, button_ForEditingPgmName.getWidth(), button_ForEditingPgmName.getHeight());
}
