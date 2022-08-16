#pragma once

#include <JuceHeader.h>

#include "mMod_2_comp_MatrixModControlBlock.h"

class TooltipsOptions;
class ExposedParameters;

class GUI_Layer_MatrixMod :
	public Component
{
	MatrixModControlBlock matrixModBlock_0;
	MatrixModControlBlock matrixModBlock_1;
	MatrixModControlBlock matrixModBlock_2;
	MatrixModControlBlock matrixModBlock_3;
	MatrixModControlBlock matrixModBlock_4;
	MatrixModControlBlock matrixModBlock_5;
	MatrixModControlBlock matrixModBlock_6;
	MatrixModControlBlock matrixModBlock_7;
	MatrixModControlBlock matrixModBlock_8;
	MatrixModControlBlock matrixModBlock_9;

public:
	GUI_Layer_MatrixMod() = delete;

	GUI_Layer_MatrixMod(ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_MatrixMod)
};