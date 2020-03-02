#pragma once

#include <JuceHeader.h>

struct Choices
{
public:
	// Presents MIDI note numbers as pitch name & octave number combinations
	// (e.g. note number 27 is presented as "D#2")
	StringArray pitchNames;

	// 0 = "-50 cents"; 50 = "Centered"; 100 = "+50 cents"
	StringArray fineTune;
	
	// 0 = "Off"; 1 = "Sawtooth"; 2 = "Triangle"; 3 = "Saw/Tri Mix";
	// 4..103 = "Pulse Width 0..99"
	StringArray oscShape;

	// 0 = "Off"; 1 = "On"
	StringArray offOn;

	StringArray glideMode;

	StringArray pitchBendRange;

	StringArray notePriority;

	// Presents integer values as pitch name & octave number combinations
	// (e.g. 27 is presented as "D#2")
	StringArray lpfFreq;

	// 0 = "2-Pole"; 1 = "4-Pole"
	StringArray lpfType;

	// 0 = "-127"; 254 = "+127"
	StringArray modAmount;

	// 0..89 = "Unsynced 0..89"
	// 90..150 = "Pitched Frequency C0..C5"
	// 151..156 = Sync to step sequencer
	StringArray lfoFreq;

	// 0 = "Triangle"; 1 = "Reverse Sawtooth";
	// 2 = "Sawtooth" 3 = "Square"; 4 = "Random"
	StringArray lfoShape;

	StringArray modDestination;

	Choices()
	{
		// initialize pitchNames
		for (int i = 0; i != 121; ++i)
		{
			auto noteNum{ i % 12 };
			auto octaveNum{ i / 12 };
			switch (noteNum)
			{
			case 0 : pitchNames.add("C"  + (String)octaveNum); break;
			case 1 : pitchNames.add("C#" + (String)octaveNum); break;
			case 2 : pitchNames.add("D"  + (String)octaveNum); break;
			case 3 : pitchNames.add("D#" + (String)octaveNum); break;
			case 4 : pitchNames.add("E"  + (String)octaveNum); break;
			case 5 : pitchNames.add("F"  + (String)octaveNum); break;
			case 6 : pitchNames.add("F#" + (String)octaveNum); break;
			case 7 : pitchNames.add("G"  + (String)octaveNum); break;
			case 8 : pitchNames.add("G#" + (String)octaveNum); break;
			case 9 : pitchNames.add("A"  + (String)octaveNum); break;
			case 10: pitchNames.add("A#" + (String)octaveNum); break;
			case 11: pitchNames.add("B"  + (String)octaveNum); break;
			default: break;
			}
		}

		// initialize fineTune
		for (int i = 0; i != 49; ++i)
		{
			fineTune.add((String)(i - 50) + " cents");
		}
		fineTune.add("-1 cent");
		fineTune.add("Centered");
		fineTune.add("+1 cent");
		for (int i = 52; i != 101; ++i)
		{
			fineTune.add("+" + (String)(i - 50) + " cents");
		}

		// initialize oscShape
		oscShape.add("Off");
		oscShape.add("Sawtooth");
		oscShape.add("Triangle");
		oscShape.add("Saw/Tri Mix");
		for (int i = 0; i != 100; ++i)
		{
			oscShape.add("Pulse Width " + (String)i);
		}

		// initialize offOn
		offOn.add("Off");
		offOn.add("On");

		// initialize glideMode
		glideMode.add("Fixed Rate");
		glideMode.add("Fixed Rate Auto");
		glideMode.add("Fixed Time");
		glideMode.add("Fixed Time Auto");

		// initialize pitchBendRange
		pitchBendRange.add("Off");
		pitchBendRange.add("+/-1 semitone");
		for (int i = 2; i != 13; ++i)
		{
			pitchBendRange.add("+/-" + (String)i + " semitones");
		}

		// initialize notePriority
		notePriority.add("Low Note");
		notePriority.add("Low Note (Re-trigger)");
		notePriority.add("High Note");
		notePriority.add("High Note (Re-trigger)");
		notePriority.add("Last Note Hit");
		notePriority.add("Last Note Hit (Re-trigger)");

		// initialize lpfFreq
		for (int i = 0; i != 165; ++i)
		{
			auto noteNum{ i % 12 };
			auto octaveNum{ i / 12 };
			switch (noteNum)
			{
			case 0 : lpfFreq.add("C"  + (String)octaveNum); break;
			case 1 : lpfFreq.add("C#" + (String)octaveNum); break;
			case 2 : lpfFreq.add("D"  + (String)octaveNum); break;
			case 3 : lpfFreq.add("D#" + (String)octaveNum); break;
			case 4 : lpfFreq.add("E"  + (String)octaveNum); break;
			case 5 : lpfFreq.add("F"  + (String)octaveNum); break;
			case 6 : lpfFreq.add("F#" + (String)octaveNum); break;
			case 7 : lpfFreq.add("G"  + (String)octaveNum); break;
			case 8 : lpfFreq.add("G#" + (String)octaveNum); break;
			case 9 : lpfFreq.add("A"  + (String)octaveNum); break;
			case 10: lpfFreq.add("A#" + (String)octaveNum); break;
			case 11: lpfFreq.add("B"  + (String)octaveNum); break;
			default: break;
			}
		}

		// initialize lpfType
		lpfType.add("2-Pole");
		lpfType.add("4-Pole");

		// initialize modAmnt
		for (int i = 0; i != 255; ++i)
		{
			if (i < 128) modAmount.add((String)(i - 127));
			else modAmount.add("+" + (String)(i - 127));
		}

		// initialize lfoFreq
		for (int i = 0; i != 151; ++i)
		{
			if (i < 90) lfoFreq.add("Un-synced " + (String)i);
			if (i > 89)
			{
				auto noteNum{ (i - 90) % 12 };
				auto octaveNum{ (i - 90) / 12 };
				switch (noteNum)
				{
				case 0 : lfoFreq.add("Pitch Freq. C"  + (String)octaveNum); break;
				case 1 : lfoFreq.add("Pitch Freq. C#" + (String)octaveNum); break;
				case 2 : lfoFreq.add("Pitch Freq. D"  + (String)octaveNum); break;
				case 3 : lfoFreq.add("Pitch Freq. D#" + (String)octaveNum); break;
				case 4 : lfoFreq.add("Pitch Freq. E"  + (String)octaveNum); break;
				case 5 : lfoFreq.add("Pitch Freq. F"  + (String)octaveNum); break;
				case 6 : lfoFreq.add("Pitch Freq. F#" + (String)octaveNum); break;
				case 7 : lfoFreq.add("Pitch Freq. G"  + (String)octaveNum); break;
				case 8 : lfoFreq.add("Pitch Freq. G#" + (String)octaveNum); break;
				case 9 : lfoFreq.add("Pitch Freq. A"  + (String)octaveNum); break;
				case 10: lfoFreq.add("Pitch Freq. A#" + (String)octaveNum); break;
				case 11: lfoFreq.add("Pitch Freq. B"  + (String)octaveNum); break;
				default: break;
				}
			}
		}
		lfoFreq.add("Sync: 32 Steps");
		lfoFreq.add("Sync: 16 Steps");
		lfoFreq.add("Sync: 8 Steps");
		lfoFreq.add("Sync: 6 Steps");
		lfoFreq.add("Sync: 4 Steps");
		lfoFreq.add("Sync: 3 Steps");
		lfoFreq.add("Sync: 2 Steps");
		lfoFreq.add("Sync: 1-1/2 Steps");
		lfoFreq.add("Sync: 1 Step");
		lfoFreq.add("Sync: 2/3 Step");
		lfoFreq.add("Sync: 1/2 Step");
		lfoFreq.add("Sync: 1/3 Step");
		lfoFreq.add("Sync: 1/4 Step");
		lfoFreq.add("Sync: 1/6 Step");
		lfoFreq.add("Sync: 1/8 Step");
		lfoFreq.add("Sync: 1/16 Step");

		// initialize lfoShape
		lfoShape.add("Triangle");
		lfoShape.add("Reverse Sawtooth");
		lfoShape.add("Sawtooth");
		lfoShape.add("Square");
		lfoShape.add("Random");

		// initiaiize modDestination
		/*0 */modDestination.add("Off");
		/*1 */modDestination.add("Oscillator 1 Pitch");
		/*2 */modDestination.add("Oscillator 2 Pitch");
		/*3 */modDestination.add("Oscillator 1 & 2 Pitch");
		/*4 */modDestination.add("Oscillator Mix");
		/*5 */modDestination.add("Noise Level");
		/*6 */modDestination.add("Osc. 1 Pulse Width");
		/*7 */modDestination.add("Osc. 2 Pulse Width");
		/*8 */modDestination.add("Osc. 1 & 2 Pulse Width");
		/*9 */modDestination.add("LPF Cutoff Frequency");
		/*10*/modDestination.add("LPF Resonance");
		/*11*/modDestination.add("LPF FM Amount");
		/*12*/modDestination.add("VCA Level");
		/*13*/modDestination.add("Output Panning");
		/*14*/modDestination.add("LFO 1 Frequency");
		/*15*/modDestination.add("LFO 2 Frequency");
		/*16*/modDestination.add("LFO 3 Frequency");
		/*17*/modDestination.add("LFO 4 Frequency");
		/*18*/modDestination.add("All LFO Frequencies");
		/*19*/modDestination.add("LFO 1 Amount");
		/*20*/modDestination.add("LFO 2 Amount");
		/*21*/modDestination.add("LFO 3 Amount");
		/*22*/modDestination.add("LFO 4 Amount");
		/*23*/modDestination.add("All LFO Amounts");
		/*24*/modDestination.add("LPF Envelope Amount");
		/*25*/modDestination.add("VCA Envelope Amount");
		/*26*/modDestination.add("Envelope 3 Amount");
		/*27*/modDestination.add("All Envelope Amounts");
		/*28*/modDestination.add("LPF Envelope Attack");
		/*29*/modDestination.add("VCA Envelope Attack");
		/*30*/modDestination.add("Envelope 3 Attack");
		/*31*/modDestination.add("All Envelope Attacks");
		/*32*/modDestination.add("LPF Envelope Decay");
		/*33*/modDestination.add("VCA Envelope Decay");
		/*34*/modDestination.add("Envelope 3 Decay");
		/*35*/modDestination.add("All Envelope Decays");
		/*36*/modDestination.add("LPF Envelope Release");
		/*37*/modDestination.add("VCA Envelope Release");
		/*38*/modDestination.add("Envelope 3 Release");
		/*39*/modDestination.add("All Envelope Releases");
		/*40*/modDestination.add("Modulator 1 Amount");
		/*41*/modDestination.add("Modulator 2 Amount");
		/*42*/modDestination.add("Modulator 3 Amount");
		/*43*/modDestination.add("Modulator 4 Amount");
		/*44*/modDestination.add("External Audio In Level");
		/*45*/modDestination.add("Sub-Osc 1 Level");
		/*46*/modDestination.add("Sub-Osc 2 Level");
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Choices)
};

// A collection of StringArrays holding choices for the various plugin parameters
const Choices choices;

//namespace Idx
//{
//	static const enum publicParam
//	{
//		osc1Pitch = 0,
//		osc1Fine,
//		osc1Shape,
//		osc1Glide,
//		osc1KeyTrack,
//		subOsc1Level,
//		osc2Pitch,
//		osc2Fine,
//		osc2Shape,
//		osc2Glide,
//		osc2KeyTrack,
//		subOsc2Level,
//		oscSync,
//		glideMode,
//		oscSlop,
//		bendRange,
//		notePriority
//	};
//}