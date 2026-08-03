#include "D_CONVERT_P.h"

const String Convert_P::int_to_mmod_amt(const int i, bool curt) {
	if (i < 128)
		return (i > 63 ? "+" : "") + String{ i - 63 };
	return curt ? "ERR" : "range error";
}

const String Convert_P::int_to_mmod_dest(const int i, bool curt) {
    switch (i)
    {
    case 0: return curt ? "none" : "NONE";
    case 1: return curt ? "envelope 1" : "ENV 1";
    case 2: return curt ? "envelope 2" : "ENV 2";
    case 3: return curt ? "envelope 3" : "ENV 3";
    case 4: return "LFO 1";
    case 5: return "LFO 2";
    case 6: return curt ? "vibrato LFO" : "VIBRATO";
    case 7: return curt ? "ramp generator 1" : "RAMP 1";
    case 8: return curt ? "ramp generator 2" : "RAMP 2";
    case 9: return curt ? "keyboard scaling" : "KEYBD";
    case 10: return curt ? "portamento speed" : "PORTA";
    case 11: return curt ? "tracking generator" : "TRACK";
    case 12: return curt ? "keyboard note gate" : "GATE";
    case 13: return curt ? "keyboard note velocity" : "VELO";
    case 14: return curt ? "keyboard release velocity" : "R VELO";
    case 15: return curt ? "keyboard pressure (aftertouch)" : "PRESS";
    case 16: return curt ? "pedal 1" : "PEDAL 1";
    case 17: return curt ? "pedal 2" : "PEDAL 2";
    case 18: return curt ? "lever 1" : "LEVER 1";
    case 19: return curt ? "lever 2" : "LEVER 2";
    case 20: return curt ? "lever 3 (lever 2 reverse)" : "LEVER 3";
    default: return curt ? "range error" : "err";
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
