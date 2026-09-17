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

std::string Tip_For::exp_osc_key_track(const unsigned int o) {
    if(o == 1)
        return from_SL(SL::osc_1_key_track_tip);
    return from_SL(SL::osc_2_key_track_tip);
}

std::string Tip_For::exp_osc_type(const unsigned int o) {
    String s{ from_SL(SL::osc_type_tip) };
    s = s.replace("_", (String)o);
    if (o == 1)
        s = s.upToLastOccurrenceOf("\n", false, false);
    return s.toStdString();
}

std::string Tip_For::exp_track_point(const int p, int c) {
    String s{ from_SL(SL::track_point_tip) };
    return s.replace("_", (String)p).replace("%", (String)c).toStdString();
}
