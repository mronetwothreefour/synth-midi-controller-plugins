#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace master
	{
		static const uint8 basicChannelOffset{ 1 };
		static const uint8 indexOfFirstMasterDataByte{ 7 };
		static const uint8 velocitySensitivity_Unused{ 63 };

		static const uint16 indexOfVibratoSpeedLSByte{ 0 };
		static const uint16 indexOfVibratoSpeedModSourceLSByte{ indexOfVibratoSpeedLSByte + 2 };
		static const uint16 indexOfVibratoSpeedModAmountLSByte{ indexOfVibratoSpeedModSourceLSByte + 2 };
		static const uint16 indexOfVibratoWaveTypeLSByte{ indexOfVibratoSpeedModAmountLSByte + 2 };
		static const uint16 indexOfVibratoAmplitudeLSByte{ indexOfVibratoWaveTypeLSByte + 2 };
		static const uint16 indexOfVibratoAmplitudeModSourceLSByte{ indexOfVibratoAmplitudeLSByte + 2 };
		static const uint16 indexOfVibratoAmplitudeModAmountLSByte{ indexOfVibratoAmplitudeModSourceLSByte + 2 };
		static const uint16 indexOfMasterTuneLSByte{ indexOfVibratoAmplitudeModAmountLSByte + 2 };
		static const uint16 indexOfVelocityScaleTypeLSByte_Unused{ indexOfMasterTuneLSByte + 2 };
		static const uint16 indexOfVelocitySensitivityLSByte_Unused{ indexOfVelocityScaleTypeLSByte_Unused + 2 };
		static const uint16 indexOfBasicChannelLSByte{ indexOfVelocitySensitivityLSByte_Unused + 2 };
		static const uint16 indexOfOmniModeEnableLSByte{ indexOfBasicChannelLSByte + 2 };
		static const uint16 indexOfControllersEnableLSByte{ indexOfOmniModeEnableLSByte + 2 };
		static const uint16 indexOfPatchChangesEnableLSByte{ indexOfControllersEnableLSByte + 2 };
		static const uint16 indexOfSysExEnableLSByte{ indexOfPatchChangesEnableLSByte + 2 };
		static const uint16 indexOfLocalControlEnableLSByte{ indexOfSysExEnableLSByte + 2 };
		static const uint16 indexOfPedal1ControllerNumber{ indexOfLocalControlEnableLSByte + 2 };
		static const uint16 indexOfPedal2ControllerNumber{ indexOfPedal1ControllerNumber + 2 };
		static const uint16 indexOfLever2ControllerNumber{ indexOfPedal2ControllerNumber + 2 };
		static const uint16 indexOfLever3ControllerNumber{ indexOfLever2ControllerNumber + 2 };
		static const uint16 indexOfPedal2InvertEnableLSByte_Unused{ indexOfLever3ControllerNumber + 2 };
		static const uint16 indexOfLeversInvertEnableLSByte_Unused{ indexOfPedal2InvertEnableLSByte_Unused + 2 };
		static const uint16 indexOfDisplayBrightnessLSByte{ indexOfLeversInvertEnableLSByte_Unused + 2 };
		static const uint16 indexOfSQUICKenableLSByte{ indexOfDisplayBrightnessLSByte + 2 };
		static const uint16 indexOfPatchMapEchoEnableLSByte{ indexOfSQUICKenableLSByte + 2 };
		static const uint16 indexOfSplitStereoEnableLSByte{ indexOfPatchMapEchoEnableLSByte + 2 };
		static const uint16 indexOfBasicChannelDisplayedValueLSByte{ indexOfSplitStereoEnableLSByte + 2 };
		static const uint16 indexOfPressureStandoffLSByte_Unused{ indexOfBasicChannelDisplayedValueLSByte + 2 };
		static const uint16 indexOfSpilloverEnableLSByte{ indexOfPressureStandoffLSByte_Unused + 2 };
		static const uint16 indexOfUndefinedLSByte2{ indexOfSpilloverEnableLSByte + 2 };
		static const uint16 indexOfActiveSenseEnableLSByte{ indexOfUndefinedLSByte2 + 2 };
		static const uint16 indexOfMIDIechoEnableLSByte{ indexOfActiveSenseEnableLSByte + 2 };
		static const uint16 indexOfPatchMapEnableLSByte{ indexOfMIDIechoEnableLSByte + 2 };
		static const uint16 indexOfUndefinedLSByte3{ indexOfPatchMapEnableLSByte + 2 };
		static const uint16 indexOfMIDImonoEnableLSByte{ indexOfUndefinedLSByte3 + 2 };
		static const uint16 indexOfFirstPatchMapInputLSByte{ indexOfMIDImonoEnableLSByte + 2 };
		static const uint16 indexOfFirstPatchMapOutputLSByte{ indexOfFirstPatchMapInputLSByte + 200 };
		static const uint16 indexOfChecksumByte{ indexOfFirstPatchMapOutputLSByte + 206 };
	}
}