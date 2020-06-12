#pragma once

#include <JuceHeader.h>

// Takes an Array<int> and fills it with the number of steps
// that each of the hardware synthesizer's parameters has
struct NumberOfStepsArrayFactory
{
	static void fillArray(Array<uint8>& numberOfStepsArray)
	{
		/*0  */ numberOfStepsArray.add(121);	// pitchOsc1		
		/*1  */ numberOfStepsArray.add(101);	// fineTuneOsc1		
		/*2  */ numberOfStepsArray.add(104);	// shapeOsc1		
		/*3  */ numberOfStepsArray.add(128);	// glideOsc1		
		/*4  */ numberOfStepsArray.add(2  );	// keyTrackOsc1		
		/*5  */ numberOfStepsArray.add(128);	// subLevelOsc1		
		/*6  */ numberOfStepsArray.add(121);	// pitchOsc2		
		/*7  */ numberOfStepsArray.add(101);	// fineTuneOsc2		
		/*8  */ numberOfStepsArray.add(104);	// shapeOsc2		
		/*9  */ numberOfStepsArray.add(128);	// glideOsc2		
		/*10 */ numberOfStepsArray.add(2  );	// keyTrackOsc2		
		/*11 */ numberOfStepsArray.add(128);	// subLevelOsc2		
		/*12 */ numberOfStepsArray.add(2  );	// oscSync			
		/*13 */ numberOfStepsArray.add(4  );	// glideMode		
		/*14 */ numberOfStepsArray.add(6  );	// oscSlop			
		/*15 */ numberOfStepsArray.add(13 );	// bendRange		
		/*16 */ numberOfStepsArray.add(6  );	// notePriority		
		/*17 */ numberOfStepsArray.add(128);	// oscMix			
		/*18 */ numberOfStepsArray.add(128);	// noiseLevel		
		/*19 */ numberOfStepsArray.add(128);	// extInLevel		
		/*20 */ numberOfStepsArray.add(165);	// lpfFreq			
		/*21 */ numberOfStepsArray.add(128);	// lpfReso			
		/*22 */ numberOfStepsArray.add(128);	// lpfKeyAmount		
		/*23 */ numberOfStepsArray.add(128);	// lpfFMamount		
		/*24 */ numberOfStepsArray.add(2  );	// lpfType			
		/*25 */ numberOfStepsArray.add(255);	// lpfEnvAmount		
		/*26 */ numberOfStepsArray.add(128);	// lpfVelAmount		
		/*27 */ numberOfStepsArray.add(128);	// lpfDelay			
		/*28 */ numberOfStepsArray.add(128);	// lpfAttack		
		/*29 */ numberOfStepsArray.add(128);	// lpfDecay			
		/*30 */ numberOfStepsArray.add(128);	// lpfSustain		
		/*31 */ numberOfStepsArray.add(128);	// lpfRelease		
		/*32 */ numberOfStepsArray.add(128);	// vcaLevel			
		/*33 */ numberOfStepsArray.add(128);	// vcaEnvAmount		
		/*34 */ numberOfStepsArray.add(128);	// vcaVelAmount		
		/*35 */ numberOfStepsArray.add(128);	// vcaDelay			
		/*36 */ numberOfStepsArray.add(128);	// vcaAttack		
		/*37 */ numberOfStepsArray.add(128);	// vcaDecay			
		/*38 */ numberOfStepsArray.add(128);	// vcaSustain		
		/*39 */ numberOfStepsArray.add(128);	// vcaRelease		
		/*40 */ numberOfStepsArray.add(128);	// pgmVolume		
		/*41 */ numberOfStepsArray.add(167);	// lfo1Freq			
		/*42 */ numberOfStepsArray.add(5  );	// lfo1Shape		
		/*43 */ numberOfStepsArray.add(128);	// lfo1Amount		
		/*44 */ numberOfStepsArray.add(47 );	// lfo1Destination	
		/*45 */ numberOfStepsArray.add(2  );	// lfo1KeySync		
		/*46 */ numberOfStepsArray.add(167);	// lfo2Freq			
		/*47 */ numberOfStepsArray.add(5  );	// lfo2Shape		
		/*48 */ numberOfStepsArray.add(128);	// lfo2Amount		
		/*49 */ numberOfStepsArray.add(47 );	// lfo2Destination	
		/*50 */ numberOfStepsArray.add(2  );	// lfo2KeySync		
		/*51 */ numberOfStepsArray.add(167);	// lfo3Freq			
		/*52 */ numberOfStepsArray.add(5  );	// lfo3Shape		
		/*53 */ numberOfStepsArray.add(128);	// lfo3Amount		
		/*54 */ numberOfStepsArray.add(47 );	// lfo3Destination	
		/*55 */ numberOfStepsArray.add(2  );	// lfo3KeySync		
		/*56 */ numberOfStepsArray.add(167);	// lfo4Freq			
		/*57 */ numberOfStepsArray.add(5  );	// lfo4Shape		
		/*58 */ numberOfStepsArray.add(128);	// lfo4Amount		
		/*59 */ numberOfStepsArray.add(47 );	// lfo4Destination	
		/*60 */ numberOfStepsArray.add(2  );	// lfo4KeySync		
		/*61 */ numberOfStepsArray.add(47 );	// env3Destination	
		/*62 */ numberOfStepsArray.add(255);	// env3Amount		
		/*63 */ numberOfStepsArray.add(128);	// env3VelAmount	
		/*64 */ numberOfStepsArray.add(128);	// env3Delay		
		/*65 */ numberOfStepsArray.add(128);	// env3Attack		
		/*66 */ numberOfStepsArray.add(128);	// env3Decay		
		/*67 */ numberOfStepsArray.add(128);	// env3Sustain		
		/*68 */ numberOfStepsArray.add(128);	// env3Release		
		/*69 */ numberOfStepsArray.add(2  );	// env3Repeat		
		/*70 */ numberOfStepsArray.add(23 );	// mod1Source		
		/*71 */ numberOfStepsArray.add(255);	// mod1Amount		
		/*72 */ numberOfStepsArray.add(47 );	// mod1Destination	
		/*73 */ numberOfStepsArray.add(23 );	// mod2Source		
		/*74 */ numberOfStepsArray.add(255);	// mod2Amount		
		/*75 */ numberOfStepsArray.add(47 );	// mod2Destination	
		/*76 */ numberOfStepsArray.add(23 );	// mod3Source		
		/*77 */ numberOfStepsArray.add(255);	// mod3Amount		
		/*78 */ numberOfStepsArray.add(47 );	// mod3Destination	
		/*79 */ numberOfStepsArray.add(23 );	// mod4Source		
		/*80 */ numberOfStepsArray.add(255);	// mod4Amount		
		/*81 */ numberOfStepsArray.add(47 );	// mod4Destination	
		/*82 */ numberOfStepsArray.add(255);	// modWheelAmount	
		/*83 */ numberOfStepsArray.add(47 );	// modWheelDest		
		/*84 */ numberOfStepsArray.add(255);	// pressureAmount	
		/*85 */ numberOfStepsArray.add(47 );	// pressureDest		
		/*86 */ numberOfStepsArray.add(255);	// breathAmount		
		/*87 */ numberOfStepsArray.add(47 );	// breathDest		
		/*88 */ numberOfStepsArray.add(255);	// velocityAmount	
		/*89 */ numberOfStepsArray.add(47 );	// velocityDest		
		/*90 */ numberOfStepsArray.add(255);	// footPedalAmount	
		/*91 */ numberOfStepsArray.add(47 );	// footPedalDest	
		/*92 */ numberOfStepsArray.add(121);	// pushItPitch		
		/*93 */ numberOfStepsArray.add(128);	// pushItVelocity	
		/*94 */ numberOfStepsArray.add(3  );	// pushItMode		
		/*95 */ numberOfStepsArray.add(221);	// clockTempo		
		/*96 */ numberOfStepsArray.add(13 );	// clockDivide		
		/*97 */ numberOfStepsArray.add(4  );	// arpegMode		
		/*98 */ numberOfStepsArray.add(2  );	// arpegOnOff		
		/*99 */ numberOfStepsArray.add(6  );	// sequencerTrig	
		/*100*/ numberOfStepsArray.add(2  );	// sequencerOnOff	
		/*101*/ numberOfStepsArray.add(47 );	// track1Dest		
		/*102*/ numberOfStepsArray.add(47 );	// track2Dest		
		/*103*/ numberOfStepsArray.add(47 );	// track3Dest		
		/*104*/ numberOfStepsArray.add(47 );	// track4Dest		
		/*105*/ numberOfStepsArray.add(184);	// assignKnob1		
		/*106*/ numberOfStepsArray.add(184);	// assignKnob2		
		/*107*/ numberOfStepsArray.add(184);	// assignKnob3		
		/*108*/ numberOfStepsArray.add(184);	// assignKnob4		
		/*109*/ numberOfStepsArray.add(0  );	// unassigned109	
		/*110*/ numberOfStepsArray.add(0  );	// unassigned110	
		/*111*/ numberOfStepsArray.add(0  );	// unassigned111	
		/*112*/ numberOfStepsArray.add(0  );	// unassigned112	
		/*113*/ numberOfStepsArray.add(0  );	// unassigned113	
		/*114*/ numberOfStepsArray.add(0  );	// unassigned114	
		/*115*/ numberOfStepsArray.add(0  );	// unassigned115	
		/*116*/ numberOfStepsArray.add(0  );	// unassigned116	
		/*117*/ numberOfStepsArray.add(0  );	// unassigned117	
		/*118*/ numberOfStepsArray.add(0  );	// unassigned118	
		/*119*/ numberOfStepsArray.add(0  );	// unassigned119	
		/*120*/ numberOfStepsArray.add(128);	// track1Step1  	
		/*121*/ numberOfStepsArray.add(128);	// track1Step2  	
		/*122*/ numberOfStepsArray.add(128);	// track1Step3  	
		/*123*/ numberOfStepsArray.add(128);	// track1Step4  	
		/*124*/ numberOfStepsArray.add(128);	// track1Step5  	
		/*125*/ numberOfStepsArray.add(128);	// track1Step6  	
		/*126*/ numberOfStepsArray.add(128);	// track1Step7  	
		/*127*/ numberOfStepsArray.add(128);	// track1Step8  	
		/*128*/ numberOfStepsArray.add(128);	// track1Step9  	
		/*129*/ numberOfStepsArray.add(128);	// track1Step10		
		/*130*/ numberOfStepsArray.add(128);	// track1Step11		
		/*131*/ numberOfStepsArray.add(128);	// track1Step12		
		/*132*/ numberOfStepsArray.add(128);	// track1Step13		
		/*133*/ numberOfStepsArray.add(128);	// track1Step14		
		/*134*/ numberOfStepsArray.add(128);	// track1Step15		
		/*135*/ numberOfStepsArray.add(128);	// track1Step16		
		/*136*/ numberOfStepsArray.add(127);	// track2Step1  	
		/*137*/ numberOfStepsArray.add(127);	// track2Step2  	
		/*138*/ numberOfStepsArray.add(127);	// track2Step3  	
		/*139*/ numberOfStepsArray.add(127);	// track2Step4  	
		/*140*/ numberOfStepsArray.add(127);	// track2Step5  	
		/*141*/ numberOfStepsArray.add(127);	// track2Step6  	
		/*142*/ numberOfStepsArray.add(127);	// track2Step7  	
		/*143*/ numberOfStepsArray.add(127);	// track2Step8  	
		/*144*/ numberOfStepsArray.add(127);	// track2Step9  	
		/*145*/ numberOfStepsArray.add(127);	// track2Step10		
		/*146*/ numberOfStepsArray.add(127);	// track2Step11		
		/*147*/ numberOfStepsArray.add(127);	// track2Step12		
		/*148*/ numberOfStepsArray.add(127);	// track2Step13		
		/*149*/ numberOfStepsArray.add(127);	// track2Step14		
		/*150*/ numberOfStepsArray.add(127);	// track2Step15		
		/*151*/ numberOfStepsArray.add(127);	// track2Step16		
		/*152*/ numberOfStepsArray.add(127);	// track3Step1  	
		/*153*/ numberOfStepsArray.add(127);	// track3Step2  	
		/*154*/ numberOfStepsArray.add(127);	// track3Step3  	
		/*155*/ numberOfStepsArray.add(127);	// track3Step4  	
		/*156*/ numberOfStepsArray.add(127);	// track3Step5  	
		/*157*/ numberOfStepsArray.add(127);	// track3Step6  	
		/*158*/ numberOfStepsArray.add(127);	// track3Step7  	
		/*159*/ numberOfStepsArray.add(127);	// track3Step8  	
		/*160*/ numberOfStepsArray.add(127);	// track3Step9  	
		/*161*/ numberOfStepsArray.add(127);	// track3Step10		
		/*162*/ numberOfStepsArray.add(127);	// track3Step11		
		/*163*/ numberOfStepsArray.add(127);	// track3Step12		
		/*164*/ numberOfStepsArray.add(127);	// track3Step13		
		/*165*/ numberOfStepsArray.add(127);	// track3Step14		
		/*166*/ numberOfStepsArray.add(127);	// track3Step15		
		/*167*/ numberOfStepsArray.add(127);	// track3Step16		
		/*168*/ numberOfStepsArray.add(127);	// track4Step1  	
		/*169*/ numberOfStepsArray.add(127);	// track4Step2  	
		/*170*/ numberOfStepsArray.add(127);	// track4Step3  	
		/*171*/ numberOfStepsArray.add(127);	// track4Step4  	
		/*172*/ numberOfStepsArray.add(127);	// track4Step5  	
		/*173*/ numberOfStepsArray.add(127);	// track4Step6  	
		/*174*/ numberOfStepsArray.add(127);	// track4Step7  	
		/*175*/ numberOfStepsArray.add(127);	// track4Step8  	
		/*176*/ numberOfStepsArray.add(127);	// track4Step9  	
		/*177*/ numberOfStepsArray.add(127);	// track4Step10		
		/*178*/ numberOfStepsArray.add(127);	// track4Step11		
		/*179*/ numberOfStepsArray.add(127);	// track4Step12		
		/*180*/ numberOfStepsArray.add(127);	// track4Step13		
		/*181*/ numberOfStepsArray.add(127);	// track4Step14		
		/*182*/ numberOfStepsArray.add(127);	// track4Step15		
		/*183*/ numberOfStepsArray.add(127);	// track4Step16		
		/*184*/ numberOfStepsArray.add(128);	// nameChar1 		
		/*185*/ numberOfStepsArray.add(128);	// nameChar2 		
		/*186*/ numberOfStepsArray.add(128);	// nameChar3 		
		/*187*/ numberOfStepsArray.add(128);	// nameChar4 		
		/*188*/ numberOfStepsArray.add(128);	// nameChar5 		
		/*189*/ numberOfStepsArray.add(128);	// nameChar6 		
		/*190*/ numberOfStepsArray.add(128);	// nameChar7 		
		/*191*/ numberOfStepsArray.add(128);	// nameChar8 		
		/*192*/ numberOfStepsArray.add(128);	// nameChar9 		
		/*193*/ numberOfStepsArray.add(128);	// nameChar10		
		/*194*/ numberOfStepsArray.add(128);	// nameChar11		
		/*195*/ numberOfStepsArray.add(128);	// nameChar12		
		/*196*/ numberOfStepsArray.add(128);	// nameChar13		
		/*197*/ numberOfStepsArray.add(128);	// nameChar14		
		/*198*/ numberOfStepsArray.add(128);	// nameChar15		
		/*199*/ numberOfStepsArray.add(128);	// nameChar16		
	}
};

