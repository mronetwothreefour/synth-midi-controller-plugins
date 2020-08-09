#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"



class ButtonForPushingSelectedProgramToHardware :
	public TextButton
{
	ProgramSlotsWidget& programSlots;

	void pushSelectedProgramToHardware() {
		programSlots.pushSelectedProgramToHardware();
	}

public:
	ButtonForPushingSelectedProgramToHardware() = delete;

	ButtonForPushingSelectedProgramToHardware(ProgramSlotsWidget& programSlots) :
		TextButton("PUSH"),
		programSlots{ programSlots }
	{
		String tipString;
		tipString =  "Push the data in the selected program storage slot\n";
		tipString += "to the corresponding storage slot in the Mopho hardware.";
		setTooltip(tipString);
		onClick = [this] { pushSelectedProgramToHardware(); };
	}

	~ButtonForPushingSelectedProgramToHardware() {

	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPushingSelectedProgramToHardware)
};

