#pragma once

#include <JuceHeader.h>

struct IntToPitchName
{
	static String convert(const uint8& i) noexcept
	{
		auto pitchNum{ i % 12 };
		auto octaveNum{ i / 12 };
		String pitchName;
		switch (pitchNum)
		{
		case 0 : pitchName = "C "  + (String)octaveNum; break;
		case 1 : pitchName = "C# " + (String)octaveNum; break;
		case 2 : pitchName = "D "  + (String)octaveNum; break;
		case 3 : pitchName = "D# " + (String)octaveNum; break;
		case 4 : pitchName = "E "  + (String)octaveNum; break;
		case 5 : pitchName = "F "  + (String)octaveNum; break;
		case 6 : pitchName = "F# " + (String)octaveNum; break;
		case 7 : pitchName = "G "  + (String)octaveNum; break;
		case 8 : pitchName = "G# " + (String)octaveNum; break;
		case 9 : pitchName = "A "  + (String)octaveNum; break;
		case 10: pitchName = "A# " + (String)octaveNum; break;
		case 11: pitchName = "B "  + (String)octaveNum; break;
		default: pitchName = "invalid"; break;
		}
		return pitchName;
	}
};

//===========================================================================

struct IntToContextualStringConverter
{
protected:
	virtual String conversionAlgorithm(const uint8& /*i*/) = 0;
	virtual String verboseConversionAlgorithm(const uint8& /*i*/) = 0;

public:
	String convert(const uint8& i) { return conversionAlgorithm(i); }
	String verboseConvert(const uint8& i) { return verboseConversionAlgorithm(i); }
};

//===========================================================================

struct IntToNullString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& /*i*/) override { return "null"; }
	String verboseConversionAlgorithm(const uint8& /*i*/) override { return "null"; }

public:
	static IntToNullString* get() { static IntToNullString converter; return &converter; }
};

//===========================================================================

struct IntToPlainValueString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) override { return (String)i; }
	String verboseConversionAlgorithm(const uint8& i) override { return (String)i; }

public:
	static IntToPlainValueString* get() { static IntToPlainValueString converter; return &converter; }
};

//===========================================================================

struct IntToOscPitchString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) override 
	{ 
		if (i < 121)
		{
			String pitchName{ IntToPitchName::convert(i) };
			return pitchName;
		}
		else if (i > 120 && i < 126) return "--";
		else return "range error";
	}

	String verboseConversionAlgorithm(const uint8& i) override
	{ 
		if (i < 121)
		{
			String pitchName{ IntToPitchName::convert(i) };
			pitchName += " (MIDI Note " + String(i) + ")";
			return pitchName;
		}
		else if (i > 120 && i < 126) return "--";
		else return "range error";
	}

public:
	static IntToOscPitchString* get() { static IntToOscPitchString converter; return &converter; }
};

//===========================================================================

struct IntToFineTuneString : 
	public IntToContextualStringConverter
{
protected:
	String conversionAlgorithm(const uint8& i) override 
	{
		if (i < 101)
		{
			if (i < 51) return (String)(i - 50);
			if (i > 50 && i < 101) return "+" + (String)(i - 50);
			else return "invalid";
		}
		else return "range error";
	}

	String verboseConversionAlgorithm(const uint8& i) override
	{
		if (i < 101)
		{
			if (i < 49) return (String)(i - 50) + " cents";
			if (i == 49) return "-1 cent";
			if (i == 50) return "No Detune";
			if (i == 51) return "+1 cent";
			if (i > 51 && i < 101) return "+" + (String)(i - 50) + " cents";
			else return "invalid";
		}
		else return "range error";
	}

public:
	static IntToFineTuneString* get() { static IntToFineTuneString converter; return &converter; }
};

