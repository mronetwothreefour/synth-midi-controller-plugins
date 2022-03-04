#include "voices_TabbedComponentForAllVoicesBanks.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



TabbedComponentForAllVoicesBanks::TabbedComponentForAllVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	tabbedComponentForCustomVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer },
	tabbedComponentForFactoryVoicesBanks{ exposedParams, unexposedParams, voiceCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForAllBanks.toString());
	setTabBarDepth(GUI::tabBarDepth);
	setOutline(0);
	addTab("FACTORY   BANKS", Color::device, &tabbedComponentForFactoryVoicesBanks, true, 1);
	addTab("CUSTOM   BANKS", Color::device, &tabbedComponentForCustomVoicesBanks, true, 1);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	setSize(GUI::tabbedComponentForAllVoicesBanks_w, GUI::tabbedComponentForAllVoicesBanks_h);
}

void TabbedComponentForAllVoicesBanks::addListenerToButtonsInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.addListenerToButtonsInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.addListenerToPushBankButtonInAllFactoryTabs(listener);
}

void TabbedComponentForAllVoicesBanks::removeListenerFromButtonsInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.removeListenerFromButtonsInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.removeListenerFromPushBankButtonInAllFactoryTabs(listener);
}

VoiceSlotsComponent* TabbedComponentForAllVoicesBanks::getVoiceSlotsComponentForCustomBank(VoicesBank bank) {
	jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
	return tabbedComponentForCustomVoicesBanks.getVoiceSlotsComponentForCustomBank(bank);
}

