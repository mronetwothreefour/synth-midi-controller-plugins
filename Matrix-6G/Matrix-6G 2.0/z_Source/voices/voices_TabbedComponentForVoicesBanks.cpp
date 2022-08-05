#include "voices_TabbedComponentForVoicesBanks.h"

#include "voices_VoicesBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabbedComponentForVoicesBanks::TabbedComponentForVoicesBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	analogSynthsA{ VoicesBank::analogSynthsA, exposedParams, unexposedParams, voiceCopyBuffer },
	analogSynthsB{ VoicesBank::analogSynthsB, exposedParams, unexposedParams, voiceCopyBuffer },
	basses{ VoicesBank::basses, exposedParams, unexposedParams, voiceCopyBuffer },
	brassAndWoodwinds{ VoicesBank::brassAndWoodwinds, exposedParams, unexposedParams, voiceCopyBuffer },
	customA{ VoicesBank::customA, exposedParams, unexposedParams, voiceCopyBuffer },
	customB{ VoicesBank::customB, exposedParams, unexposedParams, voiceCopyBuffer },
	fxAndPercussion{ VoicesBank::fxAndPercussion, exposedParams, unexposedParams, voiceCopyBuffer },
	keyboardsA{ VoicesBank::keyboardsA, exposedParams, unexposedParams, voiceCopyBuffer },
	keyboardsB{ VoicesBank::keyboardsB, exposedParams, unexposedParams, voiceCopyBuffer },
	leads{ VoicesBank::leads, exposedParams, unexposedParams, voiceCopyBuffer },
	miscellaneousA{ VoicesBank::miscellaneousA, exposedParams, unexposedParams, voiceCopyBuffer },
	miscellaneousB{ VoicesBank::miscellaneousB, exposedParams, unexposedParams, voiceCopyBuffer },
	strings{ VoicesBank::strings, exposedParams, unexposedParams, voiceCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForCustomBanks.toString());
	setTabBarDepth(GUI::voicesBanksTabBarDepth);
	setOutline(0);
	addTab("Analog Synths A", Color::device, &analogSynthsA, true, 1);
	addTab("Analog Synths B", Color::device, &analogSynthsB, true, 2);
	addTab("Basses", Color::device, &basses, true, 3);
	addTab("Brass & Woodwinds", Color::device, &brassAndWoodwinds, true, 4);
	addTab("Custom A", Color::device, &customA, true, 5);
	addTab("Custom B", Color::device, &customB, true, 6);
	addTab("FX & Percussion", Color::device, &fxAndPercussion, true, 7);
	addTab("Keyboards A", Color::device, &keyboardsA, true, 8);
	addTab("Keyboards B", Color::device, &keyboardsB, true, 9);
	addTab("Leads", Color::device, &leads, true, 10);
	addTab("Miscellaneous A", Color::device, &miscellaneousA, true, 11);
	addTab("Miscellaneous B", Color::device, &miscellaneousB, true, 12);
	addTab("Strings", Color::device, &strings, true, 13);
	setSize(GUI::voicesBanksTab_w, GUI::voicesBanksTab_h);
}

void TabbedComponentForVoicesBanks::addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener) {
	customA.addListenerToPullEntireBankButton(listener);
	customB.addListenerToPullEntireBankButton(listener);
}

void TabbedComponentForVoicesBanks::addListenerToPushBankButtonInAllTabs(Button::Listener* listener) {
	analogSynthsA.addListenerToPushEntireBankButton(listener);
	analogSynthsB.addListenerToPushEntireBankButton(listener);
	basses.addListenerToPushEntireBankButton(listener);
	brassAndWoodwinds.addListenerToPushEntireBankButton(listener);
	customA.addListenerToPushEntireBankButton(listener);
	customB.addListenerToPushEntireBankButton(listener);
	fxAndPercussion.addListenerToPushEntireBankButton(listener);
	keyboardsA.addListenerToPushEntireBankButton(listener);
	keyboardsB.addListenerToPushEntireBankButton(listener);
	leads.addListenerToPushEntireBankButton(listener);
	miscellaneousA.addListenerToPushEntireBankButton(listener);
	miscellaneousB.addListenerToPushEntireBankButton(listener);
	strings.addListenerToPushEntireBankButton(listener);
}

void TabbedComponentForVoicesBanks::removeListenerFromPullEntireBankButtonInAllCustomTabs(Button::Listener* listener) {
	customA.removeListenerFromPullEntireBankButton(listener);
	customB.removeListenerFromPullEntireBankButton(listener);
}

void TabbedComponentForVoicesBanks::removeListenerFromPushEntireBankButtonInAllTabs(Button::Listener* listener) {
	analogSynthsA.removeListenerFromPushEntireBankButton(listener);
	analogSynthsB.removeListenerFromPushEntireBankButton(listener);
	basses.removeListenerFromPushEntireBankButton(listener);
	brassAndWoodwinds.removeListenerFromPushEntireBankButton(listener);
	customA.removeListenerFromPushEntireBankButton(listener);
	customB.removeListenerFromPushEntireBankButton(listener);
	fxAndPercussion.removeListenerFromPushEntireBankButton(listener);
	keyboardsA.removeListenerFromPushEntireBankButton(listener);
	keyboardsB.removeListenerFromPushEntireBankButton(listener);
	leads.removeListenerFromPushEntireBankButton(listener);
	miscellaneousA.removeListenerFromPushEntireBankButton(listener);
	miscellaneousB.removeListenerFromPushEntireBankButton(listener);
	strings.removeListenerFromPushEntireBankButton(listener);
}
