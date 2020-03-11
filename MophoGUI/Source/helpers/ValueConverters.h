#pragma once

#include <JuceHeader.h>

// A collection of functions for converting
// integer values into various parameter
// value Strings
struct ValueConverters
{
	ValueConverters() {}
	~ValueConverters() {}

	// Converts MIDI note numbers 0..120 to a pitch name + octave
	// number String (e.g. note number 27 converts to "D# 2").
	// If verbose is true, the note number is appended to the String
	String intToPitchName(const int& i, bool verbose) const
	{
		if (i > -1 && i < 121)
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
			if (verbose)
				pitchName += " (" + String(i) + ")";
			return pitchName;
		}
		else return "range error";
	}

	// Converts integers 0..100 to a fine tune range value String
	// 0 = "-50"; 50 = "C"; 100 = "+50"
	// If verbose is true:
	// 0 = "-50 cents"; 50 = "Centered"; 100 = "+50 cents"
	String intToFineTuneRange(const int& i, bool verbose) const
	{
		if (i > -1 && i < 101)
		{
			if (i < 49) return (String)(i - 50) + (verbose ? " cents" : "");
			if (i == 49) return verbose ? "-1 cent" : "-1";
			if (i == 50) return verbose ? "Centered" : "0";
			if (i == 51) return verbose ? "+1 cent" : "+1";
			if (i > 51) return "+" + (String)(i - 50) + (verbose ? " cents" : "");
			else return "invalid";
		}
		else return "range error";
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueConverters)
};