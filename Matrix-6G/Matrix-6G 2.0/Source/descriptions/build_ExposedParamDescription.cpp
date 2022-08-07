#include "build_ExposedParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;

String ExposedParamDescription::buildForKeyboardMode() {
    String description{ "" };
    description += "Selects how notes get assigned to the hardware" + GUI::apostrophe + "s six available voices.\n";
    description += "REASGN: Reassign - once a note gets assigned to a certain voice,\n";
    description += "every time thereafter that the same note is played, it will get\n";
    description += "reassigned to the same voice.\n";
    description += "ROTATE: Rotate - the hardware loops through the six voices,\n";
    description += "assigning each new note to the next available voice.\n";
    description += "UNISON: Unison (monophonic) - each note triggers all six voices\n";
    description += "and only one note at a time can play. When multiple notes are played\n";
    description += "at once, only the lowest note will be heard.\n";
    description += "REAROB: Reassign rob - like reassign mode, but if all six voices are\n";
    description += "sounding and a new note is played, the new note will " + GUI::openQuote + "rob" + GUI::closeQuote + " a voice\n";
    description += "from one of the notes that are already playing.";
    return description;
}

String ExposedParamDescription::buildForOscBalance() {
    String description{ "" };
    description += "Sets the relative levels of the two oscillators.\n";
    description += "Range: 0 to 63. At 63, only oscillator 1 is heard.\n";
    description += "At 0, only oscillator 2 is heard. 31 is an equal mix.";
    return description;
}

String ExposedParamDescription::buildForOscKeyClick() {
    String description{ "" };
    description += "Adds percussive punch to\n";
    description += "the start of the sound.";
    return description;
}

String ExposedParamDescription::buildForOscKeyTrack(const int oscNum) {
    String description{ "" };
    description += "Selects how oscillator " + (String)oscNum + " responds to incoming pitch\n";
    description += "change messages (e.g. notes played on a keyboard controller).\n";
    if (oscNum == 1) {
        description += "KEYBD: Oscillater " + (String)oscNum + GUI::apostrophe + "s pitch tracks note key changes normally.\n";
        description += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
        description += "according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.";
    }
    else {
        description += "OFF: Oscillater 2" + GUI::apostrophe + "s pitch will not change as notes are played.\n";
        description += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
        description += "according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.\n";
        description += "KEYBD: Oscillator 2" + GUI::apostrophe + "s pitch tracks note key changes normally.";
    }
    return description;
}

String ExposedParamDescription::buildForLeverControl(const int oscNum) {
    String description{ "" };
    description += "Selects which of the performance " + GUI::openQuote + "levers" + GUI::closeQuote + "\n";
    description += "(wheel-type controllers) will modulate oscillator " + (String)oscNum + ".\n";
    description += "OFF: Oscillator " + (String)oscNum + " is not modulated by either lever.\n";
    description += "BEND: Pitch bend is modulated by lever 1 (pitch wheel).\n";
    description += "VIB: Vibrato amount is modulated by lever 2 (mod wheel).\n";
    description += "BOTH: Oscillator " + (String)oscNum + " is modulated by both levers.";
    return description;
}

String ExposedParamDescription::buildForOscPitch(const int oscNum) {
    String description{ "" };
    description += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch in semitone steps.\n";
    description += "Range: 0 (C 0) to 63 (D# 5). Hold down the\n";
    description += "SHIFT key when using the mouse wheel to incre-\n";
    description += "ment the pitch by one octave (12 semitones).";
    return description;
}

String ExposedParamDescription::buildForOscPulseWidth(const int oscNum) {
    String description{ "" };
    description += "Sets the width of oscillator " + (String)oscNum + GUI::apostrophe + "s\n";
    description += "wave when its type is set to pulse.\n";
    description += "Range: 0 (very wide) to 63 (very narrow).\n";
    description += "A value of 31 produces a square wave.";
    return description;
}

String ExposedParamDescription::buildForOscSawTri(const int oscNum) {
    String description{ "" };
    description += "Sets the shape of oscillator " + (String)oscNum + "\n";
    description += "when its type is set to wave.\n";
    description += "Range: 0 (sawtooth) to 63 (triangle).\n";
    description += "Intermediate values produce various\n";
    description += "mixtures of the two shapes.";
    return description;
}

String ExposedParamDescription::buildForOscType(const int oscNum) {
    String description{ "" };
    description += "Selects oscillator " + (String)oscNum + GUI::apostrophe + "s wave type.\n";
    description += "OFF: The oscillator produces no sound.\n";
    description += "PULSE: Set the width of the pulse below.\n";
    description += "WAVE: Set the shape of the wave below.\n";
    description += "BOTH: A blend of pulse and wave.";
    if (oscNum == 2)
        description += "\nNOISE: White noise (oscillator 2 only).";
    return description;
}

String ExposedParamDescription::buildForOsc_1_Sync() {
    String description{ "" };
    description += "Selects whether and to what degree oscillator 1" + GUI::apostrophe + "s\n";
    description += "waveform is synchronized with that of oscillator 2.";
    return description;
}

String ExposedParamDescription::buildForOsc_2_Detune() {
    String description{ "" };
    description += "Slightly lowers or raises Oscillator 2" + GUI::apostrophe + "s pitch.\n";
    description += "Range -31 to +31 (-/+ ~25 cents). 0 is no detune.\n";
    description += "NOTE: Negative values cannot be assigned to indi-\n";
    description += "vidual parameters via Quick Patch Edit. Use the\n";
    description += "PUSH button to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildForOsc_LFO_1_FM(const int oscNum) {
    String description{ "" };
    description += "Sets whether and to what degree LFO 1\n";
    description += "modulates the pitch of oscillator " + (String)oscNum + ".\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the LFO waveform.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildForOsc_LFO_2_PWM(const int oscNum) {
    String description{ "" };
    description += "Sets whether and to what degree LFO 2\n";
    description += "modulates the pulse width of oscillator " + (String)oscNum + ".\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the LFO waveform.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildForPortaLegato() {
    String description{ "" };
    description += "When legato is on, portamento will only be active\n";
    description += "when a new note is played prior to releasing the\n";
    description += "previous note. This behavior is only active when\n";
    description += "the keyboard mode is set to unison.";
    return description;
}

String ExposedParamDescription::buildForPortaMode() {
    String description{ "" };
    description += "Selects how the portamento transition rate is calculated.\n";
    description += "LINEAR: Linear - the time it takes to transition between\n";
    description += "two pitches is proportional to the distance between them.\n";
    description += "CONSTANT: Constant time - the time it takes to transition between\n";
    description += "two pitches is the same regardless of the distance between them.\n";
    description += "EXPO: Exponential - the transition between pitches starts out fast\n";
    description += "then slows down as it gets closer to the destination pitch.";
    return description;
}

String ExposedParamDescription::buildForPortaRate() {
    String description{ "" };
    description += "Sets the amount of time it takes to transition\n";
    description += "from the origin pitch to the destination pitch.\n";
    description += "Range: 0 (instantaneous) to 63 (longest).";
    return description;
}

String ExposedParamDescription::buildForPortaVelo() {
    String description{ "" };
    description += "Sets whether and to what degree note\n";
    description += "velocity modulates the portamento rate.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the velocity response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_1_PressureAmt() {
    String description{ "" };
    description += "Sets whether and to what degree keyboard pressure\n";
    description += "(aftertouch) will modulate the speed of LFO 1\n";
    description += "(e.g. higher pressure increases the cycle rate).\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the pressure response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_2_KeyTrackAmt() {
    String description{ "" };
    description += "Sets whether and to what degree keyboard\n";
    description += "position will modulate the speed of LFO 2.\n";
    description += "(e.g. higher notes increase the cycle rate).\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the key position response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Amp(const int lfoNum) {
    String description{ "" };
    description += "Sets the degree to which LFO " + (String)lfoNum + " modulates its destination.\n";
    description += "Range: 0 (no modulation) to 63 (maximum modulation).";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Lag(const int lfoNum) {
    String description{ "" };
    description += "The lag processor which smooths pitch transitions for portamento\n";
    description += "can also be used to smooth the value transitions in LFO " + (String)lfoNum + GUI::apostrophe + "s wave\n";
    description += "cycle. The effect is most notable on a square wave cycle.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_RampAmt(const int lfoNum) {
    String description{ "" };
    description += "Sets whether and to what degree ramp " + (String)lfoNum + "\n";
    description += "will modulate LFO " + (String)lfoNum + GUI::apostrophe + "s amplitude.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the ramp.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_RetrigPoint(const int lfoNum) {
    String description{ "" };
    description += "If LFO " + (String)lfoNum + " is set (above) to be triggered by the keyboard or by\n";
    description += "an external source, modulation can be set to start from a\n";
    description += "point in the LFO" + GUI::apostrophe + "s waveform cycle other than its beginning.\n";
    description += "Range: 0 (beginning of the cycle) to 63 (the cycle" + GUI::apostrophe + "s half-way point).";
    return description;
}

String ExposedParamDescription::buildFor_LFO_SampleSource(const int lfoNum) {
    String description{ "" };
    description += "Selects the modulation source that LFO " + (String)lfoNum + " will\n";
    description += "periodically sample to calculate its output value\n";
    description += "(when its wave type, above, is set to sample).";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Speed(const int lfoNum) {
    String description{ "" };
    description += "Sets the cycle rate of low-frequency oscillator " + (String)lfoNum + ".\n";
    description += "Range: 0 (slowest) to 63 (fastest).";
    return description;
}

String ExposedParamDescription::buildFor_LFO_TrigMode(const int lfoNum) {
    String description{ "" };
    description += "Selects the type of trigger that will start LFO " + (String)lfoNum + GUI::apostrophe + "s control cycle.\n";
    description += "OFF: The LFO is not triggered and cycles freely.\n";
    description += "STRIG: Single - A new note triggers the LFO only when no other\n";
    description += "notes are currently held down (only active in unison mode).\n";
    description += "MTRIG: Multiple - the LFO is triggered with every new note played.\n";
    description += "XTRIG: External - an external signal (e.g. a footswitch) triggers the LFO.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_WaveType(const int lfoNum) {
    String description{ "" };
    description += "Selects the type of modulation signal that LFO " + (String)lfoNum + " generates.\n";
    description += "TRI: Triangle - a periodic wave that steadily rises and falls\n";
    description += "between its minimum and maximum values.\n";
    description += "UPSAW: Up (rising) sawtooth - a periodic wave that rises steadily\n";
    description += "to the maximum value then abruptly returns to the minimum value.\n";
    description += "DNSAW: Down (falling) sawtooth - a periodic wave that falls steadily\n";
    description += "to the minimum value then abruptly returns to the maximum value.\n";
    description += "SQUAR: Square - a periodic wave that switches abruptly between\n";
    description += "the minimum and maximum values.\n";
    description += "RANDM: Random - an aperiodic wave that outputs a series of random values.\n";
    description += "NOISE: Noise - a much faster version of the random waveform.\n";
    description += "SAMPL: Sampled - the LFO" + GUI::apostrophe + "s waveform is created by periodically sampling\n";
    description += "the value of another modulation source. Select the sample source below.\n";
    description += "The sampling rate is determined by the LFO" + GUI::apostrophe + "s speed setting, above.";
    return description;
}

String ExposedParamDescription::buildFor_VCA_1_VeloAmt() {
    String description{ "" };
    description += "Sets whether and to what degree note velocity\n";
    description += "modulates the output level of VCA 1.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the velocity response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCA_1_Volume() {
    String description{ "" };
    description += "Sets the initial output level of the\n";
    description += "first-stage voltage-controlled amplifier.\n";
    description += "Range: 0 (silence) to 63 (maximum).";
    return description;
}

String ExposedParamDescription::buildFor_VCA_2_Env_2_Amt() {
    String description{ "" };
    description += "Sets whether and to what degree envelope 2\n";
    description += "modulates the output level of the second-\n";
    description += "stage voltage-controlled amplifier.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the envelope.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_Env_1_Amt() {
    String description{ "" };
    description += "Sets whether and to what degree envelope 1\n";
    description += "modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the envelope.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_FM_Env_3_Amt() {
    String description{ "" };
    description += "Sets whether and to what degree envelope 3\n";
    description += "modulates the amount of VCF FM by oscillator 1.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the envelope.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_FM_Osc_1_Amt() {
    String description{ "" };
    description += "Sets whether and to what degree oscillator 1\n";
    description += "modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "Range: 0 (no modulation) to 63 (maximum).";
    return description;
}

String ExposedParamDescription::buildFor_VCF_FM_PressureAmt() {
    String description{ "" };
    description += "Sets whether and to what degree keyboard\n";
    description += "pressure (aftertouch) modulates the\n";
    description += "amount of VCF FM by oscillator 1.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the pressure response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_Freq() {
    String description{ "" };
    description += "Sets the base cutoff frequency of\n";
    description += "the voltage-controlled filter.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_KeyTrack() {
    String description{ "" };
    description += "Selects how the VCF" + GUI::apostrophe + "s cutoff frequency responds to incoming pitch\n";
    description += "change messages (e.g. notes played on a keyboard controller).\n";
    description += "OFF: Note key changes have no effect on the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "PORTA: Tracking is active, but transitions between cutoff frequencies are\n";
    description += "smoothed according to the settings in the portamento (aka " + GUI::openQuote + "glide" + GUI::closeQuote + ") section.\n";
    description += "KEYBD: The VCF" + GUI::apostrophe + "s cutoff frequency tracks note key changes, rising as\n";
    description += "higher notes are played and dropping as lower notes are played.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_LeverControl() {
    String description{ "" };
    description += "Selects which of the performance " + GUI::openQuote + "levers" + GUI::closeQuote + "\n";
    description += "(wheel-type controllers) modulate the VCF frequency.\n";
    description += "OFF: VCF frequency is not modulated by either lever.\n";
    description += "BEND: VCF frequency is modulated by lever 1 (pitch wheel).\n";
    description += "VIB: VCF frequency vibrato is modulated by lever 2 (mod wheel).\n";
    description += "BOTH: VCF frequency is modulated by both levers.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_PressureAmt() {
    String description{ "" };
    description += "Sets whether and to what degree keyboard pressure \n";
    description += "(aftertouch) modulates the VCF" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "Range: -63 to +63. 0 is no modulation.\n";
    description += "Negative values invert the pressure response.\n";
    description += "NOTE: Negative values cannot be\n";
    description += "assigned to individual parameters via\n";
    description += "Quick Patch Edit. Use the PUSH button\n";
    description += "to send the entire patch instead.";
    return description;
}

String ExposedParamDescription::buildFor_VCF_Reso() {
    String description{ "" };
    description += "Sets the resonance level of\n";
    description += "the voltage-controlled filter.\n";
    description += "Range: 0 to 63. At 63, the/n";
    description += "filter will self-oscillate.";
    return description;
}
