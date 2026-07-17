#include "gui_Layer_Buttons.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoicesBankComponent.h"
#include "../randomization/randomizationComponent.h"
#include "../tooltips/tooltipOptionsComponent.h"

using namespace constants;



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPullingVoiceFromHardware{ unexposedParams },
    button_ForPushingVoiceToHardware{ exposedParams, unexposedParams },
    button_ForShowingRandomizationComponent{ exposedParams, unexposedParams },
    button_ForShowingTipsComponent{ unexposedParams },
    button_ForShowingVoicesBankComponent{ unexposedParams },
    button_ForGoingToWebSite{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPullingVoiceFromHardware);
    addAndMakeVisible(button_ForPushingVoiceToHardware);
    addAndMakeVisible(button_ForShowingVoicesBankComponent);
    button_ForShowingVoicesBankComponent.onClick = [this] { showVoicesBankComponent(); };
    addAndMakeVisible(button_ForShowingTipsComponent);
    button_ForShowingTipsComponent.onClick = [this] { showTooltipOptionsComponent(); };
    addAndMakeVisible(button_ForShowingRandomizationComponent);
    button_ForShowingRandomizationComponent.onClick = [this] { showRandomizationComponent();  };
    button_ForGoingToWebSite.setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite);
}

void ButtonsLayer::showTooltipOptionsComponent() {
    tooltipOptionsComponent.reset(new TooltipOptionsComponent(unexposedParams));
    if (tooltipOptionsComponent != nullptr) {
        addAndMakeVisible(tooltipOptionsComponent.get());
        tooltipOptionsComponent->setBounds(getLocalBounds());
        tooltipOptionsComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::showRandomizationComponent() {
    randomizationComponent.reset(new RandomizationComponent(exposedParams, unexposedParams));
    if (randomizationComponent != nullptr) {
        addAndMakeVisible(randomizationComponent.get());
        randomizationComponent->setBounds(getLocalBounds());
        randomizationComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::showVoicesBankComponent() {
    voicesBankComponent.reset(new VoicesBankComponent(exposedParams, unexposedParams));
    if (voicesBankComponent != nullptr) {
        addAndMakeVisible(voicesBankComponent.get());
        voicesBankComponent->setBounds(getLocalBounds());
        voicesBankComponent->grabKeyboardFocus();
    }
}

void ButtonsLayer::timerCallback() {
}

void ButtonsLayer::resized() {
    button_ForPerformingRedo.setBounds(GUI::bounds_RedoButton);
    button_ForPerformingUndo.setBounds(GUI::bounds_UndoButton);
    button_ForPullingVoiceFromHardware.setBounds(GUI::bounds_MainWindowPullButton);
    button_ForPushingVoiceToHardware.setBounds(GUI::bounds_MainWindowPushButton);
    button_ForShowingVoicesBankComponent.setBounds(GUI::bounds_MainWindowVoicesBankButton);
    button_ForShowingRandomizationComponent.setBounds(GUI::bounds_RandButton);
    button_ForShowingTipsComponent.setBounds(GUI::bounds_TipsButton);
    button_ForGoingToWebSite.setBounds(GUI::bounds_MainWindowWebLinkButton);
}

ButtonsLayer::~ButtonsLayer() {
    randomizationComponent = nullptr;
    tooltipOptionsComponent = nullptr;
    voicesBankComponent = nullptr;
}
