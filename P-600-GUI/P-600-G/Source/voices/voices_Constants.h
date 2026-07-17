#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace voices
	{
		static const int lengthOfVoiceDataHexString{ 64 };
		static const int indexOfFirstNameCharInVoiceDataHexString{ 64 };
		static const int indexOfLastBitOfVoiceDataMessageHeader{ 1 };
		static const int maxNumberOfDigitsInLCDeditor{ 4 };
		static const int maxLengthOfVoiceName{ 20 };
		static const int maxTransmitTimeValue{ 5000 };
		static const int minTransmitTimeValue{ 50 };
		static const int numberOfSlotsInVoicesBank{ 100 };
	}
}