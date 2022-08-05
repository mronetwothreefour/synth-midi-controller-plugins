#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"



class BaseSliderForSettingControllerNumber :
	public RotarySliderWithMouseWheelMod,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	const Identifier& propertyID;

public:
	BaseSliderForSettingControllerNumber() = delete;

	BaseSliderForSettingControllerNumber(UnexposedParameters* unexposedParams, const Identifier& propertyID);
	virtual String generateTooltipString() = 0;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~BaseSliderForSettingControllerNumber() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseSliderForSettingControllerNumber)
};

