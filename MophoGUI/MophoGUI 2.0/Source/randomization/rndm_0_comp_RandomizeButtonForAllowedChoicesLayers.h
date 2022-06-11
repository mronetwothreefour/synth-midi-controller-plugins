#pragma once

#include <JuceHeader.h>

#include "rndm_0_ParamRandomizationMethods.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ExposedParameters = AudioProcessorValueTreeState;
using Info = InfoForExposedParameters;



class RandomizeButtonForAllowedChoicesLayers :
	public TextButton
{
public:
	RandomizeButtonForAllowedChoicesLayers() = delete;

	RandomizeButtonForAllowedChoicesLayers(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams)
	{
		setComponentID(ID::button_Randomize.toString());
		onClick = [paramIndex, exposedParams, unexposedParams] {
			auto paramID{ Info::get().IDfor(paramIndex).toString()};
			ParamRandomizationMethods randomizeMethods{ exposedParams, unexposedParams };
			randomizeMethods.randomizeParameter(paramID);
		};
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescriptions()) {
			auto paramName{ Info::get().exposedNameFor(paramIndex) };
			setTooltip("Click to generate a random setting\nfor " + paramName + ".");
			setSize(GUI::button_Randomize_w, GUI::redButton_h);
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoicesLayers)
};