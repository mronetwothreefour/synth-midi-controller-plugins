#pragma once



namespace constants
{
	namespace MIDI
	{
		static const uint8 opcode_PatchData{ 1 };
		static const uint8 opcode_DataRequest{ 4 };
		static const uint8 transmitCode_Patch{ 1 };
		static const uint8 transmitCode_Split{ 2 };
		static const uint8 transmitCode_Master{ 3 };

		static const int sizeOfDataDumpRequestVector{ 5 };
		static const int sizeOfMasterDataVector{ 477 };
		static const int sizeOfParamChangeVector{ 5 };
		static const int sizeOfPatchDataVector{ 273 };
		static const int sizeOfQuickEditSelectVector{ 3 };
		static const int sizeOfSplitDataVector{ 41 };
	}
}