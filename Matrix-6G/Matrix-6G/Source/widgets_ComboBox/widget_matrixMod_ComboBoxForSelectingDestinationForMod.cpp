#include "widget_matrixMod_ComboBoxForSelectingDestinationForMod.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingDestinationForMatrixMod::ComboBoxForSelectingDestinationForMatrixMod(UnexposedParameters* unexposedParams, int modNumber) :
	unexposedParams{ unexposedParams },
	parameterID{ "matrixMod_DestinationForMod_" + (String)modNumber }
{
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToModDestinationString::get() };
	for (uint8 i = 0; i != 33; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);	
	auto paramValue{ matrixModSettings->destinationSettingForModulation(modNumber) };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingDestinationForMatrixMod::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the destination parameter for modulation.\n";
		tooltipText += "Matrix Mod settings cannot be changed via Quick Edit.\n";
		tooltipText += "Use the Push button (below the logo) to send the entire\n";
		tooltipText += "patch to the selected storage slot on the hardware.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToModDestinationString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingDestinationForMatrixMod::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingDestinationForMatrixMod::paint(Graphics& g) {
	auto currentValue{ (int8)roundToInt(getSelectedItemIndex()) };
	auto converter{ IntToModDestinationString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingDestinationForMatrixMod::~ComboBoxForSelectingDestinationForMatrixMod() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
	matrixModSettings->removeListener(this);
}
