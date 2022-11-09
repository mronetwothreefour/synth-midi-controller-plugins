#include "mMod_0_build_ChoiceName.h"

#include "../constants/constants_MatrixMod.h"

String MatrixModParamChoiceName::buildForModAmount(uint8 choiceNum) {
    return (choiceNum > 63 ? "+" : "") + String(choiceNum - 63);
}

String MatrixModParamChoiceName::buildForModDest(uint8 choiceNum, ChoiceNameType type)
{
    jassert(choiceNum < MMOD::numberOfDestChoices);
    switch (choiceNum)
    {
    case 0:
        return type == ChoiceNameType::verbose ? "None" : "NONE";
    case 1:
        return type == ChoiceNameType::verbose ? "Oscillator 1 Frequency" : "OSC1 FQ";
    case 2:
        return type == ChoiceNameType::verbose ? "Oscillator 1 Pulse Width" : "OSC1 PW";
    case 3:
        return type == ChoiceNameType::verbose ? "Oscillator 1 Saw/Tri Wave Shape" : "OSC1 W";
    case 4:
        return type == ChoiceNameType::verbose ? "Oscillator 2 Frequency" : "OSC2 FQ";
    case 5:
        return type == ChoiceNameType::verbose ? "Oscillator 2 Pulse Width" : "OSC2 PW";
    case 6:
        return type == ChoiceNameType::verbose ? "Oscillator 2 Saw/Tri Wave Shape" : "OSC2 W";
    case 7:
        return type == ChoiceNameType::verbose ? "Oscillator Mix (Balance)" : "OSC MIX";
    case 8:
        return type == ChoiceNameType::verbose ? "VCF FM Amount" : "VCF FM";
    case 9:
        return type == ChoiceNameType::verbose ? "VCF Cutoff Frequency" : "VCF FQ";
    case 10:
        return type == ChoiceNameType::verbose ? "VCF Resonance" : "VCF RES";
    case 11:
        return type == ChoiceNameType::verbose ? "VCA 1 Level" : "VCA1LVL";
    case 12:
        return type == ChoiceNameType::verbose ? "VCA 2 Level" : "VCA2LVL";
    case 13:
        return type == ChoiceNameType::verbose ? "Envelope 1 Delay" : "ENV1DEL";
    case 14:
        return type == ChoiceNameType::verbose ? "Envelope 1 Attack" : "ENV1ATK";
    case 15:
        return type == ChoiceNameType::verbose ? "Envelope 1 Decay" : "ENV1DEC";
    case 16:
        return type == ChoiceNameType::verbose ? "Envelope 1 Release" : "ENV1REL";
    case 17:
        return type == ChoiceNameType::verbose ? "Envelope 1 Amplitude" : "ENV1AMP";
    case 18:
        return type == ChoiceNameType::verbose ? "Envelope 2 Delay" : "ENV2DEL";
    case 19:
        return type == ChoiceNameType::verbose ? "Envelope 2 Attack" : "ENV2ATK";
    case 20:
        return type == ChoiceNameType::verbose ? "Envelope 2 Decay" : "ENV2DEC";
    case 21:
        return type == ChoiceNameType::verbose ? "Envelope 2 Release" : "ENV2REL";
    case 22:
        return type == ChoiceNameType::verbose ? "Envelope 2 Amplitude" : "ENV2AMP";
    case 23:
        return type == ChoiceNameType::verbose ? "Envelope 3 Delay" : "ENV3DEL";
    case 24:
        return type == ChoiceNameType::verbose ? "Envelope 3 Attack" : "ENV3ATK";
    case 25:
        return type == ChoiceNameType::verbose ? "Envelope 3 Decay" : "ENV3DEC";
    case 26:
        return type == ChoiceNameType::verbose ? "Envelope 3 Release" : "ENV3REL";
    case 27:
        return type == ChoiceNameType::verbose ? "Envelope 3 Amplitude" : "ENV3AMP";
    case 28:
        return type == ChoiceNameType::verbose ? "LFO 1 Speed" : "LFO1SPD";
    case 29:
        return type == ChoiceNameType::verbose ? "LFO 1 Amplitude" : "LFO1AMP";
    case 30:
        return type == ChoiceNameType::verbose ? "LFO 2 Speed" : "LFO2SPD";
    case 31:
        return type == ChoiceNameType::verbose ? "LFO 2 Amplitude" : "LFO2AMP";
    case 32:
        return type == ChoiceNameType::verbose ? "Portamento Time" : "PORTA";
    default:
        return type == ChoiceNameType::verbose ? "range error" : "err";
    }
}

String MatrixModParamChoiceName::buildForModSource(uint8 choiceNum, ChoiceNameType type)
{
    jassert(choiceNum < MMOD::numberOfSrcChoices);
    switch (choiceNum)
    {
    case 0:
        return type == ChoiceNameType::verbose ? "None" : "NONE";
    case 1:
        return type == ChoiceNameType::verbose ? "Envelope 1" : "ENV 1";
    case 2:
        return type == ChoiceNameType::verbose ? "Envelope 2" : "ENV 2";
    case 3:
        return type == ChoiceNameType::verbose ? "Envelope 3" : "ENV 3";
    case 4:
        return type == ChoiceNameType::verbose ? "LFO 1" : "LFO 1";
    case 5:
        return type == ChoiceNameType::verbose ? "LFO 2" : "LFO 2";
    case 6:
        return type == ChoiceNameType::verbose ? "Vibrato LFO" : "VIBRATO";
    case 7:
        return type == ChoiceNameType::verbose ? "Ramp Generator 1" : "RAMP 1";
    case 8:
        return type == ChoiceNameType::verbose ? "Ramp Generator 2" : "RAMP 2";
    case 9:
        return type == ChoiceNameType::verbose ? "Keyboard Scaling" : "KEYBD";
    case 10:
        return type == ChoiceNameType::verbose ? "Portamento Speed" : "PORTA";
    case 11:
        return type == ChoiceNameType::verbose ? "Tracking Generator" : "TRACK";
    case 12:
        return type == ChoiceNameType::verbose ? "Keyboard Note Gate" : "GATE";
    case 13:
        return type == ChoiceNameType::verbose ? "Keyboard Note Velocity" : "VELO";
    case 14:
        return type == ChoiceNameType::verbose ? "Keyboard Release Velocity" : "R VELO";
    case 15:
        return type == ChoiceNameType::verbose ? "Keyboard Pressure (Aftertouch)" : "PRESS";
    case 16:
        return type == ChoiceNameType::verbose ? "Pedal 1" : "PEDAL 1";
    case 17:
        return type == ChoiceNameType::verbose ? "Pedal 2" : "PEDAL 2";
    case 18:
        return type == ChoiceNameType::verbose ? "Lever 1" : "LEVER 1";
    case 19:
        return type == ChoiceNameType::verbose ? "Lever 2" : "LEVER 2";
    case 20:
        return type == ChoiceNameType::verbose ? "Lever 3 (Lever 2 Reverse)" : "LEVER 3";
    default:
        return type == ChoiceNameType::verbose ? "range error" : "err";
    }
}
