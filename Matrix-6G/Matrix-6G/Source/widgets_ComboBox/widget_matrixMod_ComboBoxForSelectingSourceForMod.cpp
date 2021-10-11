#include "widget_matrixMod_ComboBoxForSelectingSourceForMod.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingSourceForMatrixMod::ComboBoxForSelectingSourceForMatrixMod(UnexposedParameters* unexposedParams, int modNumber) :
	unexposedParams{ unexposedParams },
	parameterID{ "matrixMod_SourceForMod_" + (String)modNumber }
{
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToModSourceString::get() };
	for (uint8 i = 0; i != 21; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	auto paramValue{ matrixModSettings->sourceSettingForModulation(modNumber) };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSourceForMatrixMod::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the modulation source. Matrix Mod parameters\n";
		tooltipText += "cannot be changed via Quick Patch Edit. Use the\n";
		tooltipText += "PUSH button to send the entire patch instead.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToModSourceString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingSourceForMatrixMod::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingSourceForMatrixMod::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToModSourceString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingSourceForMatrixMod::~ComboBoxForSelectingSourceForMatrixMod() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->removeListener(this);
}
