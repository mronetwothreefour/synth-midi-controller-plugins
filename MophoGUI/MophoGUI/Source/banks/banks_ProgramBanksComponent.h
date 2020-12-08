#pragma once

#include <JuceHeader.h>

#include "banks_TabbedComponentForAllProgramBanks.h"
#include "../widgets_Button/widget_banks_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingEntireBankToHardware.h"



class BankTransmissionComponent;
class UnexposedParameters;

class ProgramBanksComponent : 
    public Component,
    public Label::Listener
{
    TabbedComponentForAllProgramBanks tabbedComponent;
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingProgramBanks;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    std::unique_ptr<BankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<BankTransmissionComponent> pullEntireBankComponent;
    Label label_txTime;

public:
    ProgramBanksComponent() = delete;

    ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();
    void showPushEntireBankComponent();
    void showPullEntireBankComponent();

public:
    void paint(Graphics& g) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    ~ProgramBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksComponent)
};