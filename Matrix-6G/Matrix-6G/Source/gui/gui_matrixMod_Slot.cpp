#include "gui_matrixMod_Slot.h"

#include "../params/params_UnexposedParameters_Facade.h"



MatrixModSlot::MatrixModSlot(UnexposedParameters* unexposedParams, int modNumber) :
	unexposedParams{ unexposedParams },
	modNumber{ modNumber },
	comboBox_ForSelectingDestinationForMatrixMod{ unexposedParams, modNumber },
	comboBox_ForSelectingSourceForMatrixMod{ unexposedParams, modNumber },
	slider_ForSettingAmountForMatrixMod{ unexposedParams, modNumber }
{
	comboBox_ForSelectingSourceForMatrixMod.addListener(this);
	slider_ForSettingAmountForMatrixMod.addListener(this);
	comboBox_ForSelectingDestinationForMatrixMod.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSourceForMatrixMod);
	addAndMakeVisible(slider_ForSettingAmountForMatrixMod);
	addAndMakeVisible(comboBox_ForSelectingDestinationForMatrixMod);

	setSize(216, 20);
}

void MatrixModSlot::resized() {
	auto comboBox_w{ 82 };
	auto controls_y{ 0 };
	auto controls_h{ 20 };
	comboBox_ForSelectingSourceForMatrixMod.setBounds(0, controls_y, comboBox_w, controls_h);
	slider_ForSettingAmountForMatrixMod.setBounds(88, controls_y, 40, controls_h);
	comboBox_ForSelectingDestinationForMatrixMod.setBounds(134, controls_y, comboBox_w, controls_h);
}

void MatrixModSlot::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox == &comboBox_ForSelectingSourceForMatrixMod) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
		matrixModSettings->setSourceForModulation(currentSelection, modNumber);
	}
	if (comboBox == &comboBox_ForSelectingDestinationForMatrixMod) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
		matrixModSettings->setDestinationForModulation(currentSelection, modNumber);
	}
}

void MatrixModSlot::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForSettingAmountForMatrixMod) {
		auto currentValue{ (uint8)roundToInt(slider->getValue()) };
		auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
		matrixModSettings->setAmountForModulation(currentValue, modNumber);
	}
}

MatrixModSlot::~MatrixModSlot() {
	comboBox_ForSelectingSourceForMatrixMod.removeListener(this);
	slider_ForSettingAmountForMatrixMod.removeListener(this);
	comboBox_ForSelectingDestinationForMatrixMod.removeListener(this);
}

