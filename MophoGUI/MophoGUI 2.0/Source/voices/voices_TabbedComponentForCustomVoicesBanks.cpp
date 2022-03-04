#include "voices_TabbedComponentForCustomVoicesBanks.h"

#include "voices_VoicesBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabbedComponentForCustomVoicesBanks::TabbedComponentForCustomVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	unexposedParams{ unexposedParams },
	bank1{ VoicesBank::custom1, exposedParams, unexposedParams, voiceCopyBuffer },
	bank2{ VoicesBank::custom2, exposedParams, unexposedParams, voiceCopyBuffer },
	bank3{ VoicesBank::custom3, exposedParams, unexposedParams, voiceCopyBuffer }
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

void TabbedComponentForCustomVoicesBanks::addListenerToButtonsInAllCustomTabs(Button::Listener* listener) {
	bank1.addListenerToButtons(listener);
	bank2.addListenerToButtons(listener);
	bank3.addListenerToButtons(listener);
}

void TabbedComponentForCustomVoicesBanks::removeListenerFromButtonsInAllCustomTabs(Button::Listener* listener) {
	bank1.removeListenerFromButtons(listener);
	bank2.removeListenerFromButtons(listener);
	bank3.removeListenerFromButtons(listener);
}

