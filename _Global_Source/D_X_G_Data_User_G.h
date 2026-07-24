#pragma once

#include "D_X_G_Data_Hub_P.h"

class Data_User_G
{
protected: Data_Hub_P* hub;
protected: const Tree_Exposed_Info_P& exp_info;
protected: UndoManager* u_m;
protected: AudioProcessorValueTreeState* exp_state;
protected: float& scale_factor;

//==============================================================================
public: explicit Data_User_G(Data_Hub_P* hub);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_G)
};