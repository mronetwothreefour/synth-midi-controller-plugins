#pragma once

#include <JuceHeader.h>

#include "banks_ProgramSlotsWidget.h"



class ButtonForPullingSelectedProgramFromHardware :
	public TextButton
{
	ProgramSlotsWidget& programSlots;

	void pullSelectedProgramFromHardware() {
		programSlots.pullSelectedProgramFromHardware();
	}

public:
	ButtonForPullingSelectedProgramFromHardware() = delete;

	ButtonForPullingSelectedProgramFromHardware(ProgramSlotsWidget& programSlots) :
		TextButton("PULL"),
		programSlots{ programSlots }
	{
		String tipString;
		tipString =  "Pull the data from the selected program storage slot in the Mopho hardware\n";
		tipString += "and save it in the corresponding storage slot in the plugin.";
		setTooltip(tipString);
		onClick = [this] { pullSelectedProgramFromHardware(); };
	}

	~ButtonForPullingSelectedProgramFromHardware() {

	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForPullingSelectedProgramFromHardware)
};

