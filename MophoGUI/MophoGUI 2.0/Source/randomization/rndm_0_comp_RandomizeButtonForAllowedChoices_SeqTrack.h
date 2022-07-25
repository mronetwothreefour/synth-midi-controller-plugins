#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_func_ExposedParamsRandomizationMethods.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Track = SeqTrackNum;

class RandomizeButtonForAllowedChoices_SeqTrack :
	public TextButton
{
public:
	RandomizeButtonForAllowedChoices_SeqTrack() = delete;

	RandomizeButtonForAllowedChoices_SeqTrack(Track track, ExposedParamsRandomizationMethods* randomize, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::btn_Randomize.toString());
		onClick = [track, randomize] { randomize->randomizeSeqTrack(track); };
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescription())
			setTooltip("Click to generate a random setting\nfor the target step in track " + String((int)track) + ".");
		setSize(GUI::btn_Randomize_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoices_SeqTrack)
};