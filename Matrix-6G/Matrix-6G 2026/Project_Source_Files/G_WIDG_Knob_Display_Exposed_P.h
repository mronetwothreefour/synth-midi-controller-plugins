#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Knob_Display_Exposed_B.h"

class Knob_Display_Exposed_P :
	public Knob_Display_Exposed_B
{
private: const bool for_osc_balance;

//==============================================================================
public: Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub);

private: void on_editor_show() override;
private: void set_text_to_stored_choice() override;
private: void on_text_change() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Knob_Display_Exposed_P)
};
