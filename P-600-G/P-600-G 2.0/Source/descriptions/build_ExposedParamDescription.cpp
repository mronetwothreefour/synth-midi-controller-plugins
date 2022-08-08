#include "build_ExposedParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

String ExposedParamDescription::buildForEnvAttack(EnvelopeType envType) {
    String envString{ envType == EnvelopeType::amplifier ? "amplifier" : "filter" };
    String description{ "" };
    description += "Sets the amount of time it takes for the " + envString + "\n";
    description += "envelope to rise from zero to maximum level.\n";
    description += "Range: 0 (instantaneous) to 15 (longest time)";
    return description;
}

String ExposedParamDescription::buildForEnvDecay(EnvelopeType envType) {
    String envString{ envType == EnvelopeType::amplifier ? "amplifier" : "filter" };
    String description{ "" };
    description += "Sets the amount of time it takes for the " + envString + " envelope\n";
    description += "to fall from maximum level down to the sustain level.\n";
    description += "Range: 0 (instantaneous) to 15 (longest time)";
    return description;
}

String ExposedParamDescription::buildForEnvRelease(EnvelopeType envType) {
    String envString{ envType == EnvelopeType::amplifier ? "amplifier" : "filter" };
    String description{ "" };
    description += "Sets the amount of time it takes for the " + envString + "\n";
    description += "envelope to fall to zero once the note is released.\n";
    description += "Range: 0 (instantaneous) to 15 (longest time)";
    return description;
}

String ExposedParamDescription::buildForEnvSustain(EnvelopeType envType) {
    String envString{ envType == EnvelopeType::amplifier ? "amplifier" : "filter" };
    String description{ "" };
    description += "Sets the sustain level for the " + envString + " envelope.\n";
    description += "The envelope decays to this level and stays\n";
    description += "there until the note is released.\n";
    description += "Range: 0 to 15 (maximum level)";
    return description;
}

String ExposedParamDescription::buildForFilterCutoff() {
    String description{ "" };
    description += "Adjusts the cutoff frequency of the 4-pole low-pass filter.\n";
    description += "Increasing the cutoff lets through higher and higher fre-\n";
    description += "quencies and makes the sound " + GUI::openQuote + "brighter." + GUI::closeQuote + " Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForFilterEnvAmt() {
    String description{ "" };
    description += "Sets the depth of the envelope which modulates the filter\n";
    description += "cutoff frequency. Range: 0 (no modulation) to 15 (maximum depth).";
    return description;
}

String ExposedParamDescription::buildForFilterKeyTrack() {
    String description{ "" };
    description += "When set to FULL, the filter cutoff frequency " + GUI::openQuote + "tracks" + GUI::closeQuote + " the notes\n";
    description += "played on the keyboard, rising and falling so that all pitches have\n";
    description += "consistent brightness and loudness. When set to OFF, the cutoff\n";
    description += "frequency does not change. As you go higher up the keyboard past\n";
    description += "the cutoff frequency, the pitches are progressively duller and\n";
    description += "quieter. 1/2 selects the midrange between these two effects.";
    return description;
}

String ExposedParamDescription::buildForFilterReso() {
    String description{ "" };
    description += "Increasing filter resonance boosts frequencies near the\n";
    description += "cutoff frequency. At high resonance settings, the filter\n";
    description += "will self-oscillate, producing a sine wave with a pitch\n";
    description += "determined by the cutoff frequency. Range: 0 to 63.";
    return description;
}

String ExposedParamDescription::buildForGlide() {
    String description{ "" };
    description += GUI::openQuote + "Glide" + GUI::closeQuote + " is a smooth pitch transition between two consecutive notes.\n";
    description += "This knob adjusts the amount of time for the transition to complete.\n";
    description += "The actual time is dependent upon the distance between the two notes.\n";
    description += "Range: 0 (instantaneous, i.e. no glide) to 15 (longest glide time).";
    return description;
}

String ExposedParamDescription::buildForLFO_Dest_Filter() {
    String description{ "" };
    description += "Enables modulation of the filter's cutoff\n";
    description += "frequency by the low-frequency oscillator.";
    return description;
}

String ExposedParamDescription::buildForLFO_Dest_Freq() {
    String description{ "" };
    description += "Enables modulation of the frequencies of both\n";
    description += "oscillators by the low-frequency oscillator.";
    return description;
}

String ExposedParamDescription::buildForLFO_Dest_PW() {
    String description{ "" };
    description += "Enables modulation of the pulse widths of both\n";
    description += "oscillators by the low-frequency oscillator.";
    return description;
}

String ExposedParamDescription::buildForLFO_Freq() {
    String description{ "" };
    description += "Adjusts the frequency of the low-frequency oscillator.\n";
    description += "Range: 0 (~0.25 Hz) to 16 (~20 Hz)";
    return description;
}

String ExposedParamDescription::buildForLFO_InitAmount() {
    String description{ "" };
    description += "Sets the baseline amount of modulation produced by the low-\n";
    description += "frequency oscillator when the modulation wheel is at zero.\n";
    description += "Range: 0 (no modulation) to 31 (maximum modulation)";
    return description;
}

String ExposedParamDescription::buildForLFO_Shape() {
    String description{ "" };
    description += "Sets the low-frequency oscillator" + GUI::apostrophe + "s\n";
    description += "wave shape (square or triangle).";
    return description;
}

String ExposedParamDescription::buildForMixer() {
    String description{ "" };
    description += "Adjusts the ratio of the two oscillators" + GUI::apostrophe + " output to the filter.\n";
    description += "Range: 0 (only oscillator A is output) to 63 (only oscillator B).\n";
    description += "At a setting of 32, an equal mix of the two oscillators is output.";
    return description;
}

String ExposedParamDescription::buildForOscFreq(const String oscLetter) {
    String description{ "" };
    description += "Sets oscillator " + oscLetter + GUI::apostrophe + "s base pitch in semitone steps.\n";
    description += "Range: 0 (C 0) to 48 (C 4). Hold down the\n";
    description += "SHIFT key when using the mouse wheel to incre-\n";
    description += "ment the pitch by one octave (12 semitones).";
    return description;
}

String ExposedParamDescription::buildForOscPulseWidth(const String oscLetter) {
    String description{ "" };
    description += "Sets the width of the pulse wave generated by oscillator " + oscLetter + ".\n";
    description += "This has no effect if the oscillator" + GUI::apostrophe + "s Wave Shape : Pulse switch\n";
    description += "is turned off. Range: 0 (narrowest) to 127 (widest). A value of\n";
    description += "64 will produce an approximately square wave. At the extremes of\n";
    description += "the range, the pulse will thin out so much as to be inaudible.";
    return description;
}

String ExposedParamDescription::buildForOsc_A_Sync() {
    String description{ "" };
    description += "When on, oscillator A is forced to follow\n";
    description += "oscillator B in " + GUI::openQuote + "hard" + GUI::closeQuote + " synchronization.";
    return description;
}

String ExposedParamDescription::buildForOsc_B_Fine() {
    String description{ "" };
    description += "Raises the pitch of oscillator B by\n";
    description += "up to one semitone. Range: 0 to 127";
    return description;
}

String ExposedParamDescription::buildForPolyModAmt_FilterEnv() {
    String description{ "" };
    description += "Sets the degree to which the filter envelope\n";
    description += "modulates the enabled poly-mod destination(s).\n";
    description += "Range: 0 (no modulation) to 15 (maximum modulation)";
    return description;
}

String ExposedParamDescription::buildForPolyModAmt_Osc_B() {
    String description{ "" };
    description += "Sets the degree to which oscillator B" + GUI::apostrophe + "s frequency\n";
    description += "modulates the enabled poly-mod destination(s).\n";
    description += "Range: 0 (no modulation) to 127 (maximum modulation)";
    return description;
}

String ExposedParamDescription::buildForPolyModDest_Filter() {
    String description{ "" };
    description += "Enables modulation of the filter" + GUI::apostrophe + "s cutoff\n";
    description += "frequency by the two poly-mod sources.";
    return description;
}

String ExposedParamDescription::buildForPolyModDest_Osc_A_Freq() {
    String description{ "" };
    description += "Enables modulation of oscillator A" + GUI::apostrophe + "s\n";
    description += "frequency by the two poly-mod sources.";
    return description;
}

String ExposedParamDescription::buildForUnisonTrack() {
    String description{ "" };
    description += "Enables one of the three unison keyboard tracking modes:\n";
    description += "Normal: Switch unison on while no keys are pressed. All 6 voices play\n";
    description += "at once at a single pitch (the lowest triggered note has priority).\n";
    description += "Chord Track: Switch unison on while holding down multiple notes.\n";
    description += "When new notes are triggered, the same note intervals are played,\n";
    description += "but with the lowest triggered new note as the root.\n";
    description += "Single Voice: Switch unison on while holding down a single note.\n";
    description += "Similar to normal unison, but only one voice plays at a time.";
    return description;
}
