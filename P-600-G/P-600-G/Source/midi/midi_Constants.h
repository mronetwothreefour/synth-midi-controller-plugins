#pragma once



namespace constants
{
	namespace MIDI
	{
		static const uint8 channel{ 1 };
		static const uint8 manufacturerID{ 1 };
		static const uint8 opcode_PgmDataDump{ 2 };
		static const uint8 opcode_RequestPgmDataDump{ 0 };
		static const uint8 sizeOfPgmDataDumpRequestVector{ 3 };
	}
}