#pragma once

#include <JuceHeader.h>

#include "voices_6_comp_TabbedComponentForCustomVoicesBanks.h"
#include "voices_6_comp_TabbedComponentForFactoryVoicesBanks.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"

class TabbedComponentForAllVoicesBanks :
    public TabbedComponent
{
    TabbedComponentForCustomVoicesBanks tabbedComponentForCustomVoicesBanks;
    TabbedComponentForFactoryVoicesBanks tabbedComponentForFactoryVoicesBanks;
    String voiceCopyBuffer;

public:
    TabbedComponentForAllVoicesBanks() = delete;

    TabbedComponentForAllVoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
        TabbedComponent(TabbedButtonBar::TabsAtTop),
        tabbedComponentForCustomVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer },
        tabbedComponentForFactoryVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer }
    {
        setComponentID(ID::comp_TabbedComponentForAllBanks.toString());
        setTabBarDepth(GUI::tabBarDepth);
        setOutline(0);
        addTab("FACTORY   BANKS", GUI::color_Device, &tabbedComponentForFactoryVoicesBanks, true, 1);
        addTab("CUSTOM   BANKS", GUI::color_Device, &tabbedComponentForCustomVoicesBanks, true, 1);
        setColour(backgroundColourId, GUI::color_Device.darker(0.25f));
        setSize(GUI::voicesBanksTabbedComponent_w, GUI::voicesBanksTabbedComponent_h + GUI::tabBarDepth);
    }

    void addListenerToButtonsInAllTabs(Button::Listener* listener) {
        tabbedComponentForCustomVoicesBanks.addListenerToButtonsInAllCustomTabs(listener);
        tabbedComponentForFactoryVoicesBanks.addListenerToButtonsInAllFactoryTabs(listener);
    }

    void removeListenerFromButtonsInAllTabs(Button::Listener* listener) {
        tabbedComponentForCustomVoicesBanks.removeListenerFromButtonsInAllCustomTabs(listener);
        tabbedComponentForFactoryVoicesBanks.removeListenerFromButtonsInAllFactoryTabs(listener);
    }

    VoiceSlots* getVoiceSlotsComponentForBank(VoicesBank bank) {
        if (bank >= VoicesBank::custom_1)
            return tabbedComponentForCustomVoicesBanks.getVoiceSlotsComponentForCustomBank(bank);
        else
            return tabbedComponentForFactoryVoicesBanks.getVoiceSlotsComponentForFactoryBank(bank);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForAllVoicesBanks)
};
