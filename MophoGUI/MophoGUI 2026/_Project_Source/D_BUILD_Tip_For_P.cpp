#include "D_BUILD_Tip_For_P.h"

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

String Tip_For::exp_env_3_dest() {
    return exp_mod_dest() + " by envelope 3.";
}

String Tip_For::exp_env_attack(const String env) {
    return from_string_literal(SL::env_attack_tip).replace("_envelope name_", env);
}

String Tip_For::exp_env_decay(const String env) {
    return from_string_literal(SL::env_decay_tip).replace("_envelope name_", env);
}

String Tip_For::exp_env_delay(const String env) {
    return from_string_literal(SL::env_delay_tip).replace("_envelope name_", env);
}

String Tip_For::exp_env_release(const String env) {
    return from_string_literal(SL::env_release_tip).replace("_envelope name_", env);
}

String Tip_For::exp_env_sustain(const String env) {
    return from_string_literal(SL::env_sustain_tip).replace("_envelope name_", env);
}

String Tip_For::exp_env_velo_amt(const String env) {
    return from_string_literal(SL::env_velo_amt_tip).replace("_envelope name_", env);
}

String Tip_For::exp_flex_knob(const int knob) {
    return from_string_literal(SL::flex_knob_tip).replace("_", (String)knob);
}

String Tip_For::exp_lfo_amt(const int lfo) {
    return from_string_literal(SL::lfo_amt_tip).replace("_", (String)lfo);
}

String Tip_For::exp_lfo_dest(const int lfo) {
    return exp_mod_dest() + " by LFO " + (String)lfo + ".";
}

String Tip_For::exp_lfo_freq(const int lfo) {
    return from_string_literal(SL::lfo_freq_tip).replace("_", (String)lfo);
}

String Tip_For::exp_lfo_key_sync(const int lfo) {
    return from_string_literal(SL::lfo_key_sync_tip).replace("_", (String)lfo);
}

String Tip_For::exp_lfo_shape(const int lfo) {
    return from_string_literal(SL::lfo_shape_tip).replace("_", (String)lfo);
}

String Tip_For::exp_mod_amt() {
    return from_string_literal(SL::mod_amt_tip);
}

String Tip_For::exp_mod_dest() {
    return "Selects the target parameter for modulation";
}

String Tip_For::exp_mod_src() {
    return "Selects the modulation source.";
}

String Tip_For::exp_osc_fine(const int o) {
    return from_string_literal(SL::osc_fine_tip).replace("_", (String)o);
}

String Tip_For::exp_osc_glide(const int o) {
    return from_string_literal(SL::osc_glide_tip).replace("_", (String)o);
}

String Tip_For::exp_osc_key_track(const int o) {
    return from_string_literal(SL::osc_key_track_tip).replace("_", (String)o);
}

String Tip_For::exp_osc_pitch(const int o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", (String)o);
}

String Tip_For::exp_osc_shape(const int o) {
    return from_string_literal(SL::osc_shape_tip).replace("_", (String)o);
}

String Tip_For::exp_osc_sub_level(const int o) {
    return from_string_literal(SL::osc_sub_level_tip).replace("_", (String)o);
}

String Tip_For::exp_seq_track_dest(const int track_num) {
    auto tip = from_string_literal(SL::seq_track_dest_tip_1).replace("_", String{ track_num });
    if (track_num == 2 || track_num == 4) {
        tip += "\n";
        tip += from_string_literal(SL::seq_track_dest_tip_2).
            replace("_", String{ track_num - 1 }).
            replace("^", String{ track_num });
    }
    return tip;
}

String Tip_For::exp_seq_track_step(const int track, int step) {
    String s{ from_string_literal(SL::seq_track_step_tip_1) };
    s = s.replace("_", (String)track);
    s = s.replace("%", (String)step);
    if (track == 1)
        s += from_string_literal(SL::seq_track_step_tip_2);
    s += from_string_literal(SL::seq_track_step_tip_3);
    return s;
}

String Tip_For::exp_voice_name_char(const int c) {
    return from_string_literal(SL::voice_name_char_tip).replace("_", (String)c);
}

String BUILD::Tip_For::knob_text_editor(const String& name) {
    if (name == NAME::lbl_bend_range)
        return from_string_literal(SL::knob_txt_edit_bend_range_tip);
    if (name == NAME::lbl_clock_tempo)
        return from_string_literal(SL::knob_txt_edit_clock_tempo_tip);
    if (name == NAME::lbl_lfo_freq)
        return from_string_literal(SL::knob_txt_edit_lfo_freq_tip);
    if (name == NAME::lbl_lpf_freq)
        return from_string_literal(SL::knob_txt_edit_lpf_freq_tip);
    if (name == NAME::lbl_osc_fine)
        return from_string_literal(SL::knob_txt_edit_osc_fine_tip);
    if (name == NAME::lbl_osc_pitch)
        return from_string_literal(SL::knob_txt_edit_osc_pitch_tip);
    if (name == NAME::lbl_osc_shape)
        return from_string_literal(SL::knob_txt_edit_osc_shape_tip);
    if (name == NAME::lbl_osc_slop)
        return from_string_literal(SL::knob_txt_edit_osc_slop_tip);
    if (name == NAME::lbl_seq_step)
        return from_string_literal(SL::knob_txt_edit_seq_step_tip);
    if (name == NAME::lbl_seq_step_trk_1)
        return from_string_literal(SL::knob_txt_edit_seq_step_tip) + "\n" +
            from_string_literal(SL::knob_txt_edit_seq_step_track_1_tip);
    if (name == NAME::lbl_s_8_bit_int)
        return from_string_literal(SL::knob_txt_edit_s_8_bit_int_tip);
    if (name == NAME::lbl_u_7_bit_int)
        return from_string_literal(SL::knob_txt_edit_u_7_bit_int_tip);
    return {};
}
