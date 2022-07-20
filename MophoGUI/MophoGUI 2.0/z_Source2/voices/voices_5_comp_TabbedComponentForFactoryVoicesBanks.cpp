#include "voices_5_comp_TabbedComponentForFactoryVoicesBanks.h"

#include "voices_1_tree_VoicesBanks.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



TabbedComponentForFactoryVoicesBanks::TabbedComponentForFactoryVoicesBanks(
	ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bank_1{ VoicesBank::factory_1, exposedParams, unexposedParams, voiceCopyBuffer },
	bank_2{ VoicesBank::factory_2, exposedParams, unexposedParams, voiceCopyBuffer },
	bank_3{ VoicesBank::factory_3, exposedParams, unexposedParams, voiceCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForFactoryBanks.toString());
	setTabBarDepth(GUI::tabBarDepth);
	setOutline(0);
	addTab("1", GUI::color_Device, &bank_1, true, 1);
	addTab("2", GUI::color_Device, &bank_2, true, 2);
	addTab("3", GUI::color_Device, &bank_3, true, 3);
	setColour(backgroundColourId, GUI::color_Device.darker(0.25f));
	setSize(GUI::tabbedComponentForVoicesBanks_w, GUI::tabbedComponentForVoicesBanks_h);
}

void TabbedComponentForFactoryVoicesBanks::addListenerToButtonsInAllFactoryTabs(Button::Listener* listener) {
	bank_1.addListenerToButtons(listener);
	bank_2.addListenerToButtons(listener);
	bank_3.addListenerToButtons(listener);
}

void TabbedComponentForFactoryVoicesBanks::removeListenerFromButtonsInAllFactoryTabs(Button::Listener* listener) {
	bank_1.removeListenerFromButtons(listener);
	bank_2.removeListenerFromButtons(listener);
	bank_3.removeListenerFromButtons(listener);
}

VoiceSlots* TabbedComponentForFactoryVoicesBanks::getVoiceSlotsComponentForFactoryBank(VoicesBank bank) {
	jassert(bank <= VoicesBank::factory_1);
	switch (bank) {
	case VoicesBank::factory_1:
		return bank_1.getVoiceSlots();
	case VoicesBank::factory_2:
		return bank_2.getVoiceSlots();
	case VoicesBank::factory_3:
		return bank_3.getVoiceSlots();
	default:
		return bank_1.getVoiceSlots();
	}
}
