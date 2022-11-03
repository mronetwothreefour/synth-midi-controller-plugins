#include "voices_2_comp_VoiceSlotRadioButton.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

VoiceSlotRadioButton::VoiceSlotRadioButton() :
	slotNum{ VCS::numberOfSlotsInVoicesBank },
	slotNumString{ String(slotNum) },
	unexposedParams{ nullptr }
{
	// this default constructor is needed when initializing the vector in VoiceSlots
}

VoiceSlotRadioButton::VoiceSlotRadioButton(const uint8 slotNum, UnexposedParameters* unexposedParams) :
	slotNum{ slotNum },
	slotNumString{ String(slotNum).paddedLeft('0', 2) },
	unexposedParams{ unexposedParams }
{
	auto voicesBank{ unexposedParams->getVoicesBank() };
	voiceDataAsValue = voicesBank->getVoiceDataHexStringAsValueForSlot(slotNum);
	voiceDataAsValue.addListener(this);

	setRadioGroupId(1);
	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipsOptions->shouldShowDescription() };
	setComponentID(ID::btn_VoiceSlotRadioButton.toString());
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons above.\n";
		tip += "CTRL-C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		tip += "CTRL-V overwrites the selected program with the settings in the clipboard.";
	}
	auto voiceName{ voicesBank->nameOfVoiceInSlot(slotNum) };
	setName(slotNumString + " " + voiceName);
	setSize(GUI::voiceSlotRadioButtton_w, GUI::voiceSlotAndAllowChoiceRadioButtton_h);
}

void VoiceSlotRadioButton::valueChanged(Value& /*value*/) {
	auto voiceName{ unexposedParams->getVoicesBank()->nameOfVoiceInSlot(slotNum) };
	setName(slotNumString + " " + voiceName);
	repaint();
}

VoiceSlotRadioButton::~VoiceSlotRadioButton() {
	voiceDataAsValue.removeListener(this);
}
