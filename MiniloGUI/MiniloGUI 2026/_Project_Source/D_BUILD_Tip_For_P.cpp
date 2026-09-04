#include "D_BUILD_Tip_For_P.h"

#include "C_ENUM_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;
using namespace ENUM;

String Tip_For::exp_env_attack(bool vca) {
    String s{ from_string_literal(SL::env_attack_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "16" : "20");
    return s;
}

String Tip_For::exp_env_decay(bool vca) {
    String s{ from_string_literal(SL::env_decay_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "17" : "21");
    return s;
}

String Tip_For::exp_env_release(bool vca) {
    String s{ from_string_literal(SL::env_release_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "19" : "23");
    return s;
}

String Tip_For::exp_env_sustain(bool vca) {
    String s{ from_string_literal(SL::env_sustain_tip) };
    s = s.replace("_ ", vca ? "VCA " : "");
    s = s.replace("%%", vca ? "18" : "22");
    return s;
}

String Tip_For::exp_level_knob(const int k) {
    String s{ from_string_literal(SL::level_knob_tip) };
    s = s.replace("_target_name", k == 1 ? "oscillator 1" : k == 2 ? "oscillator 2" : "the white noise generator");
    s = s.replace("%%", k == 1 ? "39" : k == 2 ? "40" : "33");
    return s;
}

String Tip_For::exp_osc_octave(const int o) {
    String s{ from_string_literal(SL::osc_octave_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "48" : "49");
    return s;
}

String Tip_For::exp_osc_pitch_fine(const int o) {
    String s{ from_string_literal(SL::osc_pitch_fine_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "34" : "35");
    return s;
}

String Tip_For::exp_osc_shape(const int o) {
    String s{ from_string_literal(SL::osc_shape_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "36" : "37");
    return s;
}

String Tip_For::exp_osc_wave(const int o) {
    String s{ from_string_literal(SL::osc_wave_tip) };
    s = s.replace("_", (String)o);
    s = s.replace("%%", o == 1 ? "50" : "51");
    return s;
}

String Tip_For::knob_txt_editor(const String& n, Aux_Voice_Params& avp) {
	if (n == NAME::knob_lfo_rate) {
        auto synced = avp.lfo_sync_bpm_on();
        return from_string_literal(synced ? SL::knob_txt_edit_lfo_synced_tip :
                                            SL::knob_txt_edit_lfo_unsynced_tip);
    }
    if (n == NAME::knob_lpf_eg_int)
        return from_string_literal(SL::knob_txt_lpf_eg_int_tip);
    if (n == NAME::knob_osc_2_pitch_eg_int)
        return from_string_literal(SL::knob_txt_edit_osc_2_pitch_eg_int_tip);
    if (n == NAME::knob_osc_pitch_fine)
        return from_string_literal(SL::knob_txt_edit_osc_pitch_fine_tip);
    if (n == NAME::knob)
        return from_string_literal(SL::knob_txt_edit_u_10_bit_int_tip);
    if (n == NAME::knob_voice_mode_depth) {
        auto mode = Voice_Mode(avp.voice_mode());
        switch (mode)
        {
        case Voice_Mode::poly:
            return from_string_literal(SL::knob_txt_edit_voice_mode_0_tip);
        case Voice_Mode::duo:
            return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
        case Voice_Mode::unison:
            return from_string_literal(SL::knob_txt_edit_voice_mode_1_2_tip);
        case Voice_Mode::mono:
            return from_string_literal(SL::knob_txt_edit_voice_mode_3_tip);
        case Voice_Mode::chord:
            return from_string_literal(SL::knob_txt_edit_voice_mode_4_tip);
        case Voice_Mode::delay:
            return from_string_literal(SL::knob_txt_edit_voice_mode_5_tip);
        case Voice_Mode::arp:
            return from_string_literal(SL::knob_txt_edit_voice_mode_6_tip);
        case Voice_Mode::sidechain:
            return from_string_literal(SL::knob_txt_edit_voice_mode_7_tip);
        default:
            return "error";
        }
    }
    return {};
}
