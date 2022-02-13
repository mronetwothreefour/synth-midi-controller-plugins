#pragma once



namespace constants
{
	namespace MIDI
	{
        static const int controllerFlag{ 0xB0 };
        static const int firstVoiceDataByte{ 6 };
        static const int firstUnusedPVoiceDataByte{ 236 };
        static const int globalBalanceByte{ 24 };
        static const int globalTransposeLSByte{ 4 };
        static const int globalTransposeMSByte{ 5 };
        static const int globalFineTuneLSByte{ 6 };
        static const int globalFineTuneMSByte{ 7 };
        static const int globalHardwareReceiveChannelLSByte{ 8 };
        static const int globalHardwareReceiveChannelMSByte{ 9 };
        static const int globalMidiClockTypeByte{ 10 };
        static const int globalMidiControllersOnByte{ 16 };
        static const int globalParameterSendTypetByte{ 12 };
        static const int globalParameterReceiveTypeByte{ 14 };
        static const int globalPedalModeIsArpByte{ 26 };
        static const int globalVoiceChangeOnByte{ 28 };
        static const int globalSysExOnByte{ 18 };
        static const int globalStereoOutByte{ 20 };
        static const int nrpnTypeForGlobalFineTune{ 385 };
		static const int nrpnTypeForGlobalTranspose{ 384 };
		static const int nrpnTypeMSB{ 99 };
		static const int nrpnTypeLSB{ 98 };
		static const int nrpnValueMSB{ 6 };
		static const int nrpnValueLSB{ 38 };
        static const int voiceDataMessageBankByte{ 4 };
        static const int voiceDataMessageSlotByte{ 5 };
        static const int sysExMessageTypeByte{ 3 };
    }
}