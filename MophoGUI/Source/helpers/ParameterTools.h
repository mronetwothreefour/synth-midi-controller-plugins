#pragma once

#include <JuceHeader.h>

namespace MophoParameterIndex
{
	enum ParamIndex
	{
		osc1Pitch = 0, osc1FineTune, osc1Shape, osc1Glide, osc1KeyTrack, osc1SubLevel,
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
		nameChar9, nameChar10, nameChar11, nameChar12, nameChar13, nameChar14, nameChar15, nameChar16
	};
}


namespace MophoParameterType
{
	enum ParamType
	{
		range0to127 = 0,
		rangeNeg127toPos127,
		oscPitch,
		oscFineTune,
		oscShape
	};
}

namespace MophoParameterNRPN
{
	enum NRPN
	{
		osc1Pitch = 0, osc1FineTune, osc1Shape, osc1Glide, osc1KeyTrack,
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

static String intToPitchName(const int& i)
{
	auto pitchNum{ i % 12 };
	auto octaveNum{ i / 12 };
	String pitchName;
	switch (pitchNum)
	{
	case 0: pitchName = "C " + (String)octaveNum; break;
	case 1: pitchName = "C# " + (String)octaveNum; break;
	case 2: pitchName = "D " + (String)octaveNum; break;
	case 3: pitchName = "D# " + (String)octaveNum; break;
	case 4: pitchName = "E " + (String)octaveNum; break;
	case 5: pitchName = "F " + (String)octaveNum; break;
	case 6: pitchName = "F# " + (String)octaveNum; break;
	case 7: pitchName = "G " + (String)octaveNum; break;
	case 8: pitchName = "G# " + (String)octaveNum; break;
	case 9: pitchName = "A " + (String)octaveNum; break;
	case 10: pitchName = "A# " + (String)octaveNum; break;
	case 11: pitchName = "B " + (String)octaveNum; break;
	default: pitchName = "invalid"; break;
	}
	return pitchName;
}

namespace MophoParameter
{
	// Renders an integer value as a String in a format appropriate to the specified parameter type
	static String generateValueString(int paramType, const int& value, bool verbose)
	{
		switch (paramType)
		{
		case MophoParameterType::range0to127:
			if (value > -1 && value < 128)
			{
				return (String)value;
			}
			else return "range error";

		case MophoParameterType::rangeNeg127toPos127:
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

		default: return "error";
		}
	}
}
