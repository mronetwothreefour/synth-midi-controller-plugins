#include "widget_BaseSliderForSettingControllerNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



BaseSliderForSettingControllerNumber::BaseSliderForSettingControllerNumber(UnexposedParameters* unexposedParams, const Identifier& propertyID) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	propertyID{ propertyID }
{
	jassert(propertyID == ID::master_Lever2ControllerNumber ||
			propertyID == ID::master_Lever3ControllerNumber ||
			propertyID == ID::master_Pedal1ControllerNumber ||
			propertyID == ID::master_Pedal2ControllerNumber
	);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 121.0, 1.0);
	setMouseDragSensitivity(140);
}

void BaseSliderForSettingControllerNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == propertyID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

void BaseSliderForSettingControllerNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

BaseSliderForSettingControllerNumber::~BaseSliderForSettingControllerNumber() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
