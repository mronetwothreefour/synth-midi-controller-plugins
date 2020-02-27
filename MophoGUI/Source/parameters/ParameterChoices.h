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
	StringArray waveShape;

	// 0 = "Off"; 1 = "On"
	StringArray offOn;

	StringArray glideMode;

	StringArray pitchBendRange;

	StringArray notePriority;

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

		// initialize waveShape
		waveShape.add("Off");
		waveShape.add("Sawtooth");
		waveShape.add("Triangle");
		waveShape.add("Saw/Tri Mix");
		for (int i = 0; i != 100; ++i)
		{
			waveShape.add("Pulse Width " + (String)i);
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
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Choices)
};

// A collection of StringArrays holding choices for the various plugin parameters
static const Choices choices;

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