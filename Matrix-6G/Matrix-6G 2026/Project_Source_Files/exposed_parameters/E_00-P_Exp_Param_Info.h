#pragma once

#include <JuceHeader.h>

#include "C_00-P_ID.h"
#include "C_01-P_ENUM.h"
#include "C_50-P_EP.h"
#include "E_00-B_Exp_Param_Info.h"

using namespace ENUM;

class Exposed_Parameter_Info :
	public Base_Exposed_Parameter_Info
{
private: ValueTree tree;

//==============================================================================
public: Exposed_Parameter_Info();

public: const uint8 byte_index_for(uint8 param_index) const;
public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};