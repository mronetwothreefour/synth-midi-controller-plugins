#pragma once

#include <JuceHeader.h>

#include "ParameterChoices.h"

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
		ParamLayout layout;
		layout.add(std::make_unique<AudioParameterChoice>	("osc1Pitch", "Oscillator 1 Pitch", choices.pitchNames, 24));
		layout.add(std::make_unique<AudioParameterChoice>	("osc1Fine", "Oscillator 1 Fine Tune", choices.fineTune, 49));
		layout.add(std::make_unique<AudioParameterChoice>	("osc1Shape", "Oscillator 1 Wave Shape", choices.waveShape, 1));
		layout.add(std::make_unique<AudioParameterInt>		("osc1Glide", "Oscillator 1 Glide Rate", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("osc1KeyTrack", "Oscillator 1 Keyboard Tracking", choices.offOn, 1));
		layout.add(std::make_unique<AudioParameterInt>		("subOsc1Level", "Sub Oscillator 1 Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("osc2Pitch", "Oscillator 2 Pitch", choices.pitchNames, 24));
		layout.add(std::make_unique<AudioParameterChoice>	("osc2Fine", "Oscillator 2 Fine Tune", choices.fineTune, 51));
		layout.add(std::make_unique<AudioParameterChoice>	("osc2Shape", "Oscillator 2 Wave Shape", choices.waveShape, 1));
		layout.add(std::make_unique<AudioParameterInt>		("osc2Glide", "Oscillator 2 Glide Rate", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("osc2KeyTrack", "Oscillator 2 Keyboard Tracking", choices.offOn, 1));
		layout.add(std::make_unique<AudioParameterInt>		("subOsc2Level", "Sub Oscillator 2 Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("oscSync", "Sync Oscillator 2 to Oscillator 1", choices.offOn, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("glideMode", "Glide Mode", choices.glideMode, 0));
		layout.add(std::make_unique<AudioParameterInt>		("oscSlop", "Oscillator Slop", 0, 5, 0));
		layout.add(std::make_unique<AudioParameterChoice>	("bendRange", "Pitch Bend Range", choices.pitchBendRange, 4));
		layout.add(std::make_unique<AudioParameterChoice>	("notePriority", "Note Priority", choices.notePriority, 0));
		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};