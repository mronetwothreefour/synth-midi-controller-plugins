#pragma once

#include <JuceHeader.h>

// Converts an integer to a note name / octave combination (e.g. "C# 2")
struct IntToPitchName
{
	static String convert(const int& i)
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

struct IntToStringConverter
{
protected:
	virtual String conversionAlgorithm(int, bool) const noexcept = 0;

public:
	String convert(int i, bool isVerbose) const noexcept { return conversionAlgorithm(i, isVerbose); }
};

struct IntToOscPitch : IntToStringConverter
{
protected:
	String conversionAlgorithm(int i, bool isVerbose) const noexcept override
	{
		if (i > -1 && i < 121)
		{
			String pitchName{ IntToPitchName::convert(i) };
			if (isVerbose)
				pitchName += " (MIDI Note " + String(i) + ")";
			return pitchName;
		}
		else if (i > 120 && i < 126) return "--";
		else return "range error";
	}

public:
	static IntToOscPitch* get() { static IntToOscPitch intToOscPitch; return &intToOscPitch; }
};

struct IntToFineTune : IntToStringConverter
{
protected:
	String conversionAlgorithm(int i, bool isVerbose) const noexcept override
	{
		if (i > -1 && i < 101)
		{
			if (i < 49) return (String)(i - 50) + (isVerbose ? " cents" : "");
			if (i == 49) return isVerbose ? "-1 cent" : "-1";
			if (i == 50) return isVerbose ? "No Detune" : "0";
			if (i == 51) return isVerbose ? "+1 cent" : "+1";
			if (i > 51 && i < 101) return "+" + (String)(i - 50) + (isVerbose ? " cents" : "");
			else return "invalid";
		}
		else return "range error";
	}

public:
	static IntToFineTune* get() { static IntToFineTune intToFineTune; return &intToFineTune; }
};

// Each hardware synth parameter gets a reference to a type of
// int-to-String converter (used for displying a parameter's raw
// value as a more meaningful String in GUI controls and tooltips,
// and for generating choices Strings for the public parameters)
struct IntToStringConverterArrayFactory
{
	static void fillArray(Array<IntToStringConverter*>& nrpnArray)
	{
		/*0  */nrpnArray.add(IntToOscPitch::get());
		/*1  */nrpnArray.add(IntToFineTune::get());
	}
};


