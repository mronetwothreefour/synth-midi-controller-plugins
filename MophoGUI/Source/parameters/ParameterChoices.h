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

	StringArray modSource;

	// 0 = "Normal"; 1 = "Toggle"; 
	// 2 = "Audio In"
	StringArray pushItMode;

	StringArray clockDivide;

	// 0 = "Up"; 1 = "Down";
	// 2 = "Up/Down" 3 = "Assign"
	StringArray arpegMode;

	// 0 = "Normal"; 1 = "Normal, No Reset";
	// 2 = "No Gate" 3 = "No Gate, No Reset";
	// 4 = "Key Step"; 5 = "Audio In"
	StringArray sequencerTrig;

	// A list of the names of all
	// the Mopho's parameters
	StringArray mophoParams;

	// 0..125; 126 = "Reset"; 127 = "Rest"
	StringArray seq1Steps;

	// 0..125; 126 = "Reset"
	StringArray seq2_3_4Steps;

	StringArray nameChars;

	Choices()
	{
		// initialize pitchNames
		for (auto i = 0; i != 121; ++i)
		{
			auto noteNum{ i % 12 };
			auto octaveNum{ i / 12 };
			switch (noteNum)
			{
			case 0: pitchNames.add("C" + (String)octaveNum); break;
			case 1: pitchNames.add("C#" + (String)octaveNum); break;
			case 2: pitchNames.add("D" + (String)octaveNum); break;
			case 3: pitchNames.add("D#" + (String)octaveNum); break;
			case 4: pitchNames.add("E" + (String)octaveNum); break;
			case 5: pitchNames.add("F" + (String)octaveNum); break;
			case 6: pitchNames.add("F#" + (String)octaveNum); break;
			case 7: pitchNames.add("G" + (String)octaveNum); break;
			case 8: pitchNames.add("G#" + (String)octaveNum); break;
			case 9: pitchNames.add("A" + (String)octaveNum); break;
			case 10: pitchNames.add("A#" + (String)octaveNum); break;
			case 11: pitchNames.add("B" + (String)octaveNum); break;
			default: break;
			}
		}

		// initialize fineTune
		for (auto i = 0; i != 49; ++i)
		{
			fineTune.add((String)(i - 50) + " cents");
		}
		fineTune.add("-1 cent");
		fineTune.add("Centered");
		fineTune.add("+1 cent");
		for (auto i = 52; i != 101; ++i)
		{
			fineTune.add("+" + (String)(i - 50) + " cents");
		}

		// initialize oscShape
		oscShape.add("Off");
		oscShape.add("Sawtooth");
		oscShape.add("Triangle");
		oscShape.add("Saw/Tri Mix");
		for (auto i = 0; i != 100; ++i)
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
		for (auto i = 2; i != 13; ++i)
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
		for (auto i = 0; i != 165; ++i)
		{
			auto noteNum{ i % 12 };
			auto octaveNum{ i / 12 };
			switch (noteNum)
			{
			case 0: lpfFreq.add("C" + (String)octaveNum); break;
			case 1: lpfFreq.add("C#" + (String)octaveNum); break;
			case 2: lpfFreq.add("D" + (String)octaveNum); break;
			case 3: lpfFreq.add("D#" + (String)octaveNum); break;
			case 4: lpfFreq.add("E" + (String)octaveNum); break;
			case 5: lpfFreq.add("F" + (String)octaveNum); break;
			case 6: lpfFreq.add("F#" + (String)octaveNum); break;
			case 7: lpfFreq.add("G" + (String)octaveNum); break;
			case 8: lpfFreq.add("G#" + (String)octaveNum); break;
			case 9: lpfFreq.add("A" + (String)octaveNum); break;
			case 10: lpfFreq.add("A#" + (String)octaveNum); break;
			case 11: lpfFreq.add("B" + (String)octaveNum); break;
			default: break;
			}
		}

		// initialize lpfType
		lpfType.add("2-Pole");
		lpfType.add("4-Pole");

		// initialize modAmnt
		for (auto i = 0; i != 255; ++i)
		{
			if (i < 128) modAmount.add((String)(i - 127));
			else modAmount.add("+" + (String)(i - 127));
		}

		// initialize lfoFreq
		for (auto i = 0; i != 151; ++i)
		{
			if (i < 90) lfoFreq.add("Un-synced " + (String)i);
			if (i > 89)
			{
				auto noteNum{ (i - 90) % 12 };
				auto octaveNum{ (i - 90) / 12 };
				switch (noteNum)
				{
				case 0: lfoFreq.add("Pitch Freq. C" + (String)octaveNum); break;
				case 1: lfoFreq.add("Pitch Freq. C#" + (String)octaveNum); break;
				case 2: lfoFreq.add("Pitch Freq. D" + (String)octaveNum); break;
				case 3: lfoFreq.add("Pitch Freq. D#" + (String)octaveNum); break;
				case 4: lfoFreq.add("Pitch Freq. E" + (String)octaveNum); break;
				case 5: lfoFreq.add("Pitch Freq. F" + (String)octaveNum); break;
				case 6: lfoFreq.add("Pitch Freq. F#" + (String)octaveNum); break;
				case 7: lfoFreq.add("Pitch Freq. G" + (String)octaveNum); break;
				case 8: lfoFreq.add("Pitch Freq. G#" + (String)octaveNum); break;
				case 9: lfoFreq.add("Pitch Freq. A" + (String)octaveNum); break;
				case 10: lfoFreq.add("Pitch Freq. A#" + (String)octaveNum); break;
				case 11: lfoFreq.add("Pitch Freq. B" + (String)octaveNum); break;
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

		// initiaiize modSource
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

		// initiaiize pushItMode
		/*0 */pushItMode.add("Normal");
		/*1 */pushItMode.add("Toggle");
		/*2 */pushItMode.add("Audio In");

		// initiaiize clockDivide
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

		// initialize arpegMode
		arpegMode.add("Up");
		arpegMode.add("Down");
		arpegMode.add("Up/Down");
		arpegMode.add("Assign");

		// initialize sequencerTrig
		sequencerTrig.add("Normal");
		sequencerTrig.add("Normal, No Reset");
		sequencerTrig.add("No Gate");
		sequencerTrig.add("No Gate, No Reset");
		sequencerTrig.add("Key Step");
		sequencerTrig.add("Audio In");

		// initialize MophoParams
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

		// initialize seq1Steps and seq2_3_4Steps
		for (auto i = 0; i != 126; ++i)
		{
			seq1Steps.add((String)i);
			seq2_3_4Steps.add((String)i);
		}
		seq1Steps.add("Reset");
		seq2_3_4Steps.add("Reset");
		seq1Steps.add("Rest");

		// initialize nameChars
		for (auto i = 0; i != 32; ++i)
			nameChars.add("");
		/*32 */nameChars.add("Space");
		/*33 */nameChars.add("!");
		/*34 */nameChars.add("\"");
		/*35 */nameChars.add("#");
		/*36 */nameChars.add("$");
		/*37 */nameChars.add("%");
		/*38 */nameChars.add("&");
		/*39 */nameChars.add("'");
		/*40 */nameChars.add("(");
		/*41 */nameChars.add(")");
		/*42 */nameChars.add("*");
		/*43 */nameChars.add("+");
		/*44 */nameChars.add(",");
		/*45 */nameChars.add("-");
		/*46 */nameChars.add(".");
		/*47 */nameChars.add("/");
		/*48 */nameChars.add("0");
		/*49 */nameChars.add("1");
		/*50 */nameChars.add("2");
		/*51 */nameChars.add("3");
		/*52 */nameChars.add("4");
		/*53 */nameChars.add("5");
		/*54 */nameChars.add("6");
		/*55 */nameChars.add("7");
		/*56 */nameChars.add("8");
		/*57 */nameChars.add("9");
		/*58 */nameChars.add(":");
		/*59 */nameChars.add(";");
		/*60 */nameChars.add("<");
		/*61 */nameChars.add("=");
		/*62 */nameChars.add(">");
		/*63 */nameChars.add("?");
		/*64 */nameChars.add("@");
		/*65 */nameChars.add("A");
		/*66 */nameChars.add("B");
		/*67 */nameChars.add("C");
		/*68 */nameChars.add("D");
		/*69 */nameChars.add("E");
		/*70 */nameChars.add("F");
		/*71 */nameChars.add("G");
		/*72 */nameChars.add("H");
		/*73 */nameChars.add("I");
		/*74 */nameChars.add("J");
		/*75 */nameChars.add("K");
		/*76 */nameChars.add("L");
		/*77 */nameChars.add("M");
		/*78 */nameChars.add("N");
		/*79 */nameChars.add("O");
		/*80 */nameChars.add("P");
		/*81 */nameChars.add("Q");
		/*82 */nameChars.add("R");
		/*83 */nameChars.add("S");
		/*84 */nameChars.add("T");
		/*85 */nameChars.add("U");
		/*86 */nameChars.add("V");
		/*87 */nameChars.add("W");
		/*88 */nameChars.add("X");
		/*89 */nameChars.add("Y");
		/*90 */nameChars.add("Z");
		/*91 */nameChars.add("[");
		/*92 */nameChars.add("\\");
		/*93 */nameChars.add("]");
		/*94 */nameChars.add("^");
		/*95 */nameChars.add("_");
		/*96 */nameChars.add("`");
		/*97 */nameChars.add("a");
		/*98 */nameChars.add("b");
		/*99 */nameChars.add("c");
		/*100*/nameChars.add("d");
		/*101*/nameChars.add("e");
		/*102*/nameChars.add("f");
		/*103*/nameChars.add("g");
		/*104*/nameChars.add("h");
		/*105*/nameChars.add("i");
		/*106*/nameChars.add("j");
		/*107*/nameChars.add("k");
		/*108*/nameChars.add("l");
		/*109*/nameChars.add("m");
		/*110*/nameChars.add("n");
		/*111*/nameChars.add("o");
		/*112*/nameChars.add("p");
		/*113*/nameChars.add("q");
		/*114*/nameChars.add("r");
		/*115*/nameChars.add("s");
		/*116*/nameChars.add("t");
		/*117*/nameChars.add("u");
		/*118*/nameChars.add("v");
		/*119*/nameChars.add("w");
		/*120*/nameChars.add("x");
		/*121*/nameChars.add("y");
		/*122*/nameChars.add("z");
		/*123*/nameChars.add("{");
		/*124*/nameChars.add("|");
		/*125*/nameChars.add("}");
		/*126*/nameChars.add("~");
		/*127*/nameChars.add("Delete");
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