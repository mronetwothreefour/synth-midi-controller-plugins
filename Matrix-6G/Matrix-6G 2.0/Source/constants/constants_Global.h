#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	namespace GLBL
	{
		const uint8 basicChannelOffset{ 1 };
		const uint8 velocitySensitivity_Unused{ 63 };
		const uint8 firstGlobalDataByte{ 7 };

		const uint16 indexOfVibratoSpeedLSByte{ 0 };
		const uint16 indexOfVibratoSpeedModSourceLSByte{ indexOfVibratoSpeedLSByte + 2 };
		const uint16 indexOfVibratoSpeedModAmountLSByte{ indexOfVibratoSpeedModSourceLSByte + 2 };
		const uint16 indexOfVibratoWaveTypeLSByte{ indexOfVibratoSpeedModAmountLSByte + 2 };
		const uint16 indexOfVibratoAmplitudeLSByte{ indexOfVibratoWaveTypeLSByte + 2 };
		const uint16 indexOfVibratoAmpModSourceLSByte{ indexOfVibratoAmplitudeLSByte + 2 };
		const uint16 indexOfVibratoAmpModAmountLSByte{ indexOfVibratoAmpModSourceLSByte + 2 };
		const uint16 indexOfGlobalTuneLSByte{ indexOfVibratoAmpModAmountLSByte + 2 };
		const uint16 indexOfVelocityScaleTypeLSByte_Unused{ indexOfGlobalTuneLSByte + 2 };
		const uint16 indexOfVelocitySensitivityLSByte_Unused{ indexOfVelocityScaleTypeLSByte_Unused + 2 };
		const uint16 indexOfBasicChannelLSByte{ indexOfVelocitySensitivityLSByte_Unused + 2 };
		const uint16 indexOfOmniModeEnableLSByte{ indexOfBasicChannelLSByte + 2 };
		const uint16 indexOfControllersEnableLSByte{ indexOfOmniModeEnableLSByte + 2 };
		const uint16 indexOfVoiceChangesEnableLSByte{ indexOfControllersEnableLSByte + 2 };
		const uint16 indexOfSysExEnableLSByte{ indexOfVoiceChangesEnableLSByte + 2 };
		const uint16 indexOfLocalControlEnableLSByte{ indexOfSysExEnableLSByte + 2 };
		const uint16 indexOfPedal_1_ControllerNumber{ indexOfLocalControlEnableLSByte + 2 };
		const uint16 indexOfPedal_2_ControllerNumber{ indexOfPedal_1_ControllerNumber + 2 };
		const uint16 indexOfLever_2_ControllerNumber{ indexOfPedal_2_ControllerNumber + 2 };
		const uint16 indexOfLever_3_ControllerNumber{ indexOfLever_2_ControllerNumber + 2 };
		const uint16 indexOfPedal_2_InvertEnableLSByte_Unused{ indexOfLever_3_ControllerNumber + 2 };
		const uint16 indexOfLeversInvertEnableLSByte_Unused{ indexOfPedal_2_InvertEnableLSByte_Unused + 2 };
		const uint16 indexOfDisplayBrightnessLSByte{ indexOfLeversInvertEnableLSByte_Unused + 2 };
		const uint16 indexOf_SQUICK_EnableLSByte{ indexOfDisplayBrightnessLSByte + 2 };
		const uint16 indexOfVoiceMapEchoEnableLSByte{ indexOf_SQUICK_EnableLSByte + 2 };
		const uint16 indexOfSplitStereoEnableLSByte{ indexOfVoicesMapEchoEnableLSByte + 2 };
		const uint16 indexOfBasicChannelDisplayedValueLSByte{ indexOfSplitStereoEnableLSByte + 2 };
		const uint16 indexOfPressureStandoffLSByte_Unused{ indexOfBasicChannelDisplayedValueLSByte + 2 };
		const uint16 indexOfSpilloverEnableLSByte{ indexOfPressureStandoffLSByte_Unused + 2 };
		const uint16 indexOfUndefinedLSByte_1{ indexOfSpilloverEnableLSByte + 2 };
		const uint16 indexOfActiveSenseEnableLSByte{ indexOfUndefinedLSByte_1 + 2 };
		const uint16 indexOf_MIDI_EchoEnableLSByte{ indexOfActiveSenseEnableLSByte + 2 };
		const uint16 indexOfVoiceMapEnableLSByte{ indexOf_MIDI_EchoEnableLSByte + 2 };
		const uint16 indexOfUndefinedLSByte_2{ indexOfVoicesMapEnableLSByte + 2 };
		const uint16 indexOf_MIDI_MonoEnableLSByte{ indexOfUndefinedLSByte_2 + 2 };
		const uint16 indexOfFirstVoicesMapInVoiceLSByte{ indexOf_MIDI_MonoEnableLSByte + 2 };
		const uint16 indexOfFirstVoicesMapOutVoiceLSByte{ indexOfFirstVoicesMapInVoiceLSByte + 200 };
	}
}