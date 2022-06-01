#pragma once

#include <JuceHeader.h>

#include "4_voices_comp_TabForFactoryVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForFactoryVoicesBanks :
    public TabbedComponent
{
    TabForFactoryVoicesBank bank_1;
    TabForFactoryVoicesBank bank_2;
    TabForFactoryVoicesBank bank_3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForFactoryVoicesBanks() = delete;

    TabbedComponentForFactoryVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void addListenerToPushBankButtonInAllFactoryTabs(Button::Listener* listener);
    void removeListenerFromPushBankButtonInAllFactoryTabs(Button::Listener* listener);
    VoiceSlots* getVoiceSlotsComponentForFactoryBank(VoicesBank bank);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForFactoryVoicesBanks)
};