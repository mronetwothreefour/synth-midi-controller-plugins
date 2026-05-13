#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::bend_range() {
    String s{ "" };
    s += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    s += "messages can raise or lower the pitches of the oscillators.\n";
    s += "Range: 0 (no pitch bend) to +/-12 semitones.";
    return s;
}

String Describe_Exp_Param::glide_mode() {
    String s{ "" };
    s += "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
    s += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
    s += "The Auto modes only apply glide when a note is played legato\n";
    s += "(i.e. a new note is triggered before the previous note is released).";
    return s;
}

String Describe_Exp_Param::osc_fine(const int o) {
    String s{ "" };
    s += "Sets oscillator " + (String)o + apostrophe + "s glide (portamento) rate.\n";
    s += "Range: 0 (instantaneous) to 127 (very slow)";
    return s;
}

String Describe_Exp_Param::osc_glide(const int o) {
    String s{ "" };
    s += "Fine tunes oscillator " + (String)o + apostrophe + "s base pitch.\n";
    s += "Range: -50 cents to +50 cents.\n";
    s += "0 = no detuning (centered).";
    return s;
}

String Describe_Exp_Param::osc_key_track(const int o) {
    String s{ "" };
    s += "Turns keyboard tracking for oscillator " + (String)o + "\n";
    s += "on or off. When turned off, the oscillator\n";
    s += "always produces its base pitch, ignoring\n";
    s += "the pitch of incoming MIDI note messages.";
    return s;
}

String Describe_Exp_Param::osc_pitch(const int o) {
    String s{ "" };
    s += "Sets oscillator " + (String)o + apostrophe + "s base pitch in semitone steps.\n";
    s += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
    s += "Hold down the SHIFT key when using the mouse wheel to\n";
    s += "increment the pitch by one octave (12 semitones).";
    return s;
}

String Describe_Exp_Param::osc_shape(const int o) {
    String s{ "" };
    s += "Selects oscillator " + (String)o + apostrophe + "s wave shape.\n";
    s += "Hold down a number on the keyboard and click\n";
    s += "the knob to jump directly to a wave shape:\n";
    s += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
    s += "3 = Sawtooth / Triangle Mixture;\n";
    s += "4 = Square (a Pulse with width 50).";
    return s;
}

String Describe_Exp_Param::osc_slop() {
    String s{ "" };
    s += "Introduces a subtle amount of random oscillator\n";
    s += "pitch drift for a " + open_quote + "vintage analog" + close_quote + " sound.\n";
    s += "Range: 0 to 5.";
    return s;
}

String Describe_Exp_Param::osc_sub_level(const int o) {
    String s{ "" };
    s += "Sets the level of sub-oscillator " + (String)o + ",\n";
    s += "which generates a square wave pitched\n";
    s += "one octave lower than oscillator " + (String)o + ".\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::osc_sync() {
    String s{ "" };
    s += "Turns hard oscillator sync on or off. When\n";
    s += "turned on, every time oscillator 2 resets\n";
    s += "it forces oscillator 1 to reset as well.";
    return s;
}
