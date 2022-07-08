#include "voices_6_comp_TabbedComponentForAllVoicesBanks.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"



TabbedComponentForAllVoicesBanks::TabbedComponentForAllVoicesBanks(
	ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	tabbedComponentForCustomVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer },
	tabbedComponentForFactoryVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForAllBanks.toString());
	setTabBarDepth(GUI::tabBarDepth);
	setOutline(0);
	addTab("FACTORY   BANKS", GUI::color_Device, &tabbedComponentForFactoryVoicesBanks, true, 1);
	addTab("CUSTOM   BANKS", GUI::color_Device, &tabbedComponentForCustomVoicesBanks, true, 1);
	setColour(backgroundColourId, GUI::color_Device.darker(0.25f));
	setSize(GUI::tabbedComponentForVoicesBanks_w, GUI::tabbedComponentForVoicesBanks_h + GUI::tabBarDepth);
}

void TabbedComponentForAllVoicesBanks::addListenerToButtonsInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.addListenerToButtonsInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.addListenerToButtonsInAllFactoryTabs(listener);
}

void TabbedComponentForAllVoicesBanks::removeListenerFromButtonsInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.removeListenerFromButtonsInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.removeListenerFromButtonsInAllFactoryTabs(listener);
}

VoiceSlots* TabbedComponentForAllVoicesBanks::getVoiceSlotsForBank(VoicesBank bank) {
	if (bank >= VoicesBank::custom_1)
		return tabbedComponentForCustomVoicesBanks.getVoiceSlotsComponentForCustomBank(bank);
	else
		return tabbedComponentForFactoryVoicesBanks.getVoiceSlotsComponentForFactoryBank(bank);
}
