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
	return verboseConversionAlgorithm(i);
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




String IntToSigned6bitValueString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToSigned6bitValueString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 63);
	if (i < 33)
		return (String)(i - 31);
	else
		return "+" + (String)(i - 31);
}

IntToSigned6bitValueString* IntToSigned6bitValueString::get() noexcept {
	static IntToSigned6bitValueString converter;
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
	if (i == 0) return "OFF";
	if (i == 1) return "SOFT";
	if (i == 2) return "MED";
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




String IntToOscTypeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 5);
	if (i == 0) return "OFF";
	if (i == 1) return "PULSE";
	if (i == 2) return "WAVE";
	if (i == 3) return "BOTH";
	if (i == 4) return "NOISE";
	else return "ERR";
}

String IntToOscTypeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 5);
	if (i == 0) return "Off";
	if (i == 1) return "Pulse";
	if (i == 2) return "Wave (Saw/Triangle)";
	if (i == 3) return "Both";
	if (i == 4) return "Noise";
	else return "range error";
}

IntToOscTypeString* IntToOscTypeString::get() noexcept {
	static IntToOscTypeString converter;
	return &converter;
}




String IntToLeverControlString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "OFF";
	if (i == 1) return "BEND";
	if (i == 2) return "VIB";
	if (i == 3) return "BOTH";
	else return "ERR";
}

String IntToLeverControlString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Off";
	if (i == 1) return "Pitch Bend by Lever 1";
	if (i == 2) return "Vibrato by Lever 2";
	if (i == 3) return "Control by Both Levers";
	else return "range error";
}

IntToLeverControlString* IntToLeverControlString::get() noexcept {
	static IntToLeverControlString converter;
	return &converter;
}




String IntToOsc1KeyPortaString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "KEYBD";
	if (i == 1) return "PORTA";
	else return "ERR";
}

String IntToOsc1KeyPortaString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "Normal Keyboard Behavior";
	if (i == 1) return "Portamento Is Active";
	else return "range error";
}

IntToOsc1KeyPortaString* IntToOsc1KeyPortaString::get() noexcept {
	static IntToOsc1KeyPortaString converter;
	return &converter;
}




String IntToOsc2KeyPortaString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "OFF";
	if (i == 1) return "PORTA";
	if (i == 2) return "KEYBD";
	else return "ERR";
}

String IntToOsc2KeyPortaString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "Off (Pitch Is Locked)";
	if (i == 1) return "Portamento Is Active";
	if (i == 2) return "Normal Keyboard Behavior";
	else return "range error";
}

IntToOsc2KeyPortaString* IntToOsc2KeyPortaString::get() noexcept {
	static IntToOsc2KeyPortaString converter;
	return &converter;
}




String IntToOffOnString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "OFF";
	if (i == 1) return "ON";
	else return "ERR";
}

String IntToOffOnString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "Off";
	if (i == 1) return "On";
	else return "range error";
}

IntToOffOnString* IntToOffOnString::get() noexcept {
	static IntToOffOnString converter;
	return &converter;
}
