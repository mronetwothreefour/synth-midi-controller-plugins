#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"



class ButtonForSavingProgramInSelectedSlot :
	public TextButton
{
	ProgramSlotsWidget& programSlots;

	void storeCurrentProgramSettingsInSelectedSlot() {
		programSlots.storeCurrentProgramSettingsInSelectedSlot();
	}

public:
	ButtonForSavingProgramInSelectedSlot() = delete;

	explicit ButtonForSavingProgramInSelectedSlot(ProgramSlotsWidget& programSlots) :
		TextButton{ "SAVE" },
		programSlots{ programSlots }
	{
		String tipString;
		tipString =  "Saves the plugin GUI's current settings\n";
		tipString += "in the selected program storage slot.";
		setTooltip(tipString);
		onClick = [this] { storeCurrentProgramSettingsInSelectedSlot(); };
	}

	~ButtonForSavingProgramInSelectedSlot() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingProgramInSelectedSlot)
};
