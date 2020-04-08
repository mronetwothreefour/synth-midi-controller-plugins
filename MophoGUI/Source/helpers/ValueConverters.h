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
		else if (i > 120 && i < 126) return "--";
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
	// 0..89 = "Un-synced 0..89"
	// 90..150 = "Pitched Frequency C0..C5"
	// 151..156 = Synced to step sequencer
	String intToLFOfreq(const int& i, bool verbose) const
	{
		if (i > -1 && i < 167)
		{
			if (i < 90) return verbose ? "Un-synced " + (String)(i) : (String)(i);
			if (i > 89 && i < 151)
			{
				String pitchString{ intToPitchName(i - 90) };
				return verbose ? (String)i + " (Pitch Freq. " + pitchString + ")" : pitchString;
			}
			if (i > 150 && i < 167)
			{
				switch (i)
				{
				case 151: return verbose ? "Synced " + String(i) +": 1 cycle lasts 32 steps" : "1:32";
				case 152: return verbose ? "Synced " + String(i) +": 1 cycle lasts 16 steps" : "1:16";
				case 153: return verbose ? "Synced " + String(i) +": 1 cycle lasts 8 steps" : "1:8";
				case 154: return verbose ? "Synced " + String(i) +": 1 cycle lasts 6 steps" : "1:6";
				case 155: return verbose ? "Synced " + String(i) +": 1 cycle lasts 4 steps" : "1:4";
				case 156: return verbose ? "Synced " + String(i) +": 1 cycle lasts 3 steps" : "1:3";
				case 157: return verbose ? "Synced " + String(i) +": 1 cycle lasts 2 steps" : "1:2";
				case 158: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1-1/2 steps" : "1:1.5";
				case 159: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1 step" : "1:1";
				case 160: return verbose ? "Synced " + String(i) +": 1 cycle lasts 2/3 step" : "3:2";
				case 161: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/2 step" : "2:1";
				case 162: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/3 step" : "3:1";
				case 163: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/4 step" : "4:1";
				case 164: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/6 step" : "6:1";
				case 165: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/8 step" : "8:1";
				case 166: return verbose ? "Synced " + String(i) +": 1 cycle lasts 1/16 step" : "16:1";
				default: return "invalid"; break;
				}
			}
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..1 to an "off" or "on" String
	String intToOffOn(const int& i) const
	{
		if (i > -1 && i < 2)
		{
			if (i == 0) return "Off";
			if (i == 1) return "On";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..5 to a note priority menu choice String
	String intToNotePriorityChoice(const int& i, bool verbose) const
	{
		if (i > -1 && i < 6)
		{
			if (i == 0) return verbose ? "Low Note Has Priority" : "Low Note";
			if (i == 1) return verbose ? "Low Note Has Priority (Re-trigger)" : "Low Note (Re-trigger)";
			if (i == 2) return verbose ? "High Note Has Priority" : "High Note";
			if (i == 3) return verbose ? "High Note Has Priority (Re-trigger)" : "High Note (Re-trigger)";
			if (i == 4) return verbose ? "Last Note Hit Has Priority" : "Last Note";
			if (i == 5) return verbose ? "Last Note Hit Has Priority (Re-trigger)" : "Last Note (Re-trigger)";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..3 to a glide mode menu choice String
	String intToGlideMode(const int& i) const
	{
		if (i > -1 && i < 4)
		{
			if (i == 0) return "Fixed Rate";
			if (i == 1) return "Fixed Rate Auto";
			if (i == 2) return "Fixed Time";
			if (i == 3) return "Fixed Time Auto";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..3 to an arpeggiator mode menu choice String
	String intToArpegMode(const int& i) const
	{
		if (i > -1 && i < 4)
		{
			if (i == 0) return "Up";
			if (i == 1) return "Down";
			if (i == 2) return "Up & Down";
			if (i == 3) return "Assign";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..1 to a low-pass filter type String
	String intToLPFtype(const int& i) const
	{
		if (i > -1 && i < 2)
		{
			if (i == 0) return "2-Pole";
			if (i == 1) return "4-Pole";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..22 to a modulation source String
	String intToModSource(const int& i) const
	{
		if (i > -1 && i < 23)
		{
			if (i == 0 ) return "Off";
			if (i == 1 ) return "Sequencer Track 1";
			if (i == 2 ) return "Sequencer Track 2";
			if (i == 3 ) return "Sequencer Track 3";
			if (i == 4 ) return "Sequencer Track 4";
			if (i == 5 ) return "LFO 1";
			if (i == 6 ) return "LFO 2";
			if (i == 7 ) return "LFO 3";
			if (i == 8 ) return "LFO 4";
			if (i == 9 ) return "LPF Envelope";
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
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..46 to a modulation destination String
	String intToModDestination(const int& i) const
	{
		if (i > -1 && i < 47)
		{
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
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 1..3 to an LFO type String
	// 1 = "Un-synced"; 2 = "Pitch"; 3 = "Synced"
	String intToLFOtype(const int& i) const
	{
		if (i > -1 && i < 3)
		{
			if (i == 0) return "Un-synced";
			if (i == 1) return "Pitch";
			if (i == 2) return "Synced";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..4 to a low-frequency oscillator wave shape String
	// 0 = "Triangle"; 1 = "Reverse Sawtooth"; 2 = "Sawtooth"; 3 = "Square Wave";
	// 4 = "Random"
	String intToLFOshape(const int& i) const
	{
		if (i > -1 && i < 5)
		{
			if (i == 0) return "Triangle";
			if (i == 1) return "Reverse Sawtooth";
			if (i == 2) return "Sawtooth";
			if (i == 3) return "Square Wave";
			if (i == 4) return "Random";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..5 to a sequencer trigger mode String
	// 0 = "Normal"; 1 = "Normal, No Reset"; 2 = "No Gate"; 3 = "No Gate, No Reset";
	// 4 = "Key Step"; 5 = "Audio Input"
	String intToSeqTrigger(const int& i) const
	{
		if (i > -1 && i < 6)
		{
			if (i == 0) return "Normal";
			if (i == 1) return "Normal, No Reset";
			if (i == 2) return "No Gate";
			if (i == 3) return "No Gate, No Reset";
			if (i == 4) return "Key Step";
			if (i == 5) return "Audio Input";
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..12 to a clock division String
	String intToClockDiv(const int& i, bool verbose) const
	{
		if (i > -1 && i < 13)
		{
			if (i == 0 ) return verbose ? "Half Note (BPM / 2)" : "Half Note";
			if (i == 1 ) return verbose ? "Quarter Note (BPM x 1)" : "Quarter Note";
			if (i == 2 ) return verbose ? "8th Note (BPM x 2)" : "8th Note";
			if (i == 3 ) return verbose ? "8th Note, 1/2 Swing (BPM x 2)" : "8th Note, 1/2 Swing";
			if (i == 4 ) return verbose ? "8th Note, Full Swing (BPM x 2)" : "8th Note, Full Swing";
			if (i == 5 ) return verbose ? "8th Note Triplets (BPM x 3)" : "8th Note Triplets";
			if (i == 6 ) return verbose ? "16th Note (BPM x 4)" : "16th Note";
			if (i == 7 ) return verbose ? "16th Note, 1/2 Swing (BPM x 4)" : "16th Note, 1/2 Swing";
			if (i == 8 ) return verbose ? "16th Note, Full Swing (BPM x 4)" : "16th Note, Full Swing";
			if (i == 9 ) return verbose ? "16th Note Triplets (BPM x 6)" : "16th Note Triplets";
			if (i == 10) return verbose ? "32nd Note (BPM x 8)" : "32nd Note";
			if (i == 11) return verbose ? "32nd Note Triplets (BPM x 12)" : "32nd Note Triplets";
			if (i == 12) return verbose ? "64th Note Triplets (BPM x 24)" : "64th Note Triplets";
			else return "invalid";
		}
		else return "range error";
	}


	// Converts integers 0..220 to a clock tempo String ("30".."250")
	String intToClockTempo(const int& i) const
	{
		if (i > -1 && i < 221)
		{
			return (String)(i + 30);
		}
		else return "range error";
	}

	String intToSeqStepPitchName(const int& i) const
	{
			auto pitchNum{ i % 24 };
			auto octaveNum{ i / 24 };
			String pitchName;
			switch (pitchNum)
			{
			case 0 : pitchName = "C"  + (String)octaveNum; break;
			case 1 : pitchName = "C"  + (String)octaveNum + "+"; break;
			case 2 : pitchName = "C#" + (String)octaveNum; break;
			case 3 : pitchName = "C#" + (String)octaveNum + "+"; break;
			case 4 : pitchName = "D"  + (String)octaveNum; break;
			case 5 : pitchName = "D"  + (String)octaveNum + "+"; break;
			case 6 : pitchName = "D#" + (String)octaveNum; break;
			case 7 : pitchName = "D#" + (String)octaveNum + "+"; break;
			case 8 : pitchName = "E"  + (String)octaveNum; break;
			case 9 : pitchName = "E"  + (String)octaveNum + "+"; break;
			case 10: pitchName = "F"  + (String)octaveNum; break;
			case 11: pitchName = "F"  + (String)octaveNum + "+"; break;
			case 12: pitchName = "F#" + (String)octaveNum; break;
			case 13: pitchName = "F#" + (String)octaveNum + "+"; break;
			case 14: pitchName = "G"  + (String)octaveNum; break;
			case 15: pitchName = "G"  + (String)octaveNum + "+"; break;
			case 16: pitchName = "G#" + (String)octaveNum; break;
			case 17: pitchName = "G#" + (String)octaveNum + "+"; break;
			case 18: pitchName = "A"  + (String)octaveNum; break;
			case 19: pitchName = "A"  + (String)octaveNum + "+"; break;
			case 20: pitchName = "A#" + (String)octaveNum; break;
			case 21: pitchName = "A#" + (String)octaveNum + "+"; break;
			case 22: pitchName = "B"  + (String)octaveNum; break;
			case 23: pitchName = "B"  + (String)octaveNum + "+"; break;
			default: pitchName = "invalid"; break;
			}
			return pitchName;
	}

	// Converts integers 0..127 to a sequencer step value String
	// 0..125 (C0..D5+); 126 = "Reset Sequence"; 127 = "Rest"
	String intToStepValue(const int& i, bool isPitch) const
	{
		if (i > -1 && i < 128)
		{
			if (i < 126) return isPitch ? intToSeqStepPitchName(i) : (String)(i);
			else if (i == 126) return (String)("Reset Sequence");
			else if (i == 127) return (String)("Rest");
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..2 to a Push It! switch mode String
	// 0 = "Normal"; 1 = "Toggle"; 2 = "Audio In"
	String intToPushItMode(const int& i) const
	{
		if (i > -1 && i < 3)
		{
			if (i == 0) return "Normal";
			if (i == 1) return "Toggle";
			if (i == 2) return "Audio In";
			else return "invalid";
		}
		else return "range error";
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueConverters)
};