#include "voices_6_comp_TabbedComponentForVoicesBanks.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

TabbedComponentForVoicesBanks::TabbedComponentForVoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	TabbedComponent(TabbedButtonBar::TabsAtTop),
	analogSynths_A{ VoicesBank::analogSynths_A, exposedParams, unexposedParams, voiceCopyBuffer },
	analogSynths_B{ VoicesBank::analogSynths_B, exposedParams, unexposedParams, voiceCopyBuffer },
	basses{ VoicesBank::basses, exposedParams, unexposedParams, voiceCopyBuffer },
	brassAndWoodwinds{ VoicesBank::brassAndWoodwinds, exposedParams, unexposedParams, voiceCopyBuffer },
	fxAndPercussion{ VoicesBank::fxAndPercussion, exposedParams, unexposedParams, voiceCopyBuffer },
	keyboards_A{ VoicesBank::keyboards_A, exposedParams, unexposedParams, voiceCopyBuffer },
	keyboards_B{ VoicesBank::keyboards_B, exposedParams, unexposedParams, voiceCopyBuffer },
	leads{ VoicesBank::leads, exposedParams, unexposedParams, voiceCopyBuffer },
	miscellaneous_A{ VoicesBank::miscellaneous_A, exposedParams, unexposedParams, voiceCopyBuffer },
	miscellaneous_B{ VoicesBank::miscellaneous_B, exposedParams, unexposedParams, voiceCopyBuffer },
	strings{ VoicesBank::strings, exposedParams, unexposedParams, voiceCopyBuffer },
	custom_A{ VoicesBank::custom_A, exposedParams, unexposedParams, voiceCopyBuffer },
	custom_B{ VoicesBank::custom_B, exposedParams, unexposedParams, voiceCopyBuffer }
{
	setComponentID(ID::comp_TabbedComponentForVoicesBanks.toString());
	setTabBarDepth(0);
	setOutline(0);
	addTab("ANALOG SYNTHS A", GUI::color_Device, &analogSynths_A, true, 1);
	addTab("ANALOG SYNTHS B", GUI::color_Device, &analogSynths_B, true, 2);
	addTab("BASSES", GUI::color_Device, &basses, true, 3);
	addTab("BRASS & WOODWIND", GUI::color_Device, &brassAndWoodwinds, true, 4);
	addTab("FX & PERCUSSION", GUI::color_Device, &fxAndPercussion, true, 5);
	addTab("KEYBOARDS A", GUI::color_Device, &keyboards_A, true, 6);
	addTab("KEYBOARDS B", GUI::color_Device, &keyboards_B, true, 7);
	addTab("LEADS", GUI::color_Device, &leads, true, 8);
	addTab("MISCELLANEOUS A", GUI::color_Device, &miscellaneous_A, true, 9);
	addTab("MISCELLANEOUS B", GUI::color_Device, &miscellaneous_B, true, 10);
	addTab("STRINGS", GUI::color_Device, &strings, true, 11);
	addTab("CUSTOM A", GUI::color_Device, &custom_A, true, 12);
	addTab("CUSTOM B", GUI::color_Device, &custom_B, true, 13);
	setSize(GUI::voicesBankTab_w, GUI::voicesBankTab_h);
}

void TabbedComponentForVoicesBanks::addListenerToButtonsInAllTabs(Button::Listener* listener) {
	analogSynths_A.addListenerToButtons(listener);
	analogSynths_B.addListenerToButtons(listener);
	basses.addListenerToButtons(listener);
	brassAndWoodwinds.addListenerToButtons(listener);
	fxAndPercussion.addListenerToButtons(listener);
	keyboards_A.addListenerToButtons(listener);
	keyboards_B.addListenerToButtons(listener);
	leads.addListenerToButtons(listener);
	miscellaneous_A.addListenerToButtons(listener);
	miscellaneous_B.addListenerToButtons(listener);
	strings.addListenerToButtons(listener);
	custom_A.addListenerToButtons(listener);
	custom_B.addListenerToButtons(listener);
}

void TabbedComponentForVoicesBanks::removeListenerFromButtonsInAllTabs(Button::Listener* listener) {
	analogSynths_A.removeListenerFromButtons(listener);
	analogSynths_B.removeListenerFromButtons(listener);
	basses.removeListenerFromButtons(listener);
	brassAndWoodwinds.removeListenerFromButtons(listener);
	fxAndPercussion.removeListenerFromButtons(listener);
	keyboards_A.removeListenerFromButtons(listener);
	keyboards_B.removeListenerFromButtons(listener);
	leads.removeListenerFromButtons(listener);
	miscellaneous_A.removeListenerFromButtons(listener);
	miscellaneous_B.removeListenerFromButtons(listener);
	strings.removeListenerFromButtons(listener);
	custom_A.removeListenerFromButtons(listener);
	custom_B.removeListenerFromButtons(listener);
}

VoiceSlots* TabbedComponentForVoicesBanks::getVoiceSlotsComponentForBank(VoicesBank bank) {
	switch (bank)
	{
	case VoicesBank::analogSynths_A: return analogSynths_A.getVoiceSlots();
	case VoicesBank::analogSynths_B: return analogSynths_B.getVoiceSlots();
	case VoicesBank::basses: return basses.getVoiceSlots();
	case VoicesBank::brassAndWoodwinds: return brassAndWoodwinds.getVoiceSlots();
	case VoicesBank::fxAndPercussion: return fxAndPercussion.getVoiceSlots();
	case VoicesBank::keyboards_A: return keyboards_A.getVoiceSlots();
	case VoicesBank::keyboards_B: return keyboards_B.getVoiceSlots();
	case VoicesBank::leads: return leads.getVoiceSlots();
	case VoicesBank::miscellaneous_A: return miscellaneous_A.getVoiceSlots();
	case VoicesBank::miscellaneous_B: return miscellaneous_B.getVoiceSlots();
	case VoicesBank::strings: return strings.getVoiceSlots();
	case VoicesBank::custom_A: return custom_A.getVoiceSlots();
	case VoicesBank::custom_B: return custom_B.getVoiceSlots();
	default: return analogSynths_A.getVoiceSlots();
	}
}
