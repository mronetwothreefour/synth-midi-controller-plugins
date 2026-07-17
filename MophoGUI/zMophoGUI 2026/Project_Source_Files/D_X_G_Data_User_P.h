#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_B.h"

class Data_User_P :
	public Data_User_B
{
	
//==============================================================================
public: explicit Data_User_P(Data_Hub_P* hub) :
	Data_User_B{ hub }
{}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_P)
};
