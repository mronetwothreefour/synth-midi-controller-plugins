#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class UnexposedParameters;

class ToggleForTooltipParam :
	public ToggleButton,
	public ValueTree::Listener
{
	GlobalParamToggleType toggleType;
	UnexposedParameters* unexposedParams;

public:
	ToggleForTooltipParam() = delete;

	ToggleForTooltipParam(GlobalParamToggleType toggleType, UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ToggleForTooltipParam();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleForTooltipParam)
};