#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace matrixParams
	{
		static const int maxPatchNameLength{ 8 };
		static const int maxSplitNameLength{ 6 };
		static const int maxTransmitTimeDigits{ 4 };
		static const int maxTransmitTimeValue{ 5000 };
		static const int minTransmitTimeValue{ 50 };
		static const int numberOfHeaderBytesInDataDumpMessages{ 4 };

		static const int8 offsetForSigned6bitRange{ 31 };
		static const int8 offsetForSigned7bitRange{ 63 };
	
		static const uint8 seventhBit{ 64 };
		static const uint8 sixthBit{ 32 };
		static const uint8 valueForBarSymbol_ASCII{ 124 };
		static const uint8 valueForBarSymbol_Matrix{ 29 };
	}
}