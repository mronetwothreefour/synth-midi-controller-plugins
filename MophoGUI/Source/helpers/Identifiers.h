#pragma once

#include <JuceHeader.h>

namespace ID
{
	//==============================================================================
	const Identifier publicParams		{ "publicParams"	};

	const Identifier osc1Pitch			{ "osc1Pitch"		};
	const Identifier osc1Fine			{ "osc1Fine"		};
	const Identifier osc1Shape			{ "osc1Shape"		};
	const Identifier osc1Glide			{ "osc1Glide"		};
	const Identifier osc1KeyTrack		{ "osc1KeyTrack"	};
	const Identifier osc1SubLevel		{ "osc1SubLevel"	};
	const Identifier osc2Pitch			{ "osc2Pitch"		};
	const Identifier osc2Fine			{ "osc2Fine"		};
	const Identifier osc2Shape			{ "osc2Shape"		};
	const Identifier osc2Glide			{ "osc2Glide"		};
	const Identifier osc2KeyTrack		{ "osc2KeyTrack"	};
	const Identifier osc2SubLevel		{ "osc2SubLevel"	};

	const Identifier oscSync			{ "oscSync"			};
	const Identifier glideMode			{ "glideMode"		};
	const Identifier oscSlop			{ "oscSlop"			};
	const Identifier bendRange			{ "bendRange"		};
	const Identifier notePriority		{ "notePriority"	};

	const Identifier oscMix				{ "oscMix"			};
	const Identifier noiseLevel			{ "noiseLevel"		};
	const Identifier extInLevel			{ "extInLevel"		};

	const Identifier lpfFreq			{ "lpfFreq"			};
	const Identifier lpfReso			{ "lpfReso"			};
	const Identifier lpfKeyAmount		{ "lpfKeyAmount"	};
	const Identifier lpfFMamount		{ "lpfFMamount"		};
	const Identifier lpfType			{ "lpfType"			};
	const Identifier lpfEnvAmount		{ "lpfEnvAmount"	};
	const Identifier lpfVelAmount		{ "lpfVelAmount"	};
	const Identifier lpfDelay			{ "lpfDelay"		};
	const Identifier lpfAttack			{ "lpfAttack"		};
	const Identifier lpfDecay			{ "lpfDecay"		};
	const Identifier lpfSustain			{ "lpfSustain"		};
	const Identifier lpfRelease			{ "lpfRelease"		};

	const Identifier vcaLevel			{ "vcaLevel"		};
	const Identifier vcaEnvAmount		{ "vcaEnvAmount"	};
	const Identifier vcaVelAmount		{ "vcaVelAmount"	};
	const Identifier vcaDelay			{ "vcaDelay"		};
	const Identifier vcaAttack			{ "vcaAttack"		};
	const Identifier vcaDecay			{ "vcaDecay"		};
	const Identifier vcaSustain			{ "vcaSustain"		};
	const Identifier vcaRelease			{ "vcaRelease"		};
	const Identifier pgmVolume			{ "pgmVolume"		};

	const Identifier lfo1Freq			{ "lfo1Freq"		};
	const Identifier lfo1Shape			{ "lfo1Shape"		};
	const Identifier lfo1Amount			{ "lfo1Amount"		};
	const Identifier lfo1Destination	{ "lfo1Destination"	};
	const Identifier lfo1KeySync		{ "lfo1KeySync"		};
	const Identifier lfo2Freq			{ "lfo2Freq"		};
	const Identifier lfo2Shape			{ "lfo2Shape"		};
	const Identifier lfo2Amount			{ "lfo2Amount"		};
	const Identifier lfo2Destination	{ "lfo2Destination"	};
	const Identifier lfo2KeySync		{ "lfo2KeySync"		};
	const Identifier lfo3Freq			{ "lfo3Freq"		};
	const Identifier lfo3Shape			{ "lfo3Shape"		};
	const Identifier lfo3Amount			{ "lfo3Amount"		};
	const Identifier lfo3Destination	{ "lfo3Destination"	};
	const Identifier lfo3KeySync		{ "lfo3KeySync"		};
	const Identifier lfo4Freq			{ "lfo4Freq"		};
	const Identifier lfo4Shape			{ "lfo4Shape"		};
	const Identifier lfo4Amount			{ "lfo4Amount"		};
	const Identifier lfo4Destination	{ "lfo4Destination"	};
	const Identifier lfo4KeySync		{ "lfo4KeySync"		};

	const Identifier env3Destination	{ "env3Destination"	};
	const Identifier env3Amount			{ "env3Amount"		};
	const Identifier env3VelAmount		{ "env3VelAmount"	};
	const Identifier env3Delay			{ "env3Delay"		};
	const Identifier env3Attack			{ "env3Attack"		};
	const Identifier env3Decay			{ "env3Decay"		};
	const Identifier env3Sustain		{ "env3Sustain"		};
	const Identifier env3Release		{ "env3Release"		};
	const Identifier env3Repeat			{ "env3Repeat"		};

	const Identifier mod1Source			{ "mod1Source"		};
	const Identifier mod1Amount			{ "mod1Amount"		};
	const Identifier mod1Destination	{ "mod1Destination" };
	const Identifier mod2Source			{ "mod2Source"		};
	const Identifier mod2Amount			{ "mod2Amount"		};
	const Identifier mod2Destination	{ "mod2Destination" };
	const Identifier mod3Source			{ "mod3Source"		};
	const Identifier mod3Amount			{ "mod3Amount"		};
	const Identifier mod3Destination	{ "mod3Destination" };
	const Identifier mod4Source			{ "mod4Source"		};
	const Identifier mod4Amount			{ "mod4Amount"		};
	const Identifier mod4Destination	{ "mod4Destination" };

	const Identifier modWheelAmount		{ "modWheelAmount"	};
	const Identifier modWheelDest		{ "modWheelDest"	};
	const Identifier aftertouchAmount	{ "aftertouchAmount"};
	const Identifier aftertouchDest		{ "aftertouchDest"	};
	const Identifier breathAmount		{ "breathAmount"	};
	const Identifier breathDest			{ "breathDest"		};
	const Identifier velocityAmount		{ "velocityAmount"	};
	const Identifier velocityDest		{ "velocityDest"	};
	const Identifier footPedalAmount	{ "footPedalAmount"	};
	const Identifier footPedalDest		{ "footPedalDest"	};

	const Identifier pushItPitch		{ "pushItPitch"		};
	const Identifier pushItVelocity		{ "pushItVelocity"	};
	const Identifier pushItMode			{ "pushItMode"		};

	const Identifier clockTempo			{ "clockTempo"		};
	const Identifier clockDivide		{ "clockDivide"		};

	const Identifier arpegMode			{ "arpegMode"		};
	const Identifier arpegOnOff			{ "arpegOnOff"		};

	const Identifier sequencerTrig		{ "sequencerTrig"	};
	const Identifier sequencerOnOff		{ "sequencerOnOff"	};
	const Identifier track1Dest			{ "track1Dest"		};
	const Identifier track2Dest			{ "track2Dest"		};
	const Identifier track3Dest			{ "track3Dest"		};
	const Identifier track4Dest			{ "track4Dest"		};

	const Identifier assignKnob1		{ "assignKnob1"		};
	const Identifier assignKnob2		{ "assignKnob2"		};
	const Identifier assignKnob3		{ "assignKnob3"		};
	const Identifier assignKnob4		{ "assignKnob4"		};

	const Identifier unassigned109		{ "unassigned109"	};
	const Identifier unassigned110		{ "unassigned110"	};
	const Identifier unassigned111		{ "unassigned111"	};
	const Identifier unassigned112		{ "unassigned112"	};
	const Identifier unassigned113		{ "unassigned113"	};
	const Identifier unassigned114		{ "unassigned114"	};
	const Identifier unassigned115		{ "unassigned115"	};
	const Identifier unassigned116		{ "unassigned116"	};
	const Identifier unassigned117		{ "unassigned117"	};
	const Identifier unassigned118		{ "unassigned118"	};
	const Identifier unassigned119		{ "unassigned119"	};

	const Identifier track1Step1  		{ "track1Step1"		};
	const Identifier track1Step2  		{ "track1Step2"		};
	const Identifier track1Step3  		{ "track1Step3"		};
	const Identifier track1Step4  		{ "track1Step4"		};
	const Identifier track1Step5  		{ "track1Step5"		};
	const Identifier track1Step6  		{ "track1Step6"		};
	const Identifier track1Step7  		{ "track1Step7"		};
	const Identifier track1Step8  		{ "track1Step8"		};
	const Identifier track1Step9  		{ "track1Step9"		};
	const Identifier track1Step10		{ "track1Step10"	};
	const Identifier track1Step11		{ "track1Step11"	};
	const Identifier track1Step12		{ "track1Step12"	};
	const Identifier track1Step13		{ "track1Step13"	};
	const Identifier track1Step14		{ "track1Step14"	};
	const Identifier track1Step15		{ "track1Step15"	};
	const Identifier track1Step16		{ "track1Step16"	};

	const Identifier track2Step1  		{ "track2Step1"		};
	const Identifier track2Step2  		{ "track2Step2"		};
	const Identifier track2Step3  		{ "track2Step3"		};
	const Identifier track2Step4  		{ "track2Step4"		};
	const Identifier track2Step5  		{ "track2Step5"		};
	const Identifier track2Step6  		{ "track2Step6"		};
	const Identifier track2Step7  		{ "track2Step7"		};
	const Identifier track2Step8  		{ "track2Step8"		};
	const Identifier track2Step9  		{ "track2Step9"		};
	const Identifier track2Step10		{ "track2Step10"	};
	const Identifier track2Step11		{ "track2Step11"	};
	const Identifier track2Step12		{ "track2Step12"	};
	const Identifier track2Step13		{ "track2Step13"	};
	const Identifier track2Step14		{ "track2Step14"	};
	const Identifier track2Step15		{ "track2Step15"	};
	const Identifier track2Step16		{ "track2Step16"	};

	const Identifier track3Step1  		{ "track3Step1"		};
	const Identifier track3Step2  		{ "track3Step2"		};
	const Identifier track3Step3  		{ "track3Step3"		};
	const Identifier track3Step4  		{ "track3Step4"		};
	const Identifier track3Step5  		{ "track3Step5"		};
	const Identifier track3Step6  		{ "track3Step6"		};
	const Identifier track3Step7  		{ "track3Step7"		};
	const Identifier track3Step8  		{ "track3Step8"		};
	const Identifier track3Step9  		{ "track3Step9"		};
	const Identifier track3Step10		{ "track3Step10"	};
	const Identifier track3Step11		{ "track3Step11"	};
	const Identifier track3Step12		{ "track3Step12"	};
	const Identifier track3Step13		{ "track3Step13"	};
	const Identifier track3Step14		{ "track3Step14"	};
	const Identifier track3Step15		{ "track3Step15"	};
	const Identifier track3Step16		{ "track3Step16"	};

	const Identifier track4Step1  		{ "track4Step1"		};
	const Identifier track4Step2  		{ "track4Step2"		};
	const Identifier track4Step3  		{ "track4Step3"		};
	const Identifier track4Step4  		{ "track4Step4"		};
	const Identifier track4Step5  		{ "track4Step5"		};
	const Identifier track4Step6  		{ "track4Step6"		};
	const Identifier track4Step7  		{ "track4Step7"		};
	const Identifier track4Step8  		{ "track4Step8"		};
	const Identifier track4Step9  		{ "track4Step9"		};
	const Identifier track4Step10		{ "track4Step10"	};
	const Identifier track4Step11		{ "track4Step11"	};
	const Identifier track4Step12		{ "track4Step12"	};
	const Identifier track4Step13		{ "track4Step13"	};
	const Identifier track4Step14		{ "track4Step14"	};
	const Identifier track4Step15		{ "track4Step15"	};
	const Identifier track4Step16		{ "track4Step16"	};

	const Identifier nameChar1 			{ "nameChar1"		};
	const Identifier nameChar2 			{ "nameChar2"		};
	const Identifier nameChar3 			{ "nameChar3"		};
	const Identifier nameChar4 			{ "nameChar4"		};
	const Identifier nameChar5 			{ "nameChar5"		};
	const Identifier nameChar6 			{ "nameChar6"		};
	const Identifier nameChar7 			{ "nameChar7"		};
	const Identifier nameChar8 			{ "nameChar8"		};
	const Identifier nameChar9 			{ "nameChar9"		};
	const Identifier nameChar10			{ "nameChar10"		};
	const Identifier nameChar11			{ "nameChar11"		};
	const Identifier nameChar12			{ "nameChar12"		};
	const Identifier nameChar13			{ "nameChar13"		};
	const Identifier nameChar14			{ "nameChar14"		};
	const Identifier nameChar15			{ "nameChar15"		};
	const Identifier nameChar16			{ "nameChar16"		};

	//==============================================================================
	const Identifier paramToggle		{ "paramToggle"		};
	const Identifier pgmSlotToggle		{ "pgmSlotToggle"	};

	//==============================================================================
	const Identifier globalOptions		{ "globalOptions"	};
	const Identifier hardwareLink		{ "hardwareLink"	};
	const Identifier masterTranspose	{ "masterTranspose"	};
	const Identifier masterFineTune		{ "masterFineTune"	};
	const Identifier midiChannel		{ "midiChannel"		};
	const Identifier midiClock			{ "midiClock"		};
	const Identifier parameterSend		{ "parameterSend"	};
	const Identifier parameterReceive	{ "parameterReceive"};
	const Identifier midiControllers	{ "midiControllers"	};
	const Identifier stereoAudioOut		{ "stereoAudioOut"	};
	const Identifier midiThru			{ "midiThru"		};
	const Identifier transmitTime		{ "transmitTime"	};

	const Identifier tooltipOptions		{ "tooltipOptions"	};
	const Identifier showCurrentVal		{ "showCurrentVal"	};
	const Identifier showParamInfo		{ "showParamInfo"	};
	const Identifier tooltipDelay		{ "tooltipDelay"	};

	const Identifier programBank1		{ "programBank1" };
	const Identifier programBank2		{ "programBank2" };
	const Identifier programBank3		{ "programBank3" };

} // namespace ID