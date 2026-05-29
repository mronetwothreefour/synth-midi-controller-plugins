#include "H_10-P_Describe_Exp_Param.h"

#include "c_SL__Tip_Exposed_p.h"

String Tip_Exposed::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Tip_Exposed::env_attack(bool filter) {
    return from_string_literal(SL::env_attack_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed::env_decay(bool filter) {
    return from_string_literal(SL::env_decay_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed::env_release(bool filter) {
    return from_string_literal(SL::env_release_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed::env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed::filter_cutoff() {
    return from_string_literal(SL::filter_cutoff_tip);
}

String Tip_Exposed::filter_env_amt() {
    return from_string_literal(SL::filter_env_amt_tip);
}

String Tip_Exposed::filter_key_track() {
    return from_string_literal(SL::filter_key_track_tip);
}

String Tip_Exposed::filter_reso() {
    return from_string_literal(SL::filter_reso_tip);
}

String Tip_Exposed::glide() {
    return from_string_literal(SL::glide_tip);
}

String Tip_Exposed::lfo_dest_filter() {
    return from_string_literal(SL::lfo_dest_filter_tip);
}

String Tip_Exposed::lfo_dest_osc_pitch() {
    return from_string_literal(SL::lfo_dest_osc_pitch_tip);
}

String Tip_Exposed::lfo_dest_osc_pw() {
    return from_string_literal(SL::lfo_dest_osc_pw_tip);
}

String Tip_Exposed::lfo_freq() {
    return from_string_literal(SL::lfo_freq_tip);
}

String Tip_Exposed::lfo_init_amt() {
    return from_string_literal(SL::lfo_init_amt_tip);
}

String Tip_Exposed::lfo_shape() {
    return from_string_literal(SL::lfo_shape_tip);
}

String Tip_Exposed::mixer() {
    return from_string_literal(SL::mixer_tip);
}

String Tip_Exposed::osc_pitch(const String o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", o);
}

String Tip_Exposed::osc_pulse_w(const String o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", o);
}

String Tip_Exposed::osc_a_sync() {
    return from_string_literal(SL::osc_a_sync_tip);
}

String Tip_Exposed::osc_b_fine() {
    return from_string_literal(SL::osc_b_fine_tip);
}

String Tip_Exposed::poly_mod_dest_filter_freq() {
    return from_string_literal(SL::poly_mod_dest_filter_freq_tip);
}

String Tip_Exposed::poly_mod_dest_osc_a_pitch() {
    return from_string_literal(SL::poly_mod_dest_osc_a_pitch_tip);
}

String Tip_Exposed::poly_mod_src_filter_env_amt() {
    return from_string_literal(SL::poly_mod_src_filter_env_amt_tip);
}

String Tip_Exposed::poly_mod_src_osc_b_amt() {
    return from_string_literal(SL::poly_mod_src_osc_b_amt_tip);
}

String Tip_Exposed::unison_track() {
    return from_string_literal(SL::unison_track_tip);
}

