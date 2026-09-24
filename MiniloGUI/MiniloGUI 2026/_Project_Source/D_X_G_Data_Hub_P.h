#pragma once

#include "D_TREE_Aux_Voice_Params_P.h"
#include "D_X_G_Data_Hub_A.h"

using namespace TREE;

class Data_Hub :
	public Data_Hub_A
{
private: Aux_Voice_Params aux_voice_params;

//==============================================================================
public: explicit Data_Hub(AudioProcessor* processor);

public: Aux_Voice_Params& get_aux_voice_params();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub)
};