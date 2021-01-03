#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForActivatingQuickPatchEdit{ unexposedParams },
    button_ForPushingPatchToHardware{ exposedParams, unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForActivatingQuickPatchEdit);
    addAndMakeVisible(button_ForPushingPatchToHardware);
    setSize(GUI::editor_w, GUI::editor_h);
}

void ButtonsLayer::resized() {
    button_ForActivatingQuickPatchEdit.setBounds(GUI::quickEditButton_x, GUI::mainWindowSmallButtons_y, GUI::quickEditButton_w, GUI::smallButtons_h);
    button_ForPushingPatchToHardware.setBounds(788, GUI::mainWindowSmallButtons_y, GUI::mainWindowSmallButtons_w, GUI::smallButtons_h);
}
