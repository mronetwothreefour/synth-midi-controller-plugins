#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_G.h"

class Data_User_P :
	public Data_User_G
{
//protected: Tree_Aux_Voice_P& avp;

//==============================================================================
public: explicit Data_User_P(Data_Hub_P* hub) :
	Data_User_G{ hub }/*,
	avp{ hub->get_additional_voice_params() }*/
{}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_P)
};
