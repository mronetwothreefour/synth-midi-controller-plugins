#include "build_ExposedParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"

String ExposedParamDescription::buildForArpegMode() {
    String description{ "" };
    description += "Sets the order in which the arpeggiator plays notes.\n";
    description += "Assign mode: notes play in the order in which they were struck.";
    return description;
}

String ExposedParamDescription::buildForArpegOnOff() {
    String description{ "" };
    description += "Turns the Mopho" + GUI::apostrophe + "s arpeggiator on and off.\n";
    description += "Turning this on will turn off the sequencer.";
    return description;
}

String ExposedParamDescription::buildForBendRange() {
    String description{ "" };
    description += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    description += "messages can raise or lower the pitches of the oscillators.\n";
    description += "Range: 0 (no pitch bend) to +/-12 semitones.";
    return description;
}

String ExposedParamDescription::buildForClockDivision() {
    String description{ "" };
    description += "Sets the rate at which the sequencer and\n";
    description += "arpeggiator advance, relative to the tempo.";
    return description;
}

String ExposedParamDescription::buildForClockTempo() {
    String description{ "" };
    description += "Sets the tempo (in beats per minute)\n";
    description += "for the sequencer and the arpeggiator.\n";
    description += "Range: 30 to 250 BPM.";
    return description;
}

String ExposedParamDescription::buildForEnvAttack(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets the length of " + theEnvelope + GUI::apostrophe + "s attack segment\n";
    description += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    description += "level to rise from minimum to maximum).\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnvDecay(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets the length of " + theEnvelope + GUI::apostrophe + "s decay segment\n";
    description += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    description += "level to fall from maximum to the sustain level).\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnvDelay(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets the length of " + theEnvelope + GUI::apostrophe + "s delay segment\n";
    description += "(the amount of time that passes after the envelope\n";
    description += "is triggered before its attack segment begins).\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnvRelease(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets the length of " + theEnvelope + GUI::apostrophe + "s release segment\n";
    description += "(the amount of time it takes to fall from the sustain\n";
    description += "level down to minimum once the envelope is gated off).\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnvSustain(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets " + theEnvelope + GUI::apostrophe + "s sustain level (once the\n";
    description += "decay segment completes, the envelope stays\n";
    description += "at this level until it is gated off).\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnvVelAmount(const EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String description{ "" };
    description += "Sets the degree to which MIDI note velocity\n";
    description += "modulates the amplitude of " + theEnvelope + ".\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForEnv_3_Amount() {
    String description{ "" };
    description += "Sets the degree to which envelope 3\n";
    description += "modulates the destination parameter.\n";
    description += "Negative values invert the envelope.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildForEnv_3_Repeat() {
    String description{ "" };
    description += "When repeat is on, envelope 3 loops through\n";
    description += "its delay, attack, decay, and sustain segments\n";
    description += "for as long as the envelope is gated on.";
    return description;
}

String ExposedParamDescription::buildForExtInLevel() {
    String description{ "" };
    description += "Sets the level of external audio\n";
    description += "input sent into the low-pass filter.\n";
    description += "When nothing is connected to audio in,\n";
    description += "this controls the level of feedback\n";
    description += "from the left audio output.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForGlideMode() {
    String description{ "" };
    description += "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
    description += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
    description += "The Auto modes only apply glide when a note is played legato\n";
    description += "(the new note is triggered before the previous note is released).";
    return description;
}

String ExposedParamDescription::buildForKnobAssign(const int knobNum) {
    String description{ "" };
    description += "Selects a target parameter for\n";
    description += "assignable hardware knob " + (String)knobNum + ".";
    return description;
}

String ExposedParamDescription::buildForModAmount() {
    String description{ "" };
    description += "Sets the degree to which the selected source\n";
    description += "modulates the selected destination parameter.\n";
    description += "Negative values invert the modulation.\nRange: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildForNoiseLevel() {
    String description{ "" };
    description += "Sets the level of white noise\n";
    description += "sent into the low-pass filter.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForNotePriority() {
    String description{ "" };
    description += "Selects which note is given priority when multiple\n";
    description += "notes are played, and whether the envelopes are\n";
    description += "re-triggered when a note is played legato (before\n";
    description += "the previous note has been released).";
    return description;
}

String ExposedParamDescription::buildForOscFine(const int oscNum) {
    String description{ "" };
    description += "Fine tunes oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch.\n";
    description += "Range: -50 cents to +50 cents.\n";
    description += "0 = no detuning (centered).";
    return description;
}

String ExposedParamDescription::buildForOscGlide(const int oscNum) {
    String description{ "" };
    description += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s glide (portamento) rate.\n";
    description += "Range: 0 (instantaneous) to 127 (very slow)";
    return description;
}

String ExposedParamDescription::buildForOscKeyTrack(const int oscNum) {
    String description{ "" };
    description += "Turns keyboard tracking for oscillator " + (String)oscNum + "\n";
    description += "on or off. When turned off, the oscillator\n";
    description += "always produces its base pitch, ignoring\n";
    description += "the pitch of incoming MIDI note messages.";
    return description;
}

String ExposedParamDescription::buildForOscMix() {
    String description{ "" };
    description += "Controls the level balance between oscillators 1 & 2.\n";
    description += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
    description += "At 127, only oscillator 2 is heard. At 64, an equal\n";
    description += "mix of the two oscillators is heard.";
    return description;
}

String ExposedParamDescription::buildForOscPitch(const int oscNum) {
    String description{ "" };
    description += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch in semitone steps.\n";
    description += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
    description += "Hold down the SHIFT key when using the mouse wheel to\n";
    description += "increment the pitch by one octave (12 semitones).";
    return description;
}

String ExposedParamDescription::buildForOscShape(const int oscNum) {
    String description{ "" };
    description += "Selects oscillator " + (String)oscNum + GUI::apostrophe + "s wave shape.\n";
    description += "Hold down a number on the keyboard and click\n";
    description += "the knob to jump directly to a wave shape:\n";
    description += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
    description += "3 = Sawtooth / Triangle Mixture;\n";
    description += "4 = Square (a Pulse with width 50).";
    return description;
}

String ExposedParamDescription::buildForOscSlop() {
    String description{ "" };
    description += "Introduces a subtle amount of random oscillator\n";
    description += "pitch drift for a " + GUI::openQuote + "vintage analog" + GUI::closeQuote + " sound.\n";
    description += "Range: 0 to 5.";
    return description;
}

String ExposedParamDescription::buildForOscSubLevel(const int oscNum) {
    String description{ "" };
    description += "Sets the level of sub-oscillator " + (String)oscNum + ",\n";
    description += "which generates a square wave pitched\n";
    description += "one octave lower than oscillator " + (String)oscNum + ".\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForOscSync() {
    String description{ "" };
    description += "Turns hard oscillator sync on or off. When\n";
    description += "turned on, every time oscillator 2 resets,\n";
    description += "it forces oscillator 1 to reset as well.";
    return description;
}

String ExposedParamDescription::buildForPushItMode() {
    String description{ "" };
    description += "Sets the operating mode for the Mopho" + GUI::apostrophe + "s Push It! switch.\n";
    description += "Normal: The selected note is gated on when the switch is\n";
    description += "pressed and gated off when the switch is released.\n";
    description += "Toggle: The selected note is gated on when the switch is\n";
    description += "pressed and remains on until the switch is pressed again.\n";
    description += "Audio In: The selected note is gated on for as long as the\n";
    description += "external audio input level is above a certain threshold.";
    return description;
}

String ExposedParamDescription::buildForPushItPitch() {
    String description{ "" };
    description += "Sets the note that plays when the Push It! switch is pressed.\n";
    description += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.\n";
    description += "Hold down the SHIFT key when using the mouse wheel to\n";
    description += "increment the pitch by one octave (12 semitones).";
    return description;
}

String ExposedParamDescription::buildForPushItVelocity() {
    String description{ "" };
    description += "Sets the velocity of the note that plays\n";
    description += "when the Push It! switch is pressed.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildForSeqOnOff() {
    String description{ "" };
    description += "Turns the Mopho" + GUI::apostrophe + "s internal sequencer on and off.\n";
    description += "Turning this on will turn off the arpeggiator.";
    return description;
}

String ExposedParamDescription::buildForSeqTrackDestination(const int trackNum) {
    String description{ "" };
    description += "Selects the target parameter for\n";
    description += "modulation by sequencer track " + (String)trackNum + ".";
    return description;
}

String ExposedParamDescription::buildForSeqTrackStep(const int trackNum, int stepNum) {
    String description{ "" };
    description = "Sets the value that sequencer track " + (String)trackNum + GUI::apostrophe + "s destination parameter has at step " + (String)stepNum + ",\n";
    description += "Range: 0 to 125. If the target is an oscillator pitch, the range is C0 to D5+.\n";
    description += "A " + GUI::openQuote + "+" + GUI::closeQuote + " indicates that the pitch is a quarter-tone higher than the displayed note.\n";
    description += "Reset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";
    if (trackNum == 0) {
        description += "\nRest (127): The step produces no output. ALT-click a step to make it a rest\n";
        description += "(Rests are only available for the steps in sequencer track 1).";
    }
    description += "\nWhen the track destination is an oscillator pitch, holding down the\n";
    description += "SHIFT key while turning the mouse wheel will increment a step" + GUI::apostrophe + "s value \n";
    description += "by 24 (equivalent to one octave including the " + GUI::openQuote + "bent" + GUI::closeQuote + " pitches).\n";
    description += "Otherwise, the value will increment by 10.";
    return description;
}

String ExposedParamDescription::buildForSeqTrigMode() {
    String description{ "" };
    description += "Normal: New notes reset the sequencer to the first step.\n";
    description += "The envelopes are re-triggered with each step.\n";
    description += "Normal, No Reset: New notes do not reset the sequencer to the\n";
    description += "first step. The envelopes are re-triggered with each step.\n";
    description += "No Gate: New notes reset the sequencer to the first step. New\n";
    description += "notes re-trigger the envelopes, but sequencer steps do not.\n";
    description += "No Gate, No Reset: New notes do not reset the sequencer to the\n";
    description += "first step. Sequencer steps do not re-trigger the envelopes.\n";
    description += "Key Step: Each new note advances the sequencer one step.\n";
    description += "Audio Input: The sequencer advances one step every time the\n";
    description += "external audio input level surpasses a certain threshold.";
    return description;
}

String ExposedParamDescription::buildForVoiceNameChar(const int charNum) {
    String description{ "" };
    description += "To change character " + (String)charNum + " of the program" + GUI::apostrophe + "s name,\n";
    description += "click-and-drag the character or hover over\n";
    description += "it and turn the mouse wheel. Click the edit\n";
    description += "button above to type in the entire name.";
    return description;
}

String ExposedParamDescription::buildForVoiceVolume() {
    String description{ "" };
    description += "Sets the overall gain of the current program.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Amount(const int lfoNum) {
    String description{ "" };
    description += "Sets the degree to which LFO " + (String)lfoNum + "\n";
    description += "modulates the destination parameter.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Freq(const int lfoNum) {
    String description{ "" };
    description += "Sets LFO " + (String)lfoNum + GUI::apostrophe + "s cycle speed. Range: 0 to 166.\n";
    description += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
    description += "From 90 to 150, LFO " + (String)lfoNum + " has a pitched frequency, increasing\n";
    description += "in semitone steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
    description += "Above 150, LFO " + (String)lfoNum + " is synced with the step sequencer,\n";
    description += "displayed as [number of LFO cycles] : [length in steps].";
    return description;
}

String ExposedParamDescription::buildFor_LFO_KeySync(const int lfoNum) {
    String description{ "" };
    description += "When on, LFO " + (String)lfoNum + GUI::apostrophe + "s cycle will reset\n";
    description += "each time a new note is played.";
    return description;
}

String ExposedParamDescription::buildFor_LFO_Shape(const int lfoNum) {
    return "Selects LFO " + (String)lfoNum + GUI::apostrophe + "s wave shape.";
}

String ExposedParamDescription::buildFor_LPF_EnvAmount() {
    String description{ "" };
    description += "Sets the degree to which the LPF envelope\n";
    description += "modulates the filter" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "Negative values invert the envelope.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_LPF_FM_Amount() {
    String description{ "" };
    description += "Sets the degree to which oscillator 1 modulates\n";
    description += "the low-pass filter" + GUI::apostrophe + "s cutoff frequency. This is\n";
    description += "useful for generating bell-like sounds.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_LPF_Freq() {
    String description{ "" };
    description += "Sets the base cutoff frequency for the low-pass filter\n";
    description += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
    description += "Hold down the SHIFT key when using the mouse wheel to\n";
    description += "increment the frequency by one octave (12 semitones).";
    return description;
}

String ExposedParamDescription::buildFor_LPF_KeyAmount() {
    String description{ "" };
    description += "Sets the amount by which keyboard (MIDI) notes\n";
    description += "will shift the low-pass filter" + GUI::apostrophe + "s cutoff frequency.\n";
    description += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
    description += "semitone for each note. At 32, cutoff is shifted\n";
    description += "by one half-semitone for each note.";
    return description;
}

String ExposedParamDescription::buildFor_LPF_Reso() {
    String description{ "" };
    description += "Sets the resonance level of the low-pass\n";
    description += "filter. When in 4-pole mode, high resonance\n";
    description += "will cause the filter to self-oscillate.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_LPF_Type() {
    String description{ "" };
    description += "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
    description += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
    description += "slope and more pronounced resonance.";
    return description;
}

String ExposedParamDescription::buildFor_MIDI_BreathAmount() {
    String description{ "" };
    description += "Sets the degree to which MIDI breath controller\n";
    description += "messages (CC#2) modulate the destination parameter.\n";
    description += "Negative values invert the modulation.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_MIDI_ModWheelAmount() {
    String description{ "" };
    description += "Sets the degree to which MIDI modulation wheel controller\n";
    description += "messages (CC#1) modulate the destination parameter.\n";
    description += "Negative values invert the modulation.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_MIDI_PedalAmount() {
    String description{ "" };
    description += "Sets the degree to which MIDI foot pedal controller\n";
    description += "messages (CC#4) modulate the destination parameter.\n";
    description += "Negative values invert the modulation.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_MIDI_PressureAmount() {
    String description{ "" };
    description += "Sets the degree to which MIDI channel pressure\n";
    description += "(aftertouch) messages modulate the destination parameter.\n";
    description += "Negative values invert the modulation.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_MIDI_VelocityAmount() {
    String description{ "" };
    description += "Sets the degree to which MIDI note velocity\n";
    description += "messages modulate the destination parameter.\n";
    description += "Negative values invert the modulation.\n";
    description += "Range: -127 to +127.";
    return description;
}

String ExposedParamDescription::buildFor_VCA_EnvAmount() {
    String description{ "" };
    description += "Sets the degree to which the VCA envelope\n";
    description += "modulates the voltage-controlled ampifier" + GUI::apostrophe + "s level.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildFor_VCA_Level() {
    String description{ "" };
    description += "Sets the voltage-controlled amplifier" + GUI::apostrophe + "s baseline level. Turn this\n";
    description += "up for droning sounds or when processing external audio input.\n";
    description += "When this level is set to 127, the VCA envelope has no effect.\n";
    description += "Range: 0 to 127.";
    return description;
}

String ExposedParamDescription::buildEnvNameString(const EnvelopeType envType) {
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

