#pragma once

#include <JuceHeader.h>



namespace ID
{
	static const Identifier button_PgmBank{ "button_PgmBank" };
	static const Identifier button_PullSelectedProgram{ "button_PullSelectedProgram" };
	static const Identifier button_PushSelectedProgram{ "button_PushSelectedProgram" };
	static const Identifier button_Rand{ "button_Rand" };
	static const Identifier button_Redo{ "button_Redo" };
	static const Identifier button_Undo{ "button_Undo" };
	static const Identifier button_Tips{ "button_Tips" };

	static const Identifier component_Knob{ "component_Knob" };
	static const Identifier component_SwitchSlider{ "component_SwitchSlider" };

	static const Identifier pgmData_CurrentProgramNumber{ "pgmData_CurrentProgramNumber" };
	static const Identifier pgmData_Options{ "pgmData_Options" };
	static const Identifier pgmData_ParamChangeEchosAreBlocked{ "pgmData_ParamChangeEchosAreBlocked" };
	static const Identifier pgmData_ProgramTransmitTime{ "pgmData_ProgramTransmitTime" };

	static const Identifier state_ExposedParams{ "state_ExposedParams" };
	static const Identifier state_PgmDataOptions{ "state_PgmDataOptions" };
	static const Identifier state_PluginState{ "state_PluginState" };
	static const Identifier state_TooltipOptions{ "state_TooltipOptions" };
	static const Identifier state_UnexposedParams{ "state_UnexposedParams" };

	static const Identifier tooltips_DelayInMilliseconds{ "tooltips_DelayInMilliseconds" };
	static const Identifier tooltips_Options{ "tooltips_Options" };
	static const Identifier tooltips_ShouldShowCurrentValue{ "tooltips_ShouldShowCurrentValue" };
	static const Identifier tooltips_ShouldShowDescription{ "tooltips_ShouldShowDescription" };
}