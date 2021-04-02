#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



BaseComboBoxForOffOnValueTreeProperty::BaseComboBoxForOffOnValueTreeProperty(UnexposedParameters* unexposedParams, const Identifier& propertyID) :
	unexposedParams{ unexposedParams },
	propertyID{ propertyID }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	StringArray choices;
	auto converter{ IntToOffOnString::get() };
	choices.add(converter->convert(0));
	choices.add(converter->convert(1));
	addItemList(choices, 1);
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);
}

void BaseComboBoxForOffOnValueTreeProperty::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == propertyID) {
		MessageManagerLock mmLock;
		setSelectedItemIndex((int)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void BaseComboBoxForOffOnValueTreeProperty::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToOffOnString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

BaseComboBoxForOffOnValueTreeProperty::~BaseComboBoxForOffOnValueTreeProperty() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
