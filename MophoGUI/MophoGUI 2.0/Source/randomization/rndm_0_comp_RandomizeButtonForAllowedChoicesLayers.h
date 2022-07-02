#pragma once

#include <JuceHeader.h>

#include "rndm_0_ParamRandomizationMethods.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



class InfoForExposedParameters;

class RandomizeButtonForAllowedChoicesLayers :
	public TextButton
{
public:
	RandomizeButtonForAllowedChoicesLayers() = delete;

	RandomizeButtonForAllowedChoicesLayers(uint8 paramIndex, ParamRandomizationMethods* randomize, UnexposedParameters* unexposedParams)
	{
		auto info{ unexposedParams->getInfoForExposedParameters() };
		setComponentID(ID::button_Randomize.toString());
		onClick = [paramIndex, info, randomize] {
			auto paramID{ info->IDfor(paramIndex).toString()};
			randomize->randomizeParameter(paramID);
		};
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescriptions()) {
			auto paramName{ info->exposedNameFor(paramIndex) };
			setTooltip("Click to generate a random setting\nfor " + paramName + ".");
		}
		setSize(GUI::button_Randomize_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoicesLayers)
};