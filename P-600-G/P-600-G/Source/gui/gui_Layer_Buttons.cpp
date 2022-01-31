#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_PgmDataBankComponent.h"
#include "../tooltips/tooltipOptionsComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPullingProgramFromHardware{ unexposedParams },
    button_ForPushingProgramToHardware{ exposedParams, unexposedParams },
    button_ForShowingProgramBankComponent{ unexposedParams },
    button_ForShowingRandomizeComponent{ exposedParams, unexposedParams },
    button_ForShowingTipsComponent{ unexposedParams }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPullingProgramFromHardware);
    addAndMakeVisible(button_ForPushingProgramToHardware);
    addAndMakeVisible(button_ForShowingProgramBankComponent);
    button_ForShowingProgramBankComponent.onClick = [this] { showProgramDataBankComponent(); };
    addAndMakeVisible(button_ForShowingRandomizeComponent);
    addAndMakeVisible(button_ForShowingTipsComponent);
    button_ForShowingTipsComponent.onClick = [this] { showTooltipOptionsComponent(); };
}

void ButtonsLayer::showProgramDataBankComponent() {
    pgmDataBankComponent.reset(new ProgramDataBankComponent(exposedParams, unexposedParams));
    if (pgmDataBankComponent != nullptr) {
        addAndMakeVisible(pgmDataBankComponent.get());
        pgmDataBankComponent->setBounds(getLocalBounds());
        pgmDataBankComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::showTooltipOptionsComponent() {
    tooltipOptionsComponent.reset(new TooltipOptionsComponent(unexposedParams));
    if (tooltipOptionsComponent != nullptr) {
        addAndMakeVisible(tooltipOptionsComponent.get());
        tooltipOptionsComponent->setBounds(getLocalBounds());
        tooltipOptionsComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPerformingRedo.setBounds(GUI::bounds_RedoButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_UndoButton);
    button_ForPullingProgramFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingProgramToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingProgramBankComponent.setBounds(GUI::bounds_MainWindowPgmBankButton);
    button_ForShowingRandomizeComponent.setBounds(GUI::bounds_RandButton);
    button_ForShowingTipsComponent.setBounds(GUI::bounds_TipsButton);
}

ButtonsLayer::~ButtonsLayer() {
    tooltipOptionsComponent = nullptr;
    pgmDataBankComponent = nullptr;
}
