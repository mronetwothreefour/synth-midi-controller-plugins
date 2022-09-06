#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

class UnexposedParameters;

class ToggleForTooltipParameter :
	public Component,
	public Value::Listener
{
	GlobalParamToggleType toggleType;
	ToggleButton redToggle;
	Value shouldShowDescriptionAsValue;

public:
	ToggleForTooltipParameter() = delete;

	ToggleForTooltipParameter(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void mouseDown(const MouseEvent& event) override;
	void valueChanged(Value& value) override;
	~ToggleForTooltipParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleForTooltipParameter)
};