#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanksTabbedComponent.h"



class ProgramBanksComponent : public Component
{
    ProgramBanksTabbedComponent tabbedComponent;
    TextButton button_ForClosingProgramBanks;

    void hideThisComponent();

public:
    ProgramBanksComponent() = delete;
    explicit ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams);
    ~ProgramBanksComponent();

    void paint(Graphics& g) override;
};