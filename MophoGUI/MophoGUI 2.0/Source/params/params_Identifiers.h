#pragma once

#include <JuceHeader.h>



namespace ID
{
	static const Identifier bank_custom1_VoiceDataHexStrings{ "bank_custom1_VoiceDataHexStrings" };
	static const Identifier bank_custom2_VoiceDataHexStrings{ "bank_custom2_VoiceDataHexStrings" };
	static const Identifier bank_custom3_VoiceDataHexStrings{ "bank_custom3_VoiceDataHexStrings" };
	static const Identifier bank_factory1_VoiceNameStrings{ "bank_factory1_VoiceNameStrings" };
	static const Identifier bank_factory2_VoiceNameStrings{ "bank_factory2_VoiceNameStrings" };
	static const Identifier bank_factory3_VoiceNameStrings{ "bank_factory3_VoiceNameStrings" };
	static const Identifier bank_custom1_VoiceNameStrings{ "bank_custom1_VoiceNameStrings" };
	static const Identifier bank_custom2_VoiceNameStrings{ "bank_custom2_VoiceNameStrings" };
	static const Identifier bank_custom3_VoiceNameStrings{ "bank_custom3_VoiceNameStrings" };

	static const Identifier button_Banks{ "button_Banks" };
	static const Identifier button_CancelFileOverwrite{ "button_CancelFileOverwrite" };
	static const Identifier button_CancelNewFolder{ "button_CancelNewFolder" };
	static const Identifier button_Clear{ "button_Clear" };
	static const Identifier button_Close{ "button_Close" };
	static const Identifier button_CloseFileNotValid{ "button_CloseFileNotValid" };
	static const Identifier button_CloseFolderExists{ "button_CloseFolderExists" };
	static const Identifier button_FileOverwrite{ "button_FileOverwrite" };
	static const Identifier button_Global{ "button_Global" };
	static const Identifier button_Load{ "button_Load" };
	static const Identifier button_PullCustomBank1{ "button_PullCustomBank1" };
	static const Identifier button_PullCustomBank2{ "button_PullCustomBank2" };
	static const Identifier button_PullCustomBank3{ "button_PullCustomBank3" };
	static const Identifier button_PullSelectedVoice{ "button_PullSelectedVoice" };
	static const Identifier button_PushCustomBank1{ "button_PushCustomBank1" };
	static const Identifier button_PushCustomBank2{ "button_PushCustomBank2" };
	static const Identifier button_PushCustomBank3{ "button_PushCustomBank3" };
	static const Identifier button_PushFactoryBank1{ "button_PushFactoryBank1" };
	static const Identifier button_PushFactoryBank2{ "button_PushFactoryBank2" };
	static const Identifier button_PushFactoryBank3{ "button_PushFactoryBank3" };
	static const Identifier button_PushSelectedVoice{ "button_PushSelectedVoice" };
	static const Identifier button_Read{ "button_Read" };
	static const Identifier button_Redo{ "button_Redo" };
	static const Identifier button_Reset{ "button_Reset" };
	static const Identifier button_Retry{ "button_Retry" };
	static const Identifier button_Save{ "button_Save" };
	static const Identifier button_Stop{ "button_Stop" };
	static const Identifier button_Undo{ "button_Undo" };
	static const Identifier button_Write{ "button_Write" };
	static const Identifier button_VoiceNameEdit{ "button_VoiceNameEdit" };

	static const Identifier component_DisplayLabel{ "component_DisplayLabel" };
	static const Identifier component_EditLabel{ "component_EditLabel" };
	static const Identifier component_HyperlinkButton{ "component_HyperlinkButton" };
	static const Identifier component_Knob{ "component_Knob" };
	static const Identifier component_VoiceNameChar{ "component_VoiceNameChar" };
	static const Identifier component_VoiceNameEditLabel{ "component_VoiceNameEditLabel" };
	static const Identifier component_VoiceSlotRadioButton{ "component_VoiceSlotRadioButton" };
	static const Identifier component_SeqStep{ "component_SeqStep" };
	static const Identifier component_TabbedComponentForAllBanks{ "component_TabbedComponentForAllBanks" };
	static const Identifier component_TabbedComponentForCustomBanks{ "component_TabbedComponentForCustomBanks" };
	static const Identifier component_TabbedComponentForFactoryBanks{ "component_TabbedComponentForFactoryBanks" };
	static const Identifier component_ToggleButton{ "component_ToggleButton" };

	static const Identifier global_Balance{ "global_Balance" };
	static const Identifier global_Clock{ "global_Clock" };
	static const Identifier global_ControllersOn{ "global_ControllersOn" };
	static const Identifier global_FineTune{ "global_FineTune" };
	static const Identifier global_HardwareOutputIsStereo{ "global_HardwareOutputIsStereo" };
	static const Identifier global_HardwareReceiveChannel{ "global_HardwareReceiveChannel" };
	static const Identifier global_Options{ "global_Options" };
	static const Identifier global_ParameterReceiveType{ "global_ParameterReceiveType" };
	static const Identifier global_ParameterSendType{ "global_ParameterSendType" };
	static const Identifier global_PedalModeArpLatch{ "global_PedalModeArpLatch" };
	static const Identifier global_SysExOn{ "global_SysExOn" };
	static const Identifier global_TransmitChannel{ "global_TransmitChannel" };
	static const Identifier global_Transpose{ "global_Transpose" };
	static const Identifier global_VoiceChangeOn{ "global_VoiceChangeOn" };

	static const Identifier param_SeqTrack1Dest{ "seqTrack1Dest" };
	static const Identifier param_SeqTrack2Dest{ "seqTrack2Dest" };
	static const Identifier param_SeqTrack3Dest{ "seqTrack3Dest" };
	static const Identifier param_SeqTrack4Dest{ "seqTrack4Dest" };

	static const Identifier state_CustomBank1VoiceNames{ "state_CustomBank1VoiceNames" };
	static const Identifier state_CustomBank2VoiceNames{ "state_CustomBank2VoiceNames" };
	static const Identifier state_CustomBank3VoiceNames{ "state_CustomBank3VoiceNames" };
	static const Identifier state_ExposedParams{ "state_ExposedParams" };
	static const Identifier state_PluginState{ "state_PluginState" };
	static const Identifier state_VoicesBanks{ "state_VoicesBanks" };
	static const Identifier state_CustomVoicesBank1{ "state_CustomVoicesBank1" };
	static const Identifier state_CustomVoicesBank2{ "state_CustomVoicesBank2" };
	static const Identifier state_CustomVoicesBank3{ "state_CustomVoicesBank3" };
	static const Identifier state_TooltipOptions{ "state_TooltipOptions" };
	static const Identifier state_UnexposedParams{ "state_UnexposedParams" };
	static const Identifier state_VoiceTransmissionOptions{ "state_VoiceTransmissionOptions" };

	static const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
	static const Identifier tooltips_Options{ "tooltips_Options" };
	static const Identifier tooltips_ShouldShowCurrentValue{ "tooltips_ShouldShowCurrentValue" };
	static const Identifier tooltips_ShouldShowDescription{ "tooltips_ShouldShowDescription" };

	static const Identifier voiceTx_Options{ "voiceTx_Options" };
	static const Identifier voiceTx_ParamChangeEchoesAreBlocked{ "voiceTx_ParamChangeEchoesAreBlocked" };
	static const Identifier voiceTx_Time{ "voiceTx_Time" };
}

