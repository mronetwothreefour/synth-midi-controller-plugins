#include "widget_master_ComboBoxForSelectingPatchChangesEnabled.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingPatchChangesEnabled::ComboBoxForSelectingPatchChangesEnabled(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToOffOnString::get() };
	choices.add(converter->convert(0));
	choices.add(converter->convert(1));
	addItemList(choices, 1);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
	auto paramValue{ masterOptions->patchChangesEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingPatchChangesEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "When set on, incoming MIDI program change messages\n";
		tooltipText += "will switch the hardware to the specified patch number.\n";
		tooltipText += "It is recommended that this option be set to on for\n";
		tooltipText += "this plugin to operate correctly. NOTE: Individual\n";
		tooltipText += "Master options are not immediately updated on the\n";
		tooltipText += "hardware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToOffOnString::get() };
		auto currentValue{ (uint8)roundToInt(getSelectedItemIndex()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void ComboBoxForSelectingPatchChangesEnabled::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_PatchChangesEnabled) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingPatchChangesEnabled::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingPatchChangesEnabled::~ComboBoxForSelectingPatchChangesEnabled() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
