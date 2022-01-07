#pragma once



namespace constants
{
	namespace MIDI
	{
		static const uint8 channel{ 1 };
		static const uint8 manufacturerID{ 1 };
		static const uint8 numberOfHeaderBytesInPgmDataDump{ 3 };
		static const uint8 opcode_PgmDataDump{ 2 };
		static const uint8 opcode_RequestPgmDataDump{ 0 };
		static const uint8 sizeOfPgmDataDumpRequestVector{ 3 };
		static const uint8 sizeOfPgmDataDumpVector{ 35 };
		static const uint8 sysExByteHolding_ManufacturerID{ 1 };
		static const uint8 sysExByteHolding_Opcode{ sysExByteHolding_ManufacturerID + 1 };
		static const uint8 sysExByteHolding_PgmNum{ sysExByteHolding_Opcode + 1 };
		static const uint8 sysExByteHolding_FirstPgmDataNybble{ sysExByteHolding_PgmNum + 1 };
	}
}