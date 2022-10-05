#include "splits_1_comp_SplitSlotRadioButton.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Splits.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

SplitSlotRadioButton::SplitSlotRadioButton() :
	slotNum{ SPLT::numberOfSlotsInSplitsBank },
	slotNumString{ String(slotNum) },
	unexposedParams{ nullptr }
{
	// this default constructor is needed when initializing the vector in SplitSlots
}

SplitSlotRadioButton::SplitSlotRadioButton(const uint8 slotNum, UnexposedParameters* unexposedParams) :
	slotNum{ slotNum },
	slotNumString{ String(slotNum).paddedLeft('0', 2) },
	unexposedParams{ unexposedParams }
{
	auto splitsBank{ unexposedParams->getSplitsBank() };
	splitNameAsValue = splitsBank->getSplitNameAsValueForSlot(slotNum);
	splitNameAsValue.addListener(this);

	setRadioGroupId(1);
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltips->shouldShowDescription() };
	setComponentID(ID::btn_RadioButton_SplitSlot.toString());
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Click a split" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
		tip += "CTRL+C copies the selected split" + GUI::apostrophe + "s settings into the clipboard.\n";
		tip += "CTRL+V overwrites the selected split with the settings in the clipboard.";
	}
	auto splitName{ splitsBank->nameOfSplitInSlot(slotNum) };
	setName(slotNumString + " - " + splitName);
	setSize(GUI::splitSlotRadioButtton_w, GUI::voiceAndSplitSlotRadioButtton_h);
}

void SplitSlotRadioButton::valueChanged(Value& /*value*/) {
	auto splitName{ splitNameAsValue.getValue().toString() };
	setName(slotNumString + " - " + splitName);
	repaint();
}

SplitSlotRadioButton::~SplitSlotRadioButton() {
	splitNameAsValue.removeListener(this);
}
