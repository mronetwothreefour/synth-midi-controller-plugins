#include "D_BUILD_Tip_P.h"

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

String Tip::exp_delay_feedback() {
    return from_string_literal(SL::delay_feedback_tip);
}

String Tip::exp_delay_routing() {
    return from_string_literal(SL::delay_routing_tip);
}

String Tip::exp_delay_time() {
    return from_string_literal(SL::delay_time_tip);
}

String Tip::exp_delay_hpf_freq() {
    return from_string_literal(SL::delay_hpf_freq_tip);
}

String Tip::exp_env_attack(bool vca) {
    String s{ from_string_literal(SL::env_attack_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "16" : "20");
    return s;
}

String Tip::exp_env_decay(bool vca) {
    String s{ from_string_literal(SL::env_decay_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "17" : "21");
    return s;
}

String Tip::exp_env_release(bool vca) {
    String s{ from_string_literal(SL::env_release_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "19" : "23");
    return s;
}

String Tip::exp_env_sustain(bool vca) {
    String s{ from_string_literal(SL::env_sustain_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "18" : "22");
    return s;
}

String Tip::exp_lpf_key_track() {
    return from_string_literal(SL::lpf_key_track_tip);
}

String Tip::exp_level_knob(const int k) {
    String s{ from_string_literal(SL::level_knob_tip) };
    s = s.replace("_target_name", k == 1 ? "oscillator 1" : k == 2 ? "oscillator 2" : "the white noise generator");
    s = s.replace("%%", k == 1 ? "39" : k == 2 ? "40" : "33");
    return s;
}

String Tip::exp_lfo_eg_mod() {
    return from_string_literal(SL::lfo_eg_mod_tip);
}

String Tip::exp_lfo_int() {
    return from_string_literal(SL::lfo_int_tip);
}

String Tip::exp_lfo_rate() {
    return from_string_literal(SL::lfo_rate_tip);
}

String Tip::exp_lfo_target() {
    return from_string_literal(SL::lfo_target_tip);
}

String Tip::exp_lfo_wave() {
    return from_string_literal(SL::lfo_wave_tip);
}

String Tip::exp_lpf_eg_int() {
    return from_string_literal(SL::lpf_eg_int_tip);
}

String Tip::exp_lpf_freq() {
    return from_string_literal(SL::lpf_freq_tip);
}

String Tip::exp_lpf_reso() {
    return from_string_literal(SL::lpf_reso_tip);
}

String Tip::exp_lpf_type() {
    return from_string_literal(SL::lpf_type_tip);
}

String Tip::exp_lpf_velo_amt() {
    return from_string_literal(SL::lpf_velo_amt_tip);
}

String Tip::exp_osc_2_pitch_eg_int() {
    return from_string_literal(SL::osc_2_pitch_eg_int_tip);
}

String Tip::exp_osc_2_ring_mod() {
    return from_string_literal(SL::osc_2_ring_mod_tip);
}

String Tip::exp_osc_2_sync() {
    return from_string_literal(SL::osc_2_sync_tip);
}

String Tip::exp_osc_2_xmod_depth() {
    return from_string_literal(SL::osc_2_x_mod_depth_tip);
}

String Tip::exp_osc_octave(const int o) {
    String s{ from_string_literal(SL::osc_octave_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "48" : "49");
    return s;
}

String Tip::exp_osc_pitch_fine(const int o) {
    String s{ from_string_literal(SL::osc_pitch_fine_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "34" : "35");
    return s;
}

String Tip::exp_osc_shape(const int o) {
    String s{ from_string_literal(SL::osc_shape_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "36" : "37");
    return s;
}

String Tip::exp_osc_wave(const int o) {
    String s{ from_string_literal(SL::osc_wave_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "50" : "51");
    return s;
}

String Tip::exp_voice_mode_depth() {
    return from_string_literal(SL::voice_mode_depth_tip);
}

String BUILD::Tip::knob_txt_editor(const String& name/*, Tree_Aux_Voice_P& avp*/) {
	if (name == NAME::lbl_lfo_rate) {
        //auto synced = avp.lfo_sync_bpm_on();
        return from_string_literal(/*synced ? SL::knob_txt_edit_lfo_synced_tip :
            */SL::knob_txt_edit_lfo_unsynced_tip);
    }
    if (name == NAME::lbl_lpf_eg_int)
        return from_string_literal(SL::knob_txt_lpf_eg_int_tip);
    if (name == NAME::lbl_osc_2_pitch_eg_int)
        return from_string_literal(SL::knob_txt_edit_osc_2_pitch_eg_int_tip);
    if (name == NAME::lbl_osc_pitch_fine)
        return from_string_literal(SL::knob_txt_edit_osc_pitch_fine_tip);
    if (name == NAME::lbl_u_10_bit_int)
        return from_string_literal(SL::knob_txt_edit_u_10_bit_int_tip);
    if (name == NAME::lbl_voice_mode_depth) {
        //switch (avp.voice_mode())
        //{
        //case ENUM::Voice_Mode::poly:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_0_tip);
        //case ENUM::Voice_Mode::duo:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
        //case ENUM::Voice_Mode::unison:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
        //case ENUM::Voice_Mode::mono:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_3_tip);
        //case ENUM::Voice_Mode::chord:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_4_tip);
        //case ENUM::Voice_Mode::delay:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_5_tip);
        //case ENUM::Voice_Mode::arp:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_6_tip);
        //case ENUM::Voice_Mode::sidechain:
        //    return from_string_literal(SL::knob_txt_edit_voice_mode_7_tip);
        //default:
        //    return "error";
        //}
    }
    return {};
}
