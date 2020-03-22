#pragma once

#include <JuceHeader.h>

#include "../helpers/ValueConverters.h"

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
		// First, create StringArrays that will be used to initialize choice parameters

		StringArray pitchNames;
		for (auto i = 0; i != 121; ++i)
			pitchNames.add(valueConverters.intToOscPitchString(i, true));

		StringArray fineTune;
		for (auto i = 0; i != 101; ++i)
			fineTune.add(valueConverters.intToFineTuneRange(i, true));

		StringArray oscShape;
		for (auto i = 0; i != 104; ++i)
		{
			oscShape.add(valueConverters.intToOscWaveShape(i));
		}

		// 0 = "Off"; 1 = "On"
		StringArray offOn;
		for (auto i = 0; i != 2; ++i)
			offOn.add(valueConverters.intToOffOn(i));

		StringArray glideMode;
		glideMode.add("Fixed Rate");
		glideMode.add("Fixed Rate Auto");
		glideMode.add("Fixed Time");
		glideMode.add("Fixed Time Auto");

		StringArray pitchBendRange;
		pitchBendRange.add("Off");
		pitchBendRange.add("+/-1 semitone");
		for (auto i = 2; i != 13; ++i)
		{
			pitchBendRange.add("+/-" + (String)i + " semitones");
		}

		StringArray notePriority;
		notePriority.add("Low Note");
		notePriority.add("Low Note (Re-trigger)");
		notePriority.add("High Note");
		notePriority.add("High Note (Re-trigger)");
		notePriority.add("Last Note Hit");
		notePriority.add("Last Note Hit (Re-trigger)");

		StringArray lpfFreq;
		for (auto i = 0; i != 165; ++i)
			lpfFreq.add(valueConverters.intToLPFfreq(i, true));

		// 0 = "2-Pole"; 1 = "4-Pole"
		StringArray lpfType;
		lpfType.add("2-Pole");
		lpfType.add("4-Pole");

		StringArray modAmount;
		for (auto i = 0; i != 255; ++i)
		{
			modAmount.add(valueConverters.intToPlusMinus127(i));
		}

		StringArray lfoFreq;
		for (auto i = 0; i != 167; ++i)
		{
			lfoFreq.add(valueConverters.intToLFOfreq(i, true));
		}


		// 0 = "Triangle"; 1 = "Reverse Sawtooth";
		// 2 = "Sawtooth" 3 = "Square"; 4 = "Random"
		StringArray lfoShape;
		lfoShape.add("Triangle");
		lfoShape.add("Reverse Sawtooth");
		lfoShape.add("Sawtooth");
		lfoShape.add("Square");
		lfoShape.add("Random");

		StringArray modDestination;
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

		StringArray modSource;
		/*0 */modSource.add("Off");
		/*1 */modSource.add("Sequencer Track 1");
		/*2 */modSource.add("Sequencer Track 2");
		/*3 */modSource.add("Sequencer Track 3");
		/*4 */modSource.add("Sequencer Track 4");
		/*5 */modSource.add("LFO 1");
		/*6 */modSource.add("LFO 2");
		/*7 */modSource.add("LFO 3");
		/*8 */modSource.add("LFO 4");
		/*9 */modSource.add("LPF Envelope");
		/*10*/modSource.add("VCA Envelope");
		/*11*/modSource.add("Envelope 3");
		/*12*/modSource.add("Pitch Bend");
		/*13*/modSource.add("Mod Wheel");
		/*14*/modSource.add("Pressure");
		/*15*/modSource.add("MIDI Breath");
		/*16*/modSource.add("MIDI Foot Pedal");
		/*17*/modSource.add("MIDI Expression");
		/*18*/modSource.add("Velocity");
		/*19*/modSource.add("Note Number");
		/*20*/modSource.add("Noise");
		/*21*/modSource.add("Audio In Env. Follower");
		/*22*/modSource.add("Audio In Peak Hold");

		// 0 = "Normal"; 1 = "Toggle"; 
		// 2 = "Audio In"
		StringArray pushItMode;
		/*0 */pushItMode.add("Normal");
		/*1 */pushItMode.add("Toggle");
		/*2 */pushItMode.add("Audio In");

		StringArray clockDivide;
		/*0 */clockDivide.add("Half Note");
		/*1 */clockDivide.add("Quarter Note");
		/*2 */clockDivide.add("8th Note");
		/*3 */clockDivide.add("8th Note 1/2 Swing");
		/*4 */clockDivide.add("8th Note Swing");
		/*5 */clockDivide.add("8th Note Triplets");
		/*6 */clockDivide.add("16th Note");
		/*7 */clockDivide.add("16th Note 1/2 Swing");
		/*8 */clockDivide.add("16th Note Swing");
		/*9 */clockDivide.add("16th Note Triplets");
		/*10*/clockDivide.add("32nd Note");
		/*11*/clockDivide.add("32nd Note Triplets");
		/*12*/clockDivide.add("64th Note Triplets");

		// 0 = "Up"; 1 = "Down";
		// 2 = "Up/Down" 3 = "Assign"
		StringArray arpegMode;
		arpegMode.add("Up");
		arpegMode.add("Down");
		arpegMode.add("Up/Down");
		arpegMode.add("Assign");

		// 0 = "Normal"; 1 = "Normal, No Reset";
		// 2 = "No Gate" 3 = "No Gate, No Reset";
		// 4 = "Key Step"; 5 = "Audio In"
		StringArray sequencerTrig;
		sequencerTrig.add("Normal");
		sequencerTrig.add("Normal, No Reset");
		sequencerTrig.add("No Gate");
		sequencerTrig.add("No Gate, No Reset");
		sequencerTrig.add("Key Step");
		sequencerTrig.add("Audio In");

		// A list of the names of all
		// the Mopho's parameters
		StringArray mophoParams;
		/*0  */mophoParams.add("Osc 1 Pitch");
		/*1  */mophoParams.add("Osc 1 Fine Tune");
		/*2  */mophoParams.add("Osc 1 Wave Shape");
		/*3  */mophoParams.add("Osc 1 Glide Rate");
		/*4  */mophoParams.add("Osc 1 Key Track");
		/*5  */mophoParams.add("Sub-Osc 1 Level");
		/*6  */mophoParams.add("Osc 2 Pitch");
		/*7  */mophoParams.add("Osc 2 Fine Tune");
		/*8  */mophoParams.add("Osc 2 Wave Shape");
		/*9  */mophoParams.add("Osc 2 Glide Rate");
		/*10 */mophoParams.add("Osc 2 Key Track");
		/*11 */mophoParams.add("Sub-Osc 2 Level");
		/*12 */mophoParams.add("Sync Osc 2 > 1");
		/*13 */mophoParams.add("Glide Mode");
		/*14 */mophoParams.add("Osc Slop");
		/*15 */mophoParams.add("Pitch Bend Range");
		/*16 */mophoParams.add("Note Priority");
		/*17 */mophoParams.add("Osc 1 & 2 Mix");
		/*18 */mophoParams.add("Noise Level");
		/*19 */mophoParams.add("Ext Audio In Level");
		/*20 */mophoParams.add("LPF Cutoff Freq");
		/*21 */mophoParams.add("LPF Resonance");
		/*22 */mophoParams.add("LPF Keyboard Amnt");
		/*23 */mophoParams.add("LPF FM (By Osc 1)");
		/*24 */mophoParams.add("LPF Type");
		/*25 */mophoParams.add("LPF Env Amount");
		/*26 */mophoParams.add("LPF Env Vel Amnt");
		/*27 */mophoParams.add("LPF Env Delay");
		/*28 */mophoParams.add("LPF Env Attack");
		/*29 */mophoParams.add("LPF Env Decay");
		/*30 */mophoParams.add("LPF Env Sustain");
		/*31 */mophoParams.add("LPF Env Release");
		/*32 */mophoParams.add("VCA Init Level");
		/*33 */mophoParams.add("VCA Env Amount");
		/*34 */mophoParams.add("VCA Env Vel Amnt");
		/*35 */mophoParams.add("VCA Env Delay");
		/*36 */mophoParams.add("VCA Env Attack");
		/*37 */mophoParams.add("VCA Env Decay");
		/*38 */mophoParams.add("VCA Env Sustain");
		/*39 */mophoParams.add("VCA Env Release");
		/*40 */mophoParams.add("Voice Volume");
		/*41 */mophoParams.add("LFO 1 Frequency");
		/*42 */mophoParams.add("LFO 1 Wave Shape");
		/*43 */mophoParams.add("LFO 1 Amount");
		/*44 */mophoParams.add("LFO 1 Mod Dest");
		/*45 */mophoParams.add("LFO 1 Key Sync");
		/*46 */mophoParams.add("LFO 2 Frequency");
		/*47 */mophoParams.add("LFO 2 Wave Shape");
		/*48 */mophoParams.add("LFO 2 Amount");
		/*49 */mophoParams.add("LFO 2 Mod Dest");
		/*50 */mophoParams.add("LFO 2 Key Sync");
		/*51 */mophoParams.add("LFO 3 Frequency");
		/*52 */mophoParams.add("LFO 3 Wave Shape");
		/*53 */mophoParams.add("LFO 3 Amount");
		/*54 */mophoParams.add("LFO 3 Mod Dest");
		/*55 */mophoParams.add("LFO 3 Key Sync");
		/*56 */mophoParams.add("LFO 4 Frequency");
		/*57 */mophoParams.add("LFO 4 Wave Shape");
		/*58 */mophoParams.add("LFO 4 Amount");
		/*59 */mophoParams.add("LFO 4 Mod Dest");
		/*60 */mophoParams.add("LFO 4 Key Sync");
		/*61 */mophoParams.add("Env 3 Mod Dest");
		/*62 */mophoParams.add("Env 3 Amount");
		/*63 */mophoParams.add("Env 3 Vel Amount");
		/*64 */mophoParams.add("Env 3 Delay");
		/*65 */mophoParams.add("Env 3 Attack");
		/*66 */mophoParams.add("Env 3 Decay");
		/*67 */mophoParams.add("Env 3 Sustain");
		/*68 */mophoParams.add("Env 3 Release");
		/*69 */mophoParams.add("Env 3 Repeat");
		/*70 */mophoParams.add("Mod 1 Source");
		/*71 */mophoParams.add("Mod 1 Amount");
		/*72 */mophoParams.add("Mod 1 Dest");
		/*73 */mophoParams.add("Mod 2 Source");
		/*74 */mophoParams.add("Mod 2 Amount");
		/*75 */mophoParams.add("Mod 2 Dest");
		/*76 */mophoParams.add("Mod 3 Source");
		/*77 */mophoParams.add("Mod 3 Amount");
		/*78 */mophoParams.add("Mod 3 Dest");
		/*79 */mophoParams.add("Mod 4 Source");
		/*80 */mophoParams.add("Mod 4 Amount");
		/*81 */mophoParams.add("Mod 4 Dest");
		/*82 */mophoParams.add("Mod Wheel Amnt");
		/*83 */mophoParams.add("Mod Wheel Dest");
		/*84 */mophoParams.add("Aftertouch Amnt");
		/*85 */mophoParams.add("Aftertouch Dest");
		/*86 */mophoParams.add("Breath Amnt");
		/*87 */mophoParams.add("Breath Dest");
		/*88 */mophoParams.add("Velocity Amnt");
		/*89 */mophoParams.add("Velocity Dest");
		/*90 */mophoParams.add("Foot Pedal Amnt");
		/*91 */mophoParams.add("Foot Pedal Dest");
		/*92 */mophoParams.add("Push It! Pitch");
		/*93 */mophoParams.add("Push It! Velocity");
		/*94 */mophoParams.add("Push It! Mode");
		/*95 */mophoParams.add("Clock Tempo");
		/*96 */mophoParams.add("Clock Divide");
		/*97 */mophoParams.add("Arpeg Mode");
		/*98 */mophoParams.add("Arpeg On/Off");
		/*99 */mophoParams.add("Seq Trigger");
		/*100*/mophoParams.add("Seq On/Off");
		/*101*/mophoParams.add("Seq Trk 1 Dest");
		/*102*/mophoParams.add("Seq Trk 2 Dest");
		/*103*/mophoParams.add("Seq Trk 3 Dest");
		/*104*/mophoParams.add("Seq Trk 4 Dest");
		/*105*/mophoParams.add("Assign Knob 1");
		/*106*/mophoParams.add("Assign Knob 2");
		/*107*/mophoParams.add("Assign Knob 3");
		/*108*/mophoParams.add("Assign Knob 4");
		/*109*/mophoParams.add("Unassigned");
		/*110*/mophoParams.add("Unassigned");
		/*111*/mophoParams.add("Unassigned");
		/*112*/mophoParams.add("Unassigned");
		/*113*/mophoParams.add("Unassigned");
		/*114*/mophoParams.add("Unassigned");
		/*115*/mophoParams.add("Unassigned");
		/*116*/mophoParams.add("Unassigned");
		/*117*/mophoParams.add("Unassigned");
		/*118*/mophoParams.add("Unassigned");
		/*119*/mophoParams.add("Unassigned");
		/*120*/mophoParams.add("Seq 1 Step 1");
		/*121*/mophoParams.add("Seq 1 Step 2");
		/*122*/mophoParams.add("Seq 1 Step 3");
		/*123*/mophoParams.add("Seq 1 Step 4");
		/*124*/mophoParams.add("Seq 1 Step 5");
		/*125*/mophoParams.add("Seq 1 Step 6");
		/*126*/mophoParams.add("Seq 1 Step 7");
		/*127*/mophoParams.add("Seq 1 Step 8");
		/*128*/mophoParams.add("Seq 1 Step 9");
		/*129*/mophoParams.add("Seq 1 Step 10");
		/*130*/mophoParams.add("Seq 1 Step 11");
		/*131*/mophoParams.add("Seq 1 Step 12");
		/*132*/mophoParams.add("Seq 1 Step 13");
		/*133*/mophoParams.add("Seq 1 Step 14");
		/*134*/mophoParams.add("Seq 1 Step 15");
		/*135*/mophoParams.add("Seq 1 Step 16");
		/*136*/mophoParams.add("Seq 2 Step 1");
		/*137*/mophoParams.add("Seq 2 Step 2");
		/*138*/mophoParams.add("Seq 2 Step 3");
		/*139*/mophoParams.add("Seq 2 Step 4");
		/*140*/mophoParams.add("Seq 2 Step 5");
		/*141*/mophoParams.add("Seq 2 Step 6");
		/*142*/mophoParams.add("Seq 2 Step 7");
		/*143*/mophoParams.add("Seq 2 Step 8");
		/*144*/mophoParams.add("Seq 2 Step 9");
		/*145*/mophoParams.add("Seq 2 Step 10");
		/*146*/mophoParams.add("Seq 2 Step 11");
		/*147*/mophoParams.add("Seq 2 Step 12");
		/*148*/mophoParams.add("Seq 2 Step 13");
		/*149*/mophoParams.add("Seq 2 Step 14");
		/*150*/mophoParams.add("Seq 2 Step 15");
		/*151*/mophoParams.add("Seq 2 Step 16");
		/*152*/mophoParams.add("Seq 3 Step 1");
		/*153*/mophoParams.add("Seq 3 Step 2");
		/*154*/mophoParams.add("Seq 3 Step 3");
		/*155*/mophoParams.add("Seq 3 Step 4");
		/*156*/mophoParams.add("Seq 3 Step 5");
		/*157*/mophoParams.add("Seq 3 Step 6");
		/*158*/mophoParams.add("Seq 3 Step 7");
		/*159*/mophoParams.add("Seq 3 Step 8");
		/*160*/mophoParams.add("Seq 3 Step 9");
		/*161*/mophoParams.add("Seq 3 Step 10");
		/*162*/mophoParams.add("Seq 3 Step 11");
		/*163*/mophoParams.add("Seq 3 Step 12");
		/*164*/mophoParams.add("Seq 3 Step 13");
		/*165*/mophoParams.add("Seq 3 Step 14");
		/*166*/mophoParams.add("Seq 3 Step 15");
		/*167*/mophoParams.add("Seq 3 Step 16");
		/*168*/mophoParams.add("Seq 4 Step 1");
		/*169*/mophoParams.add("Seq 4 Step 2");
		/*170*/mophoParams.add("Seq 4 Step 3");
		/*171*/mophoParams.add("Seq 4 Step 4");
		/*172*/mophoParams.add("Seq 4 Step 5");
		/*173*/mophoParams.add("Seq 4 Step 6");
		/*174*/mophoParams.add("Seq 4 Step 7");
		/*175*/mophoParams.add("Seq 4 Step 8");
		/*176*/mophoParams.add("Seq 4 Step 9");
		/*177*/mophoParams.add("Seq 4 Step 10");
		/*178*/mophoParams.add("Seq 4 Step 11");
		/*179*/mophoParams.add("Seq 4 Step 12");
		/*180*/mophoParams.add("Seq 4 Step 13");
		/*181*/mophoParams.add("Seq 4 Step 14");
		/*182*/mophoParams.add("Seq 4 Step 15");
		/*183*/mophoParams.add("Seq 4 Step 16");
		/*184*/mophoParams.add("Name Char 1");
		/*185*/mophoParams.add("Name Char 2");
		/*186*/mophoParams.add("Name Char 3");
		/*187*/mophoParams.add("Name Char 4");
		/*188*/mophoParams.add("Name Char 5");
		/*189*/mophoParams.add("Name Char 6");
		/*190*/mophoParams.add("Name Char 7");
		/*191*/mophoParams.add("Name Char 8");
		/*192*/mophoParams.add("Name Char 9");
		/*193*/mophoParams.add("Name Char 10");
		/*194*/mophoParams.add("Name Char 11");
		/*195*/mophoParams.add("Name Char 12");
		/*196*/mophoParams.add("Name Char 13");
		/*197*/mophoParams.add("Name Char 14");
		/*198*/mophoParams.add("Name Char 15");
		/*199*/mophoParams.add("Name Char 16");

		// 0..125; 126 = "Reset"
		StringArray seq2_3_4Steps;
		for (auto i = 0; i != 126; ++i)
		{
			seq2_3_4Steps.add((String)i);
		}
		seq2_3_4Steps.add("Reset");

		// 0..125; 126 = "Reset"; 127 = "Rest"
		StringArray seq1Steps{ seq2_3_4Steps };
		seq1Steps.add("Rest");
		
		StringArray nameChars;
		for (auto i = 0; i != 32; ++i)
			nameChars.add("");
		nameChars.add("Space");
		for (auto i = 33; i != 127; ++i)
			nameChars.add(std::string(1, char(i)));
		nameChars.add("Delete");

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
		/*84 */layout.add(std::make_unique<AudioParameterChoice>	(ID::aftertouchAmount.toString(),	"Aftertouch Amount", modAmount, 127));
		/*85 */layout.add(std::make_unique<AudioParameterChoice>	(ID::aftertouchDest.toString(),		"Aftertouch Destination", modDestination, 0));
		/*86 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathAmount.toString(),		"Breath Amount", modAmount, 127));
		/*87 */layout.add(std::make_unique<AudioParameterChoice>	(ID::breathDest.toString(),			"Breath Destination", modDestination, 0));
		/*88 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityAmount.toString(),		"Velocity Amount", modAmount, 127));
		/*89 */layout.add(std::make_unique<AudioParameterChoice>	(ID::velocityDest.toString(),		"Velocity Destination", modDestination, 0));
		/*90 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalAmount.toString(),	"Foot Pedal Amount", modAmount, 127));
		/*91 */layout.add(std::make_unique<AudioParameterChoice>	(ID::footPedalDest.toString(),		"Foot Pedal Destination", modDestination, 0));

		/*92 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItPitch.toString(),		"Push It! Switch Pitch", pitchNames, 24));
		/*93 */layout.add(std::make_unique<AudioParameterInt>		(ID::pushItVelocity.toString(),		"Push It! Switch Velocity", 0, 127, 100));
		/*94 */layout.add(std::make_unique<AudioParameterChoice>	(ID::pushItMode.toString(),			"Push It! Switch Mode", pushItMode, 0));

		/*95 */layout.add(std::make_unique<AudioParameterInt>		(ID::clockTempo.toString(),			"Clock Tempo (BPM)", 30, 250, 120));
		/*96 */layout.add(std::make_unique<AudioParameterChoice>	(ID::clockDivide.toString(),		"Clock Divide", clockDivide, 2));

		/*97 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegMode.toString(),			"Arpeggiator Mode", arpegMode, 0));
		/*98 */layout.add(std::make_unique<AudioParameterChoice>	(ID::arpegOnOff.toString(),			"Arpeggiator On/Off", offOn, 0));

		/*99 */layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerTrig.toString(),		"Sequencer Trigger", sequencerTrig, 0));
		/*100*/layout.add(std::make_unique<AudioParameterChoice>	(ID::sequencerOnOff.toString(),		"Sequencer On/Off", offOn, 0));
		/*101*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack1Dest.toString(),		"Sequencer Track 1 Destination", modDestination, 1));
		/*102*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack2Dest.toString(),		"Sequencer Track 2 Destination", modDestination, 2));
		/*103*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack3Dest.toString(),		"Sequencer Track 3 Destination", modDestination, 9));
		/*104*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seqTrack4Dest.toString(),		"Sequencer Track 4 Destination", modDestination, 0));

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
		
		/*120*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step01.toString(),			"Sequencer Track 1 Step 1",  seq1Steps, 0));
		/*121*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step02.toString(),			"Sequencer Track 1 Step 2",  seq1Steps, 0));
		/*122*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step03.toString(),			"Sequencer Track 1 Step 3",  seq1Steps, 0));
		/*123*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step04.toString(),			"Sequencer Track 1 Step 4",  seq1Steps, 0));
		/*124*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step05.toString(),			"Sequencer Track 1 Step 5",  seq1Steps, 0));
		/*125*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step06.toString(),			"Sequencer Track 1 Step 6",  seq1Steps, 0));
		/*126*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step07.toString(),			"Sequencer Track 1 Step 7",  seq1Steps, 0));
		/*127*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step08.toString(),			"Sequencer Track 1 Step 8",  seq1Steps, 0));
		/*128*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step09.toString(),			"Sequencer Track 1 Step 9",  seq1Steps, 0));
		/*129*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step10.toString(),			"Sequencer Track 1 Step 10", seq1Steps, 0));
		/*130*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step11.toString(),			"Sequencer Track 1 Step 11", seq1Steps, 0));
		/*131*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step12.toString(),			"Sequencer Track 1 Step 12", seq1Steps, 0));
		/*132*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step13.toString(),			"Sequencer Track 1 Step 13", seq1Steps, 0));
		/*133*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step14.toString(),			"Sequencer Track 1 Step 14", seq1Steps, 0));
		/*134*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step15.toString(),			"Sequencer Track 1 Step 15", seq1Steps, 0));
		/*135*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq1Step16.toString(),			"Sequencer Track 1 Step 16", seq1Steps, 0));
		
		/*136*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step01.toString(),			"Sequencer Track 2 Step 1",  seq2_3_4Steps, 0));
		/*137*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step02.toString(),			"Sequencer Track 2 Step 2",  seq2_3_4Steps, 0));
		/*138*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step03.toString(),			"Sequencer Track 2 Step 3",  seq2_3_4Steps, 0));
		/*139*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step04.toString(),			"Sequencer Track 2 Step 4",  seq2_3_4Steps, 0));
		/*140*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step05.toString(),			"Sequencer Track 2 Step 5",  seq2_3_4Steps, 0));
		/*141*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step06.toString(),			"Sequencer Track 2 Step 6",  seq2_3_4Steps, 0));
		/*142*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step07.toString(),			"Sequencer Track 2 Step 7",  seq2_3_4Steps, 0));
		/*143*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step08.toString(),			"Sequencer Track 2 Step 8",  seq2_3_4Steps, 0));
		/*144*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step09.toString(),			"Sequencer Track 2 Step 9",  seq2_3_4Steps, 0));
		/*145*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step10.toString(),			"Sequencer Track 2 Step 10", seq2_3_4Steps, 0));
		/*146*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step11.toString(),			"Sequencer Track 2 Step 11", seq2_3_4Steps, 0));
		/*147*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step12.toString(),			"Sequencer Track 2 Step 12", seq2_3_4Steps, 0));
		/*148*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step13.toString(),			"Sequencer Track 2 Step 13", seq2_3_4Steps, 0));
		/*149*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step14.toString(),			"Sequencer Track 2 Step 14", seq2_3_4Steps, 0));
		/*150*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step15.toString(),			"Sequencer Track 2 Step 15", seq2_3_4Steps, 0));
		/*151*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq2Step16.toString(),			"Sequencer Track 2 Step 16", seq2_3_4Steps, 0));
		
		/*152*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step01.toString(),			"Sequencer Track 3 Step 1",  seq2_3_4Steps, 0));
		/*153*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step02.toString(),			"Sequencer Track 3 Step 2",  seq2_3_4Steps, 0));
		/*154*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step03.toString(),			"Sequencer Track 3 Step 3",  seq2_3_4Steps, 0));
		/*155*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step04.toString(),			"Sequencer Track 3 Step 4",  seq2_3_4Steps, 0));
		/*156*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step05.toString(),			"Sequencer Track 3 Step 5",  seq2_3_4Steps, 0));
		/*157*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step06.toString(),			"Sequencer Track 3 Step 6",  seq2_3_4Steps, 0));
		/*158*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step07.toString(),			"Sequencer Track 3 Step 7",  seq2_3_4Steps, 0));
		/*159*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step08.toString(),			"Sequencer Track 3 Step 8",  seq2_3_4Steps, 0));
		/*160*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step09.toString(),			"Sequencer Track 3 Step 9",  seq2_3_4Steps, 0));
		/*161*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step10.toString(),			"Sequencer Track 3 Step 10", seq2_3_4Steps, 0));
		/*162*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step11.toString(),			"Sequencer Track 3 Step 11", seq2_3_4Steps, 0));
		/*163*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step12.toString(),			"Sequencer Track 3 Step 12", seq2_3_4Steps, 0));
		/*164*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step13.toString(),			"Sequencer Track 3 Step 13", seq2_3_4Steps, 0));
		/*165*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step14.toString(),			"Sequencer Track 3 Step 14", seq2_3_4Steps, 0));
		/*166*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step15.toString(),			"Sequencer Track 3 Step 15", seq2_3_4Steps, 0));
		/*167*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq3Step16.toString(),			"Sequencer Track 3 Step 16", seq2_3_4Steps, 0));
		
		/*168*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step01.toString(),			"Sequencer Track 4 Step 1",  seq2_3_4Steps, 0));
		/*169*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step02.toString(),			"Sequencer Track 4 Step 2",  seq2_3_4Steps, 0));
		/*170*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step03.toString(),			"Sequencer Track 4 Step 3",  seq2_3_4Steps, 0));
		/*171*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step04.toString(),			"Sequencer Track 4 Step 4",  seq2_3_4Steps, 0));
		/*172*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step05.toString(),			"Sequencer Track 4 Step 5",  seq2_3_4Steps, 0));
		/*173*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step06.toString(),			"Sequencer Track 4 Step 6",  seq2_3_4Steps, 0));
		/*174*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step07.toString(),			"Sequencer Track 4 Step 7",  seq2_3_4Steps, 0));
		/*175*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step08.toString(),			"Sequencer Track 4 Step 8",  seq2_3_4Steps, 0));
		/*176*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step09.toString(),			"Sequencer Track 4 Step 9",  seq2_3_4Steps, 0));
		/*177*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step10.toString(),			"Sequencer Track 4 Step 10", seq2_3_4Steps, 0));
		/*178*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step11.toString(),			"Sequencer Track 4 Step 11", seq2_3_4Steps, 0));
		/*179*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step12.toString(),			"Sequencer Track 4 Step 12", seq2_3_4Steps, 0));
		/*180*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step13.toString(),			"Sequencer Track 4 Step 13", seq2_3_4Steps, 0));
		/*181*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step14.toString(),			"Sequencer Track 4 Step 14", seq2_3_4Steps, 0));
		/*182*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step15.toString(),			"Sequencer Track 4 Step 15", seq2_3_4Steps, 0));
		/*183*/layout.add(std::make_unique<AudioParameterChoice>	(ID::seq4Step16.toString(),			"Sequencer Track 4 Step 16", seq2_3_4Steps, 0));

		/*184*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar01.toString(),			"Program Name Character 1",  nameChars, 77));
		/*185*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar02.toString(),			"Program Name Character 2",  nameChars, 111));
		/*186*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar03.toString(),			"Program Name Character 3",  nameChars, 112));
		/*187*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar04.toString(),			"Program Name Character 4",  nameChars, 104));
		/*188*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar05.toString(),			"Program Name Character 5",  nameChars, 111));
		/*189*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar06.toString(),			"Program Name Character 6",  nameChars, 32));
		/*190*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar07.toString(),			"Program Name Character 7",  nameChars, 71));
		/*191*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar08.toString(),			"Program Name Character 8",  nameChars, 111));
		/*192*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar09.toString(),			"Program Name Character 9",  nameChars, 111));
		/*193*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar10.toString(),			"Program Name Character 10", nameChars, 101));
		/*194*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar11.toString(),			"Program Name Character 11", nameChars, 121));
		/*195*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar12.toString(),			"Program Name Character 12", nameChars, 33));
		/*196*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar13.toString(),			"Program Name Character 13", nameChars, 33));
		/*197*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar14.toString(),			"Program Name Character 14", nameChars, 33));
		/*198*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar15.toString(),			"Program Name Character 15", nameChars, 33));
		/*199*/layout.add(std::make_unique<AudioParameterChoice>	(ID::nameChar16.toString(),			"Program Name Character 16", nameChars, 33));

		return layout;
	}

	// In many cases, the index number a parameter has when sending an 
	// NRPN controller message to the hardware differs from the index number
	// the parameter has in the plugin's AudioProcessorValueTreeState,
	// the program buffer dumps, and the edit buffer dumps. Use this function
	// to get the specified parameter's NRPN index number. A few parameters
	// that are unused by the Mopho will return -1
	int getNRPN(int parameterIndex)
	{
		switch (parameterIndex)
		{
		case 5  : return 114;
		case 6  : return 5  ;
		case 7  : return 6  ;
		case 8  : return 7  ;
		case 9  : return 8  ;
		case 10 : return 9  ;
		case 11 : return 115;
		case 12 : return 10 ;
		case 13 : return 11 ;
		case 14 : return 12 ;
		case 15 : return 93 ;
		case 16 : return 96 ;
		case 17 : return 13 ;
		case 18 : return 14 ;
		case 19 : return 116;
		case 20 : return 15 ;
		case 21 : return 16 ;
		case 22 : return 17 ;
		case 23 : return 18 ;
		case 24 : return 19 ;
		case 25 : return 20 ;
		case 26 : return 21 ;
		case 27 : return 22 ;
		case 28 : return 23 ;
		case 29 : return 24 ;
		case 30 : return 25 ;
		case 31 : return 26 ;
		case 32 : return 27 ;
		case 33 : return 30 ;
		case 34 : return 31 ;
		case 35 : return 32 ;
		case 36 : return 33 ;
		case 37 : return 34 ;
		case 38 : return 35 ;
		case 39 : return 36 ;
		case 40 : return 29 ;
		case 41 : return 37 ;
		case 42 : return 38 ;
		case 43 : return 39 ;
		case 44 : return 40 ;
		case 45 : return 41 ;
		case 46 : return 42 ;
		case 47 : return 43 ;
		case 48 : return 44 ;
		case 49 : return 45 ;
		case 50 : return 46 ;
		case 51 : return 47 ;
		case 52 : return 48 ;
		case 53 : return 49 ;
		case 54 : return 50 ;
		case 55 : return 51 ;
		case 56 : return 52 ;
		case 57 : return 53 ;
		case 58 : return 54 ;
		case 59 : return 55 ;
		case 60 : return 56 ;
		case 61 : return 57 ;
		case 62 : return 58 ;
		case 63 : return 59 ;
		case 64 : return 60 ;
		case 65 : return 61 ;
		case 66 : return 62 ;
		case 67 : return 63 ;
		case 68 : return 64 ;
		case 69 : return 98 ;
		case 70 : return 65 ;
		case 71 : return 66 ;
		case 72 : return 67 ;
		case 73 : return 68 ;
		case 74 : return 69 ;
		case 75 : return 70 ;
		case 76 : return 71 ;
		case 77 : return 72 ;
		case 78 : return 73 ;
		case 79 : return 74 ;
		case 80 : return 75 ;
		case 81 : return 76 ;
		case 82 : return 81 ;
		case 83 : return 82 ;
		case 84 : return 83 ;
		case 85 : return 84 ;
		case 86 : return 85 ;
		case 87 : return 86 ;
		case 88 : return 87 ;
		case 89 : return 88 ;
		case 90 : return 89 ;
		case 91 : return 90 ;
		case 92 : return 111;
		case 93 : return 112;
		case 94 : return 113;
		case 95 : return 91 ;
		case 96 : return 92 ;
		case 97 : return 97 ;
		case 98 : return 100;
		case 99 : return 94 ;
		case 100: return 101;
		case 101: return 77 ;
		case 102: return 78 ;
		case 103: return 79 ;
		case 104: return 80 ;
		case 109: return -1 ;
		case 110: return -1 ;
		case 111: return -1 ;
		case 112: return -1 ;
		case 113: return -1 ;
		case 114: return -1 ;
		case 115: return -1 ;
		case 116: return -1 ;
		case 117: return -1 ;
		case 118: return -1 ;
		case 119: return -1 ;
		default: return parameterIndex;
		}
	}

private:
	ValueConverters valueConverters;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PublicParameters)
};