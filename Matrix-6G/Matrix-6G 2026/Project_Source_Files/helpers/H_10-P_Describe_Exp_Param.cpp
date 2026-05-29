#include "H_10-P_Describe_Exp_Param.h"

#include "c_SL__Tip_Exposed_p.h"

String Tip_Exposed::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Tip_Exposed::env_amp(const String e) {
    return from_string_literal(SL::env_amp_tip).replace("_", e);
}

String Tip_Exposed::env_attack(const String e) {
    return from_string_literal(SL::env_attack_tip).replace("_", e);
}

String Tip_Exposed::env_decay(const String e) {
    return from_string_literal(SL::env_decay_tip).replace("_", e);
}

String Tip_Exposed::env_delay(const String e) {
    return from_string_literal(SL::env_delay_tip).replace("_", e);
}

String Tip_Exposed::env_lfo_1_trig(const String e) {
    return from_string_literal(SL::env_lfo_1_trig_tip).replace("_", e);
}

String Tip_Exposed::env_mode(const String e) {
    return from_string_literal(SL::env_mode_tip).replace("_", e);
}

String Tip_Exposed::env_release(const String e) {
    return from_string_literal(SL::env_release_tip).replace("_", e);
}

String Tip_Exposed::env_sustain(const String e) {
    return from_string_literal(SL::env_sustain_tip).replace("_", e);
}

String Tip_Exposed::env_trig_mode(const String e) {
    return from_string_literal(SL::env_trig_mode_tip).replace("_", e);
}

String Tip_Exposed::env_velo_amt(const String e) {
    return from_string_literal(SL::env_velo_amt_tip).replace("_", e);
}

String Tip_Exposed::keyboard_mode() {
    return from_string_literal(SL::keyboard_mode_tip);
}

String Tip_Exposed::lfo_1_pressure_amt() {
    return from_string_literal(SL::lfo_1_pressure_amt_tip);
}

String Tip_Exposed::lfo_2_key_track_amt() {
    return from_string_literal(SL::lfo_2_key_track_amt_tip);
}

String Tip_Exposed::lfo_amp(const int lfo) {
    return from_string_literal(SL::lfo_amp_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_lag(const int lfo) {
    return from_string_literal(SL::lfo_lag_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_ramp_amt(const int lfo) {
    return from_string_literal(SL::lfo_ramp_amt_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_retrig_point(const int lfo) {
    return from_string_literal(SL::lfo_retrig_point_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_sample_source(const int lfo) {
    return from_string_literal(SL::lfo_sample_source_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_speed(const int lfo) {
    return from_string_literal(SL::lfo_speed_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_trig_mode(const int lfo) {
    return from_string_literal(SL::lfo_trig_mode_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_wave_type(const int lfo) {
    return from_string_literal(SL::lfo_wave_type_tip).replace("_", (String)lfo);
}

String Tip_Exposed::osc_1_sync() {
    return from_string_literal(SL::osc_1_sync_tip);
}

String Tip_Exposed::osc_2_detune() {
    return from_string_literal(SL::osc_2_detune_tip);
}

String Tip_Exposed::osc_balance() {
    return from_string_literal(SL::osc_balance_tip);
}

String Tip_Exposed::osc_key_click() {
    return from_string_literal(SL::osc_key_click_tip);
}

String Tip_Exposed::osc_key_track(const int o) {
    if(o == 1)
        return from_string_literal(SL::osc_1_key_track_tip);
    return from_string_literal(SL::osc_2_key_track_tip);
}

String Tip_Exposed::osc_lever_control(const int o) {
    return from_string_literal(SL::osc_lever_control_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_lfo_1_fm(const int o) {
    return from_string_literal(SL::osc_lfo_1_fm_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_lfo_2_pwm(const int o) {
    return from_string_literal(SL::osc_lfo_2_pwm_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_pulse_w(const int o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_saw_tri(const int o) {
    return from_string_literal(SL::osc_saw_tri_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_type(const int o) {
    String s{ from_string_literal(SL::osc_type_tip).replace("_", (String)o) };
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s;
}

String Tip_Exposed::porta_legato() {
    return from_string_literal(SL::porta_legato_tip);
}

String Tip_Exposed::porta_mode() {
    return from_string_literal(SL::porta_mode_tip);
}

String Tip_Exposed::porta_rate() {
    return from_string_literal(SL::porta_rate_tip);
}

String Tip_Exposed::porta_velo() {
    return from_string_literal(SL::porta_velo_tip);
}

String Tip_Exposed::ramp_rate(const int r) {
    return from_string_literal(SL::ramp_rate_tip).replace("_", (String)r);
}

String Tip_Exposed::ramp_trig(const int r) {
    return from_string_literal(SL::ramp_trig_tip).replace("_", (String)r);
}

String Tip_Exposed::track_input() {
    return from_string_literal(SL::track_input_tip);
}

String Tip_Exposed::track_point(const int p, int c) {
    String s{ from_string_literal(SL::track_point_tip) };
    s = s.replace("_", (String)p).replace("%", (String)c);
    return s;
}

String Tip_Exposed::vca_1_velo_amt() {
    return from_string_literal(SL::vca_1_velo_amt_tip);
}

String Tip_Exposed::vca_1_volume() {
    return from_string_literal(SL::vca_1_volume_tip);
}

String Tip_Exposed::vca_2_env_2_amt() {
    return from_string_literal(SL::vca_2_env_2_amt_tip);
}

String Tip_Exposed::vcf_env_1_amt() {
    return from_string_literal(SL::vcf_env_1_amt_tip);
}

String Tip_Exposed::vcf_fm_env_3_amt() {
    return from_string_literal(SL::vcf_fm_env_3_amt_tip);
}

String Tip_Exposed::vcf_fm_osc_1_amt() {
    return from_string_literal(SL::vcf_fm_osc_1_amt_tip);
}

String Tip_Exposed::vcf_fm_press_amt() {
    return from_string_literal(SL::vcf_fm_pressure_amt_tip);
}

String Tip_Exposed::vcf_freq() {
    return from_string_literal(SL::vcf_freq_tip);
}

String Tip_Exposed::vcf_key_track() {
    return from_string_literal(SL::vcf_key_track_tip);
}

String Tip_Exposed::vcf_lever_ctrl() {
    return from_string_literal(SL::vcf_lever_ctrl_tip);
}

String Tip_Exposed::vcf_pressure_amt() {
    return from_string_literal(SL::vcf_pressure_amt_tip);
}

String Tip_Exposed::vcf_reso() {
    return from_string_literal(SL::vcf_reso_tip);
}
