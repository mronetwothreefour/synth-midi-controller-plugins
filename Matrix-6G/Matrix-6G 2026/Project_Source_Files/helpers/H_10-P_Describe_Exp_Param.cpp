#include "H_10-P_Describe_Exp_Param.h"

#include "C_12-B_FONT.h"

using namespace FONT;

String Describe_Exp_Param::env_amp(const String e) {
    String s{ "" };
    s += "Sets the maximum output level of envelope " + e + ", which determines\n";
    s += "the degree to which the envelope modulates its destination(s).\n";
    s += "Range: 0 (no modulation) to 63 (maximum modulation).";
    return s;
}

String Describe_Exp_Param::env_attack(const String e) {
    String s{ "" };
    s += "Sets the length of envelope " + e + apostrophe + "s attack\n";
    s += "stage, the amount of time it takes to\n";
    s += "rise from minimum to maximum level.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::env_decay(const String e) {
    String s{ "" };
    s += "Sets the length of envelope " + e + apostrophe + "s decay stage,\n";
    s += "the amount of time it takes to drop from\n";
    s += "the maximum level to the sustain level.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::env_delay(const String e) {
    String s{ "" };
    s += "Sets the length of envelope " + e + apostrophe + "s delay stage,\n";
    s += "the amount of time after the envelope is\n";
    s += "triggered before the attack stage begins.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::env_lfo_1_trig(const String e) {
    String s{ "" };
    s += "Selects whether and how envelope " + e + apostrophe + "s cycle is triggered by LFO 1.\n";
    s += "NORMAL: The envelope cycle is not triggered by LFO 1.\n";
    s += "G-LFO1: Gated LFO 1 trigger - LFO 1 will trigger the envelope cycle\n";
    s += "periodically only if one or more notes are currently gated on.\n";
    s += "LFO 1: The envelope cycle is triggered periodically by LFO 1.\n";
    s += "The point in LFO 1" + apostrophe + "s cycle which actually triggers the envelope\n";
    s += "cycle is determined by the LFO 1 Retrigger Point parameter.";
    return s;
}

String Describe_Exp_Param::env_mode(const String e) {
    String s{ "" };
    s += "Selects how envelope " + e + " completes its cycle when triggered.\n";
    s += "NORMAL: When a note is gated on and the envelope is triggered, the cycle\n";
    s += "will run through the delay, attack, and decay stages, then hold at the\n";
    s += "sustain level. Gating off the note will immediately trigger the release\n";
    s += "stage, even if the sustain stage has not yet been reached.\n";
    s += "DADR: Delay-Attack-Decay-Release - the release stage begins immediately\n";
    s += "after the decay stage, whether or not the voice is still gated on. Gating off \n";
    s += "the voice before the other stages complete will also start the release stage.\n";
    s += "FREE: Free run - the envelope will completely run through the delay, attack,\n";
    s += "decay, and release stages, whether or not the note is kept gated on.\n";
    s += "Keeping the note gated on will hold the sustain level normally.\n";
    s += "BOTH: Both DADR and free run - like free run mode, except the release stage\n";
    s += "begins immediately after the decay stage, even if the note is still gated on.";
    return s;
}

String Describe_Exp_Param::env_release(const String e) {
    String s{ "" };
    s += "Sets the length of envelope " + e + apostrophe + "s release stage,\n";
    s += "the amount of time it takes to drop from\n";
    s += "the sustain level to the minimum level.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::env_sustain(const String e) {
    String s{ "" };
    s += "Sets envelope " + e + apostrophe + "s sustain level. After the\n";
    s += "decay stage completes, output will remain at\n";
    s += "this level until the voice is gated off.\n";
    s += "Range: 0 (minimum) to 63 (maximum).";
    return s;
}

String Describe_Exp_Param::env_trig_mode(const String e) {
    String s{ "" };
    s += "Selects what sort of trigger will start envelope " + e + apostrophe + "s cycle.\n";
    s += "STRIG: Single trigger (unison mode only) - the cycle will start for\n";
    s += "a voice only if it is not already playing. Legato playing will not\n";
    s += "re-trigger the cycle. If the envelope is re-triggered before its cycle\n";
    s += "completes, it will continue from the point it was at in the cycle.\n";
    s += "SRESET: Single trigger reset - like single trigger mode, except\n";
    s += "that if the envelope is re-triggered before its cycle completes,\n";
    s += "the envelope will reset to the start of the cycle.\n";
    s += "MTRIG: Multiple trigger - New notes will always re-trigger the envelope,\n";
    s += "and it will continue from the last point it was at in its cycle.\n";
    s += "MRESET: Multiple trigger reset - new notes will always re-trigger\n";
    s += "the envelope and reset it to the beginning of its cycle.\n";
    s += "The remaining modes behave like their counterparts above, but the trigger\n";
    s += "comes from a DC pulse (e.g. from a footswitch) sent into the PEDAL 2 jack:\n";
    s += "XTRIG: External single trigger; XRESET: External single trigger reset;\n";
    s += "XMTRIG: External multiple trigger; XMRST: External multiple trigger reset.";
    return s;
}

String Describe_Exp_Param::env_velo_amt(const String e) {
    String s{ "" };
    s += "Sets whether and to what degree note\n";
    s += "velocity modulates envelope " + e + apostrophe + "s amplitude.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the velocity response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::keyboard_mode() {
    String s{ "" };
    s += "Selects how notes get assigned to the device" + apostrophe + "s six available voices.\n";
    s += "REASGN: Reassign - once a note gets assigned to a certain voice,\n";
    s += "every time thereafter that the same note is played, it will get\n";
    s += "reassigned to the same voice.\n";
    s += "ROTATE: Rotate - the device loops through the six voices,\n";
    s += "assigning each new note to the next available voice.\n";
    s += "UNISON: Unison (monophonic) - each note triggers all six voices\n";
    s += "and only one note at a time can play. When multiple notes are played\n";
    s += "at once, only the lowest note will be heard.\n";
    s += "REAROB: Reassign rob - like reassign mode, but if all six voices are\n";
    s += "sounding and a new note is played, the new note will " + open_quote + "rob" + close_quote + " a voice\n";
    s += "from one of the notes that are already playing.";
    return s;
}

String Describe_Exp_Param::lfo_1_pressure_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard pressure\n";
    s += "(aftertouch) will modulate the speed of LFO 1\n";
    s += "(e.g. higher pressure increases the cycle rate).\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the pressure response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::lfo_2_key_track_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard\n";
    s += "position will modulate the speed of LFO 2.\n";
    s += "(e.g. higher notes increase the cycle rate).\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the key position response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::lfo_amp(const int lfo) {
    String s{ "" };
    s += "Sets the degree to which LFO " + (String)lfo + " modulates its destination.\n";
    s += "Range: 0 (no modulation) to 63 (maximum modulation).";
    return s;
}

String Describe_Exp_Param::lfo_lag(const int lfo) {
    String s{ "" };
    s += "The lag processor, which smooths pitch transitions for portamento,\n";
    s += "can also be used to smooth the value transitions in LFO " + (String)lfo + apostrophe + "s wave\n";
    s += "cycle. The effect is most notable on a square wave cycle.";
    return s;
}

String Describe_Exp_Param::lfo_ramp_amt(const int lfo) {
    String s{ "" };
    s += "Sets whether and to what degree ramp " + (String)lfo + "\n";
    s += "will modulate LFO " + (String)lfo + apostrophe + "s amplitude.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the ramp.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::lfo_retrig_point(const int lfo) {
    String s{ "" };
    s += "If LFO " + (String)lfo + " is set (above) to be triggered by the keyboard or by\n";
    s += "an external source, modulation can be set to start from a\n";
    s += "point in the LFO" + apostrophe + "s waveform cycle other than its beginning.\n";
    s += "Range: 0 (beginning of the cycle) to 63 (the cycle" + apostrophe + "s half-way point).";
    return s;
}

String Describe_Exp_Param::lfo_sample_source(const int lfo) {
    String s{ "" };
    s += "Selects the modulation source that LFO " + (String)lfo + " will\n";
    s += "periodically sample to calculate its output value\n";
    s += "(when its wave type (above) is set to sample).";
    return s;
}

String Describe_Exp_Param::lfo_speed(const int lfo) {
    String s{ "" };
    s += "Sets the cycle rate of low-frequency oscillator " + (String)lfo + ".\n";
    s += "Range: 0 (slowest) to 63 (fastest).";
    return s;
}

String Describe_Exp_Param::lfo_trig_mode(const int lfo) {
    String s{ "" };
    s += "Selects the type of trigger that will start LFO " + (String)lfo + apostrophe + "s control cycle.\n";
    s += "OFF: The LFO is not triggered and cycles freely.\n";
    s += "STRIG: Single - A new note triggers the LFO only when no other\n";
    s += "notes are currently held down (only active in unison mode).\n";
    s += "MTRIG: Multiple - the LFO is triggered with every new note played.\n";
    s += "XTRIG: External - an external signal (e.g. a footswitch) triggers the LFO.";
    return s;
}

String Describe_Exp_Param::lfo_wave_type(const int lfo) {
    String s{ "" };
    s += "Selects the type of modulation signal that LFO " + (String)lfo + " generates.\n";
    s += "TRI: Triangle - a periodic wave that steadily rises and falls\n";
    s += "between its minimum and maximum values.\n";
    s += "UPSAW: Up (rising) sawtooth - a periodic wave that rises steadily\n";
    s += "to the maximum value then abruptly returns to the minimum value.\n";
    s += "DNSAW: Down (falling) sawtooth - a periodic wave that falls steadily\n";
    s += "to the minimum value then abruptly returns to the maximum value.\n";
    s += "SQUAR: Square - a periodic wave that switches abruptly between\n";
    s += "the minimum and maximum values.\n";
    s += "RANDM: Random - an aperiodic wave that outputs a series of random values.\n";
    s += "NOISE: Noise - a much faster version of the random waveform.\n";
    s += "SAMPL: Sampled - the LFO" + apostrophe + "s waveform is created by periodically sampling\n";
    s += "the value of another modulation source. Select the sample source below.\n";
    s += "The sampling rate is determined by the LFO" + apostrophe + "s speed setting (above).";
    return s;
}

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

String Describe_Exp_Param::porta_legato() {
    String s{ "" };
    s += "When legato is on, portamento will only be active\n";
    s += "when a new note is played prior to releasing the\n";
    s += "previous note. This behavior is only active when\n";
    s += "the keyboard mode is set to unison.";
    return s;
}

String Describe_Exp_Param::porta_mode() {
    String s{ "" };
    s += "Selects how the portamento transition rate is calculated.\n";
    s += "LINEAR: Linear - the time it takes to transition between\n";
    s += "two pitches is proportional to the distance between them.\n";
    s += "CONSTANT: Constant time - the time it takes to transition between\n";
    s += "two pitches is the same regardless of the distance between them.\n";
    s += "EXPO: Exponential - the transition between pitches starts out fast\n";
    s += "then slows down as it gets closer to the destination pitch.";
    return s;
}

String Describe_Exp_Param::porta_rate() {
    String s{ "" };
    s += "Adjusts the amount of time it takes to transition\n";
    s += "from the origin pitch to the destination pitch.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::porta_velo() {
    String s{ "" };
    s += "Sets whether and to what degree note\n";
    s += "velocity modulates the portamento rate.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the velocity response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::ramp_rate(const int ramp) {
    String s{ "" };
    s += "Sets the amount of time it takes for\n";;
    s += "Ramp " + (String)ramp + " to complete its control cycle.\n";
    s += "Range: 0 (instantaneous) to 63 (longest).";
    return s;
}

String Describe_Exp_Param::ramp_trig(const int ramp) {
    String s{ "" };
    s += "Selects the type of trigger that will start ramp " + (String)ramp + apostrophe + "s control cycle.\n";
    s += "STRIG: Single - A new note triggers the ramp only when no other\n";
    s += "notes are currently held down (only active in unison mode).\n";
    s += "MTRIG: Multiple - the ramp is triggered with every new note played.\n";
    s += "XTRIG: External - an external signal (e.g. a footswitch) triggers the ramp.\n";
    s += "GATEX: Gated External - an external signal triggers the ramp only when\n";
    s += "there are one or more notes being played.";
    return s;
}

String Describe_Exp_Param::track_input() {
    String s{ "" };
    s += "Selects the modulation source which\n";
    s += "will be shaped by the tracking generator.";
    return s;
}

String Describe_Exp_Param::track_point(const int point, int init_choice) {
    String s{ "" };
    s += "Tracking Point " + (String)point + "\n";
    s += "Range: 0 to 63.\n";
    s += "Linear output value: " + (String)init_choice + ".";
    return s;
}

String Describe_Exp_Param::vca_1_velo_amt() {
    String s{ "" };
    s += "Sets whether and to what degree note velocity\n";
    s += "modulates the output level of VCA 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the velocity response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vca_1_volume() {
    String s{ "" };
    s += "Sets the initial output level of the\n";
    s += "first-stage voltage-controlled amplifier.\n";
    s += "Range: 0 (silence) to 63 (maximum).";
    return s;
}

String Describe_Exp_Param::vca_2_env_2_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 2\n";
    s += "modulates the output level of the second-\n";
    s += "stage voltage-controlled amplifier.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_env_1_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 1\n";
    s += "modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_fm_env_3_amt() {
    String s{ "" };
    s += "Sets whether and to what degree envelope 3\n";
    s += "modulates the amount of VCF FM by oscillator 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the envelope.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_fm_osc_1_amt() {
    String s{ "" };
    s += "Sets whether and to what degree oscillator 1\n";
    s += "modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: 0 (no modulation) to 63 (maximum).";
    return s;
}

String Describe_Exp_Param::vcf_fm_pressure_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard\n";
    s += "pressure (aftertouch) modulates the\n";
    s += "amount of VCF FM by oscillator 1.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the pressure response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_freq() {
    String s{ "" };
    s += "Sets the base cutoff frequency of\n";
    s += "the voltage-controlled filter.\n";
    s += "Range: 0 to 127.";
    return s;
}

String Describe_Exp_Param::vcf_key_track() {
    String s{ "" };
    s += "Selects how the VCF" + apostrophe + "s cutoff frequency responds to incoming pitch\n";
    s += "change messages (e.g. notes played on a keyboard controller).\n";
    s += "OFF: Note key changes have no effect on the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "PORTA: Tracking is active, but transitions between cutoff frequencies are\n";
    s += "smoothed according to the settings in the portamento (aka " + open_quote + "glide" + close_quote + ") section.\n";
    s += "KEYBD: The VCF" + apostrophe + "s cutoff frequency tracks note key changes, rising as\n";
    s += "higher notes are played and dropping as lower notes are played.";
    return s;
}

String Describe_Exp_Param::vcf_lever_ctrl() {
    String s{ "" };
    s += "Selects which of the performance " + open_quote + "levers" + close_quote + "\n";
    s += "(wheel-type controllers) modulate the VCF frequency.\n";
    s += "OFF: VCF frequency is not modulated by either lever.\n";
    s += "BEND: VCF frequency is modulated by lever 1 (pitch wheel).\n";
    s += "VIB: VCF frequency vibrato is modulated by lever 2 (mod wheel).\n";
    s += "BOTH: VCF frequency is modulated by both levers.";
    return s;
}

String Describe_Exp_Param::vcf_pressure_amt() {
    String s{ "" };
    s += "Sets whether and to what degree keyboard pressure \n";
    s += "(aftertouch) modulates the VCF" + apostrophe + "s cutoff frequency.\n";
    s += "Range: -63 to +63. 0 is no modulation.\n";
    s += "Negative values invert the pressure response.\n";
    s += "NOTE: Negative values cannot be\n";
    s += "assigned to individual parameters via\n";
    s += "Quick Patch Edit. Use the PUSH button\n";
    s += "to send the entire patch instead.";
    return s;
}

String Describe_Exp_Param::vcf_reso() {
    String s{ "" };
    s += "Sets the resonance level of\n";
    s += "the voltage-controlled filter.\n";
    s += "Range: 0 to 63. At 63, the/n";
    s += "filter will self-oscillate.";
    return s;
}
