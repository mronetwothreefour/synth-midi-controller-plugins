#pragma once

#include <JuceHeader.h>



namespace MophoConstants
{
	namespace EP
	{
		const uint8 choiceNumForSeqStep_Reset{ 126 };
		const uint8 choiceNumForSeqTrack1Step_Rest{ 127 };
		const uint8 clockTempoOffset{ 30 };
		const uint8 firstKnobAssignParamNumber{ 105 };
		const uint8 firstSeqStepParamNumber{ 109 };
		const uint8 firstLFO_PitchedFreqChoice{ 90 };
		const uint8 firstLFO_SyncedFreqChoice{ 151 };
		const uint8 firstVisibleVoiceNameCharNumber{ 32 };
		const uint8 firstVoiceNameCharParamNumber{ 173 };
		const uint8 indexForArpegOnOff{ 98 };
		const uint8 indexForSeqOnOff{ 100 };
		const uint8 knobAssignAndUnassignedParamsOffset{ 15 };
		const uint8 lastUnassignedParamNumber{ 119 };
		const uint8 numberOfChoicesForBendRange{ 13 };
		const uint8 numberOfChoicesForClockTempo{ 221 };
		const uint8 numberOfChoicesForLFO_Freq{ 167 };
		const uint8 numberOfChoicesForLPF_Freq{ 165 };
		const uint8 numberOfChoicesForModDest{ 47 };
		const uint8 numberOfChoicesForModSource{ 23 };
		const uint8 numberOfChoicesForOscFineTune{ 101 };
		const uint8 numberOfChoicesForOscPitch{ 121 };
		const uint8 numberOfChoicesForOscWaveShape{ 104 };
		const uint8 numberOfChoicesForSeqTrackSteps{ 126 };
		const uint8 numberOfChoicesForSeqTracks_2_4_Dest{ 48 };
		const uint8 numberOfChoicesForVoiceNameChar{ 128 };
		const uint8 numberOfExposedParams{ 189 };
		const uint8 numberOfPitchedLFO_Frequencies{ 61 };
		const uint8 numberOfPulseWidths{ 100 };
		const uint8 numberOfSyncedLFO_Frequencies{ 16 };
		const uint8 numberOfUnsyncedLFO_Frequencies{ 90 };
	}
}
