#pragma once

#include "G_WIDG_Slider_Exp_G.h"

class Slider_Exposed_P :
	public Slider_Exposed_G
{
//==============================================================================
public: Slider_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub);

public: void update_value_tip() override;
public: void update_according_to_mod() override;
public: void attach_to_param() override;
public: ~Slider_Exposed_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Exposed_P)
};