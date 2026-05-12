#pragma once

#include <JuceHeader.h>

#include "C_00-B_ID.h"

class Base_Exposed_Parameter_Info
{
protected: ValueTree tree;
protected: const uint8 exp_param_count;

//==============================================================================
public: explicit Base_Exposed_Parameter_Info(const uint8 exp_param_count);

protected: const ValueTree param(uint8 param_index) const;
public: const Identifier id_for(uint8 param_index) const;
public: const String name_for(uint8 param_index) const;
public: const uint8 choice_count_for(uint8 param_index) const;
public: const uint8 init_choice_for(uint8 param_index) const;
public: Point<int> ctrl_center_for(uint8 param_index) const;
public: int ctrl_width_for(uint8 param_index) const;
public: int ctrl_height_for(uint8 param_index) const;
public: const String description_for(uint8 param_index) const;
public: const String choice_name_for(uint8 param_index, const uint8 choice_num, bool curt = false) const;
public: const StringArray choice_name_list_for(uint8 param_index, bool curt = false) const;
public: virtual const int drag_sensitivity_for(uint8 param_index, float scale_factor) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Base_Exposed_Parameter_Info)
};