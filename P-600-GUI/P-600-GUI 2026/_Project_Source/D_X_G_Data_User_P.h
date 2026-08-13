#pragma once

#include "D_X_G_Data_User_A.h"

class Data_User_P :
	public Data_User_A
{

//==============================================================================
public: explicit Data_User_P(Data_Hub_P* hub);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_P)
};
