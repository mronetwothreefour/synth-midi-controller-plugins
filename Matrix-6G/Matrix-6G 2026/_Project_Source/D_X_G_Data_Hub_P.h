#pragma once

#include "D_X_G_Data_Hub_A.h"
#include "D_TREE_Matrix_Mod_Params_P.h"

using namespace TREE;

class Data_Hub :
	public Data_Hub_A
{
private: Matrix_Mod_Params matrix_mod_params;

//==============================================================================
public: explicit Data_Hub(AudioProcessor* processor);

public: Matrix_Mod_Params& get_matrix_mod_params();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_Hub)
};