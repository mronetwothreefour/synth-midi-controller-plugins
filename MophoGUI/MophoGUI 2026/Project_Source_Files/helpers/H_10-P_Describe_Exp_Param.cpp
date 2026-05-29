#include "H_10-P_Describe_Exp_Param.h"

#include "c_SL__Tip_Exposed_p.h"

String Tip_Exposed::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Tip_Exposed::arp_mode() {
    return from_string_literal(SL::arp_mode_tip);
}

String Tip_Exposed::arp_on_off() {
    return from_string_literal(SL::arp_on_off_tip);
}

String Tip_Exposed::bend_range() {
    return from_string_literal(SL::bend_range_tip);
}

String Tip_Exposed::clock_division() {
    return from_string_literal(SL::clock_division_tip);
}

String Tip_Exposed::clock_tempo() {
    return from_string_literal(SL::clock_tempo_tip);
}

String Tip_Exposed::env_3_amt() {
    return from_string_literal(SL::env_3_amt_tip);
}

String Tip_Exposed::env_3_repeat() {
    return from_string_literal(SL::env_3_repeat_tip);
}

String Tip_Exposed::env_attack(const String env) {
    return from_string_literal(SL::env_attack_tip).replace("_envelope name_", env);
}

String Tip_Exposed::env_decay(const String env) {
    return from_string_literal(SL::env_decay_tip).replace("_envelope name_", env);
}

String Tip_Exposed::env_delay(const String env) {
    return from_string_literal(SL::env_delay_tip).replace("_envelope name_", env);
}

String Tip_Exposed::env_release(const String env) {
    return from_string_literal(SL::env_release_tip).replace("_envelope name_", env);
}

String Tip_Exposed::env_sustain(const String env) {
    return from_string_literal(SL::env_sustain_tip).replace("_envelope name_", env);
}

String Tip_Exposed::env_velo_amt(const String env) {
    return from_string_literal(SL::env_velo_amt_tip).replace("_envelope name_", env);
}

String Tip_Exposed::ext_in_level() {
    return from_string_literal(SL::ext_in_level_tip);
}

String Tip_Exposed::glide_mode() {
    return from_string_literal(SL::glide_mode_tip);
}

String Tip_Exposed::knob_assign(const String knob) {
    return from_string_literal(SL::knob_assign_tip).replace("_", knob);
}

String Tip_Exposed::lfo_amt(const int lfo) {
    return from_string_literal(SL::lfo_amt_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_freq(const int lfo) {
    return from_string_literal(SL::lfo_freq_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_key_sync(const int lfo) {
    return from_string_literal(SL::lfo_key_sync_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lfo_shape(const int lfo) {
    return from_string_literal(SL::lfo_shape_tip).replace("_", (String)lfo);
}

String Tip_Exposed::lpf_env_amt() {
    return from_string_literal(SL::lpf_env_amt_tip);
}

String Tip_Exposed::lpf_fm_amt() {
    return from_string_literal(SL::lpf_fm_amt_tip);
}

String Tip_Exposed::lpf_freq() {
    return from_string_literal(SL::lpf_freq_tip);
}

String Tip_Exposed::lpf_key_amt() {
    return from_string_literal(SL::lpf_key_amt_tip);
}

String Tip_Exposed::lpf_reso() {
    return from_string_literal(SL::lpf_reso_tip);
}

String Tip_Exposed::lpf_type() {
    return from_string_literal(SL::lpf_type_tip);
}

String Tip_Exposed::midi_breath_amt() {
    return from_string_literal(SL::midi_breath_amt_tip);
}

String Tip_Exposed::midi_mod_wheel_amt() {
    return from_string_literal(SL::midi_mod_wheel_amt_tip);
}

String Tip_Exposed::midi_pedal_amt() {
    return from_string_literal(SL::midi_pedal_amt_tip);
}

String Tip_Exposed::midi_pressure_amt() {
    return from_string_literal(SL::midi_pressure_amt_tip);
}

String Tip_Exposed::midi_velocity_amt() {
    return from_string_literal(SL::midi_velocity_amt_tip);
}

String Tip_Exposed::mod_amt() {
    return from_string_literal(SL::mod_amt_tip);
}

String Tip_Exposed::noise_level() {
    return from_string_literal(SL::noise_level_tip);
}

String Tip_Exposed::note_priority() {
    return from_string_literal(SL::note_priority_tip);
}

String Tip_Exposed::osc_fine(const int o) {
    return from_string_literal(SL::osc_fine_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_glide(const int o) {
    return from_string_literal(SL::osc_glide_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_key_track(const int o) {
    return from_string_literal(SL::osc_key_track_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_mix() {
    return from_string_literal(SL::osc_mix_tip);
}

String Tip_Exposed::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_shape(const int o) {
    return from_string_literal(SL::osc_shape_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_slop() {
    return from_string_literal(SL::osc_slop_tip);
}

String Tip_Exposed::osc_sub_level(const int o) {
    return from_string_literal(SL::osc_sub_level_tip).replace("_", (String)o);
}

String Tip_Exposed::osc_sync() {
    return from_string_literal(SL::osc_sync_tip);
}

String Tip_Exposed::push_it_mode() {
    return from_string_literal(SL::push_it_mode_tip);
}

String Tip_Exposed::push_it_pitch() {
    return from_string_literal(SL::push_it_pitch_tip);
}

String Tip_Exposed::push_it_velocity() {
    return from_string_literal(SL::push_it_velocity_tip);
}

String Tip_Exposed::seq_on_off() {
    return from_string_literal(SL::seq_on_off_tip);
}

String Tip_Exposed::seq_track_dest(const String track_num) {
    return from_string_literal(SL::seq_track_dest_tip).replace("_", track_num);
}

String Tip_Exposed::seq_track_step(const String track, String step) {
    String s{ from_string_literal(SL::seq_track_step_tip_1) };
    s = s.replace("_", track);
    s = s.replace("%", step);
    if (track == "1")
        s += from_string_literal(SL::seq_track_step_tip_2);
    s += from_string_literal(SL::seq_track_step_tip_3);
    return s;
}

String Tip_Exposed::seq_trig_mode() {
    return from_string_literal(SL::seq_trig_mode_tip);
}

String Tip_Exposed::vca_env_amt() {
    return from_string_literal(SL::vca_env_amt_tip);
}

String Tip_Exposed::vca_level() {
    return from_string_literal(SL::vca_level_tip);
}

String Tip_Exposed::voice_name_char(const String c) {
    return from_string_literal(SL::voice_name_char_tip).replace("_", c);
}

String Tip_Exposed::voice_volume() {
    return from_string_literal(SL::voice_volume_tip);
}
