#pragma once

#include <JuceHeader.h>

// A collection of functions for converting
// integer values into various parameter
// value Strings
struct ValueConverters
{
	String intToPitchName(int i) const
	{
		auto pitchNum{ i % 12 };
		auto octaveNum{ i / 12 };
		String pitchName;
		switch (pitchNum)
		{
		case 0 : pitchName = "C "  + (String)octaveNum; return pitchName;
		case 1 : pitchName = "C# " + (String)octaveNum; return pitchName;
		case 2 : pitchName = "D "  + (String)octaveNum; return pitchName;
		case 3 : pitchName = "D# " + (String)octaveNum; return pitchName;
		case 4 : pitchName = "E "  + (String)octaveNum; return pitchName;
		case 5 : pitchName = "F "  + (String)octaveNum; return pitchName;
		case 6 : pitchName = "F# " + (String)octaveNum; return pitchName;
		case 7 : pitchName = "G "  + (String)octaveNum; return pitchName;
		case 8 : pitchName = "G# " + (String)octaveNum; return pitchName;
		case 9 : pitchName = "A "  + (String)octaveNum; return pitchName;
		case 10: pitchName = "A# " + (String)octaveNum; return pitchName;
		case 11: pitchName = "B "  + (String)octaveNum; return pitchName;
		default: pitchName = "invalid"; return pitchName;
		}
	}
};