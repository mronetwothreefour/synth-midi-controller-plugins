#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanksTabbedComponent.h"



class UnexposedParameters;

class ProgramBanksComponent : public Component
{
    ProgramBanksTabbedComponent tabbedComponent;
    TextButton button_ForClosingProgramBanks;

public:
    ProgramBanksComponent() = delete;

    ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();

public:
    void paint(Graphics& g) override;
    ~ProgramBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksComponent)
};