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

