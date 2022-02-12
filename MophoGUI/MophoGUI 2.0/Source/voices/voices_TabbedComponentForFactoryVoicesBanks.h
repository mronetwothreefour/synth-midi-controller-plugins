#pragma once

#include <JuceHeader.h>

#include "voices_TabForFactoryVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForFactoryVoicesBanks :
    public TabbedComponent
{
    TabForFactoryVoicesBank bank1;
    TabForFactoryVoicesBank bank2;
    TabForFactoryVoicesBank bank3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForFactoryVoicesBanks() = delete;

    TabbedComponentForFactoryVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void addListenerToPushBankButtonInAllFactoryTabs(Button::Listener* listener);
    void removeListenerFromPushBankButtonInAllFactoryTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForFactoryVoicesBanks)
};
