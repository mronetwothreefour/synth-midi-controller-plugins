#pragma once

#include <JuceHeader.h>



namespace ID
{
	static const Identifier bank_custom1_ProgramDataHexStrings{ "bank_custom1_ProgramDataHexStrings" };
	static const Identifier bank_custom2_ProgramDataHexStrings{ "bank_custom2_ProgramDataHexStrings" };
	static const Identifier bank_custom3_ProgramDataHexStrings{ "bank_custom3_ProgramDataHexStrings" };
	static const Identifier bank_factory1_ProgramNameStrings{ "bank_factory1_ProgramNameStrings" };
	static const Identifier bank_factory2_ProgramNameStrings{ "bank_factory2_ProgramNameStrings" };
	static const Identifier bank_factory3_ProgramNameStrings{ "bank_factory3_ProgramNameStrings" };
	static const Identifier bank_custom1_ProgramNameStrings{ "bank_custom1_ProgramNameStrings" };
	static const Identifier bank_custom2_ProgramNameStrings{ "bank_custom2_ProgramNameStrings" };
	static const Identifier bank_custom3_ProgramNameStrings{ "bank_custom3_ProgramNameStrings" };

	static const Identifier button_Banks{ "button_Banks" };
	static const Identifier button_Clear{ "button_Clear" };
	static const Identifier button_Close{ "button_Close" };
	static const Identifier button_Global{ "button_Global" };
	static const Identifier button_Load{ "button_Load" };
	static const Identifier button_PgmNameEdit{ "button_PgmNameEdit" };
	static const Identifier button_PullCustomBank1{ "button_PullCustomBank1" };
	static const Identifier button_PullCustomBank2{ "button_PullCustomBank2" };
	static const Identifier button_PullCustomBank3{ "button_PullCustomBank3" };
	static const Identifier button_PullSelectedProgram{ "button_PullSelectedProgram" };
	static const Identifier button_PushCustomBank1{ "button_PushCustomBank1" };
	static const Identifier button_PushCustomBank2{ "button_PushCustomBank2" };
	static const Identifier button_PushCustomBank3{ "button_PushCustomBank3" };
	static const Identifier button_PushFactoryBank1{ "button_PushFactoryBank1" };
	static const Identifier button_PushFactoryBank2{ "button_PushFactoryBank2" };
	static const Identifier button_PushFactoryBank3{ "button_PushFactoryBank3" };
	static const Identifier button_PushSelectedProgram{ "button_PushSelectedProgram" };
	static const Identifier button_Read{ "button_Read" };
	static const Identifier button_Redo{ "button_Redo" };
	static const Identifier button_Reset{ "button_Reset" };
	static const Identifier button_Retry{ "button_Retry" };
	static const Identifier button_Save{ "button_Save" };
	static const Identifier button_Stop{ "button_Stop" };
	static const Identifier button_Undo{ "button_Undo" };
	static const Identifier button_Write{ "button_Write" };

	static const Identifier component_DisplayLabel{ "component_DisplayLabel" };
	static const Identifier component_EditLabel{ "component_EditLabel" };
	static const Identifier component_HyperlinkButton{ "component_HyperlinkButton" };
	static const Identifier component_Knob{ "component_Knob" };
	static const Identifier component_PgmNameChar{ "component_PgmNameChar" };
	static const Identifier component_PgmNameEditLabel{ "component_PgmNameEditLabel" };
	static const Identifier component_PgmSlotRadioButton{ "component_PgmSlotRadioButton" };
	static const Identifier component_SeqStep{ "component_SeqStep" };
	static const Identifier component_TabbedComponentForAllBanks{ "component_TabbedComponentForAllBanks" };
	static const Identifier component_TabbedComponentForCustomBanks{ "component_TabbedComponentForCustomBanks" };
	static const Identifier component_TabbedComponentForFactoryBanks{ "component_TabbedComponentForFactoryBanks" };
	static const Identifier component_ToggleButton{ "component_ToggleButton" };

	static const Identifier global_AudioOptions{ "global_AudioOptions" };
	static const Identifier global_Balance{ "global_Balance" };
	static const Identifier global_FineTune{ "global_FineTune" };
	static const Identifier global_HardwareOutputIsStereo{ "global_HardwareOutputIsStereo" };
	static const Identifier global_Transpose{ "global_Transpose" };

	static const Identifier midi_Clock{ "midi_Clock" };
	static const Identifier midi_ControllersOn{ "midi_ControllersOn" };
	static const Identifier midi_HardwareReceiveChannel{ "midi_HardwareReceiveChannel" };
	static const Identifier midi_Options{ "midi_Options" };
	static const Identifier midi_ParamChangeEchosAreBlocked{ "midi_ParamChangeEchosAreBlocked" };
	static const Identifier midi_ParameterReceiveType{ "midi_ParameterReceiveType" };
	static const Identifier midi_ParameterSendType{ "midi_ParameterSendType" };
	static const Identifier midi_PedalModeArpLatch{ "midi_PedalModeArpLatch" };
	static const Identifier midi_ProgramChangeOn{ "midi_ProgramChangeOn" };
	static const Identifier midi_ProgramTransmitTime{ "midi_ProgramTransmitTime" };
	static const Identifier midi_SysExOn{ "midi_SysExOn" };
	static const Identifier midi_ThruOn{ "midi_ThruOn" };
	static const Identifier midi_TransmitChannel{ "midi_TransmitChannel" };

	static const Identifier param_SeqTrack1Dest{ "seqTrack1Dest" };
	static const Identifier param_SeqTrack2Dest{ "seqTrack2Dest" };
	static const Identifier param_SeqTrack3Dest{ "seqTrack3Dest" };
	static const Identifier param_SeqTrack4Dest{ "seqTrack4Dest" };

	static const Identifier state_CustomBank1ProgramNames{ "state_CustomBank1ProgramNames" };
	static const Identifier state_CustomBank2ProgramNames{ "state_CustomBank2ProgramNames" };
	static const Identifier state_CustomBank3ProgramNames{ "state_CustomBank3ProgramNames" };
	static const Identifier state_FactoryBank1ProgramNames{ "state_FactoryBank1ProgramNames" };
	static const Identifier state_FactoryBank2ProgramNames{ "state_FactoryBank2ProgramNames" };
	static const Identifier state_FactoryBank3ProgramNames{ "state_FactoryBank3ProgramNames" };
	static const Identifier state_ExposedParams{ "state_ExposedParams" };
	static const Identifier state_ProgramBanks{ "state_ProgramBanks" };
	static const Identifier state_PluginState{ "state_PluginState" };
	static const Identifier state_CustomProgramBank1{ "state_CustomProgramBank1" };
	static const Identifier state_CustomProgramBank2{ "state_CustomProgramBank2" };
	static const Identifier state_CustomProgramBank3{ "state_CustomProgramBank3" };
	static const Identifier state_FactoryProgramBank1{ "state_FactoryProgramBank1" };
	static const Identifier state_FactoryProgramBank2{ "state_FactoryProgramBank2" };
	static const Identifier state_FactoryProgramBank3{ "state_FactoryProgramBank3" };
	static const Identifier state_ProgramNameStrings{ "state_ProgramNameStrings" };
	static const Identifier state_TooltipOptions{ "state_TooltipOptions" };
	static const Identifier state_UnexposedParams{ "state_UnexposedParams" };

	static const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
	static const Identifier tooltips_Options{ "tooltips_Options" };
	static const Identifier tooltips_ShouldShowCurrentValue{ "tooltips_ShouldShowCurrentValue" };
	static const Identifier tooltips_ShouldShowDescription{ "tooltips_ShouldShowDescription" };
}

