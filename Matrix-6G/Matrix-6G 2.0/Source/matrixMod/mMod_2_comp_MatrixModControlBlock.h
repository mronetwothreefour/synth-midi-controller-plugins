#pragma once

#include <JuceHeader.h>

#include "mMod_1_comp_ComboBoxForMatrixModDestination.h"
#include "mMod_1_comp_ComboBoxForMatrixModSource.h"
#include "mMod_1_comp_SliderForMatrixModAmount.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

class TooltipsOptions;

using namespace Matrix_6G_Constants;

class MatrixModControlBlock :
	public Component
{
	ComboBoxForMatrixModSource comboBox_ModSource;
	SliderForMatrixModAmount slider_ModAmount;
	ComboBoxForMatrixModDestination comboBox_ModDest;

public:
	MatrixModControlBlock() = delete;

	MatrixModControlBlock(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
		comboBox_ModSource{ modNum, exposedParams->matrixModOptions.get() , tooltips },
		slider_ModAmount{ modNum, exposedParams, tooltips },
		comboBox_ModDest{ modNum, exposedParams->matrixModOptions.get() , tooltips }
	{
		comboBox_ModSource.setTopLeftPosition(0, 0);
		addAndMakeVisible(comboBox_ModSource);

		slider_ModAmount.setTopLeftPosition(88, 0);
		addAndMakeVisible(slider_ModAmount);

		comboBox_ModDest.setTopLeftPosition(134, 0);
		addAndMakeVisible(comboBox_ModDest);

		setSize(216, GUI::control_h);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModControlBlock)
};