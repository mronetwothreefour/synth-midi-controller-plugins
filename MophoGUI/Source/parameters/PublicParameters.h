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
		/*0  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Pitch.toString(),			"Oscillator 1 Pitch", choices.pitchNames, 24));
		/*1  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Fine.toString(),			"Oscillator 1 Fine Tune", choices.fineTune, 49));
		/*2  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Shape.toString(),			"Oscillator 1 Wave Shape", choices.oscShape, 1));
		/*3  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc1Glide.toString(),			"Oscillator 1 Glide Rate", 0, 127, 0));
		/*4  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1KeyTrack.toString(),		"Oscillator 1 Keyboard Tracking", choices.offOn, 1));
		/*5  */layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc1Level.toString(),		"Sub-Oscillator 1 Level", 0, 127, 0));
		/*6  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Pitch.toString(),			"Oscillator 2 Pitch", choices.pitchNames, 24));
		/*7  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Fine.toString(),			"Oscillator 2 Fine Tune", choices.fineTune, 51));
		/*8  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Shape.toString(),			"Oscillator 2 Wave Shape", choices.oscShape, 1));
		/*9  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc2Glide.toString(),			"Oscillator 2 Glide Rate", 0, 127, 0));
		/*10 */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2KeyTrack.toString(),		"Oscillator 2 Keyboard Tracking", choices.offOn, 1));
		/*11 */layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc2Level.toString(),		"Sub-Oscillator 2 Level", 0, 127, 0));

		/*12 */layout.add(std::make_unique<AudioParameterChoice>	(ID::oscSync.toString(),			"Sync Oscillator 2 to Oscillator 1", choices.offOn, 0));
		/*13 */layout.add(std::make_unique<AudioParameterChoice>	(ID::glideMode.toString(),			"Glide Mode", choices.glideMode, 0));
		/*14 */layout.add(std::make_unique<AudioParameterInt>		(ID::oscSlop.toString(),			"Oscillator Slop", 0, 5, 0));
		/*15 */layout.add(std::make_unique<AudioParameterChoice>	(ID::bendRange.toString(),			"Pitch Bend Range", choices.pitchBendRange, 4));
		/*16 */layout.add(std::make_unique<AudioParameterChoice>	(ID::notePriority.toString(),		"Note Priority", choices.notePriority, 0));

		/*17 */layout.add(std::make_unique<AudioParameterInt>		(ID::oscMix.toString(),				"Oscillator 1 & 2 Mix", 0, 127, 64));
		/*18 */layout.add(std::make_unique<AudioParameterInt>		(ID::noiseLevel.toString(),			"Noise Level", 0, 127, 0));
		/*19 */layout.add(std::make_unique<AudioParameterInt>		(ID::extInLevel.toString(),			"External Audio Input Level", 0, 127, 0));

		/*20 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfFreq.toString(),			"LPF Cutoff Frequency", choices.lpfFreq, 148));
		/*21 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfReso.toString(),			"LPF Resonance", 0, 127, 0));
		/*22 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfKeyAmount.toString(),		"LPF Keyboard Amount", 0, 127, 0));
		/*23 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfOsc1FM.toString(),			"LPF FM (By Oscillator 1)", 0, 127, 0));
		/*24 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfType.toString(),			"LPF Type", choices.lpfType, 148));
		/*25 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfAmount.toString(),			"LPF Envelope Amount", choices.modAmount, 127));
		/*26 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfVelAmount.toString(),		"LPF Envelope Velocity Amount", 0, 127, 0));
		/*27 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfDelay.toString(),			"LPF Envelope Delay", 0, 127, 0));
		/*28 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfAttack.toString(),			"LPF Envelope Attack", 0, 127, 0));
		/*29 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfDecay.toString(),			"LPF Envelope Decay", 0, 127, 0));
		/*30 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfSustain.toString(),			"LPF Envelope Sustain", 0, 127, 0));
		/*31 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfRelease.toString(),			"LPF Envelope Release", 0, 127, 0));

		/*32 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaInitLevel.toString(),		"VCA Initial Level", 0, 127, 0));
		/*33 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaAmount.toString(),			"VCA Envelope Amount", 0, 127, 127));
		/*34 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaVelAmount.toString(),		"VCA Envelope Velocity Amount", 0, 127, 0));
		/*35 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaDelay.toString(),			"VCA Envelope Delay", 0, 127, 0));
		/*36 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaAttack.toString(),			"VCA Envelope Attack", 0, 127, 0));
		/*37 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaDecay.toString(),			"VCA Envelope Decay", 0, 127, 0));
		/*38 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaSustain.toString(),			"VCA Envelope Sustain", 0, 127, 64));
		/*39 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaRelease.toString(),			"VCA Envelope Release", 0, 127, 64));
		/*40 */layout.add(std::make_unique<AudioParameterInt>		(ID::voiceVolume.toString(),		"Voice Volume", 0, 127, 120));

		/*41 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Freq.toString(),			"LFO 1 Frequency", choices.lfoFreq, 80));
		/*42 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Shape.toString(),			"LFO 1 Wave Shape", choices.lfoShape, 1));
		/*43 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo1Amount.toString(),			"LFO 1 Amount", 0, 127, 0));
		/*44 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Destination.toString(),	"LFO 1 Modulation Destination", choices.modDestination, 0));
		/*45 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1KeySync.toString(),		"LFO 1 Key Sync", choices.offOn, 0));
		/*46 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Freq.toString(),			"LFO 2 Frequency", choices.lfoFreq, 80));
		/*47 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Shape.toString(),			"LFO 2 Wave Shape", choices.lfoShape, 1));
		/*48 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo2Amount.toString(),			"LFO 2 Amount", 0, 127, 0));
		/*49 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Destination.toString(),	"LFO 2 Modulation Destination", choices.modDestination, 0));
		/*50 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2KeySync.toString(),		"LFO 2 Key Sync", choices.offOn, 0));
		/*51 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Freq.toString(),			"LFO 3 Frequency", choices.lfoFreq, 80));
		/*52 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Shape.toString(),			"LFO 3 Wave Shape", choices.lfoShape, 1));
		/*53 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo3Amount.toString(),			"LFO 3 Amount", 0, 127, 0));
		/*54 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Destination.toString(),	"LFO 3 Modulation Destination", choices.modDestination, 0));
		/*55 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3KeySync.toString(),		"LFO 3 Key Sync", choices.offOn, 0));
		/*56 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Freq.toString(),			"LFO 4 Frequency", choices.lfoFreq, 80));
		/*57 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Shape.toString(),			"LFO 4 Wave Shape", choices.lfoShape, 1));
		/*58 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo4Amount.toString(),			"LFO 4 Amount", 0, 127, 0));
		/*59 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Destination.toString(),	"LFO 4 Modulation Destination", choices.modDestination, 0));
		/*60 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4KeySync.toString(),		"LFO 4 Key Sync", choices.offOn, 0));

		/*61 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Destination.toString(),	"Envelope 3 Modulation Destination", choices.modDestination, 0));
		/*62 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Amount.toString(),			"Envelope 3 Amount", choices.modAmount, 127));
		/*63 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3VelAmount.toString(),		"Envelope 3 Velocity Amount", 0, 127, 0));
		/*64 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Delay.toString(),			"Envelope 3 Delay", 0, 127, 0));
		/*65 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Attack.toString(),			"Envelope 3 Attack", 0, 127, 0));
		/*66 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Decay.toString(),			"Envelope 3 Decay", 0, 127, 0));
		/*67 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Sustain.toString(),		"Envelope 3 Sustain", 0, 127, 0));
		/*68 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Release.toString(),		"Envelope 3 Release", 0, 127, 0));
		/*69 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Repeat.toString(),			"Envelope 3 Repeat", choices.offOn, 0));

		/*70 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Source.toString(),			"Modulator 1 Source", choices.modSource, 0));
		/*71 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Amount.toString(),			"Modulator 1 Amount", choices.modAmount, 127));
		/*72 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Destination.toString(),	"Modulator 1 Destination", choices.modDestination, 0));
		/*73 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Source.toString(),			"Modulator 2 Source", choices.modSource, 0));
		/*74 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Amount.toString(),			"Modulator 2 Amount", choices.modAmount, 127));
		/*75 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Destination.toString(),	"Modulator 2 Destination", choices.modDestination, 0));
		/*76 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Source.toString(),			"Modulator 3 Source", choices.modSource, 0));
		/*77 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Amount.toString(),			"Modulator 3 Amount", choices.modAmount, 127));
		/*78 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Destination.toString(),	"Modulator 3 Destination", choices.modDestination, 0));
		/*79 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Source.toString(),			"Modulator 4 Source", choices.modSource, 0));
		/*80 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Amount.toString(),			"Modulator 4 Amount", choices.modAmount, 127));
		/*81 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Destination.toString(),	"Modulator 4 Destination", choices.modDestination, 0));
		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};