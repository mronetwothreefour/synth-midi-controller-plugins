#include "params_IntToContextualStringConverters.h"




String IntToPitchName::convert(const uint8& i) noexcept {
	auto pitchNum{ i % 12 };
	auto octaveNum{ i / 12 };
	String pitchName;
	switch (pitchNum) {
	case 0:
		pitchName = "C " + (String)octaveNum;
		break;
	case 1:
		pitchName = "C# " + (String)octaveNum;
		break;
	case 2:
		pitchName = "D " + (String)octaveNum;
		break;
	case 3:
		pitchName = "D# " + (String)octaveNum;
		break;
	case 4:
		pitchName = "E " + (String)octaveNum;
		break;
	case 5:
		pitchName = "F " + (String)octaveNum;
		break;
	case 6:
		pitchName = "F# " + (String)octaveNum;
		break;
	case 7:
		pitchName = "G " + (String)octaveNum;
		break;
	case 8:
		pitchName = "G# " + (String)octaveNum;
		break;
	case 9:
		pitchName = "A " + (String)octaveNum;
		break;
	case 10:
		pitchName = "A# " + (String)octaveNum;
		break;
	case 11:
		pitchName = "B " + (String)octaveNum;
		break;
	default:
		pitchName = "invalid";
		break;
	}
	return pitchName;
}

String IntToPitchName::convertToSeqStepPitchName(const uint8& i) noexcept {
	auto pitchNum{ i % 24 };
	auto octaveNumString{ String(i / 24) };
	switch (pitchNum)
	{
	case 0 : return "C"  + octaveNumString;
	case 1 : return "C"  + octaveNumString + "+";
	case 2 : return "C#" + octaveNumString;
	case 3 : return "C#" + octaveNumString + "+";
	case 4 : return "D"  + octaveNumString;
	case 5 : return "D"  + octaveNumString + "+";
	case 6 : return "D#" + octaveNumString;
	case 7 : return "D#" + octaveNumString + "+";
	case 8 : return "E"  + octaveNumString;
	case 9 : return "E"  + octaveNumString + "+";
	case 10: return "F"  + octaveNumString;
	case 11: return "F"  + octaveNumString + "+";
	case 12: return "F#" + octaveNumString;
	case 13: return "F#" + octaveNumString + "+";
	case 14: return "G"  + octaveNumString;
	case 15: return "G"  + octaveNumString + "+";
	case 16: return "G#" + octaveNumString;
	case 17: return "G#" + octaveNumString + "+";
	case 18: return "A"  + octaveNumString;
	case 19: return "A"  + octaveNumString + "+";
	case 20: return "A#" + octaveNumString;
	case 21: return "A#" + octaveNumString + "+";
	case 22: return "B"  + octaveNumString;
	case 23: return "B"  + octaveNumString + "+";
	default: return "err";
	}
}




String IntToContextualStringConverter::convert(const uint8& i) noexcept {
	return conversionAlgorithm(i);
}

String IntToContextualStringConverter::verboseConvert(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}




String IntToNullString::conversionAlgorithm(const uint8& /*i*/) noexcept {
	return "null";
}

String IntToNullString::verboseConversionAlgorithm(const uint8& /*i*/) noexcept {
	return "null";
}

IntToNullString* IntToNullString::get() noexcept {
	static IntToNullString converter;
	return &converter;
}




String IntToPlainValueString::conversionAlgorithm(const uint8& i) noexcept {
	return (String)i;
}

String IntToPlainValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	return (String)i;
}

IntToPlainValueString* IntToPlainValueString::get() noexcept {
	static IntToPlainValueString converter;
	return &converter;
}




String IntToOscPitchString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 121);
	String pitchName{ IntToPitchName::convert(i) };
	return pitchName;
}

String IntToOscPitchString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 121);
	String pitchName{ IntToPitchName::convert(i) };
	pitchName += " (MIDI Note " + String(i) + ")";
	return pitchName;
}

IntToOscPitchString* IntToOscPitchString::get() noexcept {
	static IntToOscPitchString converter;
	return &converter;
}




String IntToFineTuneString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 101);
	if (i < 51) return (String)(i - 50);
	if (i > 50 && i < 101) return "+" + (String)(i - 50);
	else return "err";
}

String IntToFineTuneString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 101);
	if (i < 49) return (String)(i - 50) + " cents";
	if (i == 49) return "-1 cent";
	if (i == 50) return "No Detune";
	if (i == 51) return "+1 cent";
	if (i > 51 && i < 101) return "+" + (String)(i - 50) + " cents";
	else return "range error";
}

IntToFineTuneString* IntToFineTuneString::get() noexcept {
	static IntToFineTuneString converter;
	return &converter;
}




String IntToOscWaveShapeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToOscWaveShapeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 104);
	if (i == 0) return "Oscillator Off";
	if (i == 1) return "Sawtooth";
	if (i == 2) return "Triangle";
	if (i == 3) return "Sawtooth/Triangle Mix";
	if (i > 3 && i < 104) return "Pulse (Width: " + String(i - 4) + ")";
	else return "range error";
}

IntToOscWaveShapeString* IntToOscWaveShapeString::get() noexcept {
	static IntToOscWaveShapeString converter;
	return &converter;
}




String IntToOffOnString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToOffOnString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	return i == 0 ? "Off" : "On";
}

IntToOffOnString* IntToOffOnString::get() noexcept {
	static IntToOffOnString converter;
	return &converter;
}




String IntToGlideModeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToGlideModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Fixed Rate";
	if (i == 1) return "Fixed Rate Auto";
	if (i == 2) return "Fixed Time";
	if (i == 3) return "Fixed Time Auto";
	else return "range error";
}

IntToGlideModeString* IntToGlideModeString::get() noexcept {
	static IntToGlideModeString converter;
	return &converter;
}




String IntToBendRangeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 13);
	if (i == 0) return "0";
	if (i > 0 && i < 13) return "+/-" + (String)i;
	else return "range error";
}

String IntToBendRangeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 13);
	if (i == 0) return "No Bend";
	if (i == 1) return "+/-1 semitone";
	if (i > 1 && i < 13) return "+/-" + (String)i + " semitones";
	else return "range error";
}

IntToBendRangeString* IntToBendRangeString::get() noexcept {
	static IntToBendRangeString converter;
	return &converter;
}




String IntToNotePriorityString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 6);
	if (i == 0) return "Low Note";
	if (i == 1) return "Low Note (Re-trigger)";
	if (i == 2) return "High Note";
	if (i == 3) return "High Note (Re-trigger)";
	if (i == 4) return "Last Note";
	if (i == 5) return "Last Note (Re-trigger)";
	else return "range error";
}

String IntToNotePriorityString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 6);
	if (i == 0) return "Low Note Has Priority";
	if (i == 1) return "Low Note Has Priority (Re-trigger)";
	if (i == 2) return "High Note Has Priority";
	if (i == 3) return "High Note Has Priority (Re-trigger)";
	if (i == 4) return "Last Note Hit Has Priority";
	if (i == 5) return "Last Note Hit Has Priority (Re-trigger)";
	else return "range error";
}

IntToNotePriorityString* IntToNotePriorityString::get() noexcept {
	static IntToNotePriorityString converter;
	return &converter;
}




String IntToLPFfreqString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 165);
	String pitchString{ IntToPitchName::convert(i) };
	return pitchString;
}

String IntToLPFfreqString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 165);
	String pitchString{ IntToPitchName::convert(i) };
	return (String)i + " (Pitch Freq. " + pitchString + ")";
}

IntToLPFfreqString* IntToLPFfreqString::get() noexcept {
	static IntToLPFfreqString converter;
	return &converter;
}




String IntToLPFtypeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToLPFtypeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	return i == 0 ? "2-Pole" : "4-Pole";
}

IntToLPFtypeString* IntToLPFtypeString::get() noexcept {
	static IntToLPFtypeString converter;
	return &converter;
}




String IntToPlusMinus127String::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToPlusMinus127String::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 255);
	return (i > 127 ? "+" : "") + (String)(i - 127);
}

IntToPlusMinus127String* IntToPlusMinus127String::get() noexcept {
	static IntToPlusMinus127String converter;
	return &converter;
}




String IntToLFOfreqString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 167);
	if (i < 90) return (String)(i);
	if (i > 89 && i < 151) {
		return IntToPitchName::convert(i - 90);
	}
	else {
		switch (i)
		{
		case 151: return "1:32";
		case 152: return "1:16";
		case 153: return "1:8";
		case 154: return "1:6";
		case 155: return "1:4";
		case 156: return "1:3";
		case 157: return "1:2";
		case 158: return "1:1.5";
		case 159: return "1:1";
		case 160: return "3:2";
		case 161: return "2:1";
		case 162: return "3:1";
		case 163: return "4:1";
		case 164: return "6:1";
		case 165: return "8:1";
		case 166: return "16:1";
		default: return "err";
		}
	}
}

String IntToLFOfreqString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 167);
	if (i < 90) return "Un-synced " + (String)(i);
	if (i > 89 && i < 151) {
		String pitchString{ IntToPitchName::convert(i - 90) };
		return (String)i + " (Pitch Freq. " + pitchString + ")";
	}
	else {
		switch (i)
		{
		case 151: return "Synced " + String(i) + ": 1 cycle lasts 32 steps";
		case 152: return "Synced " + String(i) + ": 1 cycle lasts 16 steps";
		case 153: return "Synced " + String(i) + ": 1 cycle lasts 8 steps";
		case 154: return "Synced " + String(i) + ": 1 cycle lasts 6 steps";
		case 155: return "Synced " + String(i) + ": 1 cycle lasts 4 steps";
		case 156: return "Synced " + String(i) + ": 1 cycle lasts 3 steps";
		case 157: return "Synced " + String(i) + ": 1 cycle lasts 2 steps";
		case 158: return "Synced " + String(i) + ": 1 cycle lasts 1-1/2 steps";
		case 159: return "Synced " + String(i) + ": 1 cycle lasts 1 step";
		case 160: return "Synced " + String(i) + ": 1 cycle lasts 2/3 step";
		case 161: return "Synced " + String(i) + ": 1 cycle lasts 1/2 step";
		case 162: return "Synced " + String(i) + ": 1 cycle lasts 1/3 step";
		case 163: return "Synced " + String(i) + ": 1 cycle lasts 1/4 step";
		case 164: return "Synced " + String(i) + ": 1 cycle lasts 1/6 step";
		case 165: return "Synced " + String(i) + ": 1 cycle lasts 1/8 step";
		case 166: return "Synced " + String(i) + ": 1 cycle lasts 1/16 step";
		default: return "range error";
		}
	}
}

IntToLFOfreqString* IntToLFOfreqString::get() noexcept {
	static IntToLFOfreqString converter;
	return &converter;
}




String IntToLFOshapeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToLFOshapeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 5);
	if (i == 0) return "Triangle";
	if (i == 1) return "Reverse Sawtooth";
	if (i == 2) return "Sawtooth";
	if (i == 3) return "Square Wave";
	if (i == 4) return "Random";
	else return "range error";
}

IntToLFOshapeString* IntToLFOshapeString::get() noexcept {
	static IntToLFOshapeString converter;
	return &converter;
}




String IntToModDestinationString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToModDestinationString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 47);
	if (i == 0 ) return "Off";
	if (i == 1 ) return "Oscillator 1 Pitch";
	if (i == 2 ) return "Oscillator 2 Pitch";
	if (i == 3 ) return "Oscillator 1 & 2 Pitch";
	if (i == 4 ) return "Oscillator Mix";
	if (i == 5 ) return "Noise Level";
	if (i == 6 ) return "Oscillator 1 Pulse Width";
	if (i == 7 ) return "Oscillator 2 Pulse Width";
	if (i == 8 ) return "Oscillator 1 & 2 PW";
	if (i == 9 ) return "LPF Cutoff Frequency";
	if (i == 10) return "LPF Resonance";
	if (i == 11) return "LPF FM Amount";
	if (i == 12) return "VCA Level";
	if (i == 13) return "Output Panning";
	if (i == 14) return "LFO 1 Frequency";
	if (i == 15) return "LFO 2 Frequency";
	if (i == 16) return "LFO 3 Frequency";
	if (i == 17) return "LFO 4 Frequency";
	if (i == 18) return "All LFO Frequencies";
	if (i == 19) return "LFO 1 Amount";
	if (i == 20) return "LFO 2 Amount";
	if (i == 21) return "LFO 3 Amount";
	if (i == 22) return "LFO 4 Amount";
	if (i == 23) return "All LFO Amounts";
	if (i == 24) return "LPF Envelope Amount";
	if (i == 25) return "VCA Envelope Amount";
	if (i == 26) return "Envelope 3 Amount";
	if (i == 27) return "All Envelope Amounts";
	if (i == 28) return "LPF Envelope Attack";
	if (i == 29) return "VCA Envelope Attack";
	if (i == 30) return "Envelope 3 Attack";
	if (i == 31) return "All Envelope Attacks";
	if (i == 32) return "LPF Envelope Decay";
	if (i == 33) return "VCA Envelope Decay";
	if (i == 34) return "Envelope 3 Decay";
	if (i == 35) return "All Envelope Decays";
	if (i == 36) return "LPF Envelope Release";
	if (i == 37) return "VCA Envelope Release";
	if (i == 38) return "Envelope 3 Release";
	if (i == 39) return "All Envelope Releases";
	if (i == 40) return "Modulator 1 Amount";
	if (i == 41) return "Modulator 2 Amount";
	if (i == 42) return "Modulator 3 Amount";
	if (i == 43) return "Modulator 4 Amount";
	if (i == 44) return "External Audio In Level";
	if (i == 45) return "Sub-Osc 1 Level";
	if (i == 46) return "Sub-Osc 2 Level";
	else return "range error";
}

IntToModDestinationString* IntToModDestinationString::get() noexcept {
	static IntToModDestinationString converter;
	return &converter;
}




String IntToModSourceString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToModSourceString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 23);
	if (i == 0 ) return "Off";
	if (i == 1 ) return "Sequencer Track 1";
	if (i == 2 ) return "Sequencer Track 2";
	if (i == 3 ) return "Sequencer Track 3";
	if (i == 4 ) return "Sequencer Track 4";
	if (i == 5 ) return "LFO 1";
	if (i == 6 ) return "LFO 2";
	if (i == 7 ) return "LFO 3";
	if (i == 8 ) return "LFO 4";
	if (i == 9 ) return "LPF Envelope";
	if (i == 10) return "VCA Envelope";
	if (i == 11) return "Envelope 3";
	if (i == 12) return "Pitch Bend";
	if (i == 13) return "Mod Wheel";
	if (i == 14) return "Pressure (Aftertouch)";
	if (i == 15) return "MIDI Breath";
	if (i == 16) return "MIDI Foot Pedal";
	if (i == 17) return "MIDI Expression";
	if (i == 18) return "Velocity";
	if (i == 19) return "Note Number";
	if (i == 20) return "Noise";
	if (i == 21) return "Audio In Env. Follower";
	if (i == 22) return "Audio In Peak Hold";
	else return "range error";
}

IntToModSourceString* IntToModSourceString::get() noexcept {
	static IntToModSourceString converter;
	return &converter;
}




String IntToPushItModeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToPushItModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "Normal";
	if (i == 1) return "Toggle";
	if (i == 2) return "Audio In";
	else return "range error";
}

IntToPushItModeString* IntToPushItModeString::get() noexcept {
	static IntToPushItModeString converter;
	return &converter;
}




String IntToClockTempoString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 221);
	return (String)(i + 30);
}

String IntToClockTempoString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 221);
	return (String)(i + 30) + " BPM";
}

IntToClockTempoString* IntToClockTempoString::get() noexcept {
	static IntToClockTempoString converter;
	return &converter;
}




String IntToClockDivString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 13);
	if (i == 0 ) return "Half Note";
	if (i == 1 ) return "Quarter Note";
	if (i == 2 ) return "8th Note";
	if (i == 3 ) return "8th Note, 1/2 Swing";
	if (i == 4 ) return "8th Note, Full Swing";
	if (i == 5 ) return "8th Note Triplets";
	if (i == 6 ) return "16th Note";
	if (i == 7 ) return "16th Note, 1/2 Swing";
	if (i == 8 ) return "16th Note, Full Swing";
	if (i == 9 ) return "16th Note Triplets";
	if (i == 10) return "32nd Note";
	if (i == 11) return "32nd Note Triplets";
	if (i == 12) return "64th Note Triplets";
	else return "range error";
}

String IntToClockDivString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 13);
	if (i == 0 ) return "Half Note (BPM / 2)";
	if (i == 1 ) return "Quarter Note (BPM x 1)";
	if (i == 2 ) return "8th Note (BPM x 2)";
	if (i == 3 ) return "8th Note, 1/2 Swing (BPM x 2)";
	if (i == 4 ) return "8th Note, Full Swing (BPM x 2)";
	if (i == 5 ) return "8th Note Triplets (BPM x 3)";
	if (i == 6 ) return "16th Note (BPM x 4)";
	if (i == 7 ) return "16th Note, 1/2 Swing (BPM x 4)";
	if (i == 8 ) return "16th Note, Full Swing (BPM x 4)";
	if (i == 9 ) return "16th Note Triplets (BPM x 6)";
	if (i == 10) return "32nd Note (BPM x 8)";
	if (i == 11) return "32nd Note Triplets (BPM x 12)";
	if (i == 12) return "64th Note Triplets (BPM x 24)";
	else return "range error";
}

IntToClockDivString* IntToClockDivString::get() noexcept {
	static IntToClockDivString converter;
	return &converter;
}




String IntToArpegModeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToArpegModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Up";
	if (i == 1) return "Down";
	if (i == 2) return "Up & Down";
	if (i == 3) return "Assign";
	else return "range error";
}

IntToArpegModeString* IntToArpegModeString::get() noexcept {
	static IntToArpegModeString converter;
	return &converter;
}




String IntToSeqTrigModeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToSeqTrigModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 6);
	if (i == 0) return "Normal";
	if (i == 1) return "Normal, No Reset";
	if (i == 2) return "No Gate";
	if (i == 3) return "No Gate, No Reset";
	if (i == 4) return "Key Step";
	if (i == 5) return "Audio Input";
	else return "range error";
}

IntToSeqTrigModeString* IntToSeqTrigModeString::get() noexcept {
	static IntToSeqTrigModeString converter;
	return &converter;
}




String IntToParamNameString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 169);
	switch (i)
	{
	case 0  : return "Oscillator 1 Pitch";
	case 1  : return "Oscillator 1 Fine Tune";
	case 2  : return "Oscillator 1 Wave Shape";
	case 3  : return "Oscillator 1 Glide Rate";
	case 4  : return "Oscillator 1 Key Track";
	case 5  : return "Sub-Oscillator 1 Level";
	case 6  : return "Oscillator 2 Pitch";
	case 7  : return "Oscillator 2 Fine Tune";
	case 8  : return "Oscillator 2 Wave Shape";
	case 9  : return "Oscillator 2 Glide Rate";
	case 10 : return "Oscillator 2 Key Track";
	case 11 : return "Sub-Oscillator 2 Level";
	case 12 : return "Hard Sync Oscillators";
	case 13 : return "Glide Mode";
	case 14 : return "Oscillator Slop";
	case 15 : return "Pitch Bend Range";
	case 16 : return "Keyed Note Priority";
	case 17 : return "Oscillators 1 & 2 Mix";
	case 18 : return "Noise Level";
	case 19 : return "External Audio In Level";
	case 20 : return "LPF Cutoff Frequency";
	case 21 : return "LPF Resonance";
	case 22 : return "LPF Keyboard Amount";
	case 23 : return "LPF Freq. Mod. Amount";
	case 24 : return "LPF 2- or 4-Pole Select";
	case 25 : return "LPF Envelope Amount";
	case 26 : return "LPF Env Vel Amt";
	case 27 : return "LPF Envelope Delay";
	case 28 : return "LPF Envelope Attack";
	case 29 : return "LPF Envelope Decay";
	case 30 : return "LPF Envelope Sustain";
	case 31 : return "LPF Envelope Release";
	case 32 : return "VCA Initial Level";
	case 33 : return "VCA Envelope Amount";
	case 34 : return "VCA Env Vel Amnt";
	case 35 : return "VCA Envelope Delay";
	case 36 : return "VCA Envelope Attack";
	case 37 : return "VCA Envelope Decay";
	case 38 : return "VCA Envelope Sustain";
	case 39 : return "VCA Envelope Release";
	case 40 : return "Voice Volume";
	case 41 : return "LFO 1 Frequency";
	case 42 : return "LFO 1 Wave Shape";
	case 43 : return "LFO 1 Amount";
	case 44 : return "LFO 1 Mod Destination";
	case 45 : return "LFO 1 Key Sync";
	case 46 : return "LFO 2 Frequency";
	case 47 : return "LFO 2 Wave Shape";
	case 48 : return "LFO 2 Amount";
	case 49 : return "LFO 2 Mod Destination";
	case 50 : return "LFO 2 Key Sync";
	case 51 : return "LFO 3 Frequency";
	case 52 : return "LFO 3 Wave Shape";
	case 53 : return "LFO 3 Amount";
	case 54 : return "LFO 3 Mod Destination";
	case 55 : return "LFO 3 Key Sync";
	case 56 : return "LFO 4 Frequency";
	case 57 : return "LFO 4 Wave Shape";
	case 58 : return "LFO 4 Amount";
	case 59 : return "LFO 4 Mod Destination";
	case 60 : return "LFO 4 Key Sync";
	case 61 : return "Env 3 Mod Destination";
	case 62 : return "Envelope 3 Amount";
	case 63 : return "Env 3 Velocity Amount";
	case 64 : return "Envelope 3 Delay";
	case 65 : return "Envelope 3 Attack";
	case 66 : return "Envelope 3 Decay";
	case 67 : return "Envelope 3 Sustain";
	case 68 : return "Envelope 3 Release";
	case 69 : return "Envelope 3 Repeat";
	case 70 : return "Modulator 1 Source";
	case 71 : return "Modulator 1 Amount";
	case 72 : return "Modulator 1 Destination";
	case 73 : return "Modulator 2 Source";
	case 74 : return "Modulator 2 Amount";
	case 75 : return "Modulator 2 Destination";
	case 76 : return "Modulator 3 Source";
	case 77 : return "Modulator 3 Amount";
	case 78 : return "Modulator 3 Destination";
	case 79 : return "Modulator 4 Source";
	case 80 : return "Modulator 4 Amount";
	case 81 : return "Modulator 4 Destination";
	case 82 : return "Modulation Wheel Amt";
	case 83 : return "Modulation Wheel Dest";
	case 84 : return "Pressure Amount";
	case 85 : return "Pressure Destination";
	case 86 : return "Breath Amount";
	case 87 : return "Breath Destination";
	case 88 : return "Velocity Amount";
	case 89 : return "Velocity Destination";
	case 90 : return "Foot Pedal Amount";
	case 91 : return "Foot Pedal Destination";
	case 92 : return "Push It! Switch Pitch";
	case 93 : return "Push It! Switch Velocity";
	case 94 : return "Push It! Switch Mode";
	case 95 : return "Clock Tempo (BPM)";
	case 96 : return "Clock Divide";
	case 97 : return "Arpeggiator Mode";
	case 98 : return "Arpeggiator On/Off";
	case 99 : return "Sequencer Trigger Mode";
	case 100: return "Sequencer On/Off";
	case 101: return "Sequencer Track 1 Dest";
	case 102: return "Sequencer Track 2 Dest";
	case 103: return "Sequencer Track 3 Dest";
	case 104: return "Sequencer Track 4 Dest";
	case 105: return "Seq Track 1 Step 1";
	case 106: return "Seq Track 1 Step 2";
	case 107: return "Seq Track 1 Step 3";
	case 108: return "Seq Track 1 Step 4";
	case 109: return "Seq Track 1 Step 5";
	case 110: return "Seq Track 1 Step 6";
	case 111: return "Seq Track 1 Step 7";
	case 112: return "Seq Track 1 Step 8";
	case 113: return "Seq Track 1 Step 9";
	case 114: return "Seq Track 1 Step 10";
	case 115: return "Seq Track 1 Step 11";
	case 116: return "Seq Track 1 Step 12";
	case 117: return "Seq Track 1 Step 13";
	case 118: return "Seq Track 1 Step 14";
	case 119: return "Seq Track 1 Step 15";
	case 120: return "Seq Track 1 Step 16";
	case 121: return "Seq Track 2 Step 1";
	case 122: return "Seq Track 2 Step 2";
	case 123: return "Seq Track 2 Step 3";
	case 124: return "Seq Track 2 Step 4";
	case 125: return "Seq Track 2 Step 5";
	case 126: return "Seq Track 2 Step 6";
	case 127: return "Seq Track 2 Step 7";
	case 128: return "Seq Track 2 Step 8";
	case 129: return "Seq Track 2 Step 9";
	case 130: return "Seq Track 2 Step 10";
	case 131: return "Seq Track 2 Step 11";
	case 132: return "Seq Track 2 Step 12";
	case 133: return "Seq Track 2 Step 13";
	case 134: return "Seq Track 2 Step 14";
	case 135: return "Seq Track 2 Step 15";
	case 136: return "Seq Track 2 Step 16";
	case 137: return "Seq Track 3 Step 1";
	case 138: return "Seq Track 3 Step 2";
	case 139: return "Seq Track 3 Step 3";
	case 140: return "Seq Track 3 Step 4";
	case 141: return "Seq Track 3 Step 5";
	case 142: return "Seq Track 3 Step 6";
	case 143: return "Seq Track 3 Step 7";
	case 144: return "Seq Track 3 Step 8";
	case 145: return "Seq Track 3 Step 9";
	case 146: return "Seq Track 3 Step 10";
	case 147: return "Seq Track 3 Step 11";
	case 148: return "Seq Track 3 Step 12";
	case 149: return "Seq Track 3 Step 13";
	case 150: return "Seq Track 3 Step 14";
	case 151: return "Seq Track 3 Step 15";
	case 152: return "Seq Track 3 Step 16";
	case 153: return "Seq Track 4 Step 1";
	case 154: return "Seq Track 4 Step 2";
	case 155: return "Seq Track 4 Step 3";
	case 156: return "Seq Track 4 Step 4";
	case 157: return "Seq Track 4 Step 5";
	case 158: return "Seq Track 4 Step 6";
	case 159: return "Seq Track 4 Step 7";
	case 160: return "Seq Track 4 Step 8";
	case 161: return "Seq Track 4 Step 9";
	case 162: return "Seq Track 4 Step 10";
	case 163: return "Seq Track 4 Step 11";
	case 164: return "Seq Track 4 Step 12";
	case 165: return "Seq Track 4 Step 13";
	case 166: return "Seq Track 4 Step 14";
	case 167: return "Seq Track 4 Step 15";
	case 168: return "Seq Track 4 Step 16";
	default: return "range error";
	}
}

String IntToParamNameString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 169);
	switch (i)
	{
	case 0  : return "Oscillator 1 Pitch";
	case 1  : return "Oscillator 1 Fine Tune";
	case 2  : return "Oscillator 1 Wave Shape";
	case 3  : return "Oscillator 1 Glide Rate";
	case 4  : return "Oscillator 1 Key Track";
	case 5  : return "Sub-Oscillator 1 Level";
	case 6  : return "Oscillator 2 Pitch";
	case 7  : return "Oscillator 2 Fine Tune";
	case 8  : return "Oscillator 2 Wave Shape";
	case 9  : return "Oscillator 2 Glide Rate";
	case 10 : return "Oscillator 2 Key Track";
	case 11 : return "Sub-Oscillator 2 Level";
	case 12 : return "Hard Sync Oscillators";
	case 13 : return "Glide Mode";
	case 14 : return "Oscillator Slop";
	case 15 : return "Pitch Bend Range";
	case 16 : return "Keyed Note Priority";
	case 17 : return "Oscillators 1 & 2 Mix";
	case 18 : return "Noise Level";
	case 19 : return "External Audio Input Level";
	case 20 : return "LPF Cutoff Frequency";
	case 21 : return "LPF Resonance";
	case 22 : return "LPF Keyboard Amount";
	case 23 : return "LPF Freq. Mod. Amount";
	case 24 : return "LPF 2- or 4-Pole Select";
	case 25 : return "LPF Envelope Amount";
	case 26 : return "LPF Envelope Velocity Amount";
	case 27 : return "LPF Envelope Delay";
	case 28 : return "LPF Envelope Attack";
	case 29 : return "LPF Envelope Decay";
	case 30 : return "LPF Envelope Sustain";
	case 31 : return "LPF Envelope Release";
	case 32 : return "VCA Initial Level";
	case 33 : return "VCA Envelope Amount";
	case 34 : return "VCA Envelope Velocity Amount";
	case 35 : return "VCA Envelope Delay";
	case 36 : return "VCA Envelope Attack";
	case 37 : return "VCA Envelope Decay";
	case 38 : return "VCA Envelope Sustain";
	case 39 : return "VCA Envelope Release";
	case 40 : return "Voice Volume";
	case 41 : return "LFO 1 Frequency";
	case 42 : return "LFO 1 Wave Shape";
	case 43 : return "LFO 1 Amount";
	case 44 : return "LFO 1 Modulation Destination";
	case 45 : return "LFO 1 Key Sync";
	case 46 : return "LFO 2 Frequency";
	case 47 : return "LFO 2 Wave Shape";
	case 48 : return "LFO 2 Amount";
	case 49 : return "LFO 2 Modulation Destination";
	case 50 : return "LFO 2 Key Sync";
	case 51 : return "LFO 3 Frequency";
	case 52 : return "LFO 3 Wave Shape";
	case 53 : return "LFO 3 Amount";
	case 54 : return "LFO 3 Modulation Destination";
	case 55 : return "LFO 3 Key Sync";
	case 56 : return "LFO 4 Frequency";
	case 57 : return "LFO 4 Wave Shape";
	case 58 : return "LFO 4 Amount";
	case 59 : return "LFO 4 Modulation Destination";
	case 60 : return "LFO 4 Key Sync";
	case 61 : return "Envelope 3 Mod Destination";
	case 62 : return "Envelope 3 Amount";
	case 63 : return "Envelope 3 Velocity Amount";
	case 64 : return "Envelope 3 Delay";
	case 65 : return "Envelope 3 Attack";
	case 66 : return "Envelope 3 Decay";
	case 67 : return "Envelope 3 Sustain";
	case 68 : return "Envelope 3 Release";
	case 69 : return "Envelope 3 Repeat";
	case 70 : return "Modulator 1 Source";
	case 71 : return "Modulator 1 Amount";
	case 72 : return "Modulator 1 Destination";
	case 73 : return "Modulator 2 Source";
	case 74 : return "Modulator 2 Amount";
	case 75 : return "Modulator 2 Destination";
	case 76 : return "Modulator 3 Source";
	case 77 : return "Modulator 3 Amount";
	case 78 : return "Modulator 3 Destination";
	case 79 : return "Modulator 4 Source";
	case 80 : return "Modulator 4 Amount";
	case 81 : return "Modulator 4 Destination";
	case 82 : return "Modulation Wheel Amount";
	case 83 : return "Modulation Wheel Destination";
	case 84 : return "Pressure (Aftertouch) Amount";
	case 85 : return "Pressure (Aftertouch) Destination";
	case 86 : return "Breath Controller Amount";
	case 87 : return "Breath Controller Destination";
	case 88 : return "Note Velocity Amount";
	case 89 : return "Note Velocity Destination";
	case 90 : return "Foot Pedal Amount";
	case 91 : return "Foot Pedal Destination";
	case 92 : return "Push It! Switch Pitch";
	case 93 : return "Push It! Switch Velocity";
	case 94 : return "Push It! Switch Mode";
	case 95 : return "Clock Tempo (BPM)";
	case 96 : return "Clock Divide";
	case 97 : return "Arpeggiator Mode";
	case 98 : return "Arpeggiator On/Off";
	case 99 : return "Sequencer Trigger Mode";
	case 100: return "Sequencer On/Off";
	case 101: return "Sequencer Track 1 Destination";
	case 102: return "Sequencer Track 2 Destination";
	case 103: return "Sequencer Track 3 Destination";
	case 104: return "Sequencer Track 4 Destination";
	case 105: return "Sequencer Track 1 Step 1";
	case 106: return "Sequencer Track 1 Step 2";
	case 107: return "Sequencer Track 1 Step 3";
	case 108: return "Sequencer Track 1 Step 4";
	case 109: return "Sequencer Track 1 Step 5";
	case 110: return "Sequencer Track 1 Step 6";
	case 111: return "Sequencer Track 1 Step 7";
	case 112: return "Sequencer Track 1 Step 8";
	case 113: return "Sequencer Track 1 Step 9";
	case 114: return "Sequencer Track 1 Step 10";
	case 115: return "Sequencer Track 1 Step 11";
	case 116: return "Sequencer Track 1 Step 12";
	case 117: return "Sequencer Track 1 Step 13";
	case 118: return "Sequencer Track 1 Step 14";
	case 119: return "Sequencer Track 1 Step 15";
	case 120: return "Sequencer Track 1 Step 16";
	case 121: return "Sequencer Track 2 Step 1";
	case 122: return "Sequencer Track 2 Step 2";
	case 123: return "Sequencer Track 2 Step 3";
	case 124: return "Sequencer Track 2 Step 4";
	case 125: return "Sequencer Track 2 Step 5";
	case 126: return "Sequencer Track 2 Step 6";
	case 127: return "Sequencer Track 2 Step 7";
	case 128: return "Sequencer Track 2 Step 8";
	case 129: return "Sequencer Track 2 Step 9";
	case 130: return "Sequencer Track 2 Step 10";
	case 131: return "Sequencer Track 2 Step 11";
	case 132: return "Sequencer Track 2 Step 12";
	case 133: return "Sequencer Track 2 Step 13";
	case 134: return "Sequencer Track 2 Step 14";
	case 135: return "Sequencer Track 2 Step 15";
	case 136: return "Sequencer Track 2 Step 16";
	case 137: return "Sequencer Track 3 Step 1";
	case 138: return "Sequencer Track 3 Step 2";
	case 139: return "Sequencer Track 3 Step 3";
	case 140: return "Sequencer Track 3 Step 4";
	case 141: return "Sequencer Track 3 Step 5";
	case 142: return "Sequencer Track 3 Step 6";
	case 143: return "Sequencer Track 3 Step 7";
	case 144: return "Sequencer Track 3 Step 8";
	case 145: return "Sequencer Track 3 Step 9";
	case 146: return "Sequencer Track 3 Step 10";
	case 147: return "Sequencer Track 3 Step 11";
	case 148: return "Sequencer Track 3 Step 12";
	case 149: return "Sequencer Track 3 Step 13";
	case 150: return "Sequencer Track 3 Step 14";
	case 151: return "Sequencer Track 3 Step 15";
	case 152: return "Sequencer Track 3 Step 16";
	case 153: return "Sequencer Track 4 Step 1";
	case 154: return "Sequencer Track 4 Step 2";
	case 155: return "Sequencer Track 4 Step 3";
	case 156: return "Sequencer Track 4 Step 4";
	case 157: return "Sequencer Track 4 Step 5";
	case 158: return "Sequencer Track 4 Step 6";
	case 159: return "Sequencer Track 4 Step 7";
	case 160: return "Sequencer Track 4 Step 8";
	case 161: return "Sequencer Track 4 Step 9";
	case 162: return "Sequencer Track 4 Step 10";
	case 163: return "Sequencer Track 4 Step 11";
	case 164: return "Sequencer Track 4 Step 12";
	case 165: return "Sequencer Track 4 Step 13";
	case 166: return "Sequencer Track 4 Step 14";
	case 167: return "Sequencer Track 4 Step 15";
	case 168: return "Sequencer Track 4 Step 16";
	default: return "range error";
	}
}

IntToParamNameString* IntToParamNameString::get() noexcept {
	static IntToParamNameString converter;
	return &converter;
}




String IntToSeqStepValueString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToSeqStepValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 128);
	if (i < 126) return (String)i + " (" + IntToPitchName::convertToSeqStepPitchName(i) + ")";
	if (i == 126) return "Reset Sequence";
	if (i == 127) return "Rest";
	else return "range error";
}

IntToSeqStepValueString* IntToSeqStepValueString::get() noexcept {
	static IntToSeqStepValueString converter;
	return &converter;
}




String IntToPgmNameCharString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToPgmNameCharString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 128);
	if (i > 31)
	{
		String character;
		switch (i)
		{
		case 32:
			character = "Space";
			break;
		case 92:
			character = "Yen Symbol";
			break;
		case 126:
			character = "Right Arrow";
			break;
		case 127:
			character = "Left Arrow";
			break;
		default:
			character = std::string(1, (char)i);
			break;
		}
		character += " (" + (String)i + ")";
		return character;
	}
	else return "Control Character (" + (String)i + ")";
}

IntToPgmNameCharString* IntToPgmNameCharString::get() noexcept {
	static IntToPgmNameCharString converter;
	return &converter;
}
