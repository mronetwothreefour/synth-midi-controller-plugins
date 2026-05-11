#pragma once

#include <JuceHeader.h>

#include "E_00-B_Exp_Param_Info.h"
#include "C_11-P_XYWH.h"
#include "H_00-P_Build_Tree.h"

class Exposed_Parameter_Info :
	public Base_Exposed_Parameter_Info
{
//==============================================================================
public: Exposed_Parameter_Info();

public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;
public: const Knob_Display_Type knob_display_type_for(const uint8 param_index) const;
public: const uint8 cc_num_for(const uint8 param_index) const;
public: const uint8 bit_count_for(const uint8 param_index) const;
public: const uint8 byte_index_for_param_bit(const uint8 param_index, const uint8 bit_index) const;
public: const uint8 bit_index_for_param_bit(const uint8 param_index, const uint8 bit_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};