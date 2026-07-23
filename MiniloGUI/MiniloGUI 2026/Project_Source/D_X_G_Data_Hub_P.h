#pragma once

#include "D_TREE_Aux_Voice_P.h"
#include "D_X_G_Data_Hub_G.h"

class Data_Hub_P :
	public Data_Hub_G
{
private: Tree_Aux_Voice_P aux_voice_params;

//==============================================================================
public: explicit Data_Hub_P(AudioProcessor* processor);

public: Tree_Aux_Voice_P& get_aux_voice_params();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub_P)

};