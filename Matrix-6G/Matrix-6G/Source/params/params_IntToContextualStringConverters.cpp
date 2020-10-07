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




String IntToUnsignedValueString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToUnsignedValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 128);
	return (String)i;
}

IntToUnsignedValueString* IntToUnsignedValueString::get() noexcept {
	static IntToUnsignedValueString converter;
	return &converter;
}




String IntToSigned7bitValueString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 127);
	String valueString;
	if (i < 64)
		valueString = (String)(i - 63);
	else
		valueString = "+" + (String)(i - 63);
	if ((i - 63) > -10 && (i - 63) < 10)
		valueString += " ";
	return valueString;
}

String IntToSigned7bitValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 127);
	if (i < 64)
		return (String)(i - 63);
	else
		return "+" + (String)(i - 63);
}

IntToSigned7bitValueString* IntToSigned7bitValueString::get() noexcept {
	static IntToSigned7bitValueString converter;
	return &converter;
}




String IntToOscPitchString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 64);
	String pitchName{ IntToPitchName::convert(i) };
	return pitchName;
}

String IntToOscPitchString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 64);
	String pitchName{ IntToPitchName::convert(i) };
	pitchName += " (MIDI Note " + String(i) + ")";
	return pitchName;
}

IntToOscPitchString* IntToOscPitchString::get() noexcept {
	static IntToOscPitchString converter;
	return &converter;
}




String IntToOsc1SyncString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "OFF ";
	if (i == 1) return "SOFT";
	if (i == 2) return "MED ";
	if (i == 3) return "HARD";
	else return "ERR";
}

String IntToOsc1SyncString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Off (0)";
	if (i == 1) return "Soft Sync (1)";
	if (i == 2) return "Medium Sync (2)";
	if (i == 3) return "Hard Sync (3)";
	else return "range error";
}

IntToOsc1SyncString* IntToOsc1SyncString::get() noexcept {
	static IntToOsc1SyncString converter;
	return &converter;
}
