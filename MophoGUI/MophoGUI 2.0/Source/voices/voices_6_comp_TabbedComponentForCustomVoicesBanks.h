#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBanks.h"
#include "voices_5_comp_TabForCustomVoicesBank.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

class TabbedComponentForCustomVoicesBanks :
    public TabbedComponent
{
    TabForCustomVoicesBank bank_1;
    TabForCustomVoicesBank bank_2;
    TabForCustomVoicesBank bank_3;

public:
    TabbedComponentForCustomVoicesBanks() = delete;

    TabbedComponentForCustomVoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
		TabbedComponent(TabbedButtonBar::TabsAtLeft),
		bank_1{ VoicesBank::custom_1, exposedParams, unexposedParams, voiceCopyBuffer },
		bank_2{ VoicesBank::custom_2, exposedParams, unexposedParams, voiceCopyBuffer },
		bank_3{ VoicesBank::custom_3, exposedParams, unexposedParams, voiceCopyBuffer }
	{
		setComponentID(ID::comp_TabbedComponentForCustomBanks.toString());
		setTabBarDepth(GUI::tabBarDepth);
		setOutline(0);
		addTab("1", GUI::color_Device, &bank_1, true, 1);
		addTab("2", GUI::color_Device, &bank_2, true, 2);
		addTab("3", GUI::color_Device, &bank_3, true, 3);
		setColour(backgroundColourId, GUI::color_Device.darker(0.25f));
		setSize(GUI::voicesBanksTabbedComponent_w, GUI::voicesBanksTabbedComponent_h);
	}

    void addListenerToButtonsInAllCustomTabs(Button::Listener* listener) {
		bank_1.addListenerToButtons(listener);
		bank_2.addListenerToButtons(listener);
		bank_3.addListenerToButtons(listener);
	}

    void removeListenerFromButtonsInAllCustomTabs(Button::Listener* listener) {
		bank_1.removeListenerFromButtons(listener);
		bank_2.removeListenerFromButtons(listener);
		bank_3.removeListenerFromButtons(listener);
	}

    VoiceSlots* getVoiceSlotsComponentForCustomBank(VoicesBank bank) {
		jassert(bank >= VoicesBank::custom_1);
		switch (bank) {
		case VoicesBank::custom_1: return bank_1.getVoiceSlots();
		case VoicesBank::custom_2: return bank_2.getVoiceSlots();
		case VoicesBank::custom_3: return bank_3.getVoiceSlots();
		default: return bank_1.getVoiceSlots();
		}
	}

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabbedComponentForCustomVoicesBanks)
};
