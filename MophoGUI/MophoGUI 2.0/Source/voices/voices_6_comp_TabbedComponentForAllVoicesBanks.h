#pragma once

#include <JuceHeader.h>

#include "voices_5_comp_TabbedComponentForCustomVoicesBanks.h"
#include "voices_5_comp_TabbedComponentForFactoryVoicesBanks.h"



class UnexposedParameters;

class TabbedComponentForAllVoicesBanks :
    public TabbedComponent
{
    TabbedComponentForCustomVoicesBanks tabbedComponentForCustomVoicesBanks;
    TabbedComponentForFactoryVoicesBanks tabbedComponentForFactoryVoicesBanks;
    String voiceCopyBuffer;

public:
    TabbedComponentForAllVoicesBanks() = delete;

    TabbedComponentForAllVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void addListenerToButtonsInAllTabs(Button::Listener* listener);
    void removeListenerFromButtonsInAllTabs(Button::Listener* listener);
    VoiceSlots* getVoiceSlotsForBank(VoicesBank bank);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForAllVoicesBanks)
};
