#pragma once

#include <JuceHeader.h>

#include "voices_TabbedComponentForCustomVoicesBanks.h"
#include "voices_TabbedComponentForFactoryVoicesBanks.h"



class UnexposedParameters;

class TabbedComponentForAllVoicesBanks :
    public TabbedComponent
{
    UnexposedParameters* unexposedParams;
    TabbedComponentForCustomVoicesBanks tabbedComponentForCustomVoicesBanks;
    TabbedComponentForFactoryVoicesBanks tabbedComponentForFactoryVoicesBanks;
    String voiceCopyBuffer;

public:
    TabbedComponentForAllVoicesBanks() = delete;

    TabbedComponentForAllVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void addListenerToPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void addListenerToPushEntireBankButtonInAllTabs(Button::Listener* listener);
    void removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForAllVoicesBanks)
};
