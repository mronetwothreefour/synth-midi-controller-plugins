#pragma once

#include <JuceHeader.h>



namespace MophoConstants
{
	namespace Voices
	{
		const int firstVoiceNameCharByte{ 211 };
		const int ignoredVoiceNamePackByte1{ 216 };
		const int ignoredVoiceNamePackByte2{ 224 };
		const int lastVoiceNameCharByte{ 228 };
		const int lengthOfVoiceDataHexString{ 458 };
		const int numberOfCharsInVoiceName{ 16 };
		const int numberOfSlotsInVoicesBank{ 128 };

		const String basicVoiceDataHexString{ "00183101000100180033010001000000400204004000001400000000017F00000000000000007F00000000004040785000010000005001000000005001000000005001000000007F000000000000000000007F00007F0000007F00007F007F00007F007F007F007F00003C6400780200000000000101090000050B2B170000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000426173696300205061746368200020202020" };
		const String basicVoiceNameString{ "Basic Program   " };
	}
}