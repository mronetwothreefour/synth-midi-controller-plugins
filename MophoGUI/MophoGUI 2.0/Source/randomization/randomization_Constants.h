#pragma once



namespace constants
{
	namespace randomization
	{
		static const int highestNoteNumAllowedForHighestOctave_LPFfreq{ 8 };
		static const int highestNoteNumAllowedForHighestOctave_PitchAndLFOfreq{ 0 };
		static const int numberOfNotes{ 12 };
		static const int numberOfNotesAndBentNotes{ 24 };
		static const int numberOfOctaves{ 11 };
		static const int numberOfOctavesForLFOfreqAndSeqSteps{ 6 };
		static const int numberOfOctavesForLPFfreq{ 14 };
		static const int numberOfPitchedFreqForLFOs{ 61 };
		static const int numberOfPitchedFreqForLPF{ 165 };
		static const int numberOfPitchesForOscillators{ 121 };
		static const int numberOfPitchesForSeqSteps{ 126 };
		static const int numberOfSyncedFreqForLFOs{ 16 };
	}
}