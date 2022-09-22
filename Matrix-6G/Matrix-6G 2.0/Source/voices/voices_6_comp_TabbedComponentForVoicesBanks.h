#pragma once

#include "voices_5_comp_TabForCustomVoicesBank.h"
#include "voices_5_comp_TabForFactoryVoicesBank.h"

class ExposedParameters;
class UnexposedParameters;

class TabbedComponentForVoicesBanks :
    public TabbedComponent
{
    TabForFactoryVoicesBank analogSynths_A;
    TabForFactoryVoicesBank analogSynths_B;
    TabForFactoryVoicesBank basses;
    TabForFactoryVoicesBank brassAndWoodwinds;
    TabForFactoryVoicesBank fxAndPercussion;
    TabForFactoryVoicesBank keyboards_A;
    TabForFactoryVoicesBank keyboards_B;
    TabForFactoryVoicesBank leads;
    TabForFactoryVoicesBank miscellaneous_A;
    TabForFactoryVoicesBank miscellaneous_B;
    TabForFactoryVoicesBank strings;
    TabForCustomVoicesBank custom_A;
    TabForCustomVoicesBank custom_B;
    String voiceCopyBuffer;

public:
    TabbedComponentForVoicesBanks() = delete;

    TabbedComponentForVoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void addListenerToButtonsInAllTabs(Button::Listener* listener);
    void removeListenerFromButtonsInAllTabs(Button::Listener* listener);
    VoiceSlots* getVoiceSlotsComponentForBank(VoicesBank bank);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForVoicesBanks)
};