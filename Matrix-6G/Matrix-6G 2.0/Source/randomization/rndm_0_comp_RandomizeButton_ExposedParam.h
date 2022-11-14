#pragma once

#include <JuceHeader.h>

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

class RandomizeButton_ExposedParam :
	public TextButton
{
	ParamRandomizationMethods* randomize;

public:
	RandomizeButton_ExposedParam() = delete;

	RandomizeButton_ExposedParam(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
		randomize{ exposedParams->randomize.get() }
	{
		setComponentID(ID::btn_Randomize.toString());
		onClick = [this, paramIndex] { randomize->randomizeExposedParameter(paramIndex); };
		addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
		auto tooltips{ unexposedParams->getTooltipsOptions() };
		if (tooltips->shouldShowDescription()) {
			auto paramName{ exposedParams->info->exposedNameFor(paramIndex) };
			setTooltip("Click to generate a random setting\nfor " + paramName + ".\nShortcut key: CTRL+D");
		}
		setSize(GUI::btn_Randomize_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButton_ExposedParam)
};