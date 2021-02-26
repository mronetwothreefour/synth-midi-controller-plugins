#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace patches
	{
		static const int numberOfSlotsInBank{ 100 };
		static const int rawPatchDataVectorChecksumByteIndex{ 272 };
		static const int rawPatchDataVectorNumberOfHeaderBytes{ 4 };

		static const String basicPatchDataHexString{ "20103190300202020000F1F1302000F181301020F100002000007300002000F300000082000000009000E1000000009000000000A023A0820000000000A023A08200000000004100418200009000F0F1F2F30000000000000000A20000F3F3F3F3F3F30000000000110001110051B000904100800000000000000000000000000000000000006F" };
		static const String basicPatchNameString{ "BASIC   " };

		static const uint8 indexOfLastDataByteBeforeExposedParams{ 16 };
		static const uint8 indexOfLastDataByteBeforeMatrixModSettings{ 192 };
		static const uint8 numberOfHeaderBytesInPatchDataMessage{ 4 };
		static const uint8 seventhBit{ 64 };
		static const uint8 sixthBit{ 32 };
		static const uint8 valueForBarSymbol_ASCII{ 124 };
		static const uint8 valueForBarSymbol_Matrix{ 29 };
	}
}