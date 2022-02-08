#include "gui_Layer_MatrixMod.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



MatrixModLayer::MatrixModLayer(UnexposedParameters* unexposedParams) :
	matrixModSlot_0{ unexposedParams, 0 },
	matrixModSlot_1{ unexposedParams, 1 },
	matrixModSlot_2{ unexposedParams, 2 },
	matrixModSlot_3{ unexposedParams, 3 },
	matrixModSlot_4{ unexposedParams, 4 },
	matrixModSlot_5{ unexposedParams, 5 },
	matrixModSlot_6{ unexposedParams, 6 },
	matrixModSlot_7{ unexposedParams, 7 },
	matrixModSlot_8{ unexposedParams, 8 },
	matrixModSlot_9{ unexposedParams, 9 }
{
	setInterceptsMouseClicks(false, true);
	addAndMakeVisible(matrixModSlot_0);
	addAndMakeVisible(matrixModSlot_1);
	addAndMakeVisible(matrixModSlot_2);
	addAndMakeVisible(matrixModSlot_3);
	addAndMakeVisible(matrixModSlot_4);
	addAndMakeVisible(matrixModSlot_5);
	addAndMakeVisible(matrixModSlot_6);
	addAndMakeVisible(matrixModSlot_7);
	addAndMakeVisible(matrixModSlot_8);
	addAndMakeVisible(matrixModSlot_9);
	setSize(GUI::editor_w, GUI::editor_h);
}

void MatrixModLayer::resized() {
	matrixModSlot_0.setBounds(GUI::bounds_MatrixModSlot_0);
	matrixModSlot_1.setBounds(GUI::bounds_MatrixModSlot_1);
	matrixModSlot_2.setBounds(GUI::bounds_MatrixModSlot_2);
	matrixModSlot_3.setBounds(GUI::bounds_MatrixModSlot_3);
	matrixModSlot_4.setBounds(GUI::bounds_MatrixModSlot_4);
	matrixModSlot_5.setBounds(GUI::bounds_MatrixModSlot_5);
	matrixModSlot_6.setBounds(GUI::bounds_MatrixModSlot_6);
	matrixModSlot_7.setBounds(GUI::bounds_MatrixModSlot_7);
	matrixModSlot_8.setBounds(GUI::bounds_MatrixModSlot_8);
	matrixModSlot_9.setBounds(GUI::bounds_MatrixModSlot_9);
}
