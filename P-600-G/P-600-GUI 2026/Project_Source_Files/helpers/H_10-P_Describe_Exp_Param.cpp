#include "H_10-P_Describe_Exp_Param.h"

#include "C_60-P_SL_EP_Descriptions.h"

String Describe_Exp_Param::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Describe_Exp_Param::env_attack(bool filter) {
    return from_string_literal(SL::env_attack_description).replace("_type of_", filter ? "filter" : "amplifier");
}

String Describe_Exp_Param::env_decay(bool filter) {
    return from_string_literal(SL::env_decay_description).replace("_type of_", filter ? "filter" : "amplifier");
}

String Describe_Exp_Param::env_release(bool filter) {
    return from_string_literal(SL::env_release_description).replace("_type of_", filter ? "filter" : "amplifier");
}

String Describe_Exp_Param::env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_description).replace("_type of_", filter ? "filter" : "amplifier");
}

String Describe_Exp_Param::filter_cutoff() {
    return from_string_literal(SL::filter_cutoff_description);
}

String Describe_Exp_Param::filter_env_amt() {
    return from_string_literal(SL::filter_env_amt_description);
}

String Describe_Exp_Param::filter_key_track() {
    return from_string_literal(SL::filter_key_track_description);
}

String Describe_Exp_Param::filter_reso() {
    return from_string_literal(SL::filter_reso_description);
}

String Describe_Exp_Param::glide() {
    return from_string_literal(SL::glide_description);
}

String Describe_Exp_Param::lfo_dest_filter() {
    return from_string_literal(SL::lfo_dest_filter_description);
}

String Describe_Exp_Param::lfo_dest_osc_pitch() {
    return from_string_literal(SL::lfo_dest_osc_pitch_description);
}

String Describe_Exp_Param::lfo_dest_osc_pulse_w() {
    return from_string_literal(SL::lfo_dest_osc_pulse_w_description);
}

String Describe_Exp_Param::lfo_freq() {
    return from_string_literal(SL::lfo_freq_description);
}

String Describe_Exp_Param::lfo_init_amt() {
    return from_string_literal(SL::lfo_init_amt_description);
}

String Describe_Exp_Param::lfo_shape() {
    return from_string_literal(SL::lfo_shape_description);
}

String Describe_Exp_Param::mixer() {
    return from_string_literal(SL::mixer_description);
}

String Describe_Exp_Param::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_description).replace("_", o == 1 ? "A" : "B");
}

String Describe_Exp_Param::osc_pulse_w(const int o) {
    return from_string_literal(SL::osc_pulse_w_description).replace("_", o == 1 ? "A" : "B");
}

String Describe_Exp_Param::osc_a_sync() {
    return from_string_literal(SL::osc_a_sync_description);
}

String Describe_Exp_Param::osc_b_fine() {
    return from_string_literal(SL::osc_b_fine_description);
}

String Describe_Exp_Param::poly_mod_dest_filter_freq() {
    return from_string_literal(SL::poly_mod_dest_filter_freq_description);
}

String Describe_Exp_Param::poly_mod_dest_osc_a_pitch() {
    return from_string_literal(SL::poly_mod_dest_osc_a_pitch_description);
}

String Describe_Exp_Param::poly_mod_src_filter_env_amt() {
    return from_string_literal(SL::poly_mod_src_filter_env_amt_description);
}

String Describe_Exp_Param::poly_mod_src_osc_b_amt() {
    return from_string_literal(SL::poly_mod_src_osc_b_amt_description);
}

String Describe_Exp_Param::unison_track() {
    return from_string_literal(SL::unison_track_description);
}

