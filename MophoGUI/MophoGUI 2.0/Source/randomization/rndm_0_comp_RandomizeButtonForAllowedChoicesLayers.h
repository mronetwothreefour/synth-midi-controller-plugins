#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



class InfoForExposedParameters;

class RandomizeButtonForAllowedChoicesLayers :
	public TextButton
{
public:
	RandomizeButtonForAllowedChoicesLayers() = delete;

	RandomizeButtonForAllowedChoicesLayers(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Randomize.toString());
		onClick = [paramIndex, exposedParams] {
			auto paramID{ exposedParams->info->IDfor(paramIndex).toString()};
			exposedParams->randomize->randomizeParameter(paramID);
		};
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescriptions()) {
			auto paramName{ exposedParams->info->exposedNameFor(paramIndex) };
			setTooltip("Click to generate a random setting\nfor " + paramName + ".");
		}
		setSize(GUI::button_Randomize_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoicesLayers)
};