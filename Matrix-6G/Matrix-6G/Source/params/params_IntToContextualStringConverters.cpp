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




String IntToUnsignedValueWithLeadingZeroString::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToUnsignedValueWithLeadingZeroString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 100);
	if (i < 10)
		return "0" + (String)i;
	else
		return (String)i;
}

IntToUnsignedValueWithLeadingZeroString* IntToUnsignedValueWithLeadingZeroString::get() noexcept {
	static IntToUnsignedValueWithLeadingZeroString converter;
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




String IntToOsc1KeyTrackString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "KEYBD";
	if (i == 1) return "PORTA";
	else return "ERR";
}

String IntToOsc1KeyTrackString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 2);
	if (i == 0) return "Normal Key Tracking";
	if (i == 1) return "Key Tracking With Portamento";
	else return "range error";
}

IntToOsc1KeyTrackString* IntToOsc1KeyTrackString::get() noexcept {
	static IntToOsc1KeyTrackString converter;
	return &converter;
}




String IntToOsc2AndVCFKeyTrackString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "OFF";
	if (i == 1) return "PORTA";
	if (i == 2) return "KEYBD";
	else return "ERR";
}

String IntToOsc2AndVCFKeyTrackString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "Key Tracking Is Off";
	if (i == 1) return "Key Tracking With Portamento";
	if (i == 2) return "Normal Key Tracking";
	else return "range error";
}

IntToOsc2AndVCFKeyTrackString* IntToOsc2AndVCFKeyTrackString::get() noexcept {
	static IntToOsc2AndVCFKeyTrackString converter;
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




String IntToTrackingInputString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 21);
	if (i == 0) return "NONE";
	if (i == 1) return "ENV 1";
	if (i == 2) return "ENV 2";
	if (i == 3) return "ENV 3";
	if (i == 4) return "LFO 1";
	if (i == 5) return "LFO 2";
	if (i == 6) return "VIBRATO";
	if (i == 7) return "RAMP 1";
	if (i == 8) return "RAMP 2";
	if (i == 9) return "KEYBOARD";
	if (i == 10) return "PORTA";
	if (i == 11) return "TRACKING";
	if (i == 12) return "GATE";
	if (i == 13) return "VELOCITY";
	if (i == 14) return "REL VELO";
	if (i == 15) return "PRESSURE";
	if (i == 16) return "PEDAL 1";
	if (i == 17) return "PEDAL 2";
	if (i == 18) return "LEVER 1";
	if (i == 19) return "LEVER 2";
	if (i == 20) return "LEVER 3";
	else return "ERR";
}

String IntToTrackingInputString::verboseConversionAlgorithm(const uint8& i) noexcept {
	return IntToModSourceString::get()->verboseConversionAlgorithm(i);
}

IntToTrackingInputString* IntToTrackingInputString::get() noexcept {
	static IntToTrackingInputString converter;
	return &converter;
}




String IntToModSourceString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 21);
	if (i == 0) return "NONE";
	if (i == 1) return "ENV 1";
	if (i == 2) return "ENV 2";
	if (i == 3) return "ENV 3";
	if (i == 4) return "LFO 1";
	if (i == 5) return "LFO 2";
	if (i == 6) return "VIBRATO";
	if (i == 7) return "RAMP 1";
	if (i == 8) return "RAMP 2";
	if (i == 9) return "KEYBD";
	if (i == 10) return "PORTA";
	if (i == 11) return "TRACK";
	if (i == 12) return "GATE";
	if (i == 13) return "VELO";
	if (i == 14) return "R VELO";
	if (i == 15) return "PRESS";
	if (i == 16) return "PEDAL 1";
	if (i == 17) return "PEDAL 2";
	if (i == 18) return "LEVER 1";
	if (i == 19) return "LEVER 2";
	if (i == 20) return "LEVER 3";
	else return "ERR";
}

String IntToModSourceString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 21);
	if (i == 0) return "None";
	if (i == 1) return "Envelope 1";
	if (i == 2) return "Envelope 2";
	if (i == 3) return "Envelope 3";
	if (i == 4) return "LFO 1";
	if (i == 5) return "LFO 2";
	if (i == 6) return "Vibrato LFO";
	if (i == 7) return "Ramp Generator 1";
	if (i == 8) return "Ramp Generator 2";
	if (i == 9) return "Keyboard Scaling";
	if (i == 10) return "Portamento Speed";
	if (i == 11) return "Tracking Generator";
	if (i == 12) return "Keyboard Note Gate";
	if (i == 13) return "Keyboard Note Velocity";
	if (i == 14) return "Keyboard Release Velocity";
	if (i == 15) return "Keyboard Pressure (Aftertouch)";
	if (i == 16) return "Pedal 1";
	if (i == 17) return "Pedal 2";
	if (i == 18) return "Lever 1";
	if (i == 19) return "Lever 2";
	if (i == 20) return "Lever 3 (Lever 2 Reverse)";
	else return "range error";
}

IntToModSourceString* IntToModSourceString::get() noexcept {
	static IntToModSourceString converter;
	return &converter;
}




String IntToModDestinationString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 33);
	if (i == 0) return "NONE";
	if (i == 1) return "OSC1 FQ";
	if (i == 2) return "OSC1 PW";
	if (i == 3) return "OSC1 W";
	if (i == 4) return "OSC2 FQ";
	if (i == 5) return "OSC2 PW";
	if (i == 6) return "OSC2 W";
	if (i == 7) return "OSC MIX";
	if (i == 8) return "VCF FM";
	if (i == 9) return "VCF FQ";
	if (i == 10) return "VCF RES";
	if (i == 11) return "VCA1LVL";
	if (i == 12) return "VCA2LVL";
	if (i == 13) return "ENV1DEL";
	if (i == 14) return "ENV1ATK";
	if (i == 15) return "ENV1DEC";
	if (i == 16) return "ENV1REL";
	if (i == 17) return "ENV1AMP";
	if (i == 18) return "ENV2DEL";
	if (i == 19) return "ENV2ATK";
	if (i == 20) return "ENV2DEC";
	if (i == 21) return "ENV2REL";
	if (i == 22) return "ENV2AMP";
	if (i == 23) return "ENV3DEL";
	if (i == 24) return "ENV3ATK";
	if (i == 25) return "ENV3DEC";
	if (i == 26) return "ENV3REL";
	if (i == 27) return "ENV3AMP";
	if (i == 28) return "LFO1SPD";
	if (i == 29) return "LFO1AMP";
	if (i == 30) return "LFO2SPD";
	if (i == 31) return "LFO2AMP";
	if (i == 32) return "PORTA";
	else return "ERR";
}

String IntToModDestinationString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 33);
	if (i == 0) return "None";
	if (i == 1) return "Oscillator 1 Pitch";
	if (i == 2) return "Oscillator 1 Pulse Width";
	if (i == 3) return "Oscillator 1 Saw/Tri Wave Shape";
	if (i == 4) return "Oscillator 2 Pitch";
	if (i == 5) return "Oscillator 2 Pulse Width";
	if (i == 6) return "Oscillator 2 Saw/Tri Wave Shape";
	if (i == 7) return "Oscillator Mix (Balance)";
	if (i == 8) return "VCF FM Amount";
	if (i == 9) return "VCF Cutoff Frequency";
	if (i == 10) return "VCF Resonance";
	if (i == 11) return "VCA 1 Level";
	if (i == 12) return "VCA 2 Level";
	if (i == 13) return "Envelope 1 Delay";
	if (i == 14) return "Envelope 1 Attack";
	if (i == 15) return "Envelope 1 Decay";
	if (i == 16) return "Envelope 1 Release";
	if (i == 17) return "Envelope 1 Amplitude";
	if (i == 18) return "Envelope 2 Delay";
	if (i == 19) return "Envelope 2 Attack";
	if (i == 20) return "Envelope 2 Decay";
	if (i == 21) return "Envelope 2 Release";
	if (i == 22) return "Envelope 2 Amplitude";
	if (i == 23) return "Envelope 3 Delay";
	if (i == 24) return "Envelope 3 Attack";
	if (i == 25) return "Envelope 3 Decay";
	if (i == 26) return "Envelope 3 Release";
	if (i == 27) return "Envelope 3 Amplitude";
	if (i == 28) return "LFO 1 Speed";
	if (i == 29) return "LFO 1 Amplitude";
	if (i == 30) return "LFO 2 Speed";
	if (i == 31) return "LFO 2 Amplitude";
	if (i == 32) return "Portamento Time";
	else return "range error";
}

IntToModDestinationString* IntToModDestinationString::get() noexcept {
	static IntToModDestinationString converter;
	return &converter;
}




String IntToLFOsampleSourceString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 21);
	if (i == 0) return "NONE";
	if (i == 1) return "ENV1";
	if (i == 2) return "ENV2";
	if (i == 3) return "ENV3";
	if (i == 4) return "LFO1";
	if (i == 5) return "LFO2";
	if (i == 6) return "VIB";
	if (i == 7) return "RMP1";
	if (i == 8) return "RMP2";
	if (i == 9) return "KEYB";
	if (i == 10) return "PORT";
	if (i == 11) return "TRAK";
	if (i == 12) return "GATE";
	if (i == 13) return "VEL";
	if (i == 14) return "RVEL";
	if (i == 15) return "PRES";
	if (i == 16) return "PED1";
	if (i == 17) return "PED2";
	if (i == 18) return "LEV1";
	if (i == 19) return "LEV2";
	if (i == 20) return "LEV3";
	else return "ERR";
}

String IntToLFOsampleSourceString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 21);
	if (i == 0) return "None";
	if (i == 1) return "Envelope 1";
	if (i == 2) return "Envelope 2";
	if (i == 3) return "Envelope 3";
	if (i == 4) return "LFO 1";
	if (i == 5) return "LFO 2";
	if (i == 6) return "Vibrato LFO";
	if (i == 7) return "Ramp Generator 1";
	if (i == 8) return "Ramp Generator 2";
	if (i == 9) return "Keyboard Scaling";
	if (i == 10) return "Portamento Speed";
	if (i == 11) return "Tracking Generator";
	if (i == 12) return "Keyboard Note Gate";
	if (i == 13) return "Keyboard Note Velocity";
	if (i == 14) return "Keyboard Release Velocity";
	if (i == 15) return "Keyboard Pressure (Aftertouch)";
	if (i == 16) return "Pedal 1";
	if (i == 17) return "Pedal 2";
	if (i == 18) return "Lever 1";
	if (i == 19) return "Lever 2";
	if (i == 20) return "Lever 3";
	else return "range error";
}

IntToLFOsampleSourceString* IntToLFOsampleSourceString::get() noexcept {
	static IntToLFOsampleSourceString converter;
	return &converter;
}




String IntToRampTrigString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "STRIG";
	if (i == 1) return "MTRIG";
	if (i == 2) return "XTRIG";
	if (i == 3) return "GATEX";
	else return "ERR";
}

String IntToRampTrigString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Single Trigger";
	if (i == 1) return "Multiple Trigger";
	if (i == 2) return "External Single Trigger";
	if (i == 3) return "Gated External Single Trigger";
	else return "range error";
}

IntToRampTrigString* IntToRampTrigString::get() noexcept {
	static IntToRampTrigString converter;
	return &converter;
}




String IntToPortaModeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "LINEAR";
	if (i == 1) return "CONST";
	if (i == 2) return "EXPO";
	else return "ERR";
}

String IntToPortaModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "Linear";
	if (i == 1) return "Constant Time";
	if (i == 2) return "Exponential";
	else return "range error";
}

IntToPortaModeString* IntToPortaModeString::get() noexcept {
	static IntToPortaModeString converter;
	return &converter;
}




String IntToKeyboardModeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "REASGN";
	if (i == 1) return "ROTATE";
	if (i == 2) return "UNISON";
	if (i == 3) return "REAROB";
	else return "ERR";
}

String IntToKeyboardModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Reassign";
	if (i == 1) return "Rotate";
	if (i == 2) return "Unison";
	if (i == 3) return "Reassign Rob";
	else return "range error";
}

IntToKeyboardModeString* IntToKeyboardModeString::get() noexcept {
	static IntToKeyboardModeString converter;
	return &converter;
}




String IntToEnvTrigModeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 8);
	if (i == 0) return "STRIG";
	if (i == 1) return "SRESET";
	if (i == 2) return "MTRIG";
	if (i == 3) return "MRESET";
	if (i == 4) return "XTRIG";
	if (i == 5) return "XRESET";
	if (i == 6) return "XMTRIG";
	if (i == 7) return "XMRST";
	else return "ERR";
}

String IntToEnvTrigModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 8);
	if (i == 0) return "Single Trigger";
	if (i == 1) return "Single Trigger Reset";
	if (i == 2) return "Multiple Trigger";
	if (i == 3) return "Multiple Trigger Reset";
	if (i == 4) return "External Single Trigger";
	if (i == 5) return "External Single Trigger Reset";
	if (i == 6) return "External Multiple Trigger";
	if (i == 7) return "External Multiple Trigger Reset";
	else return "range error";
}

IntToEnvTrigModeString* IntToEnvTrigModeString::get() noexcept {
	static IntToEnvTrigModeString converter;
	return &converter;
}




String IntToEnvModeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "NORMAL";
	if (i == 1) return "DADR";
	if (i == 2) return "FREE";
	if (i == 3) return "BOTH";
	else return "ERR";
}

String IntToEnvModeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Normal";
	if (i == 1) return "Delay-Attack-Decay-Release";
	if (i == 2) return "Free Run";
	if (i == 3) return "Both DADR & Free Run";
	else return "range error";
}

IntToEnvModeString* IntToEnvModeString::get() noexcept {
	static IntToEnvModeString converter;
	return &converter;
}




String IntToEnvLFO1TrigString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "NORMAL";
	if (i == 1) return "G-LFO1";
	if (i == 2) return "LFO 1";
	else return "ERR";
}

String IntToEnvLFO1TrigString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 3);
	if (i == 0) return "Normal (No LFO 1 Trigger)";
	if (i == 1) return "Gated LFO 1 Trigger";
	if (i == 2) return "LFO 1 Trigger";
	else return "range error";
}

IntToEnvLFO1TrigString* IntToEnvLFO1TrigString::get() noexcept {
	static IntToEnvLFO1TrigString converter;
	return &converter;
}




String IntToLFOwaveTypeString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 7);
	if (i == 0) return "TRI";
	if (i == 1) return "UPSAW";
	if (i == 2) return "DNSAW";
	if (i == 3) return "SQUAR";
	if (i == 4) return "RANDM";
	if (i == 5) return "NOISE";
	if (i == 6) return "SAMPL";
	else return "ERR";
}

String IntToLFOwaveTypeString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 7);
	if (i == 0) return "Triangle";
	if (i == 1) return "Up (Positive) Sawtooth";
	if (i == 2) return "Down (Negative) Sawtooth";
	if (i == 3) return "Square";
	if (i == 4) return "Random";
	if (i == 5) return "Noise";
	if (i == 6) return "Sampled";
	else return "range error";
}

IntToLFOwaveTypeString* IntToLFOwaveTypeString::get() noexcept {
	static IntToLFOwaveTypeString converter;
	return &converter;
}




String IntToLFOtrigString::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "OFF";
	if (i == 1) return "STRIG";
	if (i == 2) return "MTRIG";
	if (i == 3) return "XTRIG";
	else return "ERR";
}

String IntToLFOtrigString::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "Off (Free Running)";
	if (i == 1) return "Single Trigger";
	if (i == 2) return "Multiple Trigger";
	if (i == 3) return "External Single Trigger";
	else return "range error";
}

IntToLFOtrigString* IntToLFOtrigString::get() noexcept {
	static IntToLFOtrigString converter;
	return &converter;
}




String IntToPatchBankName::conversionAlgorithm(const uint8& i) noexcept {
	return verboseConversionAlgorithm(i);
}

String IntToPatchBankName::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 13);
	if (i == 0) return "ANALOG SYNTHS A";
	if (i == 1) return "ANALOG SYNTHS B";
	if (i == 2) return "BASSES";
	if (i == 3) return "BRASS & WOODWIND";
	if (i == 4) return "CUSTOM A";
	if (i == 5) return "CUSTOM B";
	if (i == 6) return "FX & PERCUSSION";
	if (i == 7) return "KEYBOARDS A";
	if (i == 8) return "KEYBOARDS B";
	if (i == 9) return "LEADS";
	if (i == 10) return "MISCELLANEOUS A";
	if (i == 11) return "MISCELLANEOUS B";
	if (i == 12) return "STRINGS";
	else return "ERROR";
}

IntToPatchBankName* IntToPatchBankName::get() noexcept {
	static IntToPatchBankName converter;
	return &converter;
}

String IntToZoneVoiceAssignment::conversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "2/4";
	if (i == 1) return "4/2";
	if (i == 2) return "6/0";
	if (i == 3) return "0/6";
	else return "ERR";
}

String IntToZoneVoiceAssignment::verboseConversionAlgorithm(const uint8& i) noexcept {
	jassert(i < 4);
	if (i == 0) return "2 Voices Lower / 4 Voices Upper";
	if (i == 1) return "4 Voices Lower / 2 Voices Upper";
	if (i == 2) return "6 Voices Lower / 0 Voices Upper";
	if (i == 3) return "0 Voices Lower / 6 Voices Upper";
	else return "range error";
}

IntToZoneVoiceAssignment* IntToZoneVoiceAssignment::get() noexcept {
	static IntToZoneVoiceAssignment converter;
	return &converter;
}
