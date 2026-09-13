#include "D_BUILD_Tip_For_P.h"

#include <JuceHeader.h>

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"

using namespace BUILD;

std::string Tip_For::exp_env_stage(const unsigned int env, const unsigned int stage)
{
    String s;
    switch (stage) {
    case 0: s = from_SL(SL::env_delay_tip); break;
    case 1: s = from_SL(SL::env_attack_tip); break;
    case 2: s = from_SL(SL::env_decay_tip); break;
    case 3: s = from_SL(SL::env_sustain_tip); break;
    case 4: s = from_SL(SL::env_release_tip); break;
    default: s = "error"; break;
    }
    return s.replace("_", (String)env).toStdString();
}

std::string Tip_For::exp_env_amp(const unsigned int e) {
    String s{ from_SL(SL::env_amp_tip) };
    return s.replace("_", (String)e).toStdString();
}

std::string Tip_For::exp_env_lfo_1_trig(const unsigned int e) {
    String s{ from_SL(SL::env_lfo_1_trig_tip) };
    return s.replace("_", (String)e).toStdString();
}

std::string Tip_For::exp_env_mode(const unsigned int e) {
    String s{ from_SL(SL::env_mode_tip) };
    return s.replace("_", (String)e).toStdString();
}

std::string Tip_For::exp_env_trig_mode(const unsigned int e) {
    String s{ from_SL(SL::env_trig_mode_tip) };
    return s.replace("_", (String)e).toStdString();
}

std::string Tip_For::exp_env_velo_amt(const unsigned int e) {
    String s{ from_SL(SL::env_velo_amt_tip) };
    return s.replace("_", (String)e).toStdString();
}

std::string Tip_For::exp_lfo_amp(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_amp_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_lag(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_lag_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_ramp_amt(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_ramp_amt_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_retrig_point(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_retrig_point_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_sample_source(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_sample_source_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_speed(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_speed_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_trig_mode(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_trig_mode_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_lfo_wave_type(const unsigned int lfo) {
    String s{ from_SL(SL::lfo_wave_type_tip) };
    return s.replace("_", (String)lfo).toStdString();
}

std::string Tip_For::exp_osc_key_track(const unsigned int o) {
    if(o == 1)
        return from_SL(SL::osc_1_key_track_tip);
    return from_SL(SL::osc_2_key_track_tip);
}

std::string Tip_For::exp_osc_lever_control(const unsigned int o) {
    String s{ from_SL(SL::osc_lever_control_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_lfo_1_fm(const unsigned int o) {
    String s{ from_SL(SL::osc_lfo_1_fm_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_lfo_2_pwm(const unsigned int o) {
    String s{ from_SL(SL::osc_lfo_2_pwm_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_pitch(const unsigned int o) {
    String s{ from_SL(SL::osc_pitch_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_pulse_w(const unsigned int o) {
    String s{ from_SL(SL::osc_pulse_w_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_saw_tri(const unsigned int o) {
    String s{ from_SL(SL::osc_saw_tri_tip) };
    return s.replace("_", (String)o).toStdString();
}

std::string Tip_For::exp_osc_type(const unsigned int o) {
    String s{ from_SL(SL::osc_type_tip) };
    s = s.replace("_", (String)o);
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s.toStdString();
}

std::string Tip_For::exp_ramp_rate(const unsigned int r) {
    String s{ from_SL(SL::ramp_rate_tip) };
    return s.replace("_", (String)r).toStdString();
}

std::string Tip_For::exp_ramp_trig(const unsigned int r) {
    String s{ from_SL(SL::ramp_trig_tip) };
    return s.replace("_", (String)r).toStdString();
}

std::string Tip_For::exp_track_point(const int p, int c) {
    String s{ from_SL(SL::track_point_tip) };
    return s.replace("_", (String)p).replace("%", (String)c).toStdString();
}
