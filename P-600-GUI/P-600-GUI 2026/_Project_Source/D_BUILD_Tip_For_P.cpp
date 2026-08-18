#include "D_BUILD_Tip_For_P.h"

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

String Tip_For::exp_env_attack(bool filter) {
    return from_string_literal(SL::env_attack_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_decay(bool filter) {
    return from_string_literal(SL::env_decay_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_release(bool filter) {
    return from_string_literal(SL::env_release_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_tip).replace("_type of_", filter ? "filter" : "amplifier");
}

String Tip_For::exp_filter_cutoff() {
    return from_string_literal(SL::filter_cutoff_tip);
}

String Tip_For::exp_filter_env_amt() {
    return from_string_literal(SL::filter_env_amt_tip);
}

String Tip_For::exp_filter_key_track() {
    return from_string_literal(SL::filter_key_track_tip);
}

String Tip_For::exp_filter_reso() {
    return from_string_literal(SL::filter_reso_tip);
}

String Tip_For::exp_glide() {
    return from_string_literal(SL::glide_tip);
}

String Tip_For::exp_lfo_dest_filter() {
    return from_string_literal(SL::lfo_dest_filter_tip);
}

String Tip_For::exp_lfo_dest_osc_pitch() {
    return from_string_literal(SL::lfo_dest_osc_pitch_tip);
}

String Tip_For::exp_lfo_dest_osc_pw() {
    return from_string_literal(SL::lfo_dest_osc_pw_tip);
}

String Tip_For::exp_lfo_freq() {
    return from_string_literal(SL::lfo_freq_tip);
}

String Tip_For::exp_lfo_init_amt() {
    return from_string_literal(SL::lfo_init_amt_tip);
}

String Tip_For::exp_lfo_shape() {
    return from_string_literal(SL::lfo_shape_tip);
}

String Tip_For::exp_mixer() {
    return from_string_literal(SL::mixer_tip);
}

String Tip_For::exp_osc_pitch(const String o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", o);
}

String Tip_For::exp_osc_pulse_w(const String o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", o);
}

String Tip_For::exp_osc_pulse(const String o) {
    return "When on, oscillator " + o + " outputs a pulse wave.";
}

String Tip_For::exp_osc_saw(const String o) {
    return "When on, oscillator " + o + " outputs a sawtooth wave.";
}

String Tip_For::exp_osc_tri(const String o) {
    return "When on, oscillator " + o + " outputs a triangle wave.";
}

String Tip_For::exp_osc_a_sync() {
    return from_string_literal(SL::osc_a_sync_tip);
}

String Tip_For::exp_osc_b_fine() {
    return from_string_literal(SL::osc_b_fine_tip);
}

String Tip_For::exp_poly_mod_amt_filter_env() {
    return from_string_literal(SL::poly_mod_src_filter_env_amt_tip);
}

String Tip_For::exp_poly_mod_amt_osc_b() {
    return from_string_literal(SL::poly_mod_src_osc_b_amt_tip);
}

String Tip_For::exp_poly_mod_dest_filter_freq() {
    return from_string_literal(SL::poly_mod_dest_filter_freq_tip);
}

String Tip_For::exp_poly_mod_dest_osc_a_freq() {
    return from_string_literal(SL::poly_mod_dest_osc_a_pitch_tip);
}

String Tip_For::exp_unison_track() {
    return from_string_literal(SL::unison_track_tip);
}

String BUILD::Tip_For::knob_txt_editor(const String& name) {
	if (name == NAME::lbl_u_int_4_bit)
		return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "15");
    if (name == NAME::lbl_u_int_5_bit)
        return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "31");
    if (name == NAME::lbl_u_int_6_bit)
        return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "63");
    if (name == NAME::lbl_u_int_7_bit)
        return from_string_literal(SL::knob_txt_edit_int_tip).replace("_", "127");
	if (name == NAME::lbl_osc_pitch)
		return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
    return {};
}

