#pragma once

#include <JuceHeader.h>

#include "../helpers/ParameterTools.h"
#include "../helpers/ValueConverters.h"

using ParamLayout = AudioProcessorValueTreeState::ParameterLayout;

// Has a createLayout() function which programmatically generates
// an AudioProcessorValueTreeState::ParameterLayout
class PublicParameters : public MophoParameterValueConverter
{
public:
	PublicParameters(ValueConverters* vc) : valueConverters{ vc }
	{}

	~PublicParameters() = default;

	// Creates a layout of the parameters which will be exposed to the host.
	// This layout is then used to initialize the AudioProcessorValueTreeState.
	ParamLayout createLayout()
	{
		//==============================================================================
		// First, create StringArrays that will be used to initialize choice parameters

		StringArray pitchNames;
		for (auto i = 0; i != 121; ++i)
			pitchNames.add(convertIntToValueString(MophoParameterType::oscPitch, i, true));

		StringArray fineTune;
		for (auto i = 0; i != 101; ++i)
			fineTune.add(convertIntToValueString(MophoParameterType::oscFineTune, i, true));

		StringArray oscShape;
		for (auto i = 0; i != 104; ++i)
			oscShape.add(convertIntToValueString(MophoParameterType::oscShape, i, true));

		StringArray offOn;
		for (auto i = 0; i != 2; ++i)
			offOn.add(convertIntToValueString(MophoParameterType::offOn, i, true));

		StringArray glideMode;
		for (auto i = 0; i != 4; ++i)
			glideMode.add(convertIntToValueString(MophoParameterType::glideMode, i, true));

		StringArray pitchBendRange;
		for (auto i = 0; i != 13; ++i)
			pitchBendRange.add(convertIntToValueString(MophoParameterType::pitchBendRange, i, true));

		StringArray notePriority;
		for (auto i = 0; i != 6; ++i)
			notePriority.add(convertIntToValueString(MophoParameterType::notePriority, i, true));

		StringArray lpfFreq;
		for (auto i = 0; i != 165; ++i)
			lpfFreq.add(convertIntToValueString(MophoParameterType::lpfFreq, i, true));

		StringArray lpfType;
		for (auto i = 0; i != 2; ++i)
			lpfType.add(convertIntToValueString(MophoParameterType::lpfType, i, true));

		StringArray modAmount;
		for (auto i = 0; i != 255; ++i)
			modAmount.add(convertIntToValueString(MophoParameterType::modAmount, i, true));

		StringArray lfoFreq;
		for (auto i = 0; i != 167; ++i)
			lfoFreq.add(convertIntToValueString(MophoParameterType::lfoFreq, i, true));

		StringArray lfoShape;
		for (auto i = 0; i != 5; ++i)
			lfoShape.add(convertIntToValueString(MophoParameterType::lfoShape, i, true));

		StringArray modSource;
		for (auto i = 0; i != 23; ++i)
			modSource.add(convertIntToValueString(MophoParameterType::modSource, i, true));

		StringArray modDestination;
		for (auto i = 0; i != 47; ++i)
			modDestination.add(convertIntToValueString(MophoParameterType::modDestination, i, true));

		StringArray pushItMode;
		for (auto i = 0; i != 3; ++i)
			pushItMode.add(convertIntToValueString(MophoParameterType::pushItMode, i, true));

		StringArray clockTempo;
		for (auto i = 0; i != 221; ++i)
			clockTempo.add(convertIntToValueString(MophoParameterType::clockTempo, i, true));

		StringArray clockDivide;
		for (auto i = 0; i != 13; ++i)
			clockDivide.add(convertIntToValueString(MophoParameterType::clockDivide, i, true));

		StringArray arpegMode;
		for (auto i = 0; i != 4; ++i)
			arpegMode.add(convertIntToValueString(MophoParameterType::arpegMode, i, true));

		StringArray sequencerTrig;
		for (auto i = 0; i != 6; ++i)
			sequencerTrig.add(convertIntToValueString(MophoParameterType::sequencerTrig, i, true));

		StringArray mophoParams;
		for (auto i = 0; i != 169; ++i)
			mophoParams.add(convertIntToValueString(MophoParameterType::mophoParamList, i, true));

		StringArray track1Steps;
		for (auto i = 0; i != 128; ++i)
			track1Steps.add(convertIntToValueString(MophoParameterType::stepValue, i, true));

		StringArray track2_3_4Steps;
		for (auto i = 0; i != 127; ++i)
			track2_3_4Steps.add(convertIntToValueString(MophoParameterType::stepValue, i, true));

		StringArray nameChars;
		for (auto i = 0; i != 128; ++i)
			nameChars.add(convertIntToValueString(MophoParameterType::pgmNameChar, i, true));

		//==============================================================================
		// Then, create the public parameter layout and return it

		ParamLayout layout;
		/*0  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Pitch.toString(),			"Oscillator 1 Pitch", pitchNames, 24));
		/*1  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Fine.toString(),			"Oscillator 1 Fine Tune", fineTune, 49));
		/*2  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1Shape.toString(),			"Oscillator 1 Wave Shape", oscShape, 1));
		/*3  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc1Glide.toString(),			"Oscillator 1 Glide Rate", 0, 127, 0));
		/*4  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc1KeyTrack.toString(),		"Oscillator 1 Keyboard Track On/Off", offOn, 1));
		/*5  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc1SubLevel.toString(),		"Sub-Oscillator 1 Level", 0, 127, 0));
		/*6  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Pitch.toString(),			"Oscillator 2 Pitch", pitchNames, 24));
		/*7  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Fine.toString(),			"Oscillator 2 Fine Tune", fineTune, 51));
		/*8  */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2Shape.toString(),			"Oscillator 2 Wave Shape", oscShape, 1));
		/*9  */layout.add(std::make_unique<AudioParameterInt>		(ID::osc2Glide.toString(),			"Oscillator 2 Glide Rate", 0, 127, 0));
		/*10 */layout.add(std::make_unique<AudioParameterChoice>	(ID::osc2KeyTrack.toString(),		"Oscillator 2 Keyboard Track On/Off", offOn, 1));
		/*11 */layout.add(std::make_unique<AudioParameterInt>		(ID::osc2SubLevel.toString(),		"Sub-Oscillator 2 Level", 0, 127, 0));

		/*12 */layout.add(std::make_unique<AudioParameterChoice>	(ID::oscSync.toString(),			"Sync Osc. 2 to Osc. 1 On/Off", offOn, 0));
		/*13 */layout.add(std::make_unique<AudioParameterChoice>	(ID::glideMode.toString(),			"Glide Mode", glideMode, 0));
		/*14 */layout.add(std::make_unique<AudioParameterInt>		(ID::oscSlop.toString(),			"Oscillator Slop", 0, 5, 0));
		/*15 */layout.add(std::make_unique<AudioParameterChoice>	(ID::bendRange.toString(),			"Pitch Bend Range", pitchBendRange, 4));
		/*16 */layout.add(std::make_unique<AudioParameterChoice>	(ID::notePriority.toString(),		"Note Priority", notePriority, 0));

		/*17 */layout.add(std::make_unique<AudioParameterInt>		(ID::oscMix.toString(),				"Oscillator 1 & 2 Mix", 0, 127, 64));
		/*18 */layout.add(std::make_unique<AudioParameterInt>		(ID::noiseLevel.toString(),			"Noise Level", 0, 127, 0));
		/*19 */layout.add(std::make_unique<AudioParameterInt>		(ID::extInLevel.toString(),			"External Audio Input Level", 0, 127, 0));

		/*20 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfFreq.toString(),			"LPF Cutoff Frequency", lpfFreq, 148));
		/*21 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfReso.toString(),			"LPF Resonance", 0, 127, 0));
		/*22 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfKeyAmount.toString(),		"LPF Keyboard Amount", 0, 127, 0));
		/*23 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfFMamount.toString(),		"LPF FM (By Oscillator 1)", 0, 127, 0));
		/*24 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfType.toString(),			"LPF Type", lpfType, 148));
		/*25 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lpfEnvAmount.toString(),		"LPF Envelope Amount", modAmount, 127));
		/*26 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfVelAmount.toString(),		"LPF Envelope Velocity Amount", 0, 127, 0));
		/*27 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfDelay.toString(),			"LPF Envelope Delay", 0, 127, 0));
		/*28 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfAttack.toString(),			"LPF Envelope Attack", 0, 127, 0));
		/*29 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfDecay.toString(),			"LPF Envelope Decay", 0, 127, 0));
		/*30 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfSustain.toString(),			"LPF Envelope Sustain", 0, 127, 0));
		/*31 */layout.add(std::make_unique<AudioParameterInt>		(ID::lpfRelease.toString(),			"LPF Envelope Release", 0, 127, 0));

		/*32 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaLevel.toString(),			"VCA Baseline Level", 0, 127, 0));
		/*33 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaEnvAmount.toString(),		"VCA Envelope Amount", 0, 127, 127));
		/*34 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaVelAmount.toString(),		"VCA Envelope Velocity Amount", 0, 127, 0));
		/*35 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaDelay.toString(),			"VCA Envelope Delay", 0, 127, 0));
		/*36 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaAttack.toString(),			"VCA Envelope Attack", 0, 127, 0));
		/*37 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaDecay.toString(),			"VCA Envelope Decay", 0, 127, 0));
		/*38 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaSustain.toString(),			"VCA Envelope Sustain", 0, 127, 64));
		/*39 */layout.add(std::make_unique<AudioParameterInt>		(ID::vcaRelease.toString(),			"VCA Envelope Release", 0, 127, 64));
		/*40 */layout.add(std::make_unique<AudioParameterInt>		(ID::pgmVolume.toString(),			"Program Volume", 0, 127, 120));

		/*41 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Freq.toString(),			"LFO 1 Frequency", lfoFreq, 80));
		/*42 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Shape.toString(),			"LFO 1 Wave Shape", lfoShape, 1));
		/*43 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo1Amount.toString(),			"LFO 1 Amount", 0, 127, 0));
		/*44 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1Destination.toString(),	"LFO 1 Modulation Destination", modDestination, 0));
		/*45 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo1KeySync.toString(),		"LFO 1 Key Sync On/Off", offOn, 0));
		/*46 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Freq.toString(),			"LFO 2 Frequency", lfoFreq, 80));
		/*47 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Shape.toString(),			"LFO 2 Wave Shape", lfoShape, 1));
		/*48 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo2Amount.toString(),			"LFO 2 Amount", 0, 127, 0));
		/*49 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2Destination.toString(),	"LFO 2 Modulation Destination", modDestination, 0));
		/*50 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo2KeySync.toString(),		"LFO 2 Key Sync On/Off", offOn, 0));
		/*51 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Freq.toString(),			"LFO 3 Frequency", lfoFreq, 80));
		/*52 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Shape.toString(),			"LFO 3 Wave Shape", lfoShape, 1));
		/*53 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo3Amount.toString(),			"LFO 3 Amount", 0, 127, 0));
		/*54 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3Destination.toString(),	"LFO 3 Modulation Destination", modDestination, 0));
		/*55 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo3KeySync.toString(),		"LFO 3 Key Sync On/Off", offOn, 0));
		/*56 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Freq.toString(),			"LFO 4 Frequency", lfoFreq, 80));
		/*57 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Shape.toString(),			"LFO 4 Wave Shape", lfoShape, 1));
		/*58 */layout.add(std::make_unique<AudioParameterInt>		(ID::lfo4Amount.toString(),			"LFO 4 Amount", 0, 127, 0));
		/*59 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4Destination.toString(),	"LFO 4 Modulation Destination", modDestination, 0));
		/*60 */layout.add(std::make_unique<AudioParameterChoice>	(ID::lfo4KeySync.toString(),		"LFO 4 Key Sync On/Off", offOn, 0));

		/*61 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Destination.toString(),	"Envelope 3 Modulation Destination", modDestination, 0));
		/*62 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Amount.toString(),			"Envelope 3 Amount", modAmount, 127));
		/*63 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3VelAmount.toString(),		"Envelope 3 Velocity Amount", 0, 127, 0));
		/*64 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Delay.toString(),			"Envelope 3 Delay", 0, 127, 0));
		/*65 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Attack.toString(),			"Envelope 3 Attack", 0, 127, 0));
		/*66 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Decay.toString(),			"Envelope 3 Decay", 0, 127, 0));
		/*67 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Sustain.toString(),		"Envelope 3 Sustain", 0, 127, 0));
		/*68 */layout.add(std::make_unique<AudioParameterInt>		(ID::env3Release.toString(),		"Envelope 3 Release", 0, 127, 0));
		/*69 */layout.add(std::make_unique<AudioParameterChoice>	(ID::env3Repeat.toString(),			"Envelope 3 Repeat On/Off", offOn, 0));

		/*70 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Source.toString(),			"Modulator 1 Source", modSource, 0));
		/*71 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Amount.toString(),			"Modulator 1 Amount", modAmount, 127));
		/*72 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod1Destination.toString(),	"Modulator 1 Destination", modDestination, 0));
		/*73 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Source.toString(),			"Modulator 2 Source", modSource, 0));
		/*74 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Amount.toString(),			"Modulator 2 Amount", modAmount, 127));
		/*75 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod2Destination.toString(),	"Modulator 2 Destination", modDestination, 0));
		/*76 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Source.toString(),			"Modulator 3 Source", modSource, 0));
		/*77 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Amount.toString(),			"Modulator 3 Amount", modAmount, 127));
		/*78 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod3Destination.toString(),	"Modulator 3 Destination", modDestination, 0));
		/*79 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Source.toString(),			"Modulator 4 Source", modSource, 0));
		/*80 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Amount.toString(),			"Modulator 4 Amount", modAmount, 127));
		/*81 */layout.add(std::make_unique<AudioParameterChoice>	(ID::mod4Destination.toString(),	"Modulator 4 Destination", modDestination, 0));

		/*82 */layout.add(std::make_unique<AudioParameterChoice>	(ID::modWheelAmount.toString(),		"Modulation Wheel Amount", modAmount, 127));
		/*83 */layout.add(std::make_unique<AudioParameterChoice>	(ID::modWheelDest.toString(),		"Modulation Wheel Destination", modDestination, 0));
		/*84 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pressureAmount.toString(),	"Aftertouch Amount", modAmount, 127));
		/*85 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pressureDest.toString(),		"Aftertouch Destination", modDestination, 0));
		/*86 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathAmount.toString(),		"Breath Amount", modAmount, 127));
		/*87 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathDest.toString(),			"Breath Destination", modDestination, 0));
		/*88 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityAmount.toString(),		"Velocity Amount", modAmount, 127));
		/*89 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityDest.toString(),		"Velocity Destination", modDestination, 0));
		/*90 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalAmount.toString(),	"Foot Pedal Amount", modAmount, 127));
		/*91 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalDest.toString(),		"Foot Pedal Destination", modDestination, 0));

		/*92 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItPitch.toString(),		"Push It! Switch Pitch", pitchNames, 36));
		/*93 */layout.add(std::make_unique<AudioParameterInt>		(ID::pushItVelocity.toString(),		"Push It! Switch Velocity", 0, 127, 100));
		/*94 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItMode.toString(),			"Push It! Switch Mode", pushItMode, 0));

		/*95 */layout.add(std::make_unique<AudioParameterChoice>	(ID::clockTempo.toString(),			"Clock Tempo", clockTempo, 90));
		/*96 */layout.add(std::make_unique<AudioParameterChoice>	(ID::clockDivide.toString(),		"Clock Divide", clockDivide, 2));

		/*97 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegMode.toString(),			"Arpeggiator Mode", arpegMode, 0));
		/*98 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegOnOff.toString(),			"Arpeggiator On/Off", offOn, 0));

		/*99 */layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerTrig.toString(),		"Sequencer Trigger Mode", sequencerTrig, 0));
		/*100*/layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerOnOff.toString(),		"Sequencer On/Off", offOn, 0));
		/*101*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Dest.toString(),			"Sequence Track 1 Destination", modDestination, 1));
		/*102*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Dest.toString(),			"Sequence Track 2 Destination", modDestination, 2));
		/*103*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Dest.toString(),			"Sequence Track 3 Destination", modDestination, 9));
		/*104*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Dest.toString(),			"Sequence Track 4 Destination", modDestination, 0));

		/*105*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob1.toString(),		"Assign Parameter to Knob 1", mophoParams, 20));
		/*106*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob2.toString(),		"Assign Parameter to Knob 2", mophoParams, 21));
		/*107*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob3.toString(),		"Assign Parameter to Knob 3", mophoParams, 36));
		/*108*/layout.add(std::make_unique<AudioParameterChoice>	(ID::assignKnob4.toString(),		"Assign Parameter to Knob 4", mophoParams, 39));

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
		
		/*120*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step1 .toString(),		"Sequencer Track 1 Step 1",  track1Steps, 72));
		/*121*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step2 .toString(),		"Sequencer Track 1 Step 2",  track1Steps, 72));
		/*122*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step3 .toString(),		"Sequencer Track 1 Step 3",  track1Steps, 72));
		/*123*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step4 .toString(),		"Sequencer Track 1 Step 4",  track1Steps, 72));
		/*124*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step5 .toString(),		"Sequencer Track 1 Step 5",  track1Steps, 72));
		/*125*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step6 .toString(),		"Sequencer Track 1 Step 6",  track1Steps, 72));
		/*126*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step7 .toString(),		"Sequencer Track 1 Step 7",  track1Steps, 72));
		/*127*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step8 .toString(),		"Sequencer Track 1 Step 8",  track1Steps, 72));
		/*128*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step9 .toString(),		"Sequencer Track 1 Step 9",  track1Steps, 72));
		/*129*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step10.toString(),		"Sequencer Track 1 Step 10", track1Steps, 72));
		/*130*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step11.toString(),		"Sequencer Track 1 Step 11", track1Steps, 72));
		/*131*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step12.toString(),		"Sequencer Track 1 Step 12", track1Steps, 72));
		/*132*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step13.toString(),		"Sequencer Track 1 Step 13", track1Steps, 72));
		/*133*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step14.toString(),		"Sequencer Track 1 Step 14", track1Steps, 72));
		/*134*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step15.toString(),		"Sequencer Track 1 Step 15", track1Steps, 72));
		/*135*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track1Step16.toString(),		"Sequencer Track 1 Step 16", track1Steps, 72));
		
		/*136*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step1 .toString(),		"Sequencer Track 2 Step 1",  track2_3_4Steps, 72));
		/*137*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step2 .toString(),		"Sequencer Track 2 Step 2",  track2_3_4Steps, 72));
		/*138*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step3 .toString(),		"Sequencer Track 2 Step 3",  track2_3_4Steps, 72));
		/*139*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step4 .toString(),		"Sequencer Track 2 Step 4",  track2_3_4Steps, 72));
		/*140*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step5 .toString(),		"Sequencer Track 2 Step 5",  track2_3_4Steps, 72));
		/*141*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step6 .toString(),		"Sequencer Track 2 Step 6",  track2_3_4Steps, 72));
		/*142*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step7 .toString(),		"Sequencer Track 2 Step 7",  track2_3_4Steps, 72));
		/*143*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step8 .toString(),		"Sequencer Track 2 Step 8",  track2_3_4Steps, 72));
		/*144*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step9 .toString(),		"Sequencer Track 2 Step 9",  track2_3_4Steps, 72));
		/*145*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step10.toString(),		"Sequencer Track 2 Step 10", track2_3_4Steps, 72));
		/*146*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step11.toString(),		"Sequencer Track 2 Step 11", track2_3_4Steps, 72));
		/*147*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step12.toString(),		"Sequencer Track 2 Step 12", track2_3_4Steps, 72));
		/*148*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step13.toString(),		"Sequencer Track 2 Step 13", track2_3_4Steps, 72));
		/*149*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step14.toString(),		"Sequencer Track 2 Step 14", track2_3_4Steps, 72));
		/*150*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step15.toString(),		"Sequencer Track 2 Step 15", track2_3_4Steps, 72));
		/*151*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track2Step16.toString(),		"Sequencer Track 2 Step 16", track2_3_4Steps, 72));
		
		/*152*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step1 .toString(),		"Sequencer Track 3 Step 1",  track2_3_4Steps, 0));
		/*153*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step2 .toString(),		"Sequencer Track 3 Step 2",  track2_3_4Steps, 0));
		/*154*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step3 .toString(),		"Sequencer Track 3 Step 3",  track2_3_4Steps, 0));
		/*155*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step4 .toString(),		"Sequencer Track 3 Step 4",  track2_3_4Steps, 0));
		/*156*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step5 .toString(),		"Sequencer Track 3 Step 5",  track2_3_4Steps, 0));
		/*157*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step6 .toString(),		"Sequencer Track 3 Step 6",  track2_3_4Steps, 0));
		/*158*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step7 .toString(),		"Sequencer Track 3 Step 7",  track2_3_4Steps, 0));
		/*159*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step8 .toString(),		"Sequencer Track 3 Step 8",  track2_3_4Steps, 0));
		/*160*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step9 .toString(),		"Sequencer Track 3 Step 9",  track2_3_4Steps, 0));
		/*161*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step10.toString(),		"Sequencer Track 3 Step 10", track2_3_4Steps, 0));
		/*162*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step11.toString(),		"Sequencer Track 3 Step 11", track2_3_4Steps, 0));
		/*163*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step12.toString(),		"Sequencer Track 3 Step 12", track2_3_4Steps, 0));
		/*164*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step13.toString(),		"Sequencer Track 3 Step 13", track2_3_4Steps, 0));
		/*165*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step14.toString(),		"Sequencer Track 3 Step 14", track2_3_4Steps, 0));
		/*166*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step15.toString(),		"Sequencer Track 3 Step 15", track2_3_4Steps, 0));
		/*167*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track3Step16.toString(),		"Sequencer Track 3 Step 16", track2_3_4Steps, 0));
		
		/*168*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step1 .toString(),		"Sequencer Track 4 Step 1",  track2_3_4Steps, 0));
		/*169*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step2 .toString(),		"Sequencer Track 4 Step 2",  track2_3_4Steps, 0));
		/*170*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step3 .toString(),		"Sequencer Track 4 Step 3",  track2_3_4Steps, 0));
		/*171*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step4 .toString(),		"Sequencer Track 4 Step 4",  track2_3_4Steps, 0));
		/*172*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step5 .toString(),		"Sequencer Track 4 Step 5",  track2_3_4Steps, 0));
		/*173*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step6 .toString(),		"Sequencer Track 4 Step 6",  track2_3_4Steps, 0));
		/*174*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step7 .toString(),		"Sequencer Track 4 Step 7",  track2_3_4Steps, 0));
		/*175*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step8 .toString(),		"Sequencer Track 4 Step 8",  track2_3_4Steps, 0));
		/*176*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step9 .toString(),		"Sequencer Track 4 Step 9",  track2_3_4Steps, 0));
		/*177*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step10.toString(),		"Sequencer Track 4 Step 10", track2_3_4Steps, 0));
		/*178*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step11.toString(),		"Sequencer Track 4 Step 11", track2_3_4Steps, 0));
		/*179*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step12.toString(),		"Sequencer Track 4 Step 12", track2_3_4Steps, 0));
		/*180*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step13.toString(),		"Sequencer Track 4 Step 13", track2_3_4Steps, 0));
		/*181*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step14.toString(),		"Sequencer Track 4 Step 14", track2_3_4Steps, 0));
		/*182*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step15.toString(),		"Sequencer Track 4 Step 15", track2_3_4Steps, 0));
		/*183*/layout.add(std::make_unique<AudioParameterChoice>	(ID::track4Step16.toString(),		"Sequencer Track 4 Step 16", track2_3_4Steps, 0));

		/*184*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar1 .toString(),			"Program Name Character 1",  nameChars, 77));
		/*185*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar2 .toString(),			"Program Name Character 2",  nameChars, 111));
		/*186*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar3 .toString(),			"Program Name Character 3",  nameChars, 112));
		/*187*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar4 .toString(),			"Program Name Character 4",  nameChars, 104));
		/*188*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar5 .toString(),			"Program Name Character 5",  nameChars, 111));
		/*189*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar6 .toString(),			"Program Name Character 6",  nameChars, 32));
		/*190*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar7 .toString(),			"Program Name Character 7",  nameChars, 71));
		/*191*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar8 .toString(),			"Program Name Character 8",  nameChars, 111));
		/*192*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar9 .toString(),			"Program Name Character 9",  nameChars, 111));
		/*193*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar10.toString(),			"Program Name Character 10", nameChars, 101));
		/*194*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar11.toString(),			"Program Name Character 11", nameChars, 121));
		/*195*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar12.toString(),			"Program Name Character 12", nameChars, 33));
		/*196*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar13.toString(),			"Program Name Character 13", nameChars, 33));
		/*197*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar14.toString(),			"Program Name Character 14", nameChars, 33));
		/*198*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar15.toString(),			"Program Name Character 15", nameChars, 33));
		/*199*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar16.toString(),			"Program Name Character 16", nameChars, 33));

		return layout;
	}

private:
	ValueConverters* valueConverters;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};