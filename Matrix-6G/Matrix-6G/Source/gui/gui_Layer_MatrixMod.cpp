#include "gui_Layer_MatrixMod.h"

#include "../params/params_UnexposedParameters_Facade.h"



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
	setSize(1273, 626);
}

void MatrixModLayer::resized() {
	auto slot_x{ 1016 };
	auto firstSlot_y{ 59 };
	auto slot_w{ matrixModSlot_0.getWidth() };
	auto slot_h{ matrixModSlot_0.getHeight() };
	auto verticalSpacingBetweenSlots{ 28 };
	matrixModSlot_0.setBounds(slot_x, firstSlot_y, slot_w, slot_h);
	matrixModSlot_1.setBounds(slot_x, firstSlot_y + verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_2.setBounds(slot_x, firstSlot_y + 2 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_3.setBounds(slot_x, firstSlot_y + 3 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_4.setBounds(slot_x, firstSlot_y + 4 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_5.setBounds(slot_x, firstSlot_y + 5 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_6.setBounds(slot_x, firstSlot_y + 6 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_7.setBounds(slot_x, firstSlot_y + 7 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_8.setBounds(slot_x, firstSlot_y + 8 * verticalSpacingBetweenSlots, slot_w, slot_h);
	matrixModSlot_9.setBounds(slot_x, firstSlot_y + 9 * verticalSpacingBetweenSlots, slot_w, slot_h);
}
