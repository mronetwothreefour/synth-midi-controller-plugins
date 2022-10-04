#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	namespace SPLT
	{
		const int lengthOfSplitDataHexString{ 38 };
		const int numberOfCharsInSplitName{ 8 };
		const int numberOfChoicesForZoneLimit{ 128 };
		const int numberOfSlotsInSplitsBank{ 50 };
		const int rawSplitDataVectorChecksumByteIndex{ 40 };

		const String initialSplitDataHexString{ "90E0904102020000320010420010000000103E" };
		const String initialSplitNameString{ "INIT  " };
	}
}