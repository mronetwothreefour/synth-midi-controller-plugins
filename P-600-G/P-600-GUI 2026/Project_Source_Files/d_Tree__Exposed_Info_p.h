#pragma once

#include <JuceHeader.h>

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

public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;
public: const uint8 first_nybble_index_for(const uint8 param_index) const;
public: const uint8 first_bit_index_for(const uint8 paramIndex) const;
public: const uint8 bit_count_for(const uint8 paramIndex) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};