#include "D_BUILD_Tip_P.h"

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

String Tip::exp_env_amp(const int e) {
    return from_string_literal(SL::env_amp_tip).replace("_", (String)e);
}

String Tip::exp_env_attack(const int e) {
    return from_string_literal(SL::env_attack_tip).replace("_", (String)e);
}

String Tip::exp_env_decay(const int e) {
    return from_string_literal(SL::env_decay_tip).replace("_", (String)e);
}

String Tip::exp_env_delay(const int e) {
    return from_string_literal(SL::env_delay_tip).replace("_", (String)e);
}

String Tip::exp_env_lfo_1_trig(const int e) {
    return from_string_literal(SL::env_lfo_1_trig_tip).replace("_", (String)e);
}

String Tip::exp_env_mode(const int e) {
    return from_string_literal(SL::env_mode_tip).replace("_", (String)e);
}

String Tip::exp_env_release(const int e) {
    return from_string_literal(SL::env_release_tip).replace("_", (String)e);
}

String Tip::exp_env_sustain(const int e) {
    return from_string_literal(SL::env_sustain_tip).replace("_", (String)e);
}

String Tip::exp_env_trig_mode(const int e) {
    return from_string_literal(SL::env_trig_mode_tip).replace("_", (String)e);
}

String Tip::exp_env_velo_amt(const int e) {
    return from_string_literal(SL::env_velo_amt_tip).replace("_", (String)e);
}

String Tip::exp_keyboard_mode() {
    return from_string_literal(SL::keyboard_mode_tip);
}

String Tip::exp_lfo_1_pressure_amt() {
    return from_string_literal(SL::lfo_1_pressure_amt_tip);
}

String Tip::exp_lfo_2_key_track_amt() {
    return from_string_literal(SL::lfo_2_key_track_amt_tip);
}

String Tip::exp_lfo_amp(const int lfo) {
    return from_string_literal(SL::lfo_amp_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_lag(const int lfo) {
    return from_string_literal(SL::lfo_lag_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_ramp_amt(const int lfo) {
    return from_string_literal(SL::lfo_ramp_amt_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_retrig_point(const int lfo) {
    return from_string_literal(SL::lfo_retrig_point_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_sample_source(const int lfo) {
    return from_string_literal(SL::lfo_sample_source_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_speed(const int lfo) {
    return from_string_literal(SL::lfo_speed_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_trig_mode(const int lfo) {
    return from_string_literal(SL::lfo_trig_mode_tip).replace("_", (String)lfo);
}

String Tip::exp_lfo_wave_type(const int lfo) {
    return from_string_literal(SL::lfo_wave_type_tip).replace("_", (String)lfo);
}

String Tip::exp_osc_1_sync() {
    return from_string_literal(SL::osc_1_sync_tip);
}

String Tip::exp_osc_2_detune() {
    return from_string_literal(SL::osc_2_detune_tip);
}

String Tip::exp_osc_balance() {
    return from_string_literal(SL::osc_balance_tip);
}

String Tip::exp_osc_key_click() {
    return from_string_literal(SL::osc_key_click_tip);
}

String Tip::exp_osc_key_track(const int o) {
    if(o == 1)
        return from_string_literal(SL::osc_1_key_track_tip);
    return from_string_literal(SL::osc_2_key_track_tip);
}

String Tip::exp_osc_lever_control(const int o) {
    return from_string_literal(SL::osc_lever_control_tip).replace("_", (String)o);
}

String Tip::exp_osc_lfo_1_fm(const int o) {
    return from_string_literal(SL::osc_lfo_1_fm_tip).replace("_", (String)o);
}

String Tip::exp_osc_lfo_2_pwm(const int o) {
    return from_string_literal(SL::osc_lfo_2_pwm_tip).replace("_", (String)o);
}

String Tip::exp_osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", (String)o);
}

String Tip::exp_osc_pulse_w(const int o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", (String)o);
}

String Tip::exp_osc_saw_tri(const int o) {
    return from_string_literal(SL::osc_saw_tri_tip).replace("_", (String)o);
}

String Tip::exp_osc_type(const int o) {
    String s{ from_string_literal(SL::osc_type_tip).replace("_", (String)o) };
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s;
}

String Tip::exp_porta_legato() {
    return from_string_literal(SL::porta_legato_tip);
}

String Tip::exp_porta_mode() {
    return from_string_literal(SL::porta_mode_tip);
}

String Tip::exp_porta_rate() {
    return from_string_literal(SL::porta_rate_tip);
}

String Tip::exp_porta_velo() {
    return from_string_literal(SL::porta_velo_tip);
}

String Tip::exp_ramp_rate(const int r) {
    return from_string_literal(SL::ramp_rate_tip).replace("_", (String)r);
}

String Tip::exp_ramp_trig(const int r) {
    return from_string_literal(SL::ramp_trig_tip).replace("_", (String)r);
}

String Tip::exp_track_input() {
    return from_string_literal(SL::track_input_tip);
}

String Tip::exp_track_point(const int p, int c) {
    String s{ from_string_literal(SL::track_point_tip) };
    s = s.replace("_", (String)p).replace("%", (String)c);
    return s;
}

String Tip::exp_vca_1_velo_amt() {
    return from_string_literal(SL::vca_1_velo_amt_tip);
}

String Tip::exp_vca_1_volume() {
    return from_string_literal(SL::vca_1_volume_tip);
}

String Tip::exp_vca_2_env_2_amt() {
    return from_string_literal(SL::vca_2_env_2_amt_tip);
}

String Tip::exp_vcf_env_1_amt() {
    return from_string_literal(SL::vcf_env_1_amt_tip);
}

String Tip::exp_vcf_fm_env_3_amt() {
    return from_string_literal(SL::vcf_fm_env_3_amt_tip);
}

String Tip::exp_vcf_fm_osc_1_amt() {
    return from_string_literal(SL::vcf_fm_osc_1_amt_tip);
}

String Tip::exp_vcf_fm_press_amt() {
    return from_string_literal(SL::vcf_fm_pressure_amt_tip);
}

String Tip::exp_vcf_freq() {
    return from_string_literal(SL::vcf_freq_tip);
}

String Tip::exp_vcf_key_track() {
    return from_string_literal(SL::vcf_key_track_tip);
}

String Tip::exp_vcf_lever_ctrl() {
    return from_string_literal(SL::vcf_lever_ctrl_tip);
}

String Tip::exp_vcf_press_amt() {
    return from_string_literal(SL::vcf_pressure_amt_tip);
}

String Tip::exp_vcf_reso() {
    return from_string_literal(SL::vcf_reso_tip);
}

String BUILD::Tip::slider_txt_editor(const String& name, bool u_7_bit) {
	if (name == NAME::lbl_osc_pitch)
        return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
    if (name == NAME::lbl_s_6_bit_int)
        return from_string_literal(SL::knob_txt_edit_s_int_tip).replace("_", "31");
    if (name == NAME::lbl_s_7_bit_int)
        return from_string_literal(SL::knob_txt_edit_s_int_tip).replace("_", "63");
    if (name == NAME::lbl_u_int)
        return from_string_literal(SL::knob_txt_edit_u_int_tip).replace("_", u_7_bit ? "127" : "63");
    return "";
}
