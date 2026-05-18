#include "H_10-P_Describe_Exp_Param.h"

#include "C_60-P_SL_EP_Descriptions.h"

String Describe_Exp_Param::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Describe_Exp_Param::arpeg_mode() {
    return from_string_literal(SL::arpeg_mode_description);
}

String Describe_Exp_Param::arpeg_on_off() {
    return from_string_literal(SL::arpeg_on_off_description);
}

String Describe_Exp_Param::bend_range() {
    return from_string_literal(SL::bend_range_description);
}

String Describe_Exp_Param::clock_division() {
    return from_string_literal(SL::clock_division_description);
}

String Describe_Exp_Param::clock_tempo() {
    return from_string_literal(SL::clock_tempo_description);
}

String Describe_Exp_Param::env_3_amt() {
    return from_string_literal(SL::env_3_amt_description);
}

String Describe_Exp_Param::env_3_repeat() {
    return from_string_literal(SL::env_3_repeat_description);
}

String Describe_Exp_Param::env_attack(const String env) {
    return from_string_literal(SL::env_attack_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::env_decay(const String env) {
    return from_string_literal(SL::env_decay_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::env_delay(const String env) {
    return from_string_literal(SL::env_delay_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::env_release(const String env) {
    return from_string_literal(SL::env_release_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::env_sustain(const String env) {
    return from_string_literal(SL::env_sustain_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::env_vel_amt(const String env) {
    return from_string_literal(SL::env_vel_amt_description).replace("_envelope name_", env);
}

String Describe_Exp_Param::ext_in_level() {
    return from_string_literal(SL::ext_in_level_description);
}

String Describe_Exp_Param::glide_mode() {
    return from_string_literal(SL::glide_mode_description);
}

String Describe_Exp_Param::knob_assign(const int knob) {
    return from_string_literal(SL::knob_assign_description).replace("_", (String)knob);
}

String Describe_Exp_Param::lfo_amt(const int lfo) {
    return from_string_literal(SL::lfo_amt_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_freq(const int lfo) {
    return from_string_literal(SL::lfo_freq_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_key_sync(const int lfo) {
    return from_string_literal(SL::lfo_key_sync_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lfo_shape(const int lfo) {
    return from_string_literal(SL::lfo_shape_description).replace("_", (String)lfo);
}

String Describe_Exp_Param::lpf_env_amt() {
    return from_string_literal(SL::lpf_env_amt_description);
}

String Describe_Exp_Param::lpf_fm_amt() {
    return from_string_literal(SL::lpf_fm_amt_description);
}

String Describe_Exp_Param::lpf_freq() {
    return from_string_literal(SL::lpf_freq_description);
}

String Describe_Exp_Param::lpf_key_amt() {
    return from_string_literal(SL::lpf_key_amt_description);
}

String Describe_Exp_Param::lpf_reso() {
    return from_string_literal(SL::lpf_reso_description);
}

String Describe_Exp_Param::lpf_type() {
    return from_string_literal(SL::lpf_type_description);
}

String Describe_Exp_Param::midi_breath_amt() {
    return from_string_literal(SL::midi_breath_amt_description);
}

String Describe_Exp_Param::midi_mod_wheel_amt() {
    return from_string_literal(SL::midi_mod_wheel_amt_description);
}

String Describe_Exp_Param::midi_pedal_amt() {
    return from_string_literal(SL::midi_pedal_amt_description);
}

String Describe_Exp_Param::midi_pressure_amt() {
    return from_string_literal(SL::midi_pressure_amt_description);
}

String Describe_Exp_Param::midi_velocity_amt() {
    return from_string_literal(SL::midi_velocity_amt_description);
}

String Describe_Exp_Param::mod_amt() {
    return from_string_literal(SL::mod_amt_description);
}

String Describe_Exp_Param::noise_level() {
    return from_string_literal(SL::noise_level_description);
}

String Describe_Exp_Param::note_priority() {
    return from_string_literal(SL::note_priority_description);
}

String Describe_Exp_Param::osc_fine(const int o) {
    return from_string_literal(SL::osc_fine_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_glide(const int o) {
    return from_string_literal(SL::osc_glide_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_key_track(const int o) {
    return from_string_literal(SL::osc_key_track_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_mix() {
    return from_string_literal(SL::osc_mix_description);
}

String Describe_Exp_Param::osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_shape(const int o) {
    return from_string_literal(SL::osc_shape_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_slop() {
    return from_string_literal(SL::osc_slop_description);
}

String Describe_Exp_Param::osc_sub_level(const int o) {
    return from_string_literal(SL::osc_sub_level_description).replace("_", (String)o);
}

String Describe_Exp_Param::osc_sync() {
    return from_string_literal(SL::osc_sync_description);
}

String Describe_Exp_Param::push_it_mode() {
    return from_string_literal(SL::push_it_mode_description);
}

String Describe_Exp_Param::push_it_pitch() {
    return from_string_literal(SL::push_it_pitch_description);
}

String Describe_Exp_Param::push_it_velocity() {
    return from_string_literal(SL::push_it_velocity_description);
}

String Describe_Exp_Param::seq_on_off() {
    return from_string_literal(SL::seq_on_off_description);
}

String Describe_Exp_Param::seq_track_dest(const int track) {
    return from_string_literal(SL::seq_track_dest_description).replace("_", String{ track + 1 });
}

String Describe_Exp_Param::seq_track_step(const int track, int step) {
    String s{ from_string_literal(SL::seq_track_step_description_1) };
    s = s.replace("_", String{ track + 1 });
    s = s.replace("%", String{ step + 1 });
    if (track == 0)
        s += from_string_literal(SL::seq_track_step_description_2);
    s += from_string_literal(SL::seq_track_step_description_3);
    return s;
}

String Describe_Exp_Param::seq_trig_mode() {
    return from_string_literal(SL::seq_trig_mode_description);
}

String Describe_Exp_Param::vca_env_amt() {
    return from_string_literal(SL::vca_env_amt_description);
}

String Describe_Exp_Param::vca_level() {
    return from_string_literal(SL::vca_level_description);
}

String Describe_Exp_Param::voice_name_char(const int c) {
    return from_string_literal(SL::voice_name_char_description).replace("_", String{ c + 1 });
}

String Describe_Exp_Param::voice_volume() {
    return from_string_literal(SL::voice_volume_description);
}
