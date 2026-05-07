#pragma once

#include <JuceHeader.h>

#include "C_ENUM.h"
#include "EP _0_Exp_Param_Info_Base.h"

using namespace ENUM;

class Exposed_Parameter_Info :
	public Exposed_Parameter_Info_Base
{
private: ValueTree tree;

//==============================================================================
public: Exposed_Parameter_Info();

public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};