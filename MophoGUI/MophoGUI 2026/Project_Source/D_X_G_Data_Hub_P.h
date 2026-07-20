#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_Hub_G.h"

class Data_Hub_P :
	public Data_Hub_G
{

//==============================================================================
public: explicit Data_Hub_P(AudioProcessor* processor);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_P)

};