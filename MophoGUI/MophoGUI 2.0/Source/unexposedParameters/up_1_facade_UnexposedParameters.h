#pragma once

#include <JuceHeader.h>

#include "up_0_tree_TooltipsOptions.h"

class UnexposedParameters
{
	std::unique_ptr<TooltipsOptions> tooltipsOptions;

public:
	UnexposedParameters();
	TooltipsOptions* getTooltipsOptions();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};