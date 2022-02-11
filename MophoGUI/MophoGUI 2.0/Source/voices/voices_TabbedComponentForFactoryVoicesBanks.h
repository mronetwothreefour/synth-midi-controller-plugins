#pragma once

#include <JuceHeader.h>

#include "voices_TabForFactoryVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForFactoryProgramBanks :
    public TabbedComponent
{
    TabForFactoryProgramBank bank1;
    TabForFactoryProgramBank bank2;
    TabForFactoryProgramBank bank3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForFactoryProgramBanks() = delete;

    TabbedComponentForFactoryProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer);
    void addListenerToPushBankButtonInAllFactoryTabs(Button::Listener* listener);
    void removeListenerFromPushBankButtonInAllFactoryTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForFactoryProgramBanks)
};
