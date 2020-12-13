#pragma once

#include <JuceHeader.h>

#include "banks_TabForCustomProgramBank.h"



class UnexposedParameters;

class TabbedComponentForCustomProgramBanks :
    public TabbedComponent
{
    TabForCustomProgramBank bank1;
    TabForCustomProgramBank bank2;
    TabForCustomProgramBank bank3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForCustomProgramBanks() = delete;

    TabbedComponentForCustomProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomProgramBanks)
};
