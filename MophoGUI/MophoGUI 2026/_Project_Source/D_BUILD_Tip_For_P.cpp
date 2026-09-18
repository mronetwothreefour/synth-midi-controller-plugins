#include "D_BUILD_Tip_For_P.h"

#include <JuceHeader.h>

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

std::string Tip_For::exp_env_3_dest() {
    return exp_mod_dest() + " by envelope 3.";
}

std::string BUILD::Tip_For::exp_env_stage(const std::string env, const unsigned int stage) {
    String s;
    switch (stage) {
    case 0: s = from_SL(SL::env_delay_tip); break;
    case 1: s = from_SL(SL::env_attack_tip); break;
    case 2: s = from_SL(SL::env_decay_tip); break;
    case 3: s = from_SL(SL::env_sustain_tip); break;
    case 4: s = from_SL(SL::env_release_tip); break;
    default: s = "error"; break;
    }
    return s.replace("_envelope name_", env).toStdString();
}

std::string BUILD::Tip_For::exp_env_velo_amt(const std::string env) {
    String s{ from_SL(SL::env_velo_amt_tip) };
    return s.replace("_envelope name_", env).toStdString();
}

std::string BUILD::Tip_For::exp_lfo_dest(const int n) {
    auto lfo = " by LFO " + (String)n + ".";
    return exp_mod_dest() + lfo.toStdString();
}

std::string Tip_For::exp_mod_amt() {
    return from_SL(SL::mod_amt_tip);
}

std::string Tip_For::exp_mod_dest() {
    return "Selects the target parameter for modulation";
}

std::string Tip_For::exp_mod_src() {
    return "Selects the modulation source.";
}

std::string Tip_For::exp_seq_track_dest(const unsigned int track_num) {
    auto s = String{ from_SL_replace_num(SL::seq_track_dest_tip_1, track_num) };
    if (track_num % 2 == 0) {
        s += "\n" + String{ from_SL(SL::seq_track_dest_tip_2) };
        s.replace("_", String{ track_num - 1 });
        s.replace("^", String{ track_num });
    }
    return s.toStdString();
}

std::string Tip_For::exp_seq_track_step(const unsigned int track, int step) {
    String s{ from_SL(SL::seq_track_step_tip_1) };
    s = s.replace("_", (String)track);
    s = s.replace("%", (String)step);
    if (track == 1)
        s += String{ from_SL(SL::seq_track_step_tip_2) };
    s += String{ from_SL(SL::seq_track_step_tip_3) };
    return s.toStdString();
}
