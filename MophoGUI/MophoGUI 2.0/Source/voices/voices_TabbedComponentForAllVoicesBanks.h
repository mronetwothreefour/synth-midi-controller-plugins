#pragma once

#include <JuceHeader.h>

#include "voices_TabbedComponentForCustomVoicesBanks.h"
#include "voices_TabbedComponentForFactoryVoicesBanks.h"



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
    void addListenerToPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void addListenerToPushEntireBankButtonInAllTabs(Button::Listener* listener);
    void removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForAllProgramBanks)
};
