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
