#pragma once

#include <JuceHeader.h>

#include "voices_TabbedComponentForAllVoicesBanks.h"
#include "voices_VoicesBanks.h"



class BankTransmissionComponent;
class UnexposedParameters;

class VoicesBanksComponent : 
    public Component,
    public Label::Listener,
    public Button::Listener
{
    TabbedComponentForAllVoicesBanks tabbedComponent;
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingVoicesBanksComponent;
    std::unique_ptr<BankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<BankTransmissionComponent> pullEntireBankComponent;
    Label label_txTime;

public:
    VoicesBanksComponent() = delete;

    VoicesBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;

private:
    void showPushEntireBankComponentForBank(VoicesBank bank);
    void showPullEntireBankComponentForBank(VoicesBank bank);
    void hideThisComponent();

public:
    ~VoicesBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBanksComponent)
};