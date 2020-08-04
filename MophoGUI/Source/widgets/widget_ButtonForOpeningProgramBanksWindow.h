#pragma once

#include <JuceHeader.h>



class ButtonForOpeningProgramBanksWindow :
	public TextButton
{

public:
	ButtonForOpeningProgramBanksWindow() :
		TextButton{ "BANKS" }
	{
		String tipString;
		tipString =  "Opens a window where you can manage the\n";
		tipString += "three storage banks for program presets.";
		setTooltip(tipString);
	}

	~ButtonForOpeningProgramBanksWindow() {
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForOpeningProgramBanksWindow)
};
