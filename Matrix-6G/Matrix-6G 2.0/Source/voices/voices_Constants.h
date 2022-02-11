#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace voices
	{
		static const int numberOfSlotsInBank{ 100 };
		static const int rawVoiceDataVectorChecksumByteIndex{ 272 };

		static const String basicVoiceDataHexString{ "20103190300202020000F1F1302000F181301020F100002000007300002000F300000082000000009000E1000000009000000000A023A0820000000000A023A08200000000004100418200009000F0F1F2F30000000000000000A20000F3F3F3F3F3F30000000000110001110051B000904100800000000000000000000000000000000000006F" };
		static const String basicVoiceNameString{ "BASIC   " };

		static const uint8 indexOfLastDataByteBeforeExposedParams{ 16 };
		static const uint8 indexOfLastDataByteBeforeMatrixModSettings{ 192 };
	}
}