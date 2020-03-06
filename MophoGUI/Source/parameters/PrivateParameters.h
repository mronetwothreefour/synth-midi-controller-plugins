#pragma once

#include <JuceHeader.h>

// Contains a ValueTree in which plugin parameters that are not 
// exposed to the host are stored, as well as tools for 
// accessing and manipulating the stored data.
class PrivateParameters
{
public:

private:
	ValueTree privateParamsTree;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PrivateParameters)
};