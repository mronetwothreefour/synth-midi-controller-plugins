#include "tooltipSetter_ForExposedParamComboBoxes.h"

#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



TooltipSetterForExposedParamComboBoxes::TooltipSetterForExposedParamComboBoxes(ComboBox& comboBox, uint16 param, UnexposedParameters* unexposedParams) :
	TooltipSetter{ unexposedParams },
	comboBox{ comboBox },
	param{ param },
	unexposedParams{ unexposedParams },
	converter{ InfoForExposedParameters::get().converterFor(param) }
{
	comboBox.addListener(this);
}

void TooltipSetterForExposedParamComboBoxes::comboBoxChanged(ComboBox* comboBoxThatHasChanged) {
	if (comboBoxThatHasChanged == &comboBox)
		setTooltip();
}

void TooltipSetterForExposedParamComboBoxes::setTooltip() {
	auto tooltipText{ generateTooltipText() };
	comboBox.setTooltip(tooltipText);
}

String TooltipSetterForExposedParamComboBoxes::generateTooltipText() {
	String tooltipText{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	auto& info{ InfoForExposedParameters::get() };
	if (tooltips->shouldShowDescription())
		tooltipText += info.descriptionFor(param) + "\n";
	if (tooltips->shouldShowCurrentValue()) {
		auto selectedItem{ (uint8)comboBox.getSelectedItemIndex() };
		tooltipText += ("Current Setting: " + converter->verboseConvert(selectedItem));
	}
	return tooltipText;
}

TooltipSetterForExposedParamComboBoxes::~TooltipSetterForExposedParamComboBoxes() {
	comboBox.removeListener(this);
}
