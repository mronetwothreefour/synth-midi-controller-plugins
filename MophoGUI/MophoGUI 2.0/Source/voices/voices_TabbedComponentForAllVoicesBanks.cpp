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

void TabbedComponentForAllVoicesBanks::addListenerToPullEntireBankButtonInAllCustomTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.addListenerToPullBankButtonInAllCustomTabs(listener);
}

void TabbedComponentForAllVoicesBanks::addListenerToPushEntireBankButtonInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.addListenerToPushBankButtonInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.addListenerToPushBankButtonInAllFactoryTabs(listener);
}

void TabbedComponentForAllVoicesBanks::removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.removeListenerFromPullBankButtonInAllCustomTabs(listener);
}

void TabbedComponentForAllVoicesBanks::removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomVoicesBanks.removeListenerFromPushBankButtonInAllCustomTabs(listener);
	tabbedComponentForFactoryVoicesBanks.removeListenerFromPushBankButtonInAllFactoryTabs(listener);
}

