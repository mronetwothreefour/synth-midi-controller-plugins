#pragma once

#include <JuceHeader.h>

#include "voices_TabForCustomVoicesBank.h"
#include "voices_TabForFactoryVoicesBank.h"



class UnexposedParameters;

class TabbedComponentForVoicesBanks :
    public TabbedComponent
{
    TabForCustomVoicesBank customA;
    TabForCustomVoicesBank customB;
    TabForFactoryVoicesBank analogSynthsA;
    TabForFactoryVoicesBank analogSynthsB;
    TabForFactoryVoicesBank basses;
    TabForFactoryVoicesBank brassAndWoodwinds;
    TabForFactoryVoicesBank fxAndPercussion;
    TabForFactoryVoicesBank keyboardsA;
    TabForFactoryVoicesBank keyboardsB;
    TabForFactoryVoicesBank leads;
    TabForFactoryVoicesBank miscellaneousA;
    TabForFactoryVoicesBank miscellaneousB;
    TabForFactoryVoicesBank strings;
    UnexposedParameters* unexposedParams;
    String voiceCopyBuffer;

public:
    TabbedComponentForVoicesBanks() = delete;

    TabbedComponentForVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener);
    void addListenerToPushBankButtonInAllTabs(Button::Listener* listener);
    void removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForVoicesBanks)
};
