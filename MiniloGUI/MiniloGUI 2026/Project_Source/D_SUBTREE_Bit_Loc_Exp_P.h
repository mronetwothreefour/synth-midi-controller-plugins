#pragma once

#include "C_ID_P.h"

struct Subtree_Bit_Loc_Exp_P
{
public: static ValueTree delay_feedback();
public: static ValueTree delay_hpf_freq();
public: static ValueTree delay_routing();
public: static ValueTree delay_time();
public: static ValueTree env_attack(const bool vca);
public: static ValueTree env_decay(const bool vca);
public: static ValueTree env_release(const bool vca);
public: static ValueTree env_sustain(const bool vca);
public: static ValueTree level_knob(const int knob);
public: static ValueTree lfo_eg_mod();
public: static ValueTree lfo_int();
public: static ValueTree lfo_rate();
public: static ValueTree lfo_target();
public: static ValueTree lfo_wave();
public: static ValueTree lpf_eg_int();
public: static ValueTree lpf_freq();
public: static ValueTree lpf_key_track();
public: static ValueTree lpf_reso();
public: static ValueTree lpf_type();
public: static ValueTree lpf_velo_amt();
public: static ValueTree osc_2_pitch_eg_int();
public: static ValueTree osc_2_ring_mod();
public: static ValueTree osc_2_sync();
public: static ValueTree osc_2_x_mod_depth();
public: static ValueTree osc_octave(const int osc);
public: static ValueTree osc_pitch_fine(const int osc);
public: static ValueTree osc_shape(const int osc);
public: static ValueTree osc_wave(const int osc);
public: static ValueTree voice_mode_depth();
};