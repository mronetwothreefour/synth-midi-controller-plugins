#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"
#include "C_EXP_P.h"
#include "C_ID_P.h"

using namespace ENUM;

class Tree_Exposed_Info_B
{
protected: ValueTree tree;

//==============================================================================
public: Tree_Exposed_Info_B();

protected: const ValueTree param(int param_index) const;
public: const Identifier id_for(int param_index) const;
public: const String name_for(int param_index) const;
public: const Ctrl_Type ctrl_type_for(const int param_index) const;
public: const Slider_Display_Type display_type_for(const int param_index) const;
public: const int choice_count_for(int param_index) const;
public: const int init_choice_for(int param_index) const;
public: Point<int> ctrl_center_for(int param_index) const;
public: int ctrl_width_for(int param_index) const;
public: int ctrl_height_for(int param_index) const;
public: const String tip_for(int param_index) const;
public: const String choice_for(int param_index, const int choice_num, bool curt = false) const;
public: const StringArray choices_list_for(int param_index, bool curt = false) const;
public: virtual const int drag_sensitivity_for(int param_index, float scale_factor) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_B)
};