#pragma once

#include <JuceHeader.h>

namespace MophoParameterIndex
{
	enum ParamIndex
	{
		osc1Pitch = 0, osc1Fine, osc1Shape, osc1Glide, osc1KeyTrack, osc1SubLevel,
		osc2Pitch, osc2Fine, osc2Shape, osc2Glide, osc2KeyTrack, osc2SubLevel,
		oscSync, glideMode, oscSlop, bendRange, notePriority,
		oscMix, noiseLevel, extInLevel,
		lpfFreq, lpfReso, lpfKeyAmount, lpfFMamount, lpfType, lpfEnvAmount, lpfVelAmount,
		lpfDelay, lpfAttack, lpfDecay, lpfSustain, lpfRelease,
		vcaLevel, vcaEnvAmount, vcaVelAmount, vcaDelay, vcaAttack, vcaDecay, vcaSustain, vcaRelease, pgmVolume,
		lfo1Freq, lfo1Shape, lfo1Amount, lfo1Destination, lfo1KeySync,
		lfo2Freq, lfo2Shape, lfo2Amount, lfo2Destination, lfo2KeySync,
		lfo3Freq, lfo3Shape, lfo3Amount, lfo3Destination, lfo3KeySync,
		lfo4Freq, lfo4Shape, lfo4Amount, lfo4Destination, lfo4KeySync,
		env3Destination, env3Amount, env3VelAmount,
		env3Delay, env3Attack, env3Decay, env3Sustain, env3Release, env3Repeat,
		mod1Source, mod1Amount, mod1Destination, mod2Source, mod2Amount, mod2Destination,
		mod3Source, mod3Amount, mod3Destination, mod4Source, mod4Amount, mod4Destination,
		modWheelAmount, modWheelDest, aftertouchAmount, aftertouchDest,
		breathAmount, breathDest, velocityAmount, velocityDest, footPedalAmount, footPedalDest,
		pushItPitch, pushItVelocity, pushItMode,
		clockTempo, clockDivide,
		arpegMode, arpegOnOff,
		sequencerTrig, sequencerOnOff, track1Dest, track2Dest, track3Dest, track4Dest,
		assignKnob1, assignKnob2, assignKnob3, assignKnob4,
		unassigned109, unassigned110, unassigned111, unassigned112, unassigned113,
		unassigned114, unassigned115, unassigned116, unassigned117, unassigned118, unassigned119,
		track1Step1, track1Step2, track1Step3, track1Step4, track1Step5, track1Step6, track1Step7, track1Step8,
		track1Step9, track1Step10, track1Step11, track1Step12, track1Step13, track1Step14, track1Step15, track1Step16,
		track2Step1, track2Step2, track2Step3, track2Step4, track2Step5, track2Step6, track2Step7, track2Step8,
		track2Step9, track2Step10, track2Step11, track2Step12, track2Step13, track2Step14, track2Step15, track2Step16,
		track3Step1, track3Step2, track3Step3, track3Step4, track3Step5, track3Step6, track3Step7, track3Step8,
		track3Step9, track3Step10, track3Step11, track3Step12, track3Step13, track3Step14, track3Step15, track3Step16,
		track4Step1, track4Step2, track4Step3, track4Step4, track4Step5, track4Step6, track4Step7, track4Step8, 
		track4Step9, track4Step10, track4Step11, track4Step12, track4Step13, track4Step14, track4Step15, track4Step16,
		nameChar1, nameChar2, nameChar3, nameChar4, nameChar5, nameChar6, nameChar7, nameChar8,
		nameChar9, nameChar10, nameChar11, nameChar12, nameChar13, nameChar14, nameChar15, nameChar16,
		masterTranspose = 384, masterFineTune, midiChannel, midiClock = 388,
		paramSend = 390, paramReceive, midiControllers = 394, stereoOut = 405, midiOut
	};
}


namespace MophoParameterNRPN
{
	enum NRPN
	{
		osc1Pitch = 0, osc1Fine, osc1Shape, osc1Glide, osc1KeyTrack,
		osc2Pitch, osc2Fine, osc2Shape, osc2Glide, osc2KeyTrack,
		oscSync, glideMode, oscSlop, oscMix, noiseLevel,
		lpfFreq, lpfReso, lpfKeyAmount, lpfFMamount, lpfType, lpfEnvAmount, lpfVelAmount,
		lpfDelay, lpfAttack, lpfDecay, lpfSustain, lpfRelease,
		vcaLevel, pgmVolume = 29, vcaEnvAmount, vcaVelAmount, vcaDelay, vcaAttack, vcaDecay, vcaSustain, vcaRelease,
		lfo1Freq, lfo1Shape, lfo1Amount, lfo1Destination, lfo1KeySync,
		lfo2Freq, lfo2Shape, lfo2Amount, lfo2Destination, lfo2KeySync,
		lfo3Freq, lfo3Shape, lfo3Amount, lfo3Destination, lfo3KeySync,
		lfo4Freq, lfo4Shape, lfo4Amount, lfo4Destination, lfo4KeySync,
		env3Destination, env3Amount, env3VelAmount,
		env3Delay, env3Attack, env3Decay, env3Sustain, env3Release,
		mod1Source, mod1Amount, mod1Destination, mod2Source, mod2Amount, mod2Destination,
		mod3Source, mod3Amount, mod3Destination, mod4Source, mod4Amount, mod4Destination,
		track1Dest, track2Dest, track3Dest, track4Dest,
		modWheelAmount, modWheelDest, aftertouchAmount, aftertouchDest,
		breathAmount, breathDest, velocityAmount, velocityDest, footPedalAmount, footPedalDest,
		clockTempo, clockDivide, bendRange, sequencerTrig, notePriority = 96,
		arpegMode, env3Repeat, arpegOnOff = 100, sequencerOnOff,
		assignKnob1 = 105, assignKnob2, assignKnob3, assignKnob4,
		pushItPitch = 111, pushItVelocity, pushItMode, osc1SubLevel, osc2SubLevel, extInLevel,
		track1Step1 = 120, track1Step2, track1Step3, track1Step4, track1Step5, track1Step6, track1Step7, track1Step8,
		track1Step9, track1Step10, track1Step11, track1Step12, track1Step13, track1Step14, track1Step15, track1Step16,
		track2Step1, track2Step2, track2Step3, track2Step4, track2Step5, track2Step6, track2Step7, track2Step8,
		track2Step9, track2Step10, track2Step11, track2Step12, track2Step13, track2Step14, track2Step15, track2Step16,
		track3Step1, track3Step2, track3Step3, track3Step4, track3Step5, track3Step6, track3Step7, track3Step8,
		track3Step9, track3Step10, track3Step11, track3Step12, track3Step13, track3Step14, track3Step15, track3Step16,
		track4Step1, track4Step2, track4Step3, track4Step4, track4Step5, track4Step6, track4Step7, track4Step8,
		track4Step9, track4Step10, track4Step11, track4Step12, track4Step13, track4Step14, track4Step15, track4Step16,
		nameChar1, nameChar2, nameChar3, nameChar4, nameChar5, nameChar6, nameChar7, nameChar8,
		nameChar9, nameChar10, nameChar11, nameChar12, nameChar13, nameChar14, nameChar15, nameChar16,
		masterTranspose = 384, masterFineTune, midiChannel, midiClock = 388, 
		paramSend = 390, paramReceive, midiControllers = 394, stereoOut = 405, midiOut
	};
}

namespace MophoParameterType
{
	enum ParamType
	{
		plainInteger = 0,
		modAmount,
		oscPitch,
		oscFineTune,
		oscShape,
		offOn,
		glideMode,
		pitchBendRange,
		notePriority,
		lpfFreq,
		lpfType,
		lfoFreq,
		lfoShape,
		modSource,
		modDestination,
		pushItMode,
		clockTempo,
		clockDivide,
		arpegMode,
		sequencerTrig,
		mophoParamList,
		stepValue,
		stepValueAsPitch,
		pgmNameChar,
		masterTranspose,
		midiChannel
	};
}

// A collection of knob sensitivity levels for various parameter types
namespace MophoKnobSensitivity
{
	enum KnobSensitivity
	{
		oscSlop = 75,
		bendRange = 80,
		oscPitch = 150,
		oscFineTune = 150,
		zeroTo127 = 175,
		lpfFreq = 200,
		lfoFreq = 200,
		modAmount = 275
	};
}

// Provides functionality for converting a Mopho parameter's
// raw integer value to a human-readable display String
struct MophoParameterValueConverter
{
	// Renders an integer value as a String in a format appropriate to the specified parameter type
	String convertIntToValueString(int paramType, const int& value, bool verbose) const
	{
		switch (paramType)
		{
		case MophoParameterType::modAmount:
			if (value > -1 && value < 255)
			{
				if (value < 128) return (String)(value - 127);
				if (value > 127 && value < 255) return "+" + (String)(value - 127);
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::oscPitch:
			if (value > -1 && value < 121)
			{
				String pitchName{ intToPitchName(value) };
				if (verbose)
					pitchName += " (MIDI Note " + String(value) + ")";
				return pitchName;
			}
			else if (value > 120 && value < 126) return "--";
			else return "range error";

		case MophoParameterType::oscFineTune:
			if (value > -1 && value < 101)
			{
				if (value < 49) return (String)(value - 50) + (verbose ? " cents" : "");
				if (value == 49) return verbose ? "-1 cent" : "-1";
				if (value == 50) return verbose ? "No Detune" : "0";
				if (value == 51) return verbose ? "+1 cent" : "+1";
				if (value > 51 && value < 101) return "+" + (String)(value - 50) + (verbose ? " cents" : "");
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::oscShape:
			if (value > -1 && value < 104)
			{
				if (value == 0) return "Oscillator Off";
				if (value == 1) return "Sawtooth";
				if (value == 2) return "Triangle";
				if (value == 3) return "Sawtooth/Triangle Mix";
				if (value > 3 && value < 104) return "Pulse (Width: " + String(value - 4) + ")";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::offOn:
			if (value > -1 && value < 2)
			{
				if (value == 0) return "Off";
				if (value == 1) return "On";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::glideMode:
			if (value > -1 && value < 4)
			{
				if (value == 0) return "Fixed Rate";
				if (value == 1) return "Fixed Rate Auto";
				if (value == 2) return "Fixed Time";
				if (value == 3) return "Fixed Time Auto";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::pitchBendRange:
			if (value > -1 && value < 13)
			{
				if (value == 0) return verbose ? "No Bend" : "0";
				if (value == 1) return verbose ? "+/-1 semitone" : "+/-1";
				if (value > 1 && value < 13) return verbose ? "+/-" + (String)value + " semitones" : "+/-" + (String)value;
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::notePriority:
			if (value > -1 && value < 6)
			{
				if (value == 0) return verbose ? "Low Note Has Priority" : "Low Note";
				if (value == 1) return verbose ? "Low Note Has Priority (Re-trigger)" : "Low Note (Re-trigger)";
				if (value == 2) return verbose ? "High Note Has Priority" : "High Note";
				if (value == 3) return verbose ? "High Note Has Priority (Re-trigger)" : "High Note (Re-trigger)";
				if (value == 4) return verbose ? "Last Note Hit Has Priority" : "Last Note";
				if (value == 5) return verbose ? "Last Note Hit Has Priority (Re-trigger)" : "Last Note (Re-trigger)";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::lpfFreq:
			if (value > -1 && value < 165)
			{
				String pitchString{ intToPitchName(value) };
				return verbose ? (String)value + " (Pitch Freq. " + pitchString + ")" : pitchString;
			}
			else return "range error";

		case MophoParameterType::lpfType:
			if (value > -1 && value < 2)
			{
				if (value == 0) return "2-Pole";
				if (value == 1) return "4-Pole";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::lfoFreq:
			if (value > -1 && value < 167)
			{
				if (value < 90) return verbose ? "Un-synced " + (String)(value) : (String)(value);
				if (value > 89 && value < 151)
				{
					String pitchString{ intToPitchName(value - 90) };
					return verbose ? (String)value + " (Pitch Freq. " + pitchString + ")" : pitchString;
				}
				if (value > 150 && value < 167)
				{
					switch (value)
					{
					case 151: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 32 steps" : "1:32";
					case 152: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 16 steps" : "1:16";
					case 153: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 8 steps" : "1:8";
					case 154: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 6 steps" : "1:6";
					case 155: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 4 steps" : "1:4";
					case 156: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 3 steps" : "1:3";
					case 157: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 2 steps" : "1:2";
					case 158: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1-1/2 steps" : "1:1.5";
					case 159: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1 step" : "1:1";
					case 160: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 2/3 step" : "3:2";
					case 161: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/2 step" : "2:1";
					case 162: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/3 step" : "3:1";
					case 163: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/4 step" : "4:1";
					case 164: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/6 step" : "6:1";
					case 165: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/8 step" : "8:1";
					case 166: return verbose ? "Synced " + String(value) + ": 1 cycle lasts 1/16 step" : "16:1";
					default: return "invalid"; break;
					}
				}
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::lfoShape:
			if (value > -1 && value < 5)
			{
				if (value == 0) return "Triangle";
				if (value == 1) return "Reverse Sawtooth";
				if (value == 2) return "Sawtooth";
				if (value == 3) return "Square Wave";
				if (value == 4) return "Random";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::modSource:
			if (value > -1 && value < 23)
			{
				if (value == 0 ) return "Off";
				if (value == 1 ) return "Sequencer Track 1";
				if (value == 2 ) return "Sequencer Track 2";
				if (value == 3 ) return "Sequencer Track 3";
				if (value == 4 ) return "Sequencer Track 4";
				if (value == 5 ) return "LFO 1";
				if (value == 6 ) return "LFO 2";
				if (value == 7 ) return "LFO 3";
				if (value == 8 ) return "LFO 4";
				if (value == 9 ) return "LPF Envelope";
				if (value == 10) return "VCA Envelope";
				if (value == 11) return "Envelope 3";
				if (value == 12) return "Pitch Bend";
				if (value == 13) return "Mod Wheel";
				if (value == 14) return "Pressure (Aftertouch)";
				if (value == 15) return "MIDI Breath";
				if (value == 16) return "MIDI Foot Pedal";
				if (value == 17) return "MIDI Expression";
				if (value == 18) return "Velocity";
				if (value == 19) return "Note Number";
				if (value == 20) return "Noise";
				if (value == 21) return "Audio In Env. Follower";
				if (value == 22) return "Audio In Peak Hold";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::modDestination:
			if (value > -1 && value < 47)
			{
				if (value == 0 ) return "Off";
				if (value == 1 ) return "Oscillator 1 Pitch";
				if (value == 2 ) return "Oscillator 2 Pitch";
				if (value == 3 ) return "Oscillator 1 & 2 Pitch";
				if (value == 4 ) return "Oscillator Mix";
				if (value == 5 ) return "Noise Level";
				if (value == 6 ) return "Oscillator 1 Pulse Width";
				if (value == 7 ) return "Oscillator 2 Pulse Width";
				if (value == 8 ) return "Oscillator 1 & 2 PW";
				if (value == 9 ) return "LPF Cutoff Frequency";
				if (value == 10) return "LPF Resonance";
				if (value == 11) return "LPF FM Amount";
				if (value == 12) return "VCA Level";
				if (value == 13) return "Output Panning";
				if (value == 14) return "LFO 1 Frequency";
				if (value == 15) return "LFO 2 Frequency";
				if (value == 16) return "LFO 3 Frequency";
				if (value == 17) return "LFO 4 Frequency";
				if (value == 18) return "All LFO Frequencies";
				if (value == 19) return "LFO 1 Amount";
				if (value == 20) return "LFO 2 Amount";
				if (value == 21) return "LFO 3 Amount";
				if (value == 22) return "LFO 4 Amount";
				if (value == 23) return "All LFO Amounts";
				if (value == 24) return "LPF Envelope Amount";
				if (value == 25) return "VCA Envelope Amount";
				if (value == 26) return "Envelope 3 Amount";
				if (value == 27) return "All Envelope Amounts";
				if (value == 28) return "LPF Envelope Attack";
				if (value == 29) return "VCA Envelope Attack";
				if (value == 30) return "Envelope 3 Attack";
				if (value == 31) return "All Envelope Attacks";
				if (value == 32) return "LPF Envelope Decay";
				if (value == 33) return "VCA Envelope Decay";
				if (value == 34) return "Envelope 3 Decay";
				if (value == 35) return "All Envelope Decays";
				if (value == 36) return "LPF Envelope Release";
				if (value == 37) return "VCA Envelope Release";
				if (value == 38) return "Envelope 3 Release";
				if (value == 39) return "All Envelope Releases";
				if (value == 40) return "Modulator 1 Amount";
				if (value == 41) return "Modulator 2 Amount";
				if (value == 42) return "Modulator 3 Amount";
				if (value == 43) return "Modulator 4 Amount";
				if (value == 44) return "External Audio In Level";
				if (value == 45) return "Sub-Osc 1 Level";
				if (value == 46) return "Sub-Osc 2 Level";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::pushItMode:
			if (value > -1 && value < 3)
			{
				if (value == 0) return "Normal";
				if (value == 1) return "Toggle";
				if (value == 2) return "Audio In";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::clockTempo:
			if (value > -1 && value < 221)
			{
				return (String)(value + 30) + (verbose ? " BPM" : "");
			}
			else return "range error";

		case MophoParameterType::clockDivide:
			if (value > -1 && value < 13)
			{
				if (value == 0 ) return verbose ? "Half Note (BPM / 2)" : "Half Note";
				if (value == 1 ) return verbose ? "Quarter Note (BPM x 1)" : "Quarter Note";
				if (value == 2 ) return verbose ? "8th Note (BPM x 2)" : "8th Note";
				if (value == 3 ) return verbose ? "8th Note, 1/2 Swing (BPM x 2)" : "8th Note, 1/2 Swing";
				if (value == 4 ) return verbose ? "8th Note, Full Swing (BPM x 2)" : "8th Note, Full Swing";
				if (value == 5 ) return verbose ? "8th Note Triplets (BPM x 3)" : "8th Note Triplets";
				if (value == 6 ) return verbose ? "16th Note (BPM x 4)" : "16th Note";
				if (value == 7 ) return verbose ? "16th Note, 1/2 Swing (BPM x 4)" : "16th Note, 1/2 Swing";
				if (value == 8 ) return verbose ? "16th Note, Full Swing (BPM x 4)" : "16th Note, Full Swing";
				if (value == 9 ) return verbose ? "16th Note Triplets (BPM x 6)" : "16th Note Triplets";
				if (value == 10) return verbose ? "32nd Note (BPM x 8)" : "32nd Note";
				if (value == 11) return verbose ? "32nd Note Triplets (BPM x 12)" : "32nd Note Triplets";
				if (value == 12) return verbose ? "64th Note Triplets (BPM x 24)" : "64th Note Triplets";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::arpegMode:
			if (value > -1 && value < 4)
			{
				if (value == 0) return "Up";
				if (value == 1) return "Down";
				if (value == 2) return "Up & Down";
				if (value == 3) return "Assign";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::sequencerTrig:
			if (value > -1 && value < 6)
			{
				if (value == 0) return "Normal";
				if (value == 1) return "Normal, No Reset";
				if (value == 2) return "No Gate";
				if (value == 3) return "No Gate, No Reset";
				if (value == 4) return "Key Step";
				if (value == 5) return "Audio Input";
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::mophoParamList:
			if (value > -1 && value < 169)
			{
				/*0  */if (value == 0  ) return "Oscillator 1 Pitch";
				/*1  */if (value == 1  ) return "Oscillator 1 Fine Tune";
				/*2  */if (value == 2  ) return "Oscillator 1 Wave Shape";
				/*3  */if (value == 3  ) return "Oscillator 1 Glide Rate";
				/*4  */if (value == 4  ) return "Oscillator 1 Key Track";
				/*5  */if (value == 5  ) return "Sub-Oscillator 1 Level";
				/*6  */if (value == 6  ) return "Oscillator 2 Pitch";
				/*7  */if (value == 7  ) return "Oscillator 2 Fine Tune";
				/*8  */if (value == 8  ) return "Oscillator 2 Wave Shape";
				/*9  */if (value == 9  ) return "Oscillator 2 Glide Rate";
				/*10 */if (value == 10 ) return "Oscillator 2 Key Track";
				/*11 */if (value == 11 ) return "Sub-Oscillator 2 Level";
				/*12 */if (value == 12 ) return "Hard Sync Oscillators";
				/*13 */if (value == 13 ) return "Glide Mode";
				/*14 */if (value == 14 ) return "Oscillator Slop";
				/*15 */if (value == 15 ) return "Pitch Bend Range";
				/*16 */if (value == 16 ) return "Keyed Note Priority";
				/*17 */if (value == 17 ) return "Oscillators 1 & 2 Mix";
				/*18 */if (value == 18 ) return "Noise Level";
				/*19 */if (value == 19 ) return verbose ? "External Audio Input Level" : "External Audio In Level";
				/*20 */if (value == 20 ) return "LPF Cutoff Frequency";
				/*21 */if (value == 21 ) return "LPF Resonance";				
				/*22 */if (value == 22 ) return "LPF Keyboard Amount";			
				/*23 */if (value == 23 ) return "LPF Freq. Mod. On/Off";	
				/*24 */if (value == 24 ) return "LPF 2- or 4-Pole Select";					
				/*25 */if (value == 25 ) return "LPF Envelope Amount";
				/*26 */if (value == 26 ) return verbose ? "LPF Envelope Velocity Amount" : "LPF Env Vel Amt";
				/*27 */if (value == 27 ) return "LPF Envelope Delay";
				/*28 */if (value == 28 ) return "LPF Envelope Attack";
				/*29 */if (value == 29 ) return "LPF Envelope Decay";
				/*30 */if (value == 30 ) return "LPF Envelope Sustain";
				/*31 */if (value == 31 ) return "LPF Envelope Release";
				/*32 */if (value == 32 ) return "VCA Initial Level";
				/*33 */if (value == 33 ) return "VCA Envelope Amount";
				/*34 */if (value == 34 ) return verbose ? "VCA Envelope Velocity Amount" : "VCA Env Vel Amnt";
				/*35 */if (value == 35 ) return "VCA Envelope Delay";
				/*36 */if (value == 36 ) return "VCA Envelope Attack";
				/*37 */if (value == 37 ) return "VCA Envelope Decay";
				/*38 */if (value == 38 ) return "VCA Envelope Sustain";
				/*39 */if (value == 39 ) return "VCA Envelope Release";
				/*40 */if (value == 40 ) return "Voice Volume";
				/*41 */if (value == 41 ) return "LFO 1 Frequency";
				/*42 */if (value == 42 ) return "LFO 1 Wave Shape";
				/*43 */if (value == 43 ) return "LFO 1 Amount";
				/*44 */if (value == 44 ) return verbose ? "LFO 1 Modulation Destination" : "LFO 1 Mod Destination";
				/*45 */if (value == 45 ) return "LFO 1 Key Sync";
				/*46 */if (value == 46 ) return "LFO 2 Frequency";
				/*47 */if (value == 47 ) return "LFO 2 Wave Shape";
				/*48 */if (value == 48 ) return "LFO 2 Amount";
				/*49 */if (value == 49 ) return verbose ? "LFO 2 Modulation Destination" : "LFO 2 Mod Destination";
				/*50 */if (value == 50 ) return "LFO 2 Key Sync";
				/*51 */if (value == 51 ) return "LFO 3 Frequency";
				/*52 */if (value == 52 ) return "LFO 3 Wave Shape";
				/*53 */if (value == 53 ) return "LFO 3 Amount";
				/*54 */if (value == 54 ) return verbose ? "LFO 3 Modulation Destination" : "LFO 3 Mod Destination";
				/*55 */if (value == 55 ) return "LFO 3 Key Sync";
				/*56 */if (value == 56 ) return "LFO 4 Frequency";
				/*57 */if (value == 57 ) return "LFO 4 Wave Shape";
				/*58 */if (value == 58 ) return "LFO 4 Amount";
				/*59 */if (value == 59 ) return verbose ? "LFO 4 Modulation Destination" : "LFO 4 Mod Destination";
				/*60 */if (value == 60 ) return "LFO 4 Key Sync";
				/*61 */if (value == 61 ) return verbose ? "Envelope 3 Mod Destination" : "Env 3 Mod Destination";
				/*62 */if (value == 62 ) return "Envelope 3 Amount";
				/*63 */if (value == 63 ) return verbose ? "Envelope 3 Velocity Amount" : "Env 3 Velocity Amount";
				/*64 */if (value == 64 ) return "Envelope 3 Delay";
				/*65 */if (value == 65 ) return "Envelope 3 Attack";
				/*66 */if (value == 66 ) return "Envelope 3 Decay";
				/*67 */if (value == 67 ) return "Envelope 3 Sustain";
				/*68 */if (value == 68 ) return "Envelope 3 Release";
				/*69 */if (value == 69 ) return "Envelope 3 Repeat"	;
				/*70 */if (value == 70 ) return "Modulator 1 Source";
				/*71 */if (value == 71 ) return "Modulator 1 Amount";
				/*72 */if (value == 72 ) return "Modulator 1 Destination";
				/*73 */if (value == 73 ) return "Modulator 2 Source";
				/*74 */if (value == 74 ) return "Modulator 2 Amount";
				/*75 */if (value == 75 ) return "Modulator 2 Destination";
				/*76 */if (value == 76 ) return "Modulator 3 Source";
				/*77 */if (value == 77 ) return "Modulator 3 Amount";
				/*78 */if (value == 78 ) return "Modulator 3 Destination";
				/*79 */if (value == 79 ) return "Modulator 4 Source";
				/*80 */if (value == 80 ) return "Modulator 4 Amount";
				/*81 */if (value == 81 ) return "Modulator 4 Destination";
				/*82 */if (value == 82 ) return verbose ? "Modulation Wheel Amount"	: "Modulation Wheel Amt";
				/*83 */if (value == 83 ) return verbose ? "Modulation Wheel Destination" : "Modulation Wheel Dest";
				/*84 */if (value == 84 ) return "Aftertouch Amount";
				/*85 */if (value == 85 ) return "Aftertouch Destination";
				/*86 */if (value == 86 ) return verbose ? "Breath Controller Amount" : "Breath Amount";
				/*87 */if (value == 87 ) return verbose ? "Breath Controller Destination" : "Breath Destination";
				/*88 */if (value == 88 ) return "Velocity Amount";
				/*89 */if (value == 89 ) return "Velocity Destination";
				/*90 */if (value == 90 ) return "Foot Pedal Amount";
				/*91 */if (value == 91 ) return "Foot Pedal Destination";
				/*92 */if (value == 92 ) return "Push It! Switch Pitch";
				/*93 */if (value == 93 ) return "Push It! Switch Velocity";
				/*94 */if (value == 94 ) return "Push It! Switch Mode";
				/*95 */if (value == 95 ) return "Clock Tempo (BPM)";
				/*96 */if (value == 96 ) return "Clock Divide";
				/*97 */if (value == 97 ) return "Arpeggiator Mode";
				/*98 */if (value == 98 ) return "Arpeggiator On/Off";
				/*99 */if (value == 99 ) return "Sequencer Trigger Mode";
				/*100*/if (value == 100) return "Sequencer On/Off";
				/*101*/if (value == 101) return verbose ? "Sequencer Track 1 Destination" : "Sequencer Track 1 Dest";
				/*102*/if (value == 102) return verbose ? "Sequencer Track 2 Destination" : "Sequencer Track 2 Dest";
				/*103*/if (value == 103) return verbose ? "Sequencer Track 3 Destination" : "Sequencer Track 3 Dest";
				/*104*/if (value == 104) return verbose ? "Sequencer Track 4 Destination" : "Sequencer Track 4 Dest";
				// Parameters 105..108 used for assigning parameters to the
				// hardware knobs and parameters 109..119 are unassigned.
				// These parameters are left out and the parameter number discrepancy
				// is handled by the processor in parameterValueChanged()
				/*120*/if (value == 105) return verbose ? "Sequencer Track 1 Step 1"  : "Seq Track 1 Step 1" ;
				/*121*/if (value == 106) return verbose ? "Sequencer Track 1 Step 2"  : "Seq Track 1 Step 2" ;
				/*122*/if (value == 107) return verbose ? "Sequencer Track 1 Step 3"  : "Seq Track 1 Step 3" ;
				/*123*/if (value == 108) return verbose ? "Sequencer Track 1 Step 4"  : "Seq Track 1 Step 4" ;
				/*124*/if (value == 109) return verbose ? "Sequencer Track 1 Step 5"  : "Seq Track 1 Step 5" ;
				/*125*/if (value == 110) return verbose ? "Sequencer Track 1 Step 6"  : "Seq Track 1 Step 6" ;
				/*126*/if (value == 111) return verbose ? "Sequencer Track 1 Step 7"  : "Seq Track 1 Step 7" ;
				/*127*/if (value == 112) return verbose ? "Sequencer Track 1 Step 8"  : "Seq Track 1 Step 8" ;
				/*128*/if (value == 113) return verbose ? "Sequencer Track 1 Step 9"  : "Seq Track 1 Step 9" ;
				/*129*/if (value == 114) return verbose ? "Sequencer Track 1 Step 10" : "Seq Track 1 Step 10";
				/*130*/if (value == 115) return verbose ? "Sequencer Track 1 Step 11" : "Seq Track 1 Step 11";
				/*131*/if (value == 116) return verbose ? "Sequencer Track 1 Step 12" : "Seq Track 1 Step 12";
				/*132*/if (value == 117) return verbose ? "Sequencer Track 1 Step 13" : "Seq Track 1 Step 13";
				/*133*/if (value == 118) return verbose ? "Sequencer Track 1 Step 14" : "Seq Track 1 Step 14";
				/*134*/if (value == 119) return verbose ? "Sequencer Track 1 Step 15" : "Seq Track 1 Step 15";
				/*135*/if (value == 120) return verbose ? "Sequencer Track 1 Step 16" : "Seq Track 1 Step 16";
				/*136*/if (value == 121) return verbose ? "Sequencer Track 2 Step 1"  : "Seq Track 2 Step 1" ;
				/*137*/if (value == 122) return verbose ? "Sequencer Track 2 Step 2"  : "Seq Track 2 Step 2" ;
				/*138*/if (value == 123) return verbose ? "Sequencer Track 2 Step 3"  : "Seq Track 2 Step 3" ;
				/*139*/if (value == 124) return verbose ? "Sequencer Track 2 Step 4"  : "Seq Track 2 Step 4" ;
				/*140*/if (value == 125) return verbose ? "Sequencer Track 2 Step 5"  : "Seq Track 2 Step 5" ;
				/*141*/if (value == 126) return verbose ? "Sequencer Track 2 Step 6"  : "Seq Track 2 Step 6" ;
				/*142*/if (value == 127) return verbose ? "Sequencer Track 2 Step 7"  : "Seq Track 2 Step 7" ;
				/*143*/if (value == 128) return verbose ? "Sequencer Track 2 Step 8"  : "Seq Track 2 Step 8" ;
				/*144*/if (value == 129) return verbose ? "Sequencer Track 2 Step 9"  : "Seq Track 2 Step 9" ;
				/*145*/if (value == 130) return verbose ? "Sequencer Track 2 Step 10" : "Seq Track 2 Step 10";
				/*146*/if (value == 131) return verbose ? "Sequencer Track 2 Step 11" : "Seq Track 2 Step 11";
				/*147*/if (value == 132) return verbose ? "Sequencer Track 2 Step 12" : "Seq Track 2 Step 12";
				/*148*/if (value == 133) return verbose ? "Sequencer Track 2 Step 13" : "Seq Track 2 Step 13";
				/*149*/if (value == 134) return verbose ? "Sequencer Track 2 Step 14" : "Seq Track 2 Step 14";
				/*150*/if (value == 135) return verbose ? "Sequencer Track 2 Step 15" : "Seq Track 2 Step 15";
				/*151*/if (value == 136) return verbose ? "Sequencer Track 2 Step 16" : "Seq Track 2 Step 16";
				/*152*/if (value == 137) return verbose ? "Sequencer Track 3 Step 1"  : "Seq Track 3 Step 1" ;
				/*153*/if (value == 138) return verbose ? "Sequencer Track 3 Step 2"  : "Seq Track 3 Step 2" ;
				/*154*/if (value == 139) return verbose ? "Sequencer Track 3 Step 3"  : "Seq Track 3 Step 3" ;
				/*155*/if (value == 140) return verbose ? "Sequencer Track 3 Step 4"  : "Seq Track 3 Step 4" ;
				/*156*/if (value == 141) return verbose ? "Sequencer Track 3 Step 5"  : "Seq Track 3 Step 5" ;
				/*157*/if (value == 142) return verbose ? "Sequencer Track 3 Step 6"  : "Seq Track 3 Step 6" ;
				/*158*/if (value == 143) return verbose ? "Sequencer Track 3 Step 7"  : "Seq Track 3 Step 7" ;
				/*159*/if (value == 144) return verbose ? "Sequencer Track 3 Step 8"  : "Seq Track 3 Step 8" ;
				/*160*/if (value == 145) return verbose ? "Sequencer Track 3 Step 9"  : "Seq Track 3 Step 9" ;
				/*161*/if (value == 146) return verbose ? "Sequencer Track 3 Step 10" : "Seq Track 3 Step 10";
				/*162*/if (value == 147) return verbose ? "Sequencer Track 3 Step 11" : "Seq Track 3 Step 11";
				/*163*/if (value == 148) return verbose ? "Sequencer Track 3 Step 12" : "Seq Track 3 Step 12";
				/*164*/if (value == 149) return verbose ? "Sequencer Track 3 Step 13" : "Seq Track 3 Step 13";
				/*165*/if (value == 150) return verbose ? "Sequencer Track 3 Step 14" : "Seq Track 3 Step 14";
				/*166*/if (value == 151) return verbose ? "Sequencer Track 3 Step 15" : "Seq Track 3 Step 15";
				/*167*/if (value == 152) return verbose ? "Sequencer Track 3 Step 16" : "Seq Track 3 Step 16";
				/*168*/if (value == 153) return verbose ? "Sequencer Track 4 Step 1"  : "Seq Track 4 Step 1" ;
				/*169*/if (value == 154) return verbose ? "Sequencer Track 4 Step 2"  : "Seq Track 4 Step 2" ;
				/*170*/if (value == 155) return verbose ? "Sequencer Track 4 Step 3"  : "Seq Track 4 Step 3" ;
				/*171*/if (value == 156) return verbose ? "Sequencer Track 4 Step 4"  : "Seq Track 4 Step 4" ;
				/*172*/if (value == 157) return verbose ? "Sequencer Track 4 Step 5"  : "Seq Track 4 Step 5" ;
				/*173*/if (value == 158) return verbose ? "Sequencer Track 4 Step 6"  : "Seq Track 4 Step 6" ;
				/*174*/if (value == 159) return verbose ? "Sequencer Track 4 Step 7"  : "Seq Track 4 Step 7" ;
				/*175*/if (value == 160) return verbose ? "Sequencer Track 4 Step 8"  : "Seq Track 4 Step 8" ;
				/*176*/if (value == 161) return verbose ? "Sequencer Track 4 Step 9"  : "Seq Track 4 Step 9" ;
				/*177*/if (value == 162) return verbose ? "Sequencer Track 4 Step 10" : "Seq Track 4 Step 10";
				/*178*/if (value == 163) return verbose ? "Sequencer Track 4 Step 11" : "Seq Track 4 Step 11";
				/*179*/if (value == 164) return verbose ? "Sequencer Track 4 Step 12" : "Seq Track 4 Step 12";
				/*180*/if (value == 165) return verbose ? "Sequencer Track 4 Step 13" : "Seq Track 4 Step 13";
				/*181*/if (value == 166) return verbose ? "Sequencer Track 4 Step 14" : "Seq Track 4 Step 14";
				/*182*/if (value == 167) return verbose ? "Sequencer Track 4 Step 15" : "Seq Track 4 Step 15";
				/*183*/if (value == 168) return verbose ? "Sequencer Track 4 Step 16" : "Seq Track 4 Step 16";
				// Parameters 184..199 are program name characters and cannot be assigned to a knob
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::stepValue:
			if (value > -1 && value < 128)
			{
				if (value < 126) return (String)(value);
				else if (value == 126) return (String)("Reset Sequence");
				else if (value == 127) return (String)("Rest");
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::stepValueAsPitch:
			if (value > -1 && value < 128)
			{
				if (value < 126)
				{
					auto pitchNum{ value % 24 };
					auto octaveNum{ value / 24 };
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
				else if (value == 126) return (String)("Reset Sequence");
				else if (value == 127) return (String)("Rest");
				else return "invalid";
			}
			else return "range error";

		case MophoParameterType::pgmNameChar:
			if (value > -1 && value < 128)
			{
				if (value > 31)
				{
					String character;
					switch (value)
					{
					case 32: character = "Space"; break;
					case 92: character = "Yen Symbol"; break;
					case 126: character = "Right Arrow"; break;
					case 127: character = "Left Arrow"; break;
					default: character = std::string(1, (char)value); break;
					}
					character += " (" + (String)value + ")";
					return character;
				}
				else return "Control Character (" + (String)value + ")";
			}
			else return "range error";

		case MophoParameterType::masterTranspose:
			if (value > -1 && value < 25)
			{
				auto transposition = value - 12;
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

		case MophoParameterType::midiChannel:
			if (value > -1 && value < 17)
			{
				if (value == 0) return verbose ? "All Channels" : "ALL";
				if (value > 0 && value < 17) return verbose ? "Channel " + (String)value : (String)value;
				else return "invalid";
			}
			else return "range error";

		default: return "error";
		}
	}

private:
	static String intToPitchName(const int& i)
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

