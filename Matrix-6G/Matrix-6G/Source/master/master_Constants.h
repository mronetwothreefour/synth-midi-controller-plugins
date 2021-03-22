#pragma once

#include <JuceHeader.h>



namespace constants
{
	namespace master
	{
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
		static const uint16 indexOfDisplayBrightnessLSByte_Unused{ indexOfLeversInvertEnableLSByte_Unused + 2 };
		static const uint16 indexOfSquickEnableLSByte_Unused{ indexOfDisplayBrightnessLSByte_Unused + 2 };
		static const uint16 indexOfPatchMapEchoEnableLSByte_Unused{ indexOfSquickEnableLSByte_Unused + 2 };
		static const uint16 indexOfSplitStereoEnableLSByte_Unused{ indexOfPatchMapEchoEnableLSByte_Unused + 2 };
		static const uint16 indexOfUndefinedLSByte1{ indexOfSplitStereoEnableLSByte_Unused + 2 };
		static const uint16 indexOfPressureStandoffLSByte_Unused{ indexOfUndefinedLSByte1 + 2 };
		static const uint16 indexOfSpilloverEnableLSByte{ indexOfPressureStandoffLSByte_Unused + 2 };
		static const uint16 indexOfUndefinedLSByte2{ indexOfSpilloverEnableLSByte + 2 };
		static const uint16 indexOfActiveSenseEnableLSByte_Unused{ indexOfUndefinedLSByte2 + 2 };
		static const uint16 indexOfMIDIechoEnableLSByte{ indexOfActiveSenseEnableLSByte_Unused + 2 };
		static const uint16 indexOfPatchMapEnableLSByte{ indexOfMIDIechoEnableLSByte + 2 };
		static const uint16 indexOfUndefinedLSByte3{ indexOfPatchMapEnableLSByte + 2 };
		static const uint16 indexOfMIDImonoEnableLSByte{ indexOfUndefinedLSByte3 + 2 };
		static const uint16 indexOfFirstPatchMapInputLSByte{ indexOfMIDImonoEnableLSByte + 2 };
		static const uint16 indexOfFirstPatchMapOutputLSByte{ indexOfFirstPatchMapInputLSByte + 200 };
		static const uint16 indexOfChecksumByte{ indexOfFirstPatchMapOutputLSByte + 200 };
	}
}