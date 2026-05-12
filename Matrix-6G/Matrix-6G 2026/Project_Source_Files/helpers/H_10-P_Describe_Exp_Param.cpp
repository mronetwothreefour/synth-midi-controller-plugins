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

String Describe_Exp_Param::osc_balance() {
    String s{ "" };
    s += "Sets the relative levels of the two oscillators.\n";
    s += "Range: 0 to 63. At 63, only oscillator 1 is heard.\n";
    s += "At 0, only oscillator 2 is heard. 31 is an equal mix.";
    return s;
}

String Describe_Exp_Param::osc_key_click() {
    String s{ "" };
    s += "Adds percussive punch to\n";
    s += "the start of the sound.";
    return s;
}

String Describe_Exp_Param::osc_key_track(const int o) {
    String s{ "" };
    s += "Selects how oscillator " + (String)o + " responds to incoming pitch\n";
    s += "change messages (e.g. notes played on a keyboard controller).\n";
    if (o == 1) {
        s += "KEYBD: Oscillater 1" + apostrophe + "s pitch tracks note key changes normally.\n";
        s += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
        s += "according to the settings in the portamento (aka " + open_quote + "glide" + close_quote + ") section.";
    }
    else {
        s += "OFF: Oscillater 2" + apostrophe + "s pitch will not change as notes are played.\n";
        s += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
        s += "according to the settings in the portamento (aka " + open_quote + "glide" + close_quote + ") section.\n";
        s += "KEYBD: Oscillator 2" + apostrophe + "s pitch tracks note key changes normally.";
    }
    return s;
}

String Describe_Exp_Param::osc_lever_control(const int o) {
    String s{ "" };
    s += "Selects which of the performance " + open_quote + "levers" + open_quote + "\n";
    s += "(wheel-type controllers) will modulate oscillator " + (String)o + ".\n";
    s += "OFF: Oscillator " + (String)o + " is not modulated by either lever.\n";
    s += "BEND: Pitch bend is modulated by lever 1 (pitch wheel).\n";
    s += "VIB: Vibrato amount is modulated by lever 2 (mod wheel).\n";
    s += "BOTH: Oscillator " + (String)o + " is modulated by both levers.";
    return s;
}

String Describe_Exp_Param::osc_lfo_1_fm(const int o) {
    String s{ "" };
    s += "Sets whether and to what degree LFO 1\n";
    s += "modulates the pitch of oscillator " + (String)o + ".\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the LFO waveform.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::osc_lfo_2_pwm(const int o) {
    String s{ "" };
    s += "Sets whether and to what degree LFO 2\n";
    s += "modulates the pulse width of oscillator " + (String)o + ".\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the LFO waveform.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
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
