#pragma once

#include <JuceHeader.h>

#include "voices_TabForCustomVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForCustomVoicesBanks :
    public TabbedComponent
{
    TabForCustomVoiceBank bank1;
    TabForCustomVoiceBank bank2;
    TabForCustomVoiceBank bank3;
    UnexposedParameters* unexposedParams;

public:
    TabbedComponentForCustomVoicesBanks() = delete;

    TabbedComponentForCustomVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void addListenerToButtonsInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromButtonsInAllCustomTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomVoicesBanks)
};
