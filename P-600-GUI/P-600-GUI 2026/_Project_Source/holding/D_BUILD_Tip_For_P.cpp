#include "D_BUILD_Tip_For_P.h"

#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Widget_P.h"

using namespace BUILD;

String Tip_For::exp_env_attack(bool filter) {
    return from_string_literal(SL::env_attack_tip).replace("_type of_",
                               filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_decay(bool filter) {
    return from_string_literal(SL::env_decay_tip).replace("_type of_",
                               filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_release(bool filter) {
    return from_string_literal(SL::env_release_tip).replace("_type of_",
                               filter ? "filter" : "amplifier");
}

String Tip_For::exp_env_sustain(bool filter) {
    return from_string_literal(SL::env_sustain_tip).replace("_type of_",
                               filter ? "filter" : "amplifier");
}

String Tip_For::exp_osc_pitch(const String o) {
    return from_string_literal(SL::osc_pitch_tip).replace("_", o);
}

String Tip_For::exp_osc_pulse_w(const String o) {
    return from_string_literal(SL::osc_pulse_w_tip).replace("_", o);
}

String Tip_For::exp_osc_pulse(const String o) {
    return "When on, oscillator " + o + " outputs a pulse wave.";
}

String Tip_For::exp_osc_saw(const String o) {
    return "When on, oscillator " + o + " outputs a sawtooth wave.";
}

String Tip_For::exp_osc_tri(const String o) {
    return "When on, oscillator " + o + " outputs a triangle wave.";
}
