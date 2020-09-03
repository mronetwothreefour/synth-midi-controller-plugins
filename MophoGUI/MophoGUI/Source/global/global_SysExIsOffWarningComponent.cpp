#include "global_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



SysExIsOffWarningComponent::SysExIsOffWarningComponent(UnexposedParameters* unexposedParams) :
	HardwareSettingsWarningComponent{ unexposedParams }
{
	addButtonsToComponent();
	resized();
}

void SysExIsOffWarningComponent::checkHardwareSettings() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->sysExIsOn())
		hideThisComponent();
}

void SysExIsOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
}

void SysExIsOffWarningComponent::resized() {
	button_ForClosingComponent.setBounds(700, 126, 50, 21);
	button_ForSendingGlobalParametersDumpRequest.setBounds(600, 450, 50, 21);
}

SysExIsOffWarningComponent::~SysExIsOffWarningComponent() {
}
