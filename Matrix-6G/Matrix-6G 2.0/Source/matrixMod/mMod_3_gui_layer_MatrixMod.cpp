#include "mMod_3_gui_layer_MatrixMod.h"

#include "../constants/constants_GUI_Dimensions.h"

using namespace Matrix_6G_Constants;

GUI_Layer_MatrixMod::GUI_Layer_MatrixMod(ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	matrixModBlock_0{ 0, exposedParams, tooltips },
	matrixModBlock_1{ 1, exposedParams, tooltips },
	matrixModBlock_2{ 2, exposedParams, tooltips },
	matrixModBlock_3{ 3, exposedParams, tooltips },
	matrixModBlock_4{ 4, exposedParams, tooltips },
	matrixModBlock_5{ 5, exposedParams, tooltips },
	matrixModBlock_6{ 6, exposedParams, tooltips },
	matrixModBlock_7{ 7, exposedParams, tooltips },
	matrixModBlock_8{ 8, exposedParams, tooltips },
	matrixModBlock_9{ 9, exposedParams, tooltips }
{
	setInterceptsMouseClicks(false, true);

	matrixModBlock_0.setTopLeftPosition(1016, 59);
	matrixModBlock_1.setTopLeftPosition(1016, 59 + GUI::vertDistBtwnRows);
	matrixModBlock_2.setTopLeftPosition(1016, 59 + 2 * GUI::vertDistBtwnRows);
	matrixModBlock_3.setTopLeftPosition(1016, 59 + 3 * GUI::vertDistBtwnRows);
	matrixModBlock_4.setTopLeftPosition(1016, 59 + 4 * GUI::vertDistBtwnRows);
	matrixModBlock_5.setTopLeftPosition(1016, 59 + 5 * GUI::vertDistBtwnRows);
	matrixModBlock_6.setTopLeftPosition(1016, 59 + 6 * GUI::vertDistBtwnRows);
	matrixModBlock_7.setTopLeftPosition(1016, 59 + 7 * GUI::vertDistBtwnRows);
	matrixModBlock_8.setTopLeftPosition(1016, 59 + 8 * GUI::vertDistBtwnRows);
	matrixModBlock_9.setTopLeftPosition(1016, 59 + 9 * GUI::vertDistBtwnRows);

	addAndMakeVisible(matrixModBlock_0);
	addAndMakeVisible(matrixModBlock_1);
	addAndMakeVisible(matrixModBlock_2);
	addAndMakeVisible(matrixModBlock_3);
	addAndMakeVisible(matrixModBlock_4);
	addAndMakeVisible(matrixModBlock_5);
	addAndMakeVisible(matrixModBlock_6);
	addAndMakeVisible(matrixModBlock_7);
	addAndMakeVisible(matrixModBlock_8);
	addAndMakeVisible(matrixModBlock_9);

	setSize(GUI::editor_w, GUI::editor_h);
}
