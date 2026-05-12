#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::osc_pitch(const int o) {
    String s{ "" };
    String osc_letter{ o == 1 ? "A" : "B" };
    s += "Sets oscillator " + osc_letter + apostrophe + "s base pitch in semitone steps.\n";
    s += "Range: 0 (C 0) to 48 (C 4). Hold down the\n";
    s += "SHIFT key when using the mouse wheel to incre-\n";
    s += "ment the pitch by one octave (12 semitones).";
    return s;
}
