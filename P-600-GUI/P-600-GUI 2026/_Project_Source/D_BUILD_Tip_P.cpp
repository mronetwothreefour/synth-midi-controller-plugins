#include "D_BUILD_Tip_P.h"

#include "C_SL_Tip_Exposed_P.h"

String Build_Tip::exp_env_attack(bool filter) {
    return from_string_literal(SL::env_attack_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Build_Tip::exp_env_decay(bool filter) {
    return from_string_literal(SL::env_decay_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Build_Tip::exp_env_release(bool filter) {
    return from_string_literal(SL::env_release_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Build_Tip::exp_env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Build_Tip::exp_filter_cutoff() {
    return from_string_literal(SL::filter_cutoff_tip);
}

String Build_Tip::exp_filter_env_amt() {
    return from_string_literal(SL::filter_env_amt_tip);
}

String Build_Tip::exp_filter_key_track() {
    return from_string_literal(SL::filter_key_track_tip);
}

String Build_Tip::exp_filter_reso() {
    return from_string_literal(SL::filter_reso_tip);
}

String Build_Tip::exp_glide() {
    return from_string_literal(SL::glide_tip);
}

String Build_Tip::exp_lfo_dest_filter() {
    return from_string_literal(SL::lfo_dest_filter_tip);
}

String Build_Tip::exp_lfo_dest_osc_pitch() {
    return from_string_literal(SL::lfo_dest_osc_pitch_tip);
}

String Build_Tip::exp_lfo_dest_osc_pw() {
    return from_string_literal(SL::lfo_dest_osc_pw_tip);
}

String Build_Tip::exp_lfo_freq() {
    return from_string_literal(SL::lfo_freq_tip);
}

String Build_Tip::exp_lfo_init_amt() {
    return from_string_literal(SL::lfo_init_amt_tip);
}

String Build_Tip::exp_lfo_shape() {
    return from_string_literal(SL::lfo_shape_tip);
}

String Build_Tip::exp_mixer() {
    return from_string_literal(SL::mixer_tip);
}

String Build_Tip::exp_osc_pitch(const String o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", o);
}

String Build_Tip::exp_osc_pulse_w(const String o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", o);
}

String Build_Tip::exp_osc_pulse(const String o) {
    return "When on, oscillator " + o + " outputs a pulse wave.";
}

String Build_Tip::exp_osc_saw(const String o) {
    return "When on, oscillator " + o + " outputs a sawtooth wave.";
}

String Build_Tip::exp_osc_tri(const String o) {
    return "When on, oscillator " + o + " outputs a triangle wave.";
}

String Build_Tip::exp_osc_a_sync() {
    return from_string_literal(SL::osc_a_sync_tip);
}

String Build_Tip::exp_osc_b_fine() {
    return from_string_literal(SL::osc_b_fine_tip);
}

String Build_Tip::exp_poly_mod_amt_filter_env() {
    return from_string_literal(SL::poly_mod_src_filter_env_amt_tip);
}

String Build_Tip::exp_poly_mod_amt_osc_b() {
    return from_string_literal(SL::poly_mod_src_osc_b_amt_tip);
}

String Build_Tip::exp_poly_mod_dest_filter_freq() {
    return from_string_literal(SL::poly_mod_dest_filter_freq_tip);
}

String Build_Tip::exp_poly_mod_dest_osc_a_freq() {
    return from_string_literal(SL::poly_mod_dest_osc_a_pitch_tip);
}

String Build_Tip::exp_unison_track() {
    return from_string_literal(SL::unison_track_tip);
}

