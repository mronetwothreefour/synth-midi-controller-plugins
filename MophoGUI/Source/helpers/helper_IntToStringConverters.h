#pragma once

#include <JuceHeader.h>

struct IntToStringConverters
{
	enum Types {ToPlainValue, ToOscPitch, ToFineTune};

	static String convertIntToPitchName(const uint8& i) noexcept
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

	static String convertInt(uint8 i, int conversionType, bool isVerbose)
	{
		switch (conversionType)
		{
		case ToPlainValue:
			return (String)i;
		case ToOscPitch:
			if (i < 121)
			{
				String pitchName{ convertIntToPitchName(i) };
				if (isVerbose)
					pitchName += " (MIDI Note " + String(i) + ")";
				return pitchName;
			}
			else if (i > 120 && i < 126) return "--";
			else return "range error";
		case ToFineTune:
			if (i < 101)
			{
				if (i < 49) return (String)(i - 50) + (isVerbose ? " cents" : "");
				if (i == 49) return isVerbose ? "-1 cent" : "-1";
				if (i == 50) return isVerbose ? "No Detune" : "0";
				if (i == 51) return isVerbose ? "+1 cent" : "+1";
				if (i > 51 && i < 101) return "+" + (String)(i - 50) + (isVerbose ? " cents" : "");
				else return "invalid";
			}
			else return "range error";
		default:
			return "unknown converter";
		}
	}
};
