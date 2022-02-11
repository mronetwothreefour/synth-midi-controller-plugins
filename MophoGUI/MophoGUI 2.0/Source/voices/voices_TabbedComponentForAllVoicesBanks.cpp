#include "voices_TabbedComponentForAllVoicesBanks.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



TabbedComponentForAllProgramBanks::TabbedComponentForAllProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	tabbedComponentForCustomProgramBanks{ exposedParams, unexposedParams, programCopyBuffer },
	tabbedComponentForFactoryProgramBanks{ exposedParams, unexposedParams, programCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForAllBanks.toString());
	setTabBarDepth(GUI::tabBarDepth);
	setOutline(0);
	addTab("FACTORY   BANKS", Color::device, &tabbedComponentForFactoryProgramBanks, true, 1);
	addTab("CUSTOM   BANKS", Color::device, &tabbedComponentForCustomProgramBanks, true, 1);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	setSize(GUI::tabbedComponentForAllVoicesBanks_w, GUI::tabbedComponentForAllVoicesBanks_h);
}

void TabbedComponentForAllProgramBanks::addListenerToPullEntireBankButtonInAllCustomTabs(Button::Listener* listener) {
	tabbedComponentForCustomProgramBanks.addListenerToPullBankButtonInAllCustomTabs(listener);
}

void TabbedComponentForAllProgramBanks::addListenerToPushEntireBankButtonInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomProgramBanks.addListenerToPushBankButtonInAllCustomTabs(listener);
	tabbedComponentForFactoryProgramBanks.addListenerToPushBankButtonInAllFactoryTabs(listener);
}

void TabbedComponentForAllProgramBanks::removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener) {
	tabbedComponentForCustomProgramBanks.removeListenerFromPullBankButtonInAllCustomTabs(listener);
}

void TabbedComponentForAllProgramBanks::removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener) {
	tabbedComponentForCustomProgramBanks.removeListenerFromPushBankButtonInAllCustomTabs(listener);
	tabbedComponentForFactoryProgramBanks.removeListenerFromPushBankButtonInAllFactoryTabs(listener);
}

