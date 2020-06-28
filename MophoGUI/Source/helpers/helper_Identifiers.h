#pragma once

#include <JuceHeader.h>

namespace ID
{
	static const Identifier exposedParams { "exposedParams" };

	// synth program parameters ==============================================
	/*0  */ static const Identifier pitchOsc1			{ "pitchOsc1"		};
	/*1  */ static const Identifier fineTuneOsc1		{ "fineTuneOsc1"	};
	/*2  */ static const Identifier shapeOsc1			{ "shapeOsc1"		};
	/*3  */ static const Identifier glideOsc1			{ "glideOsc1"		};
	/*4  */ static const Identifier keyTrackOsc1		{ "keyTrackOsc1"	};
	/*5  */ static const Identifier subLevelOsc1		{ "subLevelOsc1"	};
	/*6  */ static const Identifier pitchOsc2			{ "pitchOsc2"		};
	/*7  */ static const Identifier fineTuneOsc2		{ "fineTuneOsc2"	};
	/*8  */ static const Identifier shapeOsc2			{ "shapeOsc2"		};
	/*9  */ static const Identifier glideOsc2			{ "glideOsc2"		};
	/*10 */ static const Identifier keyTrackOsc2		{ "keyTrackOsc2"	};
	/*11 */ static const Identifier subLevelOsc2		{ "subLevelOsc2"	};
	/*12 */ static const Identifier oscSync				{ "oscSync"			};
	/*13 */ static const Identifier glideMode			{ "glideMode"		};
	/*14 */ static const Identifier oscSlop				{ "oscSlop"			};
	/*15 */ static const Identifier bendRange			{ "bendRange"		};
	/*16 */ static const Identifier notePriority		{ "notePriority"	};
	/*17 */ static const Identifier oscMix				{ "oscMix"			};
	/*18 */ static const Identifier noiseLevel			{ "noiseLevel"		};
	/*19 */ static const Identifier extInLevel			{ "extInLevel"		};
	/*20 */ static const Identifier lpfFreq				{ "lpfFreq"			};
	/*21 */ static const Identifier lpfReso				{ "lpfReso"			};
	/*22 */ static const Identifier lpfKeyAmount		{ "lpfKeyAmount"	};
	/*23 */ static const Identifier lpfFMamount			{ "lpfFMamount"		};
	/*24 */ static const Identifier lpfType				{ "lpfType"			};
	/*25 */ static const Identifier lpfEnvAmount		{ "lpfEnvAmount"	};
	/*26 */ static const Identifier lpfVelAmount		{ "lpfVelAmount"	};
	/*27 */ static const Identifier lpfDelay			{ "lpfDelay"		};
	/*28 */ static const Identifier lpfAttack			{ "lpfAttack"		};
	/*29 */ static const Identifier lpfDecay			{ "lpfDecay"		};
	/*30 */ static const Identifier lpfSustain			{ "lpfSustain"		};
	/*31 */ static const Identifier lpfRelease			{ "lpfRelease"		};
	/*32 */ static const Identifier vcaLevel			{ "vcaLevel"		};
	/*33 */ static const Identifier vcaEnvAmount		{ "vcaEnvAmount"	};
	/*34 */ static const Identifier vcaVelAmount		{ "vcaVelAmount"	};
	/*35 */ static const Identifier vcaDelay			{ "vcaDelay"		};
	/*36 */ static const Identifier vcaAttack			{ "vcaAttack"		};
	/*37 */ static const Identifier vcaDecay			{ "vcaDecay"		};
	/*38 */ static const Identifier vcaSustain			{ "vcaSustain"		};
	/*39 */ static const Identifier vcaRelease			{ "vcaRelease"		};
	/*40 */ static const Identifier pgmVolume			{ "pgmVolume"		};
	/*41 */ static const Identifier lfo1Freq			{ "lfo1Freq"		};
	/*42 */ static const Identifier lfo1Shape			{ "lfo1Shape"		};
	/*43 */ static const Identifier lfo1Amount			{ "lfo1Amount"		};
	/*44 */ static const Identifier lfo1Destination		{ "lfo1Destination"	};
	/*45 */ static const Identifier lfo1KeySync			{ "lfo1KeySync"		};
	/*46 */ static const Identifier lfo2Freq			{ "lfo2Freq"		};
	/*47 */ static const Identifier lfo2Shape			{ "lfo2Shape"		};
	/*48 */ static const Identifier lfo2Amount			{ "lfo2Amount"		};
	/*49 */ static const Identifier lfo2Destination		{ "lfo2Destination"	};
	/*50 */ static const Identifier lfo2KeySync			{ "lfo2KeySync"		};
	/*51 */ static const Identifier lfo3Freq			{ "lfo3Freq"		};
	/*52 */ static const Identifier lfo3Shape			{ "lfo3Shape"		};
	/*53 */ static const Identifier lfo3Amount			{ "lfo3Amount"		};
	/*54 */ static const Identifier lfo3Destination		{ "lfo3Destination"	};
	/*55 */ static const Identifier lfo3KeySync			{ "lfo3KeySync"		};
	/*56 */ static const Identifier lfo4Freq			{ "lfo4Freq"		};
	/*57 */ static const Identifier lfo4Shape			{ "lfo4Shape"		};
	/*58 */ static const Identifier lfo4Amount			{ "lfo4Amount"		};
	/*59 */ static const Identifier lfo4Destination		{ "lfo4Destination"	};
	/*60 */ static const Identifier lfo4KeySync			{ "lfo4KeySync"		};
	/*61 */ static const Identifier env3Destination		{ "env3Destination"	};
	/*62 */ static const Identifier env3Amount			{ "env3Amount"		};
	/*63 */ static const Identifier env3VelAmount		{ "env3VelAmount"	};
	/*64 */ static const Identifier env3Delay			{ "env3Delay"		};
	/*65 */ static const Identifier env3Attack			{ "env3Attack"		};
	/*66 */ static const Identifier env3Decay			{ "env3Decay"		};
	/*67 */ static const Identifier env3Sustain			{ "env3Sustain"		};
	/*68 */ static const Identifier env3Release			{ "env3Release"		};
	/*69 */ static const Identifier env3Repeat			{ "env3Repeat"		};
	/*70 */ static const Identifier mod1Source			{ "mod1Source"		};
	/*71 */ static const Identifier mod1Amount			{ "mod1Amount"		};
	/*72 */ static const Identifier mod1Destination		{ "mod1Destination" };
	/*73 */ static const Identifier mod2Source			{ "mod2Source"		};
	/*74 */ static const Identifier mod2Amount			{ "mod2Amount"		};
	/*75 */ static const Identifier mod2Destination		{ "mod2Destination" };
	/*76 */ static const Identifier mod3Source			{ "mod3Source"		};
	/*77 */ static const Identifier mod3Amount			{ "mod3Amount"		};
	/*78 */ static const Identifier mod3Destination		{ "mod3Destination" };
	/*79 */ static const Identifier mod4Source			{ "mod4Source"		};
	/*80 */ static const Identifier mod4Amount			{ "mod4Amount"		};
	/*81 */ static const Identifier mod4Destination		{ "mod4Destination" };
	/*82 */ static const Identifier modWheelAmount		{ "modWheelAmount"	};
	/*83 */ static const Identifier modWheelDest		{ "modWheelDest"	};
	/*84 */ static const Identifier pressureAmount		{ "pressureAmount"	};
	/*85 */ static const Identifier pressureDest		{ "pressureDest"	};
	/*86 */ static const Identifier breathAmount		{ "breathAmount"	};
	/*87 */ static const Identifier breathDest			{ "breathDest"		};
	/*88 */ static const Identifier velocityAmount		{ "velocityAmount"	};
	/*89 */ static const Identifier velocityDest		{ "velocityDest"	};
	/*90 */ static const Identifier footPedalAmount		{ "footPedalAmount"	};
	/*91 */ static const Identifier footPedalDest		{ "footPedalDest"	};
	/*92 */ static const Identifier pushItPitch			{ "pushItPitch"		};
	/*93 */ static const Identifier pushItVelocity		{ "pushItVelocity"	};
	/*94 */ static const Identifier pushItMode			{ "pushItMode"		};
	/*95 */ static const Identifier clockTempo			{ "clockTempo"		};
	/*96 */ static const Identifier clockDivide			{ "clockDivide"		};
	/*97 */ static const Identifier arpegMode			{ "arpegMode"		};
	/*98 */ static const Identifier arpegOnOff			{ "arpegOnOff"		};
	/*99 */ static const Identifier sequencerTrig		{ "sequencerTrig"	};
	/*100*/ static const Identifier sequencerOnOff		{ "sequencerOnOff"	};
	/*101*/ static const Identifier track1Dest			{ "track1Dest"		};
	/*102*/ static const Identifier track2Dest			{ "track2Dest"		};
	/*103*/ static const Identifier track3Dest			{ "track3Dest"		};
	/*104*/ static const Identifier track4Dest			{ "track4Dest"		};
	/*105*/ static const Identifier assignKnob1			{ "assignKnob1"		};
	/*106*/ static const Identifier assignKnob2			{ "assignKnob2"		};
	/*107*/ static const Identifier assignKnob3			{ "assignKnob3"		};
	/*108*/ static const Identifier assignKnob4			{ "assignKnob4"		};
	/*109*/ static const Identifier unassigned109		{ "unassigned109"	};
	/*110*/ static const Identifier unassigned110		{ "unassigned110"	};
	/*111*/ static const Identifier unassigned111		{ "unassigned111"	};
	/*112*/ static const Identifier unassigned112		{ "unassigned112"	};
	/*113*/ static const Identifier unassigned113		{ "unassigned113"	};
	/*114*/ static const Identifier unassigned114		{ "unassigned114"	};
	/*115*/ static const Identifier unassigned115		{ "unassigned115"	};
	/*116*/ static const Identifier unassigned116		{ "unassigned116"	};
	/*117*/ static const Identifier unassigned117		{ "unassigned117"	};
	/*118*/ static const Identifier unassigned118		{ "unassigned118"	};
	/*119*/ static const Identifier unassigned119		{ "unassigned119"	};
	/*120*/ static const Identifier track1Step1  		{ "track1Step1"		};
	/*121*/ static const Identifier track1Step2  		{ "track1Step2"		};
	/*122*/ static const Identifier track1Step3  		{ "track1Step3"		};
	/*123*/ static const Identifier track1Step4  		{ "track1Step4"		};
	/*124*/ static const Identifier track1Step5  		{ "track1Step5"		};
	/*125*/ static const Identifier track1Step6  		{ "track1Step6"		};
	/*126*/ static const Identifier track1Step7  		{ "track1Step7"		};
	/*127*/ static const Identifier track1Step8  		{ "track1Step8"		};
	/*128*/ static const Identifier track1Step9  		{ "track1Step9"		};
	/*129*/ static const Identifier track1Step10		{ "track1Step10"	};
	/*130*/ static const Identifier track1Step11		{ "track1Step11"	};
	/*131*/ static const Identifier track1Step12		{ "track1Step12"	};
	/*132*/ static const Identifier track1Step13		{ "track1Step13"	};
	/*133*/ static const Identifier track1Step14		{ "track1Step14"	};
	/*134*/ static const Identifier track1Step15		{ "track1Step15"	};
	/*135*/ static const Identifier track1Step16		{ "track1Step16"	};
	/*136*/ static const Identifier track2Step1  		{ "track2Step1"		};
	/*137*/ static const Identifier track2Step2  		{ "track2Step2"		};
	/*138*/ static const Identifier track2Step3  		{ "track2Step3"		};
	/*139*/ static const Identifier track2Step4  		{ "track2Step4"		};
	/*140*/ static const Identifier track2Step5  		{ "track2Step5"		};
	/*141*/ static const Identifier track2Step6  		{ "track2Step6"		};
	/*142*/ static const Identifier track2Step7  		{ "track2Step7"		};
	/*143*/ static const Identifier track2Step8  		{ "track2Step8"		};
	/*144*/ static const Identifier track2Step9  		{ "track2Step9"		};
	/*145*/ static const Identifier track2Step10		{ "track2Step10"	};
	/*146*/ static const Identifier track2Step11		{ "track2Step11"	};
	/*147*/ static const Identifier track2Step12		{ "track2Step12"	};
	/*148*/ static const Identifier track2Step13		{ "track2Step13"	};
	/*149*/ static const Identifier track2Step14		{ "track2Step14"	};
	/*150*/ static const Identifier track2Step15		{ "track2Step15"	};
	/*151*/ static const Identifier track2Step16		{ "track2Step16"	};
	/*152*/ static const Identifier track3Step1  		{ "track3Step1"		};
	/*153*/ static const Identifier track3Step2  		{ "track3Step2"		};
	/*154*/ static const Identifier track3Step3  		{ "track3Step3"		};
	/*155*/ static const Identifier track3Step4  		{ "track3Step4"		};
	/*156*/ static const Identifier track3Step5  		{ "track3Step5"		};
	/*157*/ static const Identifier track3Step6  		{ "track3Step6"		};
	/*158*/ static const Identifier track3Step7  		{ "track3Step7"		};
	/*159*/ static const Identifier track3Step8  		{ "track3Step8"		};
	/*160*/ static const Identifier track3Step9  		{ "track3Step9"		};
	/*161*/ static const Identifier track3Step10		{ "track3Step10"	};
	/*162*/ static const Identifier track3Step11		{ "track3Step11"	};
	/*163*/ static const Identifier track3Step12		{ "track3Step12"	};
	/*164*/ static const Identifier track3Step13		{ "track3Step13"	};
	/*165*/ static const Identifier track3Step14		{ "track3Step14"	};
	/*166*/ static const Identifier track3Step15		{ "track3Step15"	};
	/*167*/ static const Identifier track3Step16		{ "track3Step16"	};
	/*168*/ static const Identifier track4Step1  		{ "track4Step1"		};
	/*169*/ static const Identifier track4Step2  		{ "track4Step2"		};
	/*170*/ static const Identifier track4Step3  		{ "track4Step3"		};
	/*171*/ static const Identifier track4Step4  		{ "track4Step4"		};
	/*172*/ static const Identifier track4Step5  		{ "track4Step5"		};
	/*173*/ static const Identifier track4Step6  		{ "track4Step6"		};
	/*174*/ static const Identifier track4Step7  		{ "track4Step7"		};
	/*175*/ static const Identifier track4Step8  		{ "track4Step8"		};
	/*176*/ static const Identifier track4Step9  		{ "track4Step9"		};
	/*177*/ static const Identifier track4Step10		{ "track4Step10"	};
	/*178*/ static const Identifier track4Step11		{ "track4Step11"	};
	/*179*/ static const Identifier track4Step12		{ "track4Step12"	};
	/*180*/ static const Identifier track4Step13		{ "track4Step13"	};
	/*181*/ static const Identifier track4Step14		{ "track4Step14"	};
	/*182*/ static const Identifier track4Step15		{ "track4Step15"	};
	/*183*/ static const Identifier track4Step16		{ "track4Step16"	};
	/*184*/ static const Identifier nameChar1 			{ "nameChar1"		};
	/*185*/ static const Identifier nameChar2 			{ "nameChar2"		};
	/*186*/ static const Identifier nameChar3 			{ "nameChar3"		};
	/*187*/ static const Identifier nameChar4 			{ "nameChar4"		};
	/*188*/ static const Identifier nameChar5 			{ "nameChar5"		};
	/*189*/ static const Identifier nameChar6 			{ "nameChar6"		};
	/*190*/ static const Identifier nameChar7 			{ "nameChar7"		};
	/*191*/ static const Identifier nameChar8 			{ "nameChar8"		};
	/*192*/ static const Identifier nameChar9 			{ "nameChar9"		};
	/*193*/ static const Identifier nameChar10			{ "nameChar10"		};
	/*194*/ static const Identifier nameChar11			{ "nameChar11"		};
	/*195*/ static const Identifier nameChar12			{ "nameChar12"		};
	/*196*/ static const Identifier nameChar13			{ "nameChar13"		};
	/*197*/ static const Identifier nameChar14			{ "nameChar14"		};
	/*198*/ static const Identifier nameChar15			{ "nameChar15"		};
	/*199*/ static const Identifier nameChar16			{ "nameChar16"		};
}