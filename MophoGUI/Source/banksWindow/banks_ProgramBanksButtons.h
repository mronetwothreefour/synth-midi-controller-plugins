#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"



class ButtonForLoadingSelectedProgram :
	public TextButton
{
	ProgramSlotsWidget& programSlots;

	void loadProgramFromSelectedSlot() {
		programSlots.loadProgramFromSelectedSlot();
	}

public:
	ButtonForLoadingSelectedProgram() = delete;

	explicit ButtonForLoadingSelectedProgram(ProgramSlotsWidget& programSlots) :
		TextButton{ "LOAD" },
		programSlots{ programSlots }
	{
		String tipString;
		tipString =  "Applies the program settings stored in the selected slot to the\n";
		tipString += "plugin GUI and to the Mopho hardware's program edit buffer.";
		setTooltip(tipString);
		onClick = [this] { loadProgramFromSelectedSlot(); };
	}

	~ButtonForLoadingSelectedProgram() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForLoadingSelectedProgram)
};



class ButtonForSavingProgramInSelectedSlot :
	public TextButton
{
	ProgramSlotsWidget& programSlots;

	void saveProgramToSelectedSlot() {
		programSlots.storeProgramInSelectedSlot();
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
		onClick = [this] { saveProgramToSelectedSlot(); };
	}

	~ButtonForSavingProgramInSelectedSlot() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForSavingProgramInSelectedSlot)
};
