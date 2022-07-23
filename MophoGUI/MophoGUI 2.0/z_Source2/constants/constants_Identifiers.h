#pragma once

#include <JuceHeader.h>



namespace MophoConstants
{
	namespace ID 
	{
		const Identifier banks_CustomVoiceDataHexStrings{ "banks_CustomVoiceDataHexStrings" };
		const Identifier banks_CustomVoiceNameStrings{ "banks_CustomVoiceNameStrings" };
		const Identifier banks_FactoryVoiceDataHexStrings{ "banks_FactoryVoiceDataHexStrings" };
		const Identifier banks_FactoryVoiceNameStrings{ "banks_FactoryVoiceNameStrings" };

		const Identifier button_AllowAll{ "button_AllowAll" };
		const Identifier button_Banks{ "button_Banks" };
		const Identifier button_Cancel_FileOverwrite{ "button_Cancel_FileOverwrite" };
		const Identifier button_Cancel_ImportExport{ "button_Cancel_ImportExport" };
		const Identifier button_Cancel_NewFolder{ "button_Cancel_NewFolder" };
		const Identifier button_Clear{ "button_Clear" };
		const Identifier button_Close{ "button_Close" };
		const Identifier button_Create{ "button_Create" };
		const Identifier button_Global{ "button_Global" };
		const Identifier button_GroupLock{ "button_GroupLock" };
		const Identifier button_GroupUnlock{ "button_GroupUnlock" };
		const Identifier button_Edit{ "button_Edit" };
		const Identifier button_Export_File{ "button_Export_File" };
		const Identifier button_Export_VoiceFromBank_{ "button_Export_VoiceFromBank_" };
		const Identifier button_Export_VoicesBank_{ "button_Export_VoicesBank_" };
		const Identifier button_Hyperlink{ "button_Hyperlink" };
		const Identifier button_Import_AllVoicesIntoBank_{ "button_Import_AllVoicesIntoBank_" };
		const Identifier button_Import_File{ "button_Import_File" };
		const Identifier button_Import_VoiceIntoBank_{ "button_Import_VoiceIntoBank_" };
		const Identifier button_Load{ "button_Load" };
		const Identifier button_NewFolder{ "button_NewFolder" };
		const Identifier button_Pull_SelectedVoice{ "button_Pull_SelectedVoice" };
		const Identifier button_Pull_VoicesBank_{ "button_Pull_VoicesBank_" };
		const Identifier button_Push_SelectedVoice{ "button_Push_SelectedVoice" };
		const Identifier button_Push_VoicesBank_{ "button_Push_VoicesBank_" };
		const Identifier button_Randomize{ "button_Randomize" };
		const Identifier button_Read{ "button_Read" };
		const Identifier button_Redo{ "button_Redo" };
		const Identifier button_Retry{ "button_Retry" };
		const Identifier button_Save{ "button_Save" };
		const Identifier button_Stop{ "button_Stop" };
		const Identifier button_Undo{ "button_Undo" };
		const Identifier button_VoiceSlotRadioButton{ "button_VoiceSlotRadioButton" };
		const Identifier button_Write_EditBuffer{ "button_Write_EditBuffer" };
		const Identifier button_Write_OverFile{ "button_Write_OverFile" };

		const Identifier choiceNames{ "choiceNames" };
		const Identifier choiceNames_Verbose{ "choiceNames_Verbose" };

		const Identifier component_ImportExportBrowser{ "component_ImportExportBrowser" };
		const Identifier component_Knob{ "component_Knob" };
		const Identifier component_RedToggle{ "component_RedToggle" };
		const Identifier component_RedToggle_AllowLFO_Freq_Pitched{ "component_RedToggle_AllowLFO_Freq_Pitched" };
		const Identifier component_RedToggle_AllowLFO_Freq_Synced{ "component_RedToggle_AllowLFO_Freq_Synced" };
		const Identifier component_RedToggle_AllowLFO_Freq_Unsynced{ "component_RedToggle_AllowLFO_Freq_Unsynced" };
		const Identifier component_RedToggle_AllowOscShape_Off{ "component_RedToggle_AllowOscShape_Off" };
		const Identifier component_RedToggle_AllowOscShape_Pulse{ "component_RedToggle_AllowOscShape_Pulse" };
		const Identifier component_RedToggle_AllowOscShape_Saw{ "component_RedToggle_AllowOscShape_Saw" };
		const Identifier component_RedToggle_AllowOscShape_SawTri{ "component_RedToggle_AllowOscShape_SawTri" };
		const Identifier component_RedToggle_AllowOscShape_Tri{ "component_RedToggle_AllowOscShape_Tri" };
		const Identifier component_RedToggle_AllowRepeatChoices{ "component_RedToggle_AllowRepeatChoices" };
		const Identifier component_SeqTrackStepSelector{ "component_SeqTrackStepSelector" };
		const Identifier component_TabbedComponentForAllBanks{ "component_TabbedComponentForAllBanks" };
		const Identifier component_TabbedComponentForCustomBanks{ "component_TabbedComponentForCustomBanks" };
		const Identifier component_TabbedComponentForFactoryBanks{ "component_TabbedComponentForFactoryBanks" };
		const Identifier component_ToggleAllow_{ "component_ToggleAllow_" };
		const Identifier component_ToggleAllow_Choice_{ "component_ToggleAllow_Choice_" };
		const Identifier component_ToggleAllow_LFO_Freq_Pitched_{ "component_ToggleAllow_LFO_Freq_Pitched_" };
		const Identifier component_ToggleAllow_LFO_Freq_Synced_{ "component_ToggleAllow_LFO_Freq_Synced_" };
		const Identifier component_ToggleAllow_LFO_Freq_Unsynced_{ "component_ToggleAllow_LFO_Freq_Unsynced_" };
		const Identifier component_ToggleAllow_PulseWidth_{ "component_ToggleAllow_PulseWidth_" };
		const Identifier component_ToggleLock_ComboBox_Param_{ "component_ToggleLock_ComboBox_Param_" };
		const Identifier component_ToggleLock_Knob_Param_{ "component_ToggleLock_Knob_Param_" };
		const Identifier component_ToggleLock_SeqStep_Param_{ "component_ToggleLock_SeqStep_Param_" };
		const Identifier component_ToggleLock_Toggle_Param_{ "component_ToggleLock_Toggle_Param_" };
		const Identifier component_ToggleLock_VoiceNameChar_Param_{ "component_ToggleLock_VoiceNameChar_Param_" };

		const Identifier label_DisplayLabel{ "label_VoiceNameEditor" };
		const Identifier label_EditLabel{ "label_EditLabel" };
		const Identifier label_FolderNameEditor{ "label_FolderNameEditor" };
		const Identifier label_VoiceNameEditor{ "label_VoiceNameEditor" };

		const Identifier ep_000_Osc_1_Pitch{ "ep_000_Osc_1_Pitch" };
		const Identifier ep_001_Osc_1_FineTune{ "ep_001_Osc_1_FineTune" };
		const Identifier ep_002_Osc_1_Shape{ "ep_002_Osc_1_Shape" };
		const Identifier ep_003_Osc_1_Glide{ "ep_003_Osc_1_Glide" };
		const Identifier ep_004_Osc_1_KeyTrack{ "ep_004_Osc_1_KeyTrack" };
		const Identifier ep_005_Osc_1_SubLevel{ "ep_005_Osc_1_SubLevel" };
		const Identifier ep_006_Osc_2_Pitch{ "ep_006_Osc_2_Pitch" };
		const Identifier ep_007_Osc_2_FineTune{ "ep_7_Osc_2_Pitch" };
		const Identifier ep_008_Osc_2_Shape{ "ep_008_Osc_2_Shape" };
		const Identifier ep_009_Osc_2_Glide{ "ep_009_Osc_2_Glide" };
		const Identifier ep_010_Osc_2_KeyTrack{ "ep_010_Osc_2_KeyTrack" };
		const Identifier ep_011_Osc_2_SubLevel{ "ep_011_Osc_2_SubLevel" };
		const Identifier ep_012_OscSync{ "ep_012_OscSync" };
		const Identifier ep_013_GlideMode{ "ep_013_GlideMode" };
		const Identifier ep_014_OscSlop{ "ep_014_OscSlop" };
		const Identifier ep_015_BendRange{ "ep_015_BendRange" };
		const Identifier ep_016_NotePriority{ "ep_016_NotePriority" };
		const Identifier ep_017_OscMix{ "ep_017_OscMix" };
		const Identifier ep_018_NoiseLevel{ "ep_018_NoiseLevel" };
		const Identifier ep_019_ExtInLevel{ "ep_019_ExtInLevel" };
		const Identifier ep_020_LPF_Freq{ "ep_020_LPF_Freq" };
		const Identifier ep_021_LPF_Reso{ "ep_021_LPF_Reso" };
		const Identifier ep_022_LPF_KeyAmount{ "ep_022_LPF_KeyAmount" };
		const Identifier ep_023_LPF_FM_Amount{ "ep_023_LPF_FM_Amount" };
		const Identifier ep_024_LPF_Type{ "ep_024_LPF_Type" };
		const Identifier ep_025_LPF_EnvAmount{ "ep_025_LPF_EnvAmount" };
		const Identifier ep_026_LPF_VelAmount{ "ep_026_LPF_VelAmount" };
		const Identifier ep_027_LPF_Delay{ "ep_027_LPF_Delay" };
		const Identifier ep_028_LPF_Attack{ "ep_028_LPF_Attack" };
		const Identifier ep_029_LPF_Decay{ "ep_029_LPF_Decay" };
		const Identifier ep_030_LPF_Sustain{ "ep_030_LPF_Sustain" };
		const Identifier ep_031_LPF_Release{ "ep_031_LPF_Release" };
		const Identifier ep_032_VCA_Level{ "ep_032_VCA_Level" };
		const Identifier ep_033_VCA_EnvAmount{ "ep_033_VCA_EnvAmount" };
		const Identifier ep_034_VCA_VelAmount{ "ep_034_VCA_VelAmount" };
		const Identifier ep_035_VCA_Delay{ "ep_035_VCA_Delay" };
		const Identifier ep_036_VCA_Attack{ "ep_036_VCA_Attack" };
		const Identifier ep_037_VCA_Decay{ "ep_037_VCA_Decay" };
		const Identifier ep_038_VCA_Sustain{ "ep_038_VCA_Sustain" };
		const Identifier ep_039_VCA_Release{ "ep_039_VCA_Release" };
		const Identifier ep_040_VoiceVolume{ "ep_040_VoiceVolume" };
		const Identifier ep_061_Env_3_Destination{ "ep_061_Env_3_Destination" };
		const Identifier ep_062_Env_3_Amount{ "ep_062_Env_3_Amount" };
		const Identifier ep_063_Env_3_VelAmount{ "ep_063_Env_3_VelAmount" };
		const Identifier ep_064_Env_3_Delay{ "ep_064_Env_3_Delay" };
		const Identifier ep_065_Env_3_Attack{ "ep_065_Env_3_Attack" };
		const Identifier ep_066_Env_3_Decay{ "ep_066_Env_3_Decay" };
		const Identifier ep_067_Env_3_Sustain{ "ep_067_Env_3_Sustain" };
		const Identifier ep_068_Env_3_Release{ "ep_068_Env_3_Release" };
		const Identifier ep_069_Env_3_Repeat{ "ep_069_Env_3_Repeat" };
		const Identifier ep_082_ModWheelAmount{ "ep_082_ModWheelAmount" };
		const Identifier ep_083_ModWheelDest{ "ep_083_ModWheelDest" };
		const Identifier ep_084_PressureAmount{ "ep_084_PressureAmount" };
		const Identifier ep_085_PressureDest{ "ep_085_PressureDest" };
		const Identifier ep_086_BreathAmount{ "ep_086_BreathAmount" };
		const Identifier ep_087_BreathDest{ "ep_087_BreathDest" };
		const Identifier ep_088_VelocityAmount{ "ep_088_VelocityAmount" };
		const Identifier ep_089_VelocityDest{ "ep_089_VelocityDest" };
		const Identifier ep_090_PedalAmount{ "ep_090_PedalAmount" };
		const Identifier ep_091_PedalDest{ "ep_091_PedalDest" };
		const Identifier ep_092_PushItPitch{ "ep_092_PushItPitch" };
		const Identifier ep_093_PushItVelocity{ "ep_093_PushItVelocity" };
		const Identifier ep_094_PushItMode{ "ep_094_PushItMode" };
		const Identifier ep_095_ClockTempo{ "ep_095_ClockTempo" };
		const Identifier ep_096_ClockDivision{ "ep_096_ClockDivision" };
		const Identifier ep_097_ArpegMode{ "ep_097_ArpegMode" };
		const Identifier ep_098_ArpegOnOff{ "ep_098_ArpegOnOff" };
		const Identifier ep_099_SeqTrigMode{ "ep_099_SeqTrigMode" };
		const Identifier ep_100_SeqOnOff{ "ep_100_SeqOnOff" };

		const Identifier exposedParamsInfo{ "exposedParamsInfo" };

		const Identifier global_ControllersAreEnabled{ "global_ControllersAreEnabled" };
		const Identifier global_FineTune{ "global_FineTune" };
		const Identifier global_HardwareOutputBalance{ "global_HardwareOutputBalance" };
		const Identifier global_HardwareOutputIsMono{ "global_HardwareOutputIsMono" };
		const Identifier global_HardwareReceiveChannel{ "global_HardwareReceiveChannel" };
		const Identifier global_MIDI_ClockSource{ "global_MIDI_ClockSource" };
		const Identifier global_Options{ "global_Options" };
		const Identifier global_ParamChangeReceiveType{ "global_ParamChangeReceiveType" };
		const Identifier global_ParamChangeSendType{ "global_ParamChangeSendType" };
		const Identifier global_PedalModeIsArpLatch{ "global_PedalModeIsArpLatch" };
		const Identifier global_SysExIsEnabled{ "global_SysExIsEnabled" };
		const Identifier global_TransmitChannel{ "global_TransmitChannel" };
		const Identifier global_Transpose{ "global_Transpose" };
		const Identifier global_VoiceChangesAreEnabled{ "global_VoiceChangesAreEnabled" };

		const Identifier property_AllowedChoicesBackground_x{ "property_AllowedChoicesBackground_x" };
		const Identifier property_AllowedChoicesBackground_y{ "property_AllowedChoicesBackground_y" };
		const Identifier property_AllowedChoicesType{ "property_AllowedChoicesType" };
		const Identifier property_Center_x{ "property_ControlCenter_x" };
		const Identifier property_Center_y{ "property_ControlCenter_y" };
		const Identifier property_ControlType{ "property_ControlType" };
		const Identifier property_DefaultChoice{ "property_DefaultChoice" };
		const Identifier property_Description{ "property_Description" };
		const Identifier property_ExposedName{ "property_ExposedName" };
		const Identifier property_FirstAllowChoiceToggleRow{ "property_FirstAllowChoiceToggleRow" };
		const Identifier property_Height{ "property_Height" };
		const Identifier property_LSByteLocation{ "property_LSByteLocation" };
		const Identifier property_MSBitMask{ "property_MSBitMask" };
		const Identifier property_MSBitPackedByteLocation{ "property_MSbitPackedByteLocation" };
		const Identifier property_NumberOfAllowChoiceToggleColumns{ "property_NumberOfAllowChoiceToggleColumns" };
		const Identifier property_NumberOfAllowChoiceToggleRows{ "property_NumberOfAllowChoiceToggleRows" };
		const Identifier property_NumberOfChoices{ "property_NumberOfChoices" };
		const Identifier property_NRPN{ "property_NRPN" };
		const Identifier property_ParamID{ "property_ParamID" };
		const Identifier property_SeqTrackNum{ "property_SeqTrackNum" };
		const Identifier property_SeqTrackStepNum{ "property_SeqTrackStepNum" };
		const Identifier property_Width{ "property_Width" };
		const Identifier property_WidthOfAllowChoiceToggleColumn{ "property_WidthOfAllowChoiceToggleColumn" };

		const Identifier rndm_AllowedFreqCategories{ "rndm_AllowedFreqCategories" };
		const Identifier rndm_AllowedChoices{ "rndm_AllowedChoices" };
		const Identifier rndm_AllowedChoicesForAllSteps{ "rndm_AllowedChoicesForAllSteps" };
		const Identifier rndm_AllowedChoicesForStep_{ "rndm_AllowedChoicesForStep_" };
		const Identifier rndm_AllowedPitchedFreq{ "rndm_AllowedPitchedFreq" };
		const Identifier rndm_AllowedPulseWidths{ "rndm_AllowedPulseWidths" };
		const Identifier rndm_AllowedShapes{ "rndm_AllowedShapes" };
		const Identifier rndm_AllowedSyncedFreq{ "rndm_AllowedSyncedFreq" };
		const Identifier rndm_AllowedUnsyncedFreq{ "rndm_AllowedUnsyncedFreq" };
		const Identifier rndm_DupeProbForStep_{ "rndm_DupeProbForStep_" };
		const Identifier rndm_DupeProbForAllSteps{ "rndm_DupeProbForAllSteps" };
		const Identifier rndm_NoChoiceIsAllowed{ "rndm_NoChoiceIsAllowed" };
		const Identifier rndm_NoChoiceIsAllowedForAllSteps{ "rndm_NoChoiceIsAllowedForAllSteps" };
		const Identifier rndm_NoChoiceIsAllowedForStep_{ "rndm_NoChoiceIsAllowedForStep_" };
		const Identifier rndm_NoFreqCategoryIsAllowed{ "rndm_NoFreqCategoryIsAllowed" };
		const Identifier rndm_NoOscShapeIsAllowed{ "rndm_NoOscShapeIsAllowed" };
		const Identifier rndm_NoPitchedFreqIsAllowed{ "rndm_NoPitchedFreqIsAllowed" };
		const Identifier rndm_NoPulseWidthIsAllowed{ "rndm_NoPulseWidthIsAllowed" };
		const Identifier rndm_NoSyncedFreqIsAllowed{ "rndm_NoSyncedFreqIsAllowed" };
		const Identifier rndm_NoUnsyncedFreqIsAllowed{ "rndm_NoUnsyncedFreqIsAllowed" };
		const Identifier rndm_OnlyOneChoiceIsAllowed{ "rndm_OnlyOneChoiceIsAllowed" };
		const Identifier rndm_Options{ "rndm_Options" };
		const Identifier rndm_ParamIsLocked{ "rndm_ParamIsLocked" };
		const Identifier rndm_RepeatChoicesAreAllowed{ "rndm_RepeatChoicesAreAllowed" };
		const Identifier rndm_RepeatChoicesAreAllowedForAllSteps{ "rndm_RepeatChoicesAreAllowedForAllSteps" };
		const Identifier rndm_RepeatChoicesAreAllowedForStep_{ "rndm_RepeatChoicesAreAllowedForStep_" };
		const Identifier rndm_RepeatChoicesMustBeAllowedForAllSteps{ "rndm_RepeatChoicesMustBeAllowedForAllSteps" };
		const Identifier rndm_RepeatChoicesMustBeAllowedForStep_{ "rndm_RepeatChoicesMustBeAllowedForStep_" };
		const Identifier rndm_ResetProbForAllSteps{ "rndm_ResetProbForAllSteps" };
		const Identifier rndm_ResetProbForStep_{ "rndm_ResetProbForStep_" };
		const Identifier rndm_RestProbForAllSteps{ "rndm_RestProbForAllSteps" };
		const Identifier rndm_RestProbForStep_{ "rndm_RestProbForStep_" };
		const Identifier rndm_SeqTrack_{ "rndm_SeqTrack_" };
		const Identifier rndm_SeqTrackTargetStep{ "rndm_SeqTrackTargetStep" };
		const Identifier rndm_TransmitMethodIsSysEx{ "rndm_TransmitMethodIsSysEx" };

		const Identifier state_CustomVoiceDataHexStrings{ "state_CustomVoiceDataHexStrings" };
		const Identifier state_CustomVoiceNameStrings{ "state_CustomVoiceNameStrings" };
		const Identifier state_ExposedParams{ "state_ExposedParams" };
		const Identifier state_PluginState{ "state_PluginState" };
		const Identifier state_RandomizationOptions{ "state_RandomizationOptions" };
		const Identifier state_TooltipsOptions{ "state_TooltipsOptions" };
		const Identifier state_UnexposedParams{ "state_UnexposedParams" };
		const Identifier state_VoicesBanks{ "state_VoicesBanks" };
		const Identifier state_VoiceTxOptions{ "state_VoiceTxOptions" };

		const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
		const Identifier tooltips_Options{ "tooltips_Options" };
		const Identifier tooltips_ShowCurrentValue{ "tooltips_ShowCurrentValue" };
		const Identifier tooltips_ShowDescription{ "tooltips_ShowDescription" };

		const Identifier voiceTx_Options{ "voiceTx_Options" };
		const Identifier voiceTx_TransmitParamChanges{ "voiceTx_TransmitParamChanges" };
		const Identifier voiceTx_Time{ "voiceTx_Time" };
	}
}