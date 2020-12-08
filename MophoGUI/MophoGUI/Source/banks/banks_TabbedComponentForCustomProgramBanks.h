#pragma once

#include <JuceHeader.h>

#include "banks_TabForCustomProgramBank.h"



class UnexposedParameters;

class TabbedComponentForCustomProgramBanks :
    public TabbedComponent,
    public Label::Listener
{
    TabForCustomProgramBank bank1;
    TabForCustomProgramBank bank2;
    TabForCustomProgramBank bank3;
    UnexposedParameters* unexposedParams;
    String programCopyBuffer;
    Label label_txTime;

public:
    TabbedComponentForCustomProgramBanks() = delete;

    TabbedComponentForCustomProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    TabForCustomProgramBank* getCurrentProgramBankTab();
    void updateTextForAllProgramSlotsInAllBanks();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomProgramBanks)
};
