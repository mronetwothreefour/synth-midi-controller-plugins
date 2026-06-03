#pragma once

#include "C_EXP_P.h"
#include "C_XYWH_P.h"
#include "D_SUBTREE_Choices_Exp_P.h"
#include "D_SUBTREE_Exposed_Info_P.h"
#include "D_TREE_Exposed_Info_B.h"

class Tree_Exposed_Info_P :
	public Tree_Exposed_Info_B
{
//==============================================================================
public: Tree_Exposed_Info_P();

public: const int number_for(int param_index) const;
public: const int byte_index_for(int param_index) const;
public: const Ctrl_Type ctrl_type_for(const int param_index) const;
public: const Range_Type range_type_for(const int param_index) const;
public: const Slider_Display_Type slider_display_type_for(const int param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_P)
};