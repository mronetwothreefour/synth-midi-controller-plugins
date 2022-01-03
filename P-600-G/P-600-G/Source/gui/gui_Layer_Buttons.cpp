#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPullingProgramFromHardware{ unexposedParams },
    button_ForPushingProgramToHardware{ exposedParams, unexposedParams },
    button_ForShowingProgramBankComponent{ unexposedParams },
    button_ForShowingTipsComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPullingProgramFromHardware);
    addAndMakeVisible(button_ForPushingProgramToHardware);
    addAndMakeVisible(button_ForShowingProgramBankComponent);
    addAndMakeVisible(button_ForShowingTipsComponent);
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPerformingRedo.setBounds(GUI::bounds_RedoButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_UndoButton);
    button_ForPullingProgramFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingProgramToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingProgramBankComponent.setBounds(GUI::bounds_PgmBankButton);
    button_ForShowingTipsComponent.setBounds(GUI::bounds_TipsButton);
}

ButtonsLayer::~ButtonsLayer() {
}
