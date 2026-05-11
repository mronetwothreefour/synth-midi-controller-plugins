#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::osc_pitch_fine(const int o) {
    String s{ "" };
    String osc_letter{ o == 1 ? "A" : "B" };
    s += "Fine tunes the pitch of oscillator " + (String)o + "\n";
    s += "in increments of 1 cent (.01 semitone).\n";
    s += "Key modifiers for incrementing with the\n";
    s += "mouse wheel: SHIFT = 10 cent increments;\n";
    s += "CTRL = 100 cent increments; ALT = restrict\n";
    s += "to exact semitones (i.e. 100, 200, 300, ...).\n";
    s += "Transmits on CC #" + String(0 == 1 ? 34 : 35) + ". Range: -1200 to +1200.";
    return s;
}
