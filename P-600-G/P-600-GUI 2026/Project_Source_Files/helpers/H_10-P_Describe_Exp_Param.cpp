#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::env_attack(bool filter) {
    String env{ filter ? "filter" : "amplifier" };
    String s{ "" };
    s += "Sets the amount of time it takes for the " + env + "\n";
    s += "envelope to rise from zero to maximum level.\n";
    s += "Range: 0 (instantaneous) to 15 (longest time)";
    return s;
}

String Describe_Exp_Param::env_decay(bool filter) {
    String env{ filter ? "filter" : "amplifier" };
    String s{ "" };
    s += "Sets the amount of time it takes for the " + env + " envelope\n";
    s += "to fall from maximum level down to the sustain level.\n";
    s += "Range: 0 (instantaneous) to 15 (longest time)";
    return s;
}

String Describe_Exp_Param::env_release(bool filter) {
    String env{ filter ? "filter" : "amplifier" };
    String s{ "" };
    s += "Sets the amount of time it takes for the " + env + "\n";
    s += "envelope to fall to zero once the note is released.\n";
    s += "Range: 0 (instantaneous) to 15 (longest time)";
    return s;
}

String Describe_Exp_Param::env_sustain(bool filter) {
    String env{ filter ? "filter" : "amplifier" };
    String s{ "" };
    s += "Sets the sustain level for the " + env + " envelope.\n";
    s += "The envelope decays to this level and stays\n";
    s += "there until the note is released.\n";
    s += "Range: 0 to 15 (maximum level)";
    return s;
}

String Describe_Exp_Param::filter_cutoff() {
    String s{ "" };
    s += "Adjusts the cutoff frequency of the 4-pole low-pass filter.\n";
    s += "Increasing the cutoff lets through higher and higher fre-\n";
    s += "quencies and makes the sound " + open_quote + "brighter." + close_quote + " Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::filter_env_amt() {
    String s{ "" };
    s += "Sets the depth of the envelope which modulates the filter\n";
    s += "cutoff frequency. Range: 0 (no modulation) to 15 (maximum depth).";
    return s;
}

String Describe_Exp_Param::filter_key_track() {
    String s{ "" };
    s += "When set to FULL, the filter cutoff frequency " + open_quote + "tracks" + close_quote + " the notes\n";
    s += "played on the keyboard, rising and falling so that all pitches have\n";
    s += "consistent brightness and loudness. When set to OFF, the cutoff\n";
    s += "frequency does not change. As you go higher up the keyboard past\n";
    s += "the cutoff frequency, the pitches are progressively duller and\n";
    s += "quieter. 1/2 selects the midrange between these two effects.";
    return s;
}

String Describe_Exp_Param::filter_reso() {
    String s{ "" };
    s += "Increasing filter resonance boosts frequencies near the\n";
    s += "cutoff frequency. At high resonance settings, the filter\n";
    s += "will self-oscillate, producing a sine wave with a pitch\n";
    s += "determined by the cutoff frequency. Range: 0 to 63.";
    return s;
}

String Describe_Exp_Param::glide() {
    String s{ "" };
    s += open_quote + "Glide" + close_quote + " is a smooth pitch transition between two consecutive notes.\n";
    s += "This knob adjusts the amount of time for the transition to complete.\n";
    s += "The actual time is dependent upon the distance between the two notes.\n";
    s += "Range: 0 (instantaneous, i.e. no glide) to 15 (longest glide time).";
    return s;
}

String Describe_Exp_Param::lfo_dest_filter() {
    String s{ "" };
    s += "Enables modulation of the filter's cutoff\n";
    s += "frequency by the low-frequency oscillator.";
    return s;
}

String Describe_Exp_Param::lfo_dest_osc_pitch() {
    String s{ "" };
    s += "Enables modulation of the frequencies of both\n";
    s += "oscillators by the low-frequency oscillator.";
    return s;
}

String Describe_Exp_Param::lfo_dest_osc_pulse_w() {
    String s{ "" };
    s += "Enables modulation of the pulse widths of both\n";
    s += "oscillators by the low-frequency oscillator.";
    return s;
}

String Describe_Exp_Param::lfo_freq() {
    String s{ "" };
    s += "Adjusts the frequency of the low-frequency oscillator.\n";
    s += "Range: 0 (~0.25 Hz) to 16 (~20 Hz)";
    return s;
}

String Describe_Exp_Param::lfo_init_amt() {
    String s{ "" };
    s += "Sets the baseline amount of modulation produced by the low-\n";
    s += "frequency oscillator when the modulation wheel is at zero.\n";
    s += "Range: 0 (no modulation) to 31 (maximum modulation)";
    return s;
}

String Describe_Exp_Param::lfo_shape() {
    String s{ "" };
    s += "Sets the low-frequency oscillator" + apostrophe + "s\n";
    s += "wave shape (square or triangle).";
    return s;
}

String Describe_Exp_Param::mixer() {
    String s{ "" };
    s += "Adjusts the ratio of the two oscillators" + apostrophe + " output to the filter.\n";
    s += "Range: 0 (only oscillator A is output) to 63 (only oscillator B).\n";
    s += "At a setting of 32, an equal mix of the two oscillators is output.";
    return s;
}

String Describe_Exp_Param::osc_pitch(const int o) {
    String s{ "" };
    String osc_letter{ o == 1 ? "A" : "B" };
    s += "Sets oscillator " + osc_letter + apostrophe + "s base pitch in semitone steps.\n";
    s += "Range: 0 (C 0) to 48 (C 4). Hold down the\n";
    s += "SHIFT key when using the mouse wheel to incre-\n";
    s += "ment the pitch by one octave (12 semitones).";
    return s;
}

String Describe_Exp_Param::osc_pulse_w(const int o) {
    String s{ "" };
    String osc_letter{ o == 1 ? "A" : "B" };
    s += "Sets the width of the pulse wave generated by oscillator " + osc_letter + ".\n";
    s += "This has no effect if the oscillator" + apostrophe + "s Wave Shape : Pulse switch\n";
    s += "is turned off. Range: 0 (narrowest) to 127 (widest). A value of\n";
    s += "64 will produce an approximately square wave. At the extremes of\n";
    s += "the range, the pulse will thin out so much as to be inaudible.";
    return s;
}

String Describe_Exp_Param::osc_a_sync() {
    String s{ "" };
    s += "When on, oscillator A is forced to follow\n";
    s += "oscillator B in " + open_quote + "hard" + close_quote + " synchronization.";
    return s;
}

String Describe_Exp_Param::osc_b_fine() {
    String s{ "" };
    s += "Raises the pitch of oscillator B by\n";
    s += "up to one semitone. Range: 0 to 127";
    return s;
}

String Describe_Exp_Param::poly_mod_dest_filter_freq() {
    String s{ "" };
    s += "Enables modulation of the filter" + apostrophe + "s cutoff\n";
    s += "frequency by the two poly-mod sources.";
    return s;
}

String Describe_Exp_Param::poly_mod_dest_osc_a_pitch() {
    String s{ "" };
    s += "Enables modulation of oscillator A" + apostrophe + "s\n";
    s += "frequency by the two poly-mod sources.";
    return s;
}

String Describe_Exp_Param::poly_mod_src_filter_env_amt() {
    String s{ "" };
    s += "Sets the degree to which the filter envelope\n";
    s += "modulates the enabled poly-mod destination(s).\n";
    s += "Range: 0 (no modulation) to 15 (maximum modulation)";
    return s;
}

String Describe_Exp_Param::poly_mod_src_osc_b_amt() {
    String s{ "" };
    s += "Sets the degree to which oscillator B" + apostrophe + "s frequency\n";
    s += "modulates the enabled poly-mod destination(s).\n";
    s += "Range: 0 (no modulation) to 127 (maximum modulation)";
    return s;
}

String Describe_Exp_Param::unisonTrack() {
    String s{ "" };
    s += "Enables one of the three unison keyboard tracking modes:\n";
    s += "Normal: Switch unison on while no keys are pressed. All 6 voices play\n";
    s += "at once at a single pitch (the lowest triggered note has priority).\n";
    s += "Chord Track: Switch unison on while holding down multiple notes.\n";
    s += "When new notes are triggered, the same note intervals are played,\n";
    s += "but with the lowest triggered new note as the root.\n";
    s += "Single Voice: Switch unison on while holding down a single note.\n";
    s += "Similar to normal unison, but only one voice plays at a time.";
    return s;
}

