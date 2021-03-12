#pragma once



namespace constants
{
	namespace MIDI
	{
		static const uint8 deviceID_OberheimXpander{ 2 };
		static const uint8 opcode_ActivateQuickEdit{ 5 };
		static const uint8 opcode_DataRequest{ 4 };
		static const uint8 opcode_PatchData{ 1 };
		static const uint8 opcode_ParameterChange{ 6 };
		static const uint8 opcode_SplitData{ 2 };
		static const uint8 opcode_SwitchMode{ 13 };
		static const uint8 transmitCode_Patch{ 1 };
		static const uint8 transmitCode_Split{ 2 };
		static const uint8 transmitCode_Master{ 3 };

		static const int numberOfHeaderBytesInPatchAndSplitDataMessages{ 4 };
		static const int patchAndSplitDumpSlotNumberByte{ 4 };
		static const int patchAndSplitDumpFirstDataByte{ 5 };
		static const int sizeOfDataDumpRequestVector{ 5 };
		static const int sizeOfMasterDataVector{ 477 };
		static const int sizeOfParamChangeVector{ 5 };
		static const int sizeOfPatchDataVector{ 273 };
		static const int sizeOfQuickEditSelectVector{ 3 };
		static const int sizeOfSwitchToSplitModeVector{ 4 };
		static const int sizeOfSplitDataVector{ 41 };
		static const int sysexMessageOpcodeByte{ 3 };
	}
}