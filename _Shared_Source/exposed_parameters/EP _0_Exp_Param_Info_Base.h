#pragma once

#include <JuceHeader.h>

#include "C_ID _Shared.h"

class Exposed_Parameter_Info_Base
{
private: ValueTree tree;
protected: const uint8 exp_param_count;

//==============================================================================
public: explicit Exposed_Parameter_Info_Base(const uint8 exp_param_count);

protected: const ValueTree param(const uint8 param_index) const;
public: const Identifier id_for(const uint8 param_index) const;
public: const uint8 param_num_for(const uint8 param_index) const;
public: const String name_for(const uint8 param_index) const;
public: uint8 byte_index_for(const uint8 param_index) const;
public: uint8 choice_count_for(const uint8 param_index) const;
public: uint8 init_choice_for(const uint8 param_index) const;
public: Point<int> ctrl_center_for(const uint8 param_index) const;
public: int ctrl_width_for(const uint8 param_index) const;
public: String description_for(const uint8 param_index) const;
public: String choice_name_for(const uint8 param_index, const uint8 choice_num, bool curt = true) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info_Base)
};