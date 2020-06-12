#pragma once

#include <JuceHeader.h>

// Takes an Array<int> and fills it with NRPNs for
// each of the hardware synthesizer's parameters
struct NRPNarrayFactory
{
	static void fillArray(Array<uint16>& nrpnArray)
	{
		/*0  */ nrpnArray.add(0  );	// pitchOsc1			
		/*1  */ nrpnArray.add(1  );	// fineTuneOsc1		
		/*2  */ nrpnArray.add(2  );	// shapeOsc1			
		/*3  */ nrpnArray.add(3  );	// glideOsc1			
		/*4  */ nrpnArray.add(4  );	// keyTrackOsc1		
		/*5  */ nrpnArray.add(114);	// subLevelOsc1		
		/*6  */ nrpnArray.add(5  );	// pitchOsc2			
		/*7  */ nrpnArray.add(6  );	// fineTuneOsc2		
		/*8  */ nrpnArray.add(7  );	// shapeOsc2			
		/*9  */ nrpnArray.add(8  );	// glideOsc2			
		/*10 */ nrpnArray.add(9  );	// keyTrackOsc2		
		/*11 */ nrpnArray.add(115);	// subLevelOsc2		
		/*12 */ nrpnArray.add(10 );	// oscSync				
		/*13 */ nrpnArray.add(11 );	// glideMode			
		/*14 */ nrpnArray.add(12 );	// oscSlop				
		/*15 */ nrpnArray.add(93 );	// bendRange			
		/*16 */ nrpnArray.add(96 );	// notePriority		
		/*17 */ nrpnArray.add(13 );	// oscMix				
		/*18 */ nrpnArray.add(14 );	// noiseLevel			
		/*19 */ nrpnArray.add(116);	// extInLevel			
		/*20 */ nrpnArray.add(15 );	// lpfFreq				
		/*21 */ nrpnArray.add(16 );	// lpfReso				
		/*22 */ nrpnArray.add(17 );	// lpfKeyAmount		
		/*23 */ nrpnArray.add(18 );	// lpfFMamount			
		/*24 */ nrpnArray.add(19 );	// lpfType				
		/*25 */ nrpnArray.add(20 );	// lpfEnvAmount		
		/*26 */ nrpnArray.add(21 );	// lpfVelAmount		
		/*27 */ nrpnArray.add(22 );	// lpfDelay			
		/*28 */ nrpnArray.add(23 );	// lpfAttack			
		/*29 */ nrpnArray.add(24 );	// lpfDecay			
		/*30 */ nrpnArray.add(25 );	// lpfSustain			
		/*31 */ nrpnArray.add(26 );	// lpfRelease			
		/*32 */ nrpnArray.add(27 );	// vcaLevel			
		/*33 */ nrpnArray.add(30 );	// vcaEnvAmount		
		/*34 */ nrpnArray.add(31 );	// vcaVelAmount		
		/*35 */ nrpnArray.add(32 );	// vcaDelay			
		/*36 */ nrpnArray.add(33 );	// vcaAttack			
		/*37 */ nrpnArray.add(34 );	// vcaDecay			
		/*38 */ nrpnArray.add(35 );	// vcaSustain			
		/*39 */ nrpnArray.add(36 );	// vcaRelease			
		/*40 */ nrpnArray.add(29 );	// pgmVolume			
		/*41 */ nrpnArray.add(37 );	// lfo1Freq			
		/*42 */ nrpnArray.add(38 );	// lfo1Shape			
		/*43 */ nrpnArray.add(39 );	// lfo1Amount			
		/*44 */ nrpnArray.add(40 );	// lfo1Destination		
		/*45 */ nrpnArray.add(41 );	// lfo1KeySync			
		/*46 */ nrpnArray.add(42 );	// lfo2Freq			
		/*47 */ nrpnArray.add(43 );	// lfo2Shape			
		/*48 */ nrpnArray.add(44 );	// lfo2Amount			
		/*49 */ nrpnArray.add(45 );	// lfo2Destination		
		/*50 */ nrpnArray.add(46 );	// lfo2KeySync			
		/*51 */ nrpnArray.add(47 );	// lfo3Freq			
		/*52 */ nrpnArray.add(48 );	// lfo3Shape			
		/*53 */ nrpnArray.add(49 );	// lfo3Amount			
		/*54 */ nrpnArray.add(50 );	// lfo3Destination		
		/*55 */ nrpnArray.add(51 );	// lfo3KeySync			
		/*56 */ nrpnArray.add(52 );	// lfo4Freq			
		/*57 */ nrpnArray.add(53 );	// lfo4Shape			
		/*58 */ nrpnArray.add(54 );	// lfo4Amount			
		/*59 */ nrpnArray.add(55 );	// lfo4Destination		
		/*60 */ nrpnArray.add(56 );	// lfo4KeySync			
		/*61 */ nrpnArray.add(57 );	// env3Destination		
		/*62 */ nrpnArray.add(58 );	// env3Amount			
		/*63 */ nrpnArray.add(59 );	// env3VelAmount		
		/*64 */ nrpnArray.add(60 );	// env3Delay			
		/*65 */ nrpnArray.add(61 );	// env3Attack			
		/*66 */ nrpnArray.add(62 );	// env3Decay			
		/*67 */ nrpnArray.add(63 );	// env3Sustain			
		/*68 */ nrpnArray.add(64 );	// env3Release			
		/*69 */ nrpnArray.add(98 );	// env3Repeat			
		/*70 */ nrpnArray.add(65 );	// mod1Source			
		/*71 */ nrpnArray.add(66 );	// mod1Amount			
		/*72 */ nrpnArray.add(67 );	// mod1Destination		
		/*73 */ nrpnArray.add(68 );	// mod2Source			
		/*74 */ nrpnArray.add(69 );	// mod2Amount			
		/*75 */ nrpnArray.add(70 );	// mod2Destination		
		/*76 */ nrpnArray.add(71 );	// mod3Source			
		/*77 */ nrpnArray.add(72 );	// mod3Amount			
		/*78 */ nrpnArray.add(73 );	// mod3Destination		
		/*79 */ nrpnArray.add(74 );	// mod4Source			
		/*80 */ nrpnArray.add(75 );	// mod4Amount			
		/*81 */ nrpnArray.add(76 );	// mod4Destination		
		/*82 */ nrpnArray.add(81 );	// modWheelAmount		
		/*83 */ nrpnArray.add(82 );	// modWheelDest		
		/*84 */ nrpnArray.add(83 );	// pressureAmount		
		/*85 */ nrpnArray.add(84 );	// pressureDest		
		/*86 */ nrpnArray.add(85 );	// breathAmount		
		/*87 */ nrpnArray.add(86 );	// breathDest			
		/*88 */ nrpnArray.add(87 );	// velocityAmount		
		/*89 */ nrpnArray.add(88 );	// velocityDest		
		/*90 */ nrpnArray.add(89 );	// footPedalAmount		
		/*91 */ nrpnArray.add(90 );	// footPedalDest		
		/*92 */ nrpnArray.add(111);	// pushItPitch			
		/*93 */ nrpnArray.add(112);	// pushItVelocity		
		/*94 */ nrpnArray.add(113);	// pushItMode			
		/*95 */ nrpnArray.add(91 );	// clockTempo			
		/*96 */ nrpnArray.add(92 );	// clockDivide			
		/*97 */ nrpnArray.add(97 );	// arpegMode			
		/*98 */ nrpnArray.add(100);	// arpegOnOff			
		/*99 */ nrpnArray.add(94 );	// sequencerTrig		
		/*100*/ nrpnArray.add(101);	// sequencerOnOff		
		/*101*/ nrpnArray.add(77 );	// track1Dest			
		/*102*/ nrpnArray.add(78 );	// track2Dest			
		/*103*/ nrpnArray.add(79 );	// track3Dest			
		/*104*/ nrpnArray.add(80 );	// track4Dest			
		/*105*/ nrpnArray.add(105);	// assignKnob1			
		/*106*/ nrpnArray.add(106);	// assignKnob2			
		/*107*/ nrpnArray.add(107);	// assignKnob3			
		/*108*/ nrpnArray.add(108);	// assignKnob4			
		/*109*/ nrpnArray.add(109);	// unassigned109		
		/*110*/ nrpnArray.add(110);	// unassigned110		
		/*111*/ nrpnArray.add(111);	// unassigned111		
		/*112*/ nrpnArray.add(112);	// unassigned112		
		/*113*/ nrpnArray.add(113);	// unassigned113		
		/*114*/ nrpnArray.add(114);	// unassigned114		
		/*115*/ nrpnArray.add(115);	// unassigned115		
		/*116*/ nrpnArray.add(116);	// unassigned116		
		/*117*/ nrpnArray.add(117);	// unassigned117		
		/*118*/ nrpnArray.add(118);	// unassigned118		
		/*119*/ nrpnArray.add(119);	// unassigned119		
		/*120*/ nrpnArray.add(120);	// track1Step1  		
		/*121*/ nrpnArray.add(121);	// track1Step2  		
		/*122*/ nrpnArray.add(122);	// track1Step3  		
		/*123*/ nrpnArray.add(123);	// track1Step4  		
		/*124*/ nrpnArray.add(124);	// track1Step5  		
		/*125*/ nrpnArray.add(125);	// track1Step6  		
		/*126*/ nrpnArray.add(126);	// track1Step7  		
		/*127*/ nrpnArray.add(127);	// track1Step8  		
		/*128*/ nrpnArray.add(128);	// track1Step9  		
		/*129*/ nrpnArray.add(129);	// track1Step10		
		/*130*/ nrpnArray.add(130);	// track1Step11		
		/*131*/ nrpnArray.add(131);	// track1Step12		
		/*132*/ nrpnArray.add(132);	// track1Step13		
		/*133*/ nrpnArray.add(133);	// track1Step14		
		/*134*/ nrpnArray.add(134);	// track1Step15		
		/*135*/ nrpnArray.add(135);	// track1Step16		
		/*136*/ nrpnArray.add(136);	// track2Step1  		
		/*137*/ nrpnArray.add(137);	// track2Step2  		
		/*138*/ nrpnArray.add(138);	// track2Step3  		
		/*139*/ nrpnArray.add(139);	// track2Step4  		
		/*140*/ nrpnArray.add(140);	// track2Step5  		
		/*141*/ nrpnArray.add(141);	// track2Step6  		
		/*142*/ nrpnArray.add(142);	// track2Step7  		
		/*143*/ nrpnArray.add(143);	// track2Step8  		
		/*144*/ nrpnArray.add(144);	// track2Step9  		
		/*145*/ nrpnArray.add(145);	// track2Step10		
		/*146*/ nrpnArray.add(146);	// track2Step11		
		/*147*/ nrpnArray.add(147);	// track2Step12		
		/*148*/ nrpnArray.add(148);	// track2Step13		
		/*149*/ nrpnArray.add(149);	// track2Step14		
		/*150*/ nrpnArray.add(150);	// track2Step15		
		/*151*/ nrpnArray.add(151);	// track2Step16		
		/*152*/ nrpnArray.add(152);	// track3Step1  		
		/*153*/ nrpnArray.add(153);	// track3Step2  		
		/*154*/ nrpnArray.add(154);	// track3Step3  		
		/*155*/ nrpnArray.add(155);	// track3Step4  		
		/*156*/ nrpnArray.add(156);	// track3Step5  		
		/*157*/ nrpnArray.add(157);	// track3Step6  		
		/*158*/ nrpnArray.add(158);	// track3Step7  		
		/*159*/ nrpnArray.add(159);	// track3Step8  		
		/*160*/ nrpnArray.add(160);	// track3Step9  		
		/*161*/ nrpnArray.add(161);	// track3Step10		
		/*162*/ nrpnArray.add(162);	// track3Step11		
		/*163*/ nrpnArray.add(163);	// track3Step12		
		/*164*/ nrpnArray.add(164);	// track3Step13		
		/*165*/ nrpnArray.add(165);	// track3Step14		
		/*166*/ nrpnArray.add(166);	// track3Step15		
		/*167*/ nrpnArray.add(167);	// track3Step16		
		/*168*/ nrpnArray.add(168);	// track4Step1  		
		/*169*/ nrpnArray.add(169);	// track4Step2  		
		/*170*/ nrpnArray.add(170);	// track4Step3  		
		/*171*/ nrpnArray.add(171);	// track4Step4  		
		/*172*/ nrpnArray.add(172);	// track4Step5  		
		/*173*/ nrpnArray.add(173);	// track4Step6  		
		/*174*/ nrpnArray.add(174);	// track4Step7  		
		/*175*/ nrpnArray.add(175);	// track4Step8  		
		/*176*/ nrpnArray.add(176);	// track4Step9  		
		/*177*/ nrpnArray.add(177);	// track4Step10		
		/*178*/ nrpnArray.add(178);	// track4Step11		
		/*179*/ nrpnArray.add(179);	// track4Step12		
		/*180*/ nrpnArray.add(180);	// track4Step13		
		/*181*/ nrpnArray.add(181);	// track4Step14		
		/*182*/ nrpnArray.add(182);	// track4Step15		
		/*183*/ nrpnArray.add(183);	// track4Step16		
		/*184*/ nrpnArray.add(184);	// nameChar1 			
		/*185*/ nrpnArray.add(185);	// nameChar2 			
		/*186*/ nrpnArray.add(186);	// nameChar3 			
		/*187*/ nrpnArray.add(187);	// nameChar4 			
		/*188*/ nrpnArray.add(188);	// nameChar5 			
		/*189*/ nrpnArray.add(189);	// nameChar6 			
		/*190*/ nrpnArray.add(190);	// nameChar7 			
		/*191*/ nrpnArray.add(191);	// nameChar8 			
		/*192*/ nrpnArray.add(192);	// nameChar9 			
		/*193*/ nrpnArray.add(193);	// nameChar10			
		/*194*/ nrpnArray.add(194);	// nameChar11			
		/*195*/ nrpnArray.add(195);	// nameChar12			
		/*196*/ nrpnArray.add(196);	// nameChar13			
		/*197*/ nrpnArray.add(197);	// nameChar14			
		/*198*/ nrpnArray.add(198);	// nameChar15			
		/*199*/ nrpnArray.add(199);	// nameChar16			
	}
};

