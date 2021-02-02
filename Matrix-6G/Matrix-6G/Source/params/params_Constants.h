#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace matrixParams
	{
		static const int maxPatchNameLength{ 8 };
		static const int maxTransmitTimeDigits{ 4 };
		static const int maxTransmitTimeValue{ 5000 };
		static const int minTransmitTimeValue{ 50 };

		static const int8 offsetForSigned6bitRange{ 31 };
		static const int8 offsetForSigned7bitRange{ 63 };
	}
}