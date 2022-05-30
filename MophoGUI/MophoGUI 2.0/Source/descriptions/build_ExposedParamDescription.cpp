#include "build_ExposedParamDescription.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"



String ExposedParamDescription::buildFor_ArpegMode() {
    String descriptionString{ "" };
    descriptionString += "Sets the order in which the arpeggiator plays notes.\n";
    descriptionString += "Assign mode: notes play in the order in which they were struck.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_ArpegOnOff() {
    String descriptionString{ "" };
    descriptionString += "Turns the Mopho" + GUI::apostrophe + "s arpeggiator on and off.\n";
    descriptionString += "Turning this on will turn off the sequencer.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_BendRange() {
    String descriptionString{ "" };
    descriptionString += "Sets the maximum amount (in semitones) by which pitch wheel\n";
    descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
    descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_ClockDivision() {
    String descriptionString{ "" };
    descriptionString += "Sets the rate at which the sequencer and\n";
    descriptionString += "arpeggiator advance, relative to the tempo.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_ClockTempo() {
    String descriptionString{ "" };
    descriptionString += "Sets the tempo (in beats per minute)\n";
    descriptionString += "for the sequencer and the arpeggiator.\n";
    descriptionString += "Range: 30 to 250 BPM.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvAttack(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s attack segment\n";
    descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    descriptionString += "level to rise from minimum to maximum).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvDecay(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s decay segment\n";
    descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
    descriptionString += "level to fall from maximum to the sustain level).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvDelay(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s delay segment\n";
    descriptionString += "(the amount of time that passes after the envelope\n";
    descriptionString += "is triggered before its attack segment begins).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvRelease(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the length of " + theEnvelope + GUI::apostrophe + "s release segment\n";
    descriptionString += "(the amount of time it takes to fall from the sustain\n";
    descriptionString += "level down to minimum once the envelope is gated off).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvSustain(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets " + theEnvelope + GUI::apostrophe + "s sustain level (once the\n";
    descriptionString += "decay segment completes, the envelope stays\n";
    descriptionString += "at this level until it is gated off).\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_EnvVelAmount(EnvelopeType envType) {
    auto theEnvelope{ buildEnvNameString(envType) };
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI note velocity\n";
    descriptionString += "modulates the amplitude of " + theEnvelope + ".\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_Env_3_Amount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which envelope 3\n";
    descriptionString += "modulates the destination parameter.\n";
    descriptionString += "Negative values invert the envelope.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_Env_3_Repeat() {
    String descriptionString{ "" };
    descriptionString += "When repeat is on, envelope 3 loops through\n";
    descriptionString += "its delay, attack, decay, and sustain segments\n";
    descriptionString += "for as long as the envelope is gated on.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_ExtInLevel() {
    String descriptionString{ "" };
    descriptionString += "Sets the level of external audio\n";
    descriptionString += "input sent into the low-pass filter.\n";
    descriptionString += "When nothing is connected to audio in,\n";
    descriptionString += "this controls the level of feedback\n";
    descriptionString += "from the left audio output.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_GlideMode() {
    String descriptionString{ "" };
    descriptionString += "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
    descriptionString += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
    descriptionString += "The Auto modes only apply glide when a note is played legato\n";
    descriptionString += "(the new note is triggered before the previous note is released).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_KnobAssign(int knobNum) {
    String descriptionString{ "" };
    descriptionString += "Selects a target parameter for\n";
    descriptionString += "assignable hardware knob " + (String)knobNum + ".";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LFO_Amount(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which LFO " + (String)lfoNum + "\n";
    descriptionString += "modulates the destination parameter.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LFO_Freq(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "Sets LFO " + (String)lfoNum + GUI::apostrophe + "s cycle speed. Range: 0 to 166.\n";
    descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
    descriptionString += "From 90 to 150, LFO " + (String)lfoNum + " has a pitched frequency, increasing\n";
    descriptionString += "in semitone steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
    descriptionString += "Above 150, LFO " + (String)lfoNum + " is synced with the step sequencer,\n";
    descriptionString += "displayed as [number of LFO cycles] : [length in steps].";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LFO_KeySync(int lfoNum) {
    String descriptionString{ "" };
    descriptionString += "When on, LFO " + (String)lfoNum + GUI::apostrophe + "s cycle will reset\n";
    descriptionString += "each time a new note is played.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LFO_Shape(int lfoNum) {
    return "Selects LFO " + (String)lfoNum + GUI::apostrophe + "s wave shape.";
}

String ExposedParamDescription::buildFor_LPF_EnvAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which the LPF envelope\n";
    descriptionString += "modulates the filter" + GUI::apostrophe + "s cutoff frequency.\n";
    descriptionString += "Negative values invert the envelope.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LPF_FM_Amount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which oscillator 1 modulates\n";
    descriptionString += "the low-pass filter" + GUI::apostrophe + "s cutoff frequency. This is\n";
    descriptionString += "useful for generating bell-like sounds.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LPF_Freq() {
    String descriptionString{ "" };
    descriptionString += "Sets the base cutoff frequency for the low-pass filter\n";
    descriptionString += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the frequency by one octave (12 semitones).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LPF_KeyAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the amount by which keyboard (MIDI) notes\n";
    descriptionString += "will shift the low-pass filter" + GUI::apostrophe + "s cutoff frequency.\n";
    descriptionString += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
    descriptionString += "semitone for each note. At 32, cutoff is shifted\n";
    descriptionString += "by one half-semitone for each note.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LPF_Reso() {
    String descriptionString{ "" };
    descriptionString += "Sets the resonance level of the low-pass\n";
    descriptionString += "filter. When in 4-pole mode, high resonance\n";
    descriptionString += "will cause the filter to self-oscillate.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_LPF_Type() {
    String descriptionString{ "" };
    descriptionString += "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
    descriptionString += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
    descriptionString += "slope and more pronounced resonance.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_MIDI_BreathAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI breath controller\n";
    descriptionString += "messages (CC#2) modulate the destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_MIDI_ModWheelAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI modulation wheel controller\n";
    descriptionString += "messages (CC#1) modulate the destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_MIDI_PedalAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI foot pedal controller\n";
    descriptionString += "messages (CC#4) modulate the destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_MIDI_PressureAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI channel pressure\n";
    descriptionString += "(aftertouch) messages modulate the destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_MIDI_VelocityAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which MIDI note velocity\n";
    descriptionString += "messages modulate the destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\n";
    descriptionString += "Range: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_ModAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which the selected source\n";
    descriptionString += "modulates the selected destination parameter.\n";
    descriptionString += "Negative values invert the modulation.\nRange: -127 to +127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_NoiseLevel() {
    String descriptionString{ "" };
    descriptionString += "Sets the level of white noise\n";
    descriptionString += "sent into the low-pass filter.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_NotePriority() {
    String descriptionString{ "" };
    descriptionString += "Selects which note is given priority when multiple\n";
    descriptionString += "notes are played, and whether the envelopes are\n";
    descriptionString += "re-triggered when a note is played legato (before\n";
    descriptionString += "the previous note has been released).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscFine(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Fine tunes oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch.\n";
    descriptionString += "Range: -50 cents to +50 cents.\n";
    descriptionString += "0 = no detuning (centered).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscGlide(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s glide (portamento) rate.\n";
    descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscKeyTrack(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Turns keyboard tracking for oscillator " + (String)oscNum + "\n";
    descriptionString += "on or off. When turned off, the oscillator\n";
    descriptionString += "always produces its base pitch, ignoring\n";
    descriptionString += "the pitch of incoming MIDI note messages.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscMix() {
    String descriptionString{ "" };
    descriptionString += "Controls the level balance between oscillators 1 & 2.\n";
    descriptionString += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
    descriptionString += "At 127, only oscillator 2 is heard. At 64, an equal\n";
    descriptionString += "mix of the two oscillators is heard.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscPitch(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch in semitone steps.\n";
    descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the pitch by one octave (12 semitones).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscShape(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Selects oscillator " + (String)oscNum + GUI::apostrophe + "s wave shape.\n";
    descriptionString += "Hold down a number on the keyboard and click\n";
    descriptionString += "the knob to jump directly to a wave shape:\n";
    descriptionString += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
    descriptionString += "3 = Sawtooth / Triangle Mixture;\n";
    descriptionString += "4 = Square (a Pulse with width 50).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscSlop() {
    String descriptionString{ "" };
    descriptionString += "Introduces a subtle amount of random oscillator\n";
    descriptionString += "pitch drift for a " + GUI::openQuote + "vintage analog" + GUI::closeQuote + " sound.\n";
    descriptionString += "Range: 0 to 5.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscSubLevel(int oscNum) {
    String descriptionString{ "" };
    descriptionString += "Sets the level of sub-oscillator " + (String)oscNum + ",\n";
    descriptionString += "which generates a square wave pitched\n";
    descriptionString += "one octave lower than oscillator " + (String)oscNum + ".\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_OscSync() {
    String descriptionString{ "" };
    descriptionString += "Turns hard oscillator sync on or off. When\n";
    descriptionString += "turned on, every time oscillator 2 resets,\n";
    descriptionString += "it forces oscillator 1 to reset as well.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_PushItMode() {
    String descriptionString{ "" };
    descriptionString += "Sets the operating mode for the Mopho" + GUI::apostrophe + "s Push It! switch.\n";
    descriptionString += "Normal: The selected note is gated on when the switch is\n";
    descriptionString += "pressed and gated off when the switch is released.\n";
    descriptionString += "Toggle: The selected note is gated on when the switch is\n";
    descriptionString += "pressed and remains on until the switch is pressed again.\n";
    descriptionString += "Audio In: The selected note is gated on for as long as the\n";
    descriptionString += "external audio input level is above a certain threshold.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_PushItPitch() {
    String descriptionString{ "" };
    descriptionString += "Sets the note that plays when the Push It! switch is pressed.\n";
    descriptionString += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.\n";
    descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
    descriptionString += "increment the pitch by one octave (12 semitones).";
    return descriptionString;
}

String ExposedParamDescription::buildFor_PushItVelocity() {
    String descriptionString{ "" };
    descriptionString += "Sets the velocity of the note that plays\n";
    descriptionString += "when the Push It! switch is pressed.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_SeqOnOff() {
    String descriptionString{ "" };
    descriptionString += "Turns the Mopho" + GUI::apostrophe + "s internal sequencer on and off.\n";
    descriptionString += "Turning this on will turn off the arpeggiator.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_SeqTrackDestination(int trackNum) {
    String descriptionString{ "" };
    descriptionString += "Selects the target parameter for\n";
    descriptionString += "modulation by sequencer track " + (String)trackNum + ".";
    return descriptionString;
}

String ExposedParamDescription::buildFor_SeqTrackStep(int trackNum, int stepNum) {
    String descriptionString{ "" };
    descriptionString = "Sets the value that sequencer track " + (String)trackNum + GUI::apostrophe + "s destination parameter has at step " + (String)stepNum + ",\n";
    descriptionString += "Range: 0 to 125. If the target is an oscillator pitch, the range is C0 to D5+.\n";
    descriptionString += "A " + GUI::openQuote + "+" + GUI::closeQuote + " indicates that the pitch is a quarter-tone higher than the displayed note.\n";
    descriptionString += "Reset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";
    if (trackNum == 0) {
        descriptionString += "\nRest (127): The step produces no output. ALT-click a step to make it a rest\n";
        descriptionString += "(Rests are only available for the steps in sequencer track 1).";
    }
    descriptionString += "\nWhen the track destination is an oscillator pitch, holding down the\n";
    descriptionString += "SHIFT key while turning the mouse wheel will increment a step" + GUI::apostrophe + "s value \n";
    descriptionString += "by 24 (equivalent to one octave including the " + GUI::openQuote + "bent" + GUI::closeQuote + " pitches).\n";
    descriptionString += "Otherwise, the value will increment by 10.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_SeqTrigMode() {
    String descriptionString{ "" };
    descriptionString += "Normal: New notes reset the sequencer to the first step.\n";
    descriptionString += "The envelopes are re-triggered with each step.\n";
    descriptionString += "Normal, No Reset: New notes do not reset the sequencer to the\n";
    descriptionString += "first step. The envelopes are re-triggered with each step.\n";
    descriptionString += "No Gate: New notes reset the sequencer to the first step. New\n";
    descriptionString += "notes re-trigger the envelopes, but sequencer steps do not.\n";
    descriptionString += "No Gate, No Reset: New notes do not reset the sequencer to the\n";
    descriptionString += "first step. Sequencer steps do not re-trigger the envelopes.\n";
    descriptionString += "Key Step: Each new note advances the sequencer one step.\n";
    descriptionString += "Audio Input: The sequencer advances one step every time the\n";
    descriptionString += "external audio input level surpasses a certain threshold.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_VCA_EnvAmount() {
    String descriptionString{ "" };
    descriptionString += "Sets the degree to which the VCA envelope\n";
    descriptionString += "modulates the voltage-controlled ampifier" + GUI::apostrophe + "s level.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_VCA_Level() {
    String descriptionString{ "" };
    descriptionString += "Sets the voltage-controlled amplifier" + GUI::apostrophe + "s baseline level. Turn this\n";
    descriptionString += "up for droning sounds or when processing external audio input.\n";
    descriptionString += "When this level is set to 127, the VCA envelope has no effect.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_VoiceNameChar(int charNum) {
    String descriptionString{ "" };
    descriptionString += "To change character " + (String)charNum + " of the program" + GUI::apostrophe + "s name,\n";
    descriptionString += "click-and-drag the character or hover over\n";
    descriptionString += "it and turn the mouse wheel. Click the edit\n";
    descriptionString += "button above to type in the entire name.";
    return descriptionString;
}

String ExposedParamDescription::buildFor_VoiceVolume() {
    String descriptionString{ "" };
    descriptionString += "Sets the overall gain of the current program.\n";
    descriptionString += "Range: 0 to 127.";
    return descriptionString;
}

String ExposedParamDescription::buildEnvNameString(EnvelopeType envType) {
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