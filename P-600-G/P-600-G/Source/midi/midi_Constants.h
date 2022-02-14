#pragma once



namespace constants
{
	namespace MIDI
	{
		static const uint8 channel{ 1 };
		static const uint8 manufacturerID{ 1 };
		static const uint8 numberOfHeaderBytesInVoiceDataMessage{ 3 };
		static const uint8 opcode_RequestVoiceData{ 0 };
		static const uint8 sizeOfVoiceDataMessageVector{ 35 };
		static const uint8 sizeOfVoiceDataRequestVector{ 3 };
		static const uint8 sysExByteHolding_ManufacturerID{ 1 };
		static const uint8 sysExByteHolding_Opcode{ sysExByteHolding_ManufacturerID + 1 };
		static const uint8 sysExByteHolding_VoiceNum{ sysExByteHolding_Opcode + 1 };
		static const uint8 sysExByteHolding_FirstVoiceDataNybble{ sysExByteHolding_VoiceNum + 1 };
	}
}