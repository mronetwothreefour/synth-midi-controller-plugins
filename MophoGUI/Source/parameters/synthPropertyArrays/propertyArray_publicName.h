#pragma once

#include <JuceHeader.h>

// Takes an Array<String> and fills it with public names
// for each of the hardware synthesizer's parameters (this
// is the name of the property presented to the VST3 host)
struct PublicNameArrayFactory
{
	static void fillArray(Array<String>& publicNameArray)
	{
		/*0  */ publicNameArray.add("Oscillator 1 Pitch"					);
		/*1  */ publicNameArray.add("Oscillator 1 Fine Tune"				);
		/*2  */ publicNameArray.add("Oscillator 1 Wave Shape"				);
		/*3  */ publicNameArray.add("Oscillator 1 Glide Rate"				);
		/*4  */ publicNameArray.add("Oscillator 1 Keyboard Track On/Off"	);
		/*5  */ publicNameArray.add("Sub-Oscillator 1 Level"				);
		/*6  */ publicNameArray.add("Oscillator 2 Pitch"					);
		/*7  */ publicNameArray.add("Oscillator 2 Fine Tune"				);
		/*8  */ publicNameArray.add("Oscillator 2 Wave Shape"				);
		/*9  */ publicNameArray.add("Oscillator 2 Glide Rate"				);
		/*10 */ publicNameArray.add("Oscillator 2 Keyboard Track On/Off"	);
		/*11 */ publicNameArray.add("Sub-Oscillator 2 Level"				);
		/*12 */ publicNameArray.add("Sync Osc. 2 to Osc. 1 On/Off"			);
		/*13 */ publicNameArray.add("Glide Mode"							);
		/*14 */ publicNameArray.add("Oscillator Slop"						);
		/*15 */ publicNameArray.add("Pitch Bend Range"						);
		/*16 */ publicNameArray.add("Note Priority"							);
		/*17 */ publicNameArray.add("Oscillator 1 & 2 Mix"					);
		/*18 */ publicNameArray.add("Noise Level"							);
		/*19 */ publicNameArray.add("External Audio Input Level"			);
		/*20 */ publicNameArray.add("LPF Cutoff Frequency"					);
		/*21 */ publicNameArray.add("LPF Resonance"							);
		/*22 */ publicNameArray.add("LPF Keyboard Amount"					);
		/*23 */ publicNameArray.add("LPF FM (By Oscillator 1)"				);
		/*24 */ publicNameArray.add("LPF Type"								);
		/*25 */ publicNameArray.add("LPF Envelope Amount"					);
		/*26 */ publicNameArray.add("LPF Envelope Velocity Amount"			);
		/*27 */ publicNameArray.add("LPF Envelope Delay"					);
		/*28 */ publicNameArray.add("LPF Envelope Attack"					);
		/*29 */ publicNameArray.add("LPF Envelope Decay"					);
		/*30 */ publicNameArray.add("LPF Envelope Sustain"					);
		/*31 */ publicNameArray.add("LPF Envelope Release"					);
		/*32 */ publicNameArray.add("VCA Baseline Level"					);
		/*33 */ publicNameArray.add("VCA Envelope Amount"					);
		/*34 */ publicNameArray.add("VCA Envelope Velocity Amount"			);
		/*35 */ publicNameArray.add("VCA Envelope Delay"					);
		/*36 */ publicNameArray.add("VCA Envelope Attack"					);
		/*37 */ publicNameArray.add("VCA Envelope Decay"					);
		/*38 */ publicNameArray.add("VCA Envelope Sustain"					);
		/*39 */ publicNameArray.add("VCA Envelope Release"					);
		/*40 */ publicNameArray.add("Program Volume"						);
		/*41 */ publicNameArray.add("LFO 1 Frequency"						);
		/*42 */ publicNameArray.add("LFO 1 Wave Shape"						);
		/*43 */ publicNameArray.add("LFO 1 Amount"							);
		/*44 */ publicNameArray.add("LFO 1 Modulation Destination"			);
		/*45 */ publicNameArray.add("LFO 1 Key Sync On/Off"					);
		/*46 */ publicNameArray.add("LFO 2 Frequency"						);
		/*47 */ publicNameArray.add("LFO 2 Wave Shape"						);
		/*48 */ publicNameArray.add("LFO 2 Amount"							);
		/*49 */ publicNameArray.add("LFO 2 Modulation Destination"			);
		/*50 */ publicNameArray.add("LFO 2 Key Sync On/Off"					);
		/*51 */ publicNameArray.add("LFO 3 Frequency"						);
		/*52 */ publicNameArray.add("LFO 3 Wave Shape"						);
		/*53 */ publicNameArray.add("LFO 3 Amount"							);
		/*54 */ publicNameArray.add("LFO 3 Modulation Destination"			);
		/*55 */ publicNameArray.add("LFO 3 Key Sync On/Off"					);
		/*56 */ publicNameArray.add("LFO 4 Frequency"						);
		/*57 */ publicNameArray.add("LFO 4 Wave Shape"						);
		/*58 */ publicNameArray.add("LFO 4 Amount"							);
		/*59 */ publicNameArray.add("LFO 4 Modulation Destination"			);
		/*60 */ publicNameArray.add("LFO 4 Key Sync On/Off"					);
		/*61 */ publicNameArray.add("Envelope 3 Modulation Destination"		);
		/*62 */ publicNameArray.add("Envelope 3 Amount"						);
		/*63 */ publicNameArray.add("Envelope 3 Velocity Amount"			);
		/*64 */ publicNameArray.add("Envelope 3 Delay"						);
		/*65 */ publicNameArray.add("Envelope 3 Attack"						);
		/*66 */ publicNameArray.add("Envelope 3 Decay"						);
		/*67 */ publicNameArray.add("Envelope 3 Sustain"					);
		/*68 */ publicNameArray.add("Envelope 3 Release"					);
		/*69 */ publicNameArray.add("Envelope 3 Repeat On/Off"				);
		/*70 */ publicNameArray.add("Modulator 1 Source"					);
		/*71 */ publicNameArray.add("Modulator 1 Amount"					);
		/*72 */ publicNameArray.add("Modulator 1 Destination"				);
		/*73 */ publicNameArray.add("Modulator 2 Source"					);
		/*74 */ publicNameArray.add("Modulator 2 Amount"					);
		/*75 */ publicNameArray.add("Modulator 2 Destination"				);
		/*76 */ publicNameArray.add("Modulator 3 Source"					);
		/*77 */ publicNameArray.add("Modulator 3 Amount"					);
		/*78 */ publicNameArray.add("Modulator 3 Destination"				);
		/*79 */ publicNameArray.add("Modulator 4 Source"					);
		/*80 */ publicNameArray.add("Modulator 4 Amount"					);
		/*81 */ publicNameArray.add("Modulator 4 Destination"				);
		/*82 */ publicNameArray.add("Modulation Wheel Amount"				);
		/*83 */ publicNameArray.add("Modulation Wheel Destination"			);
		/*84 */ publicNameArray.add("Pressure Amount"						);
		/*85 */ publicNameArray.add("Pressure Destination"					);
		/*86 */ publicNameArray.add("Breath Amount"							);
		/*87 */ publicNameArray.add("Breath Destination"					);
		/*88 */ publicNameArray.add("Velocity Amount"						);
		/*89 */ publicNameArray.add("Velocity Destination"					);
		/*90 */ publicNameArray.add("Foot Pedal Amount"						);
		/*91 */ publicNameArray.add("Foot Pedal Destination"				);
		/*92 */ publicNameArray.add("Push It! Switch Pitch"					);
		/*93 */ publicNameArray.add("Push It! Switch Velocity"				);
		/*94 */ publicNameArray.add("Push It! Switch Mode"					);
		/*95 */ publicNameArray.add("Clock Tempo"							);
		/*96 */ publicNameArray.add("Clock Divide"							);
		/*97 */ publicNameArray.add("Arpeggiator Mode"						);
		/*98 */ publicNameArray.add("Arpeggiator On/Off"					);
		/*99 */ publicNameArray.add("Sequencer Trigger Mode"				);
		/*100*/ publicNameArray.add("Sequencer On/Off"						);
		/*101*/ publicNameArray.add("Sequence Track 1 Destination"			);
		/*102*/ publicNameArray.add("Sequence Track 2 Destination"			);
		/*103*/ publicNameArray.add("Sequence Track 3 Destination"			);
		/*104*/ publicNameArray.add("Sequence Track 4 Destination"			);
		/*105*/ publicNameArray.add("Assign Parameter to Knob 1"			);
		/*106*/ publicNameArray.add("Assign Parameter to Knob 2"			);
		/*107*/ publicNameArray.add("Assign Parameter to Knob 3"			);
		/*108*/ publicNameArray.add("Assign Parameter to Knob 4"			);
		/*109*/ publicNameArray.add("Unassigned"							);
		/*110*/ publicNameArray.add("Unassigned"							);
		/*111*/ publicNameArray.add("Unassigned"							);
		/*112*/ publicNameArray.add("Unassigned"							);
		/*113*/ publicNameArray.add("Unassigned"							);
		/*114*/ publicNameArray.add("Unassigned"							);
		/*115*/ publicNameArray.add("Unassigned"							);
		/*116*/ publicNameArray.add("Unassigned"							);
		/*117*/ publicNameArray.add("Unassigned"							);
		/*118*/ publicNameArray.add("Unassigned"							);
		/*119*/ publicNameArray.add("Unassigned"							);
		/*120*/ publicNameArray.add("Sequencer Track 1 Step 1" 				);
		/*121*/ publicNameArray.add("Sequencer Track 1 Step 2" 				);
		/*122*/ publicNameArray.add("Sequencer Track 1 Step 3" 				);
		/*123*/ publicNameArray.add("Sequencer Track 1 Step 4" 				);
		/*124*/ publicNameArray.add("Sequencer Track 1 Step 5" 				);
		/*125*/ publicNameArray.add("Sequencer Track 1 Step 6" 				);
		/*126*/ publicNameArray.add("Sequencer Track 1 Step 7" 				);
		/*127*/ publicNameArray.add("Sequencer Track 1 Step 8" 				);
		/*128*/ publicNameArray.add("Sequencer Track 1 Step 9" 				);
		/*129*/ publicNameArray.add("Sequencer Track 1 Step 10"				);
		/*130*/ publicNameArray.add("Sequencer Track 1 Step 11"				);
		/*131*/ publicNameArray.add("Sequencer Track 1 Step 12"				);
		/*132*/ publicNameArray.add("Sequencer Track 1 Step 13"				);
		/*133*/ publicNameArray.add("Sequencer Track 1 Step 14"				);
		/*134*/ publicNameArray.add("Sequencer Track 1 Step 15"				);
		/*135*/ publicNameArray.add("Sequencer Track 1 Step 16"				);
		/*136*/ publicNameArray.add("Sequencer Track 2 Step 1" 				);
		/*137*/ publicNameArray.add("Sequencer Track 2 Step 2" 				);
		/*138*/ publicNameArray.add("Sequencer Track 2 Step 3" 				);
		/*139*/ publicNameArray.add("Sequencer Track 2 Step 4" 				);
		/*140*/ publicNameArray.add("Sequencer Track 2 Step 5" 				);
		/*141*/ publicNameArray.add("Sequencer Track 2 Step 6" 				);
		/*142*/ publicNameArray.add("Sequencer Track 2 Step 7" 				);
		/*143*/ publicNameArray.add("Sequencer Track 2 Step 8" 				);
		/*144*/ publicNameArray.add("Sequencer Track 2 Step 9" 				);
		/*145*/ publicNameArray.add("Sequencer Track 2 Step 10"				);
		/*146*/ publicNameArray.add("Sequencer Track 2 Step 11"				);
		/*147*/ publicNameArray.add("Sequencer Track 2 Step 12"				);
		/*148*/ publicNameArray.add("Sequencer Track 2 Step 13"				);
		/*149*/ publicNameArray.add("Sequencer Track 2 Step 14"				);
		/*150*/ publicNameArray.add("Sequencer Track 2 Step 15"				);
		/*151*/ publicNameArray.add("Sequencer Track 2 Step 16"				);
		/*152*/ publicNameArray.add("Sequencer Track 3 Step 1" 				);
		/*153*/ publicNameArray.add("Sequencer Track 3 Step 2" 				);
		/*154*/ publicNameArray.add("Sequencer Track 3 Step 3" 				);
		/*155*/ publicNameArray.add("Sequencer Track 3 Step 4" 				);
		/*156*/ publicNameArray.add("Sequencer Track 3 Step 5" 				);
		/*157*/ publicNameArray.add("Sequencer Track 3 Step 6" 				);
		/*158*/ publicNameArray.add("Sequencer Track 3 Step 7" 				);
		/*159*/ publicNameArray.add("Sequencer Track 3 Step 8" 				);
		/*160*/ publicNameArray.add("Sequencer Track 3 Step 9" 				);
		/*161*/ publicNameArray.add("Sequencer Track 3 Step 10"				);
		/*162*/ publicNameArray.add("Sequencer Track 3 Step 11"				);
		/*163*/ publicNameArray.add("Sequencer Track 3 Step 12"				);
		/*164*/ publicNameArray.add("Sequencer Track 3 Step 13"				);
		/*165*/ publicNameArray.add("Sequencer Track 3 Step 14"				);
		/*166*/ publicNameArray.add("Sequencer Track 3 Step 15"				);
		/*167*/ publicNameArray.add("Sequencer Track 3 Step 16"				);
		/*168*/ publicNameArray.add("Sequencer Track 4 Step 1" 				);
		/*169*/ publicNameArray.add("Sequencer Track 4 Step 2" 				);
		/*170*/ publicNameArray.add("Sequencer Track 4 Step 3" 				);
		/*171*/ publicNameArray.add("Sequencer Track 4 Step 4" 				);
		/*172*/ publicNameArray.add("Sequencer Track 4 Step 5" 				);
		/*173*/ publicNameArray.add("Sequencer Track 4 Step 6" 				);
		/*174*/ publicNameArray.add("Sequencer Track 4 Step 7" 				);
		/*175*/ publicNameArray.add("Sequencer Track 4 Step 8" 				);
		/*176*/ publicNameArray.add("Sequencer Track 4 Step 9" 				);
		/*177*/ publicNameArray.add("Sequencer Track 4 Step 10"				);
		/*178*/ publicNameArray.add("Sequencer Track 4 Step 11"				);
		/*179*/ publicNameArray.add("Sequencer Track 4 Step 12"				);
		/*180*/ publicNameArray.add("Sequencer Track 4 Step 13"				);
		/*181*/ publicNameArray.add("Sequencer Track 4 Step 14"				);
		/*182*/ publicNameArray.add("Sequencer Track 4 Step 15"				);
		/*183*/ publicNameArray.add("Sequencer Track 4 Step 16"				);
		/*184*/ publicNameArray.add("Program Name Character 1" 				);
		/*185*/ publicNameArray.add("Program Name Character 2" 				);
		/*186*/ publicNameArray.add("Program Name Character 3" 				);
		/*187*/ publicNameArray.add("Program Name Character 4" 				);
		/*188*/ publicNameArray.add("Program Name Character 5" 				);
		/*189*/ publicNameArray.add("Program Name Character 6" 				);
		/*190*/ publicNameArray.add("Program Name Character 7" 				);
		/*191*/ publicNameArray.add("Program Name Character 8" 				);
		/*192*/ publicNameArray.add("Program Name Character 9" 				);
		/*193*/ publicNameArray.add("Program Name Character 10"				);
		/*194*/ publicNameArray.add("Program Name Character 11"				);
		/*195*/ publicNameArray.add("Program Name Character 12"				);
		/*196*/ publicNameArray.add("Program Name Character 13"				);
		/*197*/ publicNameArray.add("Program Name Character 14"				);
		/*198*/ publicNameArray.add("Program Name Character 15"				);
		/*199*/ publicNameArray.add("Program Name Character 16"				);
	}
};

