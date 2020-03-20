#pragma once

#include <JuceHeader.h>

// A collection of functions for converting
// integer values into various parameter
// value Strings
struct ValueConverters
{
	ValueConverters() {}
	~ValueConverters() {}

	String intToPitchName(const int& i) const
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

	// Converts MIDI note numbers 0..120 to a pitch name + octave
	// number String (e.g. note number 27 converts to "D# 2").
	// If verbose is true, the note number is appended to the String
	String intToOscPitchString(const int& i, bool verbose) const
	{
		if (i > -1 && i < 121)
		{
			String pitchName{ intToPitchName(i) };
			if (verbose)
				pitchName += " (MIDI Note " + String(i) + ")";
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
			if (i == 50) return verbose ? "No Detune" : "0";
			if (i == 51) return verbose ? "+1 cent" : "+1";
			if (i > 51 && i < 101) return "+" + (String)(i - 50) + (verbose ? " cents" : "");
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..103 to an oscillator wave shape String
	// 0 = "Off"; 1 = "Sawtooth"; 2 = "Triangle"; 3 = "Saw/Tri Mix";
	// 4..103 = "Pulse Width 0..99"
	String intToOscWaveShape(const int& i) const
	{
		if (i > -1 && i < 104)
		{
			if (i == 0) return "Oscillator Off";
			if (i == 1) return "Sawtooth";
			if (i == 2) return "Triangle";
			if (i == 3) return "Sawtooth/Triangle Mix";
			if (i > 3 && i < 104) return "Pulse (Width: " + String(i - 4) + ")";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..12 to a pitch bend range String
	String intToBendRange(const int& i, bool verbose) const
	{
		if (i > -1 && i < 13)
		{
			if (i == 0) return verbose ? "No Bend" : "0";
			if (i == 1) return verbose ? "+/-1 semitone" : "+/-1";
			if (i > 1 && i < 13) return verbose ? "+/-" + (String)i + " semitones" : "+/-" + (String)i;
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..164 to a LPF cutoff frequency String
	String intToLPFfreq(const int& i, bool verbose) const
	{
		if (i > -1 && i < 165)
		{
			String pitchString{ intToPitchName(i) };
			return verbose ? (String)i + " (Pitch Freq. " + pitchString + ")" : pitchString;
		}
		else return "range error";
	}

	// Converts integers 0..254 to a -127..+127 range String
	// 0 = "-127"; 127 = "0"; 254 = "+127"
	String intToPlusMinus127(const int& i) const
	{
		if (i > -1 && i < 255)
		{
			if (i < 128) return (String)(i - 127);
			if (i > 127 && i < 255) return "+" + (String)(i - 127);
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..150 into an LFO frequency setting String
	// 0..89 = "Unsynced 0..89"
	// 90..150 = "Pitched Frequency C0..C5"
	// 151..156 = Sync to step sequencer
	String intToLFOfreq(const int& i, bool verbose) const
	{
		if (i > -1 && i < 167)
		{
			if (i < 90) return verbose ? "Un-synced " + (String)(i) : (String)(i);
			if (i > 89 && i < 151)
			{
				String pitchString{ intToPitchName(i) };
				return verbose ? (String)i + " (Pitch Freq. " + pitchString + ")" : pitchString;
			}
			if (i > 150 && i < 167)
			{
				switch (i)
				{
				case 151: return verbose ? "Sequencer Sync: 32 steps" : "1:32";
				case 152: return verbose ? "Sequencer Sync: 16 steps" : "1:16";
				case 153: return verbose ? "Sequencer Sync: 8 steps" : "1:8";
				case 154: return verbose ? "Sequencer Sync: 6 steps" : "1:6";
				case 155: return verbose ? "Sequencer Sync: 4 steps" : "1:4";
				case 156: return verbose ? "Sequencer Sync: 3 steps" : "1:3";
				case 157: return verbose ? "Sequencer Sync: 2 steps" : "1:2";
				case 158: return verbose ? "Sequencer Sync: 1-1/2 steps" : "1:1.5";
				case 159: return verbose ? "Sequencer Sync: 1 step" : "1:1";
				case 160: return verbose ? "Sequencer Sync: 2/3 step" : "3:2";
				case 161: return verbose ? "Sequencer Sync: 1/2 step" : "2:1";
				case 162: return verbose ? "Sequencer Sync: 1/3 step" : "3:1";
				case 163: return verbose ? "Sequencer Sync: 1/4 step" : "4:1";
				case 164: return verbose ? "Sequencer Sync: 1/6 step" : "6:1";
				case 165: return verbose ? "Sequencer Sync: 1/8 step" : "8:1";
				case 166: return verbose ? "Sequencer Sync: 1/16 step" : "16:1";
				default: return "invalid"; break;
				}
			}
			else return "invalid";
		}
		else return "range error";
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueConverters)
};