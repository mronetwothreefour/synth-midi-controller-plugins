#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace voices
	{
		static const int numberOfSlotsInBank{ 128 };
		static const int firstVoiceNameCharByte{ 211 };
		static const int lastVoiceNameCharByte{ 228 };
		static const int ignoredVoiceNamePackByte1{ 216 };
		static const int ignoredVoiceNamePackByte2{ 224 };
		static const int numberOfCharsInVoiceName{ 16 };

		static const String basicVoiceDataHexString{ "00183101000100180033010001000000400204004000001400000000017F00000000000000007F00000000004040785000010000005001000000005001000000005001000000007F000000000000000000007F00007F0000007F00007F007F00007F007F007F007F00003C6400780200000000000101090000050B2B170000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000426173696300205061746368200020202020" };
		static const String basicVoiceNameString{ "Basic Program   " };
	}
}