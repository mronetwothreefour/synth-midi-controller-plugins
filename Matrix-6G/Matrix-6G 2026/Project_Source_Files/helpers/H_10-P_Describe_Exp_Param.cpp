#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::osc_1_sync() {
    String s{ "" };
    s += "Selects whether and to what degree oscillator 1" + apostrophe + "s\n";
    s += "waveform is synchronized with oscillator 2" + apostrophe + "s.";
    return s;
}

String Describe_Exp_Param::osc_2_detune() {
    String s{ "" };
    s += "Slightly lowers or raises Oscillator 2" + apostrophe + "s pitch.\n";
    s += "Range -31 to +31 (-/+ ~25 cents). 0 is no detune.\n";
    s += "NOTE: Negative values cannot be assigned to indi-\n";
    s += "vidual parameters via Quick Patch Edit. Use the\n";
    s += "PUSH button to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::osc_pitch(const int o) {
    String s{ "" };
    s += "Sets oscillator " + (String)o + apostrophe + "s base pitch in semitone steps.\n";
    s += "Range: 0 (C 0) to 63 (D# 5). Hold down the\n";
    s += "SHIFT key when using the mouse wheel to incre-\n";
    s += "ment the pitch by one octave (12 semitones).";
    return s;
}

String Describe_Exp_Param::osc_pulse_w(const int o) {
    String s{ "" };
    s += "Sets the width of oscillator " + (String)o + apostrophe + "s\n";
    s += "wave when its type is set to pulse.\n";
    s += "Range: 0 (very wide) to 63 (very narrow).\n";
    s += "A value of 31 produces a square wave.";
    return s;
}

String Describe_Exp_Param::osc_saw_tri(const int o) {
    String s{ "" };
    s += "Sets the shape of oscillator " + (String)o + "\n";
    s += "when its type is set to wave.\n";
    s += "Range: 0 (sawtooth) to 63 (triangle).\n";
    s += "Intermediate values produce a blend\n";
    s += "of the two shapes.";
    return s;
}

String Describe_Exp_Param::osc_type(const int o) {
    String s{ "" };
    s += "Selects oscillator " + (String)o + apostrophe + "s wave type.\n";
    s += "OFF: The oscillator produces no sound.\n";
    s += "PULSE: Set the width of the pulse below.\n";
    s += "WAVE: Set the shape of the wave below.\n";
    s += "BOTH: A blend of pulse and wave.";
    if (o == 2)
        s += "\nNOISE: White noise (oscillator 2 only).";
    return s;
}
