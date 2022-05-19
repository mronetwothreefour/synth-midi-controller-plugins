#pragma once

#include <JuceHeader.h>



namespace mophoConstants
{
	namespace EP
	{
		static const uint8 firstLFO_PitchedFreqChoice{ 90 };
		static const uint8 firstLFO_SyncedFreqChoice{ 151 };
		static const uint8 numberOfChoicesForBendRange{ 13 };
		static const uint8 numberOfChoicesForClockTempo{ 221 };
		static const uint8 numberOfChoicesForLFO_Freq{ 167 };
		static const uint8 numberOfChoicesForLPF_Freq{ 165 };
		static const uint8 numberOfChoicesForModDest{ 47 };
		static const uint8 numberOfChoicesForModSource{ 23 };
		static const uint8 numberOfChoicesForOscFineTune{ 101 };
		static const uint8 numberOfChoicesForOscPitch{ 121 };
		static const uint8 numberOfChoicesForOscWaveShape{ 104 };
		static const uint8 numberOfChoicesForSeqTracks_2_4_Dest{ 48 };

		static const uint8 numberOfExposedParams{ 189 };
	}
}