#include "master_PatchMapSlotsColumn.h"

#include "../gui/gui_Constants.h"

using namespace constants;



PatchMapSlotsColumn::PatchMapSlotsColumn(UnexposedParameters* unexposedParams, uint8 firstProgramNumber) :
	slot_0{ unexposedParams, firstProgramNumber },
	slot_1{ unexposedParams, firstProgramNumber + 1 },
	slot_2{ unexposedParams, firstProgramNumber + 2 },
	slot_3{ unexposedParams, firstProgramNumber + 3 },
	slot_4{ unexposedParams, firstProgramNumber + 4 },
	slot_5{ unexposedParams, firstProgramNumber + 5 },
	slot_6{ unexposedParams, firstProgramNumber + 6 },
	slot_7{ unexposedParams, firstProgramNumber + 7 },
	slot_8{ unexposedParams, firstProgramNumber + 8 },
	slot_9{ unexposedParams, firstProgramNumber + 9 }
{
	jassert(firstProgramNumber < 100 && firstProgramNumber % 10 == 0);
	addAndMakeVisible(slot_0);
	addAndMakeVisible(slot_1);
	addAndMakeVisible(slot_2);
	addAndMakeVisible(slot_3);
	addAndMakeVisible(slot_4);
	addAndMakeVisible(slot_5);
	addAndMakeVisible(slot_6);
	addAndMakeVisible(slot_7);
	addAndMakeVisible(slot_8);
	addAndMakeVisible(slot_9);
	setSize(GUI::patchMapSlotsColumn_w, GUI::patchMapSlotsColumn_h);
}

void PatchMapSlotsColumn::resized() {
	slot_0.setBounds(0, 0, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_1.setBounds(0, GUI::controlsVerticalGap, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_2.setBounds(0, GUI::controlsVerticalGap * 2, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_3.setBounds(0, GUI::controlsVerticalGap * 3, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_4.setBounds(0, GUI::controlsVerticalGap * 4, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_5.setBounds(0, GUI::controlsVerticalGap * 5, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_6.setBounds(0, GUI::controlsVerticalGap * 6, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_7.setBounds(0, GUI::controlsVerticalGap * 7, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_8.setBounds(0, GUI::controlsVerticalGap * 8, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
	slot_9.setBounds(0, GUI::controlsVerticalGap * 9, GUI::patchMapSlot_w, GUI::patchMapSlot_h);
}
