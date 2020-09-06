#include "widget_global_KnobForGlobalMidiChannel.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



KnobForGlobalMidiChannel::KnobForGlobalMidiChannel(UnexposedParameters* unexposedParams) :
	RotarySliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams },
	parameterID{ ID::midi_HardwareReceiveChannel }
{
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	setRange(0.0, 16.0, 1.0);
	auto paramValue{ midiOptions->hardwareReceiveChannel() };
	setValue((double)paramValue, dontSendNotification);
	setTooltip(generateTooltipString());
}

String KnobForGlobalMidiChannel::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects the channel on which the hardware\n";
		tooltipText += "sends and receives MIDI data. When set to\n";
		tooltipText += "All Channels, the hardware receives MIDI data\n";
		tooltipText += "on all channels and transmits on Channel 1.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToGlobalMidiChannelString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void KnobForGlobalMidiChannel::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == parameterID) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), dontSendNotification);
		setTooltip(generateTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		setTooltip(generateTooltipString());
	}
}

KnobForGlobalMidiChannel::~KnobForGlobalMidiChannel() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	auto midiOptions{ unexposedParams->midiOptions_get() };
	midiOptions->removeListener(this);
}
