#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace params
	{
		static const uint8 arpeggiator{ 98 };
		static const uint8 clockTempoIndex{ 95 };
		static const uint8 clockTempoOffset{ 30 };
		static const uint8 firstPitchedLFOfreq{ 90 };
		static const uint8 firstSyncedLFOfreq{ 151 };
		static const uint8 knobAssignFirstIndex{ 105 };
		static const uint8 knobAssignLastIndex{ 108 };
		static const uint8 knobAssignOffset{ 15 };
		static const uint8 maxPulseWidth{ 99 };
		static const uint8 maxUnsyncedLFOfreq{ 89 };
		static const uint8 maxValueForSeqTrackStep{ 125 };
		static const uint8 numberOfKnobAssignTargets{ 169 };
		static const uint8 numberOfModDestinations{ 47 };
		static const uint8 numberOfModSources{ 23 };
		static const uint8 offsetForSpecialASCIIchars{ 32 };
		static const uint8 paramNumFor1stNameChar{ 184 };
		static const uint8 paramNumForSeqTrack1Step1{ 120 };
		static const uint8 sequencer{ 100 };
		static const uint8 seqStepValueForReset{ 126 };
		static const uint8 seqStepValueForRest{ 127 };
		static const uint8 seqStepValueForRepeat{ 128 };

		static const uint16 numberOfExposedParams{ 189 };
	}
}