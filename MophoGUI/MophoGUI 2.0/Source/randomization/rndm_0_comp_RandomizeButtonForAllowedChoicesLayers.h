#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

class RandomizeButtonForAllowedChoicesLayers :
	public TextButton
{
	ExposedParamsRandomizationMethods* randomize;

public:
	RandomizeButtonForAllowedChoicesLayers() = delete;

	RandomizeButtonForAllowedChoicesLayers(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
		randomize{ exposedParams->randomize.get() }
	{
		setComponentID(ID::btn_Randomize.toString());
		onClick = [this, paramIndex] { randomize->randomizeParameter(paramIndex); };
		addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescription()) {
			auto paramName{ exposedParams->info->exposedNameFor(paramIndex) };
			setTooltip("Click to generate a random setting\nfor " + paramName + ".\nShortcut key: CTRL+D");
		}
		setSize(GUI::btn_Randomize_w, GUI::redButton_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButtonForAllowedChoicesLayers)
};