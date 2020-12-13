#include "banks_TabbedComponentForCustomProgramBanks.h"

#include "banks_ProgramBanks.h"
#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabbedComponentForCustomProgramBanks::TabbedComponentForCustomProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	unexposedParams{ unexposedParams },
	bank1{ ProgramBank::custom1, exposedParams, unexposedParams, programCopyBuffer },
	bank2{ ProgramBank::custom2, exposedParams, unexposedParams, programCopyBuffer },
	bank3{ ProgramBank::custom3, exposedParams, unexposedParams, programCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForCustomBanks.toString());
	setTabBarDepth(30);
	setOutline(0);
	addTab("1", Color::device, &bank1, true, 1);
	addTab("2", Color::device, &bank2, true, 2);
	addTab("3", Color::device, &bank3, true, 3);
	setColour(backgroundColourId, Color::device.darker(0.25f));
	auto tab_w{ bank1.getWidth() };
	auto tab_h{ bank1.getHeight() };
	setSize(tab_w + getTabBarDepth(), tab_h);
}

