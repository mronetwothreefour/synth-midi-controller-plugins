#pragma once

#include <JuceHeader.h>

#include "G_LOOK_AND_FEEL_B.h"

class Look_And_Feel_P :
	public Look_And_Feel_B
{
//==============================================================================
public: explicit Look_And_Feel_P(float& scale_factor);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel_P)
};
