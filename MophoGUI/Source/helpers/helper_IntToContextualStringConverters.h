#pragma once

#include <JuceHeader.h>



struct IntToPitchName
{
	static String convert(const uint8& i) noexcept {
		auto pitchNum{ i % 12 };
		auto octaveNum{ i / 12 };
		String pitchName;
		switch (pitchNum) {
		case 0 : 
			pitchName = "C "  + (String)octaveNum; 
			break;
		case 1 : 
			pitchName = "C# " + (String)octaveNum; 
			break;
		case 2 : 
			pitchName = "D "  + (String)octaveNum; 
			break;
		case 3 : 
			pitchName = "D# " + (String)octaveNum; 
			break;
		case 4 : 
			pitchName = "E "  + (String)octaveNum; 
			break;
		case 5 : 
			pitchName = "F "  + (String)octaveNum; 
			break;
		case 6 : 
			pitchName = "F# " + (String)octaveNum; 
			break;
		case 7 : 
			pitchName = "G "  + (String)octaveNum; 
			break;
		case 8 : 
			pitchName = "G# " + (String)octaveNum; 
			break;
		case 9 : 
			pitchName = "A "  + (String)octaveNum; 
			break;
		case 10: 
			pitchName = "A# " + (String)octaveNum; 
			break;
		case 11: 
			pitchName = "B "  + (String)octaveNum; 
			break;
		default: 
			pitchName = "invalid"; 
			break;
		}
		return pitchName;
	}
};



struct IntToContextualStringConverter
{
protected:
	virtual String conversionAlgorithm(const uint8& /*i*/) noexcept = 0;
	virtual String verboseConversionAlgorithm(const uint8& /*i*/) noexcept = 0;

public:
	String convert(const uint8& i) noexcept {
		return conversionAlgorithm(i); 
	}

	String verboseConvert(const uint8& i) noexcept {
		return verboseConversionAlgorithm(i); 
	}
};



struct IntToNullString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& /*i*/) noexcept override {
		return "null"; 
	}

	String verboseConversionAlgorithm(const uint8& /*i*/) noexcept override {
		return "null"; 
	}

public:
	static IntToNullString* get() noexcept {
		static IntToNullString converter; 
		return &converter; 
	}
};



struct IntToPlainValueString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		return (String)i; 
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		return (String)i; 
	}

public:
	static IntToPlainValueString* get() noexcept {
		static IntToPlainValueString converter; 
		return &converter; 
	}
};



struct IntToOscPitchString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 121);
		String pitchName{ IntToPitchName::convert(i) };
		return pitchName;
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 121);
		String pitchName{ IntToPitchName::convert(i) };
		pitchName += " (MIDI Note " + String(i) + ")";
		return pitchName;
	}

public:
	static IntToOscPitchString* get() noexcept {
		static IntToOscPitchString converter; 
		return &converter; 
	}
};



struct IntToFineTuneString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 101);
		if (i < 51) return (String)(i - 50);
		if (i > 50 && i < 101) return "+" + (String)(i - 50);
		else return "err";
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 101);
		if (i < 49) return (String)(i - 50) + " cents";
		if (i == 49) return "-1 cent";
		if (i == 50) return "No Detune";
		if (i == 51) return "+1 cent";
		if (i > 51 && i < 101) return "+" + (String)(i - 50) + " cents";
		else return "range error";
	}

public:
	static IntToFineTuneString* get() noexcept {
		static IntToFineTuneString converter; 
		return &converter; 
	}
};



struct IntToOscWaveShapeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 104);
		if (i == 0) return "Oscillator Off";
		if (i == 1) return "Sawtooth";
		if (i == 2) return "Triangle";
		if (i == 3) return "Sawtooth/Triangle Mix";
		if (i > 3 && i < 104) return "Pulse (Width: " + String(i - 4) + ")";
		else return "range error";
	}

public:
	static IntToOscWaveShapeString* get() noexcept {
		static IntToOscWaveShapeString converter; 
		return &converter; 
	}
};



struct IntToOffOnString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 2);
		return i == 0 ? "Off" : "On";
	}

public:
	static IntToOffOnString* get() noexcept {
		static IntToOffOnString converter;
		return &converter; 
	}
};



struct IntToGlideModeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 4);
		if (i == 0) return "Fixed Rate";
		if (i == 1) return "Fixed Rate Auto";
		if (i == 2) return "Fixed Time";
		if (i == 3) return "Fixed Time Auto";
		else return "range error";
	}

public:
	static IntToGlideModeString* get() noexcept {
		static IntToGlideModeString converter;
		return &converter; 
	}
};



struct IntToBendRangeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		jassert(i < 13);
		if (i == 0) return "0";
		if (i > 0 && i < 13) return "+/-" + (String)i;
		else return "range error";
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 13);
		if (i == 0) return "No Bend";
		if (i == 1) return "+/-1 semitone";
		if (i > 1 && i < 13) return "+/-" + (String)i + " semitones";
		else return "range error";
	}

public:
	static IntToBendRangeString* get() noexcept {
		static IntToBendRangeString converter;
		return &converter; 
	}
};



struct IntToNotePriorityString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		jassert(i < 6);
		if (i == 0) return "Low Note";
		if (i == 1) return "Low Note (Re-trigger)";
		if (i == 2) return "High Note";
		if (i == 3) return "High Note (Re-trigger)";
		if (i == 4) return "Last Note";
		if (i == 5) return "Last Note (Re-trigger)";
		else return "range error";
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 6);
		if (i == 0) return "Low Note Has Priority";
		if (i == 1) return "Low Note Has Priority (Re-trigger)";
		if (i == 2) return "High Note Has Priority";
		if (i == 3) return "High Note Has Priority (Re-trigger)";
		if (i == 4) return "Last Note Hit Has Priority";
		if (i == 5) return "Last Note Hit Has Priority (Re-trigger)";
		else return "range error";
	}

public:
	static IntToNotePriorityString* get() noexcept {
		static IntToNotePriorityString converter;
		return &converter; 
	}
};



struct IntToLPFfreqString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		jassert(i < 165);
		String pitchString{ IntToPitchName::convert(i) };
		return pitchString;
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 165);
		String pitchString{ IntToPitchName::convert(i) };
		return (String)i + " (Pitch Freq. " + pitchString + ")";
	}

public:
	static IntToLPFfreqString* get() noexcept {
		static IntToLPFfreqString converter;
		return &converter; 
	}
};



struct IntToLPFtypeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 2);
		return i == 0 ? "2-Pole" : "4-Pole";
	}

public:
	static IntToLPFtypeString* get() noexcept {
		static IntToLPFtypeString converter;
		return &converter; 
	}
};



struct IntToPlusMinus127String :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override  {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 255);
		return (i > 127 ? "+" : "") + (String)(i - 127);
	}

public:
	static IntToPlusMinus127String* get() noexcept {
		static IntToPlusMinus127String converter;
		return &converter; 
	}
};



struct IntToLFOfreqString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
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

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
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

public:
	static IntToLFOfreqString* get() noexcept {
		static IntToLFOfreqString converter;
		return &converter;
	}
};



struct IntToLFOshapeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 5);
		if (i == 0) return "Triangle";
		if (i == 1) return "Reverse Sawtooth";
		if (i == 2) return "Sawtooth";
		if (i == 3) return "Square Wave";
		if (i == 4) return "Random";
		else return "range error";
	}

public:
	static IntToLFOshapeString* get() noexcept {
		static IntToLFOshapeString converter;
		return &converter;
	}
};



struct IntToModDestinationString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
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

public:
	static IntToModDestinationString* get() noexcept {
		static IntToModDestinationString converter;
		return &converter;
	}
};



struct IntToModSourceString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 23);
		if (i == 0) return "Off";
		if (i == 1) return "Sequencer Track 1";
		if (i == 2) return "Sequencer Track 2";
		if (i == 3) return "Sequencer Track 3";
		if (i == 4) return "Sequencer Track 4";
		if (i == 5) return "LFO 1";
		if (i == 6) return "LFO 2";
		if (i == 7) return "LFO 3";
		if (i == 8) return "LFO 4";
		if (i == 9) return "LPF Envelope";
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

public:
	static IntToModSourceString* get() noexcept {
		static IntToModSourceString converter;
		return &converter;
	}
};



struct IntToPushItModeString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		return verboseConversionAlgorithm(i);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 3);
		if (i == 0) return "Normal";
		if (i == 1) return "Toggle";
		if (i == 2) return "Audio In";
		else return "range error";
	}

public:
	static IntToPushItModeString* get() noexcept {
		static IntToPushItModeString converter;
		return &converter;
	}
};



struct IntToClockTempoString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 221);
		return (String)(i + 30);
	}

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
		jassert(i < 221);
		return (String)(i + 30) + " BPM";
	}

public:
	static IntToClockTempoString* get() noexcept {
		static IntToClockTempoString converter;
		return &converter;
	}
};



struct IntToClockDivString :
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) noexcept override {
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

	String verboseConversionAlgorithm(const uint8& i) noexcept override {
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

public:
	static IntToClockDivString* get() noexcept {
		static IntToClockDivString converter;
		return &converter;
	}
};

