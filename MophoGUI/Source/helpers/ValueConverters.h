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

	// Converts integers 0..184 to a parameter name String
	String intToParamName(const int& i, bool verbose) const
	{
		if (i > -1 && i < 169)
		{
			/*0  */if (i == 0  ) return "Oscillator 1 Pitch";
			/*1  */if (i == 1  ) return "Oscillator 1 Fine Tune";
			/*2  */if (i == 2  ) return "Oscillator 1 Wave Shape";
			/*3  */if (i == 3  ) return "Oscillator 1 Glide Rate";
			/*4  */if (i == 4  ) return "Oscillator 1 Key Track";
			/*5  */if (i == 5  ) return "Sub-Oscillator 1 Level";
			/*6  */if (i == 6  ) return "Oscillator 2 Pitch";
			/*7  */if (i == 7  ) return "Oscillator 2 Fine Tune";
			/*8  */if (i == 8  ) return "Oscillator 2 Wave Shape";
			/*9  */if (i == 9  ) return "Oscillator 2 Glide Rate";
			/*10 */if (i == 10 ) return "Oscillator 2 Key Track";
			/*11 */if (i == 11 ) return "Sub-Oscillator 2 Level";
			/*12 */if (i == 12 ) return "Hard Sync Oscillators";
			/*13 */if (i == 13 ) return "Glide Mode";
			/*14 */if (i == 14 ) return "Oscillator Slop";
			/*15 */if (i == 15 ) return "Pitch Bend Range";
			/*16 */if (i == 16 ) return "Keyed Note Priority";
			/*17 */if (i == 17 ) return "Oscillators 1 & 2 Mix";
			/*18 */if (i == 18 ) return "Noise Level";
			/*19 */if (i == 19 ) return verbose ? "External Audio Input Level" : "External Audio In Level";
			/*20 */if (i == 20 ) return "LPF Cutoff Frequency";
			/*21 */if (i == 21 ) return "LPF Resonance";				
			/*22 */if (i == 22 ) return "LPF Keyboard Amount";			
			/*23 */if (i == 23 ) return "LPF Freq. Mod. On/Off";	
			/*24 */if (i == 24 ) return "LPF 2- or 4-Pole Select";					
			/*25 */if (i == 25 ) return "LPF Envelope Amount";
			/*26 */if (i == 26 ) return verbose ? "LPF Envelope Velocity Amount" : "LPF Env Vel Amt";
			/*27 */if (i == 27 ) return "LPF Envelope Delay";
			/*28 */if (i == 28 ) return "LPF Envelope Attack";
			/*29 */if (i == 29 ) return "LPF Envelope Decay";
			/*30 */if (i == 30 ) return "LPF Envelope Sustain";
			/*31 */if (i == 31 ) return "LPF Envelope Release";
			/*32 */if (i == 32 ) return "VCA Initial Level";
			/*33 */if (i == 33 ) return "VCA Envelope Amount";
			/*34 */if (i == 34 ) return verbose ? "VCA Envelope Velocity Amount" : "VCA Env Vel Amnt";
			/*35 */if (i == 35 ) return "VCA Envelope Delay";
			/*36 */if (i == 36 ) return "VCA Envelope Attack";
			/*37 */if (i == 37 ) return "VCA Envelope Decay";
			/*38 */if (i == 38 ) return "VCA Envelope Sustain";
			/*39 */if (i == 39 ) return "VCA Envelope Release";
			/*40 */if (i == 40 ) return "Voice Volume";
			/*41 */if (i == 41 ) return "LFO 1 Frequency";
			/*42 */if (i == 42 ) return "LFO 1 Wave Shape";
			/*43 */if (i == 43 ) return "LFO 1 Amount";
			/*44 */if (i == 44 ) return verbose ? "LFO 1 Modulation Destination" : "LFO 1 Mod Destination";
			/*45 */if (i == 45 ) return "LFO 1 Key Sync";
			/*46 */if (i == 46 ) return "LFO 2 Frequency";
			/*47 */if (i == 47 ) return "LFO 2 Wave Shape";
			/*48 */if (i == 48 ) return "LFO 2 Amount";
			/*49 */if (i == 49 ) return verbose ? "LFO 2 Modulation Destination" : "LFO 2 Mod Destination";
			/*50 */if (i == 50 ) return "LFO 2 Key Sync";
			/*51 */if (i == 51 ) return "LFO 3 Frequency";
			/*52 */if (i == 52 ) return "LFO 3 Wave Shape";
			/*53 */if (i == 53 ) return "LFO 3 Amount";
			/*54 */if (i == 54 ) return verbose ? "LFO 3 Modulation Destination" : "LFO 3 Mod Destination";
			/*55 */if (i == 55 ) return "LFO 3 Key Sync";
			/*56 */if (i == 56 ) return "LFO 4 Frequency";
			/*57 */if (i == 57 ) return "LFO 4 Wave Shape";
			/*58 */if (i == 58 ) return "LFO 4 Amount";
			/*59 */if (i == 59 ) return verbose ? "LFO 4 Modulation Destination" : "LFO 4 Mod Destination";
			/*60 */if (i == 60 ) return "LFO 4 Key Sync";
			/*61 */if (i == 61 ) return verbose ? "Envelope 3 Mod Destination" : "Env 3 Mod Destination";
			/*62 */if (i == 62 ) return "Envelope 3 Amount";
			/*63 */if (i == 63 ) return verbose ? "Envelope 3 Velocity Amount" : "Env 3 Velocity Amount";
			/*64 */if (i == 64 ) return "Envelope 3 Delay";
			/*65 */if (i == 65 ) return "Envelope 3 Attack";
			/*66 */if (i == 66 ) return "Envelope 3 Decay";
			/*67 */if (i == 67 ) return "Envelope 3 Sustain";
			/*68 */if (i == 68 ) return "Envelope 3 Release";
			/*69 */if (i == 69 ) return "Envelope 3 Repeat"	;
			/*70 */if (i == 70 ) return "Modulator 1 Source";
			/*71 */if (i == 71 ) return "Modulator 1 Amount";
			/*72 */if (i == 72 ) return "Modulator 1 Destination";
			/*73 */if (i == 73 ) return "Modulator 2 Source";
			/*74 */if (i == 74 ) return "Modulator 2 Amount";
			/*75 */if (i == 75 ) return "Modulator 2 Destination";
			/*76 */if (i == 76 ) return "Modulator 3 Source";
			/*77 */if (i == 77 ) return "Modulator 3 Amount";
			/*78 */if (i == 78 ) return "Modulator 3 Destination";
			/*79 */if (i == 79 ) return "Modulator 4 Source";
			/*80 */if (i == 80 ) return "Modulator 4 Amount";
			/*81 */if (i == 81 ) return "Modulator 4 Destination";
			/*82 */if (i == 82 ) return verbose ? "Modulation Wheel Amount"	: "Modulation Wheel Amt";
			/*83 */if (i == 83 ) return verbose ? "Modulation Wheel Destination" : "Modulation Wheel Dest";
			/*84 */if (i == 84 ) return "Aftertouch Amount";
			/*85 */if (i == 85 ) return "Aftertouch Destination";
			/*86 */if (i == 86 ) return verbose ? "Breath Controller Amount" : "Breath Amount";
			/*87 */if (i == 87 ) return verbose ? "Breath Controller Destination" : "Breath Destination";
			/*88 */if (i == 88 ) return "Velocity Amount";
			/*89 */if (i == 89 ) return "Velocity Destination";
			/*90 */if (i == 90 ) return "Foot Pedal Amount";
			/*91 */if (i == 91 ) return "Foot Pedal Destination";
			/*92 */if (i == 92 ) return "Push It! Switch Pitch";
			/*93 */if (i == 93 ) return "Push It! Switch Velocity";
			/*94 */if (i == 94 ) return "Push It! Switch Mode";
			/*95 */if (i == 95 ) return "Clock Tempo (BPM)";
			/*96 */if (i == 96 ) return "Clock Divide";
			/*97 */if (i == 97 ) return "Arpeggiator Mode";
			/*98 */if (i == 98 ) return "Arpeggiator On/Off";
			/*99 */if (i == 99 ) return "Sequencer Trigger Mode";
			/*100*/if (i == 100) return "Sequencer On/Off";
			/*101*/if (i == 101) return verbose ? "Sequencer Track 1 Destination" : "Sequencer Track 1 Dest";
			/*102*/if (i == 102) return verbose ? "Sequencer Track 2 Destination" : "Sequencer Track 2 Dest";
			/*103*/if (i == 103) return verbose ? "Sequencer Track 3 Destination" : "Sequencer Track 3 Dest";
			/*104*/if (i == 104) return verbose ? "Sequencer Track 4 Destination" : "Sequencer Track 4 Dest";
			// Parameters 105..108 used for assigning parameters to the
			// hardware knobs and parameters 109..119 are unassigned.
			// These parameters are left out and the parameter number discrepancy
			// is handled by the processor in parameterValueChanged()
			/*120*/if (i == 105) return verbose ? "Sequencer Track 1 Step 1"  : "Seq Track 1 Step 1" ;
			/*121*/if (i == 106) return verbose ? "Sequencer Track 1 Step 2"  : "Seq Track 1 Step 2" ;
			/*122*/if (i == 107) return verbose ? "Sequencer Track 1 Step 3"  : "Seq Track 1 Step 3" ;
			/*123*/if (i == 108) return verbose ? "Sequencer Track 1 Step 4"  : "Seq Track 1 Step 4" ;
			/*124*/if (i == 109) return verbose ? "Sequencer Track 1 Step 5"  : "Seq Track 1 Step 5" ;
			/*125*/if (i == 110) return verbose ? "Sequencer Track 1 Step 6"  : "Seq Track 1 Step 6" ;
			/*126*/if (i == 111) return verbose ? "Sequencer Track 1 Step 7"  : "Seq Track 1 Step 7" ;
			/*127*/if (i == 112) return verbose ? "Sequencer Track 1 Step 8"  : "Seq Track 1 Step 8" ;
			/*128*/if (i == 113) return verbose ? "Sequencer Track 1 Step 9"  : "Seq Track 1 Step 9" ;
			/*129*/if (i == 114) return verbose ? "Sequencer Track 1 Step 10" : "Seq Track 1 Step 10";
			/*130*/if (i == 115) return verbose ? "Sequencer Track 1 Step 11" : "Seq Track 1 Step 11";
			/*131*/if (i == 116) return verbose ? "Sequencer Track 1 Step 12" : "Seq Track 1 Step 12";
			/*132*/if (i == 117) return verbose ? "Sequencer Track 1 Step 13" : "Seq Track 1 Step 13";
			/*133*/if (i == 118) return verbose ? "Sequencer Track 1 Step 14" : "Seq Track 1 Step 14";
			/*134*/if (i == 119) return verbose ? "Sequencer Track 1 Step 15" : "Seq Track 1 Step 15";
			/*135*/if (i == 120) return verbose ? "Sequencer Track 1 Step 16" : "Seq Track 1 Step 16";
			/*136*/if (i == 121) return verbose ? "Sequencer Track 2 Step 1"  : "Seq Track 2 Step 1" ;
			/*137*/if (i == 122) return verbose ? "Sequencer Track 2 Step 2"  : "Seq Track 2 Step 2" ;
			/*138*/if (i == 123) return verbose ? "Sequencer Track 2 Step 3"  : "Seq Track 2 Step 3" ;
			/*139*/if (i == 124) return verbose ? "Sequencer Track 2 Step 4"  : "Seq Track 2 Step 4" ;
			/*140*/if (i == 125) return verbose ? "Sequencer Track 2 Step 5"  : "Seq Track 2 Step 5" ;
			/*141*/if (i == 126) return verbose ? "Sequencer Track 2 Step 6"  : "Seq Track 2 Step 6" ;
			/*142*/if (i == 127) return verbose ? "Sequencer Track 2 Step 7"  : "Seq Track 2 Step 7" ;
			/*143*/if (i == 128) return verbose ? "Sequencer Track 2 Step 8"  : "Seq Track 2 Step 8" ;
			/*144*/if (i == 129) return verbose ? "Sequencer Track 2 Step 9"  : "Seq Track 2 Step 9" ;
			/*145*/if (i == 130) return verbose ? "Sequencer Track 2 Step 10" : "Seq Track 2 Step 10";
			/*146*/if (i == 131) return verbose ? "Sequencer Track 2 Step 11" : "Seq Track 2 Step 11";
			/*147*/if (i == 132) return verbose ? "Sequencer Track 2 Step 12" : "Seq Track 2 Step 12";
			/*148*/if (i == 133) return verbose ? "Sequencer Track 2 Step 13" : "Seq Track 2 Step 13";
			/*149*/if (i == 134) return verbose ? "Sequencer Track 2 Step 14" : "Seq Track 2 Step 14";
			/*150*/if (i == 135) return verbose ? "Sequencer Track 2 Step 15" : "Seq Track 2 Step 15";
			/*151*/if (i == 136) return verbose ? "Sequencer Track 2 Step 16" : "Seq Track 2 Step 16";
			/*152*/if (i == 137) return verbose ? "Sequencer Track 3 Step 1"  : "Seq Track 3 Step 1" ;
			/*153*/if (i == 138) return verbose ? "Sequencer Track 3 Step 2"  : "Seq Track 3 Step 2" ;
			/*154*/if (i == 139) return verbose ? "Sequencer Track 3 Step 3"  : "Seq Track 3 Step 3" ;
			/*155*/if (i == 140) return verbose ? "Sequencer Track 3 Step 4"  : "Seq Track 3 Step 4" ;
			/*156*/if (i == 141) return verbose ? "Sequencer Track 3 Step 5"  : "Seq Track 3 Step 5" ;
			/*157*/if (i == 142) return verbose ? "Sequencer Track 3 Step 6"  : "Seq Track 3 Step 6" ;
			/*158*/if (i == 143) return verbose ? "Sequencer Track 3 Step 7"  : "Seq Track 3 Step 7" ;
			/*159*/if (i == 144) return verbose ? "Sequencer Track 3 Step 8"  : "Seq Track 3 Step 8" ;
			/*160*/if (i == 145) return verbose ? "Sequencer Track 3 Step 9"  : "Seq Track 3 Step 9" ;
			/*161*/if (i == 146) return verbose ? "Sequencer Track 3 Step 10" : "Seq Track 3 Step 10";
			/*162*/if (i == 147) return verbose ? "Sequencer Track 3 Step 11" : "Seq Track 3 Step 11";
			/*163*/if (i == 148) return verbose ? "Sequencer Track 3 Step 12" : "Seq Track 3 Step 12";
			/*164*/if (i == 149) return verbose ? "Sequencer Track 3 Step 13" : "Seq Track 3 Step 13";
			/*165*/if (i == 150) return verbose ? "Sequencer Track 3 Step 14" : "Seq Track 3 Step 14";
			/*166*/if (i == 151) return verbose ? "Sequencer Track 3 Step 15" : "Seq Track 3 Step 15";
			/*167*/if (i == 152) return verbose ? "Sequencer Track 3 Step 16" : "Seq Track 3 Step 16";
			/*168*/if (i == 153) return verbose ? "Sequencer Track 4 Step 1"  : "Seq Track 4 Step 1" ;
			/*169*/if (i == 154) return verbose ? "Sequencer Track 4 Step 2"  : "Seq Track 4 Step 2" ;
			/*170*/if (i == 155) return verbose ? "Sequencer Track 4 Step 3"  : "Seq Track 4 Step 3" ;
			/*171*/if (i == 156) return verbose ? "Sequencer Track 4 Step 4"  : "Seq Track 4 Step 4" ;
			/*172*/if (i == 157) return verbose ? "Sequencer Track 4 Step 5"  : "Seq Track 4 Step 5" ;
			/*173*/if (i == 158) return verbose ? "Sequencer Track 4 Step 6"  : "Seq Track 4 Step 6" ;
			/*174*/if (i == 159) return verbose ? "Sequencer Track 4 Step 7"  : "Seq Track 4 Step 7" ;
			/*175*/if (i == 160) return verbose ? "Sequencer Track 4 Step 8"  : "Seq Track 4 Step 8" ;
			/*176*/if (i == 161) return verbose ? "Sequencer Track 4 Step 9"  : "Seq Track 4 Step 9" ;
			/*177*/if (i == 162) return verbose ? "Sequencer Track 4 Step 10" : "Seq Track 4 Step 10";
			/*178*/if (i == 163) return verbose ? "Sequencer Track 4 Step 11" : "Seq Track 4 Step 11";
			/*179*/if (i == 164) return verbose ? "Sequencer Track 4 Step 12" : "Seq Track 4 Step 12";
			/*180*/if (i == 165) return verbose ? "Sequencer Track 4 Step 13" : "Seq Track 4 Step 13";
			/*181*/if (i == 166) return verbose ? "Sequencer Track 4 Step 14" : "Seq Track 4 Step 14";
			/*182*/if (i == 167) return verbose ? "Sequencer Track 4 Step 15" : "Seq Track 4 Step 15";
			/*183*/if (i == 168) return verbose ? "Sequencer Track 4 Step 16" : "Seq Track 4 Step 16";
			// Parameters 184..199 are program name characters and cannot be assigned to a knob
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..127 to a program name character String
	String intToPgmNameChar(const int& i) const
	{
		if (i > -1 && i < 128)
		{
			if (i > 31)
			{
				String character;
				switch (i)
				{
				case 32: character = "Space"; break;
				case 92: character = "Yen Symbol"; break;
				case 126: character = "Right Arrow"; break;
				case 127: character = "Left Arrow"; break;
				default: character = std::string(1, (char)i); break;
				}
				character += " (" + (String)i + ")";
				return character;
			}
			else return "Control Character (" + (String)i + ")";
		}
		else return "range error";
	}
	 
	// Converts integers 0..24 to a master transpose range String ("-12".."+12")
	String intToMasterTranspose(const int& i, bool verbose) const
	{
		if (i > -1 && i < 25)
		{
			auto transposition = i - 12;
			if (transposition > -13 && transposition < -1)
				return verbose ? (String)transposition + " semitones" : (String)transposition;
			if (transposition == -1) return verbose ? "-1 semitone" : "-1";
			if (transposition == 0) return verbose ? "No Transpose" : "0";
			if (transposition == 1) return verbose ? "+1 semitone" : "+1";
			if (transposition > 1 && transposition < 13) 
				return verbose ? "+" + (String)transposition + " semitones" : "+" + (String)transposition;
			else return "invalid";
		}
		else return "range error";
	}

	// Converts integers 0..16 to a MIDI channel String (0 = "All Channels")
	String intToMIDIchannel(const int& i, bool verbose) const
	{
		if (i > -1 && i < 17)
		{
			if (i == 0) return verbose ? "All Channels" : "ALL";
			if (i > 0 && i < 17) return verbose ? "Channel " + (String)i : (String)i;
			else return "invalid";
		}
		else return "range error";
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueConverters)
};