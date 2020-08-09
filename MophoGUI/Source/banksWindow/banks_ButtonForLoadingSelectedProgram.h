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
