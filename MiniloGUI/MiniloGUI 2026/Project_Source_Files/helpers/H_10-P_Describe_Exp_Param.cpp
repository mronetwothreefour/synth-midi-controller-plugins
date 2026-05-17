#include "H_10-P_Describe_Exp_Param.h"

#include "C_60-P_SL_EP_Descriptions.h"

String Describe_Exp_Param::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Describe_Exp_Param::delay_feedback() {
    return from_string_literal(SL::delay_feedback_description);
}

String Describe_Exp_Param::delay_routing() {
    return from_string_literal(SL::delay_routing_description);
}

String Describe_Exp_Param::delay_time() {
    return from_string_literal(SL::delay_time_description);
}

String Describe_Exp_Param::delay_hpf_freq() {
    return from_string_literal(SL::delay_hpf_freq_description);
}

String Describe_Exp_Param::env_attack(bool vca) {
    String s{ from_string_literal(SL::env_attack_description) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "16" : "20");
    return s;
}

String Describe_Exp_Param::env_decay(bool vca) {
    String s{ from_string_literal(SL::env_decay_description) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "17" : "21");
    return s;
}

String Describe_Exp_Param::env_release(bool vca) {
    String s{ from_string_literal(SL::env_release_description) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "19" : "23");
    return s;
}

String Describe_Exp_Param::env_sustain(bool vca) {
    String s{ from_string_literal(SL::env_sustain_description) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "18" : "22");
    return s;
}

String Describe_Exp_Param::key_track() {
    return from_string_literal(SL::key_track_description);
}

String Describe_Exp_Param::level_knob(const int k) {
    String s{ from_string_literal(SL::level_knob_description) };
    s = s.replace("_target_name", k == 1 ? "oscillator 1" : k == 2 ? "oscillator 2" : "the white noise generator");
    s = s.replace("%%", k == 1 ? "39" : k == 2 ? "40" : "33");
    return s;
}

String Describe_Exp_Param::lfo_eg_mod() {
    return from_string_literal(SL::lfo_eg_mod_description);
}

String Describe_Exp_Param::lfo_int() {
    return from_string_literal(SL::lfo_int_description);
}

String Describe_Exp_Param::lfo_rate() {
    return from_string_literal(SL::lfo_rate_description);
}

String Describe_Exp_Param::lfo_target() {
    return from_string_literal(SL::lfo_target_description);
}

String Describe_Exp_Param::lfo_wave() {
    return from_string_literal(SL::lfo_wave_description);
}

String Describe_Exp_Param::lpf_eg_int() {
    return from_string_literal(SL::lpf_eg_int_description);
}

String Describe_Exp_Param::lpf_freq() {
    return from_string_literal(SL::lpf_freq_description);
}

String Describe_Exp_Param::lpf_reso() {
    return from_string_literal(SL::lpf_reso_description);
}

String Describe_Exp_Param::lpf_type() {
    return from_string_literal(SL::lpf_type_description);
}

String Describe_Exp_Param::lpf_vel_amt() {
    return from_string_literal(SL::lpf_vel_amt_description);
}

String Describe_Exp_Param::osc_2_pitch_eg_int() {
    return from_string_literal(SL::osc_2_pitch_eg_int_description);
}

String Describe_Exp_Param::osc_2_ring_mod() {
    return from_string_literal(SL::osc_2_ring_mod_description);
}

String Describe_Exp_Param::osc_2_sync() {
    return from_string_literal(SL::osc_2_sync_description);
}

String Describe_Exp_Param::osc_2_x_mod_depth() {
    return from_string_literal(SL::osc_2_x_mod_depth_description);
}

String Describe_Exp_Param::osc_octave(const int o) {
    String s{ from_string_literal(SL::osc_octave_description) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "48" : "49");
    return s;
}

String Describe_Exp_Param::osc_pitch_fine(const int o) {
    String s{ from_string_literal(SL::osc_pitch_fine_description) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "34" : "35");
    return s;
}

String Describe_Exp_Param::osc_shape(const int o) {
    String s{ from_string_literal(SL::osc_shape_description) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "36" : "37");
    return s;
}

String Describe_Exp_Param::osc_wave(const int o) {
    String s{ from_string_literal(SL::osc_wave_description) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "50" : "51");
    return s;
}

String Describe_Exp_Param::voice_mode_depth() {
    return from_string_literal(SL::voice_mode_depth_description);
}
