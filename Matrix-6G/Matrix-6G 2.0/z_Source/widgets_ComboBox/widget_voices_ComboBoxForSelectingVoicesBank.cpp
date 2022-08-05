#include "widget_voices_ComboBoxForSelectingVoicesBank.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



ComboBoxForSelectingVoicesBank::ComboBoxForSelectingVoicesBank(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	setColour(ComboBox::ColourIds::textColourId, Colours::transparentBlack);

	StringArray choices;
	auto converter{ IntToVoicesBankName::get() };
	for (uint8 i = 0; i != 13; ++i)
		choices.add(converter->convert(i));
	addItemList(choices, 1);
	setSelectedItemIndex(0, dontSendNotification);

	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects which bank of stored patches to work with.\n";
		tooltipText += "Only patches in the Custom A & B banks can be overwritten.";
	}
	setTooltip(tooltipText);
}

void ComboBoxForSelectingVoicesBank::paint(Graphics& g) {
	auto currentValue{ (uint8)getSelectedItemIndex() };
	auto converter{ IntToVoicesBankName::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}
