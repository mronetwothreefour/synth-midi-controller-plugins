#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::arpeg_mode() {
    String s{ "" };
    s += "Sets the order in which the arpeggiator cs notes.\n";
    s += "Assign mode: notes are triggered in the order they were struck.";
    return s;
}

String Describe_Exp_Param::arpeg_on_off() {
    String s{ "" };
    s += "Turns the Mopho" + apostrophe + "s arpeggiator on and off.\n";
    s += "Turning this on will turn off the sequencer.";
    return s;
}

String Describe_Exp_Param::bend_range() {
    String s{ "" };
    s += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    s += "messages can raise or lower the pitches of the oscillators.\n";
    s += "Range: 0 (no pitch bend) to +/-12 semitones.";
    return s;
}

String Describe_Exp_Param::clock_division() {
    String s{ "" };
    s += "Sets the rate at which the sequencer and\n";
    s += "arpeggiator advance, relative to the tempo.";
    return s;
}

String Describe_Exp_Param::clock_tempo() {
    String s{ "" };
    s += "Sets the tempo (in beats per minute)\n";
    s += "for the sequencer and the arpeggiator.\n";
    s += "Range: 30 to 250 BPM.";
    return s;
}

String Describe_Exp_Param::env_3_amt() {
    String s{ "" };
    s += "Sets the degree to which envelope 3\n";
    s += "modulates the destination parameter.\n";
    s += "Negative values invert the envelope.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::env_3_repeat() {
    String s{ "" };
    s += "When repeat is on, envelope 3 loops through\n";
    s += "its delay, attack, decay, and sustain segments\n";
    s += "for as long as the envelope is gated on.";
    return s;
}

String Describe_Exp_Param::env_attack(const String env) {
    String s{ "" };
    s += "Sets the length of " + env + apostrophe + "s attack segment\n";
    s += "(the amount of time it takes for the envelope" + apostrophe + "s\n";
    s += "level to rise from minimum to maximum).\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::env_decay(const String env) {
    String s{ "" };
    s += "Sets the length of " + env + apostrophe + "s decay segment\n";
    s += "(the amount of time it takes for the envelope" + apostrophe + "s\n";
    s += "level to fall from maximum to the sustain level).\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::env_delay(const String env) {
    String s{ "" };
    s += "Sets the length of " + env + apostrophe + "s delay segment\n";
    s += "(the amount of time that passes after the envelope\n";
    s += "is triggered before its attack segment begins).\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::env_release(const String env) {
    String s{ "" };
    s += "Sets the length of " + env + apostrophe + "s release segment\n";
    s += "(the amount of time it takes to fall from the sustain\n";
    s += "level down to minimum once the envelope is gated off).\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::env_sustain(const String env) {
    String s{ "" };
    s += "Sets " + env + apostrophe + "s sustain level (once the\n";
    s += "decay segment completes, the envelope stays\n";
    s += "at this level until it is gated off).\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::env_vel_amt(const String env) {
    String s{ "" };
    s += "Sets the degree to which MIDI note velocity\n";
    s += "modulates the amplitude of " + env + ".\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::ext_in_level() {
    String s{ "" };
    s += "Sets the level of external audio\n";
    s += "input sent into the low-pass filter.\n";
    s += "When nothing is connected to audio in,\n";
    s += "this controls the level of feedback\n";
    s += "from the left audio output.\n";
    s += "Range: 0 to 127.";
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

String Describe_Exp_Param::knob_assign(const int knob) {
    String s{ "" };
    s += "Selects a target parameter for\n";
    s += "assignable hardware knob " + (String)knob + ".";
    return s;
}

String Describe_Exp_Param::lfo_amt(const int lfo) {
    String s{ "" };
    s += "Sets the degree to which LFO " + (String)lfo + "\n";
    s += "modulates the destination parameter.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::lfo_freq(const int lfo_num) {
    String lfo{ lfo_num };
    String s{ "" };
    s += "Sets LFO " + lfo + apostrophe + "s cycle speed. Range: 0 to 166.\n";
    s += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
    s += "From 90 to 150, LFO " + lfo + " has a pitched frequency, increasing\n";
    s += "in semitone steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
    s += "Above 150, LFO " + lfo + " is synced with the step sequencer,\n";
    s += "displayed as [number of LFO cycles] : [length in steps].";
    return s;
}

String Describe_Exp_Param::lfo_key_sync(const int lfo) {
    String s{ "" };
    s += "When on, LFO " + (String)lfo + apostrophe + "s cycle will reset\n";
    s += "each time a new note is played.";
    return s;
}

String Describe_Exp_Param::lfo_shape(const int lfo) {
    String s{ "" };
    s += "Selects LFO " + (String)lfo + apostrophe + "s wave shape.";
    return s;
}

String Describe_Exp_Param::lpf_env_amt() {
    String s{ "" };
    s += "Sets the degree to which the LPF envelope\n";
    s += "modulates the filter" + apostrophe + "s cutoff frequency.\n";
    s += "Negative values invert the envelope.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::lpf_fm_amt() {
    String s{ "" };
    s += "Sets the degree to which oscillator 1 modulates\n";
    s += "the low-pass filter" + apostrophe + "s cutoff frequency. This is\n";
    s += "useful for generating bell-like sounds.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::lpf_freq() {
    String s{ "" };
    s += "Sets the base cutoff frequency for the low-pass filter\n";
    s += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
    s += "Hold down the SHIFT key when using the mouse wheel to\n";
    s += "increment the frequency by one octave (12 semitones).";
    return s;
}

String Describe_Exp_Param::lpf_keyAmount() {
    String s{ "" };
    s += "Sets the amount by which keyboard (MIDI) notes\n";
    s += "will shift the low-pass filter" + apostrophe + "s cutoff frequency.\n";
    s += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
    s += "semitone for each note. At 32, cutoff is shifted\n";
    s += "by one half-semitone for each note.";
    return s;
}

String Describe_Exp_Param::lpf_reso() {
    String s{ "" };
    s += "Sets the resonance level of the low-pass\n";
    s += "filter. When in 4-pole mode, high resonance\n";
    s += "will cause the filter to self-oscillate.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::lpf_type() {
    String s{ "" };
    s += "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
    s += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
    s += "slope and more pronounced resonance.";
    return s;
}

String Describe_Exp_Param::midi_breath_amt() {
    String s{ "" };
    s += "Sets the degree to which MIDI breath controller\n";
    s += "messages (CC#2) modulate the destination parameter.\n";
    s += "Negative values invert the modulation.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::midi_mod_wheel_amt() {
    String s{ "" };
    s += "Sets the degree to which MIDI modulation wheel controller\n";
    s += "messages (CC#1) modulate the destination parameter.\n";
    s += "Negative values invert the modulation.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::midi_pedal_amt() {
    String s{ "" };
    s += "Sets the degree to which MIDI foot pedal controller\n";
    s += "messages (CC#4) modulate the destination parameter.\n";
    s += "Negative values invert the modulation.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::midi_pressure_amt() {
    String s{ "" };
    s += "Sets the degree to which MIDI channel pressure\n";
    s += "(aftertouch) messages modulate the destination parameter.\n";
    s += "Negative values invert the modulation.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::midi_velocity_amt() {
    String s{ "" };
    s += "Sets the degree to which MIDI note velocity\n";
    s += "messages modulate the destination parameter.\n";
    s += "Negative values invert the modulation.\n";
    s += "Range: -127 to +127.";
    return s;
}

String Describe_Exp_Param::mod_amt() {
    String s{ "" };
    s += "Sets the degree to which the selected source\n";
    s += "modulates the selected destination parameter.\n";
    s += "Negative values invert the modulation.\nRange: -127 to +127.";
    return s;
}

String Describe_Exp_Param::noise_level() {
    String s{ "" };
    s += "Sets the level of white noise\n";
    s += "sent into the low-pass filter.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::note_priority() {
    String s{ "" };
    s += "Selects which note is given priority when multiple\n";
    s += "notes are played, and whether the envelopes are\n";
    s += "re-triggered when a note is played legato (before\n";
    s += "the previous note has been released).";
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

String Describe_Exp_Param::osc_mix() {
    String s{ "" };
    s += "Controls the level balance between oscillators 1 & 2.\n";
    s += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
    s += "At 127, only oscillator 2 is heard. At 64, an equal\n";
    s += "mix of the two oscillators is heard.";
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

String Describe_Exp_Param::push_it_mode() {
    String s{ "" };
    s += "Sets the operating mode for the Mopho" + apostrophe + "s Push It! switch.\n";
    s += "Normal: The selected note is gated on when the switch is\n";
    s += "pressed and gated off when the switch is released.\n";
    s += "Toggle: The selected note is gated on when the switch is\n";
    s += "pressed and remains on until the switch is pressed again.\n";
    s += "Audio In: The selected note is gated on for as long as the\n";
    s += "external audio input level is above a certain threshold.";
    return s;
}

String Describe_Exp_Param::push_it_pitch() {
    String s{ "" };
    s += "Sets the note that plays when the Push It! switch is pressed.\n";
    s += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.\n";
    s += "Hold down the SHIFT key when using the mouse wheel to\n";
    s += "increment the pitch by one octave (12 semitones).";
    return s;
}

String Describe_Exp_Param::push_it_velocity() {
    String s{ "" };
    s += "Sets the velocity of the note that plays\n";
    s += "when the Push It! switch is pressed.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::seq_on_off() {
    String s{ "" };
    s += "Turns the Mopho" + apostrophe + "s internal sequencer on and off.\n";
    s += "Turning this on will turn off the arpeggiator.";
    return s;
}

String Describe_Exp_Param::seq_track_dest(const int track) {
    String s{ "" };
    s += "Selects the target parameter for\n";
    s += "modulation by sequencer track " + (String)track + ".";
    return s;
}

String Describe_Exp_Param::seq_track_step(const int track, int step) {
    String s{ "" };
    s = "Sets the value that sequencer track " + (String)track + apostrophe + "s destination parameter has at step " + (String)step + ",\n";
    s += "Range: 0 to 125. If the target is an oscillator pitch, the range is C0 to D5+.\n";
    s += "A " + open_quote + "+" + close_quote + " indicates that the pitch is a quarter-tone higher than the displayed note.\n";
    s += "Reset (126): Resets the sequence back to step 1. CTRL-click a step to set it to reset.";
    if (track == 0) {
        s += "\nRest (127): The step produces no output. ALT-click a step to make it a rest\n";
        s += "(Rests are only available for the steps in sequencer track 1).";
    }
    s += "\nWhen the track destination is an oscillator pitch, holding down the\n";
    s += "SHIFT key while turning the mouse wheel will increment a step" + apostrophe + "s value \n";
    s += "by 24 (equivalent to one octave including the " + open_quote + "bent" + close_quote + " pitches).\n";
    s += "Otherwise, the value will increment by 10.";
    return s;
}

String Describe_Exp_Param::seq_trig_mode() {
    String s{ "" };
    s += "Normal: New notes reset the sequencer to the first step.\n";
    s += "The envelopes are re-triggered with each step.\n";
    s += "Normal, No Reset: New notes do not reset the sequencer to the\n";
    s += "first step. The envelopes are re-triggered with each step.\n";
    s += "No Gate: New notes reset the sequencer to the first step. New\n";
    s += "notes re-trigger the envelopes, but sequencer steps do not.\n";
    s += "No Gate, No Reset: New notes do not reset the sequencer to the\n";
    s += "first step. Sequencer steps do not re-trigger the envelopes.\n";
    s += "Key Step: Each new note advances the sequencer one step.\n";
    s += "Audio Input: The sequencer advances one step every time the\n";
    s += "external audio input level surpasses a certain threshold.";
    return s;
}

String Describe_Exp_Param::vca_env_amt() {
    String s{ "" };
    s += "Sets the degree to which the VCA envelope\n";
    s += "modulates the voltage-controlled ampifier" + apostrophe + "s level.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::vca_level() {
    String s{ "" };
    s += "Sets the voltage-controlled amplifier" + apostrophe + "s baseline level. Turn this\n";
    s += "up for droning sounds or when processing external audio input.\n";
    s += "When this level is set to 127, the VCA envelope has no effect.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::voice_name_char(const int char_num) {
    String s{ "" };
    s += "To change character " + (String)char_num + " of the program" + apostrophe + "s name,\n";
    s += "click-and-drag the character or hover over\n";
    s += "it and turn the mouse wheel. Click the edit\n";
    s += "button above to type in the entire name.";
    return s;
}

String Describe_Exp_Param::voice_volume() {
    String s{ "" };
    s += "Sets the overall gain of the current program.\n";
    s += "Range: 0 to 127.";
    return s;
}
