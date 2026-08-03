#include "D_CONVERT_P.h"

String Convert_P::int_to_seq_step_pitch(const int i) {
	auto note{ i % 24 };
	auto octave{ String(i / 24) };
	switch (note)
	{
	case 0: return "C" + octave;
	case 1: return "C" + octave + "+";
	case 2: return "C#" + octave;
	case 3: return "C#" + octave + "+";
	case 4: return "D" + octave;
	case 5: return "D" + octave + "+";
	case 6: return "D#" + octave;
	case 7: return "D#" + octave + "+";
	case 8: return "E" + octave;
	case 9: return "E" + octave + "+";
	case 10: return "F" + octave;
	case 11: return "F" + octave + "+";
	case 12: return "F#" + octave;
	case 13: return "F#" + octave + "+";
	case 14: return "G" + octave;
	case 15: return "G" + octave + "+";
	case 16: return "G#" + octave;
	case 17: return "G#" + octave + "+";
	case 18: return "A" + octave;
	case 19: return "A" + octave + "+";
	case 20: return "A#" + octave;
	case 21: return "A#" + octave + "+";
	case 22: return "B" + octave;
	case 23: return "B" + octave + "+";
	default: return "";
	}
}
