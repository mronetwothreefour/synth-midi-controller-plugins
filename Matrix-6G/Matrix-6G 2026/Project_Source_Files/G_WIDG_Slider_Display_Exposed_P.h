#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Display_Exposed_B.h"

class Slider_Display_Exposed_P :
	public Slider_Display_Exposed_B
{
private: const bool for_osc_balance;

//==============================================================================
public: Slider_Display_Exposed_P(const int param_index, Data_Hub_P* hub);

private: void on_editor_show() override;
private: void set_text_to_stored_choice() override;
private: void on_text_change() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Display_Exposed_P)
};
