#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"

using namespace ENUM;

using Layout = AudioProcessorValueTreeState::ParameterLayout;

class Tree_Exposed_Info_G
{
protected: ValueTree tree;

//==============================================================================
public: Tree_Exposed_Info_G();

protected: const ValueTree param(const Exp_Param id) const;
public: const String name_for(const Exp_Param id) const;
public: const Ctrl_Type ctrl_type_for(const Exp_Param id) const;
public: const Slider_Display_Type display_type_for(const Exp_Param id) const;
public: const int choice_count_for(const Exp_Param id) const;
public: const int init_choice_for(const Exp_Param id) const;
public: Point<int> ctrl_center_for(const Exp_Param id) const;
public: int ctrl_width_for(const Exp_Param id) const;
public: int ctrl_height_for(const Exp_Param id) const;
public: const String tip_for(const Exp_Param id) const;
public: const String choice_for(const Exp_Param id, const int choice_num, bool curt = false) const;
public: const StringArray choices_list_for(const Exp_Param id, bool curt = false) const;
public: virtual const int drag_sensitivity_for(const Exp_Param id, float scale_factor) const;
public: virtual Layout build_param_layout() const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Exposed_Info_G)
};