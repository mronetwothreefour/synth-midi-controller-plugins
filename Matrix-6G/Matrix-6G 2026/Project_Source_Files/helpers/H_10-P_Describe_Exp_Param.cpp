#include "H_10-P_Describe_Exp_Param.h"

#include "C_60-P_SL_EP_Descriptions.h"

String Describe_Exp_Param::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Describe_Exp_Param::env_amp(const String e) {
    return from_string_literal(SL::env_amp_description).replace("_", e);
}

String Describe_Exp_Param::env_attack(const String e) {
    return from_string_literal(SL::env_attack_description).replace("_", e);
}

String Describe_Exp_Param::env_decay(const String e) {
    return from_string_literal(SL::env_decay_description).replace("_", e);
}

String Describe_Exp_Param::env_delay(const String e) {
    return from_string_literal(SL::env_delay_description).replace("_", e);
}

String Describe_Exp_Param::env_lfo_1_trig(const String e) {
    return from_string_literal(SL::env_lfo_1_trig_description).replace("_", e);
}

String Describe_Exp_Param::env_mode(const String e) {
    return from_string_literal(SL::env_mode_description).replace("_", e);
}

String Describe_Exp_Param::env_release(const String e) {
    return from_string_literal(SL::env_release_description).replace("_", e);
}

String Describe_Exp_Param::env_sustain(const String e) {
    return from_string_literal(SL::env_sustain_description).replace("_", e);
}

String Describe_Exp_Param::env_trig_mode(const String e) {
    return from_string_literal(SL::env_trig_mode_description).replace("_", e);
}

String Describe_Exp_Param::env_velo_amt(const String e) {
    return from_string_literal(SL::env_velo_amt_description).replace("_", e);
}

String Describe_Exp_Param::keyboard_mode() {
    return from_string_literal(SL::keyboard_mode_description);
}

String Describe_Exp_Param::lfo_1_pressure_amt() {
    return from_string_literal(SL::lfo_1_pressure_amt_description);
}

String Describe_Exp_Param::lfo_2_key_track_amt() {
    return from_string_literal(SL::lfo_2_key_track_amt_description);
}

String Describe_Exp_Param::lfo_amp(const int lfo) {
    return from_string_literal(SL::lfo_amp_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_lag(const int lfo) {
    return from_string_literal(SL::lfo_lag_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_ramp_amt(const int lfo) {
    return from_string_literal(SL::lfo_ramp_amt_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_retrig_point(const int lfo) {
    return from_string_literal(SL::lfo_retrig_point_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_sample_source(const int lfo) {
    return from_string_literal(SL::lfo_sample_source_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_speed(const int lfo) {
    return from_string_literal(SL::lfo_speed_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_trig_mode(const int lfo) {
    return from_string_literal(SL::lfo_trig_mode_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_wave_type(const int lfo) {
    return from_string_literal(SL::lfo_wave_type_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::osc_1_sync() {
    return from_string_literal(SL::osc_1_sync_description);
}

String Describe_Exp_Param::osc_2_detune() {
    return from_string_literal(SL::osc_2_detune_description);
}

String Describe_Exp_Param::osc_balance() {
    return from_string_literal(SL::osc_balance_description);
}

String Describe_Exp_Param::osc_key_click() {
    return from_string_literal(SL::osc_key_click_description);
}

String Describe_Exp_Param::osc_key_track(const int o) {
    if(o == 1)
        return from_string_literal(SL::osc_1_key_track_description);
    return from_string_literal(SL::osc_2_key_track_description);
}

String Describe_Exp_Param::osc_lever_control(const int o) {
    return from_string_literal(SL::osc_lever_control_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_lfo_1_fm(const int o) {
    return from_string_literal(SL::osc_lfo_1_fm_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_lfo_2_pwm(const int o) {
    return from_string_literal(SL::osc_lfo_2_pwm_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_pulse_w(const int o) {
    return from_string_literal(SL::osc_pulse_w_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_saw_tri(const int o) {
    return from_string_literal(SL::osc_saw_tri_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_type(const int o) {
    String s{ from_string_literal(SL::osc_type_description).replace("_", (String)o) };
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s;
}

String Describe_Exp_Param::porta_legato() {
    return from_string_literal(SL::porta_legato_description);
}

String Describe_Exp_Param::porta_mode() {
    return from_string_literal(SL::porta_mode_description);
}

String Describe_Exp_Param::porta_rate() {
    return from_string_literal(SL::porta_rate_description);
}

String Describe_Exp_Param::porta_velo() {
    return from_string_literal(SL::porta_velo_description);
}

String Describe_Exp_Param::ramp_rate(const int r) {
    return from_string_literal(SL::ramp_rate_description).replace("_", (String)r);
}

String Describe_Exp_Param::ramp_trig(const int r) {
    return from_string_literal(SL::ramp_trig_description).replace("_", (String)r);
}

String Describe_Exp_Param::track_input() {
    return from_string_literal(SL::track_input_description);
}

String Describe_Exp_Param::track_point(const int p, int c) {
    String s{ from_string_literal(SL::track_point_description) };
    s = s.replace("_", (String)p).replace("%", (String)c);
    return s;
}

String Describe_Exp_Param::vca_1_velo_amt() {
    return from_string_literal(SL::vca_1_velo_amt_description);
}

String Describe_Exp_Param::vca_1_volume() {
    return from_string_literal(SL::vca_1_volume_description);
}

String Describe_Exp_Param::vca_2_env_2_amt() {
    return from_string_literal(SL::vca_2_env_2_amt_description);
}

String Describe_Exp_Param::vcf_env_1_amt() {
    return from_string_literal(SL::vcf_env_1_amt_description);
}

String Describe_Exp_Param::vcf_fm_env_3_amt() {
    return from_string_literal(SL::vcf_fm_env_3_amt_description);
}

String Describe_Exp_Param::vcf_fm_osc_1_amt() {
    return from_string_literal(SL::vcf_fm_osc_1_amt_description);
}

String Describe_Exp_Param::vcf_fm_pressure_amt() {
    return from_string_literal(SL::vcf_fm_pressure_amt_description);
}

String Describe_Exp_Param::vcf_freq() {
    return from_string_literal(SL::vcf_freq_description);
}

String Describe_Exp_Param::vcf_key_track() {
    return from_string_literal(SL::vcf_key_track_description);
}

String Describe_Exp_Param::vcf_lever_ctrl() {
    return from_string_literal(SL::vcf_lever_ctrl_description);
}

String Describe_Exp_Param::vcf_pressure_amt() {
    return from_string_literal(SL::vcf_pressure_amt_description);
}

String Describe_Exp_Param::vcf_reso() {
    return from_string_literal(SL::vcf_reso_description);
}
