#pragma once

#include <JuceHeader.h>

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

// Has a createLayout() function which programmatically generates
// an AudioProcessorValueTreeState::ParameterLayout
class PublicParameters
{
public:
	PublicParameters() = default;

	~PublicParameters() = default;

	// Creates a layout of the parameters which will be exposed to the host.
	// This layout is then used to initialize the AudioProcessorValueTreeState.
	ParamLayout createLayout()
	{
		//==============================================================================
		// Define parameter choice StringArrays

		// Used to present a MIDI note number as a pitch name / octave number String
		// (e.g. note number 27 is presented as "D#2")
		StringArray pitchNameChoices;
		for (int i = 0; i != 121; ++i)
		{
			auto noteNum{ i % 12 };
			auto octaveNum{ i / 12 };
			switch (noteNum)
			{
			case 0 : pitchNameChoices.add("C"  + (String)octaveNum); break;
			case 1 : pitchNameChoices.add("C#" + (String)octaveNum); break;
			case 2 : pitchNameChoices.add("D"  + (String)octaveNum); break;
			case 3 : pitchNameChoices.add("D#" + (String)octaveNum); break;
			case 4 : pitchNameChoices.add("E"  + (String)octaveNum); break;
			case 5 : pitchNameChoices.add("F"  + (String)octaveNum); break;
			case 6 : pitchNameChoices.add("F#" + (String)octaveNum); break;
			case 7 : pitchNameChoices.add("G"  + (String)octaveNum); break;
			case 8 : pitchNameChoices.add("G#" + (String)octaveNum); break;
			case 9 : pitchNameChoices.add("A"  + (String)octaveNum); break;
			case 10: pitchNameChoices.add("A#" + (String)octaveNum); break;
			case 11: pitchNameChoices.add("B"  + (String)octaveNum); break;
			default: break;
			}
		}

		// 0 = "-50 cents"; 50 = "Centered"; 100 = "+50 cents"
		StringArray fineTuneChoices;
		for (int i = 0; i != 50; ++i)
		{
			fineTuneChoices.add((String)(i - 50) + " cents");
		}
		fineTuneChoices.add("Centered");
		for (int i = 51; i != 101; ++i)
		{
			fineTuneChoices.add("+" + (String)(i - 50) + " cents");
		}
		//==============================================================================

		ParamLayout layout;
		layout.add(std::make_unique<AudioParameterChoice>("osc1Pitch", "Oscillator 1 Pitch", pitchNameChoices, 24));
		layout.add(std::make_unique<AudioParameterChoice>("osc1Fine", "Oscillator 1 Fine Tune", fineTuneChoices, 49));
		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};