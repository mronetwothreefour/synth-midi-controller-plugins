#pragma once

#include "c_EXP_p.h"
#include "c_XYWH_p.h"
#include "d_Sub_Tree_Choices__Exp_p.h"
#include "d_Sub_Tree_Exposed_p.h"
#include "d_Tree__Exposed_Info_b.h"

class Exposed_Parameter_Info :
	public Tree_Exposed_Info_Base
{
//==============================================================================
public: Exposed_Parameter_Info();

public: const uint8 number_for(uint8 param_index) const;
public: const uint8 byte_index_for(uint8 param_index) const;
public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;
public: const Range_Type range_type_for(const uint8 param_index) const;
public: const Slider_Display_Type slider_display_type_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};