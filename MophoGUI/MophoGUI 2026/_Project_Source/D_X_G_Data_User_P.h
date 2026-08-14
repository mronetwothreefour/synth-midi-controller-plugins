#pragma once

#include "D_X_G_Data_User_A.h"

class Data_User :
	public Data_User_A
{

//==============================================================================
public: explicit Data_User(Data_Hub* hub);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User)
};
