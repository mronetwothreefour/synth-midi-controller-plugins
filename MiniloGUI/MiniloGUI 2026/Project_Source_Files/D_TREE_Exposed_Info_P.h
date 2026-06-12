#pragma once

#include <JuceHeader.h>

#include "c_XYWH_p.h"
#include "D_SUBTREE_Bit_Loc_Exp_P.h"
#include "D_SUBTREE_Choices_Exp_P.h"
#include "D_SUBTREE_Exposed_Info_P.h"
#include "D_TREE_Exposed_Info_B.h"

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_B
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const int cc_num_for(const int param_index) const;
public: const int bit_count_for(const int param_index) const;
public: const int byte_index_for_param_bit(const int param_index, const int bit_index) const;
public: const int bit_index_for_param_bit(const int param_index, const int bit_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};