#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace splits
	{
		static const int numberOfSlotsInBank{ 50 };
		static const int rawSplitDataVectorChecksumByteIndex{ 40 };

		static const uint8 indexOfLastDataByteBeforeSpltsParams{ 16 };
		static const uint8 indexOfLowerZoneLimitLSByte{ 0 };
		static const uint8 indexOfLowerZoneTransposeLSByte{ indexOfLowerZoneLimitLSByte + 2 };
		static const uint8 indexOfLowerZoneMIDIoutLSByte{ indexOfLowerZoneTransposeLSByte + 2 };
		static const uint8 indexOfUpperZoneLimitLSByte{ indexOfLowerZoneMIDIoutLSByte + 2 };
		static const uint8 indexOfUpperZoneTransposeLSByte{ indexOfUpperZoneLimitLSByte + 2 };
		static const uint8 indexOfUpperZoneMIDIoutLSByte{ indexOfUpperZoneTransposeLSByte + 2 };
		static const uint8 indexOfZoneVolumeBalanceLSByte{ indexOfUpperZoneMIDIoutLSByte + 2 };
		static const uint8 indexOfZoneVoiceAssignmentLSByte{ indexOfZoneVolumeBalanceLSByte + 2 };
		static const uint8 indexOfLowerZoneVoiceNumberLSByte{ indexOfZoneVoiceAssignmentLSByte + 2 };
		static const uint8 indexOfUpperZoneVoiceNumberLSByte{ indexOfLowerZoneVoiceNumberLSByte + 2 };

		static const String initialSplitDataHexString{ "90E0904102020000320010420010000000103E" };
		static const String initialSplitNameString{ "INIT  " };
	}
}