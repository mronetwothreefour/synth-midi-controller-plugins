#include "widget_splits_SliderForSettingZoneVolumeBalance.h"

#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



SliderForSettingZoneVolumeBalance::SliderForSettingZoneVolumeBalance(UnexposedParameters* unexposedParams) :
	LinearSliderWithMouseWheelMod{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);
	setRange(0.0, 62.0, 1.0);
	auto paramValue{ splitOptions->zoneVolumeBalance() };
	setValue((double)paramValue, dontSendNotification);
	setDoubleClickReturnValue(true, 31.0);
	setMouseDragSensitivity(111);
	setTooltip(generateTooltipString());
}

String SliderForSettingZoneVolumeBalance::generateTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the loudness of the lower and upper zones\n";
		tooltipText += "relative to one another. Range: -31 to +31.\n";
		tooltipText += "At 0, the zones have equal loudness. At -31,\n";
		tooltipText += "the lower zone is at full volume and the upper\n";
		tooltipText += "zone is barely heard. At +31, the reverse is true.\n";
		tooltipText += "NOTE: Changes made to split parameters are not\n";
		tooltipText += "sent to the hardware until you SAVE the split in\n";
		tooltipText += "one of the storage bank slots below.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto converter{ IntToSigned6bitValueString::get() };
		auto currentValue{ (uint8)roundToInt(getValue()) };
		tooltipText += "Current setting: ";
		tooltipText += converter->verboseConvert(currentValue);
	}
	return tooltipText;
}

void SliderForSettingZoneVolumeBalance::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::split_ZoneVolumeBalance) {
		MessageManagerLock mmLock;
		setValue((double)tree.getProperty(property), sendNotification);
		setTooltip(generateTooltipString());
	}
}

SliderForSettingZoneVolumeBalance::~SliderForSettingZoneVolumeBalance() {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
