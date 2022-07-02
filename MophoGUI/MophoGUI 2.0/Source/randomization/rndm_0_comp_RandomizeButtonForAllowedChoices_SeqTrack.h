#pragma once

#include <JuceHeader.h>

#include "rndm_0_ParamRandomizationMethods.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Track = SeqTrackNum;



class RandomizeButtonForAllowedChoices_SeqTrack :
	public TextButton
{
public:
	RandomizeButtonForAllowedChoices_SeqTrack() = delete;

	RandomizeButtonForAllowedChoices_SeqTrack(Track track, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Randomize.toString());
		onClick = [track, randomize] { randomize->randomizeSeqTrack(track); };
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescriptions())
			setTooltip("Click to generate a random setting\nfor the target step in track " + String((int)track) + ".");
		setSize(GUI::button_Randomize_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoices_SeqTrack)
};