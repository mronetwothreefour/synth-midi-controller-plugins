#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class RandomizeButton_MatrixModParam :
	public TextButton
{
	ParamRandomizationMethods* randomize;

public:
	RandomizeButton_MatrixModParam() = delete;

	RandomizeButton_MatrixModParam(int modNum, MM_Type paramType, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
		randomize{ exposedParams->randomize.get() }
	{
		setComponentID(ID::btn_Randomize.toString());
		onClick = [this, modNum, paramType] { randomize->randomizeMatrixModParameter(modNum, paramType); };
		addShortcut(KeyPress{ 'd', ModifierKeys::ctrlModifier, 0 });
		if (tooltips->shouldShowDescription()) {
			auto paramName{ "Modulator " + (String)modNum };
			paramName += paramType == MM_Type::source ? " Source" : paramType == MM_Type::amount ? " Amount" : " Destination";
			setTooltip("Click to generate a random setting\nfor " + paramName + ".\nShortcut key: CTRL+D");
		}
		setSize(GUI::btn_Randomize_w, GUI::buttons_small_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizeButton_MatrixModParam)
};