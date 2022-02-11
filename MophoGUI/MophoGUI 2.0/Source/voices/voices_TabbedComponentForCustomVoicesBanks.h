#pragma once

#include <JuceHeader.h>

#include "voices_TabForCustomVoicesBank.h"



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
    void addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener);
    void addListenerToPushBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPullBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPushBankButtonInAllCustomTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomProgramBanks)
};
