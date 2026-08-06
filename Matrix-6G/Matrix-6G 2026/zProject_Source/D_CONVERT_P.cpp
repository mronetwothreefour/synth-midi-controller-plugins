#include "D_CONVERT_P.h"

const String Convert_P::int_to_mmod_amt(const int i, bool curt) {
	if (i < 128)
		return (i > 63 ? "+" : "") + String{ i - 63 };
	return curt ? "ERR" : "range error";
}

const String Convert_P::int_to_mmod_dest(const int i, bool curt) {
    switch (i)
    {
    case 0: return curt ? "NONE" : "none";
    case 1: return curt ? "OSC1 FQ" : "oscillator 1 frequency";
    case 2: return curt ? "OSC1 PW" : "oscillator 1 pulse width";
    case 3: return curt ? "OSC1 W" : "oscillator 1 saw/tri wave shape";
    case 4: return curt ? "OSC2 FQ" : "oscillator 2 frequency";
	case 5: return curt ? "OSC2 PW" : "oscillator 2 pulse width";
	case 6: return curt ? "OSC2 W" : "oscillator 2 saw/tri wave shape";
    case 7: return curt ? "OSC MIX" : "oscillator mix (balance)";
    case 8: return curt ? "VCF FM" : "VCF FM amount";
    case 9: return curt ? "VCF FQ" : "VCF cutoff frequency";
    case 10: return curt ? "VCF RES" : "VCF resonance";
    case 11: return curt ? "VCA1LVL" : "VCA 1 level";
    case 12: return curt ? "VCA2LVL" : "VCA 2 level";
    case 13: return curt ? "ENV1DEL" : "envelope 1 delay";
    case 14: return curt ? "ENV1ATK" : "envelope 1 attack";
    case 15: return curt ? "ENV1DEC" : "envelope 1 decay";
    case 16: return curt ? "ENV1REL" : "envelope 1 release";
    case 17: return curt ? "ENV1AMP" : "envelope 1 amplitude";
    case 18: return curt ? "ENV2DEL" : "envelope 2 delay";
	case 19: return curt ? "ENV2ATK" : "envelope 2 attack";
	case 20: return curt ? "ENV2DEC" : "envelope 2 decay";
	case 21: return curt ? "ENV2REL" : "envelope 2 release";
	case 22: return curt ? "ENV2AMP" : "envelope 2 amplitude";
    case 23: return curt ? "ENV3DEL" : "envelope 3 delay";
	case 24: return curt ? "ENV3ATK" : "envelope 3 attack";
	case 25: return curt ? "ENV3DEC" : "envelope 3 decay";
	case 26: return curt ? "ENV3REL" : "envelope 3 release";
	case 27: return curt ? "ENV3AMP" : "envelope 3 amplitude";
	case 28: return curt ? "LFO1SPD" : "LFO 1 speed";
	case 29: return curt ? "LFO1AMP" : "LFO 1 amplitude";
	case 30: return curt ? "LFO2SPD" : "LFO 2 speed";
	case 31: return curt ? "LFO2AMP" : "LFO 2 amplitude";
	case 32: return curt ? "PORTA" : "portamento time";
    default: return curt ? "range error" : "ERR";
    }
}

const String Convert_P::int_to_mmod_src(const int i, bool curt) {
	switch (i) {
		case 0: return curt ? "NONE" : "none";
		case 1: return curt ? "ENV 1" : "envelope 1";
		case 2: return curt ? "ENV 2" : "envelope 2";
		case 3: return curt ? "ENV 3" : "envelope 3";
		case 4: return curt ? "LFO 1" : "LFO 1";
		case 5: return curt ? "LFO 2" : "LFO 2";
		case 6: return curt ? "VIBRATO" : "vibrato LFO";
		case 7: return curt ? "RAMP 1" : "ramp generator 1";
		case 8: return curt ? "RAMP 2" : "ramp generator 2";
		case 9: return curt ? "KEYBD" : "keyboard scaling";
		case 10: return curt ? "PORTA" : "portamento speed";
		case 11: return curt ? "TRACK" : "tracking generator";
		case 12: return curt ? "GATE" : "keyboard note gate";
		case 13: return curt ? "VELO" : "keyboard note velocity";
		case 14: return curt ? "R VELO" : "keyboard release velocity";
		case 15: return curt ? "PRESS" : "keyboard pressure (aftertouch)";
		case 16: return curt ? "PEDAL 1" : "pedal 1";
		case 17: return curt ? "PEDAL 2" : "pedal 2";
		case 18: return curt ? "LEVER 1" : "lever 1 ";
		case 19: return curt ? "LEVER 2" : "lever 2";
		case 20: return curt ? "LEVER 3" : "lever 3 (lever 2 reverse)";
		default: return curt ? "ERR" : "range error";
	}
}
