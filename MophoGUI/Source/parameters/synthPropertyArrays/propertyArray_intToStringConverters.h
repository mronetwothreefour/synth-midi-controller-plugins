#pragma once

#include <JuceHeader.h>

#include "intToStringConverters.h"

// Takes an Array<IntToStringConverter*> and fills it with pointers to the
// appropriate IntToStringConverter for each of the hardware synthesizer's parameters
struct IntToStringConverterArrayFactory
{
	static void fillArray(Array<IntToStringConverter*>& converterArray)
	{
		/*0  */ converterArray.add(IntToOscPitch		::get());	// pitchOsc1	
		/*1  */ converterArray.add(IntToFineTune		::get());	// fineTuneOsc1
		/*2  */ converterArray.add(IntToOscWaveShape	::get());	// shapeOsc1		
		/*3  */ converterArray.add(IntToPlainValue		::get());	// glideOsc1		
		/*4  */ converterArray.add(IntToOffOn			::get());	// keyTrackOsc1		
		/*5  */ converterArray.add(IntToPlainValue		::get());	// subLevelOsc1		
		/*6  */ converterArray.add(IntToOscPitch		::get());	// pitchOsc2		
		/*7  */ converterArray.add(IntToFineTune		::get());	// fineTuneOsc2		
		/*8  */ converterArray.add(IntToOscWaveShape	::get());	// shapeOsc2		
		/*9  */ converterArray.add(IntToPlainValue		::get());	// glideOsc2		
		/*10 */ converterArray.add(IntToOffOn			::get());	// keyTrackOsc2		
		/*11 */ converterArray.add(IntToPlainValue		::get());	// subLevelOsc2		
		/*12 */ converterArray.add(IntToPlainValue		::get());	// oscSync			
		/*13 */ converterArray.add(IntToGlideMode		::get());	// glideMode		
		/*14 */ converterArray.add(IntToPlainValue		::get());	// oscSlop			
		/*15 */ converterArray.add(IntToBendRange		::get());	// bendRange		
		/*16 */ converterArray.add(IntToNotePriority	::get());	// notePriority		
		/*17 */ converterArray.add(IntToPlainValue		::get());	// oscMix			
		/*18 */ converterArray.add(IntToPlainValue		::get());	// noiseLevel		
		/*19 */ converterArray.add(IntToPlainValue		::get());	// extInLevel		
		/*20 */ converterArray.add(IntToLPFfreq			::get());	// lpfFreq			
		/*21 */ converterArray.add(IntToPlainValue		::get());	// lpfReso			
		/*22 */ converterArray.add(IntToPlainValue		::get());	// lpfKeyAmount		
		/*23 */ converterArray.add(IntToPlainValue		::get());	// lpfFMamount		
		/*24 */ converterArray.add(IntToLPFtype			::get());	// lpfType			
		/*25 */ converterArray.add(IntToPlusMinus127	::get());	// lpfEnvAmount		
		/*26 */ converterArray.add(IntToPlainValue		::get());	// lpfVelAmount		
		/*27 */ converterArray.add(IntToPlainValue		::get());	// lpfDelay			
		/*28 */ converterArray.add(IntToPlainValue		::get());	// lpfAttack		
		/*29 */ converterArray.add(IntToPlainValue		::get());	// lpfDecay			
		/*30 */ converterArray.add(IntToPlainValue		::get());	// lpfSustain		
		/*31 */ converterArray.add(IntToPlainValue		::get());	// lpfRelease		
		/*32 */ converterArray.add(IntToPlainValue		::get());	// vcaLevel			
		/*33 */ converterArray.add(IntToPlainValue		::get());	// vcaEnvAmount		
		/*34 */ converterArray.add(IntToPlainValue		::get());	// vcaVelAmount		
		/*35 */ converterArray.add(IntToPlainValue		::get());	// vcaDelay			
		/*36 */ converterArray.add(IntToPlainValue		::get());	// vcaAttack		
		/*37 */ converterArray.add(IntToPlainValue		::get());	// vcaDecay			
		/*38 */ converterArray.add(IntToPlainValue		::get());	// vcaSustain		
		/*39 */ converterArray.add(IntToPlainValue		::get());	// vcaRelease		
		/*40 */ converterArray.add(IntToPlainValue		::get());	// pgmVolume		
		/*41 */ converterArray.add(IntToLFOfreq			::get());	// lfo1Freq			
		/*42 */ converterArray.add(IntToLFOshape		::get());	// lfo1Shape		
		/*43 */ converterArray.add(IntToPlainValue		::get());	// lfo1Amount		
		/*44 */ converterArray.add(IntToModDestination	::get());	// lfo1Destination	
		/*45 */ converterArray.add(IntToOffOn			::get());	// lfo1KeySync		
		/*46 */ converterArray.add(IntToLFOfreq			::get());	// lfo2Freq			
		/*47 */ converterArray.add(IntToLFOshape		::get());	// lfo2Shape		
		/*48 */ converterArray.add(IntToPlainValue		::get());	// lfo2Amount		
		/*49 */ converterArray.add(IntToModDestination	::get());	// lfo2Destination	
		/*50 */ converterArray.add(IntToOffOn			::get());	// lfo2KeySync		
		/*51 */ converterArray.add(IntToLFOfreq			::get());	// lfo3Freq			
		/*52 */ converterArray.add(IntToLFOshape		::get());	// lfo3Shape		
		/*53 */ converterArray.add(IntToPlainValue		::get());	// lfo3Amount		
		/*54 */ converterArray.add(IntToModDestination	::get());	// lfo3Destination	
		/*55 */ converterArray.add(IntToOffOn			::get());	// lfo3KeySync		
		/*56 */ converterArray.add(IntToLFOfreq			::get());	// lfo4Freq			
		/*57 */ converterArray.add(IntToLFOshape		::get());	// lfo4Shape		
		/*58 */ converterArray.add(IntToPlainValue		::get());	// lfo4Amount		
		/*59 */ converterArray.add(IntToModDestination	::get());	// lfo4Destination	
		/*60 */ converterArray.add(IntToOffOn			::get());	// lfo4KeySync		
		/*61 */ converterArray.add(IntToModDestination	::get());	// env3Destination	
		/*62 */ converterArray.add(IntToPlusMinus127	::get());	// env3Amount		
		/*63 */ converterArray.add(IntToPlainValue		::get());	// env3VelAmount	
		/*64 */ converterArray.add(IntToPlainValue		::get());	// env3Delay		
		/*65 */ converterArray.add(IntToPlainValue		::get());	// env3Attack		
		/*66 */ converterArray.add(IntToPlainValue		::get());	// env3Decay		
		/*67 */ converterArray.add(IntToPlainValue		::get());	// env3Sustain		
		/*68 */ converterArray.add(IntToPlainValue		::get());	// env3Release		
		/*69 */ converterArray.add(IntToOffOn			::get());	// env3Repeat		
		/*70 */ converterArray.add(IntToModSource		::get());	// mod1Source		
		/*71 */ converterArray.add(IntToPlusMinus127	::get());	// mod1Amount		
		/*72 */ converterArray.add(IntToModDestination	::get());	// mod1Destination	
		/*73 */ converterArray.add(IntToModSource		::get());	// mod2Source		
		/*74 */ converterArray.add(IntToPlusMinus127	::get());	// mod2Amount		
		/*75 */ converterArray.add(IntToModDestination	::get());	// mod2Destination	
		/*76 */ converterArray.add(IntToModSource		::get());	// mod3Source		
		/*77 */ converterArray.add(IntToPlusMinus127	::get());	// mod3Amount		
		/*78 */ converterArray.add(IntToModDestination	::get());	// mod3Destination	
		/*79 */ converterArray.add(IntToModSource		::get());	// mod4Source		
		/*80 */ converterArray.add(IntToPlusMinus127	::get());	// mod4Amount		
		/*81 */ converterArray.add(IntToModDestination	::get());	// mod4Destination	
		/*82 */ converterArray.add(IntToPlusMinus127	::get());	// modWheelAmount	
		/*83 */ converterArray.add(IntToModDestination	::get());	// modWheelDest		
		/*84 */ converterArray.add(IntToPlusMinus127	::get());	// pressureAmount	
		/*85 */ converterArray.add(IntToModDestination	::get());	// pressureDest		
		/*86 */ converterArray.add(IntToPlusMinus127	::get());	// breathAmount		
		/*87 */ converterArray.add(IntToModDestination	::get());	// breathDest		
		/*88 */ converterArray.add(IntToPlusMinus127	::get());	// velocityAmount	
		/*89 */ converterArray.add(IntToModDestination	::get());	// velocityDest		
		/*90 */ converterArray.add(IntToPlusMinus127	::get());	// footPedalAmount	
		/*91 */ converterArray.add(IntToModDestination	::get());	// footPedalDest	
		/*92 */ converterArray.add(IntToOscPitch		::get());	// pushItPitch		
		/*93 */ converterArray.add(IntToPlainValue		::get());	// pushItVelocity	
		/*94 */ converterArray.add(IntToPushItMode		::get());	// pushItMode		
		/*95 */ converterArray.add(IntToClockTempo		::get());	// clockTempo		
		/*96 */ converterArray.add(IntToClockDiv		::get());	// clockDivide		
		/*97 */ converterArray.add(IntToArpegMode		::get());	// arpegMode		
		/*98 */ converterArray.add(IntToOffOn			::get());	// arpegOnOff		
		/*99 */ converterArray.add(IntToSeqTrigger		::get());	// sequencerTrig	
		/*100*/ converterArray.add(IntToOffOn			::get());	// sequencerOnOff	
		/*101*/ converterArray.add(IntToModDestination	::get());	// track1Dest		
		/*102*/ converterArray.add(IntToModDestination	::get());	// track2Dest		
		/*103*/ converterArray.add(IntToModDestination	::get());	// track3Dest		
		/*104*/ converterArray.add(IntToModDestination	::get());	// track4Dest		
		/*105*/ converterArray.add(IntToParamName		::get());	// assignKnob1		
		/*106*/ converterArray.add(IntToParamName		::get());	// assignKnob2		
		/*107*/ converterArray.add(IntToParamName		::get());	// assignKnob3		
		/*108*/ converterArray.add(IntToParamName		::get());	// assignKnob4		
		/*109*/ converterArray.add(nullptr					   );	// unassigned109	
		/*110*/ converterArray.add(nullptr					   );	// unassigned110	
		/*111*/ converterArray.add(nullptr					   );	// unassigned111	
		/*112*/ converterArray.add(nullptr					   );	// unassigned112	
		/*113*/ converterArray.add(nullptr					   );	// unassigned113	
		/*114*/ converterArray.add(nullptr					   );	// unassigned114	
		/*115*/ converterArray.add(nullptr					   );	// unassigned115	
		/*116*/ converterArray.add(nullptr					   );	// unassigned116	
		/*117*/ converterArray.add(nullptr					   );	// unassigned117	
		/*118*/ converterArray.add(nullptr					   );	// unassigned118	
		/*119*/ converterArray.add(nullptr					   );	// unassigned119	
		/*120*/ converterArray.add(IntToStepValue		::get());	// track1Step1  	
		/*121*/ converterArray.add(IntToStepValue		::get());	// track1Step2  	
		/*122*/ converterArray.add(IntToStepValue		::get());	// track1Step3  	
		/*123*/ converterArray.add(IntToStepValue		::get());	// track1Step4  	
		/*124*/ converterArray.add(IntToStepValue		::get());	// track1Step5  	
		/*125*/ converterArray.add(IntToStepValue		::get());	// track1Step6  	
		/*126*/ converterArray.add(IntToStepValue		::get());	// track1Step7  	
		/*127*/ converterArray.add(IntToStepValue		::get());	// track1Step8  	
		/*128*/ converterArray.add(IntToStepValue		::get());	// track1Step9  	
		/*129*/ converterArray.add(IntToStepValue		::get());	// track1Step10		
		/*130*/ converterArray.add(IntToStepValue		::get());	// track1Step11		
		/*131*/ converterArray.add(IntToStepValue		::get());	// track1Step12		
		/*132*/ converterArray.add(IntToStepValue		::get());	// track1Step13		
		/*133*/ converterArray.add(IntToStepValue		::get());	// track1Step14		
		/*134*/ converterArray.add(IntToStepValue		::get());	// track1Step15		
		/*135*/ converterArray.add(IntToStepValue		::get());	// track1Step16		
		/*136*/ converterArray.add(IntToStepValue		::get());	// track2Step1  	
		/*137*/ converterArray.add(IntToStepValue		::get());	// track2Step2  	
		/*138*/ converterArray.add(IntToStepValue		::get());	// track2Step3  	
		/*139*/ converterArray.add(IntToStepValue		::get());	// track2Step4  	
		/*140*/ converterArray.add(IntToStepValue		::get());	// track2Step5  	
		/*141*/ converterArray.add(IntToStepValue		::get());	// track2Step6  	
		/*142*/ converterArray.add(IntToStepValue		::get());	// track2Step7  	
		/*143*/ converterArray.add(IntToStepValue		::get());	// track2Step8  	
		/*144*/ converterArray.add(IntToStepValue		::get());	// track2Step9  	
		/*145*/ converterArray.add(IntToStepValue		::get());	// track2Step10		
		/*146*/ converterArray.add(IntToStepValue		::get());	// track2Step11		
		/*147*/ converterArray.add(IntToStepValue		::get());	// track2Step12		
		/*148*/ converterArray.add(IntToStepValue		::get());	// track2Step13		
		/*149*/ converterArray.add(IntToStepValue		::get());	// track2Step14		
		/*150*/ converterArray.add(IntToStepValue		::get());	// track2Step15		
		/*151*/ converterArray.add(IntToStepValue		::get());	// track2Step16		
		/*152*/ converterArray.add(IntToStepValue		::get());	// track3Step1  	
		/*153*/ converterArray.add(IntToStepValue		::get());	// track3Step2  	
		/*154*/ converterArray.add(IntToStepValue		::get());	// track3Step3  	
		/*155*/ converterArray.add(IntToStepValue		::get());	// track3Step4  	
		/*156*/ converterArray.add(IntToStepValue		::get());	// track3Step5  	
		/*157*/ converterArray.add(IntToStepValue		::get());	// track3Step6  	
		/*158*/ converterArray.add(IntToStepValue		::get());	// track3Step7  	
		/*159*/ converterArray.add(IntToStepValue		::get());	// track3Step8  	
		/*160*/ converterArray.add(IntToStepValue		::get());	// track3Step9  	
		/*161*/ converterArray.add(IntToStepValue		::get());	// track3Step10		
		/*162*/ converterArray.add(IntToStepValue		::get());	// track3Step11		
		/*163*/ converterArray.add(IntToStepValue		::get());	// track3Step12		
		/*164*/ converterArray.add(IntToStepValue		::get());	// track3Step13		
		/*165*/ converterArray.add(IntToStepValue		::get());	// track3Step14		
		/*166*/ converterArray.add(IntToStepValue		::get());	// track3Step15		
		/*167*/ converterArray.add(IntToStepValue		::get());	// track3Step16		
		/*168*/ converterArray.add(IntToStepValue		::get());	// track4Step1  	
		/*169*/ converterArray.add(IntToStepValue		::get());	// track4Step2  	
		/*170*/ converterArray.add(IntToStepValue		::get());	// track4Step3  	
		/*171*/ converterArray.add(IntToStepValue		::get());	// track4Step4  	
		/*172*/ converterArray.add(IntToStepValue		::get());	// track4Step5  	
		/*173*/ converterArray.add(IntToStepValue		::get());	// track4Step6  	
		/*174*/ converterArray.add(IntToStepValue		::get());	// track4Step7  	
		/*175*/ converterArray.add(IntToStepValue		::get());	// track4Step8  	
		/*176*/ converterArray.add(IntToStepValue		::get());	// track4Step9  	
		/*177*/ converterArray.add(IntToStepValue		::get());	// track4Step10		
		/*178*/ converterArray.add(IntToStepValue		::get());	// track4Step11		
		/*179*/ converterArray.add(IntToStepValue		::get());	// track4Step12		
		/*180*/ converterArray.add(IntToStepValue		::get());	// track4Step13		
		/*181*/ converterArray.add(IntToStepValue		::get());	// track4Step14		
		/*182*/ converterArray.add(IntToStepValue		::get());	// track4Step15		
		/*183*/ converterArray.add(IntToStepValue		::get());	// track4Step16		
		/*184*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar1 		
		/*185*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar2 		
		/*186*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar3 		
		/*187*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar4 		
		/*188*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar5 		
		/*189*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar6 		
		/*190*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar7 		
		/*191*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar8 		
		/*192*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar9 		
		/*193*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar10		
		/*194*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar11		
		/*195*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar12		
		/*196*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar13		
		/*197*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar14		
		/*198*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar15		
		/*199*/ converterArray.add(IntToPgmNameChar		::get());	// nameChar16		
	}
};

