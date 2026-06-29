#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Exp_B.h"

class Slider_Exposed_P :
	public Slider_Exposed_B
{
//==============================================================================
public: Slider_Exposed_P(const int param_index, Data_Hub_P* hub);

public: void update_value_tip() override;
public: void update_according_to_mod() override;
public: ~Slider_Exposed_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Exposed_P)
};