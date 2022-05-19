#pragma once

#include <JuceHeader.h>



namespace mophoConstants
{
	namespace ID 
	{
		static const Identifier choiceNames{ "choiceNames" };
		static const Identifier choiceNames_Verbose{ "choiceNames_Verbose" };

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
		static const Identifier ep_065_Env_3_Attack{ "ep_064_Env_3_Attack" };
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

		static const Identifier property_DefaultChoice{ "property_DefaultChoice" };
		static const Identifier property_ExposedName{ "property_ExposedName" };
		static const Identifier property_NumberOfChoices{ "property_NumberOfChoices" };
		static const Identifier property_NRPN{ "property_NRPN" };

		static const Identifier exposedParamsInfo{ "exposedParamsInfo" };
	}
}