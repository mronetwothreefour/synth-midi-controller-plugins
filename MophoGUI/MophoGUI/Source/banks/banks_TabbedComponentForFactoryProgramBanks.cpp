#include "banks_TabbedComponentForFactoryProgramBanks.h"

#include "banks_ProgramBanks.h"
#include "../gui/gui_Colors.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabbedComponentForFactoryProgramBanks::TabbedComponentForFactoryProgramBanks(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	unexposedParams{ unexposedParams },
	bank1{ ProgramBank::factory1, exposedParams, unexposedParams, programCopyBuffer },
	bank2{ ProgramBank::factory2, exposedParams, unexposedParams, programCopyBuffer },
	bank3{ ProgramBank::factory3, exposedParams, unexposedParams, programCopyBuffer }
{
	setComponentID(ID::component_TabbedComponentForFactoryBanks.toString());
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

void TabbedComponentForFactoryProgramBanks::addListenerToPushBankButtonInAllFactoryTabs(Button::Listener* listener) {
	bank1.addListenerToPushEntireBankButton(listener);
	bank2.addListenerToPushEntireBankButton(listener);
	bank3.addListenerToPushEntireBankButton(listener);
}

void TabbedComponentForFactoryProgramBanks::removeListenerFromPushBankButtonInAllFactoryTabs(Button::Listener* listener) {
	bank1.removeListenerFromPushEntireBankButton(listener);
	bank2.removeListenerFromPushEntireBankButton(listener);
	bank3.removeListenerFromPushEntireBankButton(listener);
}

