#include "ep_build_DescriptionString.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace MophoConstants;



String DescriptionString::buildFor_BendRange() {
    String descriptionString{ "" };
    descriptionString += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
    descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
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

String DescriptionString::buildFor_LPF_Freq()
{
    String descriptionString{ "" };
    descriptionString += "Sets the base cutoff frequency for the low-pass filter\n";
    descriptionString += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the frequency by one octave (12 semitones).";
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
