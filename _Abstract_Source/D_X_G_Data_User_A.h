#pragma once

#include "D_X_G_Data_Hub_P.h"

using namespace TREE;

class Data_User_A
{
protected: Data_Hub* hub;
protected: App_Params& app_p;
protected: AudioProcessorValueTreeState* exp_state;
protected: UndoManager* u_m;

//==============================================================================
public: explicit Data_User_A(Data_Hub* hub);

public: const float scale_factor();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_A)
};