#include "d_Tip__Exposed_p.h"

#include "c_SL__Tip__Exposed_p.h"

String Tip_Exposed::from_string_literal(const char8_t* sl) {
    String s{ sl };
    s = s.trimCharactersAtStart("\n");
    return s;
}

String Tip_Exposed::delay_feedback() {
    return from_string_literal(SL::delay_feedback_tip);
}

String Tip_Exposed::delay_routing() {
    return from_string_literal(SL::delay_routing_tip);
}

String Tip_Exposed::delay_time() {
    return from_string_literal(SL::delay_time_tip);
}

String Tip_Exposed::delay_hpf_freq() {
    return from_string_literal(SL::delay_hpf_freq_tip);
}

String Tip_Exposed::env_attack(bool vca) {
    String s{ from_string_literal(SL::env_attack_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "16" : "20");
    return s;
}

String Tip_Exposed::env_decay(bool vca) {
    String s{ from_string_literal(SL::env_decay_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "17" : "21");
    return s;
}

String Tip_Exposed::env_release(bool vca) {
    String s{ from_string_literal(SL::env_release_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "19" : "23");
    return s;
}

String Tip_Exposed::env_sustain(bool vca) {
    String s{ from_string_literal(SL::env_sustain_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "18" : "22");
    return s;
}

String Tip_Exposed::lpf_key_track() {
    return from_string_literal(SL::lpf_key_track_tip);
}

String Tip_Exposed::level_knob(const int k) {
    String s{ from_string_literal(SL::level_knob_tip) };
    s = s.replace("_target_name", k == 1 ? "oscillator 1" : k == 2 ? "oscillator 2" : "the white noise generator");
    s = s.replace("%%", k == 1 ? "39" : k == 2 ? "40" : "33");
    return s;
}

String Tip_Exposed::lfo_eg_mod() {
    return from_string_literal(SL::lfo_eg_mod_tip);
}

String Tip_Exposed::lfo_int() {
    return from_string_literal(SL::lfo_int_tip);
}

String Tip_Exposed::lfo_rate() {
    return from_string_literal(SL::lfo_rate_tip);
}

String Tip_Exposed::lfo_target() {
    return from_string_literal(SL::lfo_target_tip);
}

String Tip_Exposed::lfo_wave() {
    return from_string_literal(SL::lfo_wave_tip);
}

String Tip_Exposed::lpf_eg_int() {
    return from_string_literal(SL::lpf_eg_int_tip);
}

String Tip_Exposed::lpf_freq() {
    return from_string_literal(SL::lpf_freq_tip);
}

String Tip_Exposed::lpf_reso() {
    return from_string_literal(SL::lpf_reso_tip);
}

String Tip_Exposed::lpf_type() {
    return from_string_literal(SL::lpf_type_tip);
}

String Tip_Exposed::lpf_velo_amt() {
    return from_string_literal(SL::lpf_velo_amt_tip);
}

String Tip_Exposed::osc_2_pitch_eg_int() {
    return from_string_literal(SL::osc_2_pitch_eg_int_tip);
}

String Tip_Exposed::osc_2_ring_mod() {
    return from_string_literal(SL::osc_2_ring_mod_tip);
}

String Tip_Exposed::osc_2_sync() {
    return from_string_literal(SL::osc_2_sync_tip);
}

String Tip_Exposed::osc_2_x_mod_depth() {
    return from_string_literal(SL::osc_2_x_mod_depth_tip);
}

String Tip_Exposed::osc_octave(const String o) {
    String s{ from_string_literal(SL::osc_octave_tip) };
    s = s.replace("_", o);
    s = s.replace("%%", o == "1" ? "48" : "49");
    return s;
}

String Tip_Exposed::osc_pitch_fine(const String o) {
    String s{ from_string_literal(SL::osc_pitch_fine_tip) };
    s = s.replace("_", o);
    s = s.replace("%%", o == "1" ? "34" : "35");
    return s;
}

String Tip_Exposed::osc_shape(const String o) {
    String s{ from_string_literal(SL::osc_shape_tip) };
    s = s.replace("_", o);
    s = s.replace("%%", o == "1" ? "36" : "37");
    return s;
}

String Tip_Exposed::osc_wave(const String o) {
    String s{ from_string_literal(SL::osc_wave_tip) };
    s = s.replace("_", o);
    s = s.replace("%%", o == "1" ? "50" : "51");
    return s;
}

String Tip_Exposed::voice_mode_depth() {
    return from_string_literal(SL::voice_mode_depth_tip);
}
