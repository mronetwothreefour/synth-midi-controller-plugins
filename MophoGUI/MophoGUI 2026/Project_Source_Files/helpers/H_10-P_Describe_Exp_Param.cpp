#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::osc_pitch(const int o) {
    String s{ "" };
    s += "Sets oscillator " + (String)o + apostrophe + "s base pitch in semitone steps.\n";
    s += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
    s += "Hold down the SHIFT key when using the mouse wheel to\n";
    s += "increment the pitch by one octave (12 semitones).";
    return s;
}
