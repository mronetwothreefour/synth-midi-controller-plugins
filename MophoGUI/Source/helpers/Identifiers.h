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
	const Identifier subOsc1Level		{ "subOsc1Level"	};
	const Identifier osc2Pitch			{ "osc2Pitch"		};
	const Identifier osc2Fine			{ "osc2Fine"		};
	const Identifier osc2Shape			{ "osc2Shape"		};
	const Identifier osc2Glide			{ "osc2Glide"		};
	const Identifier osc2KeyTrack		{ "osc2KeyTrack"	};
	const Identifier subOsc2Level		{ "subOsc2Level"	};

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

	const Identifier vcaInitLevel		{ "vcaInitLevel"	};
	const Identifier vcaAmount			{ "vcaAmount"		};
	const Identifier vcaVelAmount		{ "vcaVelAmount"	};
	const Identifier vcaDelay			{ "vcaDelay"		};
	const Identifier vcaAttack			{ "vcaAttack"		};
	const Identifier vcaDecay			{ "vcaDecay"		};
	const Identifier vcaSustain			{ "vcaSustain"		};
	const Identifier vcaRelease			{ "vcaRelease"		};
	const Identifier voiceVolume		{ "voiceVolume"		};

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
	const Identifier seqTrack1Dest		{ "seqTrack1Dest"	};
	const Identifier seqTrack2Dest		{ "seqTrack2Dest"	};
	const Identifier seqTrack3Dest		{ "seqTrack3Dest"	};
	const Identifier seqTrack4Dest		{ "seqTrack4Dest"	};

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

	const Identifier seq1Step01 		{ "seq1Step01"		};
	const Identifier seq1Step02 		{ "seq1Step02"		};
	const Identifier seq1Step03 		{ "seq1Step03"		};
	const Identifier seq1Step04 		{ "seq1Step04"		};
	const Identifier seq1Step05 		{ "seq1Step05"		};
	const Identifier seq1Step06 		{ "seq1Step06"		};
	const Identifier seq1Step07 		{ "seq1Step07"		};
	const Identifier seq1Step08 		{ "seq1Step08"		};
	const Identifier seq1Step09 		{ "seq1Step09"		};
	const Identifier seq1Step10			{ "seq1Step10"		};
	const Identifier seq1Step11			{ "seq1Step11"		};
	const Identifier seq1Step12			{ "seq1Step12"		};
	const Identifier seq1Step13			{ "seq1Step13"		};
	const Identifier seq1Step14			{ "seq1Step14"		};
	const Identifier seq1Step15			{ "seq1Step15"		};
	const Identifier seq1Step16			{ "seq1Step16"		};

	const Identifier seq2Step01 		{ "seq2Step01"		};
	const Identifier seq2Step02 		{ "seq2Step02"		};
	const Identifier seq2Step03 		{ "seq2Step03"		};
	const Identifier seq2Step04 		{ "seq2Step04"		};
	const Identifier seq2Step05 		{ "seq2Step05"		};
	const Identifier seq2Step06 		{ "seq2Step06"		};
	const Identifier seq2Step07 		{ "seq2Step07"		};
	const Identifier seq2Step08 		{ "seq2Step08"		};
	const Identifier seq2Step09 		{ "seq2Step09"		};
	const Identifier seq2Step10			{ "seq2Step10"		};
	const Identifier seq2Step11			{ "seq2Step11"		};
	const Identifier seq2Step12			{ "seq2Step12"		};
	const Identifier seq2Step13			{ "seq2Step13"		};
	const Identifier seq2Step14			{ "seq2Step14"		};
	const Identifier seq2Step15			{ "seq2Step15"		};
	const Identifier seq2Step16			{ "seq2Step16"		};

	const Identifier seq3Step01 		{ "seq3Step01"		};
	const Identifier seq3Step02 		{ "seq3Step02"		};
	const Identifier seq3Step03 		{ "seq3Step03"		};
	const Identifier seq3Step04 		{ "seq3Step04"		};
	const Identifier seq3Step05 		{ "seq3Step05"		};
	const Identifier seq3Step06 		{ "seq3Step06"		};
	const Identifier seq3Step07 		{ "seq3Step07"		};
	const Identifier seq3Step08 		{ "seq3Step08"		};
	const Identifier seq3Step09 		{ "seq3Step09"		};
	const Identifier seq3Step10			{ "seq3Step10"		};
	const Identifier seq3Step11			{ "seq3Step11"		};
	const Identifier seq3Step12			{ "seq3Step12"		};
	const Identifier seq3Step13			{ "seq3Step13"		};
	const Identifier seq3Step14			{ "seq3Step14"		};
	const Identifier seq3Step15			{ "seq3Step15"		};
	const Identifier seq3Step16			{ "seq3Step16"		};

	const Identifier seq4Step01 		{ "seq4Step01"		};
	const Identifier seq4Step02 		{ "seq4Step02"		};
	const Identifier seq4Step03 		{ "seq4Step03"		};
	const Identifier seq4Step04 		{ "seq4Step04"		};
	const Identifier seq4Step05 		{ "seq4Step05"		};
	const Identifier seq4Step06 		{ "seq4Step06"		};
	const Identifier seq4Step07 		{ "seq4Step07"		};
	const Identifier seq4Step08 		{ "seq4Step08"		};
	const Identifier seq4Step09 		{ "seq4Step09"		};
	const Identifier seq4Step10			{ "seq4Step10"		};
	const Identifier seq4Step11			{ "seq4Step11"		};
	const Identifier seq4Step12			{ "seq4Step12"		};
	const Identifier seq4Step13			{ "seq4Step13"		};
	const Identifier seq4Step14			{ "seq4Step14"		};
	const Identifier seq4Step15			{ "seq4Step15"		};
	const Identifier seq4Step16			{ "seq4Step16"		};

	const Identifier nameChar01 		{ "nameChar01"		};
	const Identifier nameChar02 		{ "nameChar02"		};
	const Identifier nameChar03 		{ "nameChar03"		};
	const Identifier nameChar04 		{ "nameChar04"		};
	const Identifier nameChar05 		{ "nameChar05"		};
	const Identifier nameChar06 		{ "nameChar06"		};
	const Identifier nameChar07 		{ "nameChar07"		};
	const Identifier nameChar08 		{ "nameChar08"		};
	const Identifier nameChar09 		{ "nameChar09"		};
	const Identifier nameChar10			{ "nameChar10"		};
	const Identifier nameChar11			{ "nameChar11"		};
	const Identifier nameChar12			{ "nameChar12"		};
	const Identifier nameChar13			{ "nameChar13"		};
	const Identifier nameChar14			{ "nameChar14"		};
	const Identifier nameChar15			{ "nameChar15"		};
	const Identifier nameChar16			{ "nameChar16"		};

	//==============================================================================
	const Identifier tooltipOptions		{ "tooltipOptions"	};
	const Identifier showCurrentVal		{ "showCurrentVal"	};
	const Identifier showParamInfo		{ "showParamInfo"	};
	const Identifier tooltipDelay		{ "tooltipDelay"	};
} // namespace ID