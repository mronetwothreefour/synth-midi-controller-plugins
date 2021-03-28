#include "widget_master_ComboBoxForSelectingSpilloverEnabled.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingSpilloverEnabled::ComboBoxForSelectingSpilloverEnabled(UnexposedParameters* unexposedParams) :
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
	auto paramValue{ masterOptions->spilloverEnabled() };
	setSelectedItemIndex(paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String ComboBoxForSelectingSpilloverEnabled::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "This option is useful if you have two Matrix-6R units\n";
		tooltipText += "connected via MIDI. When on, the two units can behave\n";
		tooltipText += "as if they were a single unit with 12 voices. If you\n";
		tooltipText += "play more than 6 notes at once, the additional notes\n";
		tooltipText += "will be transmitted to the second unit on the Basic\n";
		tooltipText += "Channel + 2 (e.g. if the Basic Channel is 1, the surplus\n";
		tooltipText += "notes will spillover onto channel 3). NOTE: Individual\n";
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

void ComboBoxForSelectingSpilloverEnabled::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::master_SpilloverEnabled) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void ComboBoxForSelectingSpilloverEnabled::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

ComboBoxForSelectingSpilloverEnabled::~ComboBoxForSelectingSpilloverEnabled() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto masterOptions{ unexposedParams->masterOptions_get() };
	masterOptions->removeListener(this);
}
