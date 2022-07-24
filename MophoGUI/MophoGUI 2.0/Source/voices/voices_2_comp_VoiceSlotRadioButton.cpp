#include "voices_2_comp_VoiceSlotRadioButton.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

VoiceSlotRadioButton::VoiceSlotRadioButton() :
	bank{ VoicesBank::nullBank },
	slotNum{ VCS::numberOfSlotsInVoicesBank },
	slotNumString{ String(slotNum + 1) },
	unexposedParams{ nullptr }
{
	// this default constructor is needed when initializing the vector in VoiceSlots
}

VoiceSlotRadioButton::VoiceSlotRadioButton(const VoicesBank bank, const uint8 slotNum, UnexposedParameters* unexposedParams) :
	bank{ bank },
	slotNum{ slotNum },
	slotNumString{ String(slotNum + 1).paddedLeft('0', 3) },
	unexposedParams{ unexposedParams }
{
	if (bank >= VoicesBank::custom_1) {
		voiceNameValue = unexposedParams->getVoicesBanks()->getVoiceNameValueForCustomBankSlot(bank, slotNum);
		setRadioGroupId((int)bank);
		voiceNameValue.addListener(this);
	}

	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipsOptions->shouldShowDescription() };
	setComponentID(ID::btn_VoiceSlotRadioButton.toString());
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
		tip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		tip += "CTRL+V overwrites the selected program with the settings in the\n";
		tip += "clipboard (only slots in the Custom banks can be overwritten).";
	}
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slotNum) };
	setName(slotNumString + " " + voiceName);
	setSize(GUI::voiceSlotRadioButtton_w, GUI::voiceSlotRadioButtton_h);
}

void VoiceSlotRadioButton::valueChanged(Value& /*value*/) {
	auto voiceName{ voiceNameValue.getValue().toString() };
	setName(slotNumString + " " + voiceName);
	repaint();
}

VoiceSlotRadioButton::~VoiceSlotRadioButton() {
	if (bank >= VoicesBank::custom_1)
		voiceNameValue.removeListener(this);
}