#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	namespace SPLT
	{
		const int lengthOfSplitDataHexString{ 38 };
		const int numberOfCharsInSplitName{ 6 };
		const int numberOfChoicesForZoneLimit{ 128 };
		const int numberOfSlotsInSplitsBank{ 50 };
		const int rawSplitDataVectorChecksumByteIndex{ 40 };

		const uint8 indexOfLowerZoneLimitLSByte{ 16 };
		const uint8 indexOfLowerZoneTransposeLSByte{ indexOfLowerZoneLimitLSByte + 2 };
		const uint8 indexOfLowerZoneMIDIoutLSByte{ indexOfLowerZoneTransposeLSByte + 2 };
		const uint8 indexOfUpperZoneLimitLSByte{ indexOfLowerZoneMIDIoutLSByte + 2 };
		const uint8 indexOfUpperZoneTransposeLSByte{ indexOfUpperZoneLimitLSByte + 2 };
		const uint8 indexOfUpperZoneMIDIoutLSByte{ indexOfUpperZoneTransposeLSByte + 2 };
		const uint8 indexOfZoneVolumeBalanceLSByte{ indexOfUpperZoneMIDIoutLSByte + 2 };
		const uint8 indexOfZoneVoiceAssignmentLSByte{ indexOfZoneVolumeBalanceLSByte + 2 };
		const uint8 indexOfLowerZoneVoiceNumberLSByte{ indexOfZoneVoiceAssignmentLSByte + 2 };
		const uint8 indexOfUpperZoneVoiceNumberLSByte{ indexOfLowerZoneVoiceNumberLSByte + 2 };
		const uint8 offsetForSignedZoneTransposeRange{ 36 };

		const String initialSplitDataHexString{ "90E0904102020000320010420010000000103E" };
		const String initialSplitNameString{ "INIT  " };
	}
}