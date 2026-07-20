#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"

using namespace ENUM;

class Tree_Aux_Voice_P
{
private: ValueTree tree;
private: ValueTree tree_bit_loc;
private: UndoManager* u_m;

//==============================================================================
public: explicit Tree_Aux_Voice_P(UndoManager* u_m);

public: const int amp_mod_by_velo_amt();
public: void set_amp_mod_by_velo_amt(const int new_setting);

public: const int assignable_slider_bend_range(const bool pos_limit);
public: void set_assignable_slider_bend_range(const bool pos_limit, const int new_setting);

public: const int assignable_slider_range();
public: void set_assignable_slider_range(const int new_setting);

public: const Assignable_Slider_Target assignable_slider_target();
public: void set_assignable_slider_target(const Assignable_Slider_Target new_setting);

public: const String current_voice_name();
public: void set_current_voice_name(const String new_setting);

public: const int keyboard_octave();
public: void set_keyboard_octave(const int new_setting);

public: const bool lfo_sync_bpm_on();
public: void set_lfo_sync_bpm_on(const bool should_be_on);

public: const bool lfo_sync_key_on();
public: void set_lfo_sync_key_on(const bool should_be_on);

public: const bool lfo_sync_voice_on();
public: void set_lfo_sync_voice_on(const bool should_be_on);

public: const Microtune_Scale microtune_scale();
public: void set_microtune_scale(const Microtune_Scale new_setting);
public: int microtune_scale_hardware_index(const Microtune_Scale scale);

public: const int pgm_fine_tune();
public: void set_pgm_fine_tune(const int new_setting);

public: const int pgm_level();
public: void set_pgm_level(const int new_setting);

public: const int pgm_transpose();
public: void set_pgm_transpose(const int new_setting);

public: const bool porta_mode_on();
public: void set_porta_mode_on(const bool should_be_on);

public: const bool porta_sync_bpm_on();
public: void set_porta_sync_bpm_on(const bool should_be_on);

public: const int porta_time();
public: void set_porta_time(const int new_setting);

public: const int scale_key();
public: void set_scale_key(const int new_setting);

public: const Voice_Mode voice_mode();
public: void set_voice_mode(const Voice_Mode new_setting);

public: Value get_param_as_value(const Aux_Voice_Param param);

public: const int byte_index_for_param_bit(const Aux_Voice_Param param, const int bit_index) const;
public: const int bit_index_for_param_bit(const Aux_Voice_Param param, const int bit_index) const;

public: std::unique_ptr<XmlElement> get_state();
public: void replace_state(const ValueTree& new_state);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Aux_Voice_P)
};