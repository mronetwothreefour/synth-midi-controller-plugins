#pragma once

#include <JuceHeader.h>

namespace P_600_G_Constants
{
	namespace ID
	{
		static const Identifier bank_FactoryVoiceDataHexStrings{ "bank_FactoryVoiceDataHexStrings" };
		static const Identifier bank_VoiceDataHexStrings{ "bank_VoiceDataHexStrings" };
		static const Identifier bank_VoiceNameStrings{ "bank_VoiceNameStrings" };

		static const Identifier btn_Esc{ "btn_Esc" };
		static const Identifier btn_Esc_FileOverwrite{ "btn_Esc_FileOverwrite" };
		static const Identifier btn_Esc_NewFolder{ "btn_Esc_NewFolder" };
		static const Identifier btn_Esc_ImportExport{ "btn_Esc_ImportExport" };
		static const Identifier btn_Exit{ "btn_Exit" };
		static const Identifier btn_Expt_Voice{ "btn_Expt_Voice" };
		static const Identifier btn_Expt_VoicesBank{ "btn_Expt_VoicesBank" };
		static const Identifier btn_Impt_Voice{ "btn_Impt_Voice" };
		static const Identifier btn_Impt_VoicesBank{ "btn_Impt_VoicesBank" };
		static const Identifier btn_Load{ "btn_Load" };
		static const Identifier btn_Name{ "btn_Name" };
		static const Identifier btn_NewFolder{ "btn_NewFolder" };
		static const Identifier btn_OK{ "btn_OK" };
		static const Identifier btn_OK_FileOverwrite{ "btn_OK_FileOverwrite" };
		static const Identifier btn_OK_ExportFile{ "btn_OK_ExportFile" };
		static const Identifier btn_OK_ImportFile{ "btn_OK_ExportFile" };
		static const Identifier btn_PgmBank{ "btn_PgmBank" };
		static const Identifier btn_Pull_Voice{ "btn_Pull_Voice" };
		static const Identifier btn_Pull_VoicesBank{ "btn_Pull_VoicesBank" };
		static const Identifier btn_Push_Voice{ "btn_Push_Voice" };
		static const Identifier btn_Push_VoicesBank{ "btn_Push_VoicesBank" };
		static const Identifier btn_RestoreFactoryVoices{ "btn_RestoreFactoryVoices" };
		static const Identifier btn_Save{ "btn_Save" };
		static const Identifier btn_VoiceSlotRadioButton{ "btn_VoiceSlotRadioButton" };

		static const Identifier comp_ImptExptBrowser{ "comp_ImptExptBrowser" };
		static const Identifier comp_TextEditorForKnob{ "comp_TextEditorForKnob" };
		static const Identifier comp_TextEditorForTransmitTime{ "comp_TextEditorForTransmitTime" };
		static const Identifier comp_TextEditorForVoiceName{ "comp_TextEditorForVoiceName" };
		static const Identifier comp_TextEditorForVoiceNumberSlider{ "comp_TextEditorForVoiceNumberSlider" };
		static const Identifier comp_VoiceNumberSlider{ "comp_VoiceNumberSlider" };

		static const Identifier ep_00_Osc_A_Freq{ "ep_00_Osc_A_Freq" };
		static const Identifier ep_01_Osc_A_Sync{ "ep_01_Osc_A_Sync" };
		static const Identifier ep_02_Osc_A_Saw{ "ep_02_Osc_A_Saw" };
		static const Identifier ep_03_Osc_A_Tri{ "ep_03_Osc_A_Tri" };
		static const Identifier ep_04_Osc_A_Pulse{ "ep_04_Osc_A_Pulse" };
		static const Identifier ep_05_Osc_A_PulseWidth{ "ep_05_Osc_A_PulseWidth" };
		static const Identifier ep_06_Osc_B_Freq{ "ep_06_Osc_B_Freq" };
		static const Identifier ep_07_Osc_B_Fine{ "ep_07_Osc_B_Fine" };
		static const Identifier ep_08_Osc_B_Saw{ "ep_08_Osc_B_Saw" };
		static const Identifier ep_09_Osc_B_Tri{ "ep_09_Osc_B_Tri" };
		static const Identifier ep_10_Osc_B_Pulse{ "ep_10_Osc_B_Pulse" };
		static const Identifier ep_11_Osc_B_PulseWidth{ "ep_11_Osc_B_PulseWidth" };
		static const Identifier ep_12_Mixer{ "ep_12_Mixer" };
		static const Identifier ep_13_Glide{ "ep_13_Glide" };
		static const Identifier ep_14_FilterCutoff{ "ep_14_FilterCutoff" };
		static const Identifier ep_15_FilterReso{ "ep_15_FilterReso" };
		static const Identifier ep_16_FilterEnvAmt{ "ep_16_FilterEnvAmt" };
		static const Identifier ep_17_FilterKeyTrack{ "ep_17_FilterKeyTrack" };
		static const Identifier ep_18_FilterEnvAttack{ "ep_18_FilterEnvAttack" };
		static const Identifier ep_19_FilterEnvDecay{ "ep_19_FilterEnvDecay" };
		static const Identifier ep_20_FilterEnvSustain{ "ep_20_FilterEnvSustain" };
		static const Identifier ep_21_FilterEnvRelease{ "ep_21_FilterEnvRelease" };
		static const Identifier ep_22_AmpEnvAttack{ "ep_22_AmpEnvAttack" };
		static const Identifier ep_23_AmpEnvDecay{ "ep_23_AmpEnvDecay" };
		static const Identifier ep_24_AmpEnvSustain{ "ep_24_AmpEnvSustain" };
		static const Identifier ep_25_AmpEnvRelease{ "ep_25_AmpEnvRelease" };
		static const Identifier ep_26_PolyModAmt_FilterEnv{ "ep_26_PolyModAmt_FilterEnv" };
		static const Identifier ep_27_PolyModAmt_Osc_B{ "ep_27_PolyModAmt_Osc_B" };
		static const Identifier ep_28_PolyModDest_Osc_A_Freq{ "ep_28_PolyModDest_Osc_A_Freq" };
		static const Identifier ep_29_PolyModDest_Filter{ "ep_29_PolyModDest_Filter" };
		static const Identifier ep_30_UnisonTrack{ "ep_30_UnisonTrack" };
		static const Identifier ep_31_LFO_Freq{ "ep_31_LFO_Freq" };
		static const Identifier ep_32_LFO_Shape{ "ep_32_LFO_Shape" };
		static const Identifier ep_33_LFO_InitAmount{ "ep_33_LFO_InitAmount" };
		static const Identifier ep_34_LFO_Dest_Freq{ "ep_34_LFO_Dest_Freq" };
		static const Identifier ep_35_LFO_Dest_PW{ "ep_35_LFO_Dest_PW" };
		static const Identifier ep_36_LFO_Dest_Filter{ "ep_36_LFO_Dest_Filter" };

		static const Identifier label_FolderNameEditor{ "label_FolderNameEditor" };

		static const Identifier property_Center_x{ "property_ControlCenter_x" };
		static const Identifier property_Center_y{ "property_ControlCenter_y" };
		static const Identifier property_ControlType{ "property_ControlType" };
		static const Identifier property_DefaultChoice{ "property_DefaultChoice" };
		static const Identifier property_Description{ "property_Description" };
		static const Identifier property_ExposedName{ "property_ExposedName" };
		static const Identifier property_FirstBitIndex{ "property_FirstBitIndex" };
		static const Identifier property_FirstNybbleIndex{ "property_FirstNybbleIndex" };
		static const Identifier property_Height{ "property_Height" };
		static const Identifier property_KnobTextEditorType{ "property_KnobTextEditorType" };
		static const Identifier property_NumberOfBits{ "property_NumberOfBits" };
		static const Identifier property_NumberOfChoices{ "property_NumberOfChoices" };
		static const Identifier property_ParamID{ "property_ParamID" };
		static const Identifier property_Width{ "property_Width" };

		static const Identifier state_TooltipsOptions{ "state_TooltipsOptions" };
		static const Identifier state_UnexposedParams{ "state_UnexposedParams" };
		static const Identifier state_VoicesBank{ "state_VoicesBank" };
		static const Identifier state_VoiceTxOptions{ "state_VoiceTxOptions" };

		static const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
		static const Identifier tooltips_ShouldShowCurrentChoice{ "tooltips_ShouldShowCurrentChoice" };
		static const Identifier tooltips_ShouldShowDescription{ "tooltips_ShouldShowDescription" };

		static const Identifier tree_ChoiceNames{ "tree_ChoiceNames" };
		static const Identifier tree_ChoiceNames_Verbose{ "tree_ChoiceNames_Verbose" };
		static const Identifier tree_ExposedParamsInfo{ "tree_ExposedParamsInfo" };
		static const Identifier tree_TooltipsOptions{ "tree_TooltipsOptions" };
		static const Identifier tree_VoiceTxOptions{ "tree_VoiceTxOptions" };

		static const Identifier voiceTx_CurrentVoiceNumber{ "voiceTx_CurrentVoiceNumber" };
		static const Identifier voiceTx_IncomingVoiceShouldBeStored{ "voiceTx_IncomingVoiceShouldBeStored" };
		static const Identifier voiceTx_TransmitParamChanges{ "voiceTx_TransmitParamChanges" };
		static const Identifier voiceTx_Time{ "voiceTx_Time" };
	}
}