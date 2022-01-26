#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace pgmData
	{
		static const int lengthOfPgmDataHexString{ 64 };
		static const int indexOfFirstNameCharInPgmDataHexString{ 64 };
		static const int indexOfLastBitOfPgmDataDumpHeader{ 1 };
		static const int maxLengthOfPgmName{ 20 };
		static const int numberOfSlotsInPgmDataBank{ 100 };
	}
}