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
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Pitch.toString(), "Oscillator 1 Pitch", choices.pitchNames, 24));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Fine.toString(), "Oscillator 1 Fine Tune", choices.fineTune, 49));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Shape.toString(), "Oscillator 1 Wave Shape", choices.waveShape, 1));
		layout.add(std::make_unique<AudioParameterInt>		(ID::osc1Glide.toString(), "Oscillator 1 Glide Rate", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1KeyTrack.toString(), "Oscillator 1 Keyboard Tracking", choices.offOn, 1));
		layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc1Level.toString(), "Sub Oscillator 1 Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Pitch.toString(), "Oscillator 2 Pitch", choices.pitchNames, 24));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Fine.toString(), "Oscillator 2 Fine Tune", choices.fineTune, 51));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Shape.toString(), "Oscillator 2 Wave Shape", choices.waveShape, 1));
		layout.add(std::make_unique<AudioParameterInt>		(ID::osc2Glide.toString(), "Oscillator 2 Glide Rate", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2KeyTrack.toString(), "Oscillator 2 Keyboard Tracking", choices.offOn, 1));
		layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc2Level.toString(), "Sub Oscillator 2 Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::oscSync.toString(), "Sync Oscillator 2 to Oscillator 1", choices.offOn, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::glideMode.toString(), "Glide Mode", choices.glideMode, 0));
		layout.add(std::make_unique<AudioParameterInt>		(ID::oscSlop.toString(), "Oscillator Slop", 0, 5, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::bendRange.toString(), "Pitch Bend Range", choices.pitchBendRange, 4));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::notePriority.toString(), "Note Priority", choices.notePriority, 0));
		layout.add(std::make_unique<AudioParameterInt>		(ID::oscMix.toString(), "Oscillator 1 & 2 Mix", 0, 127, 64));
		layout.add(std::make_unique<AudioParameterInt>		(ID::noiseLevel.toString(), "Noise Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterInt>		(ID::extInLevel.toString(), "External Audio Input Level", 0, 127, 0));
		layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfFreq.toString(), "LPF Cutoff Frequency", choices.lpfFreq, 148));
		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};