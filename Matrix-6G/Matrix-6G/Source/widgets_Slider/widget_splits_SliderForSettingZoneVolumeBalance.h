#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class SliderForSettingZoneVolumeBalance :
	public LinearSliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	SliderForSettingZoneVolumeBalance() = delete;

	explicit SliderForSettingZoneVolumeBalance(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~SliderForSettingZoneVolumeBalance() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderForSettingZoneVolumeBalance)
};