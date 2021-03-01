#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace splits
	{
		static const int numberOfSlotsInBank{ 50 };
		static const int rawSplitDataVectorChecksumByteIndex{ 40 };

		static const uint8 indexOfLastDataByteBeforeSpltsParams{ 16 };
		static const uint8 indexOfLowerZonePatchNumberLSByte{ 0 };
		static const uint8 indexOfUpperZonePatchNumberLSByte{ indexOfLowerZonePatchNumberLSByte + 2 };
		static const uint8 indexOfLowerZoneLimitLSByte{ indexOfUpperZonePatchNumberLSByte + 2 };
		static const uint8 indexOfLowerZoneTransposeLSByte{ indexOfLowerZoneLimitLSByte + 2 };
		static const uint8 indexOfLowerZoneMIDIoutLSByte{ indexOfLowerZoneTransposeLSByte + 2 };
		static const uint8 indexOfUpperZoneLimitLSByte{ indexOfLowerZoneMIDIoutLSByte + 2 };
		static const uint8 indexOfUpperZoneTransposeLSByte{ indexOfUpperZoneLimitLSByte + 2 };
		static const uint8 indexOfUpperZoneMIDIoutLSByte{ indexOfUpperZoneTransposeLSByte + 2 };
		static const uint8 indexOfZoneVolumeBalanceLSByte{ indexOfUpperZoneMIDIoutLSByte + 2 };
		static const uint8 indexOfZoneVoiceAssignmentLSByte{ indexOfZoneVolumeBalanceLSByte + 2 };

		static const String initialSplitDataHexString{ "" };
		static const String initialSplitNameString{ "INIT" };
	}
}