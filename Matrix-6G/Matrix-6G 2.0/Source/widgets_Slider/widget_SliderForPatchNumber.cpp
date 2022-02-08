#include "widget_SliderForPatchNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForPatchNumber::SliderForPatchNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::currentPatch_Number }
{
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	currentPatchOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ currentPatchOptions->currentPatchNumber() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
}

void SliderForPatchNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
	}
}

void SliderForPatchNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueWithLeadingZeroString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForPatchNumber::~SliderForPatchNumber() {
	auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
	currentPatchOptions->removeListener(this);
}
