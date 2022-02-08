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
    TabForFactoryPatchBank analogSynthsA;
    TabForFactoryPatchBank analogSynthsB;
    TabForFactoryPatchBank basses;
    TabForFactoryPatchBank brassAndWoodwinds;
    TabForFactoryPatchBank fxAndPercussion;
    TabForFactoryPatchBank keyboardsA;
    TabForFactoryPatchBank keyboardsB;
    TabForFactoryPatchBank leads;
    TabForFactoryPatchBank miscellaneousA;
    TabForFactoryPatchBank miscellaneousB;
    TabForFactoryPatchBank strings;
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
