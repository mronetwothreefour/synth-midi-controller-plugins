#include "voices_TabbedComponentForCustomVoicesBanks.h"

#include "voices_VoicesBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabbedComponentForCustomProgramBanks::TabbedComponentForCustomProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	unexposedParams{ unexposedParams },
	bank1{ ProgramBank::custom1, exposedParams, unexposedParams, programCopyBuffer },
	bank2{ ProgramBank::custom2, exposedParams, unexposedParams, programCopyBuffer },
	bank3{ ProgramBank::custom3, exposedParams, unexposedParams, programCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForCustomBanks.toString());
	setTabBarDepth(30);
	setOutline(0);
	addTab("1", Color::device, &bank1, true, 1);
	addTab("2", Color::device, &bank2, true, 2);
	addTab("3", Color::device, &bank3, true, 3);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	setSize(GUI::tabbedComponentForVoicesBanks_w, GUI::tabbedComponentForVoicesBanks_h);
}

void TabbedComponentForCustomProgramBanks::addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener) {
	bank1.addListenerToPullEntireBankButton(listener);
	bank2.addListenerToPullEntireBankButton(listener);
	bank3.addListenerToPullEntireBankButton(listener);
}

void TabbedComponentForCustomProgramBanks::addListenerToPushBankButtonInAllCustomTabs(Button::Listener* listener) {
	bank1.addListenerToPushEntireBankButton(listener);
	bank2.addListenerToPushEntireBankButton(listener);
	bank3.addListenerToPushEntireBankButton(listener);
}

void TabbedComponentForCustomProgramBanks::removeListenerFromPullBankButtonInAllCustomTabs(Button::Listener* listener) {
	bank1.removeListenerFromPullEntireBankButton(listener);
	bank2.removeListenerFromPullEntireBankButton(listener);
	bank3.removeListenerFromPullEntireBankButton(listener);
}

void TabbedComponentForCustomProgramBanks::removeListenerFromPushBankButtonInAllCustomTabs(Button::Listener* listener) {
	bank1.removeListenerFromPushEntireBankButton(listener);
	bank2.removeListenerFromPushEntireBankButton(listener);
	bank3.removeListenerFromPushEntireBankButton(listener);
}

