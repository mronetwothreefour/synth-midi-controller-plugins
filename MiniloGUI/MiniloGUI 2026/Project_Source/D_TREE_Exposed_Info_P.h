#pragma once

#include <JuceHeader.h>

#include "D_TREE_Exposed_Info_G.h"

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_G
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const int cc_num_for(const Exp_Param id) const;
public: const int bit_count_for(const Exp_Param id) const;
public: const int byte_index_for_param_bit(const Exp_Param id, const int bit_index) const;
public: const int bit_index_for_param_bit(const Exp_Param id, const int bit_index) const;
public: const String choice_for_voice_mode(const Voice_Mode mode, const int choice_num, bool curt = false) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};