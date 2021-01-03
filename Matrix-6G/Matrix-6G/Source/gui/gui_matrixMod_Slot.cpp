#include "gui_matrixMod_Slot.h"

#include "gui_Constants.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



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
	setSize(GUI::matrixModSlots_w, GUI::matrixModSlotControls_h);
}

void MatrixModSlot::resized() {
	comboBox_ForSelectingSourceForMatrixMod.setBounds(GUI::bounds_MatrixModSlotComboBoxForSource);
	slider_ForSettingAmountForMatrixMod.setBounds(GUI::bounds_MatrixModSlotSliderForAmount);
	comboBox_ForSelectingDestinationForMatrixMod.setBounds(GUI::bounds_MatrixModSlotComboBoxForDestination);
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

