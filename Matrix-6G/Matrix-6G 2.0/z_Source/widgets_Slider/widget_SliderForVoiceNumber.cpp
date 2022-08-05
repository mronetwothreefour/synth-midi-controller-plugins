#include "widget_SliderForVoiceNumber.h"

#include "../guiRenderers/guiRenderer_ControlValue.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForVoiceNumber::SliderForVoiceNumber(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::currentVoice_Number }
{
	auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
	currentVoiceOptions->addListener(this);
	setRange(0.0, 99.0, 1.0);
	auto paramValue{ currentVoiceOptions->currentVoiceNumber() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 0.0);
	setMouseDragSensitivity(160);
}

void SliderForVoiceNumber::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
	}
}

void SliderForVoiceNumber::paint(Graphics& g) {
	auto currentValue{ (uint8)roundToInt(getValue()) };
	auto converter{ IntToUnsignedValueWithLeadingZeroString::get() };
	String valueString{ converter->convert(currentValue) };
	ControlValueRenderer::paintValueStringInComponent(g, valueString, this);
}

SliderForVoiceNumber::~SliderForVoiceNumber() {
	auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
	currentVoiceOptions->removeListener(this);
}
