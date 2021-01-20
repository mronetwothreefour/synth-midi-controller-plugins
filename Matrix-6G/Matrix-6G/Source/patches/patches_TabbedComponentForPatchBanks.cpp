#include "patches_TabbedComponentForPatchBanks.h"

#include "patches_PatchBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabbedComponentForPatchBanks::TabbedComponentForPatchBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& patchCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	unexposedParams{ unexposedParams },
	analogSynthsA{ PatchBank::analogSynthsA, exposedParams, unexposedParams, patchCopyBuffer },
	analogSynthsB{ PatchBank::analogSynthsB, exposedParams, unexposedParams, patchCopyBuffer },
	basses{ PatchBank::basses, exposedParams, unexposedParams, patchCopyBuffer },
	brassAndWoodwinds{ PatchBank::brassAndWoodwinds, exposedParams, unexposedParams, patchCopyBuffer },
	customA{ PatchBank::customA, exposedParams, unexposedParams, patchCopyBuffer },
	customB{ PatchBank::customB, exposedParams, unexposedParams, patchCopyBuffer },
	fxAndPercussion{ PatchBank::fxAndPercussion, exposedParams, unexposedParams, patchCopyBuffer },
	keyboardsA{ PatchBank::keyboardsA, exposedParams, unexposedParams, patchCopyBuffer },
	keyboardsB{ PatchBank::keyboardsB, exposedParams, unexposedParams, patchCopyBuffer },
	leads{ PatchBank::leads, exposedParams, unexposedParams, patchCopyBuffer },
	miscellaneousA{ PatchBank::miscellaneousA, exposedParams, unexposedParams, patchCopyBuffer },
	miscellaneousB{ PatchBank::miscellaneousB, exposedParams, unexposedParams, patchCopyBuffer },
	strings{ PatchBank::strings, exposedParams, unexposedParams, patchCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForCustomBanks.toString());
	setTabBarDepth(GUI::patchBanksTabBarDepth);
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
	setSize(GUI::patchBanksTab_w, GUI::patchBanksTab_h);
}

void TabbedComponentForPatchBanks::addListenerToPullBankButtonInAllCustomTabs(Button::Listener* listener) {
	customA.addListenerToPullEntireBankButton(listener);
	customB.addListenerToPullEntireBankButton(listener);
}

void TabbedComponentForPatchBanks::addListenerToPushBankButtonInAllTabs(Button::Listener* listener) {
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

void TabbedComponentForPatchBanks::removeListenerFromPullBankButtonInAllCustomTabs(Button::Listener* listener) {
	customA.removeListenerFromPullEntireBankButton(listener);
	customB.removeListenerFromPullEntireBankButton(listener);
}

void TabbedComponentForPatchBanks::removeListenerFromPushBankButtonInAllCustomTabs(Button::Listener* listener) {
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
