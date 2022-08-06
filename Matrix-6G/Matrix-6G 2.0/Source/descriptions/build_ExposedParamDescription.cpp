#include "build_ExposedParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

using namespace Matrix_6G_Constants;

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
