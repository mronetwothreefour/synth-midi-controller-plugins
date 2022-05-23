#include "ep_build_DescriptionString.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"



String DescriptionString::buildFor_BendRange() {
    String descriptionString{ "" };
    descriptionString += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
    descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvAttack(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s attack segment\n";
    descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    descriptionString += "level to rise from minimum to maximum).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvDecay(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s decay segment\n";
    descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    descriptionString += "level to fall from maximum to the sustain level).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvDelay(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s delay segment\n";
    descriptionString += "(the amount of time that passes after the envelope\n";
    descriptionString += "is triggered before its attack segment begins).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvRelease(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s release segment\n";
    descriptionString += "(the amount of time it takes to fall from the sustain\n";
    descriptionString += "level down to minimum once the envelope is gated off).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvSustain(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets " + theEnvelope + GUI::apostrophe + "s sustain level (once the\n";
    descriptionString += "decay segment completes, the envelope stays\n";
    descriptionString += "at this level until it is gated off).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_EnvVelAmount(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI note velocity\n";
    descriptionString += "modulates the amplitude of " + theEnvelope + ".\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_ExtInLevel() {
    String descriptionString{ "" };
    descriptionString += "Sets the level of external audio\n";
    descriptionString += "input sent into the low-pass filter.\n";
    descriptionString += "When nothing is connected to audio in,\n";
    descriptionString += "this controls the level of feedback\n";
    descriptionString += "from the left audio output.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_GlideMode() {
    String descriptionString{ "" };
    descriptionString += "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
    descriptionString += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
    descriptionString += "The Auto modes only apply glide when a note is played legato\n";
    descriptionString += "(the new note is triggered before the previous note is released).";
    return descriptionString;
}

String DescriptionString::buildFor_LFO_Amount(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which LFO " + (String)lfoNum + "\n";
    descriptionString += "modulates the destination parameter.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_LFO_Destination(int lfoNum) {
    return "Selects the target parameter for modulation by LFO " + (String)lfoNum + ".";
}

String DescriptionString::buildFor_LFO_Freq(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "Sets LFO " + (String)lfoNum + GUI::apostrophe + "s cycle speed. Range: 0 to 166.\n";
    descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
    descriptionString += "From 90 to 150, LFO " + (String)lfoNum + " has a pitched frequency, increasing\n";
    descriptionString += "in semitone steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
    descriptionString += "Above 150, LFO " + (String)lfoNum + " is synced with the step sequencer,\n";
    descriptionString += "displayed as [number of LFO cycles] : [length in steps].";
    return descriptionString;
}

String DescriptionString::buildFor_LFO_KeySync(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "When on, LFO " + (String)lfoNum + GUI::apostrophe + "s cycle will reset\n";
    descriptionString += "each time a new note is played.";
    return descriptionString;
}

String DescriptionString::buildFor_LFO_Shape(int lfoNum) {
    return "Selects LFO " + (String)lfoNum + GUI::apostrophe + "s wave shape.";
}

String DescriptionString::buildFor_LPF_EnvAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which the LPF envelope\n";
    descriptionString += "modulates the filter" + GUI::apostrophe + "s cutoff frequency.\n";
    descriptionString += "Negative values invert the envelope.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String DescriptionString::buildFor_LPF_FM_Amount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which oscillator 1 modulates\n";
    descriptionString += "the low-pass filter" + GUI::apostrophe + "s cutoff frequency. This is\n";
    descriptionString += "useful for generating bell-like sounds.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_LPF_Freq() {
    String descriptionString{ "" };
    descriptionString += "Sets the base cutoff frequency for the low-pass filter\n";
    descriptionString += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the frequency by one octave (12 semitones).";
    return descriptionString;
}

String DescriptionString::buildFor_LPF_KeyAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the amount by which keyboard (MIDI) notes\n";
    descriptionString += "will shift the low-pass filter" + GUI::apostrophe + "s cutoff frequency.\n";
    descriptionString += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
    descriptionString += "semitone for each note. At 32, cutoff is shifted\n";
    descriptionString += "by one half-semitone for each note.";
    return descriptionString;
}

String DescriptionString::buildFor_LPF_Reso() {
    String descriptionString{ "" };
    descriptionString += "Sets the resonance level of the low-pass\n";
    descriptionString += "filter. When in 4-pole mode, high resonance\n";
    descriptionString += "will cause the filter to self-oscillate.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_LPF_Type() {
    String descriptionString{ "" };
    descriptionString += "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
    descriptionString += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
    descriptionString += "slope and more pronounced resonance.";
    return descriptionString;
}

String DescriptionString::buildFor_NoiseLevel() {
    String descriptionString{ "" };
    descriptionString += "Sets the level of white noise\n";
    descriptionString += "sent into the low-pass filter.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_NotePriority() {
    String descriptionString{ "" };
    descriptionString += "Selects which note is given priority when multiple\n";
    descriptionString += "notes are played, and whether the envelopes are\n";
    descriptionString += "re-triggered when a note is played legato (before\n";
    descriptionString += "the previous note has been released).";
    return descriptionString;
}

String DescriptionString::buildFor_OscFine(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Fine tunes oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch.\n";
    descriptionString += "Range: -50 cents to +50 cents.\n";
    descriptionString += "0 = no detuning (centered).";
    return descriptionString;
}

String DescriptionString::buildFor_OscGlide(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s glide (portamento) rate.\n";
    descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
    return descriptionString;
}

String DescriptionString::buildFor_OscKeyTrack(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Turns keyboard tracking for oscillator " + (String)oscNum + "\n";
    descriptionString += "on or off. When turned off, the oscillator\n";
    descriptionString += "always produces its base pitch, ignoring\n";
    descriptionString += "the pitch of incoming MIDI note messages.";
    return descriptionString;
}

String DescriptionString::buildFor_OscMix() {
    String descriptionString{ "" };
    descriptionString += "Controls the level balance between oscillators 1 & 2.\n";
    descriptionString += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
    descriptionString += "At 127, only oscillator 2 is heard. At 64, an equal\n";
    descriptionString += "mix of the two oscillators is heard.";
    return descriptionString;
}

String DescriptionString::buildFor_OscPitch(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch in semitone steps.\n";
    descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the pitch by one octave (12 semitones).";
    return descriptionString;
}

String DescriptionString::buildFor_OscShape(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Selects oscillator " + (String)oscNum + GUI::apostrophe + "s wave shape.\n";
    descriptionString += "Hold down a number on the keyboard and click\n";
    descriptionString += "the knob to jump directly to a wave shape:\n";
    descriptionString += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
    descriptionString += "3 = Sawtooth / Triangle Mixture;\n";
    descriptionString += "4 = Square (a Pulse with width 50).";
    return descriptionString;
}

String DescriptionString::buildFor_OscSlop() {
    String descriptionString{ "" };
    descriptionString += "Introduces a subtle amount of random oscillator\n";
    descriptionString += "pitch drift for a " + GUI::openQuote + "vintage analog" + GUI::closeQuote + " sound.\n";
    descriptionString += "Range: 0 to 5.";
    return descriptionString;
}

String DescriptionString::buildFor_OscSubLevel(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets the level of sub-oscillator " + (String)oscNum + ",\n";
    descriptionString += "which generates a square wave pitched\n";
    descriptionString += "one octave lower than oscillator " + (String)oscNum + ".\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_OscSync() {
    String descriptionString{ "" };
    descriptionString += "Turns hard oscillator sync on or off. When\n";
    descriptionString += "turned on, every time oscillator 2 resets,\n";
    descriptionString += "it forces oscillator 1 to reset as well.";
    return descriptionString;
}

String DescriptionString::buildFor_VCA_EnvAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which the VCA envelope\n";
    descriptionString += "modulates the voltage-controlled ampifier" + GUI::apostrophe + "s level.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_VCA_Level() {
    String descriptionString{ "" };
    descriptionString += "Sets the voltage-controlled amplifier" + GUI::apostrophe + "s baseline level. Turn this\n";
    descriptionString += "up for droning sounds or when processing external audio input.\n";
    descriptionString += "When this level is set to 127, the VCA envelope has no effect.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildFor_VoiceVolume() {
    String descriptionString{ "" };
    descriptionString += "Sets the overall gain of the current program.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String DescriptionString::buildEnvNameString(EnvelopeType envType) {
    switch (envType)
    {
    case EnvelopeType::env_3:
        return "envelope 3";
    case EnvelopeType::lpf:
        return "the LPF envelope";
    case EnvelopeType::vca:
        return "the VCA envelope";
    default:
        break;
    }
    return String();
}
