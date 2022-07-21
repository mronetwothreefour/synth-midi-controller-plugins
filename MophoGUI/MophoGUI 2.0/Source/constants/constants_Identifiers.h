#pragma once

#include <JuceHeader.h>

namespace MophoConstants
{
	namespace ID
	{
		static const Identifier btn_AllowAll{ "button_AllowAll" };
		static const Identifier btn_Banks{ "button_Banks" };
		static const Identifier btn_Cancel_FileOverwrite{ "button_Cancel_FileOverwrite" };
		static const Identifier btn_Cancel_ImportExport{ "button_Cancel_ImportExport" };
		static const Identifier btn_Cancel_NewFolder{ "button_Cancel_NewFolder" };
		static const Identifier btn_Clear{ "button_Clear" };
		static const Identifier btn_Close{ "button_Close" };
		static const Identifier btn_Create{ "button_Create" };
		static const Identifier btn_Edit{ "button_Edit" };
		static const Identifier btn_Export_File{ "button_Export_File" };
		static const Identifier btn_Export_VoiceFromBank_{ "button_Export_VoiceFromBank_" };
		static const Identifier btn_Export_VoicesBank_{ "button_Export_VoicesBank_" };
		static const Identifier btn_Global{ "button_Global" };
		static const Identifier btn_GroupLock{ "button_GroupLock" };
		static const Identifier btn_GroupUnlock{ "button_GroupUnlock" };
		static const Identifier btn_Hyperlink{ "button_Hyperlink" };
		static const Identifier btn_Import_AllVoicesIntoBank_{ "button_Import_AllVoicesIntoBank_" };
		static const Identifier btn_Import_File{ "button_Import_File" };
		static const Identifier btn_Import_VoiceIntoBank_{ "button_Import_VoiceIntoBank_" };
		static const Identifier btn_Load{ "button_Load" };
		static const Identifier btn_NewFolder{ "button_NewFolder" };
		static const Identifier btn_Pull_SelectedVoice{ "button_Pull_SelectedVoice" };
		static const Identifier btn_Pull_VoicesBank_{ "button_Pull_VoicesBank_" };
		static const Identifier btn_Push_SelectedVoice{ "button_Push_SelectedVoice" };
		static const Identifier btn_Push_VoicesBank_{ "button_Push_VoicesBank_" };
		static const Identifier btn_Randomize{ "button_Randomize" };
		static const Identifier btn_Read{ "button_Read" };
		static const Identifier btn_Redo{ "button_Redo" };
		static const Identifier btn_Retry{ "button_Retry" };
		static const Identifier btn_Save{ "button_Save" };
		static const Identifier btn_Stop{ "button_Stop" };
		static const Identifier btn_Undo{ "button_Undo" };
		static const Identifier btn_VoiceSlotRadioButton{ "button_VoiceSlotRadioButton" };
		static const Identifier btn_Write_EditBuffer{ "button_Write_EditBuffer" };
		static const Identifier btn_Write_OverFile{ "button_Write_OverFile" };

		static const Identifier comp_ImportExportBrowser{ "comp_ImportExportBrowser" };
		static const Identifier comp_Knob{ "comp_Knob" };
		static const Identifier comp_RedToggle{ "comp_RedToggle" };
		static const Identifier comp_TabbedComponentForAllBanks{ "comp_TabbedComponentForAllBanks" };
		static const Identifier comp_ToggleAllow_{ "comp_ToggleAllow_" };

		static const Identifier ep_000_Osc_1_Pitch{ "ep_000_Osc_1_Pitch" };
		static const Identifier ep_001_Osc_1_FineTune{ "ep_001_Osc_1_FineTune" };
		static const Identifier ep_002_Osc_1_Shape{ "ep_002_Osc_1_Shape" };
		static const Identifier ep_003_Osc_1_Glide{ "ep_003_Osc_1_Glide" };
		static const Identifier ep_004_Osc_1_KeyTrack{ "ep_004_Osc_1_KeyTrack" };
		static const Identifier ep_005_Osc_1_SubLevel{ "ep_005_Osc_1_SubLevel" };
		static const Identifier ep_006_Osc_2_Pitch{ "ep_006_Osc_2_Pitch" };
		static const Identifier ep_007_Osc_2_FineTune{ "ep_7_Osc_2_Pitch" };
		static const Identifier ep_008_Osc_2_Shape{ "ep_008_Osc_2_Shape" };
		static const Identifier ep_009_Osc_2_Glide{ "ep_009_Osc_2_Glide" };
		static const Identifier ep_010_Osc_2_KeyTrack{ "ep_010_Osc_2_KeyTrack" };
		static const Identifier ep_011_Osc_2_SubLevel{ "ep_011_Osc_2_SubLevel" };
		static const Identifier ep_012_OscSync{ "ep_012_OscSync" };
		static const Identifier ep_013_GlideMode{ "ep_013_GlideMode" };
		static const Identifier ep_014_OscSlop{ "ep_014_OscSlop" };
		static const Identifier ep_015_BendRange{ "ep_015_BendRange" };
		static const Identifier ep_016_NotePriority{ "ep_016_NotePriority" };
		static const Identifier ep_017_OscMix{ "ep_017_OscMix" };
		static const Identifier ep_018_NoiseLevel{ "ep_018_NoiseLevel" };
		static const Identifier ep_019_ExtInLevel{ "ep_019_ExtInLevel" };
		static const Identifier ep_020_LPF_Freq{ "ep_020_LPF_Freq" };
		static const Identifier ep_021_LPF_Reso{ "ep_021_LPF_Reso" };
		static const Identifier ep_022_LPF_KeyAmount{ "ep_022_LPF_KeyAmount" };
		static const Identifier ep_023_LPF_FM_Amount{ "ep_023_LPF_FM_Amount" };
		static const Identifier ep_024_LPF_Type{ "ep_024_LPF_Type" };
		static const Identifier ep_025_LPF_EnvAmount{ "ep_025_LPF_EnvAmount" };
		static const Identifier ep_026_LPF_VelAmount{ "ep_026_LPF_VelAmount" };
		static const Identifier ep_027_LPF_Delay{ "ep_027_LPF_Delay" };
		static const Identifier ep_028_LPF_Attack{ "ep_028_LPF_Attack" };
		static const Identifier ep_029_LPF_Decay{ "ep_029_LPF_Decay" };
		static const Identifier ep_030_LPF_Sustain{ "ep_030_LPF_Sustain" };
		static const Identifier ep_031_LPF_Release{ "ep_031_LPF_Release" };
		static const Identifier ep_032_VCA_Level{ "ep_032_VCA_Level" };
		static const Identifier ep_033_VCA_EnvAmount{ "ep_033_VCA_EnvAmount" };
		static const Identifier ep_034_VCA_VelAmount{ "ep_034_VCA_VelAmount" };
		static const Identifier ep_035_VCA_Delay{ "ep_035_VCA_Delay" };
		static const Identifier ep_036_VCA_Attack{ "ep_036_VCA_Attack" };
		static const Identifier ep_037_VCA_Decay{ "ep_037_VCA_Decay" };
		static const Identifier ep_038_VCA_Sustain{ "ep_038_VCA_Sustain" };
		static const Identifier ep_039_VCA_Release{ "ep_039_VCA_Release" };
		static const Identifier ep_040_VoiceVolume{ "ep_040_VoiceVolume" };
		static const Identifier ep_061_Env_3_Destination{ "ep_061_Env_3_Destination" };
		static const Identifier ep_062_Env_3_Amount{ "ep_062_Env_3_Amount" };
		static const Identifier ep_063_Env_3_VelAmount{ "ep_063_Env_3_VelAmount" };
		static const Identifier ep_064_Env_3_Delay{ "ep_064_Env_3_Delay" };
		static const Identifier ep_065_Env_3_Attack{ "ep_065_Env_3_Attack" };
		static const Identifier ep_066_Env_3_Decay{ "ep_066_Env_3_Decay" };
		static const Identifier ep_067_Env_3_Sustain{ "ep_067_Env_3_Sustain" };
		static const Identifier ep_068_Env_3_Release{ "ep_068_Env_3_Release" };
		static const Identifier ep_069_Env_3_Repeat{ "ep_069_Env_3_Repeat" };
		static const Identifier ep_082_ModWheelAmount{ "ep_082_ModWheelAmount" };
		static const Identifier ep_083_ModWheelDest{ "ep_083_ModWheelDest" };
		static const Identifier ep_084_PressureAmount{ "ep_084_PressureAmount" };
		static const Identifier ep_085_PressureDest{ "ep_085_PressureDest" };
		static const Identifier ep_086_BreathAmount{ "ep_086_BreathAmount" };
		static const Identifier ep_087_BreathDest{ "ep_087_BreathDest" };
		static const Identifier ep_088_VelocityAmount{ "ep_088_VelocityAmount" };
		static const Identifier ep_089_VelocityDest{ "ep_089_VelocityDest" };
		static const Identifier ep_090_PedalAmount{ "ep_090_PedalAmount" };
		static const Identifier ep_091_PedalDest{ "ep_091_PedalDest" };
		static const Identifier ep_092_PushItPitch{ "ep_092_PushItPitch" };
		static const Identifier ep_093_PushItVelocity{ "ep_093_PushItVelocity" };
		static const Identifier ep_094_PushItMode{ "ep_094_PushItMode" };
		static const Identifier ep_095_ClockTempo{ "ep_095_ClockTempo" };
		static const Identifier ep_096_ClockDivision{ "ep_096_ClockDivision" };
		static const Identifier ep_097_ArpegMode{ "ep_097_ArpegMode" };
		static const Identifier ep_098_ArpegOnOff{ "ep_098_ArpegOnOff" };
		static const Identifier ep_099_SeqTrigMode{ "ep_099_SeqTrigMode" };
		static const Identifier ep_100_SeqOnOff{ "ep_100_SeqOnOff" };

		static const Identifier label_DisplayLabel{ "label_VoiceNameEditor" };
		static const Identifier label_EditLabel{ "label_EditLabel" };
		static const Identifier label_FolderNameEditor{ "label_FolderNameEditor" };
		static const Identifier label_VoiceNameEditor{ "label_VoiceNameEditor" };

		static const Identifier property_AllowedChoicesBackground_x{ "property_AllowedChoicesBackground_x" };
		static const Identifier property_AllowedChoicesBackground_y{ "property_AllowedChoicesBackground_y" };
		static const Identifier property_AllowedChoicesType{ "property_AllowedChoicesType" };
		static const Identifier property_Center_x{ "property_ControlCenter_x" };
		static const Identifier property_Center_y{ "property_ControlCenter_y" };
		static const Identifier property_ControlType{ "property_ControlType" };
		static const Identifier property_DefaultChoice{ "property_DefaultChoice" };
		static const Identifier property_Description{ "property_Description" };
		static const Identifier property_ExposedName{ "property_ExposedName" };
		static const Identifier property_FirstAllowChoiceToggleRow{ "property_FirstAllowChoiceToggleRow" };
		static const Identifier property_Height{ "property_Height" };
		static const Identifier property_LSByteLocation{ "property_LSByteLocation" };
		static const Identifier property_MSBitMask{ "property_MSBitMask" };
		static const Identifier property_MSBitPackedByteLocation{ "property_MSbitPackedByteLocation" };
		static const Identifier property_NumberOfAllowChoiceToggleColumns{ "property_NumberOfAllowChoiceToggleColumns" };
		static const Identifier property_NumberOfAllowChoiceToggleRows{ "property_NumberOfAllowChoiceToggleRows" };
		static const Identifier property_NumberOfChoices{ "property_NumberOfChoices" };
		static const Identifier property_NRPN{ "property_NRPN" };
		static const Identifier property_ParamID{ "property_ParamID" };
		static const Identifier property_SeqTrackNum{ "property_SeqTrackNum" };
		static const Identifier property_SeqTrackStepNum{ "property_SeqTrackStepNum" };
		static const Identifier property_Width{ "property_Width" };
		static const Identifier property_WidthOfAllowChoiceToggleColumn{ "property_WidthOfAllowChoiceToggleColumn" };

		static const Identifier state_TooltipsOptions{ "state_TooltipsOptions" };
		static const Identifier state_UnexposedParams{ "state_UnexposedParams" };

		static const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
		static const Identifier tooltips_ShouldShowCurrentChoice{ "tooltips_ShouldShowCurrentChoice" };
		static const Identifier tooltips_ShouldShowDescription{ "tooltips_ShouldShowDescription" };

		static const Identifier tree_ChoiceNames{ "tree_ChoiceNames" };
		static const Identifier tree_ChoiceNames_Verbose{ "tree_ChoiceNames_Verbose" };
		static const Identifier tree_ExposedParamsInfo{ "tree_ExposedParamsInfo" };
		static const Identifier tree_TooltipsOptions{ "tree_TooltipsOptions" };
	}
}