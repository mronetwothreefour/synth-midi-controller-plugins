#include "mMod_0_build_ChoiceName.h"

#include "../constants/constants_MatrixMod.h"

using namespace Matrix_6G_Constants;

String MatrixModParamChoiceName::buildForModAmount(uint8 choiceNum) {
    return (choiceNum > 63 ? "+" : "") + String(choiceNum - 63);
}

String MatrixModParamChoiceName::buildForModDest(uint8 choiceNum, bool verbose)
{
    jassert(choiceNum < MMOD::numberOfDestChoices);
    switch (choiceNum)
    {
    case 0:
        return verbose ? "None" : "NONE";
    case 1:
        return verbose ? "Oscillator 1 Frequency" : "OSC1 FQ";
    case 2:
        return verbose ? "Oscillator 1 Pulse Width" : "OSC1 PW";
    case 3:
        return verbose ? "Oscillator 1 Saw/Tri Wave Shape" : "OSC1 W";
    case 4:
        return verbose ? "Oscillator 2 Frequency" : "OSC2 FQ";
    case 5:
        return verbose ? "Oscillator 2 Pulse Width" : "OSC2 PW";
    case 6:
        return verbose ? "Oscillator 2 Saw/Tri Wave Shape" : "OSC2 W";
    case 7:
        return verbose ? "Oscillator Mix (Balance)" : "OSC MIX";
    case 8:
        return verbose ? "VCF FM Amount" : "VCF FM";
    case 9:
        return verbose ? "VCF Cutoff Frequency" : "VCF FQ";
    case 10:
        return verbose ? "VCF Resonance" : "VCF RES";
    case 11:
        return verbose ? "VCA 1 Level" : "VCA1LVL";
    case 12:
        return verbose ? "VCA 2 Level" : "VCA2LVL";
    case 13:
        return verbose ? "Envelope 1 Delay" : "ENV1DEL";
    case 14:
        return verbose ? "Envelope 1 Attack" : "ENV1ATK";
    case 15:
        return verbose ? "Envelope 1 Decay" : "ENV1DEC";
    case 16:
        return verbose ? "Envelope 1 Release" : "ENV1REL";
    case 17:
        return verbose ? "Envelope 1 Amplitude" : "ENV1AMP";
    case 18:
        return verbose ? "Envelope 2 Delay" : "ENV2DEL";
    case 19:
        return verbose ? "Envelope 2 Attack" : "ENV2ATK";
    case 20:
        return verbose ? "Envelope 2 Decay" : "ENV2DEC";
    case 21:
        return verbose ? "Envelope 2 Release" : "ENV2REL";
    case 22:
        return verbose ? "Envelope 2 Amplitude" : "ENV2AMP";
    case 23:
        return verbose ? "Envelope 3 Delay" : "ENV3DEL";
    case 24:
        return verbose ? "Envelope 3 Attack" : "ENV3ATK";
    case 25:
        return verbose ? "Envelope 3 Decay" : "ENV3DEC";
    case 26:
        return verbose ? "Envelope 3 Release" : "ENV3REL";
    case 27:
        return verbose ? "Envelope 3 Amplitude" : "ENV3AMP";
    case 28:
        return verbose ? "LFO 1 Speed" : "LFO1SPD";
    case 29:
        return verbose ? "LFO 1 Amplitude" : "LFO1AMP";
    case 30:
        return verbose ? "LFO 2 Speed" : "LFO2SPD";
    case 31:
        return verbose ? "LFO 2 Amplitude" : "LFO2AMP";
    case 32:
        return verbose ? "Portamento Time" : "PORTA";
    default:
        return verbose ? "range error" : "err";
    }
}

String MatrixModParamChoiceName::buildForModSource(uint8 choiceNum, bool verbose)
{
    jassert(choiceNum < MMOD::numberOfSourceChoices);
    switch (choiceNum)
    {
    case 0:
        return verbose ? "None" : "NONE";
    case 1:
        return verbose ? "Envelope 1" : "ENV 1";
    case 2:
        return verbose ? "Envelope 2" : "ENV 2";
    case 3:
        return verbose ? "Envelope 3" : "ENV 3";
    case 4:
        return verbose ? "LFO 1" : "LFO 1";
    case 5:
        return verbose ? "LFO 2" : "LFO 2";
    case 6:
        return verbose ? "Vibrato LFO" : "VIBRATO";
    case 7:
        return verbose ? "Ramp Generator 1" : "RAMP 1";
    case 8:
        return verbose ? "Ramp Generator 2" : "RAMP 2";
    case 9:
        return verbose ? "Keyboard Scaling" : "KEYBD";
    case 10:
        return verbose ? "Portamento Speed" : "PORTA";
    case 11:
        return verbose ? "Tracking Generator" : "TRACK";
    case 12:
        return verbose ? "Keyboard Note Gate" : "GATE";
    case 13:
        return verbose ? "Keyboard Note Velocity" : "VELO";
    case 14:
        return verbose ? "Keyboard Release Velocity" : "R VELO";
    case 15:
        return verbose ? "Keyboard Pressure (Aftertouch)" : "PRESS";
    case 16:
        return verbose ? "Pedal 1" : "PEDAL 1";
    case 17:
        return verbose ? "Pedal 2" : "PEDAL 2";
    case 18:
        return verbose ? "Lever 1" : "LEVER 1";
    case 19:
        return verbose ? "Lever 2" : "LEVER 2";
    case 20:
        return verbose ? "Lever 3 (Lever 2 Reverse)" : "LEVER 3";
    default:
        return verbose ? "range error" : "err";
    }
}
