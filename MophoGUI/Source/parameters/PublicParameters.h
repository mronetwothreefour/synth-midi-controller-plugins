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
		/*4  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1KeyTrack.toString(),		"Oscillator 1 Keyboard Track On/Off", choices.offOn, 1));
		/*5  */layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc1Level.toString(),		"Sub-Oscillator 1 Level", 0, 127, 0));
		/*6  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Pitch.toString(),			"Oscillator 2 Pitch", choices.pitchNames, 24));
		/*7  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Fine.toString(),			"Oscillator 2 Fine Tune", choices.fineTune, 51));
		/*8  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Shape.toString(),			"Oscillator 2 Wave Shape", choices.oscShape, 1));
		/*9  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc2Glide.toString(),			"Oscillator 2 Glide Rate", 0, 127, 0));
		/*10 */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2KeyTrack.toString(),		"Oscillator 2 Keyboard Track On/Off", choices.offOn, 1));
		/*11 */layout.add(std::make_unique<AudioParameterInt>		(ID::subOsc2Level.toString(),		"Sub-Oscillator 2 Level", 0, 127, 0));

		/*12 */layout.add(std::make_unique<AudioParameterChoice>	(ID::oscSync.toString(),			"Sync Osc. 2 to Osc. 1 On/Off", choices.offOn, 0));
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
		/*45 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1KeySync.toString(),		"LFO 1 Key Sync On/Off", choices.offOn, 0));
		/*46 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Freq.toString(),			"LFO 2 Frequency", choices.lfoFreq, 80));
		/*47 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Shape.toString(),			"LFO 2 Wave Shape", choices.lfoShape, 1));
		/*48 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo2Amount.toString(),			"LFO 2 Amount", 0, 127, 0));
		/*49 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Destination.toString(),	"LFO 2 Modulation Destination", choices.modDestination, 0));
		/*50 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2KeySync.toString(),		"LFO 2 Key Sync On/Off", choices.offOn, 0));
		/*51 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Freq.toString(),			"LFO 3 Frequency", choices.lfoFreq, 80));
		/*52 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Shape.toString(),			"LFO 3 Wave Shape", choices.lfoShape, 1));
		/*53 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo3Amount.toString(),			"LFO 3 Amount", 0, 127, 0));
		/*54 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Destination.toString(),	"LFO 3 Modulation Destination", choices.modDestination, 0));
		/*55 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3KeySync.toString(),		"LFO 3 Key Sync On/Off", choices.offOn, 0));
		/*56 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Freq.toString(),			"LFO 4 Frequency", choices.lfoFreq, 80));
		/*57 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Shape.toString(),			"LFO 4 Wave Shape", choices.lfoShape, 1));
		/*58 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo4Amount.toString(),			"LFO 4 Amount", 0, 127, 0));
		/*59 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Destination.toString(),	"LFO 4 Modulation Destination", choices.modDestination, 0));
		/*60 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4KeySync.toString(),		"LFO 4 Key Sync On/Off", choices.offOn, 0));

		/*61 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Destination.toString(),	"Envelope 3 Modulation Destination", choices.modDestination, 0));
		/*62 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Amount.toString(),			"Envelope 3 Amount", choices.modAmount, 127));
		/*63 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3VelAmount.toString(),		"Envelope 3 Velocity Amount", 0, 127, 0));
		/*64 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Delay.toString(),			"Envelope 3 Delay", 0, 127, 0));
		/*65 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Attack.toString(),			"Envelope 3 Attack", 0, 127, 0));
		/*66 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Decay.toString(),			"Envelope 3 Decay", 0, 127, 0));
		/*67 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Sustain.toString(),		"Envelope 3 Sustain", 0, 127, 0));
		/*68 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Release.toString(),		"Envelope 3 Release", 0, 127, 0));
		/*69 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Repeat.toString(),			"Envelope 3 Repeat On/Off", choices.offOn, 0));

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

		/*82 */layout.add(std::make_unique<AudioParameterChoice>	(ID::modWheelAmount.toString(),		"Modulation Wheel Amount", choices.modAmount, 127));
		/*83 */layout.add(std::make_unique<AudioParameterChoice>	(ID::modWheelDest.toString(),		"Modulation Wheel Destination", choices.modDestination, 0));
		/*84 */layout.add(std::make_unique<AudioParameterChoice>	(ID::aftertouchAmount.toString(),	"Aftertouch Amount", choices.modAmount, 127));
		/*85 */layout.add(std::make_unique<AudioParameterChoice>	(ID::aftertouchDest.toString(),		"Aftertouch Destination", choices.modDestination, 0));
		/*86 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathAmount.toString(),		"Breath Amount", choices.modAmount, 127));
		/*87 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathDest.toString(),			"Breath Destination", choices.modDestination, 0));
		/*88 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityAmount.toString(),		"Velocity Amount", choices.modAmount, 127));
		/*89 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityDest.toString(),		"Velocity Destination", choices.modDestination, 0));
		/*90 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalAmount.toString(),	"Foot Pedal Amount", choices.modAmount, 127));
		/*91 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalDest.toString(),		"Foot Pedal Destination", choices.modDestination, 0));

		/*92 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItPitch.toString(),		"Push It! Switch Pitch", choices.pitchNames, 24));
		/*93 */layout.add(std::make_unique<AudioParameterInt>		(ID::pushItVelocity.toString(),		"Push It! Switch Velocity", 0, 127, 100));
		/*94 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItMode.toString(),			"Push It! Switch Mode", choices.pushItMode, 0));

		/*95 */layout.add(std::make_unique<AudioParameterInt>		(ID::clockTempo.toString(),			"Clock Tempo (BPM)", 30, 250, 120));
		/*96 */layout.add(std::make_unique<AudioParameterChoice>	(ID::clockDivide.toString(),		"Clock Divide", choices.clockDivide, 2));

		/*97 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegMode.toString(),			"Arpeggiator Mode", choices.arpegMode, 0));
		/*98 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegOnOff.toString(),			"Arpeggiator On/Off", choices.offOn, 0));

		/*99 */layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerTrig.toString(),		"Sequencer Trigger", choices.sequencerTrig, 0));
		/*100*/layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerOnOff.toString(),		"Sequencer On/Off", choices.offOn, 0));
		/*101*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack1Dest.toString(),		"Sequencer Track 1 Destination", choices.modDestination, 1));
		/*102*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack2Dest.toString(),		"Sequencer Track 2 Destination", choices.modDestination, 2));
		/*103*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack3Dest.toString(),		"Sequencer Track 3 Destination", choices.modDestination, 9));
		/*104*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack4Dest.toString(),		"Sequencer Track 4 Destination", choices.modDestination, 0));

		/*105*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob1.toString(),		"Assign Parameter to Knob 1", choices.mophoParams, 20));
		/*106*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob2.toString(),		"Assign Parameter to Knob 2", choices.mophoParams, 21));
		/*107*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob3.toString(),		"Assign Parameter to Knob 3", choices.mophoParams, 36));
		/*108*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob4.toString(),		"Assign Parameter to Knob 4", choices.mophoParams, 39));

		/*109*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned109.toString(),		"Unassigned", 0, 127, 64));
		/*110*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned110.toString(),		"Unassigned", 0, 127, 64));
		/*111*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned111.toString(),		"Unassigned", 0, 127, 64));
		/*112*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned112.toString(),		"Unassigned", 0, 127, 64));
		/*113*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned113.toString(),		"Unassigned", 0, 127, 64));
		/*114*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned114.toString(),		"Unassigned", 0, 127, 64));
		/*115*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned115.toString(),		"Unassigned", 0, 127, 64));
		/*116*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned116.toString(),		"Unassigned", 0, 127, 64));
		/*117*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned117.toString(),		"Unassigned", 0, 127, 64));
		/*118*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned118.toString(),		"Unassigned", 0, 127, 64));
		/*119*/layout.add(std::make_unique<AudioParameterInt>		(ID::unassigned119.toString(),		"Unassigned", 0, 127, 64));
		
		/*120*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step01.toString(),			"Sequencer Track 1 Step 1",  choices.seq1Steps, 0));
		/*121*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step02.toString(),			"Sequencer Track 1 Step 2",  choices.seq1Steps, 0));
		/*122*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step03.toString(),			"Sequencer Track 1 Step 3",  choices.seq1Steps, 0));
		/*123*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step04.toString(),			"Sequencer Track 1 Step 4",  choices.seq1Steps, 0));
		/*124*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step05.toString(),			"Sequencer Track 1 Step 5",  choices.seq1Steps, 0));
		/*125*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step06.toString(),			"Sequencer Track 1 Step 6",  choices.seq1Steps, 0));
		/*126*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step07.toString(),			"Sequencer Track 1 Step 7",  choices.seq1Steps, 0));
		/*127*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step08.toString(),			"Sequencer Track 1 Step 8",  choices.seq1Steps, 0));
		/*128*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step09.toString(),			"Sequencer Track 1 Step 9",  choices.seq1Steps, 0));
		/*129*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step10.toString(),			"Sequencer Track 1 Step 10", choices.seq1Steps, 0));
		/*130*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step11.toString(),			"Sequencer Track 1 Step 11", choices.seq1Steps, 0));
		/*131*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step12.toString(),			"Sequencer Track 1 Step 12", choices.seq1Steps, 0));
		/*132*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step13.toString(),			"Sequencer Track 1 Step 13", choices.seq1Steps, 0));
		/*133*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step14.toString(),			"Sequencer Track 1 Step 14", choices.seq1Steps, 0));
		/*134*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step15.toString(),			"Sequencer Track 1 Step 15", choices.seq1Steps, 0));
		/*135*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step16.toString(),			"Sequencer Track 1 Step 16", choices.seq1Steps, 0));
		
		/*136*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step01.toString(),			"Sequencer Track 2 Step 1",  choices.seq2_3_4Steps, 0));
		/*137*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step02.toString(),			"Sequencer Track 2 Step 2",  choices.seq2_3_4Steps, 0));
		/*138*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step03.toString(),			"Sequencer Track 2 Step 3",  choices.seq2_3_4Steps, 0));
		/*139*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step04.toString(),			"Sequencer Track 2 Step 4",  choices.seq2_3_4Steps, 0));
		/*140*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step05.toString(),			"Sequencer Track 2 Step 5",  choices.seq2_3_4Steps, 0));
		/*141*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step06.toString(),			"Sequencer Track 2 Step 6",  choices.seq2_3_4Steps, 0));
		/*142*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step07.toString(),			"Sequencer Track 2 Step 7",  choices.seq2_3_4Steps, 0));
		/*143*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step08.toString(),			"Sequencer Track 2 Step 8",  choices.seq2_3_4Steps, 0));
		/*144*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step09.toString(),			"Sequencer Track 2 Step 9",  choices.seq2_3_4Steps, 0));
		/*145*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step10.toString(),			"Sequencer Track 2 Step 10", choices.seq2_3_4Steps, 0));
		/*146*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step11.toString(),			"Sequencer Track 2 Step 11", choices.seq2_3_4Steps, 0));
		/*147*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step12.toString(),			"Sequencer Track 2 Step 12", choices.seq2_3_4Steps, 0));
		/*148*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step13.toString(),			"Sequencer Track 2 Step 13", choices.seq2_3_4Steps, 0));
		/*149*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step14.toString(),			"Sequencer Track 2 Step 14", choices.seq2_3_4Steps, 0));
		/*150*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step15.toString(),			"Sequencer Track 2 Step 15", choices.seq2_3_4Steps, 0));
		/*151*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step16.toString(),			"Sequencer Track 2 Step 16", choices.seq2_3_4Steps, 0));
		
		/*152*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step01.toString(),			"Sequencer Track 3 Step 1",  choices.seq2_3_4Steps, 0));
		/*153*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step02.toString(),			"Sequencer Track 3 Step 2",  choices.seq2_3_4Steps, 0));
		/*154*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step03.toString(),			"Sequencer Track 3 Step 3",  choices.seq2_3_4Steps, 0));
		/*155*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step04.toString(),			"Sequencer Track 3 Step 4",  choices.seq2_3_4Steps, 0));
		/*156*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step05.toString(),			"Sequencer Track 3 Step 5",  choices.seq2_3_4Steps, 0));
		/*157*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step06.toString(),			"Sequencer Track 3 Step 6",  choices.seq2_3_4Steps, 0));
		/*158*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step07.toString(),			"Sequencer Track 3 Step 7",  choices.seq2_3_4Steps, 0));
		/*159*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step08.toString(),			"Sequencer Track 3 Step 8",  choices.seq2_3_4Steps, 0));
		/*160*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step09.toString(),			"Sequencer Track 3 Step 9",  choices.seq2_3_4Steps, 0));
		/*161*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step10.toString(),			"Sequencer Track 3 Step 10", choices.seq2_3_4Steps, 0));
		/*162*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step11.toString(),			"Sequencer Track 3 Step 11", choices.seq2_3_4Steps, 0));
		/*163*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step12.toString(),			"Sequencer Track 3 Step 12", choices.seq2_3_4Steps, 0));
		/*164*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step13.toString(),			"Sequencer Track 3 Step 13", choices.seq2_3_4Steps, 0));
		/*165*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step14.toString(),			"Sequencer Track 3 Step 14", choices.seq2_3_4Steps, 0));
		/*166*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step15.toString(),			"Sequencer Track 3 Step 15", choices.seq2_3_4Steps, 0));
		/*167*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step16.toString(),			"Sequencer Track 3 Step 16", choices.seq2_3_4Steps, 0));
		
		/*168*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step01.toString(),			"Sequencer Track 4 Step 1",  choices.seq2_3_4Steps, 0));
		/*169*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step02.toString(),			"Sequencer Track 4 Step 2",  choices.seq2_3_4Steps, 0));
		/*170*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step03.toString(),			"Sequencer Track 4 Step 3",  choices.seq2_3_4Steps, 0));
		/*171*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step04.toString(),			"Sequencer Track 4 Step 4",  choices.seq2_3_4Steps, 0));
		/*172*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step05.toString(),			"Sequencer Track 4 Step 5",  choices.seq2_3_4Steps, 0));
		/*173*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step06.toString(),			"Sequencer Track 4 Step 6",  choices.seq2_3_4Steps, 0));
		/*174*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step07.toString(),			"Sequencer Track 4 Step 7",  choices.seq2_3_4Steps, 0));
		/*175*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step08.toString(),			"Sequencer Track 4 Step 8",  choices.seq2_3_4Steps, 0));
		/*176*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step09.toString(),			"Sequencer Track 4 Step 9",  choices.seq2_3_4Steps, 0));
		/*177*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step10.toString(),			"Sequencer Track 4 Step 10", choices.seq2_3_4Steps, 0));
		/*178*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step11.toString(),			"Sequencer Track 4 Step 11", choices.seq2_3_4Steps, 0));
		/*179*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step12.toString(),			"Sequencer Track 4 Step 12", choices.seq2_3_4Steps, 0));
		/*180*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step13.toString(),			"Sequencer Track 4 Step 13", choices.seq2_3_4Steps, 0));
		/*181*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step14.toString(),			"Sequencer Track 4 Step 14", choices.seq2_3_4Steps, 0));
		/*182*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step15.toString(),			"Sequencer Track 4 Step 15", choices.seq2_3_4Steps, 0));
		/*183*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step16.toString(),			"Sequencer Track 4 Step 16", choices.seq2_3_4Steps, 0));

		/*184*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar01.toString(),			"Program Name Character 1",  choices.nameChars, 77));
		/*185*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar02.toString(),			"Program Name Character 2",  choices.nameChars, 111));
		/*186*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar03.toString(),			"Program Name Character 3",  choices.nameChars, 112));
		/*187*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar04.toString(),			"Program Name Character 4",  choices.nameChars, 104));
		/*188*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar05.toString(),			"Program Name Character 5",  choices.nameChars, 111));
		/*189*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar06.toString(),			"Program Name Character 6",  choices.nameChars, 32));
		/*190*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar07.toString(),			"Program Name Character 7",  choices.nameChars, 71));
		/*191*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar08.toString(),			"Program Name Character 8",  choices.nameChars, 111));
		/*192*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar09.toString(),			"Program Name Character 9",  choices.nameChars, 111));
		/*193*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar10.toString(),			"Program Name Character 10", choices.nameChars, 101));
		/*194*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar11.toString(),			"Program Name Character 11", choices.nameChars, 121));
		/*195*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar12.toString(),			"Program Name Character 12", choices.nameChars, 33));
		/*196*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar13.toString(),			"Program Name Character 13", choices.nameChars, 33));
		/*197*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar14.toString(),			"Program Name Character 14", choices.nameChars, 33));
		/*198*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar15.toString(),			"Program Name Character 15", choices.nameChars, 33));
		/*199*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar16.toString(),			"Program Name Character 16", choices.nameChars, 33));

		return layout;
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};