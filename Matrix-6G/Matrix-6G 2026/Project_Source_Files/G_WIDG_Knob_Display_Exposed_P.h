#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"

class Knob_Display_Exposed_P :
	public Label,
	public AudioProcessorParameter::Listener,
	public Data_User_P
{
private: const int param_index;
private: RangedAudioParameter* param;
private: const Knob_Display_Type display_type;

//==============================================================================
public: Knob_Display_Exposed_P(const int param_index, Data_Hub_P* hub);

private: void on_editor_show();
private: void on_editor_show_pitch();
private: void on_editor_show_signed_int();
private: void on_editor_show_unsigned_int();
private: void set_text_to_stored_choice();
private: void on_text_change_pitch();
private: void on_text_change_int();
public: void parameterValueChanged(int param_index, float new_value) override;
public: ~Knob_Display_Exposed_P();


//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Knob_Display_Exposed_P)
};
