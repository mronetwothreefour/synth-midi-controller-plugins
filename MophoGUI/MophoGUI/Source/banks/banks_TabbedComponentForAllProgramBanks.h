#pragma once

#include <JuceHeader.h>

#include "banks_TabbedComponentForCustomProgramBanks.h"
#include "banks_TabbedComponentForFactoryProgramBanks.h"



class UnexposedParameters;

class TabbedComponentForAllProgramBanks :
    public TabbedComponent
{
    UnexposedParameters* unexposedParams;
    TabbedComponentForCustomProgramBanks tabbedComponentForCustomProgramBanks;
    TabbedComponentForFactoryProgramBanks tabbedComponentForFactoryProgramBanks;
    String programCopyBuffer;

public:
    TabbedComponentForAllProgramBanks() = delete;

    TabbedComponentForAllProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForAllProgramBanks)
};
