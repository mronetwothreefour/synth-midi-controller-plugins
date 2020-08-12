#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBanksTabbedComponent.h"



class OutgoingMidiBuffers;

class ProgramBanksComponent : public Component
{
    ProgramBanksTabbedComponent tabbedComponent;
    TextButton button_ForClosingProgramBanks;

public:
    ProgramBanksComponent() = delete;
    ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);
    ~ProgramBanksComponent();

    void paint(Graphics& g) override;

private:
    void hideThisComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksComponent)
};