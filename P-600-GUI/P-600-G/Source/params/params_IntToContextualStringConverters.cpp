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
	return verboseConversionAlgorithm(i);
}

String IntToPlainValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	return (String)i;
}

IntToPlainValueString* IntToPlainValueString::get() noexcept {
	static IntToPlainValueString converter;
	return &converter;
}




String IntToOscPitchString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 49);
	String pitchName{ IntToPitchName::convert(i) };
	return pitchName;
}

String IntToOscPitchString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 49);
	String pitchName{ IntToPitchName::convert(i) };
	pitchName += " (MIDI Note " + String(i) + ")";
	return pitchName;
}

IntToOscPitchString* IntToOscPitchString::get() noexcept {
	static IntToOscPitchString converter;
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




String IntToKeyTrackString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToKeyTrackString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	switch (i) {
	case 0:
		return "Off";
	case 1:
		return "1/2";
	case 2:
		return "Full";
	default:
		return "invalid";
	}
}

IntToKeyTrackString* IntToKeyTrackString::get() noexcept {
	static IntToKeyTrackString converter;
	return &converter;
}




String IntToLFOshapeString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToLFOshapeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	return i == 0 ? "Square" : "Triangle";
}

IntToLFOshapeString* IntToLFOshapeString::get() noexcept {
	static IntToLFOshapeString converter;
	return &converter;
}
