#include "D_TIP_Exposed_P.h"

#include "C_SL_Tip_Exposed_P.h"

String Tip_Exposed_P::env_attack(bool filter) {
    return from_string_literal(SL::env_attack_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed_P::env_decay(bool filter) {
    return from_string_literal(SL::env_decay_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed_P::env_release(bool filter) {
    return from_string_literal(SL::env_release_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed_P::env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_Exposed_P::filter_cutoff() {
    return from_string_literal(SL::filter_cutoff_tip);
}

String Tip_Exposed_P::filter_env_amt() {
    return from_string_literal(SL::filter_env_amt_tip);
}

String Tip_Exposed_P::filter_key_track() {
    return from_string_literal(SL::filter_key_track_tip);
}

String Tip_Exposed_P::filter_reso() {
    return from_string_literal(SL::filter_reso_tip);
}

String Tip_Exposed_P::glide() {
    return from_string_literal(SL::glide_tip);
}

String Tip_Exposed_P::lfo_dest_filter() {
    return from_string_literal(SL::lfo_dest_filter_tip);
}

String Tip_Exposed_P::lfo_dest_osc_pitch() {
    return from_string_literal(SL::lfo_dest_osc_pitch_tip);
}

String Tip_Exposed_P::lfo_dest_osc_pw() {
    return from_string_literal(SL::lfo_dest_osc_pw_tip);
}

String Tip_Exposed_P::lfo_freq() {
    return from_string_literal(SL::lfo_freq_tip);
}

String Tip_Exposed_P::lfo_init_amt() {
    return from_string_literal(SL::lfo_init_amt_tip);
}

String Tip_Exposed_P::lfo_shape() {
    return from_string_literal(SL::lfo_shape_tip);
}

String Tip_Exposed_P::mixer() {
    return from_string_literal(SL::mixer_tip);
}

String Tip_Exposed_P::osc_pitch(const String o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", o);
}

String Tip_Exposed_P::osc_pulse_w(const String o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", o);
}

String Tip_Exposed_P::osc_a_sync() {
    return from_string_literal(SL::osc_a_sync_tip);
}

String Tip_Exposed_P::osc_b_fine() {
    return from_string_literal(SL::osc_b_fine_tip);
}

String Tip_Exposed_P::poly_mod_dest_filter_freq() {
    return from_string_literal(SL::poly_mod_dest_filter_freq_tip);
}

String Tip_Exposed_P::poly_mod_dest_osc_a_pitch() {
    return from_string_literal(SL::poly_mod_dest_osc_a_pitch_tip);
}

String Tip_Exposed_P::poly_mod_src_filter_env_amt() {
    return from_string_literal(SL::poly_mod_src_filter_env_amt_tip);
}

String Tip_Exposed_P::poly_mod_src_osc_b_amt() {
    return from_string_literal(SL::poly_mod_src_osc_b_amt_tip);
}

String Tip_Exposed_P::unison_track() {
    return from_string_literal(SL::unison_track_tip);
}

