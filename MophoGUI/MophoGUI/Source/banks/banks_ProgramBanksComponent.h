#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanks.h"
#include "banks_TabbedComponentForAllProgramBanks.h"



class BankTransmissionComponent;
class UnexposedParameters;

class ProgramBanksComponent : 
    public Component,
    public Label::Listener,
    public Button::Listener
{
    TabbedComponentForAllProgramBanks tabbedComponent;
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingProgramBanks;
    std::unique_ptr<BankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<BankTransmissionComponent> pullEntireBankComponent;
    Label label_txTime;

public:
    ProgramBanksComponent() = delete;

    ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();
    void showPushEntireBankComponentForBank(ProgramBank bank);
    void showPullEntireBankComponentForBank(ProgramBank bank);

public:
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;
    ~ProgramBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksComponent)
};