#pragma once

#include "D_TREE_Exposed_Info_G.h"

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_G
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const int number_for(const Exp_Param id) const;
public: const int byte_index_for(const Exp_Param id) const;
public: const Range_Type range_type_for(const Exp_Param id) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};