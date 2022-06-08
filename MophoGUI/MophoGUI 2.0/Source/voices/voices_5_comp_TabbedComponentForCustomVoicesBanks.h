#pragma once

#include <JuceHeader.h>

#include "voices_4_comp_TabForCustomVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForCustomVoicesBanks :
    public TabbedComponent
{
    TabForCustomVoicesBank bank_1;
    TabForCustomVoicesBank bank_2;
    TabForCustomVoicesBank bank_3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForCustomVoicesBanks() = delete;

    TabbedComponentForCustomVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void addListenerToButtonsInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromButtonsInAllCustomTabs(Button::Listener* listener);
    VoiceSlots* getVoiceSlotsComponentForCustomBank(VoicesBank bank);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomVoicesBanks)
};
