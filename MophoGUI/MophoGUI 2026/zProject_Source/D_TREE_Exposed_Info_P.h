#pragma once

#include "D_TREE_Exposed_Info_G.h"

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_G
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const int nrpn_for(const Exp_Param id) const;
public: Point<int> red_toggle_center_for(const Exp_Param id) const;
public: const int packed_bits_byte_index_for(const Exp_Param id) const;
public: const int packed_bits_mask_for(const Exp_Param id) const;
public: const int byte_index_for(const Exp_Param id) const;
public: Layout build_param_layout() const override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};