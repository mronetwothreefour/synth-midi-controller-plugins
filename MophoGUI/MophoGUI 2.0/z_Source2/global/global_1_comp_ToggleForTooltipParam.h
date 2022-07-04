#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class TooltipsOptions;
class UnexposedParameters;

class ToggleForTooltipParameter :
	public ToggleButton,
	public ValueTree::Listener
{
	GlobalParamToggleType toggleType;
	TooltipsOptions* tooltips;

public:
	ToggleForTooltipParameter() = delete;

	ToggleForTooltipParameter(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleForTooltipParameter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleForTooltipParameter)
};