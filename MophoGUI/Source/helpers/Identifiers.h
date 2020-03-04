#pragma once

#include <JuceHeader.h>

namespace ID
{
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
	const Identifier lpfOsc1FM			{ "lpfOsc1FM"		};
	const Identifier lpfType			{ "lpfType"			};
	const Identifier lpfAmount			{ "lpfAmount"		};
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
} // namespace ID