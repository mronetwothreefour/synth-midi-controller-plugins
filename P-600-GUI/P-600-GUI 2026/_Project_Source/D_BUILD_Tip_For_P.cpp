#include "D_BUILD_Tip_For_P.h"

#include <JuceHeader.h>

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"

using namespace BUILD;

std::string BUILD::Tip_For::exp_env_stage(const unsigned int stage, bool filter) {
    String s;
    switch (stage) {
    case 0: s = from_SL(SL::env_attack_tip); break;
    case 1: s = from_SL(SL::env_decay_tip); break;
    case 2: s = from_SL(SL::env_sustain_tip); break;
    case 3: s = from_SL(SL::env_release_tip); break;
    default: s = "error"; break;
    }
    return s.replace("_type of_", filter ? "filter" : "amplifier").toStdString();
}

std::string Tip_For::exp_osc_pitch(const std::string o) {
    String s{ from_SL(SL::osc_pitch_tip) };
    return s.replace("_", o).toStdString();
}

std::string Tip_For::exp_osc_pulse_w(const std::string o) {
    String s{ from_SL(SL::osc_pulse_w_tip) };
    return s.replace("_", o).toStdString();
}

std::string Tip_For::exp_osc_pulse(const std::string o) {
    return "When on, oscillator " + o + " outputs a pulse wave.";
}

std::string Tip_For::exp_osc_saw(const std::string o) {
    return "When on, oscillator " + o + " outputs a sawtooth wave.";
}

std::string Tip_For::exp_osc_tri(const std::string o) {
    return "When on, oscillator " + o + " outputs a triangle wave.";
}
