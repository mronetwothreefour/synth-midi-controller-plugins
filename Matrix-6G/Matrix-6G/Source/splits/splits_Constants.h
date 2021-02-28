#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace splits
	{
		static const int numberOfSlotsInBank{ 50 };
		static const int rawSplitDataVectorChecksumByteIndex{ 40 };

		static const uint8 indexOfLastDataByteBeforeSpltsParams{ 16 };

		static const String initialSplitDataHexString{ "" };
		static const String initialSplitNameString{ "INIT" };
	}
}