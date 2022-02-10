#pragma once

#include <JuceHeader.h>

#include "patches_TabForCustomPatchBank.h"
#include "patches_TabForFactoryPatchBank.h"



class UnexposedParameters;

class TabbedComponentForPatchBanks :
    public TabbedComponent
{
    TabForCustomPatchBank customA;
    TabForCustomPatchBank customB;
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
    String patchCopyBuffer;

public:
    TabbedComponentForPatchBanks() = delete;

    TabbedComponentForPatchBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener);
    void addListenerToPushBankButtonInAllTabs(Button::Listener* listener);
    void removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener);
    void removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForPatchBanks)
};
