#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanksTabbedComponent.h"
#include "../widgets_Button/widget_banks_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_banks_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_banks_ButtonForResettingAllBanksToFactoryDefaults.h"



class BankTransmissionComponent;
class UnexposedParameters;

class ProgramBanksComponent : public Component
{
    ProgramBanksTabbedComponent tabbedComponent;
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingProgramBanks;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    std::unique_ptr<BankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<BankTransmissionComponent> pullEntireBankComponent;
    ButtonForResettingAllBanksToFactoryDefaults button_ForResettingAllBanksToFactoryDefaults;

public:
    ProgramBanksComponent() = delete;

    ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();
    void showPushEntireBankComponent();
    void showPullEntireBankComponent();
    void resetAllProgramBanks();

public:
    void paint(Graphics& g) override;
    ~ProgramBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksComponent)
};