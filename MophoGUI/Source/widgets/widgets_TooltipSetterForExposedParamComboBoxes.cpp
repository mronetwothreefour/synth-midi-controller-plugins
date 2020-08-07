#include "widgets_TooltipSetterForExposedParamComboBoxes.h"



TooltipSetterForExposedParamComboBoxes::TooltipSetterForExposedParamComboBoxes(ComboBox& comboBox, uint8 param) :
	comboBox{ comboBox },
	param{ param },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	comboBox.addListener(this);
}

TooltipSetterForExposedParamComboBoxes::~TooltipSetterForExposedParamComboBoxes() {
	comboBox.removeListener(this);
}

void TooltipSetterForExposedParamComboBoxes::comboBoxChanged(ComboBox* comboBoxThatHasChanged) {
	if (comboBoxThatHasChanged == &comboBox)
		setTooltip();
}

void TooltipSetterForExposedParamComboBoxes::setTooltip() noexcept {
	auto tooltipText{ generateTooltipText() };
	comboBox.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamComboBoxes::generateTooltipText() noexcept {
	String tooltipText{ "" };
	auto& tooltips{ TooltipOptions::get() };
	auto& info{ InfoForExposedParameters::get() };
	if (tooltips.shouldShowDescription())
		tooltipText += info.descriptionFor(param) + "\n";
	if (tooltips.shouldShowCurrentValue()) {
		auto selectedItem{ (uint8)comboBox.getSelectedItemIndex() };
		tooltipText += ("Current Setting: " + converter->verboseConvert(selectedItem));
	}
	return tooltipText;
}
